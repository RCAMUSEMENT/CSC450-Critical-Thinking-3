# CSC450: Programming III — Critical Thinking 3

**Student Name:** Ryley Carlson
**Course:** CSC450 - Programming III (Module 3)
**Development Environment:** Visual Studio Code (C/C++ Extension Pack)
**Compiler Toolchain:** GCC / G++ Cross-Platform Environment

---

## Project Overview

This repository contains the complete deliverables for the Module 3 Critical Thinking assignment. The project focuses on safe dynamic memory management, raw pointer allocation lifecycle loops, and defensive hardware input stream validation:

1. **Fazbear Security Telemetry OS (`main.cpp`):** A secure console application engineered to capture whole-number environmental variables, instantiate isolated raw integer pointers to dynamic memory blocks via the `new` operator, display concurrent stack and heap address structures, and securely release dynamic allocations back to the operating system using the `delete` operator.
2. **System Design Pseudocode (`pseudocode.txt`):** A high-level algorithmic blueprint detailing step-by-step memory allocation checks, input validation stream loops, and memory reclamation boundaries to prevent data tracking loops from hanging.

---

## Hardware Optimization Note

While Eclipse IDE was originally recommended for this course, it utilizes a heavy GUI runtime framework that creates an overwhelming processing overhead on integrated graphics processing units (such as the legacy Intel HD 530 architecture). To mitigate UI thread blocking, asset delay bottlenecks, and local development system lag, this entire project environment was migrated to a highly optimized Visual Studio Code workspace configuration.

---

## Compilation and Execution Instructions

To compile and run the source file manually via your local native terminal framework, execute the following compiler commands:

### 1. Fazbear Security Telemetry OS

```bash
g++ -std=c++17 -Wall main.cpp -o fazbear_security_os
./fazbear_security_os
```

---

## Identified Bug Fixes & Security Enhancements

### main.cpp Features:

* **Mitigated Heap Memory Leaks:** Enforced a secure memory reclamation pipeline at the end of the execution run that systematically fires off manual `delete` commands for all active pointers, preventing unreleased memory from accumulating during long shifts.
* **Eliminated Dangling Pointer Traps:** Reset every dynamic tracking pointer to `nullptr` immediately after deallocation, ensuring any subsequent accidental pointer reuse causes a predictable crash instead of exposing the application to hidden memory corruption exploits.
* **Defended Against Double-Free Faults:** Structured the dynamic cleanup block with protective conditional loops that explicitly check pointer tracking health before running deallocations, blocking catastrophic application crashes caused by multi-call deallocations.
* **Robust Input Stream Validation:** Swapped out standard unguarded `std::cin >>` inputs for a custom validation routine that actively traps non-numeric strings, clears the broken stream error flags, and flushes out corrupted characters to completely prevent terminal freeze loops.