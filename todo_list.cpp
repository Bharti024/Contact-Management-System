#include <iostream>
#include <mysql/mysql.h>  

using namespace std;

MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

// Function to connect to MySQL database
void connectToDatabase() {
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "yourpassword", "todo_db", 3306, NULL, 0);

    if (conn) {
        cout << "Connected to MySQL Database successfully!\n";
    } else {
        cout << "Failed to connect to MySQL!\n";
        exit(1);
    }
}

// Function to insert a new task
void insertTask() {
    string task;
    cout << "Enter a new task: ";
    cin.ignore();
    getline(cin, task);

    string query = "INSERT INTO tasks (task) VALUES ('" + task + "');";
    int qstate = mysql_query(conn, query.c_str());

    if (!qstate) {
        cout << "Task added successfully!\n";
    } else {
        cout << "Failed to add task!\n";
    }
}

// Function to display all tasks
void displayTasks() {
    string query = "SELECT * FROM tasks;";
    int qstate = mysql_query(conn, query.c_str());

    if (!qstate) {
        res = mysql_store_result(conn);
        cout << "To-Do List Tasks:\n";
        while ((row = mysql_fetch_row(res))) {
            cout << "ID: " << row[0] << " - Task: " << row[1] << endl;
        }
    } else {
        cout << "Failed to fetch tasks!\n";
    }
}

// Function to delete a task
void deleteTask() {
    int id;
    cout << "Enter Task ID to delete: ";
    cin >> id;

    string query = "DELETE FROM tasks WHERE id = " + to_string(id) + ";";
    int qstate = mysql_query(conn, query.c_str());

    if (!qstate) {
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Failed to delete task!\n";
    }
}

// Main function
int main() {
    connectToDatabase();

    int choice;
    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Delete Task\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertTask(); break;
            case 2: displayTasks(); break;
            case 3: deleteTask(); break;
            case 4: mysql_close(conn); exit(0);
            default: cout << "Invalid choice!\n";
        }
    }
    return 0;
}