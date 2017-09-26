#include "DataAnalysis.h"


// PUBLIC MEMBER FUNCTIONS

void DataAnalysis::runAnalysis()
{
	this->openCSV();
	this->readFileAndDisplay();
	this->displayTrends();
}


// PRIVATE MEMBER FUNCTIONS

// Description: opens data.csv with no particular mode
void DataAnalysis::openCSV()
{
	if (mCsvStream.is_open()) {		// if previously opened, we want to close it to make
		mCsvStream.close();			// it so we can change the mode if we so choose
	}
	mCsvStream.open("data.csv");
}

// Description: reads a single line from mCsvStream & stores the fields into
//				the input parameters; since the input parameters are references,
//				the function is modifying variables outside its scope
void DataAnalysis::readLine(int & units, string & type, string & transaction)
{
	char tempString[40] = "";
	mCsvStream.getline(tempString, 20, ',');
	units = atoi(tempString);
	mCsvStream.getline(tempString, 40, ',');
	type = tempString;
	mCsvStream.getline(tempString, 15, '\n');
	transaction = tempString;
}

// Description: This function loops until the entire 'data.csv' file is read. Entries
//				are stored in the appropriate BST (mTreeSold or mTreePurchased). Lastly,
//				each tree is displayed, in ascending order based on units sold or purchased.
void DataAnalysis::readFileAndDisplay()
{
	// First, get the junk line (the column headers)
	char junkLine[100] = "";
	mCsvStream.getline(junkLine, 100);
	
	while (!mCsvStream.eof()) {
		int units = 0;
		string type = "", transaction = "";
		this->readLine(units, type, transaction);
		this->insertIntoAppropriateTree(units, type, transaction);
	}
	cout << "Purchased Items:" << endl;
	mTreePurchased.inOrderTraversal();
	cout << endl << "Sold Items:" << endl;
	mTreeSold.inOrderTraversal();
	cout << endl;	// add an extra end line for viewing pleasure
}

// Description: Based on the type of transaction (which is extracted from the file), 
//				the data is inserted into either the "Purchased" tree or the "Sold" tree.
void DataAnalysis::insertIntoAppropriateTree(int & units, string & type, string & transaction)
{
	if (transaction == "Purchased") {
		mTreePurchased.insert(type, units);		// insert into tree
	}
	else if (transaction == "Sold") {		// could have done 'else' but I'll be explicit
		mTreeSold.insert(type, units);		// insert into tree
	}
}

// Description: Writes to the screen the trends we see in both trees (the type and number
//				of units that are least sold and purchased & the most sold and purchased).
void DataAnalysis::displayTrends()
{
	// Display smallest # of units solds & type
	cout << "Least Sold Item: " << mTreeSold.findSmallest().getData() << endl;
	cout << "Units Sold: " << mTreeSold.findSmallest().getUnits() << "\n\n";
	// Display smallest # of units purchased & type
	cout << "Least Purchased Item: " << mTreePurchased.findSmallest().getData() << endl;
	cout << "Units Purchased: " << mTreePurchased.findSmallest().getUnits() << "\n\n";
	// Display largest # of units solds & type
	cout << "Most Sold Item: " << mTreeSold.findLargest().getData() << endl;
	cout << "Units Sold: " << mTreeSold.findLargest().getUnits() << "\n\n";
	// Display largest # of units purchased & type
	cout << "Most Purchased Item: " << mTreePurchased.findLargest().getData() << endl;
	cout << "Units Purchased: " << mTreePurchased.findLargest().getUnits() << endl;
}