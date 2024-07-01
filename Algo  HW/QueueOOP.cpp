#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue {
private:
    T *queue;
    int n;
    int front;
    int rear;
public:
    Queue() {
        n = 5;
        queue = new T[n];
        front = 0;
        rear = 0;
    }

    Queue(int n) {
        this->n = n;
        queue = new T[n];
        front = 0;
        rear = 0;
    }

    bool isFull() {
        return (rear + 1) % n == front;
    }

    bool isEmpty() {
        return front == rear;
    }

    void enqueue(T x) {
        if (isFull()) {
            cout << "overflow\n";
        } else {
            queue[rear] = x;
            rear = (rear + 1) % n;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "underflow\n";
        } else {
            front = (front + 1) % n;
        }
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            int i = front;
            while (i != rear) {
                cout << queue[i] << " ";
                i = (i + 1) % n;
            }
            cout << endl;
        }
    }

    T frontElement() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return queue[front];
    }

    int Size() {
        return (rear - front + n) % n;
    }
};

int main() {
    Queue<string> *q = new Queue<string>();
    q->enqueue("FAHIMA");
    q->enqueue("ISLAM");
    q->printQueue();

    q->dequeue();
    q->printQueue();

    q->enqueue("C++");
    q->enqueue("Queue");
    q->enqueue("Example");
    q->printQueue();

    q->dequeue();
    q->printQueue();

    delete q;
    return 0;
}
