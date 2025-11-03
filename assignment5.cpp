#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    int priority;
    Node *next;
};
class MyQueue{
    public:
    Node *front;
    Node* rear;
    MyQueue(){
        front = NULL;
        rear = NULL;
    }

    Node* getnode(){
        Node* t;
        t = new(Node);
        t->next = NULL;
        cout << "enter data: ";
        cin >> t->data;
        cout << "enter priority: ";
        cin >> t->priority;
        return t;

    }
    void push(){
        Node* temp = getnode();
        if(front == NULL){
            front = temp;
            front->next = NULL;
            return;
        }
        if(temp->priority > front->priority)
        {
            temp->next = front;
            front = temp;
        }
        else{
        Node *p,*t;
        p = front;
        
        while(p->next != NULL && p->next->priority >= temp->priority){
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
        
    }

    Node* extract_max(){
        Node* s = front;
        front = front->next;
        return s;
    }

    void peek(){
        cout << "current priority: "<< front->priority << endl << "data: " << front->data << endl;
    }
};

int main(){
    MyQueue Q1;
    int x;
    do{
        cout << "enter choice: ";
        cin >> x;
        switch(x){
            case 1:
            Q1.push();
            break;
            case 2:
            Q1.extract_max();
            break;
            case 3:
            Q1.peek();
            break;
        }
    }while(x!=0);
}