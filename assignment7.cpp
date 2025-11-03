
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
class File{
    public:
    void display(){
        fstream FILE;
        FILE.open("StudentData.txt",ios::in);
        char word;
        string line;
        int count1 =0;
        while (getline(FILE, line)){
        count1++;
        cout << line << endl;
        }
       

    if(FILE.eof())cout << "Number of Lines: " << count1 << endl;
    FILE.close();
    }

    void numberofchars(){
        fstream FILE;
        FILE.open("StudentData.txt",ios::in);
        char word;
        
        int count =0;
        while ( FILE.get(word)) {
        count++;
    }
    if(FILE.eof())cout << "number of chars: " << count << endl;
    }

    void write(){
       fstream FILE;
        FILE.open("StudentData.txt", ios::app);
        if (!FILE) {
            cout << "File not found" << endl;
            return;
        }
        string rollno, name, grade;
       
        cout << "Enter roll no: ";
        cin >> rollno;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter grade: ";
        cin >> grade;
        FILE << rollno << " " << name << " " << grade << endl;
        FILE.close();

    }

    void search(){
        fstream FILE;
        FILE.open("StudentData.txt", ios::in);
        if(!FILE){
            cout << "File not found" << endl;
            return;
        }
        string rollno, name, grade, key;
        cout << "Enter roll no to search: ";
        cin >> key;
        int flag=0;
        while(FILE >> rollno >> name >> grade){
            if(rollno==key){
                cout << "Record: "<< rollno << " " << name << " " << grade << endl;
                flag=1;
            }
        }
        if(flag==0)cout << "Record not found" << endl;
        FILE.close();
    }
    
};
int main(){
    File f1;
    int x;
    do{
        cout << "enter choice: ";
        cin >> x;
        switch(x){
            case 1:
            f1.display();
            break;
            case 2:
            f1.numberofchars();
            break;
            case 3:
            f1.write();
            break;
        }
    }while(x!=0);
    

}