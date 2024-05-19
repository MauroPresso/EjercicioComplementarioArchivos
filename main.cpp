#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

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
        printf("\nError 404: Not Found\n");
        return 0;
    }
    else
    {
        printf("\nFile opening was OK. Continue with the procedure\n");
    }
    
	// Cantidades.
    uint8_t cant_intigers;
    uint8_t cant_float;
    uint8_t cant_double;
    uint8_t cant_complex;
    
	// Cantidades TOTALES.
	uint8_t cant_TOTAL_intigers = 0;
    uint8_t cant_TOTAL_float = 0;
    uint8_t cant_TOTAL_double = 0;
    uint8_t cant_TOTAL_complex = 0;

    // Creando vectores dinamicos para juntar los datos.
    int *intigers_vector;
    float *float_vector;
    double *double_vector;
    struct Complex *complex_vector;
    
	uint8_t finale;
	uint8_t file_size;
	char tipo;
	tipo = '\0';
	
	// Creo estas variables para guardar la ultima posicion cargada de cada vector.
	uint8_t ult_pos_i;
	uint8_t ult_pos_f;
	uint8_t ult_pos_d;
	uint8_t ult_pos_z;

	// Para saber el tamaño del archivo
	fseek(pf, 0, SEEK_END);
	file_size = ftell(pf);
	
    
	rewind(pf); // Me lo pone al principio del archivo.
    
	// Hago este bucle para saber cuanta cantidad hay de cada tipo de dato.
	do{
		fread(&tipo, sizeof(char), 1, pf); // Si yo le pido a la funcion fread() que lea 'tanto', se corre 'tanto'. 
		if(tipo == 'i')
		{
			fread(&cant_intigers, sizeof(uint8_t), 1, pf);
			cant_TOTAL_intigers = cant_TOTAL_intigers + cant_intigers;
		}
		if(tipo == 'f')
		{
			fread(&cant_float, sizeof(uint8_t), 1, pf);
			cant_TOTAL_float = cant_TOTAL_float + cant_float;
		}
		if(tipo == 'd')
		{
			fread(&cant_double, sizeof(uint8_t), 1, pf);
			cant_TOTAL_double = cant_TOTAL_double + cant_double;
		}
		if(tipo == 'z')
		{
			fread(&cant_complex, sizeof(uint8_t), 1, pf);
			cant_TOTAL_complex = cant_TOTAL_complex + cant_complex;
		}
		finale = ftell(pf);
    } while(finale < file_size); // Si finale = file_size, es porque el archivo ya se leyo completo.
	
	printf("\n");
	// Printing the total of intiger values.
	printf("Hay %u numeros enteros\n" , cant_TOTAL_intigers);	
	
	// Printing the total of float values.
	printf("Hay %u numeros float\n" , cant_TOTAL_float);
	
	// Printing the total of double values.
	printf("Hay %u  numeros double\n" , cant_TOTAL_double);
	

	// Printing the total of complex values.
	printf("Hay %u numeros complejos\n" , cant_TOTAL_complex);
	

	// Inicializo los vectores dinamicos luego de saber la cantidad de valores que tiene cada uno.
	// intigers_vector
	intigers_vector = new int[cant_TOTAL_intigers];
	ult_pos_i = 0;
	
	// float_vector
	float_vector = new float[cant_TOTAL_float];
	ult_pos_f = 0;

	// double_vector
	double_vector = new double[cant_TOTAL_double];
	ult_pos_d = 0;

	// complex_vector
	complex_vector = new struct Complex[cant_TOTAL_complex];
	ult_pos_z = 0;
	

	// Hago este bucle para cargar los valores en cada vector.
	do{
		fread(&tipo, sizeof(char), 1, pf); // Si yo le pido a la funcion fread() que lea 'tanto', se corre 'tanto'. 
		if(tipo == 'i')
		{
			if(cant_TOTAL_intigers > 0)
			{
				uint8_t k;
				fread(&cant_intigers, sizeof(uint8_t), 1, pf);
				if(ult_pos_i == 0) // Es la primera pasada.
				{
					for(k = 0 ; k < cant_intigers ; k++)
					{
						fread(&intigers_vector[k], sizeof(int), 1, pf);
					}
					ult_pos_i = ult_pos_i + k;
				}
				else
				{
					for(k = 0 ; k < cant_intigers ; k++)
					{
						fread(&intigers_vector[k + 1 + ult_pos_i], sizeof(int), 1, pf);
					}
					ult_pos_i = ult_pos_i + k;
				}
			}
		}
		if(tipo == 'f')
		{
			if(cant_TOTAL_float > 0)
			{
				uint8_t k;
				fread(&cant_float, sizeof(uint8_t), 1, pf);
				if(ult_pos_f == 0) // Es la primera pasada.
				{
					for(k = 0 ; k < cant_float ; k++)
					{
						fread(&float_vector[k], sizeof(float), 1, pf);
					}
					ult_pos_f = ult_pos_f + k;
				}
				else
				{
					for(k = 0 ; k < cant_float ; k++)
					{
						fread(&float_vector[k + 1 + ult_pos_f], sizeof(float), 1, pf);
					}
					ult_pos_f = ult_pos_f + k;
				}
			}
		}
		if(tipo == 'd')
		{
			if(cant_TOTAL_double > 0)
			{
				uint8_t k;
				fread(&cant_double, sizeof(uint8_t), 1, pf);
				if(ult_pos_d == 0) // Es la primera pasada.
				{
					for(k = 0 ; k < cant_double ; k++)
					{
						fread(&double_vector[k], sizeof(double), 1, pf);
					}
					ult_pos_d = ult_pos_d + k;
				}
				else
				{
					for(k = 0 ; k < cant_double ; k++)
					{
						fread(&double_vector[k + 1 + ult_pos_d], sizeof(double), 1, pf);
					}
					ult_pos_d = ult_pos_d + k;
				}
			}
		}
		if(tipo == 'z')
		{
			if(cant_TOTAL_complex > 0)
			{
				uint8_t k;
				fread(&cant_complex, sizeof(uint8_t), 1, pf);
				if(ult_pos_z == 0) // Es la primera pasada.
				{
					for(k = 0 ; k < cant_complex ; k++)
					{
						fread(&complex_vector[k], sizeof(Complex), 1, pf);
					}
					ult_pos_z = ult_pos_z + k;
				}
				else
				{
					for(k = 0 ; k < cant_complex ; k++)
					{
						fread(&complex_vector[k + 1 + ult_pos_z], sizeof(Complex), 1, pf);
					}
					ult_pos_z = ult_pos_z + k;
				}
			}
		}
		finale = ftell(pf);
    } while(finale < file_size); // Si finale = file_size, es porque el archivo ya se leyo completo.
	
	printf("\n");
	// Imprimiendo los vectores.
	if(cant_TOTAL_intigers > 0)
	{
		printf("\nVector numeros enteros:\n");
		for(uint8_t j = 0 ; j < cant_TOTAL_intigers ; j++)
		{
			printf("%d\t", intigers_vector[j]);
		}
		printf("\n");
	}
	if(cant_TOTAL_float > 0)
	{
		printf("\nVector numeros float:\n");
		for(uint8_t j = 0 ; j < cant_TOTAL_float ; j++)
		{
			printf("%f\t", float_vector[j]);
		}
		printf("\n");
	}
	if(cant_TOTAL_double > 0)
	{
		printf("\nVector numeros double:\n");
		for(uint8_t j = 0 ; j < cant_TOTAL_double ; j++)
		{
			printf("%lf\t", double_vector[j]);
		}
		printf("\n");
	}
	if(cant_TOTAL_complex > 0)
	{
		printf("\nVector numeros complejos:\n");
		for(uint8_t j = 0 ; j < cant_TOTAL_complex ; j++)
		{
			printf("%f + (%f)j\t", complex_vector[j].re, complex_vector[j].im);
		}
		printf("\n");
	}


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
	
	printf("\nFin del programa :D");
    return 0;
}

// Conclusión: El error está en el printf de los complex.