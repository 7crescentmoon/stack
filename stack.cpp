//Stuck Using Array
#include <iostream>
using namespace std;

//inisialisasi 
int Max = 7;
int data [7];
int dataTemp[7];
int top;
int tempTop;

//pengecekkan jika isi satck full
bool stackFull(){
    if(top == Max){
       return true; 
    }else{
        return false;
    }
}

//pengecekkan jika isi stack kosong
bool stackEmpty(){
    if(top == 0){
       return true; 
    }else{
        return false;
    }
}

//pengecekkan jika isi stcak temporary kosong
bool tempStackEmpty(){
   if(tempTop == 0){
       return true;
   } else{
       return false;
   }
}

//menghapus dan mengembalikkan data pada stack yang paling atas(top)
int popStack(){
    if(stackEmpty()){
        cout<< "Data Kosong !!"<<endl;
    }else{
        int del = data[top];
        top--;
        return del;   
    }
}

//menghapus dan mengembalikkan data pada stack temporary yang paling atas(top)
int popTemp(){
    if(tempStackEmpty()){
        cout<<"Data Kosong !!"<<endl;
    }
    else{
        int del = dataTemp[tempTop];
        tempTop--;
        return del;
    }
}

//menambahkan data stack dangan cara beruruatan 
void pushStack(int number){
    //pengecekan jika data stack full
    if (stackFull()){
        cout<<"Data Stack Full!!"<<endl;
    }
    //pengecekakn jika data stack kosong, data langsung dimasukkan
    if (stackEmpty()){
        top++;
        data[top] = number;
    //jika data yang dimasukkan lebih besar dari ddata yg seblumnya telah dimasukkn
    //maka data yng baru dimasuukn kan msuk kedalam stack/array stack
    }else{
        if (number > data[top]){
            top++;
            data[top] = number;
        }
        //jika data yang dimasuukan lebih kecil dari pada data yg ada didalam stack seblumnya
        //maka data akan dihpus,dan dimasukkan ke dalam data temporary(dataTemp) 
        else{
            while (!stackEmpty() && data[top] > number){
                tempTop++;
                dataTemp[tempTop] = popStack();
            }
            //setelah data yg lebih besar masuk ke dalam data temporary (dataTemp)
            //maka data yang lebih kecil akan masuk ke dalam stack
            top++;
            data[top] = number;
            //setalah itu, data yang lebih kecil sudah msuk kedalam data stack
            //maka data yang ada didalam data temporary(dataTemp) akan dikembalikan ke dalam data stack
            while (!tempStackEmpty()){
                top++;
                data[top] = popTemp();

            }    
        }
    }
}
//menampilkan data stack
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
    pushStack(4);
    displayStack();

    pushStack(3);
    displayStack();

    pushStack(5);
    displayStack();

    pushStack(7);
    displayStack();   

    pushStack(88);
    displayStack(); 

    pushStack(555);
    displayStack(); 

    pushStack(990);
    displayStack();     
}