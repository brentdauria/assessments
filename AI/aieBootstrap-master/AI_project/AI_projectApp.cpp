#include "AI_projectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Ants.h"
#include <Texture.h>
#include <Renderer2D.h>
#include "Agent.h"
#include "KeyboardController.h"
#include "SeekBehavior.h"
#include "State.h"
#include "ChaseState.h"
#include "Searchstate.h"
#include "FiniteStateMachines.h"



AI_projectApp::AI_projectApp() {

}

AI_projectApp::~AI_projectApp() {

}

bool AI_projectApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	//creates ant and sets location
	m_ant = new Ants(glm::vec2(400, 400));
	m_otherAgent = new Agent(500.f, 500.f);
	
	//m_otherAgent->AddState(new Searchstate(m_));
//	m_target = new Agent(500f, 500f);
	m_target = new Agent(10.f, 10.f);
	//m_testAgent = new Agent(500.f, 500.f);
	//m_otherAgent->
	m_otherAgent->AddBehavior(new KeyboardController(aie::Input::getInstance()));
	m_fsm = new FiniteStateMachines();
	m_fsm->SetCurrentState(new Searchstate(m_otherAgent, 15.0f, 25.0f, 25.0f));
	m_target->SetMachine(m_fsm);
	//m_agent->AddBehavior()
	agents.push_back(m_target);
	agents.push_back(m_otherAgent);
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_agentTexture = new aie::Texture("../bin/textures/car.png");
	m_otherTexture = new aie::Texture("../bin/textures/ant.png");
	return true;


	return true;
}

void AI_projectApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_target;
	delete m_agentTexture;

	
}

void AI_projectApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	
	for (auto agent : agents)
		agent->update(deltaTime);
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
	m_2dRenderer->drawSprite(m_agentTexture, m_target->m_position.x, m_target->m_position.y, 0, 0, 0, 1);

	m_2dRenderer->drawSprite(m_otherTexture, m_otherAgent->m_position.x, m_otherAgent->m_position.y, 50, 50, 100);
	m_ant->Draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}