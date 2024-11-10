#include <iostream>
using std::cout;

struct Node{
    int value;
    Node *left;
    Node *right;
};

Node *create_new_node(int value) {
    Node *new_node = new Node;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node *insert(int value, Node *root) {
    if (root == NULL) return create_new_node(value);
    else if (value < root->value) root->left = insert(value, root->left);
    else if (value > root->value) root->right = insert(value, root->right);
    return root;
}

Node *search(int value, Node *root) {
    if (root == NULL) return NULL;
    if (root->value == value) return root;
    else if (value < root->value) return search(value, root->left);
    else return search(value, root->right);
}

Node *max(Node *root) {
    if (root->right != NULL) return max(root->right);
    return root;
}

Node *min(Node *root) {
    if (root->left != NULL) return min(root->left);
    return root;
}

Node *remove(int value, Node *root) {
    if (root == NULL) return NULL;
    else if (value < root->value) root->left = remove(value, root->left);
    else if (value > root->value) root->right = remove(value, root->right);

    else {
        Node *aux;
        if (root->left != NULL && root->right != NULL) {
            aux = max(root->left);
            root->value = aux->value;
            aux->value = value;
            root->left = remove(value, root->left);
        }
        else {
            aux = root;
            if (root->left == NULL && root->right == NULL) root = NULL;
            else if (root->left == NULL) root = root->right;
            else root = root->left;
            delete aux; 
        }
    }
    return root;
}

void traverse(Node *root) {
    if (root == NULL) return;
    traverse(root->left);
    cout << root->value << '\n';
    traverse(root->right);
}

int main() {
    Node *root = NULL;

    root = insert(10, root);
    root = insert(22, root);
    root = insert(6, root);
    root = insert(15, root);
    root = insert(2, root);
    root = insert(15, root);
    // root = remove(6, root);

    // cout << search(2, root)->value;

    traverse(root);

    return 0;
}