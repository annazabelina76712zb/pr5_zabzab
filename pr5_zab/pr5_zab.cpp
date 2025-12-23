#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int value)
    {
        Node* newnode = new Node(value);
        newnode->next = head;
        if (head != nullptr)
        {
            head->prev = newnode;
        }
        if (tail == nullptr)
        {
            tail = newnode;
        }
        head = newnode;
    }

    void push_back(int value)
    {
        Node* newnode = new Node(value);
        newnode->prev = tail;
        if (tail != nullptr)
        {
            tail->next = newnode;
        }
        if (head == nullptr)
        {
            head = newnode;
        }
        tail = newnode;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            return;
        }
        Node* newnode = head->next;
        if (newnode != nullptr)
        {
            newnode->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete head;
        head = newnode;
    }
    void pop_back()
    {
        if (tail == nullptr) {
            return;
        }

        Node* prevNode = tail->prev;
        delete tail;

        if (prevNode != nullptr) {
            prevNode->next = nullptr;
            tail = prevNode;
        }
        else {
            head = nullptr;
            tail = nullptr;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "Список пуст!" << endl;
            return;
        }
        Node* node = head;
        while (node != nullptr)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    void sortList()
    {
        for (Node* node = head; node != nullptr; node = node->next)
        {
            for (Node* nextnode = node->next; nextnode != nullptr; nextnode = nextnode->next)
            {
                if (node->data > nextnode->data)
                {
                    int temp = node->data;
                    node->data = nextnode->data;
                    nextnode->data = temp;
                }
            }
        }
    }

    void remove_duplicates()
    {
        if (head == nullptr) {
            return;
        }

        Node* node = head;
        while (node != nullptr) {
            Node* sled = node->next;
            Node* ydal = node;
            while (sled != nullptr)
            {
                if (sled->data == node->data)
                {
                    Node* dubl = sled;
                    sled = sled->next;
                    ydal->next = sled;
                    if (sled != nullptr)
                        sled->prev = ydal;
                    else
                        tail = ydal;
                    delete dubl;
                }
                else
                {
                    ydal = sled;
                    sled = sled->next;
                }
            }
            node = node->next;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    DoublyLinkedList list;
    while (true)
    {
        cout << "Меню:" << endl;
        cout << "1) Добавить элемент в начало.\n2) Добавить элемент в конец.\n"
            << "3) Удалить элемент с начала.\n4) Удалить элемент с конца.\n"
            << "5) Отобразить список.\n6) Сортировать список.\n7) Удалить дубликаты.\n8) Выйти." << endl;
        cout << "Выберите пункт из списка: ";
        int a, value;
        cin >> a;
        if (a <= 0 || a > 8)
        {
            cout << "Введено неверное значение." << endl;
            continue;
        }
        switch (a)
        {
        case 1: {
            cout << "Введите элемент для добавления: ";
            cin >> value;
            list.push_front(value);
            break;
        }
        case 2: {
            cout << "Введите элемент для добавления: ";
            cin >> value;
            list.push_back(value);
            break;
        }
        case 3: {
            cout << "Удаление элемента из начала списка" << endl;
            list.pop_front();
            break;
        }
        case 4: {
            cout << "Удаление элемента из конца списка" << endl;
            list.pop_back();
            break;
        }
        case 5: {
            cout << "Список: ";
            list.display();
            break;
        }
        case 6: {
            cout << "Сортировка списка..." << endl;
            list.sortList();
            cout << "Отсортированный список: ";
            list.display();
            break;
        }
        case 7: {
            cout << "Удаление дубликатов..." << endl;
            list.remove_duplicates();
            cout << "Результат: ";
            list.display();
            break;
        }
        case 8: {
            cout << "Выход." << endl;
            return 0;
        }
        }
        cout << endl;
    }
}