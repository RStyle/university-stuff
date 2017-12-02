/*
 * main.c
 *
 *  Created on: 29.11.2017
 *  Author: group work by RStyle and 2 fellow students
 */

#include "Verzeichnis.h"

int main() {
	struct VerzeichnisBaum myTree = init("C:/");
	insert(&myTree, "C:/", "Programme");
	insert(&myTree, "C:/", "Benutzer");
	insert(&myTree, "Benutzer", "Ich");
	insert(&myTree, "Programme", "Notepad++");
	insert(&myTree, "Notepad++", "localisation");
	insert(&myTree, "Notepad++", "plugins");
	insert(&myTree, "Programme", "themes");
	insert(&myTree, "Programme", "Internet Explorer");
	insert(&myTree, "Notepadd++", "Internet Explorer");
	insert(&myTree, "Programm", "test");
	print(myTree);
	delete(&myTree, "NameDerNichtExestiert");
	delete(&myTree, "Benutzer");
	delete(&myTree, "Notepad++");
	delete(&myTree, "Ich");
	delete(&myTree, "plugins");
	print(myTree);

	kill(&myTree);
	print(myTree);

}
