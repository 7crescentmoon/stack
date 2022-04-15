//Stuck Using Array
#include <iostream>
using namespace std;

int Max = 7;
int data [7];
int top;

bool stackFull(){
    if(top >= Max){
       return true; 
    }else{
        return false;
    }
}
bool stackEmpty(){
    if(top == 0){
       return true; 
    }else{
        return false;
    }
}

void pushStack(int number){
    if (stackFull()){
       cout<< "Data Sudah Penuh !!"<<endl; 
    }else{
        data[top] = number;
        top++;
    }
}
void popStack(){
    if(stackEmpty()){
        cout<< "Data Kosong !!"<<endl;
    }else{
        data[top -1] = 0 ;   
    }
}

void displayStack(){
    cout<< "data : "<<endl;
    for (int i = Max -1; i >= 0; i-- ){
        if(data[i] != 0){
           cout<< "" << data[i] <<endl;     
        }
    }    
    cout<<"\n"; 
}
    

int main (){
    pushStack(1);
    displayStack();

    pushStack(3);
    displayStack();

    pushStack(5);
    displayStack();

    popStack();
    displayStack();
    
}



