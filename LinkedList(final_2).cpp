#include <iostream>
#include <cassert>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

void addfront(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void addafter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void addend(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        delete temp;
        return;
    } else {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        prev->next = temp->next;
        delete temp;
    }
}

int GetNth(Node* head, int index) {
    Node* current = head;
    int count = 0;

    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }

    assert(0);
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr;

    addfront(&head, 4);
    addfront(&head, 6);
    addfront(&head, 8);

    Node* middleNode = head->next;
    addafter(middleNode, 4);

    addend(&head, 5);

    deleteNode(&head, 6);

    int index = 2;
    int dataAtIndex = GetNth(head, index);

    cout << "Final List: ";
    printList(head);

    cout << "Data at index " << index << ": " << dataAtIndex << endl;

    return 0;
}
