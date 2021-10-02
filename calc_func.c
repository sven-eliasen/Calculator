//
// Created by user0 on 02/10/2021.
//

#include "calc_func.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float addition(const float op1, const float op2) {
    return op1 + op2;
}

float soustraction(const float op1, const float op2) {
    return op1 - op2;
}

float multiplication(const float op1, const float op2) {
    return op1 * op2;
}

float division(const float op1, const float op2) {
    return op1 / op2;
}

void division2(const float op1, const float op2) {
    int opp1 = (int) op1;
    int opp2 = (int) op2;
    int c = 0;

    if (opp2 > opp1) {
        printf("Quotien : 0, Reste : %d\n", opp2);
        exit(0);
    }

    while (opp1 >= opp2) {
        opp1 = opp1 - opp2;
        c++;
    }

    printf("Quotien : %d, Reste : %d\n", c, opp1);
}

float power(const float op1, const float op2) {
    return pow(op2, op1);
}