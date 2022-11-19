#ifndef UTILS_H
#define UTILS_H

#include <string.h>

/**
 * Split a string into an NULL-terminated array of strings.
 * @param str The string to split.
 * @param delim The delimiter.
 * @return The array of strings (NULL-terminated).
 */
char** split(char* str, char delim);

int find(char** array, char* str);

char* concat__(const char* s, ...);
#define concat(...) concat__(__VA_ARGS__, NULL)

#endif //UTILS_H
