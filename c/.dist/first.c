#include<stdio.h>

#define max 20
// ayush soni 202051043
void main()
{
int omk[max],q[max],t[max],i,j,nq,nt,link,high=0;
static int qt[max],tt[max];

printf("\n\tFirst Fit");
printf("\nnumber of blocks:");
scanf("%d",&nq);
printf("number of files:");
scanf("%d",&nt);
printf("\nsize of the blocks:-\n");
for(i=1;i<=nq;i++)
{
    printf("Block %d:",i);
    scanf("%d",&q[i]);
}
    printf("size of the files :-\n");
for(i=1;i<=nt;i++)
{
    printf("File %d:",i);
    scanf("%d",&t[i]);
}
for(i=1;i<=nt;i++)
{

    for(j=1;j<=nq;j++)
    {
        if(qt[j]!=1) 
    {
        link=q[j]-t[i];
        if(link>=0)
    if(high<link)
    {
    tt[i]=j;
    high=link;
}
}
}
omk[i]=high;
qt[tt[i]]=1;
high=0;
}
printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
for(i=1;i<=nt;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,t[i],tt[i],q[tt[i]],omk[i]);
}
