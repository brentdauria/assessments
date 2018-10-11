#include "AI_ClassApp.h"

int main() {
	
	// allocation
	auto app = new AI_ClassApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}