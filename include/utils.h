#ifndef UTILS_H
#define UTILS_H

/**
 * Split a string into an NULL-terminated array of strings.
 * @param str The string to split.
 * @param delim The delimiter.
 * @return The array of strings (NULL-terminated).
 */
char** split(char* str, char delim);

#endif //UTILS_H
