#include <stdio.h>
#include <stdlib.h>

#define mb 32768


int main()
{
    FILE* fichier;
    FILE* fd;

    fichier=fopen("fd.txt","r");
    fd=fopen("decompesse.txt","w");

    short c=8;
    unsigned short a,b,total;
    int i,j,test;
    unsigned short us=mb;

    test=0;
    total=0;


    for(i=c/8;i>0;i--)
    {
        fread(&a,sizeof(short),1,fichier);
        printf("a= %u \n",a);
        for(j=0;j<=8;j++)
        {
        //trouve le 1er bit
        b=a/32768;
        a=a%32768;
        a=a*2;//décale

        if(b)   total=total+10;



        //trouve le deuxième bit
        b=a/32768;
        a=a%32768;
        a=a*2;

        if(b)   total=total+1;

        printf("total= %d\n",total);

            if(total==0)
                fprintf(fd,"A");
            if(total==1)
                fprintf(fd,"T");
            if(total==10)
                fprintf(fd,"G");
            if(total==11)
                fprintf(fd,"C");



        total=0;



        }
    }
    exit(0);
}
