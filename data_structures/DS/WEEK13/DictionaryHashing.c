// Dictionary (ADT) using Hashing

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10  // size of hash table

// Structure for each key-value pair
struct DataItem
{
    char key[20];
    int value;
};

// Global hash table and dummy item
struct DataItem* hashTable[SIZE];
struct DataItem* dummyItem;

// Hash function: sum of ASCII values mod SIZE
int hashCode(char* key)
{
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++)
        sum += key[i];
    return sum % SIZE;
}

// Insert function
void insert(char* key, int value)
{
    struct DataItem* item = (struct DataItem*) malloc(sizeof(struct DataItem));
    strcpy(item->key, key);
    item->value = value;

    int hashIndex = hashCode(key);

    // Linear probing
    while (hashTable[hashIndex] != NULL && strcmp(hashTable[hashIndex]->key, "##DELETED##") != 0)
    {
        if (strcmp(hashTable[hashIndex]->key, key) == 0) {
            // Update existing key
            hashTable[hashIndex]->value = value;
            free(item);
            return;
        }
        hashIndex = (hashIndex + 1) % SIZE;
    }

    hashTable[hashIndex] = item;
}

// Search function
struct DataItem* search(char* key)
{
    int hashIndex = hashCode(key);

    while (hashTable[hashIndex] != NULL)
    {
        if (strcmp(hashTable[hashIndex]->key, key) == 0)
            return hashTable[hashIndex];
        hashIndex = (hashIndex + 1) % SIZE;
    }
    return NULL;
}

// Delete function
void deleteItem(char* key)
{
    int hashIndex = hashCode(key);

    while (hashTable[hashIndex] != NULL)
    {
        if (strcmp(hashTable[hashIndex]->key, key) == 0)
        {
            hashTable[hashIndex] = dummyItem;
            printf("Deleted key '%s'\n", key);
            return;
        }
        hashIndex = (hashIndex + 1) % SIZE;
    }
    printf("Key '%s' not found\n", key);
}

// Display function
void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] != NULL && strcmp(hashTable[i]->key, "##DELETED##") != 0)
            printf("[%d] => (%s, %d)\n", i, hashTable[i]->key, hashTable[i]->value);
        else
            printf("[%d] => ~~\n", i);
    }
    printf("\n");
}

// Main function with menu
int main()
{
    dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    strcpy(dummyItem->key, "##DELETED##");
    dummyItem->value = -1;

    int choice, value;
    char key[20];
    struct DataItem* item;

    while (1)
    {
        printf("\n\t DICTIONARY ADT (using Hashing)\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter key (string): ");
                scanf("%s", key);
                printf("Enter value (integer): ");
                scanf("%d", &value);
                insert(key, value);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%s", key);
                item = search(key);
                if (item != NULL)
                    printf("Found: (%s, %d)\n", item->key, item->value);
                else
                    printf("Key not found!\n");
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%s", key);
                deleteItem(key);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
