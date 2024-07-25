#include <iostream> // Include standard input-output library
#include <cstdlib> // Include standard library for functions like rand()
#include <cmath> // Include cmath library for mathematical functions
#include <bits/stdc++.h> // Include all standard libraries (for maps, vectors, etc.)
#include <ctime> // Include library for handling date and time

using namespace std;

// Task Class
class Task {
public:
    string description;
    string category;
    bool completed;
    string dueDate; // TAKEN FROM SYSTEM TODAY();
    string priority; // LOW MEDIUM

    Task(string description, string category, string priority, string dueDate) {
        this->description = description;
        this->category = category;
        this->dueDate = dueDate;
        this->priority = priority;
        this->completed = false;
    }
};

// Global Variables
stack<Task> undoStack;
vector<Task> NotesAdded;
vector<string> categories = {"Work", "Personal", "Study", "Shopping", "Other"};

// Function to compare tasks by due date
bool compareByDueDate(const Task &a, const Task &b) {
    return a.dueDate < b.dueDate;
}

// Display Tasks
void displayTasks() {
    if (NotesAdded.empty()) {
        cout << "Please add some task first to View";
    } else {
        cout << "\nTasks:\n";
        cout << "   " << "Task" << " " << "Category" << " " << "Priority" << " " << "DueDate" << " " << "Status" << "\n";
        for (int i = 0; i < NotesAdded.size(); i++) {
            cout << i + 1 << ". "
                 << NotesAdded[i].description << " "
                 << NotesAdded[i].category << " "
                 << NotesAdded[i].priority << " "
                 << NotesAdded[i].dueDate << " "
                 << (NotesAdded[i].completed ? "Completed" : "Pending") << "\n";
        }
    }
}

// Mark Task as Completed
void markTaskAsCompleted() {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= NotesAdded.size()) {
        NotesAdded[taskNumber - 1].completed = true;
    } else {
        cout << "Invalid Task Number\n";
    }
}

// Delete Task
void deleteTask() {
    int taskNumber;
    cout << "Enter the task number to delete: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= NotesAdded.size()) {
        Task task = NotesAdded[taskNumber - 1];
        undoStack.push(task);
        NotesAdded.erase(NotesAdded.begin() + taskNumber - 1);
        cout << "Task deleted successfully.\n";
    } else {
        cout << "Invalid Task Number\n";
    }
}

// Undo Delete
void undoDelete() {
    if (!undoStack.empty()) {
        Task lastTask = undoStack.top();
        undoStack.pop();
        NotesAdded.push_back(lastTask);
        cout << "Last deleted task restored.\n";
    } else {
        cout << "Nothing to Undo\n";
    }
}

// Add Task
void addTask() {
    string description, category, priority;
    cout << "Enter the Description: ";
    cin.ignore();
    getline(cin, description);
    auto now = time(nullptr);
    tm* current = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", current);
    string dueDate(buffer);

    cout << "Choose a category: \n";
    for (size_t i = 0; i < categories.size(); ++i) {
        cout << i + 1 << ". " << categories[i] << endl;
    }

    int categoryChoice;
    cin >> categoryChoice;
    if (categoryChoice > 0 && categoryChoice <= categories.size()) {
        category = categories[categoryChoice - 1];
    } else {
        cout << "Invalid choice, defaulting to 'Other'\n";
        category = "Other";
    }

    cout << "Enter priority (HIGH/LOW/MEDIUM): ";
    cin >> priority;

    Task task(description, category, priority, dueDate);
    NotesAdded.push_back(task);
}

// Edit Task
void editTask() {
    int taskNumber;
    cout << "Enter the task number to edit: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= NotesAdded.size()) {
        string description, category, priority;
        cout << "Enter the new Description: ";
        cin.ignore();
        getline(cin, description);

        cout << "Choose a new category: \n";
        for (size_t i = 0; i < categories.size(); ++i) {
            cout << i + 1 << ". " << categories[i] << endl;
        }

        int categoryChoice;
        cin >> categoryChoice;
        if (categoryChoice > 0 && categoryChoice <= categories.size()) {
            category = categories[categoryChoice - 1];
        } else {
            cout << "Invalid choice, defaulting to 'Other'\n";
            category = "Other";
        }

        cout << "Enter new priority (HIGH/LOW/MEDIUM): ";
        cin >> priority;

        auto now = time(nullptr);
        tm* current = localtime(&now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", current);
        string dueDate(buffer);

        NotesAdded[taskNumber - 1].description = description;
        NotesAdded[taskNumber - 1].category = category;
        NotesAdded[taskNumber - 1].priority = priority;
        NotesAdded[taskNumber - 1].dueDate = dueDate;

        cout << "Task edited successfully.\n";
    } else {
        cout << "Invalid Task Number\n";
    }
}

// Sort Tasks By Due Date
void sortTasksByDueDate() {
    sort(NotesAdded.begin(), NotesAdded.end(), compareByDueDate);
    cout << "Tasks sorted by due date.\n";
}

// Filter Tasks by Completion Status
void filterTasksByStatus() {
    int statusChoice;
    cout << "Enter 1 to view completed tasks or 0 to view pending tasks: ";
    cin >> statusChoice;
    bool completed = (statusChoice == 1);

    cout << "\nTasks:\n";
    cout << "   " << "Task" << " " << "Category" << " " << "Priority" << " " << "DueDate" << " " << "Status" << "\n";
    for (int i = 0; i < NotesAdded.size(); i++) {
        if (NotesAdded[i].completed == completed) {
            cout << i + 1 << ". "
                 << NotesAdded[i].description << " "
                 << NotesAdded[i].category << " "
                 << NotesAdded[i].priority << " "
                 << NotesAdded[i].dueDate << " "
                 << (NotesAdded[i].completed ? "Completed" : "Pending") << "\n";
        }
    }
}

// Display Menu
void displayMenu() {
    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Task\n"
             << "3. Mark Task as Completed\n"
             << "4. Delete Task\n"
             << "5. Edit Task\n"
             << "6. Sort Tasks By Due Date\n"
             << "7. Filter Tasks By Completion Status\n"
             << "8. Undo Delete\n"
             << "9. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                editTask();
                break;
            case 6:
                sortTasksByDueDate();
                break;
            case 7:
                filterTasksByStatus();
                break;
            case 8:
                undoDelete();
                break;
            case 9:
                cout << "Goodbye! Please do the tasks on time.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 9);
}

// Main Function
int main() {
    displayMenu();
    return 0;
}

