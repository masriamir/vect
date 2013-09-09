/**
 * error.h
 */

#include <stdbool.h>

/**
 * Enum for all error codes.
 */
typedef enum {
	E_NULL, /**< null pointer */
	E_INDEX /**< index out of bounds */
} error_code;

/**
 * Tests whether a pointer is null.
 *
 * @param ptr a void pointer.
 * @return True if the pointer is null.
 */
bool is_null(const void *ptr);

/**
 * Tests whether an index is valid.
 *
 * @param size the current size.
 * @param index the specified index.
 * @return True if the index is positive and less than size.
 */
bool is_valid_index(const int size, const int index);

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

/**
 * Prints an appropriate error message and exits.
 *
 * @param e the error code.
 */
void error(const error_code e);
