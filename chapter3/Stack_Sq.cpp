#include <stdio.h>
#include <stdlib.h>

#define Error(msg) {printf(#msg);abort();}

typedef int ElemType;

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 10

typedef struct {
    ElemType *elem;
    int top;
    int stacksize;
} SqStack;

void InitStack_Sq(SqStack &S) {
    S.elem = new ElemType[STACK_INIT_SIZE];
    if (!S.elem) Error(" Overflow!");
    S.top = -1;
    S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack_Sq(SqStack S) {
    delete[] S.elem;
    S.top = -1;
    S.stacksize = 0;
}

void Clear_Sq(SqStack &S) {
    S.top = -1;
}

int StackLength_Sq(SqStack S) {
    return (S.top + 1);
}

void GetTop_Sq(SqStack S, ElemType &e) {
    if (S.top == -1) Error("Stack Empty!");
    e = S.elem[S.top];
}

void Increment(SqStack &S) {
    ElemType *newstack = new ElemType[S.stacksize + STACK_INCREMENT];
    if (!newstack) Error(" Overflow!");
    for (int i = 0; i <= S.top; i++) {
        newstack[i] = S.elem[i];
    }
    delete[] S.elem;
    S.elem = newstack;
    S.stacksize += STACK_INCREMENT;
}

void Push_Sq(SqStack &S, ElemType e) {
    if (S.top == (S.stacksize - 1))
        Increment(S);
    S.elem[++S.top] = e;
}

void Pop_Sq(SqStack &S, ElemType &e) {
    if (S.top == -1) Error("Stack Empty!");
    e = S.elem[S.top--];
}

void mem(SqStack S) {
    printf("{");
    for (int i = 0; i < S.stacksize; i++) {
        printf("%d,", S.elem[i]);
    }
    printf("} Size: %d Top: %d\n", S.stacksize, S.top);
}

// application
// S3-1 C3-8
#include <iostream>

using namespace std;

void Conversion() {
//对于输入的任意非负十进制整数，打印输出与其等值的其他进制数
    // prefix
    SqStack S;
    int N, D;
    ElemType e;
    // raw code
    InitStack_Sq(S);
    cin >> N;
    cin >> D;
    while (N) {
        Push_Sq(S, N % D);
        N = N / D;
    }
    while (S.top != -1) {
        Pop_Sq(S, e);
        cout << e;
    }
}

//S3-2 C3-9
int matching() {
    // prefix
    SqStack S;
    int ch, state;
    ElemType e;
    // raw code
    InitStack_Sq(S);
    Push_Sq(S, '#');
    ch = getchar();
    state = 1;
    while ((ch != '\n') && state) {
        if (ch == '(') Push_Sq(S, ch);
        if (ch == ')') {
            GetTop_Sq(S, e);
            if (e == '#') state = 0;
            else Pop_Sq(S, e);
        }
        ch = getchar();
    }
    GetTop_Sq(S, e);
    if (e != '#') state = 0;
    if (state) return 1;
    else return 0;
}

// C3-10

void hanoi(int n, char A, char B, char C) {
    // prefix
#define move(Start, num, End) printf("from %c move %d to %c\n",Start,num,End)
    // raw code
    if (n == 1) move(A, 1, C);
    else {
        hanoi(n - 1, A, C, B);
        move(A, n, C);
        hanoi(n - 1, B, A, C);

    }
}

int main() {
    SqStack s;
    InitStack_Sq(s);

    Push_Sq(s, 1);
    Push_Sq(s, 1);
    mem(s);

    ElemType temp;
    Pop_Sq(s, temp);
    mem(s);
    GetTop_Sq(s, temp);
    printf("%d\n", temp);

    // application
    // S3-1 C3-8
    //Conversion();

    hanoi(3,'A','B','C');
    return 0;
}
