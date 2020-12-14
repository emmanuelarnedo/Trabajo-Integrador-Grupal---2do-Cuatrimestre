#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct veterinario
{
	int Matricula;
	char contra[10];
};

struct registrov
{
	char apynom[60];
	int matricula;
	int dni;
	char cel[25];
	char Acontra[10];
};

int dibujarMenu();
bool iniciarse(FILE *f);

main()
{
	FILE *mascotas = fopen("mascotas.dat", "a+b");
	FILE *turnos = fopen("turnos.dat", "rb");
	FILE *veterinarios = fopen("veterinarios.dat", "rb");
	if(veterinarios == NULL)
	{
		printf("Veterinarios.dat no ha sido creado.\n\n");
		system("pause");
		exit(1);
	}
	bool inicio = false;
	
	int opc;
	do{
		opc = dibujarMenu();
		switch(opc){
			case 1:	inicio = iniciarse(veterinarios);			 	 
					 break;
					 
			case 2:	if(inicio == true)
						{
			
					 	}
						 else printf("\nPrimerio debe Iniciar sesion!\n");
					 break;
					 
			case 3: if(inicio == true)
						{
					
					 	}
						 else printf("\nPrimerio debe Iniciar sesion!\n");	 
					 break;
					 
		}
		printf("\n");
		system("pause");
	}while(opc != 4);
	
	fclose(veterinarios);
	
}

int dibujarMenu(){
	system("cls");
	printf("****************** Modulo de Asistente **********************\n");
	printf("\t 1) Iniciar Sesion   \n");
	printf("\t 2) Visualizar lista de espera de turnos						\n");
	printf("\t 3) Registrar Evolucion de la mascota							\n\n");
    printf("\t 4) Cerrar la aplicacion								\n");
	printf("*************************************************************\n");
	printf("\nIngrese la opcion deseada -> ");
	int opc;
	scanf("%d", &opc);
	return opc;
}
bool iniciarse(FILE *f)
{
	veterinario log;
	registrov veti;
	bool iniciado = false;
	int valor;
	system("cls");
	
	printf("Ingrese numero de matricula: ");
	scanf("%d", &log.Matricula);
	printf("\nIngrese contrasena: ");
	_flushall();
	gets(log.contra);
	
    rewind(f);
    fread(&veti, sizeof(registrov), 1, f);
    while(!feof(f))
    {
        valor = strcmp(log.contra, veti.Acontra);
        
        if(log.Matricula == veti.matricula && valor == 0)
		{
			printf("\n\nSesion iniciada correctamente\n\n");
			iniciado = true;
		}
        fread(&veti, sizeof(registrov), 1, f);
    }
    if(iniciado == false) printf("\n\nEl nombre de usuario y/o contrasena no coinciden\n\n");
    return iniciado;
}
