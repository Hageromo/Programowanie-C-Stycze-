#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int Value;
    Node *Next;
};

Node *Create(int value) {
    Node *created = (Node *) malloc(sizeof(Node));
    created->Value = value;
    created->Next = created;

    return created;
}

Node *GetTail(Node *root) {
    Node *current = root;

    while (current->Next != root)
        current = current->Next;

    return current;
}

void Add(Node *root, int value) {
    Node *tail = GetTail(root);
    Node *added = (Node *) malloc(sizeof(Node));
    added->Value = value;
    tail->Next = added;
    added->Next = root;
}

void PrintList(Node *root) {
    if (root) {
        Node *current = root;
        while (current->Next != root) {
            printf("%d, ", current->Value);
            current = current->Next;
        }
        printf("%d\n", current->Value);
    }
}

void FreeList(Node *root) {
    Node *current = root;
    Node *last = GetTail(root);

    while (current != last) {
        Node *next = current->Next;
        free(current);
        current = next;
    }

    free(last);
}

// Można tą funkcję napisać w taki sposób, wtedy na zmienną możemy ustawić NULL (0), i printlist nie będzie
// próbować wyswietlac listy, gdy przekazany mu root został już usunięty
/*void FreeList(Node **root) {
    Node *current = *root;
    Node *last = GetTail(*root);

    while (current != last) {
        Node *next = current->Next;
        free(current);
        current = next;
    }

    free(last);
    *root = NULL;
}*/

int Count(Node *root) {
    Node *current = root;
    int length = 1;

    while (current->Next != root) {
        length++;
        current = current->Next;
    }

    return  length;
}

void RemoveNode(Node *root, int value) {
    Node *prev = root;
    Node *current = root->Next;

    for (int i = 0; i < Count(root); i++) {
        if (current->Value == value) {
            prev->Next = current->Next;
            free(current);
        }

        prev = current;
        current = current->Next;
    }
}