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
    cout << "Ура! Мы добавили число: " << data << ". Оно теперь в очереди, как Wi-Fi на даче — всегда в ожидании!" << endl << endl;
}
string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return ""; // строка состоит только из пробелов
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void show(PNode& Head)
{
    PNode Temp = Head;
    if (Temp == NULL)
    {
        cout << "Очередь пуста, как холодильник ночью, когда самый жор только начинается!" << endl;
    }
    while (Temp != NULL)
    {
        cout << "Число: " << Temp->x << " - это не просто число, это звезда нашей очереди!" << endl;
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

        cout << "Удаляем элемент из очереди... Прощай, " << a << "! Ты был хорошим числом!" << endl;
    }
    else
    {
        cout << endl;
        cout << "Ошибка! Очередь пуста, как мой кошелек после покупки гречки в эпоху инфляции!" << endl;
    }
}


void front(PNode& Head, int a)
{
    if (Head != NULL)
    {
        a = Head->x;
        cout << "На переднем плане нашей очереди - это величественное число: " << a << endl << endl;
    }
    else
    {
        cout << endl;
        cout << "Ошибка! Очередь пуста, как пустая банка из-под варенья!" << endl << endl;
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
        cout << "Размер очереди: " << n << ". Это не так уж и много, но и не мало - идеальный размер для вечеринки!" << endl << endl;
    }
    else
    {
        cout << "0. Очередь пуста, как я без сладкого на диете!" << endl << endl;
    }

}


void clear(PNode& Head)
{
    while (Head != NULL)
    {
        Head = Head->Next;
    }
    cout << "Очередь очищена! Теперь она как чистый лист бумаги - готова к новым приключениям!" << endl << endl;
}


void exit()
{

    cout << "До свидания! Надеемся увидеть вас снова - не забывайте про нас, как про любимую пиццу!!!" << endl << endl;
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
    { // Проверяем на команду push
        string s = komand.substr(5); // Извлекаем часть строки после 'push '

        try
        {
            int n = stoi(s);
            push(n, Head, LastNode);
        }
        catch (invalid_argument&)
        { // Обработка ошибки преобразования
            cout << "Ошибка: некорректное число. Это не магия - просто число должно быть числом!" << endl << endl;
        }
        catch (out_of_range&)
        { // Обработка ошибки переполнения
            cout << "Ошибка: число вне диапазона. Вы что, хотите вызвать у нас гиперпространственный коллапс?" << endl << endl;
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