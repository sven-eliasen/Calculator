#include <stdio.h>

typedef struct Number {
    char operator;
    float number;
} NUMBER;

void reorder_list(NUMBER list[], float res, int *i, int *nb_c) {
    list[(*i)-1].operator = '+';
    list[(*i)-1].number = res;

    for (int j = *i; j < *nb_c-1; ++j) {
        list[j].operator = list[j+1].operator;
        list[j].number = list[j+1].number;
    }

    // Decrease loop cursor
    (*i)--;
    (*nb_c)--;
}

int main(void) {
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

    // Loop to calculate all multiplication and division
    for(int i = 1; i < nb_c; i++) {

        float res = -1;
        if (list[i].operator == 'x') {
            res = list[i].number * list[i-1].number;
        }
        if (list[i].operator == '/') {
            res = list[i-1].number / list[i].number;
        }

        // If there is a multiplication or division, then reorder the list with result
        if (res != -1) {
            reorder_list(list, res, &i, &nb_c);
        }
    }

    // Loop to calculate all addition and subtraction
    for(int i = 1; i < nb_c; i++) {

        float res = -1;
        if (list[i].operator == '+') {
            res = list[i].number + list[i-1].number;
        }
        if (list[i].operator == '-') {
            res = list[i-1].number - list[i].number;
        }

        if (res != -1) {
            reorder_list(list, res, &i, &nb_c);
        }
    }

    // First number of list is the result at the end
    printf("Result : %f\n", list[0].number);

    return 0;
}
