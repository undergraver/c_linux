// can you make some examples of function calls and local variables to better understand the stack and how it works
//
// how do I debug with gdb the example with a, b, c functions
#include <stdio.h>

void c(int p) {
    int z = 3 + 2*p; // on the stack variable
    printf("In c: z = %d\n", z);
    printf("Address of z is:%p\n",&z);
}

void b(int param) {
    int y = 2 + param;// on the stack variable
    c(y);
    printf("Address of y is:%p\n",&y);
}

void a(int param) {
    char buf[10];
    int x = 0x123 + param;// on the stack variable
    b(x);
    printf("Address of x is:%p\n",&x);
}

int main(void) {
    a(1);
    return 0;
}

