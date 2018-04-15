#include <stdio.h>  
#include <tchar.h>  
#include <cstdlib>  
#include <iostream>  
using namespace std;
#define TRUE 1  
#define OK 1  
typedef struct {
	int *base;
	int *top;
	int stacksize;
}SqStack;
int InitStack(SqStack &S) {
	S.base = (int *)malloc(100 * sizeof(int));
	if (!S.base) exit(-2);
	S.top = S.base;
	S.stacksize = 100;
	return OK;
}

int StackEmpty(SqStack S) {
	if (S.top == S.base)
		return OK;
}

int Push(SqStack &S, int e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (int *)realloc(S.base, (S.stacksize + 10) * sizeof(int));
		if (!S.base) exit(-2);
		S.top = S.base + S.stacksize;
		S.stacksize += 10;
	}
	*S.top++ = e;
	// *S.top = e;  
	// S.top++;  
	return OK;
}
int Pop(SqStack &S, int &e) {
	if (S.top == S.base) return 0;
	e = *--S.top;
	return OK;
}

void conversion() {
	int j, e;
	SqStack S;
	InitStack(S);
	scanf_s("%d", &j);
	while (j) {
		Push(S, j % 8);
		j = j / 8;
	}
	while (StackEmpty(S) != OK) {
		Pop(S, e);
		printf("%d", e);
	}
}
int main(int argc, char* argv[])
{
	int i;
	int e;
	SqStack S;
	InitStack(S);
	for (i = 1; i < 51; i++) {
		Push(S, i * 2);
	}
	cout << "Decimal representation:" << endl;
	for (i = 0; i < 50; i++) {
		Pop(S, e);
		cout << e << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl;
	cout << "Octal representation:" << endl;
	conversion();
	getchar();
	return 0;
}