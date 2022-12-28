#include<bits/stdc++.h>
using namespace std;

class Node {

    public:
    char data;
    Node *left;
    Node *right;
    Node *next;

    Node() {

        left = NULL;
        right = NULL;
        next = NULL;
    }

    Node(char c) {

        data = c;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Stack {


    public:
    Node *top;

    Stack() {
        top = NULL;
    }

    void push(char c) {
        Node *temp = new Node(c);
        if(top == NULL) {
            top = temp;
        }
        else {
            temp->next = top;
            top = temp;
        }
    }

    void push(Node *temp) {
        temp->next = top;
        top = temp;
    }

    Node *pop() {
        if(top == NULL)
            return NULL;
        Node *temp = top;
        top = top->next;

        return temp;

    }

    Node *stackTop() {
        return top;
    }

};

class ExpressionTree {

    public:
    Node *root;
    ExpressionTree() {
        root = NULL;
    }

    Node *createTreeFromPostfix(string str) {

        Stack s1;
        for(int i = 0; i < str.length(); i++) {

            char c = str[i];
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                s1.push(c);
            }

            else {
                Node *fe = s1.pop();
                Node *se = s1.pop();

                Node *temp = new Node(c);
                temp->right = fe;
                temp->left = se;

                s1.push(temp);
            }
        }

        return s1.stackTop();
    }

    string reverse(string str) {

        string ans;
        for(int i = str.length()-1; i >= 0; i--) {
            ans += str[i];
        }

        return ans;
    }
    Node *createTreeFromPrefix(string str) {
        
        string exp = reverse(str);
        Node *pointer = createTreeFromPostfix(exp);

        return pointer;
    }


    void displayTree(Node *root) {

        if(root == NULL) {
            return;
        }
        displayTree(root->left);
        cout << root->data << " ";
        displayTree(root->right);
    }
};

int main() {

    ExpressionTree et;
    string ex;
    cout << "Enter equation : ";
    cin >> ex;
    et.root = et.createTreeFromPostfix(ex);
    et.displayTree(et.root);
    cout << endl;

    cout << "Enter equation for prefix : ";
    cin >> ex;
    et.root = et.createTreeFromPrefix(ex);
    et.displayTree(et.root);

    return 0;

}