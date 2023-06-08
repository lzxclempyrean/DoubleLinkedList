#include <iostream>
using namespace std;


char* input(FILE* stream) // Ввод значения в консоль
{
    char* string;
    string = (char*)malloc(sizeof(char));
    char c;
    int length = 0;
    while ((c = getc(stream)) != '\n')
    {
        string[length] = c;
        string = (char*)realloc(string, sizeof(char) * (++length + 1));
    }
    string[length] = '\0';
    return string;
}

int getInt() { // Ввод int
    int n;
    int c = 0;
    char* buff;
    buff = input(stdin);
    n = atoi(buff);
    for (int i = 0; i < strlen(buff); i++) {
        if (buff[i] >= '0' and buff[i] <= '9') c++;
    }
    if (c != strlen(buff)) {
        cout << "Input integer" << endl;
        cout << " Here ---> ";
        n = getInt();
    }
    else return n;
}

class Elem { // Класс элемента
public:
    int data; // Значение
    Elem* next; // Указатель на следующий элемент
    Elem* prev; // Указатель на предыдущий элемент
    Elem(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};


class doubleLinkedList { // Класс списка
public:
    Elem* head; // "Голова" списка
    doubleLinkedList() {
        head = NULL;
    }

    void addBackElem() { // Функция добавления элементов в конец
        int amount;
        cout << "Enter the amount of elements" << endl;
        amount = getInt(); // Ввод кол-ва элементов
        for (int i = 0; i < amount; i++)
        {
            int value;
            cout << "Input integer value" << endl;
            value = getInt();
            Elem* newElem = new Elem(value);
            if (head == NULL)
            {
                head = newElem;
            }
            else {
                Elem* current = head;
                while (current->next != NULL)
                {
                    current = current->next; // Перебор указателей до пустого
                }
                current->next = newElem; // Добавление элемента
                newElem->prev = current;
            }
        }
    }

    void addFrontElem() { // Функция добавления элемента в начало
        int data;
        cout << "Enter integer value" << endl;
        data = getInt();
        Elem* newElem = new Elem(data);
        if (head == NULL) {
            head = newElem;
        }
        else {
            newElem->next = head;
            head->prev = newElem;
            head = newElem;
        }

    }

    void display() { // Функция вывода
        if (head == NULL) { // Проверка на наличие элементов в списке
            cout << "List is empty" << endl;
        }
        else {
            cout << "List:" << endl;
            Elem* current = head; // Установление указателя в начало
            while (current != NULL) {
                cout << current->data << " "; // Проход по списку указателей и вывод значений
                current = current->next;
            }
            cout << endl;
        }
    }

};

int main()
{
    doubleLinkedList list;
    int command = 0;
    while (command != 4)
    {
        cout << "_____Double_Linked_List_____" << endl;
        cout << "Add elements to the back...1" << endl;
        cout << "Add element to the front...2" << endl;
        cout << "Display list...............3" << endl;
        cout << "Exit.......................4" << endl;

        command = getInt();
        switch (command)
        {
        case 1:
        {
            list.addBackElem();
        }
        break;

        case 2:
        {
            list.addFrontElem();
        }
        break;

        case 3:
        {
            list.display();
        }
        break;

        case 4:
            break;
        default:
            break;
        }
    }
    system("pause");
    return 0;

    
}
