#include<stdio.h>
struct a
{
int cost;
int fun;
};
int main()
{
int max,n;
while(scanf("%d%d",&max,&n) && max && n)
{
struct a obj[n+1];
int i;
for(i=1;i<=n;i++)
{
scanf("%d%d",&obj[i].cost,&obj[i].fun);
}
int m[n+1][max+1];
int w=0;
int sum=0;
for(w=0;w<=max;w++)
m[0][w]=0;
for(i=1;i<=n;i++)
{
m[i][0]=0;
for(w=1;w<=max;w++)
{
if(obj[i].cost<=w)
{
if((obj[i].fun+m[i-1][w-obj[i].cost])>m[i-1][w])
{
m[i][w]=obj[i].fun+m[i-1][w-obj[i].cost];
}
else
m[i][w]=m[i-1][w];
}
else
{
m[i][w]=m[i-1][w];
}
// printf("%d ",m[i][w]);
}
// putchar('\n');
}
i=n;
w=max;
//printf("\n\n\n");
while(i>0 && w>0)
{
if(m[i][w]!=m[i-1][w])
{
//printf("Including %d\n",obj[i].cost);
sum+=obj[i].cost;
w-=obj[i].cost;
i--;
}
else
{
i--;
}
}
printf("%d %d\n",sum,m[n][max]);
}
return 0;
}
