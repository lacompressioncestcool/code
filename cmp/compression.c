#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE* fichier;
    FILE* fd;
    short a,nb;
    int c,com;
    char b;

    fichier=fopen("ADN.txt","r");
    fd=fopen("fd.txt","w");
    b=fgetc(fichier);

    while(b != EOF)
    {

        switch(b)
        {
            case 'A':
                a<<2;
                break;
            case 'T':
                a<<2;
                a++;
                break;
            case 'G':
                a<<1;
                a++;
                a<<1;
                break;
            case 'C':
                a<<1;
                a++;
                a<<1;
                a++;
                break;
            default:
                exit(-1);
        }
        c++;
        b=fgetc(fichier);
        if(com==7)
        {
            com=0;
            fwrite(&a,1,sizeof(short),fd);
            a=0;
        }
    }

    if(a)   fwrite(&a,1,sizeof(short),fd);

    nb=c;
    fwrite(&nb,1,sizeof(short),fd);

    fclose(fd);
    fclose(fichier);
    return 0;
}
