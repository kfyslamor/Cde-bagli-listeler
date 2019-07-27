#include <stdio.h>

struct node{
	int data;
	struct node* next; 
}*head,*temp; 

void addMiddle()
{
	int a=0,i=0;
	printf("Kacinci elemandan sonra eklensin:");
	scanf("%d",&a);
	temp = head; // hata almamak icin listede her degisiklik yapacaginizda bunu yapmakta fayda var
	while(temp->next!=NULL && i < a-1)
	{
		temp = temp->next;
		i++;
	} // iteleme bittikten sonra
	struct node* newNode = (int*)malloc(sizeof(struct node)); // dügüm icin hafizada yer acildi.
	struct node* after; // deger degisecegi icin, hafizadaki yeri koruma amacli tanimlandi.
	after = temp->next;
	temp->next = newNode; // suanda bulundugumuz dügümün gösterecegi dügüm yeni olusturalacak olan dügüm.
	newNode->data = 55; // veriyi koyduk
	newNode->next = after;	// yeni olusturulan dügüm olusturuldu ve listeye eklendi, örnegin siralamada 6. eleman oldu eski 6. elemani simdiki 7. elemani göstermesi icin bu satir gerekli.. 
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
	addMiddle();
	printList();
}
