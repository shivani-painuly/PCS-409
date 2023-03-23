#include<stdio.h>
int main()
{
    int a[90],n,k,key,l,i;
    printf("enter number of elements");
    scanf("%d",&n);
    while(l<=n)
    {
        printf("number of input");
        scanf("%d",&k);
        for( i=0;i<k;i++){
        scanf("%d",&a[i]);
        }
    
    printf("enter key");
    scanf("%d",&key);
    for(i=0;i<k;i++)
    {
        if(a[i]==key)
        {
            printf("index==%d",i);
        }
    }
    l++;
    }
}
