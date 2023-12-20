#include "propagating_u.h"
#include <sstream>

using namespace std;

string add(string a, string b){
    // don't need parentheses? #check
    stringstream returnVal;
    returnVal << a << "+" << b;
    return returnVal.str();
}

string subtract(string a, string b){
    // need parentheses on second term
    stringstream returnVal;
    returnVal << a << "-(" << b << ")";
    return returnVal.str();
}

string multiply(string a, string b){
    // need parentheses on both terms
    stringstream returnVal;
    returnVal << "(" << a << ")*(" << b << ")";
    return returnVal.str();
}

string divide(string a, string b){
    // need parentheses on both terms
    stringstream returnVal;
    returnVal << "(" << a << ")/(" << b << ")";
    return returnVal.str();
}

string pow(string a, string pow){
    stringstream returnVal;
    returnVal << "(" << a << ")^(" << pow << ")";
    return returnVal.str();
}

string u_addsub(string uA, string uB){
    stringstream returnVal;
    returnVal << "SQRT(" << 
        add(pow(uA, "2"), pow(uB, "2"))
    << ")";
    return returnVal.str();
}

string u_multdiv(string a, string b, string uA, string uB){
    stringstream returnVal;
    returnVal << multiply(a, b) << "*SQRT(" <<
        add(pow(divide(uA, a), "2"), pow(divide(uB, b), "2"))
    << ")";
    return returnVal.str();
}

string u_pow(string a, string u_a, string n)
{
    string u_aFractional = divide(u_a, a);
    string u_resultFractional = multiply(u_aFractional, n);
    string result = pow(a, n);
    string u_result = multiply(u_resultFractional, result);
    return u_result;
}
