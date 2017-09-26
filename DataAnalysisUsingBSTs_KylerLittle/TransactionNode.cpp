#include "TransactionNode.h"

TransactionNode::TransactionNode(string data, int units) : Node(data)
{
	mUnits = units;
}

TransactionNode::~TransactionNode()
{
	//cout << "Inside TransactionNode's destructor!" << endl;
}

int TransactionNode::getUnits() const
{
	return mUnits;
}

void TransactionNode::setUnits(const int &newUnits)
{
	mUnits = newUnits;
}

// In this functions, setw() adds a column pad. Anything inserted into the stream after
// this->getData() is pushed to the other side of the column pad. In this way, I align
// my columns perfectly.
void TransactionNode::printData()
{
	cout << "Item: " << setw(25) << left << this->getData();
	cout << "Units: " << this->getUnits() << endl;
}