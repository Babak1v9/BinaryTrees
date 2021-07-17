
#ifndef __NODE_H_
#define _NODE_H_

class Node
{
public:
	Node(int value);
	~Node();
	int value;
	Node* left;
	Node* right;
	int calculateBalancefactor(Node* node);
	int calculateHeight(Node* node);
	void addNode(int newvalue);
};

#endif /* _NODE_H_ */