/*
 ============================================================================
 Name        : c_sentence.c
 Author      : RStyle
 Version     : 1.0
 Description : struct sentence in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "sentence.h"

int main(void) {
	printf("Fun with structs\n"); /* prints !!!Hello World!!! */

	char deletedWord[16];

	struct sentence sentence1 = createEmptySentence();
	insertWordAtFront(&sentence1, "3");
	insertWordAtFront(&sentence1, "2");
	insertWordAtFront(&sentence1, "1");
	insertWordAtPosition(&sentence1, "error", 8);
	insertWordAtPosition(&sentence1, "error", -8);
	printSentence(sentence1);
	insertWordAtPosition(&sentence1, "4", 3);
	insertWordAtPosition(&sentence1, "3.2", 3);
	insertWordAtPosition(&sentence1, "0", 0);
	insertWordAtPosition(&sentence1, "0.2", 1);
	insertWordAtEnd(&sentence1, "End");
	printSentence(sentence1);

	printf("delete at front: ");
	deleteWordAtFront(&sentence1, deletedWord);
	printf("deleted: '%s'\n", deletedWord);
	printf("delete at end: ");
	deleteWordAtEnd(&sentence1, deletedWord);
	printf("deleted: '%s'\n", deletedWord);
	printSentence(sentence1);

	char ch[][16] = {"C", "is", "fun"};
	struct sentence sentence2 = createSentenceFromArray(ch, 3);
	printf("createSentenceFromArray test: ");
	printSentence(sentence2);
	deleteWordAtPosition(&sentence2, deletedWord, 1);
	printf("deleted at pos[1]: '%s'\n", deletedWord);
	printSentence(sentence2);
	deleteWordAtPosition(&sentence2, deletedWord, 1);
	printf("deleted at pos[1]: '%s'\n", deletedWord);
	printSentence(sentence2);
	deleteWordAtPosition(&sentence2, deletedWord, 1);
	printf("deleted at pos[1]: '%s'\n", deletedWord);
	printSentence(sentence2);
	printf("deleteSentence and then print test: ");
	deleteSentence(&sentence1);
	printSentence(sentence1);

	return 0;
}
