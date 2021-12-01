#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instance.h"


int main(int argc, char **argv)
{
	//printf("hello world\n");
	FILE *fichier = fopen("/home/administrateur/Documents/projet2/projettut2/instances/_mknapcb1_res.txt","r");
	if (fichier == NULL)
	{
		printf("pas de fichier");
		exit(1);
	}
	int n_instances = 0;
	
	fscanf(fichier, "%d", &n_instances);
	printf("nombre d'instances : %d\n", n_instances);
	
	int n_obj = 0;
	fscanf(fichier, "%d", &n_obj);
	printf("nombre d'objets : %d\n", n_obj);
	
	int n_dimensions = 0;
	fscanf(fichier, "%d", &n_dimensions);
	printf("nombre de dimensions : %d\n", n_dimensions);
	
	time_t start_t, end_t;
	for(int i = 0; i < n_instances; i++)
	{
		time(&start_t);
		time(&end_t);
	}
	instance inst;
	Init_instance(&inst, 10, 10);
	Finalize_instance(&inst);
	
	return 0;
}
