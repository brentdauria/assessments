#include "newbootstrapApp.h"
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <stdlib.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

int main() {
	
	PlaySound(TEXT("../bin/Aleksander Vinter - Ism suite.wav"), NULL, SND_FILENAME | SND_ASYNC);

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