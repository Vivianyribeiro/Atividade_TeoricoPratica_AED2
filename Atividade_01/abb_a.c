#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct Node {
    int key;
    char *data;
    struct Node *left;
    struct Node *right;
} Node;

// Função para criar um novo nó
Node *createNode(int key, char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um novo nó na árvore
Node *insert(Node *root, int key, char *data) {
    if (!root) {
        return createNode(key, data);
    }

    if (key < root->key) {
        root->left = insert(root->left, key, data);
    } else if (key > root->key) {
        root->right = insert(root->right, key, data);
    } else {
        printf("Chave já existente na árvore.\n");
        exit(EXIT_FAILURE);
    }

    return root;
}

// Função para realizar o percurso em ordem (inorder traversal)
void inorderTraversal(Node *root) {
    if (root) {
        inorderTraversal(root->left);
        printf("(%d, %s) ", root->key, root->data);
        inorderTraversal(root->right);
    }
}

// Função para liberar a memória alocada para a árvore
void freeTree(Node *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Exemplo de uso
int main() {
    Node *root = NULL;
    root = insert(root, 10, "Dado 10");
    insert(root, 5, "Dado 5");
    insert(root, 15, "Dado 15");
    insert(root, 3, "Dado 3");
    insert(root, 7, "Dado 7");
    insert(root, 12, "Dado 12");
    insert(root, 17, "Dado 17");

    printf("Inorder Traversal:\n");
    inorderTraversal(root);
    printf("\n");

    freeTree(root); // Liberar memória alocada para a árvore

    return 0;
}
