#include <iostream>
#include <string.h>
#include <string>
using namespace std;


/*а) Să se creeze clasa Bool – variabile logice.Să se definească operatorii "+" – SAU logic, "*" –
ŞI logic, "^" – SAU EXCLUSIV, ca metode ale clasei, iar operatorii "==" şi "!=" – ca funcţii
prietene.Operatorii trebuie să permită realizarea operaţiilor atît cu variabilele clasei date, cît şi
cu variabilele de tip predefinit int. (Dacă numărul întreg este diferit de zero, se consideră că
	variabila este adevăr, altfel – fals.)*/

class Bool
{
	private:
		int operandul;
	public:
		bool operator+(const Bool& oper);
		bool operator*(const Bool& oper);
		bool operator^(const Bool& oper);
		friend bool operator==(const Bool& oper1, const Bool& oper2);
		friend bool operator!=(const Bool& oper1, const Bool& oper2);
		Bool(int num);
};


Bool::Bool(int num)
{
	operandul = num;
}

bool Bool::operator+(const Bool& oper)
{
	if (this->operandul != 0 || oper.operandul != 0)
		return true;
	if (this->operandul == 0 && oper.operandul == 0)
		return false;
}

bool Bool::operator*(const Bool& oper)
{
	if (this->operandul == 0 || oper.operandul == 0)
		return false;
	if (this->operandul != 0 && oper.operandul != 0)
		return true;
}

bool Bool::operator^(const Bool& oper)
{
	if (this->operandul == oper.operandul)
		return false;
	if (this->operandul != oper.operandul)
		return true;
}

bool operator==(const Bool& oper1, const Bool& oper2)
{
	if (oper1.operandul == oper2.operandul)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const Bool& oper1, const Bool& oper2)
{
	if (oper1.operandul != oper2.operandul)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*b) Să se creeze clasa String – şir, utilizînd memoria dinamică.Să se definească operatorii "+" –
adunarea şirurilor, "=" şi "+=" – atribuirea ca metode ale clasei.Să se definească operatorii de
comparare : "==", "!=", "<", ">" ca funcţii prietene.Operatorii trebuie să lucreze atît cu String,
cît şi cu char* .Să se definească operatorul "[]" de acces la fiecare simbol în parte.Să se
supraîncarce operatorii "<<" şi ">>" pentru ieşiri / intrări de obiecte.*/


class String
{
private:
	char* sir = new char[100];
public:
	char* operator+(const String& sir_arg);
	void operator=(const String& sir_arg);
	void operator+=(const String& sir_arg);
	bool operator==(const String& sir_arg);
	bool operator!=(const String& sir_arg);
	bool operator>(const String& sir_arg);
	bool operator<(const String& sir_arg);
	char* operator[](int index);
	friend ostream& operator<<(ostream& os, String sir_arg);
	friend istream& operator>>(istream& is, String& sir_arg);
	static char* getString(const String& get);
	String(char* sir_arg);
};

String::String(char* sir_arg)
{
	this->sir = sir_arg;
}

char* String::operator+(const String& sir_arg)
{
	char* rez = new char[100];
	rez = strcat(this->sir, sir_arg.sir);
	return rez;
}

void String::operator=(const String& sirul_arg)
{
	delete[] this->sir;
	this->sir = new char[strlen(sirul_arg.sir) + 1];
	strcpy(this->sir, sirul_arg.sir);
}

void String::operator+=(const String& sirul_arg)
{
	char* rezultat = new char[100];
	rezultat = strcat(this->sir, sirul_arg.sir);
	strcpy(this->sir, rezultat);
}

bool String::operator==(const String& sirul_arg)
{
	if (strcmp(this->sir, sirul_arg.sir) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator!=(const String& sirul_arg)
{
	if (strcmp(this->sir, sirul_arg.sir) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator<(const String& sirul_arg)
{
	if (strcmp(this->sir, sirul_arg.sir) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator>(const String& sirul_arg)
{
	if (strcmp(this->sir, sirul_arg.sir) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

char* String::operator[](int index)
{
	if (index <= strlen(sir) && index >= 0)
	{
		return sir + index;
	}
	else
	{
		return NULL;
	}
}

ostream& operator<<(ostream& os, String sir_arg)
{
	os << sir_arg.sir;
	return os;
}

istream& operator>>(istream& is, String& sir_arg)
{
	cout << "Dati sirul: ";
	is >> sir_arg.sir;
	return is;
}

char* String::getString(const String& get)
{
	return get.sir;
}

int main()
{
	int num1, num2;
	cout << "Dati primul numar ";
	cin >> num1;
	cout << "Dati al doilea numar ";
	cin >> num2;
	Bool operandul1(num1), operandul2(num2);
	bool b = operandul1 + operandul2;
	cout << endl << "SAU logic: " << b << endl;
	b = operandul1 * operandul2;
	cout << "Si logic: " << b << endl;
	b = operandul1 ^ operandul2;
	cout << "SAU EXCLUSIV: " << b << endl;
	cout << "Se verifica supraincarcarea operatorului ==: ";
	if (operandul1 == operandul2)
	{
		cout << "Numerele sunt egale";
	}
	else
	{
		cout << "Numerele sunt diferite";
	}
	cout << endl;
	cout << "Se verifica supraincarcarea operatorului !=: ";
	if (operandul1 != operandul2)
	{
		cout << "Numerele sunt diferite";
	}
	else
	{
		cout << "Numerele sunt egale";
	}
	cout << endl << endl;

	char* sirul1 = new char[100];
	cout << "Dati primul sir: ";
	cin >> sirul1;
	char* sirul2 = new char[100];
	cout << "Dati al doilea sir: ";
	cin >> sirul2;
	String obj_sirul1(sirul1), obj_sirul2(sirul2);
	char* rez_adunare = new char[100];
	rez_adunare = obj_sirul1 + obj_sirul2;
	cout << "Rezultatul supraincarcarii operarorului + este: " << rez_adunare << endl << endl;
	cout << "Se verifica supraincarcarea operatorului ==: ";
	if (obj_sirul1 == obj_sirul2)
	{
		cout << "Sirurile sunt identice." << endl;
	}
	else
	{
		cout << "Sirurile nu sunt identice." << endl;
	}
	cout << endl;
	cout << "Se verifica supraincarcarea operatorului !=: ";
	if (obj_sirul1 != obj_sirul2)
	{
		cout << "Sirurile nu sunt identice." << endl;
		if (obj_sirul1 > obj_sirul2)
		{
			cout << "Primul sir este mai mare decat al doilea." << endl;
		}
		else if (obj_sirul1 < obj_sirul2)
		{
			cout << "Primul sir este mai mic decat al doilea." << endl;
		}
	}
	else
	{
		cout << "Sirurile sunt identice." << endl;
	}
	cout << endl;
	obj_sirul1 = obj_sirul2;
	cout << "Rezultatul suparaincarcarii operatorului atribuire este: " << obj_sirul1.getString(obj_sirul1) << " (sirul1)" << endl << endl;
	char* rez_assignment = new char[100];
	cout << "Dati sirul de verificarea a supraincarcarii operatorului +=: ";
	cin >> rez_assignment;
	String obj_assigment(rez_assignment);
	obj_assigment += obj_sirul2;
	cout << "Se verifica supraincarcarea operatrorului +=: " << obj_assigment.getString(obj_assigment) << endl << endl;
	int index;
	cout << "Dati indexul: ";
	cin >> index;
	if(sirul2[index] != NULL)
	cout << "Se verifica supraincarcarea operatorului []: " << sirul2[index] << endl << endl;
	char* rez_intrari_iesiri = new char[100];
	String obj_os_is(rez_intrari_iesiri);
	cin >> obj_os_is;
	cout << "Se afiseaza sirul: " << obj_os_is;
	return 0;
}