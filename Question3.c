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
  struct student s[20];
  int nums;
  printf("Enter the number of students :");
  scanf("%d",&nums);
  int i=0;
  for(i=0;i<nums;i++)
   {
     Input(&s[i]);
     Display_Stud(&s[i]);
   }
}
