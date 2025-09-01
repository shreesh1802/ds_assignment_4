#include <iostream>
using namespace std;
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

bool isFull()
{
    return (rear == MAX - 1);
}

bool isEmpty()
{
    return (front == -1 || front > rear);
}

void enqueue(int x)
{
    if(isFull())
    {
        cout << "Queue is full \n"<<endl;
        return;
    }
    
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    
    else 
    {
        rear = rear + 1;
    }
    queue[rear] = x;
}

int dequeue() 
{
    if(isEmpty())
    {
        cout << "Queue is empty" <<endl;
        return -1;
    }
    else
    {
        int x = queue[front];
        front = front + 1;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
        return x;
    }
}

int display()
{
    if(isEmpty())
    {
        cout << "Queue is empty \n" << endl;
        return -1;
    }
    
    for(int i = front ; i <= rear ; i++)
    {
        cout << queue[i] << " " ;
    }
    return 0;
}

int peek()
{
    if(isEmpty())
    {
        cout << "Queue is empty \n" << endl;
        return -1;
    }
    
    else
    {
        return queue[front];
    }
}

int main()
{
    enqueue(10);
    cout << "front element of queue: "<< peek() << endl;
    enqueue(20);
    enqueue(30);
    display();
    cout << endl;
    cout << "Dequeued: " << dequeue() <<endl;
    cout << "front element of queue: "<< peek() << endl;
    cout << "Dequeued: " << dequeue() <<endl;
    cout << "front element of queue: "<< peek() << endl;
    cout << "Dequeued: " << dequeue() <<endl;
    cout << "front element of queue: "<< peek() << endl;
    return 0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~METHOD - 2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include<iostream>
using namespace std;
#define SIZE 3

class Queue
{
    int arr[SIZE];
    int front;
    int rear;

    public:

    Queue()
    {
        front = 0;
        rear = 0;
    }

    void enqueue(int val)
    {
        if(rear == SIZE)
            cout<<"Queue is Full"<<endl;
        else
        {
            arr[rear] = val;
            rear++;
        }
    }
    
    
    void dequeue()
    {
        if(front == rear)
            cout<<"Queue is Empty"<<endl;
        else
        {
            cout<<"Dequeued element= "<<arr[front]<<endl;
            front++;
        }
    }
    
    void display()
    {
        if(front == rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            for(int i = front; i < rear; i++)
            {
                cout << arr[i] <<" ";
            }
        }
    }
    
    void peek()
    {
        if(front == rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            cout<<"front element: "<<arr[front]<<endl;
        }
    }
};

int main()
{
    Queue q;

    cout<<"Enqueuing element= "<<10<<endl;
    q.enqueue(10);
    cout<<"Enqueuing element= "<<20<<endl;
    q.enqueue(20);
    cout<<"Enqueuing element= "<<30<<endl;
    q.enqueue(30);
    q.peek();
    
    q.display();
    
    cout << endl;
    
    q.dequeue();
    q.peek();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}

