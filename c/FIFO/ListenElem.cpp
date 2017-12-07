#include <iostream>
#include "ListenElem.hpp"
using namespace std;


ListenElem::ListenElem() {
	value = 0;
	pNext = NULL;
}

void ListenElem::setValue(int v) {
	value = v;
}

int ListenElem::getValue() {
	return value;
}

void ListenElem::setNext(ListenElem* e) {
	pNext = e;
}

ListenElem* ListenElem::getNext() {
	return pNext;
}
