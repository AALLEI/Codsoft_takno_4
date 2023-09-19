#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to display tasks from "data.txt" file
void displayTasks() {
    ifstream file("data.txt");
    string task;
    int taskNumber = 1;

    cout << endl;
    cout << " TASK LIST :\n";
    cout << endl;

    while (getline(file, task)) {
        cout << taskNumber << ". " << task << endl;
        taskNumber++;
    }
}

// Function to add a task to the "data.txt" file
void addTask() {
    ofstream file("data.txt", ios::app);
    string task;

    cout << "ENTER TASK OR TYPE '/' to finish: ";
    cin.ignore();
    getline(cin, task);

    if (task != "/") {
        file << task << endl;
        cout << "TASK ADDED!\n";
    }
}

// Function to remove a task from the "data.txt" file
void removeTask() {
    int number;
    displayTasks();
    cout << "Enter the task number to remove: ";
    cin >> number;

    ifstream inputFile("data.txt");
    ofstream outputFile("temp.txt");

    string task;
    int taskNumber = 1;

    while (getline(inputFile, task)) {
        if (taskNumber != number) {
            outputFile << task << endl;
        }
        taskNumber++;
    }

    inputFile.close();
    outputFile.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    cout << "Task removed!\n";
}

// Function to view tasks with their status (completed or pending)
void viewTasksWithStatus() {
    ifstream file("data.txt");
    string task;
    int taskNumber = 1;

    cout << endl;
    cout << " TASK LIST WITH STATUS :\n";
    cout << endl;

    while (getline(file, task)) {
        cout << taskNumber << ". ";
        if (task.find("[completed]") != string::npos) {
            // If the task contains "[completed]", it's marked as completed
        }
        else {
            cout << "[pending]  ";
        }
        cout << task << endl;
        taskNumber++;
    }
}

// Function to mark a task as completed in the "data.txt" file
void markTaskAsCompleted() {
    int number;
    displayTasks();
    cout << "Enter the task number to mark as completed: ";
    cin >> number;

    ifstream inputFile("data.txt");
    ofstream outputFile("temp.txt");

    string task;
    int taskNumber = 1;

    while (getline(inputFile, task)) {
        if (taskNumber == number) {
            task = "[completed] " + task;
        }
        outputFile << task << endl;
        taskNumber++;
    }

    inputFile.close();
    outputFile.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    cout << "Task marked as completed!\n";
}

int main() {
    char choice;

    cout << "TASK MANAGEMENT SYSTEM\n";
    do {
        cout << "\nPress 1 to Add a Task\n";
        cout << "Press 2 to Remove a Task\n";
        cout << "Press 3 to View Tasks with Status\n";
        cout << "Press 4 to Mark a Task as Completed\n";
        cout << "Press 5 to Display Tasks\n";
        cout << "Press 6 to Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            addTask();
            break;
        case '2':
            removeTask();
            break;
        case '3':
            viewTasksWithStatus();
            break;
        case '4':
            markTaskAsCompleted();
            break;
        case '5':
            displayTasks();
            break;
        case '6':
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        system("pause");
        system("cls");
    } while (choice != '6');

    return 0;
}
