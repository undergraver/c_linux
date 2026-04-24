#include "int_vec.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

template <typename T>

GenericVector<T>::GenericVector(int max_elems)
{
	allocate(max_elems);
	printf("constructor\n");
}

template <typename T>
GenericVector<T>::GenericVector(const GenericVector<T>& rightHandSide)
{
	printf("copy constructor\n");
	allocate(rightHandSide.maximumSize);
	std::copy(rightHandSide.array,rightHandSide.array+rightHandSide.length,array);
	length = rightHandSide.length;
}

template <typename T>
bool GenericVector<T>::allocate(int max_elems)
{
	array = new T[max_elems];
	length = 0;
	maximumSize = max_elems;
	printf("allocate %p\n",array);
	return (array != nullptr);
}

template <typename T>

const GenericVector<T>& GenericVector<T>::operator=(const GenericVector<T>& rightHandSide)
{
	printf("operator =\n");
	releaseMemory();
	allocate(rightHandSide.maximumSize);
	std::copy(rightHandSide.array,rightHandSide.array+rightHandSide.length,array);
	length = rightHandSide.length;
	return (*this);
}

template <typename T>
GenericVector<T> GenericVector<T>::operator+(const GenericVector<T>& rightHandSide)
{
	GenericVector<T> temp(maximumSize + rightHandSide.maximumSize);
	T* dest = temp.array;
	std::copy(array,array+length,dest);
	temp.length+=length;

	dest+=length;
	std::copy(rightHandSide.array,rightHandSide.array+rightHandSide.length,dest);

	temp.length+=rightHandSide.length;
	return temp;
}

template <typename T>
const GenericVector<T>& GenericVector<T>::operator+=(const GenericVector<T>& rightHandSide)
{
	// poor implementation when it comes down to performance - maybe
	for(int i=0;i<rightHandSide.length;i++)
	{
		add(rightHandSide.array[i]);
	}
	return *this;
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
	releaseMemory();
	printf("destructor\n");
}

template <typename T>

void GenericVector<T>::releaseMemory()
{
	if (array != NULL)
	{
		printf("release:%p\n",array);
		delete [] array;
	}
}


template class GenericVector<int>;
template class GenericVector<double>;

