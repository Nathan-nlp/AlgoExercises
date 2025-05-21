#include <stdio.h>
#include <stdlib.h>
struct  node
{
    int w;
    int p;
}a[10001];
void qsor(struct node a[],int l,int r)
{
    int i=l,j=r;
    if(l>=r)
        return ;
    struct node x=a[l];
    while(i<j)
    {
        while(i<j&&a[j].w>x.w)j--;
        while(i<j&&a[j].w==x.w)
        {
            if(a[j].p<=x.p)//Guaranteed value is in descending order
                j--;
            else break;
        }
        a[i]=a[j];
        while(i<j&&a[i].w<x.w)i++;
         while(i<j&&a[i].w==x.w)
        {
            if(a[i].p>=x.p)
               i++;
            else break;
        }
        a[j]=a[i];
    }
    a[i]=x;
    qsor(a,i+1,r);
    qsor(a,l,i-1);
}

int main()
{
   int n,m;
   while(~scanf("%d %d",&n,&m))
   {
       for(int i=0;i<n;i++)
       {
           scanf("%d %d",&a[i].w,&a[i].p);
       }
       qsor(a,0,n-1);
       int sum=0;
       for(int i=0;i<m;i++)
       {
            sum+=a[i].p;
       }
       printf("%d\n",sum);
   }
    return 0;
}

