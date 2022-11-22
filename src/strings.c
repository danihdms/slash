#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include "string.h"

/**
 * Check if an array of strings contains a string.
 * @param array The array of strings.
 * @param str The string to find.
 * @return -1 if the string is not found, the index of the string otherwise.
 */
int find(char** array, char* str) {
	if(array == NULL || str == NULL)
		return -1;
	for(int i = 0; array[i] != NULL; ++i)
		if(strcmp(array[i], str) == 0)
			return i;
	return -1;
}

char* concat__(const char* s, ...) {
	if(s == NULL) return NULL;
	va_list args;
	size_t len = strlen(s);
	char* tmp;

	// Compute the length of the string
	va_start(args, s);
	while((tmp = va_arg(args, char *)) != NULL)
		len += strlen(tmp);
	va_end(args);

	// Allocate the string
	char* result = calloc(len + 1, sizeof(char));
	if(result == NULL) return NULL;

	// Concatenate the strings
	va_start(args, s);
	if(memmove(result, s, strlen(s) + 1) == NULL) {
		free(result);
		return NULL;
	}

	size_t j = strlen(s), l;
	while((tmp = va_arg(args, char *)) != NULL && result != NULL) {
		l = strlen(tmp);
		if(memmove(result + j, tmp, l + 1) == NULL) {
			free(result);
			return NULL;
		}
		j += l;
	}
	va_end(args);
	result[len] = '\0';
	return result;
}

#define INT_MAX_LENGTH 12

char* int_to_string(int i) {
	char* res = calloc(INT_MAX_LENGTH + 1, sizeof(char));
	if(res == NULL) return NULL;
	for(int j = 0; j < INT_MAX_LENGTH; ++j) {
		res[j] = (char) (i % 10 + '0');
		i /= 10;
		if(i == 0) break;
	}
	return res;
}
