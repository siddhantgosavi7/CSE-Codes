#include <stdio.h>

#include <stdlib.h>

struct Node {

    int data;

    struct Node *left, *right;

};

struct Node* createNode(int key) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = key;

    newNode->left = newNode->right = NULL;

    return newNode;

}

struct Node* insert(struct Node* root, int key) {

    if (root == NULL) return createNode(key);

    if (key < root->data)

        root->left = insert(root->left, key);

    else if (key > root->data)

        root->right = insert(root->right, key);

    return root;

}

int search(struct Node* root, int key) {

    if (root == NULL) return 0;

    if (root->data == key) return 1;

    if (key < root->data) return search(root->left, key);

    return search(root->right, key);

}

struct Node* findMin(struct Node* node) {

    struct Node* current = node;

    while (current && current->left != NULL)

        current = current->left;

    return current;

}

struct Node* deleteNode(struct Node* root, int key) {

    if (root == NULL) return root;

    if (key < root->data)

        root->left = deleteNode(root->left, key);

    else if (key > root->data)

        root->right = deleteNode(root->right, key);

    else {

        if (root->left == NULL) {

            struct Node* temp = root->right;

            free(root);

            return temp;

        } else if (root->right == NULL) {

            struct Node* temp = root->left;

            free(root);

            return temp;

        }

        struct Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);

    }

    return root;

}

void inorder(struct Node* root) {

    if (root != NULL) {

        inorder(root->left);

        printf("%d ", root->data);

        inorder(root->right);

    }

}

void preorder(struct Node* root) {

    if (root != NULL) {

        printf("%d ", root->data);

        preorder(root->left);

        preorder(root->right);

    }

}

void postorder(struct Node* root) {

    if (root != NULL) {

        postorder(root->left);

        postorder(root->right);

        printf("%d ", root->data);

    }

}

int main() {

    struct Node* root = NULL;

    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)

        root = insert(root, keys[i]);

    printf("Inorder traversal: ");

    inorder(root);

    printf("\nPreorder traversal: ");

    preorder(root);

    printf("\nPostorder traversal: ");

    postorder(root);

    printf("\n\nSearch 40: %s\n", search(root, 40) ? "Found" : "Not Found");

    printf("Deleting 50 (Root with two children)...\n");

    root = deleteNode(root, 50);

    printf("Inorder after deletion: ");

    inorder(root);

    printf("\n");

    return 0;

}
