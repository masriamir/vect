/*
 * error.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

/**
 * Tests whether a pointer is null.
 *
 * @param ptr a void pointer.
 * @return True if the pointer is null.
 */
static bool is_null(const void *ptr) {
	return !ptr;
}

/**
 * Tests whether an index is valid.
 *
 * @param size the current size.
 * @param index the specified index.
 * @return True if the index is positive and less than size.
 */
static bool is_valid_index(const int size, const int index) {
	return !(index < 0 || index >= size);
}

/**
 * Prints an appropriate error message and exits.
 *
 * @param e the error code.
 */
static void error(const error_code e) {
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
