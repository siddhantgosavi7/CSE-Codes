#include<stdio.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* newNode(int x) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* Tree, int val) {
    if(Tree == NULL) {
        newNode(val);
        return Tree;
    }

    if(val < Tree->data) {
        insert(Tree->left, val);
    } else if(val > Tree->data) {
        insert(Tree->right, val);
    } else {
        printf("Invalid! %d", val);
    }

    return Tree;
}

int search(struct TreeNode* Tree, int val) {
    if(Tree->data == val) {
        printf("Value %d found!", val);
        return 1;
    } else if(Tree->data == NULL) {
        return 0;
    }

    if(val < Tree->data) {
        search(Tree->left, val);
    }else if(val > Tree->data) {
        search(Tree->right, val);
    }
}

void deleted() {
    return;
}


void inOrdered(struct TreeNode* Tree) {
    if(Tree == NULL) return;
    
    inOrdered(Tree->left);
    printf("%d ", Tree->data);
    inOrdered(Tree->right);
}


void preOrdered(struct TreeNode* Tree) {
    if(Tree == NULL) return;
    
    printf("%d ", Tree->data);
    inOrdered(Tree->left);
    inOrdered(Tree->right);
}


void postOrdered(struct TreeNode* Tree) {
    if(Tree == NULL) return;
    
    inOrdered(Tree->left);
    inOrdered(Tree->right);
    printf("%d ", Tree->data);
}

int main() {
    


    return 0;
}