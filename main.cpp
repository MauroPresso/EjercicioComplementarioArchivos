#include<stdio.h>
#include<stdlib.h>

struct Complex
{
    float re;
    float im;
};

int main()
{
    FILE *pf;
    pf = fopen("C:\\Users\\MAURO\\Documents\\EjercicioComplementarioArchivos\\number_mixed.dat","rb");
    if (pf == NULL)
    {
        printf("Error 404: Not Found\n");
        return 0;
    }
    else
    {
        printf("File opening was OK. Continue with the procedure\n");
    }
    

    int cant_intigers;
    int cant_float;
    int cant_double;
    int cant_complex;
    
    // Creando vectores dinamicos para juntar los datos.
    int *intigers_vector;
    float *float_vector;
    double *double_vector;
    struct Complex *complex_vector;
    
	int finale;
	int file_size;
	char tipo;
	tipo = '\0';
	
	// Para saber el tamaño del archivo
	fseek(pf, 0, SEEK_END);
	file_size = ftell(pf);
	
    rewind(pf); // Me lo pone al principio del archivo.
    do{
		fread(&tipo, sizeof(char), 1, pf); // Si yo le pido a la funcion fread() que lea 'tanto', se corre 'tanto'. 
		if(tipo == 'i')
		{
			fread(&cant_intigers, sizeof(int), 1, pf);
			intigers_vector = new int[cant_intigers]; // Inicializo el vector dinamico luego de saber la cantidad.
			// Charging values.
			fread(intigers_vector, sizeof(int), cant_intigers, pf);
		}
		if(tipo == 'f')
		{
			fread(&cant_float, sizeof(int), 1, pf);
			float_vector = new float[cant_float]; // Inicializo el vector dinÃ¡mico luego de saber la cantidad.
			// Charging values.
			fread(float_vector, sizeof(float), cant_float, pf);
		}
		if(tipo == 'd')
		{
			fread(&cant_double, sizeof(int), 1, pf);
			double_vector = new double[cant_double];
			// Charging values.
			fread(double_vector, sizeof(double), cant_double, pf);
		}
		if(tipo == 'z')
		{
			fread(&cant_complex, sizeof(int), 1, pf);
			complex_vector = new struct Complex[cant_complex];
			// Charging values.
			fread(complex_vector, sizeof(struct Complex), cant_complex, pf);
		}
		finale = ftell(pf);
    } while(finale < file_size); // fread me devuelve la cantidad de bits que lee. Si fread me devuelve un 0, es porque o el archivo es nulo, o porque ya no hay nada que leer (llegÃ³ hasta el final).
	
	// Printing intiger values.
	printf("Hay %d de numeros enteros:\n" , cant_intigers);
	for(int j = 0 ; j < cant_intigers ; j++)
	{
		printf("%d\t", intigers_vector[j]);
	}
	printf("\n");	
	
	// Printing float values.
	printf("Hay %d de numeros float:\n" , cant_float);
	for(int j = 0 ; j < cant_float ; j++)
	{
		printf("%f\t", float_vector[j]);
	}
	printf("\n");

	// Printing double values.
	printf("Hay %d de numeros double:\n" , cant_double);
	for(int j = 0 ; j < cant_double ; j++)
	{
		printf("%lf\t", double_vector[j]);
	}
	printf("\n");

	// Printing values.
	printf("Hay %d de numeros complejos:\n" , cant_complex);
	for(int j = 0 ; j < cant_complex ; j++)
	{
		printf("%f + (%f)j\t", complex_vector[j].re, complex_vector[j].im);
	}
	printf("\n");

	fclose(pf);
    
	// Liberar memoria
    delete[] intigers_vector;
    delete[] float_vector;
    delete[] double_vector;
    delete[] complex_vector;
	
	// Asegurar que no quede ningun puntero residual.
    intigers_vector = NULL;
    float_vector = NULL;
    double_vector = NULL;
    complex_vector = NULL;
	
	printf("\nFin del programa :)");
    return 0;
}

// Conclusión: El error está en el printf de los complex.