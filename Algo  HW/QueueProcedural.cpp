#include <bits/stdc++.h>
using namespace std;

int n = 5;
int queue1[5];
int front = 0;
int rear = 0;

bool isEmpty() {
    return front == rear;
}

bool isFull() {
    return (rear + 1) % n == front;
}

void enqueue(int element) {
    if (isFull()) {
        cout << "enqueue failed!" << endl;
    } else {
        queue1[rear] = element;
        rear = (rear + 1) % n;
        cout << "element: " << element << " enqueued" << endl;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "dequeue failed!" << endl;
    } else {
        cout << queue1[front] << " dequeued" << endl;
        front = (front + 1) % n;
    }
}

void frontElement() {
    if (isEmpty()) {
        cout << "No elements available" << endl;
    } else {
        cout << queue1[front] << " is the front element" << endl;
    }
}

void show() {
    if (isEmpty()) {
        cout << "Nothing to show" << endl;
    } else {
        cout << "The values are:" << endl;
        for (int i = front; i != rear; i = (i + 1) % n) {
            cout << queue1[i] << endl;
        }
    }
    cout << endl;
    cout << "Here ";
    frontElement();
    cout << endl;
}

int main() {
    dequeue();
    enqueue(10);
    enqueue(20);

    show();

    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    show();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    show();

    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);
    enqueue(110);

    show();

    return 0;
}

