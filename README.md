# Uncertainty Propagator 🔭🪐

## ⭐ IN DEVELOPMENT ------------------------------------------------
A program that propagates uncertainty for a function given a mathematical expression. For example, given `f = a(b + c)`, this program can calculate `δf` using rules of uncertainty propagation. This program has two modes: **direct uncertainty calculation** and **Excel formula generation.**

## Installation/Usage instructions:
- Clone the git repository
- Modify main.cpp as necessary
- Run the command "make" in a git bash terminal at the directory of the repo to build the executable
- Run the resulting main.exe executable

## Requirements:
- Must have [GNU make](https://gnuwin32.sourceforge.net/packages/make.htm) installed on the system and added to path

## Mode 1: Direct uncertainty calculation
Still to do

## Mode 2: Excel formula generation
This is the original mode of the program. Created out of a necessity to generate very long Excel equations without making errors.

### How to Use
Example 1 from main.cpp::main():

```
// Let f = a(b + c)
// Goal: generate an Excel formula for δf
// The program must know in which cells the values of a, δa, b, δb, c, and δc are stored.
// Thus, for each known variable in the mathematical expression, we must have a
// string variable set to the cell number in which its value is stored.

// example values; these can be changed
std::string a = "B2";
std::string δa = "C2";
std::string b = "B3";
std::string δb = "C3";
std::string c = "B4";
std::string δc = "C4";

// To find δf, we can use a combination of basic and uncertainty function calls
//
// Basic functions handle basic mathematical operations. For instance, to add b + c,
// we use the basic add() function.
// string b_plus_c = add(b, c)
// More complex example:
//      let g = a(a - b)/b
//      string g = divide(multiply(a, subtract(a, b)), b)
//      Note: The result of the inner-most operation (subtract(a, b)) is used in the next operation,
//          multiply()
//
// Uncertainty functions handle propagating uncertainty. These functions are all preceded with "u_"
// Example: given δa and δb, find uncertainty δ(a + b)
//      string δa_plus_b = u_addsub(δa, δb)
//

// the resulting string δf contains the Excel formula for the uncertainty of f
std::string δf = u_multdiv(a, add(b, c), δa, u_addsub(δb, δc));
std::cout << δf;
```

## Types of uncertainty propagation supported:
- Adding/subtracting of two values a and b where a and b both have some uncertainty
- Multiplying/diving of two values a and b where a and b both have some uncertainty
- Exponential uncertainty propagation given a value a^n where a has some uncertainty but not n

## Limitations:
- Uncertainty propagation for more complex functions not supported (such as uncertainty propagation involving derivatives)
- Assumes uncertainties are [uncorrelated](https://en.wikipedia.org/wiki/Propagation_of_uncertainty#:~:text=If%20the%20uncertainties%20are%20correlated,group%20averages%20will%20be%20correlated.)