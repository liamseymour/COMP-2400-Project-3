/* This is a test driver for new_string.c, a re-implementation of the c string library.
 * Authors: Jarrett Gorecki, Liam Seymour 
 *
 * This file should not be included in the final submission.
 *
 * READ-ME: 
 * 	Adding a new test case is mildly convoluted. In each test function,
 * 	there are 1 or 2 arrays of arguments, this is for arguments of different types,
 * 	if two arguments share a type then they can be included in one 2d array. 
 * 	If a case is added then the case count needs to be incremented.
 */ 

#include <stdio.h>
#include <string.h>
#include "new_string.h"

#define MAX_LEN 2500

int test_new_strcpy(void);
int test_new_strncpy(void);
int test_new_strcmp(void);
int test_new_strncmp(void);
int test_new_strcat(void);
int test_new_strncat(void);
int test_new_strlen(void);
int test_new_strchr(void);
int test_new_strstr(void);

int main(void) 
{
	int functionsPassed = 0;
	const int functions = 9;

	if (test_new_strcpy()) {
		functionsPassed++;
	}

	if (test_new_strncpy()) {
		functionsPassed++;
	}
	
	if (test_new_strcmp()) {
		functionsPassed++;
	}
	
	if (test_new_strncmp()) {
		functionsPassed++;
	}
	
	if (test_new_strcat()) {
		functionsPassed++;
	}

	if (test_new_strncat()) {
		functionsPassed++;
	}

	if (test_new_strlen()) {
		functionsPassed++;
	}

	if (test_new_strchr()) {
		functionsPassed++;
	}

	if (test_new_strstr()) {
		functionsPassed++;
	}


	
	printf("\n%d of %d functions passed.\n", functionsPassed, functions);
	return 0;
}

// Tests:
// char* new_strcpy(char* destination, const char* source)
// Copies the characters from source into destination.
int test_new_strcpy(void)
{
	printf("\n####################### strcpy ########################\n\n");


    const int casesCount = 3;
    int passed = 0;
	/* 2nd parameter, source */
    char *cases[] = {
        "foobar", // normal
        "You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created.", // long
        "" // empty string
    };
	
	char ours[MAX_LEN];
	char theirs[MAX_LEN];
	for (int i = 0; i < casesCount; ++i) {
		new_strcpy(ours, cases[i]);
		strcpy(theirs, cases[i]);
		/* Pass */
		if (strcmp(ours, theirs) == 0) {
			passed++;
		} else {
            printf("Test Case failed on function new_strncpy() with arguments: (\"%s\")\n\tExpected: \"%s\"\n\tGot: \"%s\"\n",
				   cases[i], theirs, ours);
		}
	}
	
	printf("%d of %d tests passed for new_strcpy.\n", passed, casesCount);
	return casesCount == passed;
}

// Tests:
// char* new_strncpy(char* destination, const char* source, size_t n)
// Copies the first n characters from source into destination. If the 
// function hits a null character in source before it has copied n 
// characters, the remaining characters are filled with null characters.
int test_new_strncpy(void)
{
	printf("\n####################### strncpy #######################\n\n");


    const int casesCount = 6;
    int passed = 0;
	/* 2nd parameter, source */
    char *cases1[] = {
        "foobar", 
        "You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created.", 
        "", 
		"foobar",
		"foobar",
		""
    };
	/* 3rd parameter, n */
	int cases2[] = {
		3,
		40,
		0,
		6,
		10,
		5
	};
	
	char ours[MAX_LEN];
	char theirs[MAX_LEN];
	for (int i = 0; i < casesCount; ++i) {
		new_strncpy(ours, cases1[i], cases2[i]);
		strncpy(theirs, cases1[i], cases2[i]);
		/* Pass */
		if (strcmp(ours, theirs) == 0) {
			passed++;
		/* Fail */
		} else {
            printf("Test Case failed on function new_strncpy() with arguments: (\"%s\", %d)\n\tExpected: \"%s\"\n\tGot: \"%s\"\n",
				   cases1[i], cases2[i], theirs, ours);
		}
	}
	
	printf("%d of %d tests passed for new_strncpy.\n", passed, casesCount);
	return casesCount == passed;
}

// Tests:
// int new_strcmp(const char* string1, const char* string2)
// Compares two strings. The return value is positive if string1 comes 
// after string2 alphabetically, negative if string1 comes before string2 
// alphabetically, and 0 if the two strings are equal.
int test_new_strcmp(void)
{
	printf("\n####################### strcmp ########################\n\n");


    const int casesCount = 8;
    int passed = 0;
	/* both parameters, string1 and string2*/
    char *cases[][2] = {
		{"foobar", "foobar"},
		{"foobar", "FOOBAR"},
		{"You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created.", "You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created." },
		{"You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created.", "You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created...." },
		{"", ""},
		{"foobaz", ""},
		{"", "foobar"},
		{"1234", "12345"}
    };
	
	int ours;
	int theirs;
	for (int i = 0; i < casesCount; ++i) {
		ours = new_strcmp(cases[i][0], cases[i][1]);
		theirs = strcmp(cases[i][0], cases[i][1]);
		/* Pass */
		if (ours == theirs) {
			passed++;
		/* Fail */
		} else {
            printf("Test Case failed on function new_strcmp() with arguments: (\"%s\", \"%s\")\n\tExpected: %d\n\tGot: %d\n",
				   cases[i][0], cases[i][1], theirs, ours);
		}
	}
	
	printf("%d of %d tests passed for new_strcmp.\n", passed, casesCount);
	return casesCount == passed;
}

// Tests:
// int new_strncmp(const char* string1, const char* string2, size_t n)
// Compares two strings exactly like new_strcmp(), except comparing at 
// most the first n characters.
int test_new_strncmp(void) 
{
	printf("\n####################### strncmp #######################\n\n");


    const int casesCount = 9;
    int passed = 0;
	/* string1 and string2 */
    char *cases1[][2] = {
		{"foobar", "foobar"},
		{"foobar", "FOOBAR"},
		{"You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created.", "You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created." },
		{"You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created.", "You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created...." },
		{"", ""},
		{"foobaz", ""},
		{"", "foobar"},
		{"1234", "12345"},
		{"Joe", "Max"}
    };

	/* n */
	int cases2[] = {
		6,
		6,
		40,
		40,
		0,
		3,
		10,
		4,
		0
	};
	
	int ours;
	int theirs;
	for (int i = 0; i < casesCount; ++i) {
		ours = new_strncmp(cases1[i][0], cases1[i][1], cases2[i]);
		theirs = strncmp(cases1[i][0], cases1[i][1], cases2[i]);
		/* Pass */
		if (ours == theirs) {
			passed++;
		/* Fail */
		} else {
            printf("Test Case failed on function new_strncmp() with arguments: (\"%s\", \"%s\", %d)\n\tExpected: %d\n\tGot: %d\n",
				   cases1[i][0], cases1[i][1], cases2[i], theirs, ours);
		}
	}
	
	printf("%d of %d tests passed for new_strncmp.\n", passed, casesCount);
	return casesCount == passed;
}

// Tests:
// char* new_strcat(char* destination, const char* source)
// Adds the string contained in source to the end of the string contained 
// in destination. The values in destination are modified, but a pointer 
// to destination is also returned.
int test_new_strcat(void)
{
	printf("\n####################### strcat ########################\n\n");


    const int casesCount = 9;
    int passed = 0;
	/* destination and source */
    char *cases[][2] = {
		{"foobar", "foobar"},
		{"foobar", "FOOBAR"},
		{"You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created.", "You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created." },
		{"You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created.", "You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created...." },
		{"", ""},
		{"foobaz", ""},
		{"", "foobar"},
		{"1234", "12345"},
		{"Joe", "Max"}
    };
	
	char ours[MAX_LEN];
	char theirs[MAX_LEN];
	for (int i = 0; i < casesCount; ++i) {
		strcpy(ours, cases[i][0]); // write destination into ours
		strcpy(theirs, cases[i][0]); // write destination into theirs
		
		new_strcat(ours, cases[i][1]);
		strcat(theirs, cases[i][1]);

		/* Pass */
		if (strcmp(ours, theirs) == 0) {
			passed++;
		/* Fail */
		} else {
            printf("Test Case failed on function new_strcat() with arguments: (\"%s\", \"%s\")\n\tExpected: \"%s\"\n\tGot: \"%s\"\n",
				   cases[i][0], cases[i][1], theirs, ours);
		}
	}
	
	printf("%d of %d tests passed for new_strcat.\n", passed, casesCount);
	return casesCount == passed;

}

// Tests:
// char* new_strncat(char* destination, const char* source, size_t n)
// Adds the string contained in source to the end of the string contained 
// in destination, but adding a maximum of n characters.
int test_new_strncat(void)
{
	printf("\n####################### strncat #######################\n\n");


    const int casesCount = 9;
    int passed = 0;
	/* destination and source */
    char *cases1[][2] = {
		{"foobar", "foobar"},
		{"foobar", "FOOBAR"},
		{"You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created.", "You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created." },
		{"You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created.", "You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created...." },
		{"", ""},
		{"foobaz", ""},
		{"", "foobar"},
		{"1234", "12345"},
		{"Joe", "Max"}
    };

	/* n */
	int cases2[] = {
		3,
		6,
		40,
		1000,
		0,
		4,
		10,
		123,
		3
	};
	
	char ours[MAX_LEN];
	char theirs[MAX_LEN];
	for (int i = 0; i < casesCount; ++i) {
		strcpy(ours, cases1[i][0]); // write destination into ours
		strcpy(theirs, cases1[i][0]); // write destination into theirs
		
		new_strncat(ours, cases1[i][1], cases2[i]);
		strncat(theirs, cases1[i][1], cases2[i]);

		/* Pass */
		if (strcmp(ours, theirs) == 0) {
			passed++;
		/* Fail */
		} else {
            printf("Test Case failed on function new_strncat() with arguments: (\"%s\", \"%s\", %d)\n\tExpected: \"%s\"\n\tGot: \"%s\"\n",
				   cases1[i][0], cases1[i][1], cases2[i], theirs, ours);
		}
	}
	
	printf("%d of %d tests passed for new_strncat.\n", passed, casesCount);
	return casesCount == passed;

}

// Tests:
// size_t new_strlen(const char* string)
// Returns the number of characters in string before the null character.
int test_new_strlen(void)
{
	printf("\n####################### strlen ########################\n\n");


    const int casesCount = 3;
    int passed = 0;
	/* 2nd parameter, source */
    char *cases[] = {
        "foobar", 
        "You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created.", 
        "" 
    };
	
	int ours;
	int theirs;
	for (int i = 0; i < casesCount; ++i) {
		ours = new_strlen(cases[i]);
		theirs = strlen(cases[i]);
		/* Pass */
		if (ours == theirs) {
			passed++;
		} else {
            printf("Test Case failed on function new_strlen() with arguments: (\"%s\")\n\tExpected: %d\n\tGot: %d\n",
				   cases[i], theirs, ours);
		}
	}
	
	printf("%d of %d tests passed for new_strlen.\n", passed, casesCount);
	return casesCount == passed;
}

// Tests:
// char* new_strchr(const char* string, int character)
// Returns a pointer to the first occurrence of character in string or a 
// NULL pointer if character cannot be found.
int test_new_strchr(void)
{
	printf("\n####################### strchr ########################\n\n");


    const int casesCount = 6;
    int passed = 0;
	/* string */
    char *cases1[] = {
		"Where is the sem;colon?",
		"foobar",
		"fizzbuzz",
		" ",
		"Hello world!",
		"string"
    };
	/* character */
	int cases2[] = {
		';',
		'o',
		'o',
		' ',
		'!',
		'\0'
	};
	
	char *ours;
	char *theirs;
	for (int i = 0; i < casesCount; ++i) {
		ours = new_strchr(cases1[i], cases2[i]);
		theirs = strchr(cases1[i], cases2[i]);

		/* Pass */
		if (ours == theirs) {
			passed++;
		/* Fail */
		} else {
            printf("Test Case failed on function new_strchr() with arguments: (\"%s\", \"%c\")\n\tExpected: %p\n\tGot: %p\n",
				   cases1[i], cases2[i], theirs, ours);
		}
	}
	
	printf("%d of %d tests passed for new_strchr.\n", passed, casesCount);
	return casesCount == passed;
}

// Tests:
// char* new_strstr(const char* haystack, const char* needle)
// Returns a pointer to the first occurrence of the string contained in 
// needle in haystack or a NULL pointer if needle cannot be found.
int test_new_strstr(void)
{
	printf("\n####################### strstr ########################\n\n");


    const int casesCount = 9;
    int passed = 0;
	/* needle and haystack */
    char *cases[][2] = {
		{"foobar", "oba"},
		{"foobar", "FOOBAR"},
		{"You can decide what you want to do in life, but I suggest doing "
		"something that creates. Something that leaves a tangible thing once "        
		"you're done. That way even after you're gone, you will still live on "
        "in the things you created.", "That way "},
		{"FOOBAR", ""},
		{"", ""},
		{"foobaz", ""},
		{"", "foobar"},
		{"1234", "12345"},
		{"Joe", "Max"}
    };
	
	char *ours;
	char *theirs;
	for (int i = 0; i < casesCount; ++i) {
		ours = new_strstr(cases[i][0], cases[i][1]);
		theirs = strstr(cases[i][0], cases[i][1]);
		/* Pass */
		if (ours == theirs) {
			passed++;
		/* Fail */
		} else {
            printf("Test Case failed on function new_strstr() with arguments: (\"%s\", \"%s\")\n\tExpected: %p\n\tGot: %p\n",
				   cases[i][0], cases[i][1], theirs, ours);
		}
	}
	
	printf("%d of %d tests passed for new_strstr.\n", passed, casesCount);
	return casesCount == passed;
}
