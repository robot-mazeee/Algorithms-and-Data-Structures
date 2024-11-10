#include <iostream>
#include <string>
using std::cout, std::string;

struct Node {
    int value;
    Node *next;
};

Node *create_new_node(int value) {
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        cout << current->value << " -> ";
        current = current->next;
    }
}

Node *add_to_start(Node *head, int value) {
    Node *new_node = create_new_node(value);

    if (head == NULL) head = new_node;
    else {
        new_node->next = head;
        head = new_node;
    }
    return head;
}

void add_to_end(Node **head, int value) {
    Node *current = *head;
    Node *new_node = create_new_node(value);

    if (*head == NULL) *head = new_node;
    else {
        while (current->next != NULL) current = current->next;
        current->next = new_node;
    }
}

void add_to_middle(Node **head, int value, int new_value) {
    Node *new_node = create_new_node(new_value);
    Node *current  = *head;

    if (*head == NULL) *head = new_node;
    else {
        while (current->next != NULL && current->value != value) 
            current = current->next;

        if (current->next == NULL && current->value != value) 
            cout << "Element not found\n";
        else if (current->next == NULL) current->next = new_node;
        else {
            new_node->next = current->next;
            current->next = new_node;
        }
    }
}

Node *remove(Node *head, int value) {
    Node *current = head, *prev = head;

    if (head == NULL) return NULL;
    else if (head->value == value) {
        current = head->next;
        delete head;
        return current;
    }
    else {
        while (current->next != NULL && current->value != value) {
            prev = current;
            current = current->next;
        }

        if (current->next == NULL && current->value != value) {
            return head;
        }
        else if (current->next == NULL) {
            prev->next = NULL;
            delete current;
        }
        else {
            prev->next = current->next;
            delete current;
        }

        return head;
    }
}

int main() {
    Node *head = create_new_node(10);
    head = add_to_start(head, 20);
    head = add_to_start(head, 30);
    add_to_end(&head, 25);
    add_to_end(&head, 32);
    add_to_middle(&head, 10, 23);
    head = remove(head, 10);

    print_list(head);

    return 0;
}