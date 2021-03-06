

void isSquareOutOfBounds(int squareSize, int maxMatrix, int minMatrix)
{
	if(squareSize > maxMatrix || squareSize < minMatrix)
	{
		printf("Entered square size is: %d\n", squareSize);
		if (squareSize > maxMatrix)
		  printf("Bigger than max possible value for this program, which is: %d\n", maxMatrix);
		else
		  printf("Smaller than min possible value for this program, which is: %d\n", minMatrix);
		printf("Please try again, aborting the program..\n\n");
		exit(0);
	}
	
	
	
}


/* 
 * Checks if given rectangle is a square
 * 
 * sumOfSquare -- represents the sum of square elements in row/column/diagonal
 */

int isItMagic(int square[MAX_MATRIX][MAX_MATRIX], int squareSize, int sumOfSquare)
{
	/* Defining variables, columns is an array which has sum for it's array number */
	int row, mainDiag, secondDiag, columns[MAX_MATRIX], i, j;

	/* initiate vars */
	row = 0;
	mainDiag = 0;
	secondDiag = 0;
	for(i = 0; i < MAX_MATRIX; i++) 
	{
		columns[i] = 0;
	}

	/* Sum calculations */ 
	for(i = 0; i < squareSize; i++)
	{
		for(j = 0; j < squareSize; j++)
		{
			/* main diagonal sum */
			if(i ==  j)
			{
				mainDiag +=  square[i][j];
			}
			/* secondary diagonal summary*/
			/* secondary located at elements that has their
			 * location value of i + j == square Size.
			 * But since i & j start at 0 need to add both 1, hence +2 */
			if(i + j + 2 == squareSize + 1)
			{
				secondDiag += square[i][j];
			}
			columns[j] += square[i][j];
			row += square[i][j];
		}

		/* Test if row sum is good */
		/* calculated sum of row is not correct */
		if (row != sumOfSquare)
		{
			printf("ROW SUM IS: %d", row);
			return -1;
		}
		/* if it is good - restore row sum to: 0 */
		row = 0;
	}

	/* Test the rest, columns and diagonals */
	for(i = 0; i < squareSize; i++)
	{
		if (columns[i] != sumOfSquare)
		{
			printf("COL SUM IS: %d", columns[i]);
			return -1;
		}
	}
	if (mainDiag != sumOfSquare)
	{
		printf("MAIND SUM IS: %d", mainDiag);
		return -1;
	}
	if (secondDiag != sumOfSquare)
	{
		printf("SECOND SUM IS: %d", secondDiag);
		printf("\nSize is: %d\n", squareSize);
		return -1;
	} 
	return 1; /* All good */
}

/* 
 * Used for qsort comparator between two int numbers
 * */
int comp (const void * elem1, const void * elem2) 
{
		int f,s;
    f = *((int*)elem1);
    s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}


/* 
 * making sure all numbers between 1 - N^2 inside square
 */
void testInputNumber(int squareInputnumbers[], int squareSize)
{
	int tempArr[MAX_ARRAY_INPUT], i;
	squareSize *= squareSize; /* Number of all elements in a square */
	/* Creating temp array */
	for(i = 0; i <= squareSize; i++)
	{
		tempArr[i] = squareInputnumbers[i];
	}
	
	/* sorting temp array */
	qsort(tempArr, squareSize, sizeof(int), comp);
	
	
	/* Testing sorted array, it should have numbers 1 , 2 , 3 .. N^2 */
	for(i = 0; i < squareSize; i++)
	{
		if(tempArr[i] != i + 1)
		{
			printf("ERROR: Square should have all numbers from 1 to N^2 once.\n\n");
			exit(-1);
		}
	}
	/* Test if given more numbers than square should have */
	if (i < MAX_ARRAY_INPUT && tempArr[i] != -1)
	{
		printf("ERROR: Too many numbers provided in input.\n");
		exit(-1);
	}
	
	printf("\n\n");
}

/* 
 * Creates a square matrix representing a square.
 * squareSize - represents the size of the square - columns and rows.
 * */
void createSquare(int square[MAX_MATRIX][MAX_MATRIX], int squareSize, 
										int *squareInputnumbers)
{
	int i;
	int j;

	for(i = 0; i < squareSize; i++)
	{
		for(j = 0; j < squareSize; j++)
		{
			square[i][j] = squareInputnumbers[i*squareSize + j];
		}
	}
}
