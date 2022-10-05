#include <stdio.h>
#include <stdlib.h>

#define Error(msg) {printf("Error: %s\n",msg);abort();}

typedef int ElemType;

typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

void InitQueue_L(LinkQueue &Q) {
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
}

void DestroyQueue_L(LinkQueue &Q) {
    while (Q.front) {
        Q.rear = Q.front->next;
        delete Q.front;
        Q.front = Q.rear;
    }
}

void ClearQueue_L(LinkQueue &Q) {
    QueuePtr q, p;
    // raw
    p = Q.front->next;
    while (p) {
        q = p;
        p = p->next;
        delete q;
    }
    Q.front->next = NULL;
    Q.rear = Q.front;
}

int QueueLength_L(LinkQueue Q) {
    QueuePtr p;
    int length;
    //raw
    p = Q.front;
    length = 0;
    while (p->next) {
        length++;
        p = p->next;
    }
    return length;
}

void GetHead_L(LinkQueue Q, ElemType &e) {
    if (Q.front == Q.rear) Error("Queue Empty!");
    e = Q.front->next->data;
}

void EnQueue_L(LinkQueue &Q, ElemType e) {
    QueuePtr p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

void DeQueue_L(LinkQueue &Q, ElemType &e) {
    QueuePtr p;
    //raw
    if (Q.front == Q.rear) Error("Queue Empty!");
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    delete p;
}

// application

//S3-3 C3-25
#include <iostream>

using namespace std;

void SeeDoctor() {
    //模拟患者在医院等候就诊的过程
    // prefix
    LinkQueue Q;
    int flag, n;
    char ch;
    // raw code
    InitQueue_L(Q);
    flag = 1;
    while (flag) {
        cout << "请输入命令：";
        cin >> ch;
        switch (ch) {
            case 'a':
            case 'A':
                cout << "病历号：";
                cin >> n;
                cout << endl;
                EnQueue_L(Q, n);
                break;
            case 'n':
            case 'N':
                if (Q.front->next) {
                    DeQueue_L(Q, n);
                    cout << "病历号为" << n << "的患者就诊" << endl;
                } else cout << "无患者等候就诊。" << endl;
                break;
            case 's':
            case 'S':
                cout << "下列排队的患者依次就诊：";
                while (Q.front->next) {
                    DeQueue_L(Q, n);
                    cout << n << " ";
                }
                cout << endl << "今天不再接收患者排队" << endl;
                flag = 0;
                break;
            default:
                cout << "输入命令不合法！" << endl;
        }
    }
}

// S3-4 C3-26
typedef struct {
    char *name;
    char sex;
} Person;
typedef Person ElemType;

int main() {
    SeeDoctor();
    return 0;
}























