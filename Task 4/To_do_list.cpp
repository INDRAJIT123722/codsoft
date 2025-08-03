#include <iostream>
#include <windows.h>
using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

void display_tasks(Task tasks[], int task_count) {
    cout << "Tasks To do\n";
    cout << "-------------\n";
    for (int i = 0; i < task_count; i++) {
        cout << i + 1 << ". " << tasks[i].description 
             << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
    cout << "-------------\n";
}

int main() {
    system("color a");
    Task tasks[10];
    int task_count = 0;
    int option = -1;

    while (option != 0) {
        cout << "\n--- To Do List ---\n";
        cout << "1. Add New Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Remove Task\n";
        cout << "4. Mark Task as Completed\n";
        cout << "0. Exit Program\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
        case 1: {
            if (task_count > 9) {
                cout << "-- TASK LIST IS FULL --\n";
            } else {
                cout << "Enter a new Task: ";
                cin.ignore();
                getline(cin, tasks[task_count].description);
                tasks[task_count].isCompleted = false; // default: pending
                task_count++;
            }
            break;
        }
        case 2: {
            system("cls");
            display_tasks(tasks, task_count);
            break;
        }
        case 3: {
            system("cls");
            display_tasks(tasks, task_count);
            int del_task;
            cout << "Enter task number to delete: ";
            cin >> del_task;

            if (del_task < 1 || del_task > task_count) {
                cout << "Invalid task number.\n";
                break;
            }

            for (int i = del_task - 1; i < task_count - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            task_count--;
            cout << "Task deleted successfully.\n";
            break;
        }
        case 4: {
            system("cls");
            display_tasks(tasks, task_count);
            int complete_task;
            cout << "Enter task number to mark as completed: ";
            cin >> complete_task;

            if (complete_task < 1 || complete_task > task_count) {
                cout << "Invalid task number.\n";
                break;
            }

            tasks[complete_task - 1].isCompleted = true;
            cout << "Task marked as completed.\n";
            break;
        }
        case 0:
            cout << "Terminating the Program...\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}