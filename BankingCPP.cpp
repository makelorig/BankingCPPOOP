#include <iostream>
#include <string>
#define random(min,max) min+rand()%(max-min+1)
using namespace std;

class Client {
	friend class Bank;
private:
	static unsigned int lastId;

	string firstName;
	string secondName;
	unsigned short age;
	unsigned long long bankAccount;
	unsigned int id;
	double balance = 0;
	Client(string firstName, string secondName, unsigned short age, long long bankAccount) {
		this->firstName = firstName;
		this->secondName = secondName;
		this->age = age;
		this->balance = 0;
		this->id = lastId++;
		this->bankAccount = bankAccount;
	}

public:
	Client() {}

	void setFirstName(string firstName) {
		this->firstName = firstName;
	}
	void setSecondName(string secondName) {
		this->secondName = secondName;
	}
	string getFirstName() {
		return this->firstName;
	}

	void clientInfo() {
		cout << "First Name: " << this->firstName << endl;
		cout << "Second Name: " << this->secondName << endl;
		cout << "Balance: " << this->balance << endl;
		cout << "Bank Account: " << this->bankAccount << endl;
		cout << "ID: " << this->id << endl;
	}

};
unsigned int Client::lastId = 0;

class Bank
{
private:
	string bankName;
	Client** clients = new Client * [10];
	unsigned int size = 0;
public:
	Bank() {
		this->bankName = bankName;
	}
	/*int operator = (Bank);*/
	void changeBalance(Client bankAccaunt, double value) {
		char f;
		cin >> f;
		if (f == '+') {

		}
		else if (f == '-') {

		}
		else {
			cout << "Return again";
		}
	}

	~Bank() {
		for (int i = 0; i < size; i++)
		{
			delete clients[i];
		}
		delete[] this->clients;
	}


	void createClient() {
		Client** buf = new Client * [size + 1];
		for (int i = 0; i < size; i++)
		{
			buf[i] = clients[i];
		}
		delete[]  clients;
		clients = buf;
		size++;
	}
	//void deleteClient() {
	//	if (size == 0) {
	//		cout << "Clients aren't avalible";
	//	}

	//}

	long long createBA() {
		int uid = random(1000000000000000, 9999999999999999);
		bool flag = false;

		for (int i = 0; i < size; i++)
		{
			if (clients[i]->bankAccount == uid) {

			}
		}


	}
	void BankInfo() {
		cout << "Name: " << this->bankName << endl;
		cout << "Cars count: " << this->size << endl;
		if (size == 0)cout << "Bank is empty" << endl;
		else {
			cout << "Clients: " << endl;
			for (int i = 0; i < size; i++)
			{
				clients[i]->clientInfo();
			}

		}

	}

};

int main()
{
	srand(time(NULL));
	/*Client** clients = new Client * [10];
	for (int i = 0; i < 100; i++)
	{
		clients[i] = new clients[i]();
	}*/
}
