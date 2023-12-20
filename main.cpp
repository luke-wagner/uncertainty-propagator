#include <iostream>
#include "propagating_u.h"

int main(){

    //////////////////////////
    // EXAMPLES
    //////////////////////////
    // Example 1: Using Excel formula generation
    // -----------------------------------------------------------------------------------
    // Let f = a(b + c)
    // Goal: generate an Excel formula for δf
    // The program must know in which cells the values of a, δa, b, δb, c, and δc are stored.
    // Thus, for each known variable in the mathematical expression, we must have a
    // string variable set to the cell number in which its value is stored.

    // example values; these can be changed
    string a = "B2";
    string δa = "C2";
    string b = "B3";
    string δb = "C3";
    string c = "B4";
    string δc = "C4";

    // To find δf, we can use a combination of basic and uncertainty function calls
    //
    // Basic functions handle basic mathematical operations. For instance, to add b + c,
    // we use the basic add() function.
    // string b_plus_c = add(b, c)
    // More complex example:
    //      let g = a(a - b)/b
    //      string g = divide(multiply(a, subtract(a, b)), b)
    //      Note: The result of the inner-most operation (subtract(a, b)) is used in the next operation, multiply()
    //
    // Uncertainty functions handle propagating uncertainty. These functions are all preceded with "u_"
    // Example: given δa and δb, find uncertainty δ(a + b)
    //      string δa_plus_b = u_addsub(δa, δb)
    //

    // the resulting string δf contains the formula for the uncertainty of f
    string δf = u_multdiv(a, add(b, c), δa, u_addsub(δb, δc));
    cout << δf;

    // wait for the user to press enter before terminating program
    cin.get();

    return 0;
}