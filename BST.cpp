    #include "BST.h"
    
    //Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	Node * BST::getRootNode() const{
        return rootNode;
    }

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool BST::add(int data){

        return addHelper(data, rootNode);
    }
    bool BST::addHelper(int data, Node*& parentNode){

        if(parentNode == NULL){
            parentNode = new Node(data);
            return true;
        }
        else if(parentNode->data > data){
            return addHelper(data, parentNode->leftChild);
        }
        else if(parentNode->data < data){
            return addHelper(data, parentNode->rightChild);
        } 
        else{
            return false;
        }
        
    }

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool BST::remove(int data){
        return removeHelper(rootNode, data);
    }
    bool BST::removeHelper(Node*& local_root,int data){
        if(local_root == NULL){
            return false;
        }
        else{
            if (data < local_root->getData()){
                return removeHelper(local_root->leftChild, data);
            }
            else if(data > local_root->getData()){
                return removeHelper(local_root->rightChild, data);
            }
            else{
                Node* old_root = local_root;
                if(local_root->getLeftChild() == NULL){
                    local_root = local_root->getRightChild();
                    delete old_root;
                }
                else if(local_root->getRightChild() == NULL){
                    local_root = local_root->getLeftChild();
                    delete old_root;
                }
                else{
                    //replace(old_root, local_root->leftChild);
                    Node *ptr = local_root->leftChild;
                    while (ptr->rightChild != NULL) {						
                        ptr = ptr->rightChild;					
                        }					
                    local_root->data = ptr->getData();					
                    removeHelper(local_root->leftChild, local_root->data);
                }
                return true;
            }
        }
    }
	
    /*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void BST::clear(){
        clearHelper(this->rootNode);
        rootNode = NULL;
    }
    void BST::clearHelper(Node *&node){
        if(node != NULL){
            clearHelper(node->leftChild);
            clearHelper(node->rightChild);
            delete node;
        }
    }
