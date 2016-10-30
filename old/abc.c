#include<stdio.h>
int main()
{
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    int* (*pa)[3];
    pa=&a;
    int i=0;
    for(i=0;i<3;i++)
    {
        printf("%d",**(pa));
    }

    return 0;
}
