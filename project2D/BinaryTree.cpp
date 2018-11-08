#include "BinaryTree.h"


BinaryTree::BinaryTree()
{
}

BinaryTree::~BinaryTree()
{
}

bool BinaryTree::isEmpty() const
{
	return false;
}

void BinaryTree::insert(int a_nValue)
{
	if (isEmpty())
	{
		m_pRoot->setData(a_nValue);
	}
	TreeNode* currentNode;
	currentNode = m_pRoot;

	while (currentNode != nullptr)
	{
		if (a_nValue < currentNode->getData())
		{
			currentNode->getLeft();
			continue;
		}
		if (a_nValue > currentNode->getData())
		{
			currentNode->getRight();
			continue;
		}
		if (a_nValue == currentNode->getData())
		{
			break;
		}
	}
	if (currentNode = nullptr)
	{
		a_nValue < 
	}
}

void BinaryTree::remove(int a_nValue)
{

}

TreeNode * BinaryTree::find(int a_nValue)
{
	return nullptr;
}

void BinaryTree::draw(aie::Renderer2D * renderer, TreeNode * selected)
{
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
	return false;
}

void BinaryTree::draw(aie::Renderer2D * renderer, TreeNode *pNode, int x, int y, int horizontalSpacing, TreeNode * selected)
{
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->hasLeft())
		{
			renderer ->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
			draw(renderer, pNode->getLeft(), x - horizontalSpacing, y - 80, horizontalSpacing, selected);
		}
		if (pNode->hasRight())
		{
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			draw(renderer, pNode->getRight(), x + horizontalSpacing, y - 80, horizontalSpacing, selected);
		}
		pNode->draw(renderer, x, y, false, (selected == pNode));
	}
}