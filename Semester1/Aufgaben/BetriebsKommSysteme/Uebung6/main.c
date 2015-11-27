#include <stdio.h>
#include "mm.h"

int	main()
{
	status();
	void *mem1 = my_malloc(1000);
	status();
	void *mem2 = my_malloc(100);
	status();
	my_free(mem2);
	status();
	void *mem3 = my_malloc(6000);
	status();
	void *mem4 = my_malloc(2000);
	status();
	my_free(mem4);
	status();
	my_free(mem1);
	status();
	my_free(mem3);
	status();

	return 0;
}
