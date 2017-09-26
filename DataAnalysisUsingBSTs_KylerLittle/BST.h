/*******************************************************************************
* Programmer: Kyler Little													  *
* Class: CptS 122; Lab Section 6                                              *
* Programming Assignment: Data Analysis Using BSTs (PA #8)					  *
* Date: 4/10/2017                                                             *
*                                                                             *
* Description: This program detects trends in consumer products over a 48	  *
*			   hr period. Data is imported from a csv file with vital info	  *
*			   such as the # of units sold/purchased, the item name, and	  *
*			   a tag indicating whether the product was sold or purchased.	  *
*			   This program prints the contents to the screen (in ascending   *
*			   order) and prints interesting trends.						  *
*																			  *
* Relevant Formulas: Refer to each function definition.                       *
*                                                                             *
*																			  *
******************************************************************************/

#pragma once

#include "Node.h"
#include "TransactionNode.h"
#include <iostream>
#include <string>
#include <fstream>

using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

class BST
{
public:
	BST();			// Constructor
	~BST();			// calls destroyTree()

	void insert(string &newItem, int &numUnits);			// calls private insert
	void inOrderTraversal();								// calls private inOrderTraversal
	TransactionNode & findSmallest();
	TransactionNode & findLargest(); 
private:
	// Private Attributes
	Node *mpRoot;
	// Private Member Functions
	void destroyTree(Node *& pTree);
	void insert(Node *& pTree, string &newItem, int &numUnits);
	void inOrderTraversal(Node * pTree);		// no reference, since I'm just printing
};