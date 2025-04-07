// Singly Linked List Guided Exercise
// Project: Contact List Manager
// Student name: Ronaldo Coc

#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    Contact* next;

    // add constructor here---
    Contact(string userName, string userPhone) {
        name = userName;
        phone = userPhone;
        next = nullptr;
    }
};

// Function prototypes
void insertAtBeginning(Contact*& head, string name, string phone);
void insertAtEnd(Contact*& head, string name, string phone);
void displayList(Contact* head);
Contact* searchByName(Contact* head, string name);
bool deleteByName(Contact*& head, string name);

int main() {

    Contact* head = nullptr;

    int choice;
    string name, phone;
    do {
        cout << "\nContact List Menu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Display Contacts\n";
        cout << "4. Search by Name\n";
        cout << "5. Delete by Name\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone: ";
                getline(cin, phone);
                insertAtBeginning(head, name, phone);
                break;
            case 2:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone: ";
                getline(cin, phone);
                insertAtEnd(head, name, phone);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                cout << "Enter name to search: ";
                getline(cin, name);
                {
                    Contact* found = searchByName(head, name);
                    if (found) {
                        cout << "Found: " << found->name << " - " << found->phone << endl;
                    } else {
                        cout << "Contact not found.\n";
                    }
                }
                break;
            case 5:
                cout << "Enter name to delete: ";
                getline(cin, name);
                if (deleteByName(head, name)) {
                    cout << "Deleted successfully.\n";
                } else {
                    cout << "Contact not found.\n";
                }
                break;
        }

    } while (choice != 6);

    return 0;
}

//My code for inserting at the beginning
void insertAtBeginning(Contact*& head, string name, string phone) {
    Contact* newHead = new Contact(name, phone);
    newHead->next = head;
    head = newHead;
    cout << "Your contact added at the top.\n";
}

//My code for inserting at the end
void insertAtEnd(Contact*& head, string name, string phone) {
    Contact* newContact = new Contact(name, phone);
    if (head == nullptr) {
        head = newContact;
    } else {
        Contact* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newContact;
    }
    cout << "Your contact added at the bottom.\n";
}

//My code for displaying all contacts
void displayList(Contact* head) {
    if (head == nullptr) {
        cout << "Your contact list is empty.\n";
        return;
    }
    Contact* current = head;
    while (current != nullptr) {
        cout << "Contact name: " << current->name << " Contact phone#: " << current->phone << endl;
        current = current->next;
    }
}

//My code for searchin contacts by its name
Contact* searchByName(Contact* head, string name) {
    Contact* current = head;
    while (current != nullptr) {
        if (current->name == name) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

//My code for deleting contacts by its name
bool deleteByName(Contact*& head, string name) {
    Contact* current = head;
    Contact* previous = nullptr;

    while (current != nullptr && current->name != name) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        return false;
    }

    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    return true;
}
