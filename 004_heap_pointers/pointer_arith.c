// explain in an example the definition of heap and pointers. show also pointers that point to stack variables, not only heap
#include <stdio.h>
#include <stdlib.h>

struct point2d {
    float x;
    float y;
};


int main(void) {
    int v = 9;
    int *p1 = &v;
    int *p = malloc(sizeof(int));  // heap allocation
    char buf[]="C++ course starts with C.";
    char *pchar = &buf[0];
    struct point2d fromAtoB[2] = { {0.0,0.0}, {1.1,1.1} };
    struct point2d *coord = fromAtoB;
    *p = 99;

    printf("*p = %d\n", *p);
    printf("sizeof(p) = %d\n", sizeof(p));
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("p1 = %p\n", p1);
    printf("p1+1 = %p\n", p1+1);
    printf("p1+5 = %p\n", p1+5);
    printf("p = %p\n", p);
    printf("pchar = %p\n", pchar);
    printf("pchar + 4 = %p\n", pchar + 4);
    printf("value at pchar + 4 = %c\n", *(pchar + 4));
    printf("Sizeof point2d:%d\n",sizeof(struct point2d));
    printf("coord = %p\n", coord);
    printf("coord+5 = %p\n", coord+5);

    printf("coord val= %f,%f\n", coord->x,coord->y);
    coord++;
    printf("coord + 1 1val= %f,%f\n", coord->x,coord->y);

    free(p);    // MUST free heap memory
    return 0;
}

