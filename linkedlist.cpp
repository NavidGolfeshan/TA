#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtTail(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at specific position (1-based)
    void insertAtPosition(int position, int value) {
        if (position <= 1) {
            insertAtHead(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        int current = 1;

        while (temp != nullptr && current < position - 1) {
            temp = temp->next;
            current++;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete first node
    void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete at specific position (1-based)
    void deleteAtPosition(int position) {
        if (position <= 1) {
            deleteHead();
            return;
        }

        Node* temp = head;
        int current = 1;

        while (temp != nullptr && current < position - 1) {
            temp = temp->next;
            current++;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Search for a value
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // Print the entire list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    cout << "Inserting values at head...\n";
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);
    list.printList();

    cout << "\nInserting at tail...\n";
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.printList();

    cout << "\nInsert 10 at position 3...\n";
    list.insertAtPosition(3, 10);
    list.printList();

    cout << "\nDelete head...\n";
    list.deleteHead();
    list.printList();

    cout << "\nDelete position 4...\n";
    list.deleteAtPosition(4);
    list.printList();

    cout << "\nSearch 10: ";
    cout << (list.search(10) ? "Found\n" : "Not Found\n");

    cout << "Search 99: ";
    cout << (list.search(99) ? "Found\n" : "Not Found\n");

    return 0;
}
