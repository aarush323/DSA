#include<iostream>
using namespace std;

class Student {
public:
    int roll_no;
    int password;
    string name;
};

class Hash {
public:
    Student* arr[10];

    Hash() {
        for (int i = 0; i < 10; i++)
            arr[i] = NULL; 
    }

    
    Student* getNode() {
        Student* t = new Student;
        cout << "roll no: ";
        cin >> t->roll_no;
        cout << "password: ";
        cin >> t->password;
        cout << "name: ";
        cin >> t->name;
        return t;
    }

    int Hash1(int roll) {
        int num = roll, sum = 0;
        do {
            int n = num % 10;
            num /= 10;
            sum += n;
        } while (num != 0);
        return sum % 10;
    }

    void insert() {
        Student* t = getNode();  
        int index = Hash1(t->roll_no);
        int count =0;

        while (arr[index] != NULL) {
            count++;
            index = (index + 1) % 10;
            if (count == 10) {
                cout << "Hash Table full" << endl;
                delete t; 
                return;
            }
        }
        arr[index] = t;
    }

    void display() {
        for (int i = 0; i < 10; i++) {
            if (arr[i] != NULL)
                cout << arr[i]->roll_no << " " << arr[i]->name << " " << arr[i]->password << endl;
        }
    }

    void search() {
        int roll_no;
        cout << "enter roll: ";
        cin >> roll_no;

        int index = Hash1(roll_no);
        int start = index;

        while (arr[index] != NULL) {
            if (arr[index]->roll_no == roll_no) {
                cout << "student record found: " << arr[index]->name << endl;
                return;
            }
            index = (index + 1) % 10;
            if (index == start) break;
        }
        cout << "record not found" << endl;
    }
};

int main() {
    Hash h1;
    int x;
    do {
        cout << "choice (1 to insert , 2 to display , 3 to search , 0 to exit): ";
        cin >> x;
        switch (x) {
            case 1:
            h1.insert(); 
            break;
            case 2: 
            h1.display(); 
            break;
            case 3:
            h1.search(); 
            break;
        }
    } while (x != 0);
}
