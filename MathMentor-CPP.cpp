
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
enum enLevelOfQuestion { Easy = 1, Med = 2, Hard = 3 };
enum enOperationType { Add = 1, Sub = 2, Div = 3, Mult = 4, Mix = 5 };
struct stFinalResults {
	short RightAnswers;
	short WrongAnswers;
	short NumberOfQuestions;
	string OperationType;
	string QuestionsLevel;
};
struct stQuestionInfo {
	enLevelOfQuestion LevelOfQuestion;
	enOperationType OperationType;

};
struct stQuestionContent {

	int numbers[2] = { 0,0 };
	char Operation;
};
string Blank(short Number) {
	string String = "";
	for (int i = 0; i < Number; i++)
	{
		String += "\t";

	}
	return String;
}
int RandomNumberInRange(int From, int To) {
	int random;
	random = rand() % (To - From) + From;
	return random;
}
int ReadPositiveNumber(string message) {
	int number;
	do
	{
		cout << message;
		cin >> number;

	} while (number <= 0);
	return number;
}
enLevelOfQuestion ReadLevelOfQuestion() {
	short LevelOfQuestion = ReadPositiveNumber("\nEnetr The Level OF Questions? [1]Easy [2]Med [3]Hard [4]Mix? ");
	return enLevelOfQuestion(LevelOfQuestion);
}
string LevelOfQuestionToString(enLevelOfQuestion LevelOfQuestion) {
	switch (LevelOfQuestion)
	{
	case Easy:
		return"Easy";
		break;
	case Med:
		return"Med";
		break;
	case Hard:
		return"Hard";
		break;
	default:
		return"Mix";
		break;
	}
}
string OperationTypeToString(enOperationType OperationType) {
	switch (OperationType)
	{
	case Add:
		return"Add";
		break;
	case Sub:
		return"Sub";
		break;
	case Div:
		return"Div";
		break;
	case Mult:
		return"Mult";
		break;
	case Mix:
		return"Mix";
		break;
	}
}
char OperationChar(enOperationType OpertaionType) {
	char Operations[4] = { '+','-','/','*' };
	switch (OpertaionType)
	{
	case Add:
		return Operations[0];
		break;
	case Sub:
		return Operations[1];
		break;
	case Div:
		return Operations[2];
		break;
	case Mult:
		return Operations[3];
		break;
	case Mix:
		return Operations[RandomNumberInRange(0, 3)];
		break;
	}
}
enOperationType ReadOperationType() {
	short OperationType = ReadPositiveNumber("\nEnter the operation type? [1]Add [2]Sub [3]Div [4]Mult [5]Mix? ");
	return enOperationType(OperationType);
}
stFinalResults FinalResultsFill(stQuestionInfo QuestionInfo, int NumberOfQuestions, int RightAnswers, int WrongAnswers) {
	stFinalResults FinalResults;
	FinalResults.QuestionsLevel = LevelOfQuestionToString(QuestionInfo.LevelOfQuestion);
	FinalResults.OperationType = OperationTypeToString(QuestionInfo.OperationType);
	FinalResults.NumberOfQuestions = NumberOfQuestions;
	FinalResults.RightAnswers = RightAnswers;
	FinalResults.WrongAnswers = WrongAnswers;
	return FinalResults;
}
int NumbersGenerator(enLevelOfQuestion LevelOfQuestion) {
	switch (LevelOfQuestion)
	{
	case Easy:
		return RandomNumberInRange(1, 10);
		break;
	case Med:
		return RandomNumberInRange(10, 50);
		break;
	case Hard:
		return RandomNumberInRange(50, 100);
		break;
	default:
		return RandomNumberInRange(1, 100);
		break;
	}
}
stQuestionContent QuestionContentFill(stQuestionInfo QuestionInfo) {
	stQuestionContent QuestionContent;
	QuestionContent.Operation = OperationChar(QuestionInfo.OperationType);
	QuestionContent.numbers[0] = NumbersGenerator(QuestionInfo.LevelOfQuestion);
	QuestionContent.numbers[1] = NumbersGenerator(QuestionInfo.LevelOfQuestion);
	return QuestionContent;
}
void SingleQuestion(stQuestionContent QuestionContent) {
	cout << Blank(1) << QuestionContent.numbers[0] << endl;
	cout << Blank(1) << QuestionContent.numbers[1] << "  " << QuestionContent.Operation;
	cout << "\n---------------\n";
}
int Answer(stQuestionContent QuestionContent) {
	switch (QuestionContent.Operation) {
	case '+':
		return QuestionContent.numbers[0] + QuestionContent.numbers[1];
		break;
	case '-':
		return QuestionContent.numbers[0] - QuestionContent.numbers[1];
		break;
	case '/':
		return QuestionContent.numbers[0] / QuestionContent.numbers[1];
		break;
	case '*':
		return QuestionContent.numbers[0] * QuestionContent.numbers[1];
		break;
	}
}
bool RightOrWrongOutput(int answer, stQuestionContent QuestionContent) {
	int RightAnswer = Answer(QuestionContent);
	if (answer == RightAnswer) {
		system("color 2F");
		cout << "\nRight Answer :)\n";
		return true;
	}
	else {
		system("color 4F");
		cout << "\nWrong Answer :(";
		cout << "\nThe Right Answer is " << RightAnswer << endl;
		return false;
	}



}
void FinalOutput(stFinalResults FinalResults) {
	cout << "\n-------------------------------------------\n";
	int result = FinalResults.RightAnswers - FinalResults.WrongAnswers;
	if (result >= 0)
		cout << "The Final Resul is Pass :)";
	else
		cout << "The Final Result is Fail :(";
	cout << "\n-------------------------------------------\n";
	cout << "Number Of Questions: " << FinalResults.NumberOfQuestions;
	cout << "\nQuestions Level  : " << FinalResults.QuestionsLevel;
	cout << "\nOperations Type  : " << FinalResults.OperationType;
	cout << "\nRight Answers    : " << FinalResults.RightAnswers;
	cout << "\nWrong Answers    : " << FinalResults.WrongAnswers;
	cout << "\n--------------------------------------------" << endl;


}
void Questions(short NumberOfQuestions) {
	int answer;
	int RightAnswers = 0, WrongAnswers = 0;
	bool RightOrWrong;
	char Operation;
	stFinalResults FinalResults;
	stQuestionContent QuestionContent;
	stQuestionInfo QuestionInfo;
	QuestionInfo.OperationType = ReadOperationType();
	QuestionInfo.LevelOfQuestion = ReadLevelOfQuestion();
	for (int i = 1; i <= NumberOfQuestions; i++)
	{
		QuestionContent = QuestionContentFill(QuestionInfo);

		cout << "\n" << Blank(4) << "Question[" << i << "/" << NumberOfQuestions << "]\n";
		SingleQuestion(QuestionContent);
		cin >> answer;
		RightOrWrong = RightOrWrongOutput(answer, QuestionContent);
		if (RightOrWrong)
			RightAnswers++;
		else
			WrongAnswers++;
	}
	FinalResults = FinalResultsFill(QuestionInfo, NumberOfQuestions, RightAnswers, WrongAnswers);
	FinalOutput(FinalResults);
}
void OurApp() {
	bool PlayAgain;
	int NumberOfQuestions;
	do
	{

		NumberOfQuestions = ReadPositiveNumber("\nHow many questions do you want to answer?");
		Questions(NumberOfQuestions);
		cout << "Do you want to play again? [1]Yes [0]No?\n";
		cin >> PlayAgain;
		system("color 0F");
		system("cls");

	} while (PlayAgain);
}
int main() {
	srand((unsigned)time(NULL));
	OurApp();
}