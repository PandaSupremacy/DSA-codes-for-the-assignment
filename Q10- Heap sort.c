#include<stdio.h>
#include <conio.h>
void Adjust(int he[],int i)  
{

	int Reference = 1,num,copy,j;
	num=he[0];
	while(2*i<=num && Reference==1)
{
j=2*i;
if(j+1<=num && he[j+1] > he[j])
j=j+1;
if( he[j] < he[i])
Reference=0;
else
{
	copy=he[i];
	he[i]=he[j];
	he[j]=copy;
	i=j;
}
}
}
void Make_Heap(int heap[])
{
int NE,i;
NE=heap[0];
for(i=NE/2;i>=1;i--)
Adjust(heap,i);
}
int main()
{
	int heap[30],ne,i,le,cpyvar;
	printf("Enter the number of elements you want in the original Array:");
	scanf("%d",&ne);
	printf("\nEnter the members of the array one by one:"); /* Asking for the elements of the unsorted array*/
	for(i=1;i<=ne;i++)
	scanf("%d",&heap[i]);
	heap[0]=ne;
	Make_Heap(heap);
	while(heap[0] > 1) 
	{
		le=heap[0];
		cpyvar=heap[1];
		heap[1]=heap[le];
		heap[le]=cpyvar;
		heap[0]--;
		Adjust(heap,1);
	}
	printf("\nSorted Array:\n");
	for(i=1;i<=ne;i++)
	printf("%d ",heap[i]);
	return 0;
}
