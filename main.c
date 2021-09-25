#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

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

void division2 (const float op1, const float op2)
{
    int opp1 = (int)op1;
    int opp2 = (int)op2;
    int c = 0;

    if (opp2 > opp1) 
    {
        printf("Quotien : 0, Reste : %d\n",  opp2);
        exit(0);
    }

    while (opp1 >= opp2)
    {
        opp1 = opp1 - opp2;
        c++;
    }

    printf("Quotien : %d, Reste : %d\n", c, opp1);
}

int verifArg(int argc, char **argv)
{
    // TODO: gestion avec switch + modulo que à la fin
    for (int i = 2; i < argc; i += 2)
    {
        if (argc % 2 != 0)
        {
            printf("Error usage : the the format of the calculation is not up to standard\nExample of usage : \n# 2 + 2 / 3\n# - 4 x 3 / 6\n");
            exit(1);
        }

        // Do switch here
        if ((strcmp(argv[i],"+") != 0 || strcmp(argv[i],"-") != 0 || strcmp(argv[i],"x") != 0 ||strcmp(argv[i],"m") != 0 || strcmp(argv[i],"*") != 0 || strcmp(argv[i],"/") != 0 || strcmp(argv[i],"%") != 0 || strcmp(argv[i],"v") != 0 || strcmp(argv[i],"V") != 0 || strcmp(argv[i],"^") != 0) && isdigit(atof(argv[i + 1])) != 0)
        {
            printf("Error usage : the the format of the calculation is not up to standard\nExample of usage : \n# 2 + 2 / 3\n# - 4 x 3 / 6\n");
            exit(1);
        }
    }
    return argc/2;
}

int parseArgs (int argc, char **argv, NUMBER list[])
{
    int nb_c = 0;

    //Sort arguments in list
    for (int i = 1; i < argc; i += 2)
    {
		if (i == 1)
		{
			list[nb_c].operator = '+';
            list[nb_c].number = atof(argv[i]);
			nb_c ++;
		}
		else
		{
			list[nb_c].operator = argv[i - 1][0];
            list[nb_c].number = atof(argv[i]);
			nb_c ++;
		}
    }
    return nb_c;
}

float addition (const float op1, const float op2)
{
	return op1 + op2;
}

float soustraction (const float op1, const float op2)
{
	return op1 - op2;
}

float multiplication (const float op1, const float op2)
{
	return op1 * op2;
}

float division (const float op1, const float op2)
{
	return op1 / op2;
}

float power(const float op1, const float op2)
{
    return pow(op2, op1);
}

void calculate(int nb_c, NUMBER list[]) {

    // Loop to calculate all power
    for (int i = 1; i < nb_c; ++i) {
        float res = -1;
        char bool = 0;

        if (list[i].operator == '^') {
            res = power(list[i].number, list[i-1].number);
            bool = 1;
        }

        if (bool) {
            reorder_list(list, res, &i, &nb_c);
        }
    }

    // Loop to calculate all multiplication and division
    for(int i = 1; i < nb_c; i++) {
        float res = -1;
        char bool = 0;

        if (list[i].operator == 'x') {
            res = multiplication(list[i].number, list[i-1].number);
            bool = 1;
        }
        if (list[i].operator == '/') {
            res = division(list[i].number, list[i-1].number);
            bool = 1;
        }

        // If there is a multiplication or division, then reorder the list with result
        if (bool) {
            reorder_list(list, res, &i, &nb_c);
        }
    }

    // Loop to calculate all addition and subtraction
    for(int i = 1; i < nb_c; i++) {

        float res = -1;
        char bool = 0;

        if (list[i].operator == '+') {
            res = addition(list[i].number, list[i-1].number);
            bool = 1;
        }
        if (list[i].operator == '-') {
            res = soustraction(list[i].number, list[i-1].number);
            bool = 1;
        }

        if (bool) {
            reorder_list(list, res, &i, &nb_c);
        }
    }

    // If there is a modulo do it, if not print normal result
    if (list[1].operator == '%') {
        division2(list[0].number, list[1].number);
    } else {
        // First number of list is the result at the end
        printf("Result : %f\n", list[0].number);
    }
}

int main(int argc, char **argv) 
{
    int lengthTab = verifArg(argc, argv);
    NUMBER list[lengthTab];
    int nb_c = parseArgs(argc, argv, list);
    calculate(nb_c, list);
    return 0;
}
