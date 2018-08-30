#include "newbootstrapApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "player.h"
#include "rock.h"
#include <imgui.h>
#include <stdlib.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")



newbootstrapApp::newbootstrapApp() {

}

newbootstrapApp::~newbootstrapApp() {

}


bool newbootstrapApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_timer = 0;
// imports .wav file to play, had to move from the main due to when using the restart aspect in the update it calls the startup not the main
	PlaySound(TEXT("../bin/Aleksander Vinter - Ism suite.wav"), NULL, SND_FILENAME | SND_ASYNC);  

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
	//restarts the aplication
	if (input->isKeyDown(aie::INPUT_KEY_R))
		startup();
}

void newbootstrapApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	if (!m_player->isGameOver())
	{
		ImGui::Begin("timer");//prints timer value and visuals
		ImGui::Text("timer: (%1.1f)", m_timer);
		ImGui::End();
	}
	if (m_player->isGameOver()) { // prints time the player lasted and ending game message
		m_2dRenderer->drawText(m_font, "YOU LASTED!", 500, 400);
		ImGui::Text("time: (%1.1f)", m_timer);
	}
	if (!m_player->isGameOver())
	{
		m_player->Draw(m_2dRenderer);
	}
	/*m_rock->Draw(m_2dRenderer);*/
	// draws messages left on the screen
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	m_2dRenderer->drawText(m_font, "Press R to Restart", 950, 700);
	// done drawing sprites
	m_2dRenderer->end();
}