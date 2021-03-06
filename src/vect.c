/*
 * vect.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vect.h"
#include "error.h"

/**
 * Increases the maximum size of the vector.
 * By default, Vector size will be expanded if it reaches 75% capacity
 *
 * @param v a Vector pointer.
 */
static void expand(Vector *v) {
	if (v->size == v->total * INCREMENT_THRESHOLD && v->total < MAX_SIZE) {
		char **new_elements = realloc(v->elements, (v->total + INCREMENT_SIZE) * sizeof(char *));
		check_null(new_elements);

		v->elements = new_elements;
		v->total += INCREMENT_SIZE;
	}
}

/**
 * Decreases the maximum size of the vector.
 * By default, Vector size will be reduced if it is only 50% full
 *
 * @param v a Vector pointer.
 */
static void shrink(Vector *v) {
	if (v->size == v->total * DECREMENT_THRESHOLD && v->total > STARTING_SIZE) {
		char **new_elements = realloc(v->elements, (v->total - DECREMENT_SIZE) * sizeof(char *));
		check_null(new_elements);

		v->elements = new_elements;
		v->total -= DECREMENT_SIZE;
	}
}

Vector *new() {
	Vector *v = calloc(1, sizeof(Vector));
	check_null(v);
	char **elements = calloc(STARTING_SIZE, sizeof(char *));
	check_null(elements);

	v->size = 0;
	v->total = STARTING_SIZE;
	v->elements = elements;
	return v;
}

bool is_empty(const Vector *v) {
	return v->size <= 0;
}

bool is_full(const Vector *v) {
	return v->size == MAX_SIZE;
}

void push(Vector *v, const char *data) {
	check_null(v);

	if (!is_full(v)) {
		char *data_ptr = calloc(sizeof(data), sizeof(char));
		check_null(data_ptr);
		strcpy(data_ptr, data);

		v->elements[v->size] = data_ptr;
		v->size ++;
		expand(v);
	}
}

void pop(Vector *v) {
	check_null(v);

	if (!is_empty(v)) {
		v->elements[v->size - 1] = '\0';
		v->size --;
		shrink(v);
	}
}

char *get(const Vector *v, const int index) {
	check_null(v);
	check_index(v->size, index);

	if (is_empty(v)) {
		return NULL;
	}

	return v->elements[index];
}

int find(const Vector *v, const char *data) {
	check_null(v);
	check_null(data);

	for (int i = 0; i < v->size; ++ i) {
		if (!strcmp(v->elements[i], data)) {
			return i;
		}
	}

	return -1;
}

int find_n(const Vector *v, const char *data) {
	check_null(v);
	check_null(data);
	int count = 0;

	for (int i = 0; i < v->size; ++ i) {
		if (!strcmp(v->elements[i], data)) {
			count ++;;
		}
	}

	return count;
}

void replace(Vector *v, const int index, const char *data) {
	check_null(v);
	check_null(data);
	check_index(v->size, index);

	/* allocate memory for new data */
	char *data_ptr = calloc(sizeof(data), sizeof(char));
	check_null(data_ptr);
	strcpy(data_ptr, data);

	/* free existing memory before assigning new pointer */
	free(v->elements[index]);
	v->elements[index] = data_ptr;
}

void clear(Vector *v) {
	check_null(v);

	if (!is_empty(v)) {
		memset(v, '\0', sizeof(v));
		v->total = STARTING_SIZE;
	}
}

void print(const Vector *v) {
	check_null(v);

	if (!is_empty(v)) {
		printf("[ ");

		for (int i = 0; i < v->size; ++ i) {
			printf("%s", get(v, i));

			/* comma formatting */
			if (i != v->size - 1) {
				printf(", ");
			}
		}

		printf(" ]\n");
	} else {
		printf("[]\n");
	}
}
