/*
 * vect.h
 */

#include <stdbool.h>

/**
 * Maximum size of the Vector.
 */
#define MAX_SIZE 128

/*
 * Vector struct.
 */
typedef struct Vector {
	int size; /**< current size of the Vector. */
	char *elements[MAX_SIZE]; /**< the elements of the Vector. */
} Vector;

/**
 * Initializes a new Vector.
 *
 * @return A Vector pointer.
 */
Vector *new();

/**
 * Tests whether a Vector is empty.
 *
 * @param v a Vector pointer.
 * @return True if the Vector is empty.
 */
bool is_empty(const Vector *v);

/**
 * Tests whether a Vector is full.
 *
 * @param v a Vector pointer.
 * @return True if the Vector is full.
 */
bool is_full(const Vector *v);

/**
 * Adds a new element to the Vector.
 *
 * @param v a Vector pointer.
 * @param data a char pointer to the data.
 */
void push(Vector *v, const char *data);

/**
 * Removes the last element from the Vector.
 *
 * @param v a Vector pointer.
 */
void pop(Vector *v);

/**
 * Gets the specified element of the Vector.
 *
 * @param v a Vector pointer.
 * @param index the index of the element.
 * @return The element.
 */
char *get(const Vector *v, const int index);

/**
 * Clears the contents of the Vector.
 *
 * @param v a Vector pointer.
 */
void clear(Vector *v);

/**
 * Displays the contents of the Vector.
 *
 * @param v a Vector pointer.
 */
void print(const Vector *v);
