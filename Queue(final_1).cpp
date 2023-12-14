#include <iostream>
using namespace std;

const int maxSize = 10;

class Queue {
private:
    int front, rear;
    int arr[maxSize];

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize;
        }

        arr[rear] = value;
        cout << value << " enqueued to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        int removedValue = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }

        cout << removedValue << " dequeued from the queue." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Elements in the queue: ";
        int i = front;

        do {
            cout << arr[i] << " ";
            i = (i + 1) % maxSize;
        } while (i != (rear + 1) % maxSize);

        cout << endl;
    }
};

int main() {
    Queue ok;

    ok.enqueue(10);
    ok.enqueue(20);
    ok.enqueue(30);

    ok.display();

    ok.dequeue();
    ok.display();

    ok.enqueue(40);
    ok.display();
    ok.enqueue(50);
    ok.display();
    ok.dequeue();
    ok.enqueue(60);
    ok.enqueue(70);
    ok.dequeue();
    ok.display();

    return 0;
}
