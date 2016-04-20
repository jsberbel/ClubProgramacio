#include <vector>
#include <iostream>
using std::cout; using std::endl;

// Print the sum of "a" and "b"
void funcA(int &a, int **b) {
	
}

// Swap the values of "a" and "b" and print them out
void funcB(int *a, int *&b) {
	
}

// Print the product of each element inside the vector
void funcC(std::vector<int*> &data) {
	
}

// Print the result of substracting "a" from "b" inside data
struct T { int a; int b; };
void funcD(T **data) {
	
}

// Change the first element of data from '.' to '#', and print all the content out
void funcE(char *data[]) {
	
}

// Set all properties of "nums" to 0, and print out the content of "a" inside "nums" and the content of data as an string
struct K { int a; int b; int c; };
void funcF(void *data, K *&nums) {
	
}

#include <conio.h>

int main() {
	int x = 2, *xPtr = &x,
		y = 6, *yPtr = &y,
		z = -1, *zPtr = &z;
	T t = { 8, 3 }, *tPtr = &t;
	K k = { 1, 2, 3 }, *kPtr = &k;
	char str[11] = ".memorable", *strPtr = str;

	cout << "Function A:\n";	funcA(x, &yPtr);
	cout << "\nFunction B:\n";	funcB(xPtr, yPtr);
	cout << "\nFunction C:\n";	funcC(std::vector<int*>{ xPtr, yPtr, zPtr });
	cout << "\nFunction D:\n";	funcD(&tPtr);
	cout << "\nFunction E:\n";	funcE(&strPtr);
	cout << "\nFunction F:\n";	funcF(strPtr, kPtr);

	_getch();
	return 0;
}