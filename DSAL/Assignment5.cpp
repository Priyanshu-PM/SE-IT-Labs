// Name : Priyanshu Mahukhaye\
// Roll no : 23385
// Assignment 5

// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }


    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree {

    public:
    Node *root;

    BinarySearchTree() {
        
        root = NULL;
    }

    Node *insertNode(Node *rooter, Node *n) {

        if(rooter == NULL) {
            return n;
        }
        else if(rooter->data > n->data) {
            rooter->left = insertNode(rooter->left, n);
        }
        else if(rooter->data < n->data) {
            rooter->right = insertNode(rooter->right, n);
        }
        else if(rooter->data == n->data) {
            cout << "Cannot insert same value !!";
            return rooter;
        }
        
        return rooter;
    }

    void inOrder(Node *n) {
        if(n == NULL) {
             return;
        }
        else {
            inOrder(n->left);
            cout << n->data << " ";
            inOrder(n->right);
        }
    }

    void preOrder(Node *n) {
        if(n == NULL) {
            return;
        }
        else {
            cout << n->data << " ";
            preOrder(n->left);
            preOrder(n->right);
        }
    }

    void postOrder(Node *n) {
        if(n == NULL) {
            return;
        }
        else {
            postOrder(n->left);
            postOrder(n->right);
            cout << n->data << " ";
        }
    }

    void searchNode(Node *n, int key) {

        if(n == NULL) {
            cout << "Tree is empty !!\n";
        }
        else {
            if(n->data == key) {
                cout << "Key is available in the tree !!\n";
            }
            else if(n->data > key) {
                searchNode(n->left, key);
            }
            else if(n->data < key) {
                searchNode(n->right, key);
            }
            else {
                cout << "Key not found in the tree !!\n";
            }
        }
    }

    Node* findSuccessor(Node *n) {
        
        n = n->right;
        while(n->left != NULL) {
            n = n->left;
        }
        return n;
    }
    Node* deleteNode(Node *n, int key) {

        if(n == NULL) {
            cout << "Cannot delete node as tree is empty !!\n";
            return n;
        }
        if(n->data == key) {

            if(n->left == NULL && n->right == NULL) {
                cout << "\n"" Node deleted from the tree\n";
                return NULL;
            }
            else if(n->left != NULL && n->right == NULL) {
                cout << "\n"<<" Node deleted from the tree\n";
                return n->left;
            }
            else if(n->left == NULL && n->right != NULL) {
                cout << "\n"<<" Node deleted from the tree\n";
                return n->right;
            }

            else {

                Node *temp = findSuccessor(n);
                n->data = temp->data;
                n->right = deleteNode(n->right, temp->data);
            }
        }
        else if(n->data > key) {
            n->left = deleteNode(n->left, key);
        }
        else if(n->data < key) {
            n->right = deleteNode(n->right, key);
        }
        return n;
    }

    int calculateHeight(Node *n) {
        int height;
        if(n == NULL) {
            return 0;
        }

        int l  = 1 + calculateHeight(n->left);
        int r = 1 + calculateHeight(n->right);
        return max(l, r);
    }

    int leafNodes(Node *n) {
        if(n == NULL) {
            return 0;
        }
        if(n->left == NULL && n->right == NULL) {

            cout << n->data << " ";
        }
        leafNodes(n->left);
        leafNodes(n->right);
        
    }

    void levelWiseDisplay(Node *n, int level, map<int,vector<int>> &mappi) {
        if(n == NULL) {
            return;
        }
        mappi[level].push_back(n->data);
        
        levelWiseDisplay(n->left, level+1, mappi);
        levelWiseDisplay(n->right, level+1, mappi);
    }

};

int main() {

    BinarySearchTree *bst = new BinarySearchTree();
    int ch = 0;
    do {

        cout << "\nBinary Search Tree Program\n\n1. for inserting a node\n2. for searching the node\n3. for deleting a node\n4. for inorder traversal\n5. for preorder\n6. for postorder\n7. for calculating the height\n8. for printing the leaf node\n9. for Printing the tree level wise \n0. for exit\n\n";
        cout << "Enter your choice : ";
        cin >> ch;
        int val;
        map<int, vector<int>> level;
        switch(ch) {

            case 1:
                cout << "Enter the value you want to insert : ";
                cin >> val;
                bst->root = bst->insertNode(bst->root, new Node(val));
                break;

            case 2:
                cout << "Enter the value you want to search : ";
                cin >> val;
                bst->searchNode(bst->root, val);
                break;

            case 3:
                cout << "Enter the value you want to delete from the tree : ";
                cin >> val;
                bst->deleteNode(bst->root, val);
                break;

            case 4:
                cout << "Printing the inorder traversal :\n";
                bst->inOrder(bst->root);
                break;

            case 5:
                cout << "Printing the preorder traversal :\n";
                bst->preOrder(bst->root);
                break;

            case 6:
                cout << "Printing the postorder traversal :\n";
                bst->postOrder(bst->root);
                break;

            case 7:
                cout << "The height of the tree is : "<< bst->calculateHeight(bst->root) << endl;
                break;

            case 8:
                cout << "The leaf nodes in the tree are :\n" << bst->leafNodes(bst->root) << endl;
                break;

            case 9:
                // map<int, vector<int>> level;
                // map<int, vector<int>> level;
                bst->levelWiseDisplay(bst->root, 1, level);
                for(auto element: level) {

                    cout << "Level " << element.first << " : ";
                    for(auto x: element.second) {
                        cout << x << " ";
                    }
                    cout << endl;
                    break;
                }
                
            case 0:
            	cout << "Program terminated successfully !!";
            	break;

            default:
                cout << "Program terminated !!";
                break;
        
        }
    } while (ch != 0);
//     bst.root = bst.insertNode(bst.root, new Node(75));
//     bst.insertNode(bst.root, new Node(234));
//     bst.insertNode(bst.root, new Node(23));
//     bst.insertNode(bst.root, new Node(284));
//     bst.insertNode(bst.root, new Node(2894));
//     bst.insertNode(bst.root, new Node(25));
//     bst.insertNode(bst.root, new Node(204));
//     bst.insertNode(bst.root, new Node(24));
//     cout << "\n\nPrinting the inorder traversal :\n";
//     bst.inOrder(bst.root);
//     cout << "\n\nPrinting the preorder traversal :\n";
//     bst.preOrder(bst.root);
//     cout << "\n\nPrinting the postorder traversal :\n";
//     bst.postOrder(bst.root);
//     cout <<"\n\n";
//    bst.deleteNode(bst.root, 23);

    return 0;
}
