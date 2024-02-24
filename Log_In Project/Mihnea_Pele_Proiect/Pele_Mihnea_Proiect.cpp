#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include<time.h>


using namespace std;


//Creare clasa User
class User {
private:
	string userName;
	string password;
	string answer1;
	string answer2;
	string answer3;


public:
	User(string name, string pass, string a1, string a2, string a3) {
		this->userName = name;
		this->password = pass;
		this->answer1 = a1;
		this->answer2 = a2;
		this->answer3 = a3;

	}
	//Encapsulare Username
	string getUserName() {
		return this->userName;
	}
	//Encapsulare Parola
	string getPassword() {
		return this->password;
	}
	//Encapsulare raspunsul 1
	string getAnswer1() {
		return this->answer1;
	}
	//Encapsulare raspunsul 2
	string getAnswer2() {
		return this->answer2;
	}
	//Encapsulare raspunsul 3
	string getAnswer3() {
		return this->answer3;
	}
	//Setare Username
	void setUserName(string name) {
		this->userName = name;
	}
	//Setare Parola
	void setPassword(string pass) {
		this->password = pass;
	}
	//Setare raspunsul 1
	void setAnswer1(string a1) {
		this->answer1 = a1;
	}
	//Setare raspunsul 2
	void setAnswer2(string a2) {
		this->answer1 = a2;
	}
	//Setare raspunsul 3
	void setAnswer3(string a3) {
		this->answer1 = a3;
	}

	void afisare() {
		ofstream fout("date.txt", ios::app);

		fout << this->userName << endl;
		fout << this->password << endl;
		fout << "Numele cainelui tau ?" << endl;
		fout << this->answer1 << endl;
		fout << "Mancarea preferata ? " << endl;
		fout << this->answer2 << endl;
		fout << "Sportul preferat ? " << endl;
		fout << this->answer3 << endl;
		fout << " ==================" << endl;
		fout.close();

	}
};


//Verificare daca exista username-ul
bool checkUsername(string name) {
	ifstream fin("date.txt");
	string linie;
	while (getline(fin, linie))
	{
		if (linie == name)
		{
			fin.close();
			return true;
		}
	}
	fin.close();
	return false;
}


//Functia de inregistrare a unui nou user
void inregistrare()
{
	string name, pass, a1, a2, a3;

	cout << "Introduceti username-ul: ";
	do {
		cin >> name;
		if (checkUsername(name))
		{
			cout << "Username-ul exista deja.\nIntroduceti alt username: ";
		}
	} while (checkUsername(name));
	cout << "Introduceti parola: ";
	cin >> pass;
	cout << "Intrebarea 1:\nNumele cainelui tau?: " << endl << "Raspuns: ";
	cin >> a1;
	cout << "Intrebarea 2:\nMancarea preferata?" << endl << "Raspuns: ";
	cin >> a2;
	cout << "Intrebarea 3:\nSportul preferat?" << endl << "Raspuns: ";
	cin >> a3;

	cout << "Bine ai venit, " << name << "!" << endl;

	system("pause");
	User user(name, pass, a1, a2, a3);
	user.afisare();

}


//Functia de autentificare a userului
void autentificare()
{

	string name, pass;
	cout << "Introduceti username-ul: ";
	cin >> name;
	cout << "Introduceti parola: ";
	cin >> pass;

	ifstream fin("date.txt");
	string linie;
	while (getline(fin, linie))
	{
		if (linie == name)
		{
			getline(fin, linie);
			if (linie == pass)
			{
				cout << "Bine ai revenit, " << name << " !" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "Username sau parola incorecta!" << endl;
				system("pause");
				break;
			}
		}
	}

	fin.close();
}

//Functia de resetare a parolei
void resetareParola()
{
	string name, pass, a1, a2, a3;
	string date;
	ifstream fin("date.txt");


	cout << "Introduceti username-ul: ";
	cin >> name;
	cout << "Intrebarea 1:\nNumele cainelui tau ?: " << endl << "Raspuns: ";
	cin >> a1;
	cout << "Intrebarea 2:\nMancarea preferata?" << endl << "Raspuns: ";
	cin >> a2;
	cout << "Intrebarea 3:\nSportul preferat?" << endl << "Raspuns: ";
	cin >> a3;
	cout << "Introduceti noua parola: ";
	cin >> pass;


	while (getline(fin, date))
	{
		if (date == name)
		{
			getline(fin, date);
			getline(fin, date);
			getline(fin, date);
			if (date == a1)
			{
				getline(fin, date);
				getline(fin, date);
				if (date == a2)
				{
					getline(fin, date);
					getline(fin, date);
					if (date == a3)
					{
						User user(name, pass, a1, a2, a3);
						user.setPassword(pass);
						user.afisare();
						cout << "Parola a fost resetata cu succes!" << endl;
						system("pause");
						break;
					}
					else
					{
						cout << "Raspunsuri incorecte!" << endl;
						system("pause");
						break;
					}
				}
				else
				{
					cout << "Raspunsuri incorecte!" << endl;
					system("pause");
					break;
				}
			}
		}
	}

	fin.close();
}

//Salvare evidenta evenimentelor in log.log cu time-stamp
void evidenta_inregistrare()
{
	ofstream fout("log.log", ios::app);

	time_t t = time(0);
	struct tm* now = localtime(&t);
	fout << "Cont creat la data de:" << now->tm_mday << '-' << (now->tm_mon + 1) << '-' << (now->tm_year + 1900) << ' ' << now->tm_hour << ':' << now->tm_min << ':' << now->tm_sec << endl;
	fout.close();
}

void evidenta_autentificare()
{
	ofstream fout("log.log", ios::app);

	time_t t = time(0);
	struct tm* now = localtime(&t);
	fout << "Cont accesat la data de:" << now->tm_mday << '-' << (now->tm_mon + 1) << '-' << (now->tm_year + 1900) << ' ' << now->tm_hour << ':' << now->tm_min << ':' << now->tm_sec << endl;
	fout.close();
}

void evidenta_resetareParola()
{
	ofstream fout("log.log", ios::app);

	time_t t = time(0);
	struct tm* now = localtime(&t);
	fout << "Parola resetata la data de:" << now->tm_mday << '-' << (now->tm_mon + 1) << '-' << (now->tm_year + 1900) << ' ' << now->tm_hour << ':' << now->tm_min << ':' << now->tm_sec << endl;
	fout.close();
}

int main()
{
	int optiune;


	do {
		system("cls");

		cout << "Ce doriti sa faceti?" << endl;
		cout << "0.Iesire" << endl;
		cout << "1.Inregistrare user" << endl;
		cout << "2.Autentificare" << endl;
		cout << "3.Resetare parola" << endl;
		cout << "Opriunea:";
		cin >> optiune;

		switch (optiune)
		{
		case 0:
			exit(0);
		case 1:
			inregistrare();
			evidenta_inregistrare();
			break;
		case 2:
			autentificare();
			evidenta_autentificare();
			break;
		case 3:
			resetareParola();
			evidenta_resetareParola();
			break;
		}

	} while (1);
	return 0;
}