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
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;

class TransactionNode : public Node			// public inheritance
{
public:
	TransactionNode(string data, int units);	// Constructor invokes Node's constructor
	~TransactionNode();							// Destructor

	int getUnits() const;					// getter
	void setUnits(const int &newUnits);		// setter

	void printData();						// overrides Node's printData()
private:
	int mUnits;			// units bought or sold
};