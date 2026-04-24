#pragma once

template <typename T>
class GenericVector {
public:
	GenericVector(int max_elems);
	GenericVector(const GenericVector<T>& rhs);
	~GenericVector();
	int add(T elem);
	void display();
	const GenericVector<T>& operator=(const GenericVector<T>& rightHandSide);
	GenericVector<T> operator+(const GenericVector<T>& rightHandSide);
	const GenericVector<T>& operator+=(const GenericVector<T>& rightHandSide);
private:
	void releaseMemory();
	bool allocate(int max_elems);
	int length;
	int maximumSize;
	T *array;
};

