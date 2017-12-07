#include <iostream>
#include "Warteschlange.hpp"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	ListenElem e1;
	e1.setValue(2);
	cout << e1.getValue();
	Warteschlange s1 = new Warteschlange(3);
	return 0;
}
