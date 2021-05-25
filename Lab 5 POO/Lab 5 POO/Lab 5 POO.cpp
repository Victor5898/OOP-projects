#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

class Container
{
    public:
    virtual void push(int value)
    {

    }
    virtual void pop()
    {

    }
    virtual void afisare()
    {

    }
};

class Stack : public Container
{
    int value;
    Stack* next;

    Stack* head = NULL;
    public:
    void push(int value);
    void pop();
    void afisare();
};

void Stack::push(int value) //functia de inserare a nodului la inceput
{
    Stack* NewNode;
    NewNode = new Stack();
    NewNode->value = value;
    NewNode->next = NULL;
    if (head == NULL)
    {
        head = NewNode;
    }
    else
    {
        NewNode->next = head;
        head = NewNode;
    }
}

void Stack::pop()
{
    Stack* temp;
    if (head == NULL)
    {
        cout << "Este imposibila operatia de exetragere. Stiva este vida!" << endl;
        return;
    }
    else 
    {
        temp = head;
        head = temp->next;
        delete temp;
        cout << "S-a eliminat o valoare!" << endl;
    }
}

void Stack::afisare()
{
    Stack* current = head;
    cout << "Se afiseaza valorile stivei" << endl;
    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl << flush;
}

class Queue : public Container
{
    int value;
    Queue* next;
    Queue* head;
    public:
    void push(int value);
    void pop();
    void afisare();
};

void Queue::push(int value)
{
    Queue* NewNode;
    Queue* currentNode = head;
    NewNode = new Queue();
    NewNode->value = value;
    NewNode->next = NULL;
    if (head == NULL)
    {
        head = NewNode;
    }
    else
    {
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = NewNode;
    }
}

void Queue::pop()
{
    Queue* temp;
    if (head == NULL)
    {
        cout << "Este imposibila operatia de exetragere. Coada este vida!" << endl;
        return;
    }
    else
    {
        temp = head;
        head = temp->next;
        delete temp;
        cout << "S-a eliminat o valoare!" << endl;
    }
}

void Queue::afisare()
{
    Queue* current = head;
    cout << "Se afiseaza valorile cozii" << endl;
    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl << flush;
}

void alegerea_operatiei(Container** containere, string nume_container)
{
    char operatia;
    int valoarea;
    do
    {
        cout << "Alegeti operatia asupra stivei: " << endl;
        cout << "Pentru inserare alegeti -'i', pentru extragere - 'e', pentru afisare - 'a', pentru iesire - orice alta tasta: " << endl;
        cin >> operatia;
        if (operatia == 'i' || operatia == 'I')
        {
            cout << "Dati valoarea care trebuie de inserat: " << endl;
            cin >> valoarea;
            containere[0]->push(valoarea);
            cout << "Valoarea s-a inserat cu succes!" << endl;
            system("pause");
        }
        if (operatia == 'e' || operatia == 'E')
        {
            containere[0]->pop();

            system("pause");
        }
        if (operatia == 'a' || operatia == 'A')
        {
            containere[0]->afisare();
            system("pause");
        }
        system("CLS");
    } 
    while (operatia == 'i' || operatia == 'I' || operatia == 'e' || operatia == 'E' || operatia == 'a' || operatia == 'A');
}

void meniu(Container** containere)
{
    char alegerea;
    do
    {
        cout << "Alegeti containerul cu care veti lucra:" << endl;
        cout << "Pentru stiva alegeti -'S', pentru coada - 'c', pentru iesire - orice alta tasta: " << endl;
        cin >> alegerea;
        system("CLS");
        if (alegerea == 'S' || alegerea == 's')
        {
            alegerea_operatiei(&containere[0], "stivei");
            system("CLS");
        }
        if (alegerea == 'c' || alegerea == 'C')
        {
            alegerea_operatiei(&containere[1], "cozii");
            system("CLS");
        }
    } while (alegerea == 'S' || alegerea == 's' || alegerea == 'C' || alegerea == 'c');
}

int main()
{
    Container* containere[2];
    containere[0] = new Stack();
    containere[1] = new Queue();
    meniu(containere);
}
