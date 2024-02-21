//
// Created by Hailey on 2/12/24.
//

#ifndef PROJECT1_AVLTREE_H
#define PROJECT1_AVLTREE_H

#endif //PROJECT1_AVLTREE_H

#include <iostream>
#include <sstream>
using namespace std;

struct node {
    node(string _name, int _UFID) {
        name = _name;
        UFID = _UFID;
    }
    int UFID;
    string name;
    node* leftChild = nullptr;
    node* rightChild = nullptr;
};

class AVLTree {
public:
    node* root;
    bool removedFlag;
    bool notFoundFlag = false;

    AVLTree() {
        root = nullptr;
    }

    AVLTree(string _name, int _UFID) {
        insertion(nullptr, _name, _UFID);
    }

    ~AVLTree() {
        deleteHelper(root);
    }

    node* insertNode(string _name, int _UFID) { // insert NAME ID
        return insertion(root, _name, _UFID);
    }

    string removeByID(int _UFID) { // remove ID
        root = removeID(root, _UFID);
        if(removedFlag) {
            removedFlag = false;
            return "successful";

        } else {
            return "unsuccessful";
        }
    }

    string searchByID(int _UFID) { // search ID
        return searchID(root, _UFID);
    }

    string searchByName(string _name) { // search NAME
        return clipNewline(searchName(root, _name, ""));
    }

    string inorderTraversal() {
        return clipComma(printInorder(root, ""));
    }

    string preorderTraversal() {
        return clipComma(printPreorder(root, ""));
    }

    string postorderTraversal() {
        return clipComma(printPostorder(root, ""));
    }

    int levelCount(){
        return getLevelCount(root);
    }

    string removeAtN(int N) {
        return removeInorder(root, N);
    }

    int getTreeHeight() {
        return getLevelCount(root);
    }

    string appendZeros(string N) {
        //    string intString = to_string(N);
        if (N.length() == 8) {
            return N;
        }
        string withLeading = "";
        for(int i = 0; i < 8-N.length(); i++) {
            withLeading += "0";
        }
        for(int i = 0; i < N.length(); i++) {
            withLeading += N[i];
        }
        return withLeading;
    }

private:

    int getBalance(node* _root) { // function to get balance of tree
        if(_root == nullptr) {
            return 0;
        }
        int leftHeight = getLevelCount(_root->leftChild);
        int rightHeight = getLevelCount(_root->rightChild);
        return leftHeight - rightHeight;
    }

    node* rotateRight(node* _y) { // rotate nodes to right
        node* x = _y->leftChild;
        node* T2 = x->rightChild;

        x->rightChild = _y;
        _y->leftChild = T2;

        if (_y == root ) {
            root = x;
        }

        return x;
    }

    node* rotateLeft(node* _x) { // rotate nodes to left
        node* y = _x->rightChild;
        node* T2 = y->leftChild;

        _x->rightChild = T2;
        y->leftChild = _x;

        if(_x == root) {
            root = y;
        }

        return y;
    }

    node* rebalanceTree(node* _root, int _UFID) {
        int balance = getBalance(_root);
        // left left
        if (balance > 1 && _UFID < _root->leftChild->UFID) {
            return rotateRight(_root);
        }
        // right right
        if (balance < -1 && _UFID > _root->rightChild->UFID) {
            return rotateLeft(_root);
        }
        // left right
        if (balance > 1 && _UFID > _root->leftChild->UFID)
        {
            _root->leftChild = rotateLeft(_root->leftChild);
            return rotateRight(_root);
        }
        // right left
        if (balance < -1 && _UFID < _root->rightChild->UFID)
        {
            _root->rightChild = rotateRight(_root->rightChild);
            return rotateLeft(_root);
        }

        return nullptr;
    }

    node* insertion(node* _root, string _name, int _UFID) { // insert node and balance tree if necessary
        if (root == nullptr) { // if tree is empty
            node *newNode = new node(_name, _UFID);
            root = newNode;
            return newNode;

        } else if (_root == nullptr) { // if current node does not exist, insert there
            node *newNode = new node(_name, _UFID);
            return newNode;

        } else if (_UFID < _root->UFID) { // if inserted UFID is less than
            _root->leftChild = insertion(_root->leftChild, _name, _UFID);

        } else if (_UFID > _root->UFID) { // if inserted UFID is greater than
            _root->rightChild = insertion(_root->rightChild, _name, _UFID);

        } else if (_UFID == _root->UFID) { // if it's equal, don't insert
            return nullptr;
        }

        // balance
        node* rebalanced = rebalanceTree(_root,_UFID);
        if(rebalanced != nullptr) {
            return rebalanced;
        }

        return _root;
    }

    node* smallestNode(node* _root) { // find smallest node
        node* temp = _root;

        while(temp->leftChild != nullptr) {
            temp = temp->leftChild;
        }

        return temp;
    }

    node* removeID(struct node* _root, int _targetUFID) {
        if(_root == nullptr) {
            return _root;
        } else if(_targetUFID != _root->UFID) {
            if (_targetUFID > _root->UFID) { // if target ID greater than
                _root->rightChild = removeID(_root->rightChild, _targetUFID);
                return _root;

            } else if (_targetUFID < _root->UFID){ // if target ID less than
                _root->leftChild = removeID(_root->leftChild, _targetUFID);
                return _root;
            }
        } else {
            removedFlag = true;
            if (_root->leftChild == nullptr) { // if only left child
                node *temp = _root->rightChild;
                delete _root;
                _root = nullptr;
                return temp;

            } else if (_root->rightChild == nullptr) { // if only right child
                node *temp = _root->leftChild;
                delete _root;
                _root = nullptr;
                return temp;

            } else { // if has two children
                // find successor
                node *successorParent = _root;

                node *successor = _root->rightChild;
                while(successor->leftChild != nullptr) {
                    successorParent = successor;
                    successor = successor->leftChild;
                }

                if (successorParent != _root) {
                    successorParent->leftChild = successor->rightChild;
                } else {
                    successorParent->rightChild = successor->rightChild;
                }

                // replace information
                _root->UFID = successor->UFID;
                _root->name = successor->name;
                delete successor;
                successor = nullptr;

                rebalanceTree(_root,_root->UFID);

                return _root;

            }
        }

        return nullptr;
        }

    string searchID(node* _root, int _targetUFID) { // search for specified ID

        if(_root == nullptr) { // if node has no children, ID couldn't be found
            return "unsuccessful";

        } else if(_root->UFID == _targetUFID) { // if ID found
            return _root->name;

        } else if (_targetUFID > _root->UFID) { // if ID greater than
            return searchID(_root->rightChild, _targetUFID);

        } else { // if ID less than
            return searchID(_root->leftChild, _targetUFID);
        }

    }

    // search for names and return string of all names using a preorder traversal
    string searchName(node *_root, string _targetName, string foundNames) {
        // if no children, return input

        if (_root != nullptr) {
            // root
            if(_root->name == _targetName) {
                foundNames += appendZeros((to_string(_root->UFID))) + "\n";
            }

            // left
            foundNames = searchName(_root->leftChild, _targetName, foundNames);

            // right
            foundNames = searchName(_root->rightChild, _targetName, foundNames);

        }
        return foundNames;
    }

    string printInorder(node *_root, string inorderString) { // return a string of the inorder traversal
        if(_root != nullptr) {
            inorderString = printInorder(_root->leftChild, inorderString);

            inorderString += _root->name + ", ";

            inorderString = printInorder(_root->rightChild, inorderString);
        }
        return inorderString;
    }

    string printPreorder(node *_root, string preorderString) { // return a string of the preorder traversal
        if(_root != nullptr) {
            preorderString += _root->name + ", ";

            preorderString = printPreorder(_root->leftChild, preorderString);

            preorderString = printPreorder(_root->rightChild, preorderString);
        }
        return preorderString;
    }

    string printPostorder(node *_root, string postorderString) { // return a string of the postorder traversal
        if(_root != nullptr) {
            postorderString = printPostorder(_root->leftChild, postorderString);

            postorderString = printPostorder(_root->rightChild, postorderString);

            postorderString += _root->name + ", ";
        }
        return postorderString;
    }

    string clipComma (string _originalString) { // utility function that gets rid of trailing commas in a string
        return _originalString.substr(0,_originalString.length()-2);
    }

    string clipNewline (string _originalString) { // utility function that gets rid of trailing newlines in a string
        return _originalString.substr(0,_originalString.length()-1);
    }

    int getLevelCount(node* _root) { // recursive function which compares heights of left and right children to find height
        // if the tree is empty or a leaf, return 0
        if(_root == nullptr) {
            return 0;
        } else {
            int leftHeight = getLevelCount(_root->leftChild)+1;
            int rightHeight = getLevelCount(_root->rightChild)+1;

            return max(leftHeight, rightHeight);
        }

    }

    string removeInorder(node* _root, int N) { // Remove node at the Nth node of an inorder traversal
        notFoundFlag = true;

        node* currentNode = removeInorderFinder(root,N);

        if(currentNode == nullptr || notFoundFlag) {
            return "unsuccessful";
        } else {
            return "successful";
        }

    }

    node* removeInorderFinder(node *_root, int& N) { // return a string of the inorder traversal
        if(N <= -2) {
            return _root;
        }
        if(_root != nullptr && N >= 0) {


            // left
            _root->leftChild = removeInorderFinder(_root->leftChild, N);

            // node
            N--;
            if(N==-1) {
                notFoundFlag = false;
                N=-2;
                node* temp = removeInorderHelper(_root);
                root = removeID(root, _root->UFID);
                return temp;
            }

            // right
            _root->rightChild = removeInorderFinder(_root->rightChild, N);

        }
        return _root;


    }

    node* removeInorderHelper(node* _root) { // find replacement for deleted node
        if (_root->leftChild == nullptr && _root->rightChild == nullptr) {
            return nullptr;
        } else if (_root->leftChild == nullptr) { // if only left child
            node *temp = _root->rightChild;
            return temp;
        } else if (_root->rightChild == nullptr) { // if only right child
            node *temp = _root->leftChild;
            return temp;
        } else { // if has two children
            // find successor
            node *successorParent = _root;

            node *successor = _root->rightChild;
            while(successor->leftChild != nullptr) {
                successorParent = successor;
                successor = successor->leftChild;
            }

            if (successorParent != _root) {
                successorParent->leftChild = successor->rightChild;
            } else {
                successorParent->rightChild = successor->rightChild;
            }

            rebalanceTree(successor,successor->UFID);

            return successor;
        }
    }

    void deleteHelper(node* currentNode) { // recursive delete function
        // use post order to delete each node

        if(currentNode != nullptr) {
            deleteHelper(currentNode->leftChild);

            deleteHelper(currentNode->rightChild);

            delete currentNode;
            currentNode = nullptr;
        }
    }


};