#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fecha
{
	int dia, mes, anio;
};

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
	int atendidos=0;
};

struct mascota
{
	char apynomM[60];
	char domicilio[60];
	int DNIdueno;
	char localidad[60];
	fecha fec;
	int edad;
	float peso;
	char telefono[25];
};

struct turnos
{
	int matvet;
	fecha fec;
	int DNId;
	char detAten[380];
};

int dibujarMenu();
bool iniciarse(FILE *f, int &matvet);
void lista(FILE *f);
bool evolucion(FILE *f);
void incontador(FILE *f, int matvet);

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

	bool inicio = false, borrar = false;
	int matvet;
	
	int opc;
	do{
		opc = dibujarMenu();
		switch(opc){
			case 1:	inicio = iniciarse(veterinarios, matvet);		 	 
					 break;
					 
			case 2:	if(inicio == true)
						{
							lista(turnos);
					 	}
						 else printf("\nPrimero debe Iniciar sesion!\n");
					 break;
					 
			case 3: if(inicio == true)
						{
							borrar = evolucion(turnos);
					 	}
						 else printf("\nPrimerio debe Iniciar sesion!\n");	 
						 if(borrar == true) incontador(veterinarios, matvet);
					 break;
					 
		}
		printf("\n");
		system("pause");
	}while(opc != 4);
	
	fclose(mascotas);
	fclose(turnos);
	fclose(veterinarios);
}

int dibujarMenu(){
	system("cls");
	printf("****************** Modulo Consultorio **********************\n");
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
bool iniciarse(FILE *f, int &matvet)
{
	rewind(f);
	veterinario log;
	registrov veti;
	bool iniciado = false;
	int valor;
	system("cls");
	
	do
	{
		printf("Ingrese numero de matricula: ");
		scanf("%d", &log.Matricula);
	} while (log.Matricula <= 999 || log.Matricula >= 9999);
	matvet = log.Matricula;

	printf("\nIngrese contrasena: ");
	_flushall();
	gets(log.contra);
	
    fread(&veti, sizeof(registrov), 1, f);
    while(!feof(f))
    {
        valor = strcmp(log.contra, veti.Acontra);
        
        if(log.Matricula == veti.matricula)
		{
			if(valor == 0)
			{
				printf("\n\nSesion iniciada correctamente\n\n");
				iniciado = true;
			}

		}
        fread(&veti, sizeof(registrov), 1, f);
    }
    if(iniciado == false) printf("\n\nEl nombre de usuario y/o contrasena no coinciden\n\n");
    return iniciado;
}

void lista(FILE *f)
{
	rewind(f);
	system("cls");
	turnos tur;
	int c=0;
	int nada;

	

	fread(&tur, sizeof(turnos), 1, f);
	while(!feof(f))
	{
		nada = strcmp(tur.detAten, "");

		if(nada == 0)
		{
			printf("\n\n\nTurno %d\n\n", c+1);

			printf("Matricula de Veterinario --> %d\n", tur.matvet);
			printf("Fecha --> %d/%d/%d\n",tur.fec.dia, tur.fec.mes, tur.fec.anio);
			printf("DNI(dueno) --> %d\n", tur.DNId);
			fread(&tur, sizeof(turnos), 1, f);
		}
		else fread(&tur, sizeof(turnos), 1, f);;
	}
}

bool evolucion(FILE *f)
{
	rewind(f);
	system("cls");
	turnos tur;
	bool borrar = false;
	int dni;


	printf("Ingrese DNI: ");
	scanf("%d",&dni);
	system("cls");

	fread(&tur, sizeof(turnos), 1, f);
	while(!feof(f))
	{
		if(dni == tur.DNId)
		{
			borrar = true;
			printf("Detalle de atencion:\n-");
			_flushall();
			gets(tur.detAten);

			fread(&tur, sizeof(turnos), 1, f);
		}
		else fread(&tur, sizeof(turnos), 1, f);
	}
	if(borrar == true)
	{
		printf("\n\nEvolucion registrada\n\n");
		fwrite(&tur, sizeof(turnos), 1, f);
	}
	else printf("\n\nEvolucion no registrada\n\n");

	return borrar;
}
void incontador(FILE *f, int matvet)
{
	rewind(f);
	registrov reg;

	fread(&reg, sizeof(registrov), 1, f);
	while(!feof(f))
	{
		if(matvet == reg.matricula)
		{
			reg.atendidos++;
			fwrite(&reg, sizeof(registrov), 1, f);
		}
		fread(&reg, sizeof(registrov), 1, f);
	}
}