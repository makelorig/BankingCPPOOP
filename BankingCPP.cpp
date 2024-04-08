#include <iostream>
#include <string>
#define random(min,max) min+rand()%(max-min+1)
using namespace std;

class Bank;

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
	void setAge(unsigned int age) {
		this->age = age;
	}
	void setBalance() {
		 this->balance = balance;
	}
	string getFirstName() {
		return this->firstName;
	}
	string getSecondName() {
		return this->secondName;
	}
	unsigned int getAge() {
		return this->age;
	}
	double getBalance() {
		return this->balance;
	}
	
	void clientInfo() {
		cout << endl;
		cout << "First Name: " << this->firstName << endl;
		cout << "Second Name: " << this->secondName << endl;
		cout << "Balance: " << this->balance << endl;
		cout << "Bank Account: " << this->bankAccount << endl;
		cout << "ID: " << this->id << endl;
	}

	bool operator ==(const Client &cl) {
		if (this->firstName == cl.firstName &&
			this->secondName == cl.secondName &&
			this->age == cl.age)return 1;
			else return 0;
	}

};
unsigned int Client::lastId = 1;

class Bank
{
private:
	string name;
	Client* clients = new Client[10];
	unsigned int size = 0;
public:
	Bank(string name) {
		this->name = name;
	}
	void createClient(string firstName, string secondName, unsigned short age) {
		Client* buf = new Client[size + 1];
		for (int i = 0; i < size; i++)
		{
			buf[i] = clients[i];
		}
		delete[]  clients;
		clients = buf;
		clients[size++] = Client(firstName, secondName, age, createBA());
	}

	unsigned long long createBA() {
		unsigned long long uid = 0;
		bool flag = false;
		do {
			uid += random(1000, 9999) * 10000;
			uid += random(1000, 9999);
		} while (!checkBankAcccount(uid));

		return uid;
	}
	bool checkBankAcccount(unsigned long long bankAccount) {
		for (int i = 0; i < size; i++)
		{
			if (clients[i].bankAccount == bankAccount)return false;
		}
		return true;
	}
	void bankInfo() {
		cout << "Name: " << this->name << endl;
		cout << "Cars count: " << this->size << endl;
		if (size == 0)cout << "Bank is empty" << endl;
		else {
			cout << "Clients: " << endl;
			for (int i = 0; i < size; i++)
			{
				clients[i].clientInfo();
			}

		}
	}
	void showClients() {
		for (int i = 0; i < size; i++)
		{
			clients[i].clientInfo();
		}
	}
	~Bank() {
		delete[] clients;
	}

	void delClient(int id) {
		Client* buf = new Client[size - 1];

		for (int i = 0,k=0; i < size; i++)
		{
			if(this->clients[i].id!=id) buf[k++] = clients[i];
		}
		delete[]  clients;
		clients = buf;
	}

	void foundByID(int id) {
		if (id > size || id <= 0 ) {
			cout << "ID is difernt";
		}
		else {
			clients[id-1].clientInfo();
		}
	}

	void addBalane(unsigned long long ba, int amount) {
		for (int i = 0; i < size; i++)
		{ 
			if (clients[i].bankAccount ==ba)
			{
				clients[i].balance += amount;
			}
		}
	}
	void transaction(unsigned long long sender, unsigned long long reciver, int amount) {
		int sendInd = -1;
		int reciInd = -1;
		for (int i = 0; i < size; i++)
		{
			if (clients[i].bankAccount == sender) {
				if (clients[i].balance >= amount) {
					sendInd = i;
				}
				else {
					cout << "Not enough money" << endl;
					return;
				}
			}
		}
		if (sendInd == -1) {
			cout << "Sender not found" << endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			if (clients[i].bankAccount == reciver) {
				if (clients[i].balance >= amount) {
					reciInd = i;
				}
			}
			else
			{
				cout << "Tacker not found" << endl;
				return;
			}
		}
		clients[sendInd].balance -= amount;
		clients[reciInd].balance += amount;
		cout << "Transaction complited" << endl;
	}
	void operator =(Bank& bk) {
		bk.name = this->name; 
		bk.clients = this->clients; 
		bk.size = this->size;
	}
};

int main()
{


	srand(time(NULL));
	Bank bk1("Hitbank");
	for (int i = 0; i < 20; i++)
	{
		bk1.createClient("Nigr", "Nillers", 52);
	}
	bk1.bankInfo();
	bk1.delClient(14);
	bk1.foundByID(15);
	bk1.bankInfo();
}
