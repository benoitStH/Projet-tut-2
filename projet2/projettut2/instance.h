
typedef struct _instance_
{
	int n_obj;
	int n_dim;
	int** tab;
	
}instance;

void Init_instance(instance* inst, int obj, int dim);
void Finalize_instance(instance* inst);