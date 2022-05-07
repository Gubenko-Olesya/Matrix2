#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main()					//Gubenko Olesya 112
{
	int size, i, j, k, Error;
	double **A, **idA, **B;
	FILE *in = fopen("input.txt", "wt");
	FILE *out = fopen("output.txt", "wt");

	printf("Hi! This program was made to compute the inverse matrix of given matrix A.\n");
	printf("Please, enter matrix size.\n");
	if ( (scanf("%d", &size) != 1) || (size < 0) )	{
		printf("Wrong matrix size, please, try again.\n");
		return -1;
	}

	//fscanf(in, "%d", &size);
	A = (double**) malloc(size * sizeof(double));
	for(i=0; i<size; i++)
		A[i] = (double*) malloc(size * sizeof(double));
	idA = (double**) malloc(size * size * sizeof(double));
	for(i=0; i<size; i++)
		idA[i] = (double*) malloc(size * sizeof(double));
	B = (double**) malloc(size * size * sizeof(double));
	for(i=0; i<size; i++)
		B[i] = (double*) malloc(size * sizeof(double));
	randomize(A, size);

	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
			fprintf(in, "%lf ", A[i][j]);
		}
		fprintf(in, "\n");
	}

	printf("Open input.txt to check given matrix.\n");
	copy(A, idA, size);
	identity(B, size);
	find_inverse(A, B, size, &Error);

	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
			fprintf(out, "%lf ", B[i][j]);
		}
		fprintf(out, "\n");
	}

	if (check(idA, B, size)==(-1))
		printf("Something went wrong while finding inverse matrix, please, try again.\n");
	else {
		if (Error == 1)	{
			printf("There is no inverse matrix for non-square matrix.\n");
			return -1;
		}
		else
			printf("The inverse matrix was successfully found. Open output.txt file to see the result.\n");
	}
	for (i = 0; i < size; i++)
		free(A[i]);
	free(A);
	for (i = 0; i < size; i++)
		free(B[i]);
	free(B);
	for (i = 0; i < size; i++)
		free(idA[i]);
	free (idA);
	fclose(in);
	fclose(out);
	return 0;
}


