#include<stdio.h>
 struct student
 {
    char surname[20];
    char other[20];
    int age;
    char address[30];
 };
 void Input(struct student *stud)
 {
  printf("Enter the Surname of the student : ");
  scanf("%s",stud->surname);
  printf("Enter Other name of the Student : ");
  scanf("%s",stud->other);
  printf("Enter the age of the Student : ");
  scanf("%d",&stud->age);
  printf("Enter the address of the Student : ");
  scanf("%s",stud->address);
 }
 void Display_Stud(struct student *s1)
 {
  printf("%s", s1->surname);
 }
 void main()
 {
  struct student s1,s2;
  Input(&s1);
  Display_Stud(&s1);
 }
