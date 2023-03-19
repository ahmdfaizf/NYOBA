#ifndef COMPXML_H_INCLUDE
#define COMPXML_H_INCLUDE

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

#define Head(Q) ((Q).Head)
#define Tail(Q) ((Q).Tail)
#define next(P) ((P)->next)
#define info(P) ((P)->info)
#define name(A) (A).name
#define root(A) (A).root
#define info(A) (A)->info
#define next(A) (A)->next
#define top(A) (A).top
#define tagStack(A) (A).tagStack
#define first(A) (A).first
#define last(A) (A).last

struct StackTag{
    char infoTag[10000];
    int top;
};

typedef struct ElmQueueStatus *adr;

struct isiQueue{
    string TAG;
    bool Format;
    bool status;
    int cek;
};
typedef isiQueue infoQueue;

struct ElmQueueStatus{
    infoQueue info;
    adr next;
};

struct QueueStatus{
    adr Head;
    adr Tail;
};

void createStack(StackTag &S);
bool IsEmpty(StackTag S);
bool IsFull(StackTag S);
void PushStack(StackTag &S, char NewInfo);
void PopStack(StackTag &S, char &x);
void PrintStack(StackTag S);
void createQueue(QueueStatus &Q);
adr NewQueue(string TAG);
void EnQueue(QueueStatus &Q, adr p);
void DeQueue(QueueStatus &Q, adr &p);
void PrintQueue(QueueStatus Q);
string PisahTAG(string isiFile);
void EnqueuTAG(QueueStatus &Q, string isiFile);
bool CekFormatTag(QueueStatus Q);
bool cekPasaangan(QueueStatus Q);
//
typedef struct elmQueue *adrs;

struct elm {
    string name;
    int root;
};

struct elmQueue {
    elm info;
    adrs next;
};

struct Stack {
    elm tagStack[10000];
    int top;
};

struct Queue {
    adrs first, last;
};

void createStack (Stack &S);
void createQueue (Queue &Q);
void push(Stack &S, elm p);
void pop(Stack &S, elm &p);
void enqueue(Queue &Q, elm elmnt);
void dequeue(Queue &Q, elm &elmnt);
elm topStack(Stack S);
bool emptyQueue(Queue Q);
bool thereIsOneElement(Queue Q);
bool emptyStack(Stack S);
bool fullStack(Stack S);
void olahString(string line, Queue &tags, bool &elementHasName, int &rootOrder, int &countFirstRoot);
void pairing(bool &isValid, Queue &tags, Stack &tagStacks, int countFirstRoot, bool elementHasName);

#endif
