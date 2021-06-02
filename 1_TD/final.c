#include <stdio.h>
#include "module.h"

int main()
{
	for (int i = 0; i < 10; i = addone(i)){
		printf("%i\n", i);
	}
}
