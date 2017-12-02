/*
 *  Verzeichnis.c
 *
 *  Created on: 29.11.2017
 *  Author: group work by RStyle and 2 fellow students
 */

#include "Verzeichnis.h"

struct Verzeichnis* searchDir(struct Verzeichnis *curDir, char dir[]);


struct VerzeichnisBaum init(char rootName[]) {
	struct VerzeichnisBaum vb;
	struct Verzeichnis *pRoot;
	pRoot = malloc(sizeof(struct Verzeichnis));
	strcpy(pRoot->name, rootName);
	pRoot->pChildren = NULL;
	pRoot->pFather = NULL;
	pRoot->pNext = NULL;
	vb.pRoot = pRoot;
	return vb;
}

void insert(struct VerzeichnisBaum *tree, char fatherName[], char newName[]) {

	if (search(tree, newName) == NULL){
		struct Verzeichnis *newDir = malloc(sizeof(struct Verzeichnis));
		strcpy(newDir->name, newName);
		newDir->pChildren = NULL;
		newDir->pFather = search(tree, fatherName);
		newDir->pNext = NULL;
		if (newDir->pFather != NULL) {
			newDir->pNext = newDir->pFather->pChildren;
			newDir->pFather->pChildren = newDir;
		} else {
			free(newDir);
			printf("Insert Error: Vater nicht gefunden.\n");
		}
	} else {
    	printf("Insert Error: Verzeichnisname bereits verwendet.\n");
	}

}

struct Verzeichnis* search(struct VerzeichnisBaum *tree, char dir[]) {
	return searchDir(tree->pRoot, dir);
}

struct Verzeichnis* searchDir(struct Verzeichnis *curDir, char dir[]) {
	if(curDir != NULL) {
		struct Verzeichnis *pHilf;
		if (strcmp(curDir->name, dir) == 0)
			return curDir;
		pHilf = searchDir(curDir->pChildren, dir);
		if (pHilf != NULL)
			return pHilf;
		pHilf = searchDir(curDir->pNext, dir);
		if (pHilf != NULL)
			return pHilf;
	}
	return NULL;
}

void delete(struct VerzeichnisBaum *tree, char dir[]) {
	struct Verzeichnis *pCurrent = search(tree, dir);
	struct Verzeichnis *hilf;

	if (pCurrent == NULL) {        	//check if root or has children
    	printf("Delete Error: Verzeichnis nicht vorhanden.\n");
	} else if (pCurrent->pChildren != NULL) {
    	printf("Delete Error: Verzeichnis besitzt Unterverzeichnisse.\n");
	} else {
		if (pCurrent == tree->pRoot) {
			kill(tree);
		} else if (pCurrent->pFather->pChildren == pCurrent) {
			pCurrent->pFather->pChildren = pCurrent->pNext;
		} else {
			hilf = pCurrent->pFather->pChildren;
			while (hilf->pNext != pCurrent)
				hilf = hilf->pNext;
			hilf->pNext = hilf->pNext->pNext;
		}
		free(pCurrent);
		printf("Verzeichnis wurde erfolgreich gelöscht.\n");
	}
}

void print(struct VerzeichnisBaum tree) {
	if (tree.pRoot != NULL) {
    	printDir(tree.pRoot, 0);
	} else {
		printf("Print Error: Verzeichnisbaum ist leer.");
	}
}

void printDir(struct Verzeichnis *dir, int level){
	if(dir != NULL) {
		for(int i = 0; i < level; i++)
			printf("\t");
		printf("%s\n", dir->name);
    	printDir(dir->pChildren, level + 1);
    	printDir(dir->pNext, level);
	}
}

void kill(struct VerzeichnisBaum *tree) {
	killAllDirs(tree->pRoot);
	tree->pRoot = NULL;
}

void killAllDirs(struct Verzeichnis *dir) {
	if(dir != NULL) {
    	killAllDirs(dir->pChildren);
    	killAllDirs(dir->pNext);
    	free(dir);
	}
}
