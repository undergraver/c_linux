#pragma once

class vector_int {
public:
	vector_int(int max_elems);
	~vector_int();
	int add(int elem);
	void display();
private:
	int length;
	int maximumSize;
	int *array;
};

