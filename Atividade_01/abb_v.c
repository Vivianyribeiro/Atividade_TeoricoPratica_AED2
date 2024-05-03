#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct {
    int key;
    char *data;
    int left;
    int right;
} Node;

Node tree[MAX_NODES];
int root = -1;
int nextAvailableIndex = 0;

void initTree() {
    for (int i = 0; i < MAX_NODES; i++) {
        tree[i].key = -1;
        tree[i].left = -1;
        tree[i].right = -1;
    }
}

int insert(int key, char *data) {
    if (nextAvailableIndex >= MAX_NODES) {
        printf("Árvore estática cheia.\n");
        exit(EXIT_FAILURE);
    }

    int newNodeIndex = nextAvailableIndex++;
    tree[newNodeIndex].key = key;
    tree[newNodeIndex].data = data;
    tree[newNodeIndex].left = -1;
    tree[newNodeIndex].right = -1;

    if (root == -1) {
        root = newNodeIndex;
    } else {
        int current = root;
        while (1) {
            if (key < tree[current].key) {
                if (tree[current].left == -1) {
                    tree[current].left = newNodeIndex;
                    break;
                } else {
                    current = tree[current].left;
                }
            } else if (key > tree[current].key) {
                if (tree[current].right == -1) {
                    tree[current].right = newNodeIndex;
                    break;
                } else {
                    current = tree[current].right;
                }
            } else {
                printf("Chave já existente na árvore.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    return newNodeIndex;
}

void inorderTraversal(int index) {
    if (index != -1) {
        inorderTraversal(tree[index].left);
        printf("(%d, %s) ", tree[index].key, tree[index].data);
        inorderTraversal(tree[index].right);
    }
}

int main() {
    initTree();

    insert(10, "Dado 10");
    insert(5, "Dado 5");
    insert(15, "Dado 15");
    insert(3, "Dado 3");
    insert(7, "Dado 7");
    insert(12, "Dado 12");
    insert(17, "Dado 17");

    printf("Inorder Traversal (Estático): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
