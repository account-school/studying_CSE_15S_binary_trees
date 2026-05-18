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


void insert(Node* root, Node* node2) {
    Node* originalRoot = root;
    printf("%d & %d\n",root->val,node2->val);
    if (root) {
        while (root->left || root->right) {
        //printf("midprocessing:: ");
        printNode(root);
        if (root->val > node2->val) {
            if (root->left) {
                root = root->left;
            } else {
                break;
            }
        } else {
            if (root->right) {
                root = root->right;
            } else {
                break;
            }
        }
    }
    }
    if (root->val > node2->val) {
        root->left = node2;
    } else {
        root->right = node2;
    }
    root = originalRoot;
}


void printTree(Node* root) {
    if (root) {
        //printNode(root);
        if (root->left) {
            printTree(root->left);
        }
        if (root) {
            printNode(root);
        }
        if (root->right){
            printTree(root->right);
        }
    }
}

int traverseTree(Node* root, int value) {
    Node* originalRoot = root;
    if (root) {
        while (root->left || root->right) {
            if (root->val == value) {
                return 1;
            }
            if (value > root->val) {
                if (root->right) {
                    root = root->right;
                } else {
                    break;
                }
            } else {
                if (root->left) {
                    root = root->left;
                } else {
                    break;
                }
            }
        }

    }

    if (root->val == value) {
        return 1;
    }

    root = originalRoot;
    return 0;
}

int main() {
    int newNum;
    scanf("%d", &newNum);
    Node* node = newNode(newNum);
    printNode(node);
    
    scanf("%d", &newNum);
    Node* node2 = newNode(newNum);
    insert(node,node2);
    printNode(node);
    printNode(node2);

    scanf("%d", &newNum);
    Node* node3 = newNode(newNum);
    insert(node,node3);
    printNode(node);
    printNode(node2);
    printNode(node3);

    scanf("%d", &newNum);
    Node* node4 = newNode(newNum);
    insert(node,node4);
    printNode(node);
    printNode(node2);
    printNode(node3);
    printNode(node4);

    scanf("%d", &newNum);
    Node* node5 = newNode(newNum);
    insert(node,node5);
    printNode(node);
    printNode(node2);
    printNode(node3);
    printNode(node4);
    printNode(node5);
    //printNode(node);

    //printNode(node->left);
    //printNode(node->right);
    //free(node);
    //free(node2);
    printf("\n start print\n\n");
    printTree(node);
    printf("\n\nNumber to search?:: ");
    scanf("%d", &newNum);
    printf("result: %d",traverseTree(node,newNum));
    return 0;
}