/*
 *  Verzeichnis.h
 *
 *  Created on: 29.11.2017
 *  Author: group work by RStyle and 2 fellow students
 */

#ifndef SABNAHME_H_
#define SABNAHME_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Verzeichnis {
	struct Verzeichnis *pFather;
	struct Verzeichnis *pChildren;
	struct Verzeichnis *pNext;
	char name[64];
};
struct VerzeichnisBaum {
	struct Verzeichnis *pRoot;
};


struct VerzeichnisBaum init(char rootName[]);
void insert(struct VerzeichnisBaum *tree, char fatherName[], char newName[]);
struct Verzeichnis* search(struct VerzeichnisBaum *tree, char dir[]);
void delete(struct VerzeichnisBaum *tree, char dir[]);
void print(struct VerzeichnisBaum tree);
void kill(struct VerzeichnisBaum *tree);


#endif /* SABNAHME_H_ */
