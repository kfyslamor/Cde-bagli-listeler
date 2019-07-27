#include <stdio.h>

struct node{
	int data;
	struct node* next; // her zaman icin bir sonraki d�g�m� g�sterecek olan pointer.
}*head,*temp; // head = her zaman icin baslangici g�sterecek olan "d�g�m" pointeri.
			  // temp = listenin icinde, sirasiyla d�g�mlere erismemizi saglayacak bir d�g�m pointeri.

void createList(int n)
{
	int i; // sayac
	struct node* newNode = (int*)malloc(sizeof(struct node)); // Yeni bir d�g�m icin hafizada yer acilmasi.
	newNode->data = 1;
	head = newNode; // baslangic pointerinin yeni olusturulan d�g�m�n basini g�stermesi.
	temp = head; // gecici pointerin da baslangici g�stermesi gerekiyor c�nk� listeyi okumaya buradan baslayacak.
	for(i=0;i<n;i++) // i = 1, ile baslamasinin sebebi ilk d�g�m�n �zel olmasi ve baslangici temsil etmesi, diger d�g�mler sadece birbirini g�sterecek.
	{
		newNode = (int*) malloc(sizeof(struct node)); // her seferinde yeni bir d�g�m icin alan ayrilmasi.
		newNode->data = i+2;
		temp->next = newNode; // bir �nceki d�g�m, her seferinde olusturulan yeni d�g�me baglantiyi bu kodla saglayacak.
		newNode->next = NULL; // yeni olusturulan d�g�m, NULL'u g�stermezse liste bitmesi gerektigi yerde bitmez.
		temp = temp->next; // gecici olarak atadigimiz pointerin, her seferinde yeniden olusturacagimiz pointeri g�stermesi.
	}
}

void printList()
{
	int i=1;
	temp = head; // head hicbir zaman degismemeli ve her okuma yaptiktan sonra temp pointerinin headi g�sterdigin emin olunmali.
	while(temp->next!=NULL) // gecici olarak kullandigimiz pointerin ->next'i (yani g�sterdigi d�g�m) NULL olmadigi s�rece assagidaki islemleri yap
	{
		printf("%d. eleman = %d\n",i++,temp->data);
		temp=temp->next; //gecici olarak kullanilan pointer, icindeki degeri her yazdirdiginda kendini iteleyerek, �n�ndeki d�g�m�n�n icindeki veriyi yazdiracak.
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	createList(n);
	printList();
}
