#include <stdio.h>
#include <stdlib.h>

#define mb 0x8000


int main()
{
    FILE* fichier;
    FILE* fd;

    fichier=fopen("fd.txt","r");
    fd=fopen("decompesse.txt","w");

    short c=100;
    short a;
    int i,j,b,test;

    // lecture de c

    //aller début

    for(i=c/8;i>0;i--)
    {
        fread(&a,sizeof(short),1,fichier);
        for(j=0;j<=8;j++)
        {
            b=a&mb;
            if(b&&mb){test=10;}
            a<<1;
            b=a&mb;
            if(b&&mb){test++;}
        }
    }

}
