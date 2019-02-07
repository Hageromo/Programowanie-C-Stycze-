#include <stdio.h>

void appendToNumbersTxt(int toAppend, FILE *file) {
    char buf[16];
    sprintf(buf, "%d, ", toAppend);
    fputs(buf, file);
}

int main() {
    FILE *numbers = fopen("numbers.txt", "w+");

    int provided;

    do {
        scanf("%d", &provided);
        appendToNumbersTxt(provided, numbers);
    } while (provided != 0);

    if (numbers) {
        fclose(numbers);
    }
    return 0;
}


/*Zad. 3.1
Wczytywać od użytkownika liczby, aż nie poda on 0. Wszystkie wczytane liczby zapisać do pliku numbers.txt*/