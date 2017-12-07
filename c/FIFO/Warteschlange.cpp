#include <iostream>
#include "Warteschlange.hpp"
using namespace std;

void Warteschlange::extend() {
	ListenElem* pCurrent = pBottom;
	ListenElem newElement;
	if (pCurrent == NULL) {
		pCurrent = &newElement;
	} else {
		while(pCurrent->getNext() != pBottom) {
			pCurrent->setNext(pCurrent->getNext());
		}
		pCurrent->setNext(&newElement);
	}
	newElement.setNext(pBottom);
}

Warteschlange::Warteschlange(int quantity) {
	if(quantity < 1)
		quantity = 1;
	for(int i = 0; i < quantity; i++) {
		extend();
	}
}

Warteschlange::~Warteschlange() {

}

int Warteschlange::pop() {
	return 0;
}

void Warteschlange::push(int v) {

}
