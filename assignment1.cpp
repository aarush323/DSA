//SINGLY LINKED LIST

#include<iostream>
using namespace std;
// struct containing the required elements of the db
typedef struct Mynode{
    long long int phone_no;
    string name;
    struct Mynode *next;
}Mynode;

class MyList{
    Mynode *head;

    public:
    MyList(){
        head = NULL; // head pointer should be null by default
    }

    ~MyList(){
        while(head != NULL){
            Mynode *p = head->next; 
            p = head->next;
            free (head);
            head = p;
        }
    }
    Mynode *getNode(){
        // creating a new node 
        Mynode *t;
        t = new(Mynode);
        cout << "enter phone no: ";
        cin >> t->phone_no;
        if(t->phone_no >= 1000000000 && t->phone_no <= 9999999999){
        cout << "enter email: ";
        cin >> t->name;

        }
        else {
            // again asking for the correct mobile num input
            cout << "enter valid num" << endl;
            t = new(Mynode);
        cout << "enter phone no: ";
        cin >> t->phone_no;
        if(t->phone_no >= 1000000000 && t->phone_no <= 9999999999){
        cout << "enter email: ";
        cin >> t->name;}
        else{
            cout << "again wrong num entered again, restart program" << endl;
        }
            
        }
        return t;
        
    }
    
    void create(){
        // creating node for first time
        
        Mynode *t = getNode();
        
        t->next = NULL;
        if(head == NULL){
            head = t;
        }
        else{
            Mynode *p;
            p = head;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = t;
        }

    }

    void insertathead(){
        // insert at beginning
        Mynode *t = getNode();
        t->next = NULL;

        if(head == NULL){// if list is empty
            head = t;
        }
        else{
            t->next = head;
            head = t;
        }
    }

    void insertatend(){
        // add node at end
        Mynode *t = getNode();
        t->next = NULL;

        if(head == NULL){ // if list is empty
            head = t;
        }
        else{
            Mynode *p = head;
            while(p->next != NULL){//to go to end
                p = p->next;
            }
            p->next = t;
            p = t;
        }
    }

    void insertinbw(){
        // adding element after the node containing the value
        Mynode *t = getNode();
        t->next = NULL;
        long long int temp;
        cout << "select the phone number after which you have to insert: ";
        cin >> temp;
        if(head == NULL){//empty list
            head = t;
        }
        else{
        Mynode *p = head;
        while(p->phone_no != temp){// to go to the given valued node
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
        }
    }
    void search(){
        // searches data and displays
        long long int data;
        cout << "enter data you want searched: ";
        cin >> data ;
        Mynode *p = head;
        Mynode *t;
        if(head == NULL){
            cout << "nothing to search" << endl;
        }
        else{
            while(p->phone_no != data){
                t = p;
                p = p->next;
            }
            if(p == NULL){
            cout << " not found in the list." << endl;
                }
            else{
        cout << "Name: " << p->name << endl;
        cout << "Phone number: " << p->phone_no << endl;
            }
        }
    }
    
    void deletedata(){
        // deletes the node after the node of which data is entered
        long long int data;
        cout << "enter data you want deleted: ";
        cin >> data ;
        Mynode *p = head;
        Mynode *t;
        if(head == NULL){
            cout << "nothing to delete" << endl;
        }
        else{
            while(p->phone_no != data){
                t = p;
                p = p->next;
            }
            if(p == head){
                head = head->next;
                delete p;
            }
            else{
                t->next = p->next;
                delete p;
            }
        }
    }

    /*void deleteathead(){
        // deletes the starting position
        Mynode *p = head;
        p = head;
        if(head == NULL){
            cout << "list is empty";
        }
        else{
            head = head->next;
            delete p;
        }
    }

    void deleteatend(){
        // deletes the last positioned node
        Mynode *p;
        p = head;
        Mynode *t;
        t = head;
        if(head == NULL){
            cout << "nothing to delete";
        }
        else{
            while(p->next != NULL){
                t = p;
                p = p->next;
            }
            t->next = NULL;
            delete p;
        }
    }*/

    void reverselist(){
        //reverses the linked list
        Mynode *current, *temp, *result;
        temp = NULL;
        result = NULL;
        current = head;

        if(head == NULL){
            cout << "empty list";
        }
        else{
            while(current!=NULL){
                temp = current->next;
                current->next = result;
                result = current;
                current = temp;
            }
            head = result;
        }
    }
    void display(){
        Mynode *f;
        f = head;
        if(head == NULL){
            cout << "LIST EMPTY"<< endl;
        }
        while(f!=NULL){
            cout << "Name: " << f->name << endl << "phone number: " << f->phone_no << endl << endl;
            f = f->next;
        }
    }
};

int main(){
    MyList L1; // object created
   int x;
   int y;
    L1.create();
   do{// to continue/exit the code
    cout << "enter choice(1:insertathead, 2:insertatend, 3:insertinbetween, 4:deletedata, 7:reverse list, 8:display:   ";
    cin >> y;
    switch(y){
        // choice to the user b/w various ops
    case 1:
        L1.insertathead();
        break;
    case 2:
        L1.insertatend();
        break;
    case 3:
        L1.insertinbw();
        break;
    case 4:
        L1.deletedata();
        break;
    case 5:
        L1.reverselist();
        break;
    case 6:
        L1.display();
        break;
    case 7:
        L1.search();
        break;
    default:
    cout << "enter valid choice: ";
    break;
    
    }
    cout << "0 to continue, 1 to stop: " ;
    cin >> x;
    

   }while(x!=1);
   
    
}