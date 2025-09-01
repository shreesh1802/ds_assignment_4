#include <iostream>
using namespace std;
#define SIZE 5

class Queue 
{
    int arr[SIZE];
    int front;
    int rear;

public:
    Queue() 
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int val) 
    {
        if ((rear + 1) % SIZE == front) 
        {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) 
        { 
            front = rear = 0;
        } 
        else 
        {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = val;
        cout << "Enqueued: " << val << endl;
    }

    void dequeue() {
        if (front == -1) 
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) 
        {
            front = rear = -1;
        } 
        else 
        {
            front = (front + 1) % SIZE;
        }
    }

    int peek() 
    {
        if (front == -1) 
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (front == -1) 
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) 
        {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() 
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); 

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    cout << "Peek: " << q.peek() << endl;

    return 0;
}

