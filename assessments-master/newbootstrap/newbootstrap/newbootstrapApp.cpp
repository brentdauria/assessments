#include "newbootstrapApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "player.h"
#include "rock.h"
#include <imgui.h>


newbootstrapApp::newbootstrapApp() {

}

newbootstrapApp::~newbootstrapApp() {

}


bool newbootstrapApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_timer = 0;

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_player = new player(glm::vec2(50, 50));

	/*m_rock = new rock(glm::vec2(1000, 600));*/

	return true;
}

void newbootstrapApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_player;
}

void newbootstrapApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	if (!m_player->isGameOver())
	{
	// if (input->isKeyDown(aie::INPUT_KEY_A) {
	// 	std::cout<<"wait"<<endl::std;
	// }
		m_timer += deltaTime;
		m_player->Update(deltaTime, input);
	}
	//m_rock->Update(deltaTime);
	//if (input->isKeyDown(aie::INPUT_KEY_R))
		
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void newbootstrapApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	if (!m_player->isGameOver())
	{
		ImGui::Begin("timer");
		ImGui::Text("timer: (%1.1f)", m_timer);
		ImGui::End();
	}
	if (m_player->isGameOver()) {
		m_2dRenderer->drawText(m_font, "YOU LASTED!", 500, 400);
		ImGui::Text("time: (%1.1f)", m_timer);
	}
	if (!m_player->isGameOver())
	{
		m_player->Draw(m_2dRenderer);
	}
	/*m_rock->Draw(m_2dRenderer);*/
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}