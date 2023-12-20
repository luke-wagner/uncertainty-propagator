#include "propagating_u.h"
#include <sstream>

std::string add(std::string a, std::string b){
    // don't need parentheses? #check
    std::stringstream returnVal;
    returnVal << a << "+" << b;
    return returnVal.str();
}

std::string subtract(std::string a, std::string b){
    // need parentheses on second term
    std::stringstream returnVal;
    returnVal << a << "-(" << b << ")";
    return returnVal.str();
}

std::string multiply(std::string a, std::string b){
    // need parentheses on both terms
    std::stringstream returnVal;
    returnVal << "(" << a << ")*(" << b << ")";
    return returnVal.str();
}

std::string divide(std::string a, std::string b){
    // need parentheses on both terms
    std::stringstream returnVal;
    returnVal << "(" << a << ")/(" << b << ")";
    return returnVal.str();
}

std::string pow(std::string a, std::string n){
    std::stringstream returnVal;
    returnVal << "(" << a << ")^(" << n << ")";
    return returnVal.str();
}

std::string u_addsub(std::string δa, std::string δb){
    std::stringstream returnVal;
    returnVal << "SQRT(" << 
        add(pow(δa, "2"), pow(δa, "2"))
    << ")";
    return returnVal.str();
}

std::string u_multdiv(std::string a, std::string b, std::string δa, std::string δb){
    std::stringstream returnVal;
    returnVal << multiply(a, b) << "*SQRT(" <<
        add(pow(divide(δa, a), "2"), pow(divide(δa, b), "2"))
    << ")";
    return returnVal.str();
}

std::string u_pow(std::string x, std::string δx, std::string n)
{
    std::string δxFractional = divide(δx, x);
    std::string δresultFractional = multiply(δxFractional, n);
    std::string result = pow(x, n);
    std::string δresult = multiply(δresultFractional, result);
    return δresult;
}