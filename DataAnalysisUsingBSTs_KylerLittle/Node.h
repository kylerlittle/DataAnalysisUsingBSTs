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

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Node
{
public:
	Node(string &data);			// Constructor
	virtual ~Node();			// Virtual Destructor -- virtual so that any child objects
								// can be properly destructed through a base class pointer
	// Setters
	void setData(string const &newData);
	void setmpLeft(Node *& newpLeft);
	void setmpRight(Node *& newpRight);

	// Getters
	string getData() const;
	Node *& getpLeft();			// return by reference so that values can be modified
	Node *& getpRight();

	virtual void printData() = 0;		// makes Node an abstract class; now each
										// child class MUST provide an implementation
										// of printData()
protected:
	string mData;
	Node *mpLeft;
	Node *mpRight;
};