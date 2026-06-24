# Templated 3D Vector Math Library

A high-performance, header-only 3D vector mathematics library written in C++20 and fully unit-tested with Google Test. Designed with hardware memory alignment for potential SIMD (Single Instruction, Multiple Data) optimization.

This library was developed to demonstrate core systems-programming competencies: templates, explicit memory layouts, operator overloading symmetry, and test-driven development (TDD).

## Key Technical Teatures

- **Generic Template Architecture (`template <typename T>`):** Supports `float` (ideal for graphics processing), `double` (high-precision calculations), and integer coordinates without code duplication.
- **Hardware Memory Alignment (`alignas(16)`):** Forces the compiler to align the struct to 16-byte boundaries. 
  - For `float` types, this pads the structure from 12 bytes to 16 bytes.
  - For `double` types, this pads the structure to 32 bytes (the next 16-byte boundary).
  - This structure design matches the alignment boundaries required by CPU vector registers (SSE/AVX) for efficient cache loading.
- **Decoupled Non-Member Design:** Adheres to the core C++ guideline: *"Prefer non-member non-friend functions to member functions."*
- **Memory Safety & Efficiency:** Applied pass-by-reference-to-const for larger read-only operations to eliminate copying, while utilizing pass-by-value optimally for primitive types and accumulator copy tricks (e.g., implementing binary `+` in terms of member `+=`).
- **Epsilon-Based Floating Point Testing:** Implemented custom tolerance comparison tests via Google Test’s `EXPECT_NEAR` to safeguard against binary rounding errors inherent in IEEE 754 representations.

## Implemented Operations

- **Accumulator Operators:** `+=`, `-=`, `*=`, `/=` (with division-by-zero safety checks)
- **Binary Arithmetic Operators:** `+`, `-`, `*` (symmetric/commutative scalar), `/`
- **Unary Operators:** Negation (`-vector`)
- **Vector Operations:** Magnitude (`length()`), Normalization (`normalized()`), Dot Product (`dot()`), and Cross Product (`cross()`)

---

## Directory Structure

```text
Vector_Library/
├── .gitignore
├── README.md
├── Math_Library/
│   ├── Math_Library.slnx          # Visual Studio Solution File (XML Format)
│   ├── Math_Library.vcxproj       # Static Library Project File
│   └── Vector3.h                  # Header-Only Templated Library Implementation
│
└── Math_Tests_Google/
    ├── Math_Tests_Google.vcxproj  # Test Executable Project File
    ├── pch.h / pch.cpp            # Precompiled Headers (reused for gTest)
    └── test.cpp                   # Comprehensive Google Test Suite
```

## How to Build and Run the Tests

**Prerequisites**
Windows 10/11
Visual Studio 2022 (with the "Desktop development with C++" workload installed)
Git

**Build Instructions**
1. Clone the repository to your local machine: git clone https://github.com/menonvasu/Vector_Library.git
2. Open Visual Studio.
3. Select Open a project or solution and navigate to: Vector_Library/Math_Library/Math_Library.slnx
5. Change your Build Configuration to Debug or Release and your platform to x64.
6. Build the Solution (Ctrl + Shift + B).

**Running the Google Test Suite**
1. In Visual Studio, open the Test Explorer (Test -> Test Explorer from the top menu).
2. Click the Run All Tests button (or press Ctrl + R, A).
3. All tests should pass with green checkmarks.

## Lessons Learned & Systems Insights
The Pitfalls of Moving C++ Projects: Learned how Visual Studio's MSBuild system hardcodes relative paths for NuGet dependencies (like Google Test). Moving directories manually breaks XML targets, teaching the value of recreating test configurations inside the permanent folder structure.
Portability with Solution Macros: Configured Additional Include Directories using the $(SolutionDir) macro. This ensures the project remains fully portable across different machines and relative path moves.
