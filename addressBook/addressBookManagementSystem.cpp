#include <iostream>
using namespace std;
#define MAX 1000

struct Person
{
	string m_name;
	string m_gender;
	int m_age;
	string m_phoneNumber;
	string m_address;
};

struct addressBooks
{
	struct Person personArray[MAX];
	int m_size;
};

void showMenu()
{
	cout << "1.Add a contact" << endl; 
	cout << "2.Show all contact" << endl;
	cout << "3.Delete a contact" << endl;
	cout << "4.Search a contact" << endl;
	cout << "5.Alter a contact" << endl;
	cout << "6.Clean all contact" << endl;
	cout << "0.Exit" << endl;
}

void addPerson(addressBooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_size == MAX)
	{
		cout << "Addressbooks is full!" << endl;
		return;
	}
	else
	{
		//name
		string name;
		cout << "Please input a name: " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;
		//gender
		string gender;
		cout << "Please input the gender: " << endl;
		cin >> gender;
		abs->personArray[abs->m_size].m_gender = gender;
		//age
		int age;
		cout << "Please input the age: " << endl;
		cin >> age;
		abs->personArray[abs->m_size].m_age = age;
		//phone
		string phoneNum;
		cout << "Please input the phone number: " << endl;
		cin >> phoneNum;
		abs->personArray[abs->m_size].m_phoneNumber = phoneNum;
		//address
		string address;
		cout << "Please input the address: " << endl;
		cin >> address;
		abs->personArray[abs->m_size].m_address = address;
		//cout << "������" << endl;
		abs->m_size += 1;
		cout << "Successfully added!" << endl;
		system("pause");
		system("cls");
		return;
	}
}
 
void showPerson(addressBooks Abs)
{
	if (Abs.m_size == 0)
	{
		cout << "NULL" << endl;
		return;
	}
	else
	{
		for (size_t i = 0; i < Abs.m_size; i++)
		{
			cout << endl;
			cout << "************** Printing **************" << endl;
			cout << "Name: " << Abs.personArray[i].m_name << endl;
			cout << "Gender: " << Abs.personArray[i].m_gender << endl;
			cout << "Age: " << Abs.personArray[i].m_age << endl;
			cout << "Phone Number: " << Abs.personArray[i].m_phoneNumber << endl;
			cout << "Address: " << Abs.personArray[i].m_address << endl;
			cout << "**************************************" << endl;
			cout << endl;
		}
		system("pause");
		system("cls");
		return;
	}
}

int detectPerson(addressBooks * Abs, string name)
{
	for (size_t i = 0; i < Abs->m_size; i++)
	{
		if (Abs->personArray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(addressBooks * Abs)
{
	string name;
	int deleteDecision;
	cout << "Please input the name you want to delete." << endl;
	cin >> name;
	if (detectPerson(Abs, name) == -1)
	{
		cout << "Can not find this person." << endl;
	}
	else
	{
		cout << "Detected, if you wan to delete this contact, please input 1." << endl;
		cin >> deleteDecision;
		if (deleteDecision == 1)
		{
			int ret = detectPerson(Abs, name);
			for (size_t i = ret; i < Abs->m_size; i++)
			{
				Abs->personArray[i] = Abs->personArray[i + 1];
			}
			Abs->m_size -= 1;
			cout << "Successfully deleted " << endl;	
		}
		return;
	}
}

void searchPerson(addressBooks Abs)
{
	cout << "Lookup Method" << endl;
	cout << "1. Number " << endl;
	cout << "2. Name" << endl;
	cout << "Please input the method: " << endl;
	int method;
	cin >> method;
	if (method == 1)
	{
		cout << "Please input the Number: " << endl;
		int n;
		cin >> n;
		if (n>Abs.m_size)
		{
			cout << "the number is out of range!" << endl;
			return;
		}
		else
		{
			cout << endl;
			cout << "************** Printing **************" << endl;
			cout << "Name: " << Abs.personArray[n - 1].m_name << endl;
			cout << "Gender: " << Abs.personArray[n - 1].m_gender << endl;
			cout << "Age: " << Abs.personArray[n - 1].m_age << endl;
			cout << "Phone Number: " << Abs.personArray[n - 1].m_phoneNumber << endl;
			cout << "Address: " << Abs.personArray[n - 1].m_address << endl;
			cout << "**************************************" << endl;
			cout << endl;
			return;
		}
		n = 0;
	}
	else if (method == 2)
	{
		string name;
		cout << "Please input the name: " << endl;
		cin >> name;
		int ret = detectPerson(&Abs, name);
		if (ret ==-1)
		{
			cout << "Can't find this person." << endl;
		}
		else
		{
			cout << "************** Printing **************" << endl;
			cout << "Name: " << Abs.personArray[ret].m_name << endl;
			cout << "Gender: " << Abs.personArray[ret].m_gender << endl;
			cout << "Age: " << Abs.personArray[ret].m_age << endl;
			cout << "Phone Number: " << Abs.personArray[ret].m_phoneNumber << endl;
			cout << "Address: " << Abs.personArray[ret].m_address << endl;
			cout << "**************************************" << endl;
			cout << endl;
		}
		return;
	}
	else
	{
		cout << "The number is out of range!!!" << endl;
	}
	return;
}



int main() 
{

	//����ͨѶ¼�ṹ�����
	addressBooks Abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	Abs.m_size = 0;

	int select = 0;

	while (true)
	{

		showMenu();
		cin >> select;

		switch (select)
		{
		case 1:
			addPerson(&Abs);
			break;
		case 2:
			showPerson(Abs);
			break;
		case 3:
			deletePerson(&Abs);
			break;
		case 4:
			searchPerson(Abs);
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			cout << "Thank you for using and see you next time!" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	


	//system("pause");
	return 0;
}