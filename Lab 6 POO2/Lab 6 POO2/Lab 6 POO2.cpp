#include <iostream>
#include <string>
using namespace std;

/*b) Sã se creeze clasa student, care are nume, specialitate, anul de studiu ºi balul mediu.
Determinaþi funcþia de definire, schimbare a datelor ºi comparare.Pentru setarea câmpurilor
textuale se foloseºte operatorul new. Definiþi constructorii, destructorul ºi alte funcþii necesare.
Creaþi clasa grupa, care conþine studenþi(un numãr nelimitat). Definiþi metodele de adãugare ºi
eliminare a studenþilor, de determinare a balului mediu pe grupã, constructorii, destructorul ºi
alte funcþii necesare.*/


class Student
{
    char* nume = new char[50];
    char* specialitatea = new char[5];
    int anul_studiu;
    double balul_mediu;
    public:
    void schimbare();
    void comparare(Student student1);
    void operator=(const Student& obj);
    Student() {};
    ~Student();
    void citire();
    char* getNume();
    char* getSpecialitatea();
    int getAnul_studii();
    double getBalul_mediu();
    void afisareStudent();
};

void Student::operator=(const Student& obj)
{
    strcpy(this->nume, obj.nume);
    strcpy(this->specialitatea, obj.specialitatea);
    this->anul_studiu = obj.anul_studiu;
    this->balul_mediu = obj.balul_mediu;
}

char* Student::getNume()
{
    return nume;
}

char* Student::getSpecialitatea()
{
    return specialitatea;
}

int Student::getAnul_studii()
{
    return anul_studiu;
}

double Student::getBalul_mediu()
{
    return balul_mediu;
}

Student::~Student()
{
    
}

void Student::citire()
{
    cout << "Dati numele studentului: ";
    cin >> nume;
    cout << "Dati specialitatea: ";
    cin >> specialitatea;
    cout << "Dati anul de studiu: ";
    cin >> anul_studiu;
    cout << "Dati balul mediu: ";
    cin >> balul_mediu;
}

void Student::afisareStudent()
{
    cout << "Numele " << nume << endl;
    cout << "Specialitatea " << specialitatea << endl;
    cout << "Anul de studiu " << anul_studiu << endl;
    cout << "Balul mediu " << balul_mediu << endl;
    cout << endl;
}

void Student::schimbare()
{
    char choice;
    do
    {
        cout << endl << "Ce doriti sa schimbati? (pentru nume - n, pentru specialitate - s, pentru anul de studiu - a, pentru balul mediu - b, pentru orice alta tasta - iesire): " << endl;
        cin >> choice;
        switch (choice)
        {
            case 'n':
                cout << "Schimbarea numelui: ";
                cin >> nume;
                break;
            case 's':
                cout << "Schimbarea specialitatii: ";
                cin >> specialitatea;
            case 'a':
                cout << "Schimbarea anului de studiu :";
                cin >> anul_studiu;
            case 'b':
                cout << "Schimbarea balului mediu: ";
                cin >> balul_mediu;
        }
    } 
    while (choice == 'n' || choice == 's' || choice == 'a' || choice == 'b');
}

void Student::comparare(Student student1)
{
    if (this->balul_mediu > student1.balul_mediu)
    {
        cout << "Balul mediu al studentului " << this->nume << " este mai mare decat al studentului " << student1.nume << " cu " << this->balul_mediu - student1.balul_mediu << ".";
    }
    else if (this->balul_mediu < student1.balul_mediu)
    {
        cout << "Balul mediu al studentului " << student1.nume << " este mai mare decat al studentului " << this->nume << " cu " << student1.balul_mediu - this->balul_mediu << ".";
    }
    else
    {
        cout << "Baluile medii ale studentilor sunt egale!" << endl;
    }
}

class Grupa
{
    int n;
    Student* student;
    public:
    Grupa(int n);
    ~Grupa()
    {

    }
    Student* adaugare();
    Student* eliminare(int indice);
    double balulGrupa();
    void afisareGrupa();
    void meniu();
};

void Grupa::afisareGrupa()
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Studentul " << i + 1 << endl;
        cout << "Numele " << student[i].getNume() << endl;
        cout << "Specialitatea " << student[i].getSpecialitatea() << endl;
        cout << "Anul de studiu " << student[i].getAnul_studii() << endl;
        cout << "Balul mediu " << student[i].getBalul_mediu() << endl;
        cout << endl;
    }
}

Grupa::Grupa(int n)
{
    this->n = n;
    this->student = new Student[n];
    for (int i = 0; i < n; i++)
    {
        student[i].citire();
    }
}

Student* Grupa::adaugare()
{
    Student* adaug = new Student[n + 1];
    for (int i = 0; i < n; i++)
    {
        adaug[i] = student[i];
    }
    adaug[n].citire();
    n = n + 1;
    return adaug;
}

Student* Grupa::eliminare(int indice)
{
    int count = 0;
    Student* elim = new Student[n - 1];
    for (int i = 0; i < n; i++)
    {
        if (i != indice)
        {
            elim[count] = student[i];
            count++;
        }
    }
    n = n - 1;
    return elim;
}

double Grupa::balulGrupa()
{
    double balulMed;
    double suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma = suma + student[i].getBalul_mediu();
    }
    balulMed = suma / n;
    return balulMed;
}

void Grupa::meniu()
{
    char choice;
    int indice;
    int indice2;
    int balulMediu;
    do
    {
        cout << endl << "Ce operatii doriti sa efectuati cu grupa? (a - adaugare, e - eliminare, b - afisarea balului mediu, s - schimbarea datelor unui student, c - comparare a doi studenti)" << endl;
        cin >> choice;
        switch (choice)
        {
            case 'a':
                student = adaugare();
                afisareGrupa();
                break;
            case 'e':
                cout << "Ce student doriti sa eliminati (dati indicele): ";
                cin >> indice;
                student = eliminare(indice);
                afisareGrupa();
                break;
            case 'b':
                balulMediu = balulGrupa();
                cout << "Balul mediu pe grupa este " << balulMediu;
                break;
            case 's':
                cout << "Dati indicele studentului al carui date doriti sa le schimbati: ";
                cin >> indice;
                student[indice].schimbare();
                cout << "Se afiseaza datele schimbate pentru studentul " << indice + 1 << endl;
                student[indice].afisareStudent();
                break;
            case 'c':
                cout << "Care studenti doriti sa ii comparati dupa balul mediu? (dati 2 indici)" << endl;
                cout << "Indice 1: ";
                cin >> indice;
                cout << "Indice 2: ";
                cin >> indice2;
                student[indice].comparare(student[indice2]);
                break;
        }
    } while (choice == 'a' || choice == 'e' || choice == 'b' || choice == 's' || choice == 'c');
}

int main()
{
    int num;
    cout << "Dati numarul de studenti din grupa: ";
    cin >> num;
    Grupa TI_192(num);
    TI_192.meniu();
}
