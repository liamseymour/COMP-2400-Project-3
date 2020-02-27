/*******************************
 *
 *  Project Name: Project 3: String 'Em Up
 *  Description: Re-implementing the c string library.
 *  File names: new_string.c, new_string.h
 *  Date: Friday, February 28, 2020 at 11:59 p.m.
 *  Authors: Jarrett Gorecki, Liam Seymour
 *
 *******************************/

#include <stddef.h>
#include "new_string.h"

/*
Description: The new_strcpy() function copies the string pointed to by 
			 source, including the terminating null byte ('\0'), to the buffer
			 pointed to by  destination.
       		 
			 The  strings may not overlap, and the destination string 
			 destination must be large enough to receive the copy.

Parameters:  Source - String to be copied.
			 Destination - String to be copied into.

Returns: 	 The new-strcpy() function returns a pointer to the destination 
			 string destination.
*/
char* new_strcpy(char* destination, const char* source) {
	
}

/*
Description: The new_strncpy() function copies the string pointed to by 
			 source, including the terminating null byte ('\0'), to the buffer
			 pointed to by  destination.
       		 
			 The  strings may not overlap, and the destination string 
			 destination must be large enough to receive the copy.

		     At most n bytes of source are copied.  Warning: If there is 
			 no null byte  among  the  first  n bytes of source, the string 
			 placed in destination will not be null-terminated.

Parameters:  Source - String to be copied.
			 Destination - String to be copied into.
			 n - Max number of bytes to be copied.

Returns: 	 The new-strncpy() function returns a pointer to the destination 
			 string destination.
*/
char* new_strncpy(char* destination, const char* source, size_t n) {

}

/*
Description: The new_strcmp() function Compares two strings.
			 Compares the two strings string1 and string2.  It returns
       		 an integer less than, equal to, or greater than zero if string1 
			 is found, respectively, to be less than, to match, or be greater 
			 than string2.

Parameters:  string1, string2 - strings to be compared
Returns:     The new_strcmp() function returns the difference between strings
			 as described by description.
*/
int new_strcmp(const char* string1, const char* string2) {

}

/*
Description: The new_strncmp() function Compares two strings.
			 Compares the two strings string1 and string2.  It returns
       		 an integer less than, equal to, or greater than zero if string1 
			 is found, respectively, to be less than, to match, or be greater 
			 than string2.

			 Compares only the first (at most) n bytes of s1 and s2.

Parameters:  string1, string2 - strings to be compared
			 n - Max number of bytes to be compared.

Returns:     The new_strncmp() function returns the difference between strings
			 as described by description.
*/
int new_strncmp(const char* string1, const char* string2, size_t n) {

}

/*
Description: The new_strcat() function appends  the  source string to the 
			 destination string, overwriting the terminating null byte ('\0') 
			 at the end of destination, and then  adds a terminating null 
			 byte.  The strings may not overlap, and the  destination string 
			 must have enough space for the result. If  destination is not  
			 large enough, program behavior is unpredictable.

Returns: 	 The new_strcat() function returns a pointer to the  resulting 
			 string destination.
*/
char* new_strcat(char* destination, const char* source) {
	return new_strncat(destination, source, new_strlen(source));
}

/*
Description: The new_strncat() function appends  the  source string to the 
			 destination string, overwriting the terminating null byte ('\0') 
			 at the end of destination, and then  adds a terminating null 
			 byte.  The strings may not overlap, and the  destination string 
			 must have enough space for the result. If  destination is not  
			 large enough, program behavior is unpredictable.

			 The  strncmp() function is similar, except it compares only 
			 the first (at most) n bytes of string1 and string2.

Parameters:  n - Max number of bytes to use from source.
Returns: 	 The new_strncat() function returns a pointer to the  resulting 
			 string destination.
*/
char* new_strncat(char* destination, const char* source, size_t n) {
	int destinEnd = new_strlen(destination); //position of null char in destination
	
	int i = 0; 
	while(source[i] != '\0' && i < n)
	{
		destination[destinEnd + i] = source[i];
		i++;
	}

	destination[destinEnd + i] = '\0';
	return destination;
}

/*
Description: The  new_strlen() function calculates the length of the string 
			 pointed to by string, excluding the terminating null byte ('\0').

Returns: 	 The new_strlen() function returns the number of characters in 
			 the  string pointed to by string.
*/
size_t new_strlen(const char* string) {
    size_t i;
    for (i = 0; string[i] != '\0'; ++i);
    return i;
}

/*
Description: The  new_strchr()  function  returns a pointer to the first 
			 occurrence of the character c in the string s.

Parameters:  string - string to be searched in.
			 character - characters to be found in string.

Returns:     The new_strchr() function returns a pointer to the  
			 matched character  or  NULL  if  the character is not found.  
			 The terminating null byte is considered part of the string, so 
			 that if c is specified as '\0', these functions return a 
			 pointer to the terminator.
*/
char* new_strchr(const char* string, int character) {

}

/*
Description: The  new_strstr()  function  finds  the first occurrence of the 
			 sub-string needle in the string haystack.  The terminating null 
			 bytes ('\0') are not compared.

Parameters:  needle - sub-string to be found in haystack.
			 haystack - string to be searched in for sub-string needle.

Returns: 	 The new_strstr() function returns a pointer to the beginning of 
			 the located sub-string, or NULL if the sub-string is not found.
*/
char* new_strstr(const char* haystack, const char* needle) {

}

