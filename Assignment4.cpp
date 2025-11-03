/*

Conversion and Evaluation of Expressions 
To implement a program that converts an infix expression to both prefix and postfix notation
and evaluates them using Standard Template Library (STL), demonstrating understanding of
expression conversion, stack operations, and expression evaluation.

Aarush Oak 23332
*/

#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

// operator comparisiond
int precedence(char op){
    if(op=='(') {
        return 0;
    }
    if(op=='^'){
         return 3;
    }
    if(op=='*' || op=='/' || op=='%'){
        return 2;
    }
    if(op=='+' || op=='-') {
        return 1;
    }
    else{
    return 0;
    }
}

// Postfix
string postfix(string infix){
    stack<char> op;
    string postfix = "";

    for(char c : infix){
        if(isalnum(c)){
            postfix += c;
        }
        else if(c=='('){
            op.push(c);
        }
        else if(c==')'){
            while(!op.empty() && op.top()!='('){
                postfix += op.top();
                op.pop();
            }
            if(!op.empty()) op.pop();
        }
        else{ 
            while(!op.empty() && ((precedence(op.top())>precedence(c)) || 
                  (precedence(op.top())==precedence(c) && c!='^')) && op.top()!='('){
                postfix += op.top();
                op.pop();
            }
            op.push(c);
        }
    }
    while(!op.empty()){
        postfix += op.top();
        op.pop();
    }
    return postfix;
}

// prefix
string prefix(string infix){
    reverse(infix.begin(), infix.end());
    for(char &c : infix){
        if(c=='(') c=')';
        else if(c==')') c='(';
    }
    string result = postfix(infix);
    reverse(result.begin(), result.end());
    return result;
}


float operation(float a,float b,char op){
    if(op == '+'){
        return a+b;
    }
    else if(op == '-'){
        return a-b;
    }
    else if(op =='*'){
        return a*b;
    }
    else if(op =='/'){
        return a/b;
    }
    else if(op == '^'){
        return pow(a,b);
    }
    else{
        return 0;
    }
    
}

float evaluate(string infix){
    string exp = postfix(infix);
    stack<float> s;
    for(char c : exp){
        if(isdigit(c)){
            s.push(c-'0');
        } else{
            float b = s.top();
            s.pop();
            float a = s.top();
            s.pop();

            s.push(operation(a,b,c));
        }
    }
    return s.top();
}

int main(){
    
        int choice;
        string infix;
       do{
        cout << "1. Infix to Postfix" << endl; 
        cout << "2.  Infix to Prefix" << endl;
        cout << "3. Evaluate Expression: " << endl;
        cout << "0. Exit" << endl;
        
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Insert infix expression: ";
                cin >> infix;
                cout << "Postfix Expression: " << postfix(infix) << endl;
                break;

            case 2:
                cout << "Insert infix expression: ";
                cin >> infix;
                cout << "Prefix Expression: " << prefix(infix) << endl;
                break;

            case 3:
                cout << "Insert numeric infix expression: ";
                cin >> infix;
                cout << "Result: " << evaluate(infix) << endl;
                break;
        }
    }while(choice != 0);
    return 0;
}

/*
Sample Output:

1. Convert Infix to Postfix
2. Convert Infix to Prefix
3. Evaluate Infix Expression
4. Exit
Enter choice: 1
Enter infix expression: (A+B)*(C-D)
Postfix Expression: AB+CD-*

Enter choice: 2
Enter infix expression: (A+B)*(C-D)
Prefix Expression: *+AB-CD

Enter choice: 3
Enter numeric infix expression: 3+4*2/(1-5)^2^3
Evaluated Value: 3.00012

Enter choice: 4

*/
