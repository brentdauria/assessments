#include "newbootstrapApp.h"
#include <iostream>

using namespace std;
int main() {
	
	// allocation
	auto app = new newbootstrapApp();

	// initialise and loop
	try {
		app->run("AIE", 1280, 720, false);
	}
	catch (exception e) {
		cout << "game not working" << endl;
	}
	// deallocation
	delete app;

	return 0;
}