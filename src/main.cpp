#include <iostream>
#include <complex>
#include <cbrain.h>

int main(){

    std::complex<double> 
    testb[9] = {1,2,3,
                4,5,6,
                7,8,9};
    int testc[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    brain::Vec<std::complex<double>,9> test(testb);
    std::cout << test;
}