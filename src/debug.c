#include <stdio.h>
#include "debug.h"

void debug(const Vector *v) {
	print(v);
	printf("Size: %d, Total: %d\n\n", v->size, v->total);
}
