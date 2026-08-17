//Stack using Linked List

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

// Push operation
void push(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = top;

    top = newNode;
}

// Pop operation
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }

    Node* temp = top;

    cout << "Popped: " << temp->data << endl;

    top = top->next;

    delete temp;
}

void display() {
    Node* temp = top;

    cout << "Stack: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    return 0;
} 

//Queue Using Linked List

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// Enq operation
void enqueue(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Deq operation
void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = front;

    cout << "Dequeued: " << temp->data << endl;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

void display() {
    Node* temp = front;

    cout << "Queue: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    return 0;
}