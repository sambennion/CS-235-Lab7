#pragma once

#include <iostream>
#include "NodeInterface.h"


class Node: public NodeInterface {
protected:
    
    //Node(const int& the_data, Node* next_val = NULL):
	//	data(the_data){next = next_val;
	//}
public:
    int data;
    Node* leftChild;
    Node* rightChild;
	Node(int data) {
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
	virtual ~Node() {}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	Node * getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	Node * getRightChild() const;
    
};