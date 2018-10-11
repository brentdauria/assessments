#include "demoApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "KeyboardController.h"
#include "Agent.h"

demoApp::demoApp() {

}

demoApp::~demoApp() {

}

bool demoApp::startup() {
	m_testAgent = new Agent(10.f, 10.f);
	m_testAgent->AddBehavior(new KeyboardController(aie::Input::getInstance()));
	m_testAgent->AddBehavior(new SeekBehavior(m_otherAgent));
	agents.push_back(m_testAgent);
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_agentTexture = new aie::Texture("./textures/car.png");
	return true;
}

void demoApp::shutdown() {
	delete m_testAgent;
	delete m_agentTexture;
	delete m_font;
	delete m_2dRenderer;
}

void demoApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	//m_testAgent->AddForce(10.f, 10.f);
	for (auto agent : agents)
	agent->update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void demoApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_2dRenderer->drawSprite(m_agentTexture, m_testAgent->m_position.x, m_testAgent->m_position.y, 0, 0, 0, 1);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}