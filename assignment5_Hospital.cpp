#include<iostream>
using namespace std;

class Hospital{
    public:
    int priority;
    string injury;
};
enum Priority{

};
class DEQUEUE{
    public:
    Hospital* arr[100];
    int front;
    int rear;
    DEQUEUE(){
         front = -1;
         rear = -1;
    }

    Hospital* getelement(){
        Hospital *t = new Hospital();
        cout << "Enter Hospital record" << endl;
        cin >> t->injury;
        cout << "enter priority: " << endl;
        cin >> t->priority;
        return t;
    }

    void Insert_Record(){
        Hospital *temp = getelement();
        if(rear == 99){
            cout << "queue full" << endl;
        }
        else{
            rear++;
            if(front == -1){front++;}
            arr[rear] = temp;

        }
    }

    void dequeue_record(){
        if(front == -1){
            cout << "No records to delete: ";

        }
        else{
            int min = 0;
            int track;
            for(int i= front; i<=rear;i++){
                if(arr[i]->priority < min ){
                    min = arr[i]->priority;
                    track = i;
                }
            }
            for(int i=track;i<rear;i++){
                arr[i] = arr[i+1];

            }
            rear--;
        }
    }

    void display(){
        if (front == -1) {
            cout << "No records to display." << endl;
            return;
        }
        for (int i = front+1; i <= rear; i++) {
        Hospital* key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j]->priority < key->priority) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for(int i=front;i<=rear;i++){
        cout << "Description: " << arr[i]->injury << endl;
    }
    }

    
};
int main(){
    DEQUEUE d;
    int x;
    do{
    cout << "enter option (1:display 2:insert record 3:delete record): ";
    cin >> x;
    switch(x){
        case 1:
        d.display();
        break;
        case 2:
        d.Insert_Record();
        break;
        case 3:
        d.dequeue_record();
        break;
    }
}while(x!=0);
}