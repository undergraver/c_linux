// explain in an example the definition of heap and pointers. show also pointers that point to stack variables, not only heap
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int v = 9;
    int *p1 = &v;
    int *p = malloc(sizeof(int));  // heap allocation

    *p = 99;

    printf("*p = %d\n", *p);
    printf("sizeof(p) = %d\n", sizeof(p));
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("p1 = %p\n", p1);
    printf("p = %p\n", p);

    free(p);    // MUST free heap memory
    return 0;
}

