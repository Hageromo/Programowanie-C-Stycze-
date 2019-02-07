#include <stdio.h>
#include "list.c"

int main() {
    FILE *numbers = fopen("numbers.txt", "r");

    int read;
    fscanf(numbers, "%d, ", &read);
    Node *list = Create(read);

    while (fscanf(numbers, "%d, ", &read) != EOF) {
        Add(list, read);
    }

    PrintList(list);

    FreeList(list);
    if (numbers) {
        fclose(numbers);
    }
    return 0;
}

/*Zad. 3.2
Wczytać z numbers.txt liczby.Utworzyć listę jednokierunkową(z zadania 2) zawierającą te liczby.Wypisać je na
ekran.*/