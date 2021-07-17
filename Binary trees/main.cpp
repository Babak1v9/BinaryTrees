#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Node.h"
using namespace std;

//function to find the lowest value in the tree 
int min(Node* node) {
	if (node->left == NULL) {
		return node->value;
	}
	else {
		min(node->left);
	}
}

//function to find the highest value in the tree 
int max(Node* node) {
	if (node->right == NULL) {
		return node->value;
	}
	else {
		max(node->right);
	}
}

//prepares the sum and count needed to calculate the average value
double calculateAverage(Node* node, double* sum, double* count) {
	if (node != nullptr) {
		(*count)++;
		(*sum) = (*sum) + node->value;
		calculateAverage(node->left, sum, count);
		calculateAverage(node->right, sum, count);
	}
	double average = (*sum) / (*count);
	return average;
}

//prints out the tree while simultaneously checking the balance factor for each node
bool printTree(Node* node, bool AVL) {
	if (node != nullptr) {
		//node->balancefactor = node->calculateBalancefactor();
		cout << "bal (" << node->value << ") = " << node->calculateBalancefactor(node);
		if (node->calculateBalancefactor(node) > 1) {
			cout << " (AVL violation!)" << endl;
			AVL = false;
		}
		else {
			cout << endl;
		}
		printTree(node->right, AVL);
		printTree(node->left, AVL);
		return AVL;
	}
}

int main()
{
	// reads text file (file name as parameter)
	string input;
	std::vector<int> myArray;
	cout << "Please enter a file name" << '\n';
	cin >> input;

	string line;
	ifstream myFile(input);
	// int myArr[100] = {};

	if (myFile.is_open()) {
		while (getline(myFile, line)) {
			myArray.push_back(atoi(line.c_str()));
		}
		myFile.close();
	}

	//creates the root for the tree by creating a node with a value and left/right set to NULL
	Node* root = new Node(myArray[0]);

	//buildes the tree by using the addNode function for each value of the array which contains the numbers from the input file
	for (int index = 1; index < myArray.size(); index++) {
		root->addNode(myArray[index]);
	}

	//prints out all values and checks if it is an AVL tree
	bool AVL = true;
	AVL = printTree(root, AVL);
	cout << "AVL: ";
	if (AVL == false) {
		cout << "no" << endl;
	}
	else {
		cout << "yes" << endl;
	}

	double sum = 0;
	double count = 0;
	double average = calculateAverage(root, &sum, &count);

	//prints out all stats about the tree
	cout << "min: " << min(root) << ", max: " << max(root) << ", avg: " << average << endl << endl;

	system("pause");
	return 0;
}