#include<stdio.h>
#define MAX 100

typedef struct
{
    int frequency;
    char c;
    int weight;
}Node;

void build_min_heap(Node n1[MAX],int n);
void min_heap(Node n1[],int i,int n);
void branch_weight(Node n1[],int n);
void path(Node n1[],int n);
void find_path(Node n1[],Node n2[],int n,int i,int k);
void print_path(Node n2[],int k);
Node extract_min(Node a[],int *n);
void huffman(Node n1[],int *n);

void main()
{
    int i,n;
    Node n1[MAX];

    printf("Enter the total numbers of character: ");
    scanf("%d",&n);

    //printf("Enter the character: ");

    printf("Enter the character & frequency: ");
    for(i=1;i<=n;i++)
        scanf(" %c %d",&n1[i].c,&n1[i].frequency);

    huffman(n1,&n);
    branch_weight(n1,n);

    printf("Min heap is: ");
    for(i=1;i<=n;i++)
        printf(" %c, %d, %d\n",n1[i].c,n1[i].frequency,n1[i].weight);

    path(n1,n);
}

void build_min_heap(Node n1[MAX],int n)
{
    int i,size;
    size=n;

    for(i=n/2;i>=1;i--)
    {
        min_heap(n1,i,size);
    }
}

void min_heap(Node n1[],int i,int n)
{
    int l,r,size,min;
    Node temp;
    l=2*i;
    r=2*i+1;
    if(l<=n && n1[l].frequency<n1[i].frequency)
        min=l;
    else
        min=i;

    if(r<=n && n1[r].frequency<n1[min].frequency)
        min=r;

    if(min!=i)
    {
        temp=n1[i];
        n1[i]=n1[min];
        n1[min]=temp;
        min_heap(n1,min,n);
    }
}

void branch_weight(Node n1[],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            n1[i].weight=0;
        }
        else
        {
            n1[i].weight=1;
        }
    }
}

void path(Node n1[],int n)
{
    int i,j,k=1;
    Node n2[MAX];
    //for(i=1;i<=n/2;i++)
    //{
       // k=1;
        find_path(n1,n2,n,1,k);
    //}
}

void find_path(Node n1[],Node n2[],int n,int i,int k)
{
    if(i>n)
        return;

    n2[k++]=n1[i];
    if((2*i)>n &&((2*i)+1)>n)
        print_path(n2,k);

    else
    {
        find_path(n1,n2,n,2*i,k);
        find_path(n1,n2,n,2*i+1,k);
    }
}

void print_path(Node n2[],int k)
{
    int i;
    printf("\n");
    for(i=1;i<k;i++)
    {
        printf(" %d,",n2[i].weight);
    }
}

void huffman(Node n1[],int *n)
{
    int i,p,l,r;
    Node z,x,y;
    p=*n;
    build_min_heap(n1,*n);

    for(i=1;i<p;i++)
    {

        x = extract_min(n1,n);
        y = extract_min(n1,n);
        *n=*n+1;
        n1[*n].frequency=x.frequency+y.frequency;
        l=2*(*n);
        r=l+1;
        n1[l]=x;
        n1[r]=y;
        min_heap(n1,1,*n);
    }
}

Node extract_min(Node a[],int *n)
{
    Node min;
    if(*n<0)
    {
        printf("Underflow error");
        return;
    }

    else
    {
        min=a[1];
        a[1]=a[*n];
        *n=*n-1;
        min_heap(a,1,*n);

        return min;
    }

}


/*void min_heap_insert(Node a[],int i,int key)
{
    int temp;
    a[i]=key;
    while(i>1&& a[i/2]<a[i])
    {
        temp=a[i];
        a[i]=a[i/2];
        a[i/2]=temp;

        i=i/2;
    }
}*/



