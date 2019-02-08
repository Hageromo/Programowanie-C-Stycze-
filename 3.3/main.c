#include <stdio.h>
#include "list.c"
#include <stdio.h>

void cyclicSwap(int *nr1,int *nr2,int *nr3,int *nr4){

    int temp;

    temp = *nr2;
    *nr2 = *nr1;
    *nr1 = *nr3;
    *nr3 = *nr4;
    *nr4 = temp;
}

void appendNumbersToTxt(int toAppend, FILE *file) {
    char buf[16];
    sprintf(buf, "%d, ", toAppend);
    fputs(buf, file);
}


int main() {
    FILE *numbers = fopen("numbers.txt", "r");

    int read;
    fscanf(numbers, "%d, ", &read);
    Node *list = Create(read);

    // read from file to list
    while (fscanf(numbers, "%d, ", &read) != EOF) {
        Add(list, read);
    }

    // print list
    PrintList(list);

    // sort list
    int wrong = 1;
    while (wrong != 0) {
        wrong = 0;
        Node *current = list;
        int listLength = Count(list);
        for (int i = 0; i < listLength - 1; i++) {
            if (current->Value > current->Next->Value) {
                int temp = current->Value;
                current->Value = current->Next->Value;
                current->Next->Value = temp;
                wrong = 1;
            }
            current = current->Next;
        }
    }

    // write sorted list to sorted.txt
    FILE *sorted = fopen("sorted.txt", "w");
    Node *current = list;
    for (int i = 0; i < Count(list); i++) {
        appendNumbersToTxt(current->Value, sorted);
        current = current->Next;
    }

    FreeList(list);
    if (numbers) {
        fclose(numbers);
    }
    if (sorted) {
        fclose(sorted);
    }

    return 0;
}

//Zad. 3.3
//Posortować(w dowolny sposób) listę z zadania 2.3 (już po wczytaniu z pliku).Zapisać posortowaną liczbę do pliku
//sorted.txt.Algorytm sortowania proszę zaimplementować samodzielnie.