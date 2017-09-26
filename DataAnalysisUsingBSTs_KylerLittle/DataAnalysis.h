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

#include "BST.h"

class DataAnalysis
{
public:
	void runAnalysis();
private:
	// Private Attributes
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	// Private Member Functions
	void openCSV();
	void readLine(int & units, string & type, string & transaction);
	void readFileAndDisplay();
	void insertIntoAppropriateTree(int & units, string & type, string & transaction);
	void displayTrends();
};