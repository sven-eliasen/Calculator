#include <stdio.h>
#include <stdlib.h>

typedef struct Number {
    char operator;
    float number;
} NUMBER;

void reorder_list(NUMBER list[], float res, int *i, int *nb_c) {
    if (*i == 0) {
        list[0].operator = '+';
        list[0].number = res;

        for (int j = 1; j < *nb_c-1; ++j) {
            list[j].operator = list[j+1].operator;
            list[j].number = list[j+1].number;
        }
    } else {
        list[(*i)-1].operator = '+';
        list[(*i)-1].number = res;

        for (int j = *i; j < *nb_c-1; ++j) {
            list[j].operator = list[j+1].operator;
            list[j].number = list[j+1].number;
        }
    }

    // Decrease loop cursor
    (*i)--;
    (*nb_c)--;
}

int main() {
    int nb_c = 5;
    NUMBER list[nb_c];

    list[0].operator = '+';
    list[0].number = 2;

    list[1].operator = '+';
    list[1].number = 4;

    list[2].operator = 'x';
    list[2].number = 4;

    list[3].operator = '/';
    list[3].number = 2;

    list[4].operator = '+';
    list[4].number = 2;

    // x and /
    for(int i = 1; i < nb_c; i++) {

        float res = -1;
        if (list[i].operator == 'x') {
            if (i == 0) {
                res = list[i].number * list[i+1].number;
            } else {
                res = list[i].number * list[i-1].number;
            }
        }
        if (list[i].operator == '/') {
            if (i == 0) {
                res = list[i].number / list[i+1].number;
                //printf("op1:%f op2:%f res:%f", list[i].number, list[i+1].number, res);
            } else {
                res = list[i-1].number / list[i].number;
                //printf("op1:%f op2:%f res:%f", list[i].number, list[i+1].number, res);
            }
        }

        if (res != -1) {
            reorder_list(list, res, &i, &nb_c);
        }
    }

    for(int i = 1; i < nb_c; i++) {

        float res = -1;
        if (list[i].operator == '+') {
            if (i == 0) {
                res = list[i].number + list[i+1].number;
            } else {
                res = list[i].number + list[i-1].number;
            }
        }
        if (list[i].operator == '-') {
            if (i == 0) {
                res = list[i].number - list[i+1].number;
            } else {
                res = list[i-1].number - list[i].number;
            }
        }

        if (res != -1) {
            reorder_list(list, res, &i, &nb_c);
        }
    }

    // First number of list is the result
    printf("Result : %f\n", list[0].number);

    return 0;
}
