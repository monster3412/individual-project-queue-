/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
using namespace std;
#include <stdio.h>
#include <iostream>
#include <set>
#include "functions.h"
#include <string>
#include <locale.h>
#include <algorithm>
int main()
{
    PNode Head = NULL;
    PNode LastNode = NULL;
    setlocale(LC_ALL, "Russian");
    int count = 0;
    string komand;

    set<string> komands = { "push","front","pop","size","clear","exit","show" };

    cout << "������������, �� ������ �� ���� ��������� 'queue is all you need !!!'" << endl << endl;

    cout << "� ����� ������������ ����� ������� ���: " << endl << "push n" << endl << "pop" << endl << "front" << endl << "size" << endl << "clear" << endl << "exit" << endl << "show" << endl;

    cout << endl;

    while (count != 1)
    {
        int schet = 0;
        cout << "������� 1 �� ������������� ������: ";

        getline(cin, komand);
        cout << endl;
        komand = trim(komand);
        if (komand.substr(0, 4) == "push")
        {
            find(komand.substr(0, 4), komands, schet); //  ������ 4 ������� 
        }

        else
        {
            find(komand, komands, schet);
        }

        if (schet == 0) {
            cout << "� ���������, ����� ������� ���. ���������� ��� ��� ��� ��������� �����!" << endl;
            continue;
        }

        choice_komand(Head, LastNode, komand, count);

    }









    return 0;
}