// mmn11.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "string.h"

int displayAnswer(int functionNumber, int functionAnswer, char *firstArgument, char *secondArgument, char *thirdArgument);
int my_strncmp(char *firstArgument, char *secondArgument, int n);
int my_strchr(char *firstArgument, int secondArgument);
void OptionsMessage();
int displayAnswer(int functionNumber, int functionAnswer, char *firstArgument, char *secondArgument, char *thirdArgument);
/*
	Welcome message
	Ask user to choose which function
	ask for first argument
	ask for second argument
	calculate
	present results
*/
int main()
{
	/* Init variables */
	short func_option, funcAnswer;
	int nBytes;
	char firstArgument[128], secondArgument[128];
	

	printf("\t\tWelcome to my_string proram!\n\n\n\t");
	OptionsMessage();
	/*While loop, showing options message and taking input from user
	  inside while loop options for getting rid of white spaces like 'enter'
	  */
	while ( (func_option = getchar()) != '\n' || (func_option = getchar()) != ' ')
	{
		switch (func_option)
		{
		default:
			printf("Wrong option, there is no %c option..\n", func_option);
			printf("Please, try again or type 'q' or 'Q' to exit.\n\n\n");
			break;
		case '1':
			printf("You have chosen strcmp!\n");
			printf("Please provide string arguments to chosen function.\n");
			printf("First argument: ");
			scanf("%s", firstArgument);
			printf("\nSecond argument: ");
			scanf("%s", secondArgument);
			funcAnswer = my_strcmp(firstArgument, secondArgument);
			return displayAnswer(1, funcAnswer, firstArgument, secondArgument, -1);
			break;
		case '2':
			printf("You have chosen strncmp!\n");
			printf("Please provide string arguments to chosen function.\n");
			printf("First argument, is a string: ");
			scanf("%s", firstArgument);
			printf("\nSecond argument, is a string: ");
			scanf("%s", secondArgument);
			printf("\nThird argument, how many bytes to check: ");
			scanf("%d", nBytes);
			funcAnswer = my_strncmp(firstArgument, secondArgument, nBytes);
			return displayAnswer(2, funcAnswer, firstArgument, secondArgument, nBytes);
			break;
		case '3':
			printf("You have chosen strchr!\n");
			printf("Please provide string arguments to chosen function.\n");
			printf("First argument, string to look in: ");
			scanf("%s", firstArgument);
			printf("\nSecond argument, a char to look for: ");
			scanf("%d", secondArgument);
			funcAnswer = my_strchr(firstArgument, secondArgument);
			return displayAnswer(3, funcAnswer, firstArgument, secondArgument, -1);
			break;
		case 'q': case 'Q':
			return 0;
		}
		OptionsMessage();
	}
	return 0;
}


void OptionsMessage ( void )
{
	printf("Please select one of the following functions to run:\n");
	printf("1) strcmp\n");
	printf("2) strncmp\n");
	printf("3) strchr\n\n\t");
}

int displayAnswer(int functionNumber, int functionAnswer, char *firstArgument, char *secondArgument, char *thirdArgument)
{
	printf("\n\n\n\n\n");
	switch (functionNumber)
	{
	case 1: /*strcmp function answer*/
		printf("Function that ran was 'strcmp'\n");
		printf("First argument: %s\n", firstArgument);
		printf("Second argument: %s\n", secondArgument);
		printf("Function answer was: %d\n", functionAnswer);
		return functionAnswer;
		break;
	case 2: /*strncmp function answer*/

		break;
	case 3: /*strchr function answer*/

		break;
	default:
		break;
	}



}

int my_strcmp(char *firstArgument, char *secondArgument)
{
	int i;
	for (i = 0; i < strlen(firstArgument) && i < strlen(secondArgument); i++)
	{
		if (firstArgument[i] - secondArgument[i] == 0)
		{
			continue;
		}
		else
		{
			return firstArgument[i] - secondArgument[i];
		}
	}
	return 0;
}

int my_strncmp (char *firstArgument, char *secondArgument, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (firstArgument[i] - secondArgument[i] == 0)
		{
			continue;
		}
		else
		{
			return firstArgument[i] - secondArgument[i];
		}
	}
	return 0;
}



int my_strchr (char *firstArgument, int secondArgument)
{




	return -1;
}


