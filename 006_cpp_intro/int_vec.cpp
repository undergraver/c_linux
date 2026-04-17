#include "int_vec.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


vector_int::vector_int(int max_elems)
{
	array = (int *)malloc(max_elems*sizeof(int));
	length = 0;
	maximumSize = max_elems;
	printf("constructor\n");
}

int vector_int::add(int elem)
{
	if (length >= maximumSize)
	{
		int newMaxSize = length + 100;
		int *newArray = (int *)malloc(newMaxSize*sizeof(int));
		if (newArray == NULL)
		{
			return 2;
		}
		memcpy(newArray,array,length*sizeof(int));
		free(array);
		array = newArray;
		maximumSize = newMaxSize;
	}
	// 0 elements - index 0
	// 1 element  - index 1
	array[length] = elem;
	length++;
	return 0;
}

void vector_int::display()
{
	int i;
	printf("[");
	for(i=0;i<length;i++)
	{
		printf("%d,",array[i]);
	}
	printf("]\n");
}

vector_int::~vector_int()
{
	if (array != NULL)
	{
		free(array);
	}
	printf("destructor\n");
}

