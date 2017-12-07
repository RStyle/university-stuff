#ifndef WARTESCHLANGE_HPP_
#define WARTESCHLANGE_HPP_

#include "ListenElem.hpp"

class Warteschlange {

private:
	ListenElem* pTop;
	ListenElem* pBottom;
	void extend();

public:
	Warteschlange(int quantity = 4);
	~Warteschlange();
	void push(int v);
	int pop();
};



#endif /* WARTESCHLANGE_HPP_ */
