#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
    int val; 
} Node;


Node* newNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printNode (Node* root) {
    printf("[");
    if (root->left) {
        printf("%d <-- ",root->left->val);
    } else {
        printf("XX <-- ");
    }
    printf("%d", root->val);
    if (root->right) {
        printf(" --> %d",root->right->val);
    } else {
        printf(" --> XX");
    }
    printf("]");
}
int main() {
    int newNum;
    scanf("%d", &newNum);
    Node* node = newNode(newNum);
    printNode(node);
    free(node);
    return 0;
}