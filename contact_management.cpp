#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

// Function to add a contact
void addContact() {
    ofstream file("contacts.txt", ios::app);
    Contact contact;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, contact.name);

    cout << "Enter Phone Number: ";
    cin >> contact.phone;

    cout << "Enter Email: ";
    cin >> contact.email;

    file << contact.name << "," << contact.phone << "," << contact.email << endl;
    file.close();
    
    cout << "Contact added successfully!\n";
}

// Function to view all contacts
void viewContacts() {
    ifstream file("contacts.txt");
    string line;
    int count = 1;

    cout << "\nYour Contacts:\n";
    while (getline(file, line)) {
        cout << count++ << ". " << line << endl;
    }
    file.close();
}

// Function to search for a contact
void searchContact() {
    ifstream file("contacts.txt");
    string line, searchName;
    bool found = false;

    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, searchName);

    while (getline(file, line)) {
        if (line.find(searchName) != string::npos) {
            cout << "Contact Found: " << line << endl;
            found = true;
        }
    }
    file.close();

    if (!found) {
        cout << "No contact found with the name: " << searchName << endl;
    }
}

// Function to delete a contact
void deleteContact() {
    ifstream file("contacts.txt");
    vector<string> contacts;
    string line, deleteName;
    bool found = false;

    while (getline(file, line)) {
        contacts.push_back(line);
    }
    file.close();

    if (contacts.empty()) {
        cout << "No contacts to delete!\n";
        return;
    }

    cout << "Enter name to delete: ";
    cin.ignore();
    getline(cin, deleteName);

    ofstream outFile("contacts.txt");
    for (string contact : contacts) {
        if (contact.find(deleteName) == string::npos) {
            outFile << contact << endl;
        } else {
            found = true;
        }
    }
    outFile.close();

    if (found) {
        cout << "Contact deleted successfully!\n";
    } else {
        cout << "No contact found with the name: " << deleteName << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}
