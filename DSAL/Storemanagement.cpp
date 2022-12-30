#include<bits/stdc++.h>
using namespace std;

// defining the store size
#define MAX 6

// product details
struct products {
    string productname;
    int cost;
    string weight;
};


class Queue {


    public:

// products array creation
    products stores[MAX];
    int front, rear;


    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        if(front == -1 && rear == -1)
            return true;

        return false;
    }

    bool isFull() {

        if((rear + 1)%MAX == front) {
            return true;
        }
        return false;
    }


// adding product in the store
    void enqueue() {
        
        if(isFull()) {
            cout << "Cannot insert product\n";
            cout << "Queue is full !!\n\n";
        }
        else {

            products p;

            cout << "Enter the name of the product : ";
            cin >> p.productname;

            cout << "Enter the cost of the product : ";
            cin >> p.cost;

            cout << "Enter the weight of the product : ";
            cin >> p.weight;

            if(isEmpty()) {
                

                front++;
                rear++;
                stores[rear] = p;
            }

            else {
                rear = (rear+1)%MAX;
                stores[rear] = p;

            }
            cout << p.productname <<" added in the store !!\n";
        }

    }


// removing product from the store
    void dequeue() {

        if(isEmpty()) {
            cout << "Cannot delete product !!\n";
            cout << "store is empty\n\n";
        }

        else if(front == rear) {
            cout << "The product removed from the store is : "<<stores[front].productname <<endl;

            front = -1;
            rear = -1;
            cout << "The store is now empty\n";
        }

        else {
            cout << "The product removed from the store is : "<<stores[front].productname <<endl;
            front = (front+1)%MAX;
        }
    }


// displying the product list
    void display() {

        if(isEmpty()) {
            cout << "Store is empty !!\n";
        }
        else {
            cout << "Diplaying the products list\n\n";
            int i = front;
            do {

                cout << stores[i].productname <<"   "<<stores[i].cost <<"  "<<stores[i].weight<<"   "<<endl;
                i = (i+1)%MAX;

            }while((rear+1)%MAX != i);
            cout << "\n";
        }

    }
};
int main() {

    Queue q1;
    int choice = 0;

    // menu driven code
    do {

        cout << "\nWelcome to the store management system\n";
        cout << "\n1. Add product in the store";
        cout << "\n2. Delete product from the store";
        cout << "\n3. Display the products list";
        cout << "\n0. for exit";
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch(choice) {
            
            // add products
            case 1:
            {
                q1.enqueue();
                break;
            }

            // remove products
            case 2:
            {
                q1.dequeue();
                break;
            }

            // display the products list
            case 3:
            {
                q1.display();
                break;
            }

            // end of program
            case 0:
            {
                cout << "Program terminated successfully !!\n";
                break;
            }

            default:
            {
                cout << "Wrong choice entered !!\n";
            }
        }

    }while(choice != 0);


    return 0;
}