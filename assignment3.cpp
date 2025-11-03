/*
Problem Statement:
Create a student database of at least 5 SEIT students, each having:
• Roll Number (Integer)
• Name (String)
• SGPA (Float)
Perform the following operations on the array of structure:
a. Sort students by roll number (ascending order) using Bubble Sort.
b. Sort students alphabetically by name using Insertion Sort.
c. Sort students by SGPA in descending order using Quick Sort to get top 10 toppers.
d. Search for students by SGPA using Linear Search and display all matches.
e. Search for student(s) by name using non-recursive Binary Search, display all partial matches
*/


#include<iostream>
#include<cstring>
#include<string>
using namespace std;

template<typename T>
T template1(const string &output) {//template for sgpa
    T value;
    int flag = 0;
    while(flag == 0){
    cout << output;
    cin >> value;
    if(value >0 && value<11){
        flag = 1;
    }
    else{
        cout << "enter valid sgpa: " << endl;
    }
    }
    return value;
}

struct Student
{
   int roll_no;
   float sgpa;
   char name[100];
   

};
class students{
    public:
    struct Student s[50];
    students(int n){
         for(int i=0;i<n;i++){
            int flag = false;
            cout << "enter details of student"<<i+1<<endl;
            cout << "enter roll no: ";
            cin >> s[i].roll_no;
            cin.ignore();
            cout << "enter the name: ";
            cin.getline(s[i].name, 100);
            
            int choice = template1<int> ("Enter 1 for sgpa in float and 2 for sgpa in double:");//choice for float or double
            if (choice == 1) {
            float temp = template1<float>("Enter SGPA (float): ");
            s[i].sgpa = temp;   
            } 
            else {
            s[i].sgpa = template1<double>("Enter SGPA (double): ");
            }
        }
    }
    
    

    void display(int n){
        for(int i=0;i<n;i++){
            cout << i+1 << "   ROLL NO: " << s[i].roll_no << "    NAME: "<< s[i].name<< "    MARKS: "<<s[i].sgpa << endl;
        }
    }
    void displayTop(int n){
        cout << "students with more than 9 sgpa: "<< endl;;
        for(int i=0;i<n;i++){
            if(s[i].sgpa >9){
                cout << s[i].roll_no << "    " << s[i].name << endl;
            }
            
        }
    }

    void modify(int n){
        int t;
        cout << "enter new marks: ";
        cin >> t;
        s[n].sgpa = t;
       
    }
    template<typename T>
    void LinearSearch(T key, int n){
        int i =0;
        int flag=0;
        cout << "students with the entered sgpa: "<< endl;
        while(i<n){
            if(s[i].sgpa == key ){
                cout << "roll no: " << s[i].roll_no << " and name: " << s[i].name << endl;
                flag = 1;
            }
            i++;

        }
        if(flag ==0){
            cout << "No student w the entered sgpa found";
        }

    }

    void bubble_sort(int n){
        for( int j=0;j<n;j++){
            for(int i=0;i<n-1;i++){
            if (s[i].roll_no > s[i+1].roll_no){
                swap(s[i],s[i+1]);
                
            }
        }
    
    }
}


    void insertion_sort(int n) {
        for (int i = 1; i < n; i++) {
            Student key = s[i];
            int j = i - 1;
            while (j >= 0 && strcmp(s[j].name, key.name) > 0) {
                s[j+1]=s[j];
                j--;
            }
            s[j+1]=key;
        }
    }

    int partition(int l,int h) {
        float pivot = s[l].sgpa;
        int i = l+1;
        int j = h;
        while(i<=j){
            while(s[i].sgpa >= pivot && i <= h){
                i++;
            }
            while(s[j].sgpa <pivot && j>= l){
                j--;
            }
            if(i<j){
                swap(s[i],s[j]);
            }
        }
        swap(s[l],s[j]);
        return j;
        
    }
    void quicksort(int l, int h){
        if(l<h){
            int p = partition(l,h);
            quicksort(l,p-1);
            quicksort(p+1,h);
        }
    }


    void binary_search(int n, char k[100]){
        int low =0;
        int high = n-1;
        while (low <= high){
            int mid = (low+high)/2;
            if(strcmp(s[mid].name,k)==0){
                cout << "element found at " << mid << endl;
                break;
            }
            if(strcmp(k,s[mid].name)<0){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }

            }
        }
    
    
    };

int main(){
    int n;
    cout<<"enter num of students: ";
    cin >> n;
    students s1(n); // object created and constructor takes input
    int x;
    string key;
    
    do{
        cout << "enter the operation (1: display, 2:Top students, 3:modify, 4:linear search sgpa,5:bubble sort,6:insertion sort,7: binary search,8:quicksort, 0 to quit ): ";
        cin >> x;
        switch(x){
        case 1:
        s1.display(n);
        break;
        case 2:
        s1.displayTop(n);
        break;
        case 3:
        s1.modify(4);
        break;
        case 4:
        float k;
        cout << "enter sgpa for linear search: ";
        cin >> k;
        s1.LinearSearch(k, n);
        break;
        case 5:
        s1.bubble_sort(n);
        cout << "sorted list: " << endl;
        s1.display(n);
        break;
        case 6:
        s1.insertion_sort(n);
        break;
        case 7:
        s1.insertion_sort(n);
        char key[100];
        cin.ignore();
        cout << "enter name you want to search: " ;
        cin.getline(key, 100);
        s1.binary_search(n, key);
        break;
        case 8:
        s1.quicksort(0,n-1);
        s1.display(n);
        break;
        
        default:
        cout << "enter valid case no";
    }
    }while(x != 0);
    
    
    
return 0;
    
}


