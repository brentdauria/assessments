#include "AI_projectApp.h"

int main() {
	
	// allocation
	auto app = new AI_projectApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}