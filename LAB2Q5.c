#include<stdio.h>
void inputArray(int arr[],int *n)
{
   int i;
   for(i=0;i<*n;i++)
      {
       scanf("%d",&arr[i]);
      }
}

void displaynum(int arr[],int *n)
{
   int j;
   for(j=0;j<*n;j++)
      {
        printf("%d",arr[j]);
      }
}


void main()
{
  printf("Enter the size of the array");
  int n;
  scanf("%d",&n);
  int arr[n];
  inputArray(arr,&n);
  displaynum(arr,&n);
}
