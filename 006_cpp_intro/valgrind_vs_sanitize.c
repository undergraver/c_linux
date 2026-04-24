#include <string.h>

int main(void)
{
	int a;
	char buf[10];
	int b;

	memset(buf,0,11); // valgrind doesn't find this, as it treats memory like a block (memory is on stack in this case)
			  // but -fsanitize=address finds this as it instruments the code
	return 0;
}
