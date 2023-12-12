#pragma once

#include <iostream>

using namespace std;

/*
Gives the excel formula for adding two values
*/
string add(string a, string b);

/*
Gives the excel formula for subtracting two values (a - b)
*/
string sub(string a, string b);

/*
Gives the excel formula for multiplying two values
*/
string multiply(string a, string b);

/*
Gives the excel formula for dividing two values (a/b)
*/
string divide(string a, string b);

/*
Gives the excel formula for raising a value to a power (a^pow)
*/
string pow(string a, string pow);

/*
Gives the excel formula for uncertainty of two values that are added or subtracted
- a: the first value
- b: the second value
- u_a: uncertainty of the first value
- u_b: uncertainty of the second value
*/
string u_addsub(string uA, string uB);

/*
Gives the excel formula for uncertainty of two values that are multiplied or divided
- a: the first value
- b: the second value
- u_a: uncertainty of the first value
- u_b: uncertainty of the second value
*/
string u_multdiv(string a, string b, string uA, string uB);

string u_pow(string a, string u_a, string n);