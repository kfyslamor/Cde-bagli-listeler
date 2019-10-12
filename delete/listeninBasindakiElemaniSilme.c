#include <stdio.h>

struct node{
	int data;
	struct node* next; // her zaman icin bir sonraki dügümü gösterecek olan pointer.
}*head,*temp; // head = her zaman icin baslangici gösterecek olan "dügüm" pointeri.
			  // temp = listenin icinde, sirasiyla dügümlere erismemizi saglayacak bir dügüm pointeri.
void deleteTheFirstNode(){
  temp = head;
  struct node* deleteNode;
  deleteNode = head;
  head = temp->next;
  temp = head;
  free(deleteNode);
}

void createList(int n)
{
	int i; // sayac
	struct node* newNode = (int*)malloc(sizeof(struct node)); // Yeni bir dügüm icin hafizada yer acilmasi.
	newNode->data = 1;
	head = newNode; // baslangic pointerinin yeni olusturulan dügümün basini göstermesi.
	temp = head; // gecici pointerin da baslangici göstermesi gerekiyor cünkü listeyi okumaya buradan baslayacak.
	for(i=1;i<n;i++) // i = 1, ile baslamasinin sebebi ilk dügümün özel olmasi ve baslangici temsil etmesi, diger dügümler sadece birbirini gösterecek.
	{
		newNode = (int*) malloc(sizeof(struct node)); // her seferinde yeni bir dügüm icin alan ayrilmasi.
		newNode->data = i+2;
		temp->next = newNode; // bir önceki dügüm, her seferinde olusturulan yeni dügüme baglantiyi bu kodla saglayacak.
		newNode->next = NULL; // yeni olusturulan dügüm, NULL'u göstermezse liste bitmesi gerektigi yerde bitmez.
		temp = temp->next; // gecici olarak atadigimiz pointerin, her seferinde yeniden olusturacagimiz pointeri göstermesi.
	}
}

void printList()
{
	int i=1;
	temp = head; // head hicbir zaman degismemeli ve her okuma yaptiktan sonra temp pointerinin headi gösterdigin emin olunmali.
	while(temp!=NULL) // gecici olarak kullandigimiz pointerin icindeki dügüm NULL olmadigi sürece assagidaki islemleri yap
	{
		printf("%d. eleman = %d\n",i++,temp->data);
		temp=temp->next; //gecici olarak kullanilan pointer, icindeki degeri her yazdirdiginda kendini iteleyerek, önündeki dügümünün icindeki veriyi yazdiracak.
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	createList(n);
  deleteTheFirstNode();
	printList();
}
