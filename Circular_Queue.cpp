#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class CircularQueue {
private:
    int size;
    int front, rear;
    int queue[MAX_SIZE];

public:
    CircularQueue() {
        size = MAX_SIZE;
        front = rear = -1;
    }

    void enqueue(int item) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full" << endl;
        } else if (front == -1) {
            front = rear = 0;
            queue[rear] = item;
        } else {
            rear = (rear + 1) % size;
            queue[rear] = item;
        }
    }

    int dequeue() {
        int item;
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        } else if (front == rear) {
            item = queue[front];
            front = rear = -1;
        } else {
            item = queue[front];
            front = (front + 1) % size;
        }
        return item;
    }

   void displayQueue() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        } else if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        } else {
            for (int i = front; i < size; i++) {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
};


int main() {
    CircularQueue cQueue;
    cQueue.enqueue(11);
    cQueue.enqueue(22);
    cQueue.enqueue(33);
    cQueue.enqueue(44);
    cQueue.enqueue(55);
    cQueue.displayQueue();
    cQueue.dequeue();
    cQueue.dequeue();
    cQueue.displayQueue();
    cQueue.enqueue(66);
    cQueue.displayQueue();

    return 0;
}
