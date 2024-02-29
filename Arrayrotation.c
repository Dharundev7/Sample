// Array Rotation
#include<stdio.h>
#include<assert.h>
int a[1000][1000],n;
int rotate(int);
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int totalrotation=0;
    while(1)
    {
        char ch;
        scanf("%s",&ch);
        if(ch=='A')
        {
            int angle;
            scanf("%d",&angle);
            totalrotation+=angle;
            rotate(angle);
        }
        else if(ch=='Q')
        {
            int p1,p2;
            scanf("%d %d",&p1,&p2);
            printf("%d\n",a[p1-1][p2-1]);
        }
        else if(ch=='U')
        {
            int p1,p2,value;
            scanf("%d %d %d",&p1,&p2,&value);
            int up=360-(totalrotation%360);
            rotate(up);
            a[p1-1][p2-1]=value;
            rotate(360-up);
        }
        else break;
    }
}

int rotate(int angle)
{
    int t,temp[n][n];
    t=(angle/90)%4;
    for(int p=0;p<t;p++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                temp[j][n-1-i]=a[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=temp[i][j];
            }
        }
    }
    return 0;
}