// Hasta La Vista.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>

using namespace std;

class Student {
private:
    string name;
    string group;
    int age;
public:
    Student(const string& _name, const string& _group, int _age) : name(_name), group(_group), age(_age) {}

    string getName() const {
        return name;
    }

    string getGroup() const {
        return group;
    }

    int getAge() const {
        return age;
    }
};

class Journal {
private:
    vector<Student> students;
public:
    Journal(const vector<Student>& _students) : students(_students) {}

    void printJournal() const {
        for (const auto& student : students) {
            cout << "Name: " << student.getName() << ", Group: " << student.getGroup() << ", Age: " << student.getAge() << endl;
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& student : students) {
                file << "Name: " << student.getName() << ", Group: " << student.getGroup() << ", Age: " << student.getAge() << endl;
            }
            file.close();
            cout << "Journal saved to file: " << filename << endl;
        }
        else {
            cout << "Error: Unable to open file " << filename << " for writing." << endl;
        }
    }
};

void saveJournalToFile(const Journal& journal, const string& filename) {
    journal.saveToFile(filename);
}

int main() {
    vector<Student> students1 = { Student("John", "Group A", 20), Student("Alice", "Group A", 22) };
    vector<Student> students2 = { Student("Bob", "Group B", 21), Student("Eve", "Group B", 23) };

    Journal journal1(students1);
    Journal journal2(students2);

    thread thread1(saveJournalToFile, journal1, "journal1.txt");
    thread thread2(saveJournalToFile, journal2, "journal2.txt");

    thread1.join();
    thread2.join();

    return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
