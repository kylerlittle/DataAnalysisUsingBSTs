#include "Node.h"

Node::Node(string &data)
{
	mData = data;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{
	//cout << "Inside Node's destructor!" << endl;
}

void Node::setData(string const &newData)
{
	mData = newData;
}

void Node::setmpLeft(Node *& newpLeft)
{
	mpLeft = newpLeft;
}

void Node::setmpRight(Node *& newpRight)
{
	mpRight = newpRight;
}

string Node::getData() const
{
	return mData;
}

Node *& Node::getpLeft()
{
	return mpLeft;
}

Node *& Node::getpRight()
{
	return mpRight;
}