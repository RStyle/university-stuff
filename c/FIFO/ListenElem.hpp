#ifndef LISTENELEM_HPP_
#define LISTENELEM_HPP_

class ListenElem {

private:
	int value;
	ListenElem* pNext;

public:
	ListenElem();
	void setValue(int v);
	int getValue();
	void setNext(ListenElem* e);
	ListenElem* getNext();
};

#endif /* LISTENELEM_HPP_ */
