/*
 * vect.h
 */

#ifndef VECT_H
#define VECT_H

#include <stdbool.h>

/** Maximum size of the Vector. */
#define MAX_SIZE 128

 /** Starting size of the Vector. */
#define STARTING_SIZE 8

/** Amount to increase Vector size by. */
#define INCREMENT_SIZE 8

/** Capacity filled before increasing Vector size. */
#define INCREMENT_THRESHOLD 0.75

/** Amount to decrease Vector size by. */
#define DECREMENT_SIZE 8

/** Capacity filled before decreasing Vector size. */
#define DECREMENT_THRESHOLD 0.50

/*
 * Vector struct.
 */
typedef struct Vector {
	int size; /**< current size of the Vector. */
	int total; /**< total size of the Vector. */
	char **elements; /**< the elements of the Vector. */
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
 * Determines if the given data is contained within the Vector.
 *
 * @param v a Vector pointer.
 * @param data a char pointer to the data.
 * @return The index into the Vector if found, -1 otherwise.
 */
int find(const Vector *v, const char *data);

/**
 * Counts the number of occurrences of the given data.
 *
 * @param v a Vector pointer.
 * @param data a char pointer to the data.
 * @return The number of occurrences.
 */
int find_n(const Vector *v, const char *data);

/**
 * Replaces the element at the specified index with the new data.
 *
 * @param v a Vector pointer.
 * @param index the index of the element to replace.
 * @param data a char pointer to the data.
 */
void replace(Vector *v, const int index, const char *data);

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

#endif
