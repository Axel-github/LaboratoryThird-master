
#include <iostream>
#include <vector>
#include <ctime>
#include "windows.h"
#include <forward_list>
#include <string>

using namespace std;

void custom_clear();



void rand_init_list(forward_list<int>& lst, int count);
void user_init_list(forward_list<int>& lst, int count);

void print_list(forward_list<int>& lst);

void find_elem(forward_list<int> lst);

void find_more_than_average(forward_list<int> lst);

forward_list<int> new_lst(forward_list<int> lst);

template<typename type >type getValue(string s);

int main()
{
    srand(time(0));//Задание зерна ПСГЧ
    setlocale(LC_ALL, "");//Кириллица в консоле
   
    forward_list<int> lst;
    int list_size = 0;

    while(list_size <= 0) list_size = getValue<int>("Введите размер списка");
    rand_init_list(lst, list_size);
    //user_init_list(lst, list_size);

    print_list(lst);
    find_elem(lst);
    forward_list<int> lst_helper;
    lst_helper = new_lst(lst);
    print_list(lst_helper);
    system("pause");
}

//Шаблон безопасного считывания данных со стандартного потока istream и вывод
template<typename type > type getValue(string s)
{
    while (true) // Цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        cout << s << ": ";
        type a;
        cin >> a;
        if (cin.fail()) // Если предыдущее извлечение оказалось неудачным,
        {
            system("cls");
            cin.clear(); // То возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // Удаляем значения предыдущего ввода из входного буфера
        }
        else // Eсли всё хорошо, то возвращаем a
            return a;
    }
}



//Инициазиация массива случайными значениями с зерном time(0)
void rand_init_list(forward_list<int>& lst, int count)
{
    


    for (size_t i = 0; i < count; i++)
    {
        lst.push_front(rand() % 101-50);
    }
        
    lst.sort();
}

void user_init_list(forward_list<int>& lst, int count)
{

    for (size_t i = 0; i < count; i++)
    {
        lst.push_front(getValue<int>("Введите " + std::to_string(i) + " элемент"));
    }

    lst.sort();
}

void print_list(forward_list<int>& lst)
{
    auto elem = lst.begin();
    while (elem != lst.end())
    {
        cout << *elem++ << " ";
    }
    cout << endl;
}

void find_elem(forward_list<int> lst)
{
    bool isFind = false;
    int iter = 0;
    auto elem = lst.begin();
    while (elem != lst.end())
    {
        if (*elem == 18) 
        {
            isFind = true;
            break;
        }
        *elem++;
        iter++;
    }
    if (isFind) cout << "Элемент cо значением 18 найден под индексом " << iter << "!" << endl;
    else cout << "Элемент cо значением 18 не был найден" << endl;
}



forward_list<int> new_lst(forward_list<int> lst)
{
    int i = 1;

    forward_list<int> listik;
    for (int it : lst)
    {
        if (i % 3 == 0) listik.push_front(it);
        i ++;
    }
    listik.sort();
    return listik;
}


//Безопасное считывание из потока istream
int getValue()
{
    while (true) // Цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        int a;
        cin >> a;
        if (cin.fail()) // Если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // То возвращаем cin в 'обычный' режим работы
            cin.ignore(32767, '\n'); // Удаляем значения предыдущего ввода из входного буфера
        }
        else // Eсли всё хорошо, то возвращаем a
            return a;
    }
}

