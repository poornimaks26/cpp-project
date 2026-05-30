//#include ".tests/main.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// vector to store tasks
vector<string> tasks;
// Integer vectors to store deadlines
vector<int> days, months, years;

// Complete the user_choice function--------------------------------------
string user_choice(int choice) {

   if(){  // if user choice 1

        // Call the 'add_task' function 
        ________

   }else if(_____){  // if user choice 2

        cout << "Enter task number to delete: ";

        // Take user input for 'task_number'
        ________

        // Delete task using 'delete_task' function
        ________

   }else if(_____){  // if user choice 3

        // Display all tasks using 'display_tasks' function
        ________

   }else if(_____){  // if user choice 4

        return "Exiting application. Goodbye!";

   }else{ // Handle invalid choices

        cout << "Invalid choice!\n\n";
        
   }
   return "";
}
//------------------------------------------------------------------------

bool validate_date(int day, int month, int year) {
    cout << "Function to validate the date\n";
}

void add_task() {
    cout << "Function to add a task\n";
}

void delete_task(int task_number) {
    cout << "Function to delete a task\n";
}

void display_tasks() {
    cout << "Function to display all tasks\n";
}

int main() {
    cout << "\nWelcome to the To-Do List Application!\n\n";

    while (true) {
        cout << "Choose one operation:\n";
        cout << "1. Add Task\n";
        cout << "2. Delete Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        string result = user_choice(choice);
        if (result == "Exiting application. Goodbye!") {
            cout << result << endl;
            break;
        }
    }
    return 0;
}