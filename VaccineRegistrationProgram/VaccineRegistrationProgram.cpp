#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<ctime>

using namespace std;

struct Person {
	string Id;
	string Name;
	string Surname;
	string Age;
	string City;
	string LastVactineDate;
	string Doze;
	string VactineType;
};

int Entrance();
vector<Person> ReadFile(vector<Person>& person);
void Login(vector<Person>& person);
void Register(vector<Person>& person);
void DisplayInfo(Person& p);
void Save(vector<Person>& person);


int main() {

	vector<Person>person;
	Person p;

	ReadFile(person);

	while (1) {

		int decision = Entrance();

		if (decision == 1) {
			Login(person);
		}

		else if (decision == 2)
			Register(person);

		else if (decision == 3)
			Save(person);

	}

	return 0;
}

int Entrance() {
	cout << "***********************************************************************\n\n\n";
	cout << "                      Welcome to login page                               \n\n";
	cout << "*******************        MENU        *******************************\n\n";
	cout << "1. LOGIN" << endl;
	cout << "2. REGISTER" << endl;
	cout << "3. Save and Exit" << endl;

	int decision;
	cin >> decision;

	return decision;
}

vector<Person> ReadFile(vector<Person>& person) {

	fstream dataFile;
	string tmp;

	dataFile.open("database.txt", fstream::in);
	if (!dataFile)
	{
		cout << "File open error!" << endl;
		exit(0);
	}

	else
	{
		cout << "File opened successfully!" << endl;

		dataFile >> tmp;
		int i = 0;
		Person p;

		while (!dataFile.eof())
		{

			p.Id = tmp;
			dataFile >> tmp;
			p.Name = tmp;
			dataFile >> tmp;
			p.Surname = tmp;
			dataFile >> tmp;
			p.Age = tmp;
			dataFile >> tmp;
			p.City = tmp;
			dataFile >> tmp;
			p.LastVactineDate = tmp;
			dataFile >> tmp;
			p.Doze = tmp;
			dataFile >> tmp;
			p.VactineType = tmp;
			dataFile >> tmp;

			person.push_back(p);
		}
		return person;
	}
}

void Login(vector<Person>& person) {
	while (1) {
		string id;
		cout << "\nEnter your id.";
		cin >> id;

		for (int i = 0; i < person.size(); i++) {
			if (id == person[i].Id) {
				cout << "Login Succesfull";
				DisplayInfo(person[i]);
			}
		}
		cout << "Wrong Id";
		return;
	}
}

void Register(vector<Person>& person) {

	Person p;

	while (1)
	{
		cout << "Id: ";
		cin >> p.Id;

		//if ((p.Id[0] >= 65 && p.Id[0] <= 90) && (p.Id[1] >= 65 && p.Id[1] <= 90) && (p.Id[0] >= 97 && p.Id[0] <= 122) && (p.Id[1] >= 97 && p.Id[1] <= 122) && (p.Id[2] >= 48 && p.Id[2] <= 57) && (p.Id[3] >= 48 && p.Id[3] <= 58)) {

		cout << "Ad: ";
		cin >> p.Name;

		cout << "Soyad: ";
		cin >> p.Surname;

		cout << "Yas: ";
		cin >> p.Age;
		
		cout << "Sehir: ";
		cin >> p.City;

		p.LastVactineDate = "01.06.2020";
		p.Doze = "0";
		p.VactineType = "Null";

		person.push_back(p);
		break;
		//}

		//else
		//	continue;

	}


}

void Save(vector<Person>& person) {

	ofstream outFile;
	outFile.open("database.txt");

	for (int i = 0; i < person.size(); i++) {
		outFile << person[i].Id << " " << person[i].Name << " " << person[i].Surname << " " << person[i].Age << " " << person[i].City << " " << person[i].LastVactineDate << " " << person[i].Doze << " " << person[i].VactineType << endl;
	}

	outFile.close();
	exit(0);
}

void DisplayInfo(Person& p) {
	while (1) {


		int decision;

		cout << endl << endl << "Your Information";
		cout << p.Id << endl;
		cout << p.Name << endl;
		cout << p.Surname << endl;
		cout << p.Age << endl;
		cout << p.City << endl;
		cout << p.LastVactineDate << endl;
		cout << p.Doze << endl;
		cout << p.VactineType << endl << endl;

		cout << "Press 1 to Update Information" << endl;
		cout << "Press 2 to Vactine Register" << endl;
		cout << "Press 3 to Exit" << endl;

		cin >> decision;


		if (decision == 1) {

			cout << "Id: " << endl;
			cin >> p.Id;

			cout << "Name: " << endl;
			cin >> p.Name;

			cout << "Surname" << endl;
			cin >> p.Surname;

			cout << "Age" << endl;
			cin >> p.Age;

			cout << "City" << endl;
			cin >> p.City;
		}

		else if (decision == 2) {

			string type;

			cout << "We have two type of vactine X and Y. Which one do you want to choose?";
			cin >> type;

			if (stoi(p.Age) >= 18 && stoi(p.Doze) < 2) {

				if ((type == "x" || type == "X") && (p.VactineType == "X" || p.VactineType == "Null")) {
					/**/p.VactineType = "X";
					int a = stoi(p.Doze) ;
					a = a + 1;


				
									p.Doze = to_string(a);

				}
				else if ((type == "y" || type == "Y") && (p.VactineType == "Y" || p.VactineType == "Null")) {
					p.VactineType = "Y";
					int a = stoi(p.Doze);
					a = a + 1;
					p.Doze = to_string(a);
				}

				else
					cout << "You have to choose last vactine type";
			}

			else
				cout << "You are under 18 or You have vactined twice already";

		}

		else if (decision == 3) {
			return;
		}
	}
}