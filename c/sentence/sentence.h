/*
 * sentence.h
 *
 *  Created on: Nov 23, 2017
 *  Author: RStyle
 */

#ifndef SENTENCE_H_
#define SENTENCE_H_

struct word {
	char value[16];
	struct word* pPrevious;
	struct word* pNext;
};

struct sentence {
	struct word* pFirst;
	struct word* pLast;
};

struct sentence createEmptySentence();
void insertWordAtFront(struct sentence *mySentence, char value[16]);
void insertWordAtEnd(struct sentence *mySentence, char value[16]);
void insertWordAtPosition(struct sentence *mySentence, char value[16], int position);
struct sentence createSentenceFromArray(char myArray[][16], int quantity);
// deleted word.value will be safed in *pDeletedWord
void deleteWordAtFront(struct sentence *mySentence, char *pDeletedWord);
void deleteWordAtEnd(struct sentence *mySentence, char *pDeletedWord);
void deleteWordAtPosition(struct sentence *mySentence, char *pDeletedWord, int position);
void deleteSentence(struct sentence *mySentence);

#endif /* SENTENCE_H_ */
