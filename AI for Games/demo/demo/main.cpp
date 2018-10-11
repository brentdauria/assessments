#include "demoApp.h"

int main() {
	
	auto app = new demoApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}