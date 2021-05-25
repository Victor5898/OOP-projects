#include <iostream>
#include <math.h>

using namespace std;
class Ecuatie
{ 
    int a, b, c;

    public:
    Ecuatie();
    void citire();
    void afisare();
    int discriminant();
    void solutie();
    ~Ecuatie();
};

Ecuatie::Ecuatie()
{
    a = 0;
    b = 0;
    c = 0;
}


void Ecuatie:: citire()
{
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
}

void Ecuatie:: afisare()
{
    cout << a << "*x^2 + " << b << "*x + " << c << " = 0" << endl;
}

int Ecuatie:: discriminant()
{
    int delta;
    delta = pow(b, 2) - 4 * a * c;
    return delta;
}

void Ecuatie:: solutie()
{
    int delta = discriminant();
    int x1, x2;

    if (delta > 0)
    {
        x1 = (-b - sqrt(delta)) / 2 * a;
        x2 = (-b + sqrt(delta)) / 2 * a;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        return;
    }
    if (delta == 0)
    {
        x1 = -b / 2 * a;
        cout << "x1 = " << x1;
    }
    if (delta < 0)
    {
        cout << "Solutie nu se pot determina in multimea numerelor reale" << endl;
    }
}
Ecuatie::~Ecuatie()
{

}

int main()
{
    int discriminant;
    Ecuatie ecuatia1, ecuatia2;

    cout << "Citirea datelor pentru ecuatia 1" << endl;
    ecuatia1.citire();
    cout << "Citirea datelor pentru ecuatia 2" << endl;
    ecuatia2.citire();

    cout << endl <<"Se afiseaza ecuatia 1: ";
    ecuatia1.afisare();
    cout << "Se afiseaza ecuatia 2: ";
    ecuatia2.afisare();

    cout << endl << "Se afiseaza discriminantul pentru ecuatia 1: " << ecuatia1.discriminant() << endl;
    cout << "Se afiseaza discriminantul pentru ecuatia 2: " << ecuatia2.discriminant() << endl << endl;

    cout << "Solutile ecuatiei 1:" << endl;
    ecuatia1.solutie();
    cout << endl;
    cout << "Solutile ecuatiei 2:" << endl;
    ecuatia2.solutie();
}