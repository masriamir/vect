#include <stdio.h>
#include <stdlib.h>
#include "vect.h"
#include "debug.h"

int main(int argc, char *argv[]) {
	/* create a new Vector */
	Vector *v = new();

	/* display initial contents */
	debug(v);

	/* add some data */
	push(v, "e1");
	push(v, "e2");
	debug(v);

	/* remove the last element */
	pop(v);
	debug(v);

	push(v, "e3");
	push(v, "e4");
	debug(v);

	/* clear the contents of the array */
	clear(v);
	debug(v);

	push(v, "e5");
	push(v, "e6");
	debug(v);

	/* grow the Vector */
	push(v, "e7");
	push(v, "e8");
	push(v, "e9");
	debug(v);

	push(v, "e10");
	push(v, "e11");
	push(v, "e12");
	debug(v);

	pop(v);
	pop(v);
	push(v, "e13");
	debug(v);

	/* shrink the Vector */
	pop(v);
	pop(v);
	pop(v);
	pop(v);
	debug(v);

	clear(v);
	debug(v);

	/* add elements to the Vector */
	for (int i = 0; i < MAX_SIZE / 4 + 4; ++ i) {
		char *buf;
		sprintf(buf, "e%d", i);
		push(v, buf);
	}

	debug(v);

	pop(v);
	pop(v);
	pop(v);
	pop(v);
	pop(v);
	pop(v);
	pop(v);
	pop(v);
	pop(v);
	pop(v);
	pop(v);
	pop(v);
	pop(v);
	pop(v);
	pop(v);
	pop(v);
	debug(v);

	/* replace elements of the Vector using find() */
	replace(v, find(v, "e6"), "e93");
	replace(v, find(v, "e11"), "");
	replace(v, 0, "e44");
	replace(v, 4, "e44");
	replace(v, 12, "e44");
	debug(v);

	/* check if elements exist */
	printf("# of 'e881': %d\n", find_n(v, "e881"));
	printf("# of 'e12': %d\n", find_n(v, "e12"));
	printf("# of '': %d\n", find_n(v, ""));
	printf("# of 'e44': %d\n\n", find_n(v, "e44"));

	/* get and print an element */
	char *e7 = get(v, 7);
	printf("v[7]: %s\n", e7);

	free(v);
	return 0;
}
