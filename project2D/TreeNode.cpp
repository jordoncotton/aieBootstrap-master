#include "Application2D.h"
#include "TreeNode.h"
#include <iostream>

extern aie::Font* g_systemFont;

TreeNode::TreeNode(int value)
{
}

TreeNode::~TreeNode()
{
}

void TreeNode::draw(aie::Renderer2D *renderer, int x, int y, aie::Font* g_systemFont, bool selected)
{
	static char buffer[10];

	sprintf_s(buffer, "%d", m_value);

	renderer->setRenderColour(1, 1, 0);
	renderer->drawCircle(x, y, 30);

	if (selected == true)
		renderer->setRenderColour(.5, .5, 0);
	else
		renderer->setRenderColour(0, 0, 0);
	renderer->drawCircle(x, y, 28);

	renderer->setRenderColour(1, 1, 1);
	renderer->drawText(g_systemFont, buffer, x - 12, y - 10);
}