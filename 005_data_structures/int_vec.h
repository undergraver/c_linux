#pragma once

struct vector_int_c {
	int length;
	int maximumSize;
	int *array;
};

int vector_init(struct vector_int_c* newVec,int max_elems);
struct vector_int_c* vector_new(int max_elems);
int vector_add(struct vector_int_c* v,int elem);
void vector_display(struct vector_int_c* v);
void vector_free_internal(struct vector_int_c*v);
void vector_free(struct vector_int_c* v);
