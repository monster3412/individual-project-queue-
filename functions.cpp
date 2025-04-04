using namespace std;
#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
#include "functions.h"
#include <algorithm>
void push(int data, PNode& Head, PNode& LastNode)
{
    PNode Temp;
    if (Head == NULL)
    {
        Head = new Node;
        LastNode = Head;
        Head->Next = NULL;

    }
    else
    {
        Temp = new Node;
        LastNode->Next = Temp;
        LastNode = Temp;
        LastNode->Next = NULL;
    }
    LastNode->x = data;
    cout << "���! �� �������� �����: " << data << ". ��� ������ � �������, ��� Wi-Fi �� ���� � ������ � ��������!" << endl << endl;
}
string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return ""; // ������ ������� ������ �� ��������
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void show(PNode& Head)
{
    PNode Temp = Head;
    if (Temp == NULL)
    {
        cout << "������� �����, ��� ����������� �����, ����� ����� ��� ������ ����������!" << endl;
    }
    while (Temp != NULL)
    {
        cout << "�����: " << Temp->x << " - ��� �� ������ �����, ��� ������ ����� �������!" << endl;
        Temp = Temp->Next;
    }
}


void pop(PNode& Head, int a)
{

    if (Head != NULL)
    {
        a = Head->x;

        Head = Head->Next;

        cout << endl;

        cout << "������� ������� �� �������... ������, " << a << "! �� ��� ������� ������!" << endl;
    }
    else
    {
        cout << endl;
        cout << "������! ������� �����, ��� ��� ������� ����� ������� ������ � ����� ��������!" << endl;
    }
}


void front(PNode& Head, int a)
{
    if (Head != NULL)
    {
        a = Head->x;
        cout << "�� �������� ����� ����� ������� - ��� �������������� �����: " << a << endl << endl;
    }
    else
    {
        cout << endl;
        cout << "������! ������� �����, ��� ������ ����� ��-��� �������!" << endl << endl;
    }
}


void size(PNode& Head, int n)
{

    if (Head != NULL)
    {
        n = 0;
        PNode Temp = Head;
        while (Temp != NULL)
        {
            n += 1;
            Temp = Temp->Next;
        }
        cout << "������ �������: " << n << ". ��� �� ��� �� � �����, �� � �� ���� - ��������� ������ ��� ���������!" << endl << endl;
    }
    else
    {
        cout << "0. ������� �����, ��� � ��� �������� �� �����!" << endl << endl;
    }

}


void clear(PNode& Head)
{
    while (Head != NULL)
    {
        Head = Head->Next;
    }
    cout << "������� �������! ������ ��� ��� ������ ���� ������ - ������ � ����� ������������!" << endl << endl;
}


void exit()
{

    cout << "�� ��������! �������� ������� ��� ����� - �� ��������� ��� ���, ��� ��� ������� �����!!!" << endl << endl;
}

void find(string komand, set<string> komands, int& schet)
{


    for (const auto& nezn_kak_nazvat : komands)
    {
        if (komand == nezn_kak_nazvat)
        {
            schet += 1;
        }
    }



}



void choice_komand(PNode& Head, PNode& LastNode, string komand, int& count)
{
    int n=0;
    if (komand.substr(0, 5) == "push ")
    { // ��������� �� ������� push
        string s = komand.substr(5); // ��������� ����� ������ ����� 'push '

        try
        {
            int n = stoi(s);
            push(n, Head, LastNode);
        }
        catch (invalid_argument&)
        { // ��������� ������ ��������������
            cout << "������: ������������ �����. ��� �� ����� - ������ ����� ������ ���� ������!" << endl << endl;
        }
        catch (out_of_range&)
        { // ��������� ������ ������������
            cout << "������: ����� ��� ���������. �� ���, ������ ������� � ��� ��������������������� �������?" << endl << endl;
        }

    }
    else if (komand == "pop")
    {
        pop(Head, n);
    }
    else if (komand == "front")
    {
        front(Head, n);
    }

    else if (komand == "size")
    {
        size(Head, n);
    }


    else if (komand == "clear")
    {

        clear(Head);
    }
    else if (komand == "show")
    {

        show(Head);
    }

    else if (komand == "exit")
    {
        exit();
        count = 1;
    }
}