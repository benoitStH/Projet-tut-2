#include "instance.h"
#include <stdlib.h>

void Init_instance(instance *inst, int obj, int dim)
{
	inst->n_obj = obj;
	inst->n_dim = dim;
	inst->tab = malloc((dim+1)*sizeof(int*));
	for(int i = 0; i < dim + 1; i++)
	{
		inst->tab[i] = malloc(obj*sizeof(int));
		for(int o = 0; o < obj; o++)
		{
			inst->tab[i][o] = 0;
		}
	}
}

void Finalize_instance(instance* inst)
{
	if(inst->tab != NULL)
	{
		for(int i = 0; i < inst->n_dim + 1; i++)
		{
			if(inst->tab[i] != NULL)
			{
				free(inst->tab[i]);
				inst->tab[i] = NULL;
			}
		}
		free(inst->tab);
		inst->tab = NULL;
	}
}

void AddIn_instance(instance* inst, int dim, int obj, int val)
{
	if(dim < 0 || dim > inst->n_dim+1 || obj < 0 || obj > inst->n_obj)
	{
		printf("erreur AddIn_instance");
		exit(1);
	}
	inst->tab[dim][obj] = val;
}

void fill_instance_obj(instance *inst, FILE* fichier, int dim)
{
	for (int i = 0; i < inst->n_obj; i++)
	{
		fcanf("%d",&inst->tab[dim][i]);
	}
}

void fill_instance(instance *inst, FILE *fichier)
{
	for (int i = 0; i < inst->n_dim; i++)
	{
		fill_instance_obj(inst, fichier, i);
	}
}

void Print_instance(instance inst)
{
	for (int i = 0; i < inst->n_dim, i++)
	{
		for (int j = 0, j < inst->n_obj; j++)
		{
			printf("%d | ", inst->tab[i][j]);
		}
	}
}