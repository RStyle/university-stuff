/*
 * sentence.c
 *
 *  Created on: Nov 23, 2017
 *  Author: RStyle
 */

#include <stdio.h>
#include <stdlib.h>
#include "sentence.h"

struct sentence createEmptySentence() {
	return (struct sentence){NULL,NULL};
}

int countWordsInSentence(struct sentence mySentence) {
	int c = 0;
	if(mySentence.pFirst != NULL) {
		struct word* pWord = mySentence.pFirst;
		do {
			c++;
			pWord = pWord->pNext;
		} while(pWord != mySentence.pFirst);
	}
	return c;
}

void insertWordAtFront(struct sentence *mySentence, char value[16]) {
	insertWordAtPosition(mySentence, value, 0);
}

void insertWordAtEnd(struct sentence *mySentence, char value[16]) {
	insertWordAtPosition(mySentence, value, countWordsInSentence(*mySentence));
}

void insertWordAtPosition(struct sentence *mySentence, char value[16], int position) {
	int count = countWordsInSentence(*mySentence);
	struct word* pInputWord = (struct word*) malloc(sizeof(struct word));
	strcpy(pInputWord->value, value);

	if(position == 0) {	// insert Word At Front
		if(mySentence->pFirst == NULL) {
			pInputWord->pNext = pInputWord->pPrevious = pInputWord;
			mySentence->pFirst = mySentence->pLast = pInputWord;
		} else {
			pInputWord->pNext = mySentence->pFirst;
			pInputWord->pPrevious = mySentence->pLast;
			mySentence->pFirst->pPrevious = pInputWord;
			mySentence->pLast->pNext = pInputWord;
			mySentence->pFirst = pInputWord;
		}
	} else if(mySentence->pFirst != NULL) {
		if(position > 0 && position < count) {	//insert Word between Front and End
				struct word* pWord = mySentence->pFirst;
				for(int i = 0; i < position - 1; i++) {
					pWord = pWord->pNext;
				}
				// now pWord is the Word at position-1
				pInputWord->pPrevious = pWord;
				pInputWord->pNext = pWord->pNext;
				pWord->pNext->pPrevious = pInputWord;
				pWord->pNext = pInputWord;
		} else if(position == count) {	// insert Word At End
			pInputWord->pNext = mySentence->pFirst;
			pInputWord->pPrevious = mySentence->pLast;
			mySentence->pLast->pNext = pInputWord;
			mySentence->pFirst->pPrevious = pInputWord;
			mySentence->pLast = pInputWord;
		} else {
			printf("Insert Error: position %d out of Bounce[0-%d]\n", position, count-1);
			free(pInputWord);
		}
	} else {
		printf("Insert Error: position %d out of Bounce, sentence is empty\n", position);
		free(pInputWord);
	}
}

// printSentence iterative, recursive with auxiliary function recPrintSentence also possible
void printSentence(struct sentence mySentence) {
	if(mySentence.pFirst != NULL) {
		struct word* pWord = mySentence.pFirst;
		do {
		printf("%s\t", pWord->value);
		pWord = pWord->pNext;
		} while (pWord != mySentence.pFirst);
		printf("\n");
	} else {
		printf("Print Error: empty list\n");
	}
}

struct sentence createSentenceFromArray(char myArray[][16], int quantity) {
	if(quantity > 0) {
		struct sentence mySentence = createEmptySentence();
		for(int i = 0; i < quantity; i++) {
			insertWordAtEnd(&mySentence, myArray[i]);
		}
		return mySentence;
	}
	return createEmptySentence();
}

void deleteWordAtFront(struct sentence *mySentence, char *pDeletedWord) {
	deleteWordAtPosition(mySentence, pDeletedWord, 0);
}

void deleteWordAtEnd(struct sentence *mySentence, char *pDeletedWord) {
	deleteWordAtPosition(mySentence, pDeletedWord, countWordsInSentence(*mySentence) - 1);
}

void deleteWordAtPosition(struct sentence *mySentence, char *pDeletedWord, int position) {
	int count = countWordsInSentence(*mySentence);
	if(mySentence->pLast != NULL) {
		if(position == 0) {
			strcpy(pDeletedWord, mySentence->pFirst->value);
			if(mySentence->pFirst == mySentence->pLast) {	// only 1 element in sentence
				free(mySentence->pFirst);
				mySentence->pFirst = mySentence->pLast = NULL;
			} else if(mySentence->pFirst->pNext == mySentence->pLast) {	// 2 elements in sentence
				free(mySentence->pFirst);
				mySentence->pFirst = mySentence->pLast;
				mySentence->pFirst->pNext = mySentence->pFirst->pPrevious = mySentence->pFirst;
			} else {	// more than 2 elements in sentence
				mySentence->pLast->pNext = mySentence->pFirst->pNext;
				free(mySentence->pFirst);
				mySentence->pFirst = mySentence->pLast->pNext;
				mySentence->pFirst->pPrevious = mySentence->pLast;
			}
		} else if(position > 0 && position < count - 1) {
			struct word* pWord = mySentence->pFirst;
			for(int i = 0; i < position; i++) {
				pWord = pWord->pNext;
			}
			// now pWord is the Word at position "position"
			strcpy(pDeletedWord, pWord->value);
			pWord->pPrevious->pNext = pWord->pNext;
			pWord->pNext->pPrevious = pWord->pPrevious;
			free(pWord);
		} else if(position == count - 1) {
			strcpy(pDeletedWord, mySentence->pLast->value);
			// deleting last element when only 1 element in sentence is already done at "if(position == 0)"
			if(mySentence->pFirst->pNext == mySentence->pLast) {	// 2 elements in sentence
				free(mySentence->pLast);
				mySentence->pLast = mySentence->pFirst;
				mySentence->pFirst->pNext = mySentence->pFirst->pPrevious = mySentence->pFirst;
			} else {	// more than 2 elements in sentence
				mySentence->pFirst->pPrevious = mySentence->pLast->pPrevious;
				free(mySentence->pLast);
				mySentence->pLast = mySentence->pFirst->pPrevious;
				mySentence->pLast->pNext = mySentence->pFirst;
			}
		} else {
			printf("Delete Error: position %d out of Bounce[0-%d]\n", position, count-1);
			strcpy(pDeletedWord, "");
		}
	} else {
		printf("Delete Error: sentence is empty\n");
		strcpy(pDeletedWord, "");
	}
}

void deleteSentence(struct sentence *mySentence) {
	char ch[16];
	while(mySentence->pFirst != NULL) {
		deleteWordAtFront(mySentence, ch);
	}
}
