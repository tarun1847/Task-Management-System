# Task Management System

A simple C++ task management system for managing tasks with features like adding, deleting, and viewing tasks, as well as marking tasks as completed. It also supports filtering tasks by completion status and undoing deleted tasks.

## Features

- **Add Task**: Add a new task with a description, category, priority, and due date.
- **View Tasks**: Display all tasks with details including status.
- **Mark Task as Completed**: Mark a task as completed.
- **Delete Task**: Remove a task from the list and move it to an undo stack.
- **Undo Delete**: Restore the last deleted task.
- **Filter Tasks**: Filter tasks by completion status (completed or pending).
- **Menu Navigation**: Easy navigation through a menu system for different functionalities.

## Classes and Functions

### `Task`

Represents a task with the following attributes:
- `description`: Description of the task.
- `category`: Category of the task (e.g., Work, Personal).
- `completed`: Status indicating whether the task is completed or pending.
- `dueDate`: Due date of the task.
- `priority`: Priority level of the task (HIGH/LOW/MEDIUM).

### `displayTasks()`

Displays all tasks with details such as description, category, priority, due date, and status.

### `markTaskAsCompleted()`

Marks a task as completed based on the task number provided by the user.

### `deleteTask()`

Deletes a task based on the task number and moves it to the undo stack.

### `undoDelete()`

Restores the last deleted task from the undo stack.

### `addtask()`

Prompts the user to enter details for a new task and adds it to the task list.

### `filterTasksByStatus()`

Filters and displays tasks based on their completion status (completed or pending).

### `displayMenu()`

Displays the main menu and handles user choices for various functionalities such as adding tasks, viewing tasks, and more.

## Example with the Format of Input
- Menu:
1. Add Task
2. View Task
3. Mark Task as Completed
4. Delete Task
5. Edit Task
6. Sort Tasks By Due Date
7. Filter Tasks By Completion Status
8. Undo Delete
9. Exit
- Enter your choice: 1

- Enter the Description:
Finish homework
- Choose a category: 
1. Work
2. Personal
3. Study
4. Shopping
5. Other
- Enter category number: 3
- Enter priority (HIGH/LOW/MEDIUM): HIGH
