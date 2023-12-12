# Uncertainty Propagator

## IN DEVELOPMENT ------------------------------------------------
A program that calculates the uncertainty for a value given an equation that defines this value. For example, given f = a(b + c), this program can calculate δf using rules of uncertainty propagation. This program has two modes: direct uncertainty calculation, and excel formula generation

## Mode 1: Direct uncertainty calculation
Still to do

## Mode 2: Excel formula generation
This is the original mode of the program. Created out of a necessity to generate very long Excel equations without making errors.

## Types of uncertainty propagation supported:
- Adding/subtracting of two values a and b where a and b both have some uncertainty
- Multiplying/diving of two values a and b where a and b both have some uncertainty
- Exponential uncertainty propagation given a value a^n where a has some uncertainty

## Installation instructions:
- Clone the git repository
- Modify the code as necessary
- Run the command "make" in a git bash terminal at the directory of the repo
- Run the resulting main.exe executable