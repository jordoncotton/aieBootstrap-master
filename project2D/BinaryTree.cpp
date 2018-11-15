#include "BinaryTree.h"


BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
}

bool BinaryTree::isEmpty() const
{
	if (m_pRoot == nullptr)
	{
		return true;
	}
	return false;
}

void BinaryTree::insert(int a_nValue)  
{
	if (isEmpty())
	{
		m_pRoot = new TreeNode(a_nValue);
		m_pRoot->setLeft(nullptr);
		m_pRoot->setRight(nullptr);
		return;
	}
	TreeNode* currentNode;
	TreeNode* parentNode;
	currentNode = m_pRoot;
	parentNode = m_pRoot;

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
	if (a_nValue < parentNode->getData())
	{
		currentNode = currentNode->getLeft();
	}
	else
	{
		currentNode = currentNode->getRight();
	}
}

void BinaryTree::remove(int a_nValue)
{
	//created two nodes that are set to the root
	TreeNode* currentNode = m_pRoot;
	TreeNode* parentNode = m_pRoot;

		//created two nodes pointers that are set to the nodes we just created
		TreeNode** ptrCurrentNode = &currentNode;
		TreeNode** ptrParentNode = &parentNode;

		//checks to see if the node you are finding exist
		if (findNode(a_nValue, ptrCurrentNode, ptrParentNode))
		{
			//checks if the current node has a right node
			if (currentNode->hasRight())
			{
				//creates two Iterating nodes set to the node pointers
				TreeNode* IterCurrent = (*ptrCurrentNode);
				TreeNode* IterParent = (*ptrParentNode);
			}
			//checks of the Iterating currents node has right node
			if (currentNode->hasRight())
			{
				//points Iterator currents node to its right
				//while making Iterator parents node point to Iterator currents node
				parentNode = currentNode;
				currentNode = currentNode->getRight();
			}
			//runs while the Iterator currents node has left node 
			while (currentNode ->hasLeft())
			{
				//points Iterator currents node to its left
				//while making Iterator parents node point to Iterator currents node
				parentNode = currentNode;
				currentNode = currentNode->getLeft();
			}

			//sets the current nodes data to the iterating currents node data
			currentNode->setData(currentNode->getData());

			//checks if the Iterating parents nodes left eqauls the Iterator currents node
			if (parentNode->getLeft() == currentNode)
			{
			//sets Iterator parents left node is set to Iterator currents right node 
			parentNode->setLeft(currentNode->getRight());
			}

			//checks if the Iterating parents nodes right eqauls the Iterator currents node
			else if (parentNode->getRight() == currentNode)
			{
				//sets Iterator parents right node is set to Iterator currents right node 
				parentNode->setRight(currentNode->getRight());
			}
			delete currentNode;
		}

	else
	{
		//checks if the parents nodes left eqauls the currents node
		if (parentNode->getLeft() == currentNode)
		{
			//sets parents left node is set to currents right node 
			parentNode->setLeft(currentNode->getLeft());
		}

		//checks if the parents nodes right eqauls the currents node
		else if (parentNode->getRight() == currentNode)
		{
			//sets parents right node is set to currents right node 
			parentNode->setRight(currentNode->getLeft());
		}

		//checks if the root equals the currents node
		else if (m_pRoot == currentNode)
		{
			//sets the root to the current nodes left
			m_pRoot = currentNode->getLeft();
		}
		delete currentNode;
	}
}

TreeNode* BinaryTree::find(int a_nValue)
{
	if (isEmpty())
	{
		m_pRoot->setData(a_nValue);
	}
	TreeNode* currentNode;
	TreeNode* parentNode;
	currentNode = m_pRoot;
	parentNode = m_pRoot;

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
	if (a_nValue < parentNode->getData())
	{
		currentNode = currentNode->getLeft();
	}
	else
	{
		currentNode = currentNode->getRight();
	}

	return nullptr;
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* selected)
{
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent)
{
	TreeNode* currentNode = m_pRoot;

	while (currentNode != nullptr)
	{
		if (a_nSearchValue == currentNode->getData())
		{
			return currentNode;
			return ppOutParent;
		}
		else if (a_nSearchValue < currentNode->getData())
		{
			currentNode = currentNode->getLeft();
		}
		else
		{
			currentNode = currentNode->getRight();
		}
	}
	return false;
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->hasLeft())
		{
			renderer->setRenderColour(1, 0, 0);
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
