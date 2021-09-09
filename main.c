#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void division2 (const float op1, const float op2)
{
	int opp1 = (int)op1;
  	int opp2 = (int)op2;
  	int c = 0;
  
  	if (opp2 > opp1) printf("Quotien : 0, Reste : %d\n",  opp2);
  
  	while (opp1 >= opp2)
       	{
    		opp1 = opp1 - opp2;
    		c++;
 	 }
  
  	printf("Quotien : %d, Reste : %d\n", c, opp1);
}

float power (const float op1, const float op2)
{
	return pow(op1, op2);
}

void calcul (float op1, float op2, char op)
{
	switch(op)
        {
                case '+':
                        printf("Result addition : %f\n", addition(op1, op2));
			break;
		case '-':
                        printf("Result soustraction : %f\n", soustraction(op1, op2));
             		break;
	     	case '/':
			printf("Result divi : %f\n", division(op1, op2));
              		break;
	      	case '%':
                        division2(op1, op2);
			break;
                case '*':
                case 'm':
                case 'x':
                        printf("Result multiplication : %f\n", multiplication(op1, op2));
           		break;
	   	case '^':
                        printf("Result power : %lf\n", power(op1, op2));
              		break;
	      	default:
                        printf("Wrong operator !\n");
			exit(1);
        }
}

int main (int argc, char **argv)
{
	float op1, op2;
  
// Check if enough argument, 4 because we take at least 2 number and 1 operator
	if (argc < 4)
	{
		printf("Not enough args !\n");
		exit(1);
	}
	
	if (argc%2 != 1)
	{
		printf("Wrong args number!\n");
		exit(1);
	}

	op1 = atof(argv[1]);
	op2 = atof(argv[3]);

	calcul(op1, op2, argv[2][0]);

	return 0;
}
//test123
