#include "AI_projectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Ants.h"
#include <Texture.h>
#include <Renderer2D.h>

AI_projectApp::AI_projectApp() {

}

AI_projectApp::~AI_projectApp() {

}

bool AI_projectApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_ant = new Ants(glm::vec2(50, 50));


	return true;
}

void AI_projectApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AI_projectApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void AI_projectApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_ant->Draw(Spritebatch);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}