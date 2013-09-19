/**
 * error.h
 */

#ifndef ERROR_H
#define ERROR_H

#include <stdbool.h>

/**
 * Enum for all error codes.
 */
typedef enum {
	E_NULL, /**< null pointer */
	E_INDEX /**< index out of bounds */
} error_code;

/**
 * Checks if a pointer is null.
 *
 * @param ptr a void pointer.
 */
void check_null(const void *ptr);

/**
 * Checks if an index is valid.
 *
 * @param size the current size.
 * @param index the specified index.
 */
void check_index(const int size, const int index);

#endif
