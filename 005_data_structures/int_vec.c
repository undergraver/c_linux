#include "int_vec.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int vector_init(struct vector_int_c* newVec,int max_elems)
{
	if ( newVec == NULL )
	{
		return 1;
	}
	int * array = malloc(max_elems*sizeof(int));
	newVec->length = 0;
	newVec->maximumSize = max_elems;
	newVec->array = array;
	return 0;
}


struct vector_int_c* vector_new(int max_elems)
{
	struct vector_int_c * newVec = malloc(sizeof(struct vector_int_c));
	if(newVec == NULL)
	{
		// no memory available
		return NULL;
	}
	if( vector_init(newVec,max_elems) )
	{
		free(newVec);
		newVec = NULL;
	}
	return newVec;
}

int vector_add(struct vector_int_c* v,int elem)
{
	if(v == NULL)
	{
		return 1;
	}
	if (v->length >= v->maximumSize)
	{
		int newMaxSize = v->length + 100;
		int *newArray = malloc(newMaxSize*sizeof(int));
		if (newArray == NULL)
		{
			return 2;
		}
		memcpy(newArray,v->array,v->length*sizeof(int));
		free(v->array);
		v->array = newArray;
		v->maximumSize = newMaxSize;
	}
	// 0 elements - index 0
	// 1 element  - index 1
	v->array[v->length] = elem;
	v->length++;
	return 0;
}

void vector_display(struct vector_int_c* v)
{
	int i;
	if (v == NULL)
	{
		return;
	}
	printf("[");
	for(i=0;i<v->length;i++)
	{
		printf("%d,",v->array[i]);
	}
	printf("]\n");
}

void vector_free_internal(struct vector_int_c*v)
{
	if (v != NULL && v->array != NULL)
	{
		free(v->array);
	}
}


void vector_free(struct vector_int_c* v)
{
	if (v == NULL)
	{
		return;
	}
	vector_free_internal(v);
	free(v);
}
