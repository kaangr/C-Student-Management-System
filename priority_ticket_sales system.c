

/*
65 yaş üstü müşteriler en öncelikli müşterilerdir. Daima kuyruğun başına alınacaktır. 65 yaş
üstü müşteriler daima birbirlerini beklemek zorundadır. Kurumsal işlem yapan müşteriler
bireysel işlem yapan müşterilerden daha önceliklidir. Fakat geldiklerinde hemen kuyruğun
başına alınmazlar. Kendilerinden önce mutlaka en az iki bireysel müşteri olmak zorundadır.
Eğer bireysel müşteri yok ise önceki kurumsal işlem bekleyen müşterilerin önüne geçemez.
Sırasını beklemek zorundadır.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX 10

void insert_by_priority(int);

void addque();
void check(int);
void display_pqueue();
void display_queue();
bool isone();
int pri_que[MAX];
int que[MAX];
int front = -1, rear = -1;
int front1 = -1, rear1 = -1;

void main()
{
    int n, ch;
    int i;

    printf("\n1 - Insert  elements into pqueue");
    printf("\n2 - Display pqueue elements");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");

    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                addque();

                for(i=0;i<MAX;i++){
                    insert_by_priority(que[i]);
                }

                // insert_by_priority(n);
                break;
            case 2:
                display_pqueue();
                break;
            case 3:
                display_queue();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}




bool isone()
{

    int i, j;
    int ikinin_indexleri;
    int iki_counter;
    for (i; i < 10; i++)
    {

        if (que[i] == 2)
        {
            ikinin_indexleri = i;
            for (j = ikinin_indexleri; 0 < ikinin_indexleri; --j)
            {
                if (que[j] == 1)
                    iki_counter++;

            }
        }

    }
    if (iki_counter >= 3)
        return true;
    else
        return false;


}
void insert_by_priority(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}
void addque() // normal sira
{
    int i;
    srand(time(NULL));
    for (i = 0; i < MAX; i++)
    {
        int data = rand() % 3 +1;

        if (rear1 == MAX - 1)
            printf("Overflow \n");
        else
        {
            if (front1 == -1)

                front1 = 0;
            printf("Element to be inserted in the Queue\n : ");
            rear1 = rear1 + 1;
            que[rear1] = data;
        }
    }
}

/* Function to check priority and place element */
void check(int data)
{
    int i, j;
int temp;
    for (i = 0; i <= rear; i++)
    {
        if (data==3 && data> pri_que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
    if(isone()==true){
        for(i=0;i<10;i++){
          if(pri_que[i]!=3)
              continue;
          if(pri_que[i]==2){
              pri_que[i]=temp;
              pri_que[i]=pri_que[i+1];
              temp=pri_que[i+1];
          }
        }
    }
}


/* Function to delete an element from queue */


/* Function to display queue elements */
void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }

    for (; front <= rear; front++)
    {
        printf(" %d ", pri_que[front]);
    }

    front = 0;
}
void display_queue()
{
    if ((front1 == -1) && (rear1 == -1))
    {
        printf("\nQueue is empty");
        return;
    }

    for (; front1 <= rear1; front1++)
    {
        printf(" %d ", que[front1]);
    }

    front1 = 0;
}