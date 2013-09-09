/*
 * vect.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vect.h"
#include "error.h"

Vector *new() {
	Vector *v = (Vector *) calloc(1, sizeof(Vector));
	check_null(v);

	v->size = 0;
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
		char *data_ptr = (char *) calloc(sizeof(data), sizeof(char));
		check_null(data_ptr);

		strcpy(data_ptr, data);
		v->elements[v->size] = data_ptr;
		v->size ++;
	}
}

void pop(Vector *v) {
	check_null(v);

	if (!is_empty(v)) {
		v->elements[v->size - 1] = '\0';
		v->size --;
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

void clear(Vector *v) {
	check_null(v);

	if (!is_empty(v)) {
		memset(v, '\0', sizeof(Vector));
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
