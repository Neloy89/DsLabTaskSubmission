#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void addFront(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = nullptr;

    if ((*head_ref) != nullptr) {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node;
}

void addAfter(Node* prev_node, int new_data) {
    if (prev_node == nullptr) {
        cout << "The given previous node cannot be NULL" << endl;
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

    new_node->prev = prev_node;

    if (new_node->next != nullptr) {
        new_node->next->prev = new_node;
    }
}

void addEnd(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        new_node->prev = nullptr;
        *head_ref = new_node;
        return;
    }

    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void deleteFront(Node** head_ref) {
    if (*head_ref == nullptr) {
        cout << "The list is already empty." << endl;
        return;
    }

    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;

    if (*head_ref != nullptr) {
        (*head_ref)->prev = nullptr;
    }

    delete temp;
}

void deleteAfter(Node* prev_node) {
    if (prev_node == nullptr || prev_node->next == nullptr) {
        cout << "Cannot perform deletion. Either the previous node is null or it's the last node." << endl;
        return;
    }

    Node* temp = prev_node->next;
    prev_node->next = temp->next;

    if (temp->next != nullptr) {
        temp->next->prev = prev_node;
    }

    delete temp;
}

void deleteEnd(Node** head_ref) {
    if (*head_ref == nullptr) {
        cout << "The list is already empty." << endl;
        return;
    }

    Node* last = *head_ref;
    while (last->next != nullptr) {
        last = last->next;
    }

    if (last->prev != nullptr) {
        last->prev->next = nullptr;
    } else {
        *head_ref = nullptr;
    }

    delete last;
}


void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    addEnd(&head, 1);
    addFront(&head, 2);
    addEnd(&head, 3);
    addAfter(head->next, 4);

    cout << "Linked List before deletions: ";
    printList(head);


    deleteFront(&head);
    deleteAfter(head);
    deleteEnd(&head);

    cout << "Linked List after deletions: ";
    printList(head);

    return 0;
}

