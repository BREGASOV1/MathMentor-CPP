# MathMentor-CPP

A professional-grade console application for arithmetic skill development, demonstrating modern C++ practices.

## Features
- 🧮 **Core Operations**: +, -, ×, ÷ with integer precision
- 🎚️ **Adaptive Difficulty**:
  - Easy (1-10)
  - Medium (10-50)
  - Hard (50-100)
- 📊 **Performance Analytics**:
  - Real-time accuracy tracking
  - Session history with detailed breakdowns
  - Final competency assessment

## Technical Implementation
- **C++17 Features**:
  - Strongly-typed enums (`enLevelOfQuestion`, `enOperationType`)
  - Struct-based data modeling (`stQuestionInfo`, `stFinalResults`)
  - Windows Console API integration (`system("color")`)
  - Modular architecture with 10+ focused functions

# How to Use
```bash
# Clone repository
git clone https://github.com/BREGASOV1/MathMentor-CPP.git

# Compile (Windows)
g++ MathMentor-CPP.cpp -o MathMentor-CPP

# Start training
MathMentor-CPP.exe

Note: Requires Windows for color features
