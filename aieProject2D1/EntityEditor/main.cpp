#include "EntityEditorApp.h"

int main() {
	
	auto app = new EntityEditorApp();
	app->run("Blocks", 1280, 720, false);
	delete app;

	return 0;
}