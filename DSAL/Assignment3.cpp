#include<bits/stdc++.h>
using namespace std;
#define MAX 6

class Queue {
    public:
    int arr[MAX];
    int front, rear;
    
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int n) {
        if(front == -1 && rear == -1) {
            front++;
            rear++;
            arr[rear] = n;
        }

        else if((rear+1)%MAX == front) {
            cout << "Queue is overflow !!\n";
        }
        else {
            rear = (rear+1)%MAX;
            arr[rear] = n;

        }
    }

    void dequeue() {
        if(front == -1 && rear == -1) {
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
        if(front == -1 && rear == -1) {
            cout << "Cannot display !! Queue is empty !!\n";
        }
        else {
            int i = front;
            do {
                cout << arr[i] << " ";
                i = (i+1)%MAX;

            }while((rear+1)%MAX != i);
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

    a1.dequeue();

    a1.enqueue(100);
    a1.enqueue(1);

    a1.display();

}