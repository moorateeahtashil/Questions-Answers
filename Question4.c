#include<stdio.h>
struct servicing
{
  int servicing_np;
  char Reg_no[10];
  char surname[15];
  float cost;
};
void input_serv(struct servicing *serv)
{
  printf("Enter Servicing number : ");
  scanf("%d",&serv->servicing_np);
  printf("Enter Registration no :");
  scanf("%s",serv->Reg_no);
  printf("Enter the Surname of the customer : ");
  scanf("%s",serv->surname);
}
void Display_stud(struct servicing *serv)
{
 printf("%d/n",serv->servicing_np);
 printf("%s/n",serv->Reg_no);
 printf("%s/n",serv->surname);
 printf("%f",serv->cost);
}
void assign_cost(struct servicing *serv[],int *size,int *num,int *cost)

{
  int a=0;
  for(a=0;a<*size;a++)
  {
    if(serv[a]->servicing_np==*num)
    {
     scanf("%f",&serv[a]->cost);
    }
  }
}

void main()
{
  struct servicing s[20];
  printf("1.Add");
  printf("2. Cost");
  printf("3.Display");
  int choice;
  int i=0;
  int servnum;
  scanf("%d",&choice);
  if(choice==1)
  {
   input_serv(&s[i]);
  }
  if(choice==2)
  {
   printf("Enter servicing number : ");
   scanf("%d",&servnum);
   int z=0;
   for(z=0;z<20;z++)
   {
    if(s[z].servicing_np==servnum)
        Display_stud(&s[z]);
   }
}
}
