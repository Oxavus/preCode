#include <iostream>
#include <string>
using namespace std;
//TODO
//create mod instance in menu




class Menu;

//-------------------------Main Block-------------------------
int main()
{
	Menu menu = new Menu();
	menu.run();
	return 0;
}
//------------------------------------------------------------

//------------------define variable----------------------------
struct Staffdata
{
	string id[5],
		name[10],
		sex[5],
		adres[10],
		userInput[10];
	int age, phone, salary;
	bool loop;
};
//------------------------------------------------------------

//------------------------menu()------------------------------
class
{
	public:
	Staffdata Staff;
	Staff.loop = true;
	int run()
	{
		do
		{
			cout << "*************************\n\t\tMenu:**************************\n\tr to Read\n\tw to Write" << endl;
			cin >> Staff.userInput;
			switch (Staff.userInput)
			{
			case "w":
				do
				{
					cout << "**************************\n\t\tWrite_Mode Menu:*************************\n\tn to New\n\te to Existed" << endl;
					cin >> Staff.userInput;
					switch (Staff.userInput) //	Write_mode
					{
					case "n": // Create New file
						cout << "**************************\n\t\tNew_File Menu:*************************\n\tFile Name : ";
						cin >> Staff.userInput;
						//	newFile(Staff.userInput);
						break;
					case "e":
						cout << "**************************\n\t\tEdit_File Menu:*************************\n\tFile Name : ";
						cin >> Staff.userInput;
						//	editFile(Staff.userInput); // Edit existing file
						break;
					case "d":
						cout << "**************************\n\t\tDelete_File Menu:*************************\n\tFile Name : ";
						cin >> Staff.userInput;
					//	deleteFile(Staff.userInput);
					default:
						cout << "\nInvalid Input!!!" << endl;
						break;
					}
				} while (Staff.loop);
				break;
			case "r":
				do
				{
					switch (Staff.userInput) //	Read_mode
					{
					case "a":
						cout << "**************************\n\t\tRead_File Menu:*************************\n\tFile Name : ";
						cin >> Staff.userInput;
						//	readfile(); // read all doc in selected file
						break;
					case "s":
						cout << "**************************\n\t\tSearch_File Menu:*************************\n\tFile Name : ";
						cin >> Staff.userInput;
						//	searchData(); // search data in file
						break;
					case "x":
						cout << "**************************\n\t\tRead_All_File:*************************\n\t";
						cin >> Staff.userInput;
						//	readAll(); // read all files
						break;
					default:
						cout << "\nInvalid Input!!!" << endl;
						break;
					}
				} while (Staff.loop);
				break;
			default:
				cout << "\nInvalid Input!!!" << endl;
				break;
			}
		} while (Staff.loop);
	}
};
//------------------------------------------------------------

//------------------------------MODS-------------------------
class Mode
{
public:
	string newFile()
	{
	}

	string editFile()
	{
	}

	string deleteFile()
	{
	}

	string readfile()
	{
	}

	string searchData()
	{
	}

	string readAll()
	{
	}
};
//-----------------------------------------------------------

//----------------------sort_engine--------------------------
class Sort
{
public:
};
//----------------------------------------------------------
