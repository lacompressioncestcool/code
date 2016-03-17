#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE* fichier;
    FILE* fd;
    unsigned short a,nb;
    int c,com;
    char b;

    fichier=fopen("ADN.txt","r");
    fd=fopen("fd.txt","w");
    b=fgetc(fichier);
    com=0;

    while(b != EOF)
    {

        switch(b)
        {
            case 'A'://00
                a=a*4;
                break;
            case 'T'://01
                a=a*4;
                a++;
                break;
            case 'G'://10
                a=a*2;
                a++;
                a=a*2;
                break;
            case 'C'://11
                a=a*2;
                a++;
                a=a*2;
                a++;
                break;
            default:
                exit(-1);
        }
        c++;
       com++;
        b=fgetc(fichier);

        if(com==8)
        {
            com=0;
            printf("%u\n",a);
            fwrite(&a,1,sizeof(short),fd);
            a=0;
        }
    }

    if(com)   fwrite(&a,1,sizeof(short),fd);

    nb=c;
    //fwrite(&nb,1,sizeof(short),fd);

    fclose(fd);
    fclose(fichier);
    return 0;
}
