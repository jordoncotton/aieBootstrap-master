#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "TreeNode.h"
#include "BinaryTree.h"

Application2D::Application2D() 
{

}

Application2D::~Application2D()
{

}

aie::Font* g_systemFont = nullptr;

bool Application2D::startup()
{
	m_2dRenderer = new aie::Renderer2D();
	g_systemFont = new aie::Font("./font/consolas.ttf", 32);
	return true;
}

void CDDS_BinaryTreesApp::update(float deltaTime)
{
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
}

void CDDS_BinaryTreesApp::draw()
{
	//wipe the screen to the background colour
	clearscreen();

	//begin drawing sprites
	m_2drenderer->begin();

	//draw your stuff here!
	m_binaryTree.draw(m_2drenderer, m_selectedNode);

	//output some text
	m_2drenderer->drawText(g_systemFont, "Press ESC to quit", 0, 0);

	//done drawing sprites
	m_2drenderer->end();
}

void Application2D::shutdown()
{
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

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
//
//if (setUVRect > 5)
//{
//
//}
void Application2D::draw()
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	// demonstrate animation
	/*m_2dRenderer->setUVRect(int(m_timer) % 8 / 40.0f, 0, 2.0f / 8, 3.0f / 8);
	m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);*/

	// demonstrate spinning sprite
	m_2dRenderer->setUVRect(int(m_timer* 11) % 10 / 10.0f, 0, 1.f / 11, 1.f / 8);
	m_2dRenderer->drawSprite(m_shipTexture, 600, 200, 120, 310, 0, 1);
	
	//// draw a moving purple circle
	//m_2dRenderer->setRenderColour(1, 0, 1, 1);
	//m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	// draw a rotating red box
	/*m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(600, 500, 60, 20, 0);*/

	// draw a slightly rotated sprite with no texture, coloured yellow
	/*m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);*/
	
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}