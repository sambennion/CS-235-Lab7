#include "Node.h"

/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int Node::getData() const{
        return this->data;
    }

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	Node * Node::getLeftChild() const{
        return this->leftChild;
    }

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	Node * Node::getRightChild() const{
        return this-> rightChild;
    }