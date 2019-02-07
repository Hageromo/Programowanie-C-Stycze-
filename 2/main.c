#include <stdio.h>
#include <stdlib.h>
#include "list.c"


int main(int argc, const char *argv[]) {

    Node *root = Create(2);
    PrintList(root);

    Add(root, 4);
    Add(root, 8);
    Add(root, 16);
    PrintList(root);

    Add(root, 20);
    PrintList(root);

    printf("Ostatni wezel ma wartosc %d\n", GetTail(root)->Value);

    Add(root, 16);
    PrintList(root);
    printf("%d\n", Count(root));

    RemoveNode(root, 8);
    PrintList(root);
    RemoveNode(root, 10);
    PrintList(root);
    RemoveNode(root, 16);
    PrintList(root);

    printf("%d\n", Count(root));

    FreeList(root);

    PrintList(root);

    return 0;
}

//zad.1 Zaimplementować cykliczną listę jednokierunkową.Powinna ona zawierać struktury węzła: