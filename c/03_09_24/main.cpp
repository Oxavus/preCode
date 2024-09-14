#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <vector>
using namespace std;
namespace fs = filesystem;

//------------------define variable----------------------------
struct Staffdata
{
	string id[5],
	       name[10],
	       sex[5],
	       adres[10],
	       userInput;
	int age, phone, salary;
	bool loop;
};
//------------------------------------------------------------


//------------------------menu()------------------------------
class Menu
{
public:
	Staffdata Staff;
	Menu() {
		Staff.loop = true;
	}
	int run()
	{
		do
		{
			cout << "*************************Menu:**************************\n\tr to Read\n\tw to Write" << endl;
			cin >> Staff.userInput;

			if (Staff.userInput == "w") {
				do
				{
					cout << "**************************Menu:*************************\n\tn to New\n\te to Filen\td to Delete" << endl;
					cin >> Staff.userInput;
					if (Staff.userInput == "n") {
						cout << "**************************New_File Menu:*************************\n\tFile Name : ";
						cin >> Staff.userInput;
						cout << "File Created: " << Staff.userInput << endl;
					}
					else if (Staff.userInput == "e") {
						cout << "**************************Edit_File Menu:*************************\n\tFile Name : ";
						cin >> Staff.userInput;
						cout << "File Edited: " << Staff.userInput << endl;
					}
					else if (Staff.userInput == "d") {
						cout << "**************************Delete_File Menu:*************************\n\tFile Name : ";
						cin >> Staff.userInput;
						cout << "File Deleted: " << Staff.userInput << endl;
					}
					else {
						cout << "\nInvalid Input!!!" << endl;
					}
				} while (Staff.loop);
			}
			else if (Staff.userInput == "r") {
				do
				{
					cout << "**************************Read_Mode Menu:*************************\n\ta to Read\n\ts to Search\n\tx to Read All" << endl;
					cin >> Staff.userInput;

					if (Staff.userInput == "a") {
						cout << "**************************Read_File Menu:*************************\n\tFile Name : ";
						cin >> Staff.userInput;
						cout << "File Read: " << Staff.userInput << endl;
					}
					else if (Staff.userInput == "s") {
						cout << "**************************Search_File Menu:*************************\n\tFile Name : ";
						cin >> Staff.userInput;
						cout << "File Searched: " << Staff.userInput << endl;
					}
					else if (Staff.userInput == "x") {
						cout << "**************************Read_All_File:*************************\n\t";
						cin >> Staff.userInput;
						cout << "All Files Read: " << Staff.userInput << endl;
					}
					else {
						cout << "\nInvalid Input!!!" << endl;
					}
				} while (Staff.loop);
			}
			else {
				cout << "\nInvalid Input!!!" << endl;
			}
		} while (Staff.loop);

		return 0;
	}
};
//------------------------------------------------------------

//------------------------------MODS-------------------------
class Mode
{
public:
void newFile(string filename)
{
    ofstream MyFile("%s.txt", filename);
    MyFile.close();
}


void editFile()
{
}

void deleteFile()
{
    int status = remove("myfile.txt");
    if (status != 0) {
        perror("Error deleting file");
    }
    else {
        cout << "File successfully deleted" << endl;
    }
}

void readfile(string filename)
{
    ifstream inputFile("%s.txt", filename);
    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }
    string line;
    cout << "File Content: " << endl;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }
    inputFile.close();
}

void searchData(string filename, string searchID)
{
    string line;
    bool found = false;
    cout << "Enter the ID to search: ";
    cin >> searchID;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    while (getline(file, line)) {
        if (line.find(searchID) != string::npos) {
            cout << "ID found: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "ID not found in the file." << endl;
    }
    file.close();
}

void listDir()
{
    string path = "./";
    try {

        if (fs::exists(path) && fs::is_directory(path)) {
            cout << "Listing files in directory: " << path << endl;
            for (const auto& entry : fs::directory_iterator(path)) {
                cout << entry.path().filename().string() << endl;
            }
        } else {
            cerr << "The specified path is not a valid directory." << endl;
        }
    } catch (const fs::filesystem_error& e) {
        cerr << "Filesystem error: " << e.what() << endl;
    }

}

};
//-----------------------------------------------------------

//----------------------sort_engine--------------------------
class Sort
{
public:

    engine()
    {
      ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: Could not open the input file.\n";
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();
    sort(lines.begin(), lines.end());
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Error: Could not open the output file.\n";
        return 1;
    }
    for (const auto& sortedLine : lines) {
        outputFile << sortedLine << '\n';
    }
    outputFile.close();
    cout << "Sorting complete! Check 'output.txt' for the sorted text.\n";
    }
};
//-----------------------------------------------------------

//-------------------------Main Block-------------------------
int main()
{
	Menu menu;
	menu.run();
	return 0;
}
//------------------------------------------------------------
