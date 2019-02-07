#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Student Student;

struct Student
{
    int Age;
    int Height;
    int Semester;
};

int main() {

    int arr_size = 3;
    int i;
    Student* s_arr = (Student*)malloc(arr_size * sizeof(Student));
    for (i = 0; i < arr_size; i++)
    {
        printf("Proszę wprowadzić dane studenta nr %d:", i + 1);
        scanf("%d %d %d", &s_arr[i].Age, &s_arr[i].Height, &s_arr[i].Semester);
    }


    for (i = 0; i < arr_size; i++)
    {
        printf("Student %d: Age = %d, Height = %d, Semester = %d\n", i + 1, s_arr[i].Age, s_arr[i].Height, s_arr[i].Semester);
    }

    free(s_arr);

    return 0;
}


//Zad 1 2
// Utworzyć tablicę 3 studentów.Zapełnić ją wartościami, wyświetlić, zwolnić pamięć.Tablica powinna być utworzona za
//pomocą metody malloc(proszę pilnować odpowiedniej ilości gwiazdek!)


