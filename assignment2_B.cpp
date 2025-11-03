/*
Task Scheduling System (Queue): Managing tasks in a first-in, first-out (FIFO) order, such
as print job scheduling or process management in an operating system.

Aarush Oak 23332
*/

#include<iostream>
using namespace std;

enum level{//difficulty priority level 
    low=0,
    medium,
    high
};
typedef struct Task{
    string title;
    enum level priority;
    Task* next;
} Task;

class my_queue{
    Task* front=NULL;
    Task* rear=NULL;
    public:
        Task* get_node(){
            // Function to create a new node by taking  input
            string title;
            cout<<"Enter Title of Task:";
            cin>>title;
            int difficulty;
           /*cout<<"Enter Difficulty of Task(0->Low,1->Medium,2->High):";    
            cin>>difficulty;*/ 
            int priority;
            cout<<"Enter Priority of Task(0->Low,1->Medium,2->High):";
            cin>>priority;


            enum level arr[]={low,medium,high};
            Task* new_node=new Task();

            new_node->title=title;
            //new_node->difficulty=arr[difficulty];
            new_node->priority=arr[priority];
            return new_node;
        }
        void enqueue(){
            // Insert node at rear
            Task* t=get_node();
            if(front==NULL){
                front=t;
                rear=t;
            }
            else{
                rear->next=t;
                rear=t;
            }
        }
        void dequeue(){
            // Delete node from front
            if(front==NULL){
                cout<<"Queue is empty!\n";
            }
            else{
                Task* temp=front;
                front=front->next;
                delete temp;
            }
        }
       void  peek(){
            // Return front element
            if(isEmpty()){
                cout<<"Queue is empty!";
                
            }
            else{
                cout << "current element is " << front->title << " and priority is "<< front->priority << endl << endl;
            }
        }
        bool isEmpty(){
            //Check if queue is empty
            return front==NULL;
        }

};
int main(){
    my_queue Tasks;
   
       
        int choice, x;
        do{
        cout << "0 to continue, 1 to stop: ";
        cin >> x; 
        cout<<"Enter 0(Exit),1(Add Task),2(delete Task),3(Peek):";
        cin>>choice;
        switch(choice){
            case 1:
                Tasks.enqueue();
                
                break;
            case 2:
                if(Tasks.isEmpty()){
                    cout<<"No Tasks" << endl;
                }
                else {
                    Tasks.dequeue();
                    cout<<"Task Finished " << endl;
                }
                break;
            case 3:
                if(Tasks.isEmpty()){
                    cout<<"No Tasks to peek at "  << endl;
                }
                else{
                    Tasks.peek();
                }
                break;
            
    
        }
    }while(x != 1);
    return 0;
}
/*
================ SAMPLE OUTPUT =================

Enter 1(Add Task),2(Finish Task),3(Peek):1
Enter Title of Task: Homework
Enter Priority of Task(0->Low,1->Medium,2->High):2
Task Added to front!

1(Add Task),2(Finish Task),3(Peek):1
Enter Title of Task: Laundry
Enter Priority of Task(0->Low,1->Medium,2->High):0
Task Added to front!

Enter 0(Exit),1(Add Task),2(Finish Task),3(Peek):3
Title:Homework
Priority:2

Enter 0(Exit),1(Add Task),2(Finish Task),3(Peek):2
Task Finished

Enter 0(Exit),1(Add Task),2(Finish Task),3(Peek):3
Title:Laundry
Difficulty:0
Priority:1

Enter 0(Exit),1(Add Task),2(Complete Task),3(Peek):2
Task Finished

Enter 0(Exit),1(Add Task),2(Finish Task),3(Peek):3
Queue is empty!

Enter 0(Exit),1(Add Task),2(Finish Task),3(Peek):0

*/