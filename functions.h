#include <set>
#include <algorithm>
#include <string>
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
struct Node
{
    int x;
    Node* Next;
};
typedef Node* PNode;


void push(int data, PNode& Head, PNode& LastNode);
void show(PNode& Head);
void pop(PNode& Head, int a);
void front(PNode& Head, int a);
void size(PNode& Head, int n);
void clear(PNode& Head);
void exit();
void find(string komand, set<string> komands, int& schet);
void choice_komand(PNode& Head, PNode& LastNode, string komand, int& count);
string trim(const string& str);
#endif 