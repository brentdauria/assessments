#include "Maths_AppApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"

Maths_AppApp::Maths_AppApp() {

}

Maths_AppApp::~Maths_AppApp() {

}

bool Maths_AppApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	m_player = new Player();

	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void Maths_AppApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_player;
}

void Maths_AppApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_player->update(deltaTime, input);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Maths_AppApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_player->draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}