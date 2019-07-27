#include <stdio.h>

struct node{
	int data;
	struct node* next; 
}*head,*temp; 

void addFirst()
{
	struct node* newNode = (int*)malloc(sizeof(struct node*)); // dügüm icin hafizada yer actim
	newNode->next = head; // yeni olusturulan dügümün gösterecegi dügüm, baslangic dügümü olacak.
	newNode->data = 11; // icindeki veri = 11.
	head=newNode; // baslangicin yeni adresi, yeni olusturulan dügüm.
}			  

void createList(int n)
{
	int i; // sayac
	struct node* newNode = (int*)malloc(sizeof(struct node));
	newNode->data = 1;
	head = newNode; 
	temp = head;
	for(i=0;i<n;i++) 
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
	while(temp->next!=NULL) 
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
	addFirst();
	printList();
}
