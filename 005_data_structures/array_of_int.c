#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "int_vec.h"



int main()
{
	int nElems;
	struct vector_int_c v;// = NULL;
	printf("How many elems:");
	scanf("%d",&nElems);

	vector_init(&v,nElems);
	for(int i=0;i<nElems;i++)
	{
		int val;
		scanf("%d",&val);
		if( vector_add(&v,val) )
		{
			fprintf(stderr,"Failed to insert element\n");
		}
	}
	vector_display(&v);
	vector_free_internal(&v);
	return 0;
}

