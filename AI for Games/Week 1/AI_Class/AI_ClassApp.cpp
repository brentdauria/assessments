#include "AI_ClassApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Agent.h"
#include "KeyBoardController.h"
#include "SeekState.h"

AI_ClassApp::AI_ClassApp() {

}

AI_ClassApp::~AI_ClassApp() {

}

bool AI_ClassApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_player = new Agent(new aie::Texture("../bin/textures/ship.png"), Vector2(10, 20));
	m_player->AddBehavior(new KeyBoardController(aie::Input::getInstance()));

	m_AI = new Agent(new aie::Texture("../bin/textures/ship.png"), Vector2(100, 200));
	m_AI->AddBehavior(new SeekState(m_player));

	return true;
}

void AI_ClassApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AI_ClassApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_player->update(deltaTime);
	m_AI->update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void AI_ClassApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_player->draw(m_2dRenderer);
	m_AI->draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}