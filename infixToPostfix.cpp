#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//inisialisasi
char stack[100], hasil[100], infix[100];
int pos = 0, top = -1, exclude = 0;

//parse dari string ke char array
void parseToChar(string target) {
	size_t i = 1;
	infix[0] = '(';
	while (i<target.length()){
		infix[i] = target[i];
		i++;
		pos++;
	}
	infix[i + 1] = ')';
	pos = pos + 2;	
	}
	

//operator yang diprioritaskan 
int precedence(char ope) {
	if (ope == '^') {
		return 3;
	}
	if (ope == '*' || ope == '/') {
		return 2;
	}
	if (ope == '+' || ope == '-') {
		return 1;
	}
	return 0;
}


//print char array hasil
void print(char out[]) {
	int i = 0;
	while (out[i] !='\0'){
		cout<<out[i];
		i++;
	}	
}


//add data ke stack dari array infix berdasarkan indexnya
void push(int i) {
	if (top >= 49) {
		return;
	}
	else {
		top++;
		stack[top] = infix[i];
	}
}

//menghapus pada stack (awal)
char pop() {
	if (top < 0) {
		return '\0';
	}
	else {
		char deletedChar = stack[top];
		stack[top] = '\0';
		top--;
		return deletedChar;
	}
}

//konversi infix ke postfix
void convert() {
	int i = 0, j = 0;
	while (i != pos) {
		//jika char nya adalah huruf maka langsung di pindahkan ke char array hasil
		if ((infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z' || infix[i] >= '0' && infix[i] <= '9') && infix[i] != '^') {
			hasil[j] = infix[i];
			j++;
			i++;
		}
		//jika charnya kurung (bracket) maka di masukkan ke dalam stack
		else if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[') {
			push(i);
			i++;
		}
		else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']') {
			//jika charnya kurung buka (open bracket) maka semua operator dalam stack 
			//akan di pindahkan ke hasil sampai ketemu kurung tutup (close bracket)
			switch (infix[i]) {
			case ')':
				while (stack[top] != '(') {
					hasil[j] = pop();
					j++;
				}
				pop();
				exclude = exclude + 2;//exclude gunanya dikarenakan di dalam prefix kurung - kurungan 
										//(bracket) tidak ada, yang artinya variabel untuk memberikan 
										//berapa kurung yang dihapus
				i++;
				break;
			case '}':
				while (stack[top] != '{') {
					hasil[j] = pop();
					j++;
				}
				pop();
				exclude = exclude + 2;
				i++;
				break;
			case ']':
				while (stack[top] != '[') {
					hasil[j] = pop();
					j++;
				}
				pop();
				exclude = exclude + 2;
				i++;
				break;
			}
		}
		else {
			if (top == -1) {
				push(i);
				i++;
			}
			else if (precedence(infix[i]) < precedence(stack[top])) {
				hasil[j] = pop();
				j++;
				while (precedence(stack[top]) > precedence(infix[i])) {
					hasil[j] = pop();
					j++;
					if (top != -1) {
						break;
					}
				}
				push(i);
				i++;
			}
			else if (precedence(infix[i]) == precedence(stack[top])) {
				hasil[j] = pop();
				push(i);
				j++;
				i++;
			}
			else if (precedence(infix[i]) > precedence(stack[top])) {
				push(i);
				i++;
			}
		}
	}
	//pemindahan jika masih ada operator yang tersisa dalam stack
	while (stack[0] != '\0') {
		hasil[j] = pop();
	}
}

//pengoprasian matematika berbentuk postfix
int eval(char postfix[]) {
	int i = 0, local_top = 0, res = '\0', res_array[8] = { 0, 0, 0, 0, 0, 0, 0, 0};

	while (postfix[i] != '\0') {
		if (postfix[i] >= '0' && postfix[i] <= '9' && !(postfix[i] >= 'a' && postfix[i] <= 'z' || postfix[i] >= 'A' && postfix[i] <= 'Z') && !(postfix[i] == '^')) {
			res_array[local_top] = postfix[i] - '0';
			local_top++;
			i++;
		}
		else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
			int x, y;
			switch (postfix[i]) {
			case '+':
				x = res_array[local_top - 2];
				y = res_array[local_top - 1];
				res = x + y;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = res;
				local_top++;
				break;
			case '-':
				x = res_array[local_top - 2];
				y = res_array[local_top - 1];
				res = x - y;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = res;
				local_top++;
				break;
			case '*':
				x = res_array[local_top - 2];
				y = res_array[local_top - 1];
				res = x * y;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = res;
				local_top++;
				break;
			case '/':
				x = res_array[local_top - 2];
				y = res_array[local_top - 1];
				res = x / y;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = res;
				local_top++;
				break;
			case '^':
				x = res_array[local_top - 2];
				y = res_array[local_top - 1];
				res = (int)pow(x, y);
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = res;
				local_top++;
				break;
			}
			i++;
		}
	} if (res_array[1] == 0) {
		return res;
	}
	return 0;
}

int main() {
	//string bahan (inputan)
	string target = "(9+6)*2+9";

	//parse string inputan ke char
	parseToChar(target);

	//konversi infix
	convert();

	//print
	print(hasil);

	cout << "\nhasil dari postfix : " << eval(hasil);
}
