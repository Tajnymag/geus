#include <iostream>
#include "geus.h"

using namespace std;

int main() {

	Geus geus;
	try {
		geus.play();
	} catch (const char* e) {
		cout << e << endl;
		return 1;
	}

	return 0;
}
