#include <stddef.h>
#include <string.h>
#include <malloc.h>
#include "utils.h"

static size_t split_count(char* str, char delim) {
	size_t count = 0;
	while(*str == delim && *str != '\0')
		++str;
	while(*str != '\0') {
		if(*str == delim) {
			++count;
			while(*str == delim && *str != '\0')
				++str;
		} else ++str;
	}
	return count + 1;
}

char** split(char* str, char delim) {
	if(str == NULL || delim == '\0')
		return NULL;
	size_t count = split_count(str, delim) + 1;

	// Allocate the array of strings
	char** res = calloc(count, sizeof(char*));
	if(res == NULL) return NULL;
	res[count - 1] = NULL;

	char* start = str, * end;
	size_t i = 0;
	while(*start == delim && *start != '\0')
		++start;
	while(*start != '\0') {
		if(*start != delim) {
			// Find where the string end
			end = start;
			while(*end != delim && *end != '\0')
				++end;

			// Allocate the string
			res[i++] = strndup(start, (unsigned long) (end - start));
			if(res[i - 1] == NULL) { // If allocation failed
				for(size_t j = 0; res[j] != NULL; ++j)
					free(res[j]);
				free(res);
				return NULL;
			}

			// Move the start pointer
			start = end;
		} else ++start; // Skip the delimiter
	}
	return res;
}

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
