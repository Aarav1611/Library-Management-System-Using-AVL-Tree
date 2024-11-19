#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    char author[100];
    int availableCopies;
} Book;

typedef struct Node {
    Book book;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Function to get height of a node
int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to get the balance factor of a node
int getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Right rotation to balance the AVL tree
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    // Perform rotation
    x->right = y;
    y->left = T2;
    
    // Update heights
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    
    return x;
}

// Left rotation to balance the AVL tree
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    // Perform rotation
    y->left = x;
    x->right = T2;
    
    // Update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    
    return y;
}

// Function to insert a book into the AVL tree
Node* insert(Node* node, Book book) {
    // Step 1: Perform the normal BST insert
    if (node == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->book = book;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }
    
    if (strcmp(book.title, node->book.title) < 0) {
        node->left = insert(node->left, book);
    } else if (strcmp(book.title, node->book.title) > 0) {
        node->right = insert(node->right, book);
    } else {
        // If the book already exists, just update the availableCopies
        node->book.availableCopies += book.availableCopies;
        return node;
    }

    // Step 2: Update height of this ancestor node
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // Step 3: Get the balance factor to check whether this node became unbalanced
    int balance = getBalance(node);

    // If the node becomes unbalanced, then there are 4 cases
    
    // Left Left Case
    if (balance > 1 && strcmp(book.title, node->left->book.title) < 0) {
        return rightRotate(node);
    }
    
    // Right Right Case
    if (balance < -1 && strcmp(book.title, node->right->book.title) > 0) {
        return leftRotate(node);
    }
    
    // Left Right Case
    if (balance > 1 && strcmp(book.title, node->left->book.title) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // Right Left Case
    if (balance < -1 && strcmp(book.title, node->right->book.title) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to delete a book from the AVL tree
Node* deleteNode(Node* root, char* title) {
    // Step 1: Perform the normal BST delete
    if (root == NULL) {
        return root;
    }
    
    if (strcmp(title, root->book.title) < 0) {
        root->left = deleteNode(root->left, title);
    } else if (strcmp(title, root->book.title) > 0) {
        root->right = deleteNode(root->right, title);
    } else {
        // This is the book to be deleted
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            // Get the inorder successor (smallest in the right subtree)
            Node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            
            // Copy the inorder successor's data to this node
            root->book = temp->book;
            
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->book.title);
        }
    }

    if (root == NULL) {
        return root;
    }

    // Step 2: Update height of the current node
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    // Step 3: Get the balance factor to check whether this node became unbalanced
    int balance = getBalance(root);

    // Step 4: Rebalance the node if unbalanced
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
    
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
    
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal to display the books
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Title: %s, Author: %s, Available Copies: %d\n", root->book.title, root->book.author, root->book.availableCopies);
        inorder(root->right);
    }
}

// Main function to interact with the library management system
int main() {
    Node* root = NULL;
    Book book1 = {"The Catcher in the Rye", "J.D. Salinger", 3};
    Book book2 = {"To Kill a Mockingbird", "Harper Lee", 5};
    Book book3 = {"1984", "George Orwell", 2};
    
    root = insert(root, book1);
    root = insert(root, book2);
    root = insert(root, book3);
    
    printf("Library Books:\n");
    inorder(root);
    
    // Remove a book
    printf("\nRemoving '1984' from the library:\n");
    root = deleteNode(root, "1984");
    inorder(root);
    
    return 0;
}
