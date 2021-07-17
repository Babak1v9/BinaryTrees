
#include "Node.h"
#include <iostream>
#include <cstdlib>
#include <ostream>
using namespace std;

Node::Node(int newValue) {
	value = newValue;
	left = NULL;
	right = NULL;
}

Node::~Node()
{
	delete left;
	delete right;
}

//adds new nodes to the tree by checking if the current value is higher/lower than the current value
//if it's identical to the current value it will delete the current value and continue with the next one
//if the value is higher/lower it will either put a reference in left/right if they are currently pointing to NULL
//or reiterate the function for the left/right node until it hits a nullpointer
void Node::addNode(int newValue) {

	if (newValue == value) {
		return;
	}
	else if (newValue < value) {
		if (left == NULL) {
			left = new Node(newValue);
		}
		else {
			left->addNode(newValue);
		}
	}
	else if (newValue > value) {
		if (right == NULL) {
			right = new Node(newValue);
		}
		else {
			right->addNode(newValue);
		}
	}
}

//calculating the balancefactor by subtracting the heights from their respective left/right tree
//if the balancefactor is negative it is multiplied by (-1) so there are only positive values
int Node::calculateBalancefactor(Node* node) {
	int balancefactor = calculateHeight(node->left) - calculateHeight(node->right);
	if (balancefactor < 0) {
		balancefactor = balancefactor * (-1);
	}
	return balancefactor;
}

//calculating the height of each tree by checking for each node if the right or left sub tree goes deeper
int Node::calculateHeight(Node* node) {
	if (node == NULL)
		return 0;
	int leftHeight = calculateHeight(node->left);
	int rightHeight = calculateHeight(node->right);

	if (leftHeight > rightHeight) {
		return leftHeight + 1;
	}
	else
		return rightHeight + 1;
}