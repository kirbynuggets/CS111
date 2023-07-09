#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    int isbn;
    char title[50];
    char author[50];
    int quantity;
    struct book *left;
    struct book *right;
};

struct book* createBook(int isbn, char title[], char author[], int quantity) {
    struct book* newBook = (struct book*) malloc(sizeof(struct book));
    newBook->isbn = isbn;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->quantity = quantity;
    newBook->left = NULL;
    newBook->right = NULL;
    return newBook;
}

struct book* insertBook(struct book* root, int isbn, char title[], char author[], int quantity) {
    // If the root is NULL, create a new book node and return it
    if (root == NULL) {
        return createBook(isbn, title, author, quantity);
    }
    if (isbn < root->isbn) {
        root->left = insertBook(root->left, isbn, title, author, quantity);
    }

    else if (isbn > root->isbn) {
        root->right = insertBook(root->right, isbn, title, author, quantity);
    }

    else {
        root->quantity += quantity;
    }
    return root;
}

struct book* searchBook(struct book* root, int isbn) {
       if (root == NULL || root->isbn == isbn) {
        return root;
    }

    if (root->isbn > isbn) {
        return searchBook(root->left, isbn);
    }

    return searchBook(root->right, isbn);
}

void displayBook(struct book* root) {
    if (root != NULL) {
        displayBook(root->left);
        printf("ISBN: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\n\n", root->isbn, root->title, root->author, root->quantity);
        displayBook(root->right);
    }
}

void update_quantity(struct book* root, int isbn, int quantity) {
    struct book* bookNode = searchBook(root, isbn);
    if (bookNode != NULL) {
        bookNode->quantity = quantity;
        printf("The quantity of the book with ISBN %d has been updated to %d.\n", isbn, quantity);
    }
    else {
        printf("The book with ISBN %d was not found.\n", isbn);
    }
}

struct book* removeBook(struct book* root, int isbn) {
    if (root == NULL) {
        return root;
    }
    if (isbn < root->isbn) {
        root->left = removeBook(root->left, isbn);
    }
    else if (isbn > root->isbn) {
        root->right = removeBook(root->right, isbn);
    }

    else {

        if (root->left == NULL) {
            struct book* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct book* temp = root->left;
            free(root);
            return temp;
        }

        struct book* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->isbn = temp->isbn;
        strcpy(root->title, temp->title);
        strcpy(root->author, temp->author);
        root->quantity = temp->quantity;
        root->right = removeBook(root->right, temp->isbn);
    }
    return root;
}

// Main function
int main() {
    struct book* root = NULL;
    int choice, isbn, quantity;
    char title[50], author[50];
    while (1) {
        printf("1. Insert a book\n2. Search for a book\n3. Display all books\n4. Update book quantity\n5. Remove a book\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the ISBN of the book: ");
                scanf("%d", &isbn);
                printf("Enter the title of the book: ");
                scanf("%s", title);
                printf("Enter the author of the book: ");
                scanf("%s", author);
                printf("Enter the available quantity of the book: ");
                scanf("%d", &quantity);
                root = insertBook(root, isbn, title, author, quantity);
                printf("The book has been inserted.\n");
                break;
            case 2:
                printf("Enter the ISBN of the book to search for: ");
                scanf("%d", &isbn);
                struct book* bookNode = searchBook(root, isbn);
                if (bookNode != NULL) {
                    printf("ISBN: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\n", bookNode->isbn, bookNode->title, bookNode->author, bookNode->quantity);
                }
                else {
                    printf("The book with ISBN %d was not found.\n", isbn);
                }
                break;
            case 3:
                printf("All books in the library:\n");
                displayBook(root);
                break;
            case 4:
                printf("Enter the ISBN of the book whose quantity needs to be updated: ");
                scanf("%d", &isbn);
                printf("Enter the new quantity of the book: ");
                scanf("%d", &quantity);

            case 5:
                 printf("\nEnter the ISBN of the book to remove: ");
                scanf("%d", &isbn);
                root = removeBook(root, isbn);
                printf("\nBook removed successfully!\n");
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
            }
        }
        return 0;
}
