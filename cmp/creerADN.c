#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

float alea_float()
	{
	static int init_alea = 1;
	if (init_alea) srand(getpid());
	init_alea = 0;
	return (float)rand() / (float)RAND_MAX;
	}

int alea_int(int N) { return (int)(N*alea_float()); }


int main()
{

    int a;
    int n;
    int i;

    scanf("%d \n",&n);

    FILE* fichier = fopen("ADN.txt","w");

    for(i = 0; i < n; i++)
    {
        a = alea_int(4);
        if(a == 0) { fprintf(fichier,"A"); }
        else if(a == 1) { fprintf(fichier,"T"); }
        else if(a == 2) { fprintf(fichier,"G"); }
        else { fprintf(fichier,"C"); }
    }

    return 0;
}
