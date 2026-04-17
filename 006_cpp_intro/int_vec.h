#pragma once

template <typename T>
class GenericVector {
public:
	GenericVector(int max_elems);
	~GenericVector();
	int add(T elem);
	void display();
private:
	int length;
	int maximumSize;
	T *array;
};

