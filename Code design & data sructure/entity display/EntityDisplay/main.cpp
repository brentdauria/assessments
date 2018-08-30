#include "EntityDisplayApp.h"

int main() {
	//creates and runs the entity display through bootstrap
	auto app = new EntityDisplayApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}