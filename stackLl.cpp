//Stuck Using Linked LIst
#include <iostream>
using namespace std;

struct stack
{
    int number;
    stack* next;
};

stack *top, *cur, *tail;
int maxData = 5;

int countNumber(){
    if (top == NULL){
        return 0;
    }else{
        int data = 0;
        cur = top;
        while (cur != NULL){
            cur = cur->next;
            data++;            
        }
        return data;
    }
}

bool dataFull(){
    if (countNumber() == maxData){
        return true;
    }else{
        return false;
    }
}

bool dataEmpty(){
    if (countNumber() == NULL){
        return true;
    }else{
        return false;
    }
}

void pushStack(int num){
    if (dataFull()){
        cout<<"Data penuh !!"<<endl;       
    }else{
        if(countNumber() == 0){
            top = new stack;
            top->number = num;
            top->next = NULL;
            tail = top;
        }else{
            stack* n = new stack;
            n->number = num;
            n->next = top;
            top = n;
        }
    }
}

void popStack(){
    if(dataEmpty()){
        cout<<"Data Kosong !!"<<endl;
    }else{
        stack* del = top;
        top = top->next;
        delete del;
    }
}
void displayStack(){
    if (top == NULL){
        cout<<"Data Kosong !!"<<endl;
    }else{
        cout<<"Data : "<<endl;
        cur = top;
        while (cur != NULL){
           cout<<""<<cur->number<<endl;
           cur = cur->next;
        }
        
    }
}

int main(){
    
    pushStack(1);
    displayStack();

    pushStack(2);
    displayStack();

    pushStack(6);
    displayStack();

    pushStack(1);
    displayStack();

    pushStack(66);
    displayStack();

    popStack();
    displayStack();
 

}