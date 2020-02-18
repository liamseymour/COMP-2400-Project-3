/* This is a test driver for new_string.c, a re-implementation of the c string library.
 * Authors: Jarrett Gorecki, Liam Seymour 
 *
 * This file should not be included in the final submission.
 */ 

#include <stdio.h>
#include <string.h>
#include "new_string.h"

int main(void) 
{
	int testc = 0;
	int testpass = 0;	
	// Tests:
    // char* new_strcpy(char* destination, const char* source)
    // Copies the characters from source into destination.

	printf("%d of %d tests passed for new_strcpy.\n", testpass, testc);

	// Tests:
    // char* new_strncpy(char* destination, const char* source, size_t n)
    // Copies the first n characters from source into destination. If the 
	// function hits a null character in source before it has copied n 
	// characters, the remaining characters are filled with null characters.
	testc = testpass = 0;

	printf("%d of %d tests passed for new_strncpy.\n", testpass, testc);

	// Tests:
	// int new_strcmp(const char* string1, const char* string2)
	// Compares two strings. The return value is positive if string1 comes 
	// after string2 alphabetically, negative if string1 comes before string2 
	// alphabetically, and 0 if the two strings are equal.
	testc = testpass = 0;

	printf("%d of %d tests passed for new_strcmp.\n", testpass, testc);

	// Tests:
	// int new_strncmp(const char* string1, const char* string2, size_t n)
	// Compares two strings exactly like new_strcmp(), except comparing at 
	// most the first n characters.
	testc = testpass = 0;

	printf("%d of %d tests passed for new_strncmp.\n", testpass, testc);

	// Tests:
    // char* new_strcat(char* destination, const char* source)
    // Adds the string contained in source to the end of the string contained 
	// in destination. The values in destination are modified, but a pointer 
	// to destination is also returned.
	testc = testpass = 0;

	printf("%d of %d tests passed for new_strcat.\n", testpass, testc);

	// Tests:
    // char* new_strncat(char* destination, const char* source, size_t n)
    // Adds the string contained in source to the end of the string contained 
	// in destination, but adding a maximum of n characters.
	testc = testpass = 0;

	printf("%d of %d tests passed for new_strncat.\n", testpass, testc);

	// Tests:
    // size_t new_strlen(const char* string)
    // Returns the number of characters in string before the null character.
	testc = testpass = 0;

	printf("%d of %d tests passed for new_strlen.\n", testpass, testc);

	// Tests:
    // char* new_strchr(const char* string, int character)
    // Returns a pointer to the first occurrence of character in string or a 
	// NULL pointer if character cannot be found.
	testc = testpass = 0;

	printf("%d of %d tests passed for new_strchr.\n", testpass, testc);

	// Tests:
    // char* new_strstr(const char* haystack, const char* needle)
    // Returns a pointer to the first occurrence of the string contained in 
	// needle in haystack or a NULL pointer if needle cannot be found.
	testc = testpass = 0;

	printf("%d of %d tests passed for new_strstr.\n", testpass, testc);

	return 0;
}
