#include "stdio.h"
#include "stdlib.h"
//Sona ekleme

struct node{
  int data;
  struct node* next;
}*head,*temp;
void addToEnd()
{
  int i;
  temp = head;
  while(temp->next !=NULL){ // gecici pointerin listenin son elemanini isaret etmesi
    temp = temp->next;
    //printf("%d\n",temp->data);
  }
  struct node* newNode = (int*) malloc(sizeof(struct node)); // hafizada yer acilmasi
  newNode->data = 99; // icine veri alinmasi
  temp->next = newNode;//listenin en son elemaninin eklenecek yeni elemani göstermesi
  newNode->next = NULL;// yeni elemanin gösterdigi yerin NULL olmasi
}
void createList(int n)
{
	int i; // sayac
	struct node* newNode = (int*)malloc(sizeof(struct node));
	newNode->data = 1;
  newNode->next =NULL;
	head = newNode;
	temp = head;
	for(i=0;i<n-1;i++)
	{
		newNode = (int*) malloc(sizeof(struct node));
		newNode->data = i+2;
		temp->next = newNode;
		newNode->next = NULL;
		temp = temp->next;
	}
}

void printList()
{
	int i=1;
	temp = head;
	while(temp!=NULL)//En son gelen elemanin okunabilmesi icin temp !=NULL olmali
	{
		printf("%d. eleman = %d\n",i++,temp->data);
		temp=temp->next;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	createList(n);
  addToEnd();
	printList();
}
