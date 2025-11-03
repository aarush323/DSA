#include<iostream>
using namespace std;
class MyNode{
    public:
    string data;
    MyNode *next;

};



class MyStack{
    MyNode *top;
    MyNode *prev;
    //string prev;
    public:
    MyStack(){
        top = NULL;
        prev = NULL;
    }

    MyNode *getnode(){
        MyNode *t;
        t = new MyNode;
        
        cout << "enter text: ";
        cin >> t->data;
        return t;
    }

    void PushStack(){
        MyNode *temp = getnode();
        temp->next = NULL;
        if(top == NULL){
            top = temp;
        }
        else{
            temp->next = top;
            top = temp;
        }

    }

    void PopStack(){
        MyNode *temp = top;
        if(top == NULL){
            cout << "nothing to pop , stack empty." << endl;
        }
        else{
            top = top->next;
        
            temp->next = prev;
            prev = temp;
        
            
        }
    }

    void peek(){
        if(top == NULL){
            cout << "Stack is empty" << endl;
        }
        else{
            cout << "value of top: " << top->data << endl;
        }
    }

    void redo(){
        
        MyNode *temp = prev;
        if(prev == NULL){
            cout << "nothing to redo";
        }
        else{
            prev = prev->next;
            temp->next = top;
            top = temp;
            
            
        }
    }
    
};

int main(){
    MyStack L1; // object created
   int x;
   int y;
   
   do{// to continue/exit the code
    cout << "enter choice(1:Push, 2:undo, 3:Peek, 4:redo): ";
    cin >> y;
    switch(y){
        // choice to the user b/w various ops
    case 1:
    L1.PushStack();
    break;
    case 2:
    L1.PopStack();
    break;
    case 3:
    L1.peek();
    break;
    case 4:
    L1.redo();
    break;
    default:
    cout << "enter valid choice: ";
    }
    cout << "0 to continue, 1 to stop: " ;
    cin >> x;
    

   }while(x!=1);
   
}