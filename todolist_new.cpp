#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int ID = 0;

struct todo {
    int id;
    bool completed;
    string task;
};

void print(todo t) {
    cout << "\n-----------------------------------";
    cout << "\nID      : " << t.id;
    cout << "\nTask    : " << t.task;
    cout << "\nStatus  : "
         << (t.completed ? "Completed" : "Pending");
    cout << "\n-----------------------------------";
}

void addTodo() {
    todo t;

    cout << "\nEnter New Task: ";

    cin.ignore();
    getline(cin, t.task);

    ID++;
    t.id = ID;
    t.completed = false;

    ofstream write("todo.txt", ios::app);

    write << t.id << endl;
    write << t.completed << endl;
    write << t.task << endl;

    write.close();

    ofstream idFile("id.txt");
    idFile << ID;
    idFile.close();

    cout << "\nTask Added Successfully!\n";
}

void readData() {
    ifstream read("todo.txt");

    todo t;
    bool found = false;

    cout << "\n======= TODO LIST =======\n";

    while (read >> t.id) {
        read >> t.completed;
        read.ignore();
        getline(read, t.task);

        print(t);
        found = true;
    }

    if (!found) {
        cout << "\nNo tasks available!\n";
    }

    read.close();
}

int searchData(bool display = true) {
    int searchId;

    cout << "\nEnter Task ID: ";
    cin >> searchId;

    ifstream read("todo.txt");

    todo t;

    while (read >> t.id) {
        read >> t.completed;
        read.ignore();
        getline(read, t.task);

        if (t.id == searchId) {
            if (display)
                print(t);

            read.close();
            return searchId;
        }
    }

    read.close();

    cout << "\nNo task found with ID " << searchId << "!\n";
    return -1;
}

void deleteData() {
    int id = searchData();

    if (id == -1)
        return;

    char choice;

    cout << "\nDelete this task? (y/n): ";
    cin >> choice;

    if (choice != 'y' && choice != 'Y')
        return;

    ifstream read("todo.txt");
    ofstream temp("temp.txt");

    todo t;
    int newId = 1;

    while (read >> t.id) {
        read >> t.completed;
        read.ignore();
        getline(read, t.task);

        if (t.id != id) {
            t.id = newId++;

            temp << t.id << endl;
            temp << t.completed << endl;
            temp << t.task << endl;
        }
    }

    read.close();
    temp.close();

    remove("todo.txt");
    rename("temp.txt", "todo.txt");

    ID = newId - 1;

    ofstream idFile("id.txt");
    idFile << ID;
    idFile.close();

    cout << "\nTask Deleted Successfully!\n";
}

void markDone() {
    int id;

    cout << "\nEnter Task ID to mark as completed: ";
    cin >> id;

    ifstream read("todo.txt");
    ofstream temp("temp.txt");

    todo t;
    bool found = false;

    while (read >> t.id) {
        read >> t.completed;
        read.ignore();
        getline(read, t.task);

        if (t.id == id) {
            t.completed = true;
            found = true;
        }

        temp << t.id << endl;
        temp << t.completed << endl;
        temp << t.task << endl;
    }

    read.close();
    temp.close();

    remove("todo.txt");
    rename("temp.txt", "todo.txt");

    if (found)
        cout << "\nTask Marked as Completed!\n";
    else
        cout << "\nNo task found with ID " << id << "!\n";
}

int main() {
    ifstream idFile("id.txt");

    if (idFile.is_open())
        idFile >> ID;

    idFile.close();

    int choice;

    while (true) {
        cout << "\n\n=================================";
        cout << "\n          TODO LIST";
        cout << "\n=================================";
        cout << "\n1. Add Task";
        cout << "\n2. View Tasks";
        cout << "\n3. Search Task";
        cout << "\n4. Delete Task";
        cout << "\n5. Mark Task as Done";
        cout << "\n6. Exit";
        cout << "\n=================================";
        cout << "\nEnter Choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            addTodo();
            break;

        case 2:
            readData();
            break;

        case 3:
            searchData();
            break;

        case 4:
            deleteData();
            break;

        case 5:
            markDone();
            break;

        case 6:
            cout << "\nThank You For Using TODO LIST!\n";
            return 0;

        default:
            cout << "\nInvalid Choice!";
        }
    }

    return 0;
}