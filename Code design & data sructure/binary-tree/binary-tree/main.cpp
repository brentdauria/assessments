#include "binary_treeApp.h"

int main() {
	
	// allocation
	auto app = new binary_treeApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}