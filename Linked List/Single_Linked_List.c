#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to swap the data of two node
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}   

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the linked list
void addToBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end of the linked list
void addToEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to add a new node after the nth node in the linked list
void addAfterNthNode(struct Node** head, int n, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    if (n <= 0) {
        printf("Invalid index.\n");
        return;
    }
    
    struct Node* current = *head;
    for (int i = 1; current != NULL && i < n; ++i) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Index out of range.\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete the first node
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the last node
void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// Function to delete the nth node from the start of the linked list
void deleteNthNode(struct Node** head, int n) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    if (n <= 0) {
        printf("Invalid index.\n");
        return;
    }
    
    if (n == 1) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    struct Node* current = *head;
    for (int i = 1; current != NULL && i < n - 1; ++i) {
        current = current->next;
    }
    
    if (current == NULL || current->next == NULL) {
        printf("Index out of range.\n");
        return;
    }
    
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Function to merge two linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    struct Node* mergedList = NULL;
    if (list1->data < list2->data) {
        mergedList = list1;
        mergedList->next = mergeLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeLists(list1, list2->next);
    }
    return mergedList;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to sort the linked list using bubble sort
void bubbleSort(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    int swapped;
    struct Node* current;
    struct Node* last = NULL;

    swapped = 1; // Initialize swapped to any non-zero value to enter the loop
    while (swapped) {
        swapped = 0;
        current = *head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    }
}

// Function to reverse a linked list
void reverseList(struct Node** head) {
    struct Node* prevNode = NULL;
    struct Node* currentNode = *head;
    struct Node* nextNode = NULL;

    while (currentNode != NULL) {
        nextNode = currentNode->next; // Store the next node
        currentNode->next = prevNode; // Change next of current node
        prevNode = currentNode;       // Move prev to the current node
        currentNode = nextNode;       // Move current to the next node
    }

    *head = prevNode; // Update the head to the last node (new start of the list)
}

// Prints the operations menu
void printMenu() {
    printf("\nDoubly Linked List Operations:\n");
    printf("1. Add Node to List 1 (Beginning)\n");
    printf("2. Add Node to List 1 (End)\n");
    printf("3. Add Node after nth Node in List 1\n");
    printf("4. Delete First Node from List 1\n");
    printf("5. Delete Last Node from List 1\n");
    printf("6. Delete nth Node from List 1\n");
    printf("7. Reverse List 1\n");
    printf("8. Sort List 1\n");
    printf("9. Print List 1\n");
    printf("10. Add Node to List 2 (Beginning)\n");
    printf("11. Add Node to List 2 (End)\n");
    printf("12. Add Node after nth Node in List 2\n");
    printf("13. Delete First Node from List 2\n");
    printf("14. Delete Last Node from List 2\n");
    printf("15. Delete nth Node from List 2\n");
    printf("16. Reverse List 2\n");
    printf("17. Sort List 2\n");
    printf("18. Print List 2\n");
    printf("19. Merge Lists\n");
    printf("20. Add Node to Merged List (Beginning)\n");
    printf("21. Add Node to Merged List (End)\n");
    printf("22. Add Node after nth Node in Merged List\n");
    printf("23. Delete First Node from Merged List\n");
    printf("24. Delete Last Node from Merged List\n");
    printf("25. Delete nth Node from Merged List\n");
    printf("26. Reverse Merged List\n");
    printf("27. Sort Merged List\n");
    printf("28. Print Merged List\n");
    printf("29. Exit\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* mergedList = NULL;

    int choice, data, n;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addToBeginning(&list1, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                addToEnd(&list1, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter n: ");
                scanf("%d", &n);
                addAfterNthNode(&list1, n, data);
                break;
            case 4:
                deleteFirstNode(&list1);
                printf("First node deleted from List 1.\n");
                break;
            case 5:
                deleteLastNode(&list1);
                printf("Last node deleted from List 1.\n");
                break;
            case 6:
                printf("Enter n: ");
                scanf("%d", &n);
                deleteNthNode(&list1, n);
                printf("Node at position %d deleted from List 1.\n", n);
                break;
            case 7:
                reverseList(&list1);
                printf("List 1 reversed.\n");
                break;
            case 8:
                bubbleSort(&list1);
                printf("List 1 sorted.\n");
                break;
            case 9:
                printf("List 1: ");
                printList(list1);
                break;
            case 10:
                printf("Enter data: ");
                scanf("%d", &data);
                addToBeginning(&list2, data);
                break;
            case 11:
                printf("Enter data: ");
                scanf("%d", &data);
                addToEnd(&list2, data);
                break;
            case 12:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter n: ");
                scanf("%d", &n);
                addAfterNthNode(&list2, n, data);
                break;
            case 13:
                deleteFirstNode(&list2);
                printf("First node deleted from List 2.\n");
                break;
            case 14:
                deleteLastNode(&list2);
                printf("Last node deleted from List 2.\n");
                break;
            case 15:
                printf("Enter n: ");
                scanf("%d", &n);
                deleteNthNode(&list2, n);
                printf("Node at position %d deleted from List 2.\n", n);
                break;
            case 16:
                reverseList(&list2);
                printf("List 2 reversed.\n");
                break;
            case 17:
                bubbleSort(&list2);
                printf("List 2 sorted.\n");
                break;
            case 18:
                printf("List 2: ");
                printList(list2);
                break;
            case 19:
                mergedList = mergeLists(list1, list2);
                printf("Lists merged.\n");
                break;
            case 20:
                printf("Enter data: ");
                scanf("%d", &data);
                addToBeginning(&mergedList, data);
                break;
            case 21:
                printf("Enter data: ");
                scanf("%d", &data);
                addToEnd(&mergedList, data);
                break;
            case 22:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter n: ");
                scanf("%d", &n);
                addAfterNthNode(&mergedList, n, data);
                break;
            case 23:
                deleteFirstNode(&mergedList);
                printf("First node deleted from Merged List.\n");
                break;
            case 24:
                deleteLastNode(&mergedList);
                printf("Last node deleted from Merged List.\n");
                break;
            case 25:
                printf("Enter n: ");
                scanf("%d", &n);
                deleteNthNode(&mergedList, n);
                printf("Node at position %d deleted from Merged List.\n", n);
                break;
            case 26:
                reverseList(&mergedList);
                printf("Merged List reversed.\n");
                break;
            case 27:
                bubbleSort(&mergedList);
                printf("Merged List sorted.\n");
                break;
            case 28:
                printf("Merged List: ");
                printList(mergedList);
                break;
            case 29:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
