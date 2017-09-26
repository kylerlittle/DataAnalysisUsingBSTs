#include "BST.h"


// PUBLIC MEMBER FUNCTIONS

BST::BST()
{
	mpRoot = nullptr;
}

BST::~BST()
{
	destroyTree(mpRoot);
}

void BST::insert(string &newItem, int &numUnits)
{
	this->insert(mpRoot, newItem, numUnits);
}

void BST::inOrderTraversal()
{
	this->inOrderTraversal(mpRoot);
}

TransactionNode & BST::findSmallest()
{
	Node *pTree = mpRoot;
	while (pTree->getpLeft() != nullptr) {		// not at left-most node (smallest value)!
		pTree = pTree->getpLeft();
	}
	return *(dynamic_cast <TransactionNode *> (pTree));
}

TransactionNode & BST::findLargest()
{
	Node *pTree = mpRoot;
	while (pTree->getpRight() != nullptr) {		// not at right-most node (largest value)!
		pTree = pTree->getpRight();
	}
	return *(dynamic_cast <TransactionNode *> (pTree));
}


// PRIVATE MEMBER FUNCTIONS
void BST::destroyTree(Node *& pTree)
{
	if (pTree != nullptr) {
		destroyTree(pTree->getpLeft());
		destroyTree(pTree->getpRight());
		delete pTree;	// going all the way left, then all the way right insures that
	}					// whatever node we're deleting is a leaf node!
}

void BST::insert(Node *& pTree, string &newItem, int &numUnits)
{
	if (pTree == nullptr) {			// found our spot to insert!
		pTree = new TransactionNode(newItem, numUnits);
	}
	else {		// continue looking for a spot to insert
		// Need to downcast now to access TransactionNode's public member fct getUnits()!
		TransactionNode * temp = (dynamic_cast <TransactionNode *> (pTree));
		if (temp != nullptr) {		// successful downcast
			if (numUnits < temp->getUnits()) {		// go down left subtree
				insert(pTree->getpLeft(), newItem, numUnits);
			}
			else {		// go down right subtree
				insert(pTree->getpRight(), newItem, numUnits);
			}
		}
		else {
			cout << "Downcast failed!" << endl;
		}
	}
}

void BST::inOrderTraversal(Node * pTree)
{
	if (pTree != nullptr) {
		inOrderTraversal(pTree->getpLeft());		// left
		pTree->printData();							// process
		inOrderTraversal(pTree->getpRight());		// right
	}
}