#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.

// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// declare capacity and size variables
	int capacity = 10;
	int mySize = 0; // how full the array of strings is
	char str[1000];

	// Allocate memory for an array of strings (arr).
	char ** arr = malloc(capacity * sizeof(char *)); // pointer to the array of strings that holds size char pointers

	// Read the file line by line.
	while (fgets(str, 1000, in)) // puts each line of the in file into the str variable
	{
    
	//   Trim newline from the fgets function
		for (int i = 0 ; i < strlen(str) ; i++)
		{
			if (str[i] == '\n')
			{
				str[i] = '\0';
			}
		}

	//   Expand array if necessary (realloc).
	if (mySize > capacity) // don't know if the resizing works!!
	{
		capacity = capacity * 2;
		arr = realloc(arr, capacity * sizeof(char *));
	}

	//   Allocate memory for the string (str).
	printf(" %lu", strlen(str));
	arr[mySize] = malloc(strlen(str));


	//   Copy each line into the string (use strcpy).
	strcpy(arr[mySize], str);
	mySize++; // incrementing the count

	//   Attach the string to the large array (assignment =).
	}

    // Close the file.
	fclose(in);
	
	// The size should be the number of entries in the array.
	*size = mySize;
	
	// Return pointer to the array of strings.
	return arr;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{
	for(int i = 0; i < size; i++)
	{
		// use strstr to check if the target is there
		if (strstr(lines[i], target))
		{
			return lines[i];
		}
	}
	return NULL;
}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		//free the strings
		free(arr[i]);
	}
	// free the array
	free(arr);
}