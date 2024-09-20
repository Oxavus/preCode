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
	int age, phone;
	float salary;
};
//------------------------------------------------------------


//------------------------menu()------------------------------
class Menu : public Func
{
public:
	Staffdata Staff;
	int run()
	{
		do
		{
			cout << "*************************Menu:**************************\n\tr to Read\n\tw to Write\n\tx to Exit" << endl;
			cin >> Staff.userInput;

			if (Staff.userInput == "w") {
				do
				{
					cout << "**************************Menu:*************************\n\tn to New\n\te to Filen\n\td to Delete" << endl;
					cin >> Staff.userInput;
                       system("clear");
					if (Staff.userInput == "n") {
                        system("clear");
						cout << "**************************New_File Menu:*************************\n\tFile Name : ";
						cin >> Staff.userInput;
						//Func.newFile(Staff.userInput);
						// fillForm();
						//Func.writeToFile(Staff.userInput, Staff.id, Staff.name, Staff.sex, Staff.age, Staff.adres, Staff.phone, Staff.salary);
					}

					else if (Staff.userInput == "e") {
                        system("clear");
						cout << "**************************Edit_File Menu:*************************\n\tList Files";
						// list directory Func.listDir();
						cout << "File Name : ";
						cin >> Staff.userInput;
					}
					else if (Staff.userInput == "d") {
                           system("clear");
						cout << "**************************Delete_File Menu:*************************\n\tFile Name : ";
						cin >> Staff.userInput;
						cout << "File Deleted: " << Staff.userInput << endl;
						//Func.deleteFile(Staff.userInput);
					}else if(Staff.userInput== "x"){
                        cout << "\nClosing!!!" << endl;
					}else {
						cout << "\nInvalid Input!!!" << endl;
					}
				} while (Staff.userInput!="x");
			}
			else if (Staff.userInput == "r") {
				do
				{
					cout << "**************************Read_Mode Menu:*************************\n\ta to List all Files\n\ts to Search\n\tx to Exit" << endl;
					cin >> Staff.userInput;

					if (Staff.userInput == "a") {
                        system("clear");
						cout << "**************************List_All_Files*************************\n";
						//Func.listDir();
						//Func.readFile(Staff.userInput);
						cout << "File Name : ";
						cin >> Staff.userInput;
					}
					else if (Staff.userInput == "s") {
                        system("clear");
						cout << "**************************Search_File Menu:*************************\n\tFile Name : ";
						cin >> Staff.userInput;
						cout << "File Searched: " << Staff.userInput << endl;
					}
					else if (Staff.userInput == "all") {
                        system("clear");
						cout << "**************************Read_All_File:*************************\n\t";
						cin >> Staff.userInput;
					}else if(Staff.userInput=="x"){
                        cout << "\nClosing!!!" << endl;
					}else {
						cout << "\nInvalid Input!!!" << endl;
					}
				} while (Staff.userInput!="x");
			}
			else if(Staff.userInput=="x"){
				cout << "\nClosing!!!" << endl;
			}else {
				cout << "\nInvalid Input!!!" << endl;
			}
		}while (Staff.userInput!="x");

		return 0;
	}
void fileForm(){
cout << "**************************Fill_Form:*************************\n";
cout << "STAFFID :"
cin >> Staff.id;
cout << "STAFFNAME :"
cin >> Staff.name;
cout << "SEX :"
cin >> Staff.sex;
cout << "AGE :"
cin >> Staff.age;
cout << "ADDRESS :"
cin >> Staff.address;
cout << "PHONE :"
cin >> Staff.phone;
cout << "SALARY :"
cin >> Staff.salary;
}
};
//------------------------------------------------------------

//------------------------------MODS--------------------------
class Func : public Sort
{
public:

void newFile(string filename)// need fixing
{
 string dirPath = "Staff";
    try {
        if (fs::create_directory(dirPath)) {
            cout << "Directory created successfully." << endl;
        } else {
            cout << "Directory already exists or could not be created." << endl;
        }
    } catch (const fs::filesystem_error& e) {
        cerr << "Filesystem error: " << e.what() << endl;
    }

   ofstream MyFile("%s.txt", filename);
    MyFile.close();
}

void editFile(string filename)
{
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Could not open the file for reading!" << endl;
        return 1;
    }
    string content;
    string line;
    while (getline(infile, line)) {
        content += line + "\n";
    }
    infile.close();
    string oldText = "oldText";
    string newText = "newText";
    size_t pos = content.find(oldText);
    if (pos != string::npos) {
        content.replace(pos, oldText.length(), newText);
    }
    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cerr << "Could not open the file for writing!" << endl;
        return 1;
    }
    outfile << content;
    outfile.close();
    cout << "File updated successfully." << endl;
}

void deleteFile(string filename)
{
    int status = remove("%s.txt",filename);
    if (status != 0) {
        perror("Error deleting file");
    }
    else {
        cout << "File successfully deleted" << endl;
    }
}

void readFile(string filename)
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
    string path = "Staff/";
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

 // college all user input and write to text file add NO system
void writeToFile(string filename, string id, string name, string sex, int age, string address, int phone, float salary ){
     string line;
     int note=0;
    ofstream file;
    file.open(filename);
      while (getline(file, line)) {
      note+=1;
    }
    if (file.eof()) {
       file << "%d-%s-%s-%s-%d-%s-%d-%f", note, id, name, sex, age, address, phone, salary << endl;
    } else {
        cerr << "Error reading file!" << endl;
    }
    file.close();
    cout << "write to " << filename << " successfully." << endl;
}
};
//-----------------------------------------------------------

//----------------------sort_engine--------------------------
class Sort
{
public:

    bubble(string filename)
    {
      ifstream inputFile("%s.txt",filename);
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
