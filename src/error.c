/*
 * error.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

bool is_null(const void *ptr) {
	return !ptr;
}

bool is_valid_index(const int size, const int index) {
	return !(index < 0 || index >= size);
}

void check_null(const void *ptr) {
	if (is_null(ptr)) {
		error(E_NULL);
	}
}

void check_index(const int size, const int index) {
	if (!is_valid_index(size, index)) {
		error(E_INDEX);
	}
}

void error(const error_code e) {
	char *msg;

	switch (e) {
		case E_NULL:
			msg = "Null pointer reference.";
			break;
		case E_INDEX:
			msg = "Index out of bounds.";
			break;
		default:
			msg = "Unhandled error.";
	}

	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}
