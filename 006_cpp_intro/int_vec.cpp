#include "int_vec.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

template <typename T>

GenericVector<T>::GenericVector(int max_elems)
{
	array = new T[max_elems];
	length = 0;
	maximumSize = max_elems;
	printf("constructor\n");
}

template <typename T>

int GenericVector<T>::add(T elem)
{
	if (length >= maximumSize)
	{
		int newMaxSize = length + 100;
		T *newArray = new T[newMaxSize];
		if (newArray == NULL)
		{
			return 2;
		}
		memcpy(newArray,array,length*sizeof(T));
		delete [] array;
		array = newArray;
		maximumSize = newMaxSize;
	}
	// 0 elements - index 0
	// 1 element  - index 1
	array[length] = elem;
	length++;
	return 0;
}

template <typename T>

void GenericVector<T>::display()
{
	int i;
	cout << "[";
	for(i=0;i<length;i++)
	{
		cout << array[i] << ",";
	}
	cout << "]\n";
}

template <typename T>

GenericVector<T>::~GenericVector()
{
	if (array != NULL)
	{
		delete [] array;
	}
	printf("destructor\n");
}


template class GenericVector<int>;
template class GenericVector<double>;

