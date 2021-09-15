#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

int verifArg(int argc, char **argv)
{
	int i;

    if (strcmp(argv[2],"+") == 0 || strcmp(argv[2],"-") == 0 || strcmp(argv[2],"x") == 0 ||strcmp(argv[2],"m") == 0 || strcmp(argv[2],"*") == 0 || strcmp(argv[2],"/") == 0 || strcmp(argv[2],"%") == 0 || strcmp(argv[2],"v") == 0 || strcmp(argv[2],"V") == 0 || strcmp(argv[2],"^") == 0)
        {
	    	//if is 2 + 2
		for (i = 2; i < argc; i += 2)
                {
                        if ((strcmp(argv[i],"+") != 0 || strcmp(argv[i],"-") != 0 || strcmp(argv[i],"x") != 0 ||strcmp(argv[i],"m") != 0 || strcmp(argv[i],"*") != 0 || strcmp(argv[i],"/") != 0 || strcmp(argv[i],"%") != 0 || strcmp(argv[i],"v") != 0 || strcmp(argv[i],"V") != 0 || strcmp(argv[i],"^") != 0) && isdigit(atof(argv[i + 1])) != 0)
                        {
                                printf("Error usage : the the format of the calculation is not up to standard\nExample of usage : \n# 2 + 2 / 3\n# - 4 x 3 / 6\n");
                                exit(1);
                       	}
		}
		return 1;
        }
        else
        {
                printf("Error usage : the the format of the calculation is not up to standard\nExample of usage : \n# 2 + 2 / 3\n# -4 x 3 / 6\n");
                exit(1);
            }
}

int main(int argc, char **argv) {

    int nb_c = argc / 2;
    int j = verifArg(argc, argv);
    int i;

    NUMBER list[nb_c];
    nb_c = 0;
    //Sort arguments in list
    for (i = 1; i < argc; i += 2)
    {
	    if (j == 1)
	    {
	    	// if is 2 + 2
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
	    else if (j == 2) {
		// if is - 2 + 2
		list[nb_c].operator = argv[i][0];
                list[nb_c].number = atof(argv[i + 1]);
                nb_c ++;
	    }
	    else
	    {
		printf("Error usage : the the format of the calculation is not up to standard\nExample of usage : \n# 2 + 2 / 3\n# - 4 x 3 / 6\n");
	    }
    }

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
