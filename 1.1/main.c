#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Student
{
    int Age;
    int Height;
    int Semester;
};

typedef struct Student Student;

Student* StudentCreate(int age, int height, int semester)
{
    Student * student = (Student*)malloc(sizeof(Student));
    student->Age = age;
    student->Height = height;
    student->Semester = semester;
    return student;

}


void PrintStudent(Student *s)
{
    printf("Age = %d \nHeight = %d\nSemester = %d", s->Age, s->Height, s->Semester);
}


bool AreEqual(Student *s1, Student *s2)
{
    if (s1->Age == s2->Age && s1->Height == s2->Height && s1->Semester == s2->Semester)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main() {


    int a, h, s;


    printf("Wpisz dane pierwszego studenta(wiek,wzrost,semestr):");
    scanf("%d %d %d", &a,&h,&s);
    Student *s1 = StudentCreate(a, h, s);


    printf("Wpisz dane drugiego studenta(wiek,wzrost,semestr):");
    scanf("%d %d %d", &a,&h,&s);
    Student *s2 = StudentCreate(a, h, s);

    if (AreEqual(s1, s2))
        printf("Studenci mają takie same dane.");
    else
        printf("Studenci mają różne dane.");


    Student *toPrint = StudentCreate(25, 180, 5);
    PrintStudent(toPrint);
    free(toPrint);

    free(s1);
    free(s2);

    return 0;
}

//Zad 1.1
//Utworzyć strukturę Student taką jak powyżej.Napisać metody :
//Student * Create(int age, int height, int semester) // alokuje pamięć i tworzy studenta o podanych parametrach.
//WAŻNE - pamięć należy potem zwolnić w main() !
//void PrintStudent(Student *s) // wypisuje wszystkich składowych struktury
//bool AreEqueal(Student* sl, Student* s2) // zwraca informację, czy składowe są takie same (Uwaga - w C int zamiast
//bool)