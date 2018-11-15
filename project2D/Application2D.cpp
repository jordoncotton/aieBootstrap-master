#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "TreeNode.h"
#include "BinaryTree.h"
#include "CDDSBinaryTreeApp.h"

CDDS_BinaryTreesApp::CDDS_BinaryTreesApp()
{

}

CDDS_BinaryTreesApp::~CDDS_BinaryTreesApp()
{

}

aie::Font* g_systemFont = nullptr;

bool CDDS_BinaryTreesApp::startup()
{
	m_2dRenderer = new aie::Renderer2D();
	g_systemFont = new aie::Font("./font/consolas.ttf", 32);
	return true;
}

void CDDS_BinaryTreesApp::update(float deltaTime)
{
	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	static int value = 0;
	ImGui::InputInt("Value", &value);

	if (ImGui::Button("Insert", ImVec2(50, 0)))
	{
		m_binaryTree.insert(value);
		m_selectedNode = m_binaryTree.find(value);
	}

	if (ImGui::Button("Remove", ImVec2(50, 0)))
	{
		m_binaryTree.remove(value);
	}

	if (ImGui::Button("Find", ImVec2(50, 0)))
	{
		m_selectedNode = m_binaryTree.find(value);
	}

	//exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		m_cameraY += 100.0f * deltaTime;
	}


	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		m_cameraY -= 100.0f * deltaTime;
	}


	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		m_cameraX -= 100.0f * deltaTime;
	}


	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		m_cameraX += 100.0f * deltaTime;
	}


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}
}

void CDDS_BinaryTreesApp::draw()
{
	//wipe the screen to the background colour
	clearScreen();

	//begin drawing sprites
	m_2dRenderer->begin();

	//draw your stuff here!
	m_binaryTree.draw(m_2dRenderer, m_selectedNode);

	//output some text
	m_2dRenderer->drawText(g_systemFont, "Press ESC to quit", 0, 0);

	//done drawing sprites
	m_2dRenderer->end();
}


