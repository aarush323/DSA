#include<iostream>
using namespace std;
class Student{
    public:
    int roll_no;
    int password;
    string name;
    Student* next;

};

class Hash{
public:
Student *s[10];


Hash(){
    for(int i=0;i<10;i++){
        s[i] = NULL;
    }
}


Student* getNode(){
    Student* temp = new Student;
    temp->next = NULL;
    cout << "roll no: ";
    cin >> temp->roll_no;

   cout << "password: ";
    cin >> temp->password;
   
    cout << "name: ";
    cin >> temp->name;
    return temp;
}

void insert(){
    Student* t = getNode();
    int num = t->roll_no;
    int sum=0;

    do{
        int n = num%10;
        num = num/10;
        sum += n;
    }while(num!=0);

    int hash_index = (sum)%10;
    

    if(s[hash_index] == NULL){
        s[hash_index] = t;
        return;
    }
    Student *p = s[hash_index];

    while(p->next != NULL){
        p=p->next;
    }
    p->next = t;
    

}

void display(){
    
    
    int roll,roll_no;
    cout << "enter roll:";
    cin >> roll_no;
    roll = roll_no;
    int sum=0;

    do{
        int n = roll%10;
        roll = roll/10;
        sum += n;
    }while(roll!=0);

    Student *f = s[sum % 10];

    while(f!= NULL){
        if(f->roll_no == roll_no){
            cout << "student record found: "<< f->name << endl;
            return;
        }
        f=f->next;
    }
    if(f == NULL){cout << "record not found" << endl;}
}

};

int main(){
    Hash h1;
    int x;
    do{
        cout << "choice ( 1 to insert , 2 to display , 0 to exit: ): ";
        cin >> x;
        switch(x){
            case 1:
            h1.insert();
            break;
            case 2:
            
            h1.display();
            break;
        }
    }while(x!=0);
}