#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Student 
{
	string FirstName;
	string LastName;
	string StudentID;

public:
	Student()
	{

	}
	void setFirstName(string fn)
	{	
		FirstName = fn;
	}	 
		 
	void setLastName(string ln)
	{	 
		LastName = ln;
	}	 
		 
	void setStudentID(string sid)
	{
		StudentID = sid;

	}
	string getData()
	{
		string output = "";
		output = FirstName + "\t" + LastName + "\t" + StudentID;
		return output;
	}
	string getStudentID()
	{
		return StudentID;
	}
	template <class T>
	friend void swap(Student &a, Student &b);
	friend void selectionSort(int size, Student* arr);
};

template <class T>
void swap(Student a, Student b)
{
	Student temp = a;
	a = b;
	b = temp;
}
void selectionSort(int size,Student* arr)
{
	// Sort by Last Name: using Selection Sort Algorithm

	int indexOfMin, temp;

	for (int i = 0; i < size - 1; i++)
	{
		indexOfMin = i;//set indexOfMin to the current index of array

		for (int j = i + 1; j < size; j++)
		{


			if (arr[j].LastName.compare(arr[indexOfMin].LastName)<0)
				indexOfMin = j;
			//indexOfMin will keep track of the index that min is in, this is needed when a swap happens
		}

		//if indexOfMin no longer equals i than a smaller value must have been found, so a swap must occur
		if (indexOfMin != i)
		{
			swap(arr[i], arr[indexOfMin]);
		}
	}
}


void waitForUser()
{
	cout << "Press Any Key To Return To Menu" << endl;
	_getch();
}

void clearScreen()
{
	system("cls");
}



void main()
{
	int num;
	cout << "Please Enter Number of Stundents" << endl;
	cin >> num;

	Student* students= new Student[num];
	clearScreen();
	cout << "Welcome to The Student Management Application" << endl;
	while (true)
	{
		char choice;
		//view menu for data entry,search,display
		clearScreen();
		cout << "Please Select Your Desired Operation:" << endl;
		cout << "\t1) Enter Student Data (will overwrite previous data)" << endl
			<< "\t2) Display Stored Data " << endl
			<< "\t3) Search For Specific Entry" << endl
			<< "\tx) Exit" << endl;
		choice = _getch();
		
		if (choice == '1')
		{
			for (int i = 0;i < num;i++)
			{
				clearScreen();
				string input;
				cout << "Receiving Data for Record " << i + 1<<":" << endl;
				//Set First Name:
				cout << "Enter First Name" << endl;
				cin >> input;
				students[i].setFirstName(input);
				//Set Last Name:
				cout << "Enter Last Name" << endl;
				cin >> input;
				students[i].setLastName(input);
				//Set Student ID:
				cout << "Enter Student ID" << endl;
				cin >> input;
				students[i].setStudentID(input);

			}
			
			selectionSort(num, students);
			


			
		}
		
		
		else if (choice == '2')//Will Display Data For All Entered Records
		{
			for (int i = 0;i < num;i++)
			{
				cout << students[i].getData() << endl;
			}
			waitForUser();

		}

		else if (choice == '3')
		{
			string query;
			cout << "Enter Student ID" << endl;
			cin >> query;
			cout << "Seraching..." << endl;
			bool found = false;
			int index = 0;
			while (found != true)
			{
				if (students[index].getStudentID() == query)
				{
					found = true;
					cout << students[index].getData() << endl;
				}
				else if (index < num)
					index++;
				else
					cout << "No Match Found!" << endl;

			}
			waitForUser();
		}
		
		else if (choice=='x')
			break;

		
		}
	

}