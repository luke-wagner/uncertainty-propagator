#pragma once
#include <string>

//////////////////////////
// BASIC FUNCTIONS
//////////////////////////
/*
Gives the excel formula for adding two values
*/
std::string add(std::string a, std::string b);

/*
Gives the excel formula for subtracting two values (a - b)
*/
std::string subtract(std::string a, std::string b);

/*
Gives the excel formula for multiplying two values
*/
std::string multiply(std::string a, std::string b);

/*
Gives the excel formula for dividing two values (a/b)
*/
std::string divide(std::string a, std::string b);

/*
Gives the excel formula for raising a value to a power (x^n)
*/
std::string pow(std::string x, std::string n);

//////////////////////////
// UNCERTAINTY FUNCTIONS
//////////////////////////
/*
Gives the excel formula for uncertainty of two values that are added or subtracted
@param: a - the first value
@param: b -  the second value
@param: δa - uncertainty of the first value
@parma: δb - uncertainty of the second value
*/
std::string u_addsub(std::string δa, std::string δb);

/*
Gives the excel formula for uncertainty of two values that are multiplied or divided
@param: a - the first value
@param: b -  the second value
@param: δa - uncertainty of the first value
@parma: δb - uncertainty of the second value
*/
std::string u_multdiv(std::string a, std::string b, std::string δa, std::string δb);

/*
Gives the excel formula for uncertainty of raising a value to a power (x^n)
Assumes n has no uncertainty
@param: x - a value
@param: δx - the uncertainty of this value
@param: n - the power the value is raised to
*/
std::string u_pow(std::string x, std::string δx, std::string n);