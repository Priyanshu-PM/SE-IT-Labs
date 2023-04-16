#include<bits/stdc++.h>
using namespace std;
#define MAX 6

class Queue {
    public:
    int arr[MAX];
    int front = -1, rear = -1;
    
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        if(front == -1 && rear == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if((rear+1)%MAX == front) {
            return true;
        }
        return false;
    }

    void enqueue(int n) {
        if(isEmpty()) {
            front++;
            rear++;
            arr[rear] = n;
        }

        else if(isFull()) {
            cout << "Queue is overflow !!\n";
        }
        else {
            rear = (rear+1)%MAX;
            arr[rear] = n;

        }
    }

    void dequeue() {
        if(isEmpty()) {
            cout << "Queue is underflow !!\n";
        }

        else if(front == rear) {
            cout << "The dequeued element is : "<<arr[front] << "\n";
            front = -1;
            rear = -1;
            cout << "The queue is now empty !!\n";
        }

        else {
            cout << "The dequeued element is : "<< arr[front]<<"\n";
            front = (front+1)%MAX;
        }
    }

    void display() {
        if(isEmpty()) {
            cout << "Cannot display !! Queue is empty !!\n";
        }
        else {
            int i = front;
            do {
                cout << arr[i] << " ";
                i = (i+1)%MAX;

            }while((rear+1)%MAX != i);
            cout << "\n";
        }
    }
};

int main() {
    Queue a1;

    a1.enqueue(3);
    a1.enqueue(5);
    a1.enqueue(7);
    a1.enqueue(10);
    a1.enqueue(13);
    a1.enqueue(33);
    a1.display();
    a1.dequeue();

    a1.enqueue(100);
    a1.enqueue(1);

    a1.display();

}