//#PROGRAM: (Student Database Management System)

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int roll_no;
    string name;
    string division;
    string address;
};

void addStudent(ofstream &file)
{
    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.roll_no;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, student.name);
    cout << "Enter Division: ";
    cin >> student.division;
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, student.address);
    file << student.roll_no << " " << student.name << " " << student.division << " " << student.address << endl;
    cout << "Student record added successfully.\n";
}


void displayStudent(ifstream &file)
{
    Student student;
    int roll_no;
    bool found = false;
    cout << "Enter Roll Number to search: ";
    cin >> roll_no;
    while (file >> student.roll_no >> student.name >> student.division)
    {
        file.ignore();
        getline(file, student.address);
        if (student.roll_no == roll_no)
        {
            cout << "\nStudent Details:\n";
            cout << "Roll Number: " << student.roll_no << "\n";
            cout << "Name: " << student.name << "\n";
            cout << "Division: " << student.division << "\n";
            cout << "Address: " << student.address << "\n";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Record not found for Roll Number: " << roll_no << "\n";
    }
}

void displayAllStudents(ifstream &file)
{
    Student student;
    cout << "\nAll Student Records:\n";
    while (file >> student.roll_no >> student.name >> student.division)
    {
        file.ignore();
        getline(file, student.address);

        cout << "\nStudent Details:\n";
        cout << "Roll Number: " << student.roll_no << "\n";
        cout << "Name: " << student.name << "\n";
        cout << "Division: " << student.division << "\n";
        cout << "Address: " << student.address << "\n";
    }
}


void deleteStudent(const string &filename)
{
    ifstream file(filename);
    ofstream tempFile("temp.dat");
    Student student;
    int roll_no;
    bool found = false;
    if (!file || !tempFile)
    {
        cout << "Unable to open file.\n";
        return;
    }
    cout << "Enter Roll Number to delete: ";
    cin >> roll_no;
    while (file >> student.roll_no >> student.name >> student.division)
    {
        file.ignore();
        getline(file, student.address);
        if (student.roll_no != roll_no)
        {
            tempFile << student.roll_no << " " << student.name << " " << student.division << " " << student.address << endl;
        } else
        {
            found = true;
        }
    }
    if (found)
    {
        cout << "Student record deleted successfully.\n";
    } else
    {
        cout << "Record not found for Roll Number: " << roll_no << "\n";
    }

    file.close();
    tempFile.close();
    remove(filename.c_str());
    rename("temp.dat", filename.c_str());
}


void displayMenu()
{
    cout << "\nStudent Database Management System\n";
    cout << "1. Add Student\n";
    cout << "2. Display Student\n";
    cout << "3. Display All Students\n";
    cout << "4. Delete Student\n";
    cout << "Enter your choice: ";
}

int main()
{
    string filename = "student_data.txt";
    int choice;
    while (true)
    {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            ofstream file(filename, ios::app);
            if (!file)
            {
                cout << "Unable to open file.\n";
                break;
            }
            addStudent(file);
            file.close();
            break;
        }

        case 2:
        {
            ifstream file(filename);

            if (!file)
            {
                cout << "Unable to open file.\n";
                break;
            }
            displayStudent(file);
            file.close();
            break;
        }

        case 3:
        {
            ifstream file(filename);
            if (!file)
            {
                cout << "Unable to open file.\n";
                break;
            }
            displayAllStudents(file);
            file.close();
            break;
        }

        case 4:
            deleteStudent(filename);
            break;
        }
    }
    return 0;
}
