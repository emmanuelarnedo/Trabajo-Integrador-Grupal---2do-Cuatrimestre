#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fecha
{
	int dia, mes, anio;
};

struct registro
{
	char Ausuario[10];
	char Acontra[10];
	char apynom[60];
	int modulo;
};

struct usuario
{
	char usuario[10];
	char contra[10];
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
bool iniciars(FILE *f);
void regmascota(FILE *f);
void regturnos(FILE *f);

main()
{
	FILE *mascotas = fopen("mascotas.dat", "a+b");
	FILE *turnos = fopen("turnos.dat", "a+b");
	FILE *usuario = fopen("usuarios.dat", "rb");

	bool iniciado = false;
	
	int opc;
	do{
		opc = dibujarMenu();
		switch(opc){
			case 1:	iniciado = iniciars(usuario);			 	 
					 break;
					 
			case 2:	if(iniciado == true)
						{
							regmascota(mascotas);
					 	}
						 else printf("\n¡Inicie sesion!\n");
					 break;
					 
			case 3: if(iniciado == true)
						{
							
					 	}
						 else printf("\n¡Inicie sesion!\n");	 
					 break;
					 
			case 4: if(iniciado == true)
						{
							
					 	}
						 else printf("\n¡Inicie sesion!\n");
                    break;
		}
		system("pause");
	}while(opc != 5);
	
	fclose(mascotas);
	fclose(usuario);
}

int dibujarMenu(){
	system("cls");
	printf("*********************Modulo del asistente*************************\n");
	printf("\t 1) Iniciar Sesion\n");
	printf("\t 2) Registrar Mascota\n");
	printf("\t 3) Registrar Turno\n");
	printf("\t 4) Listado de Atenciones por Veterinario y Fecha\n");
    printf("\t 5) Cerrar la aplicacion\n");
	printf("****************************************************\n");
	printf("ingrese la opcion deseada: ");
	int opc;
	scanf("%d", &opc);
	return opc;
}

bool iniciars(FILE *f)
{
	usuario login;
	registro us;
	bool iniciado = false;
	int valor, valor2;
	system("cls");
	
	printf("Ingrese nombre de usuario: ");
	_flushall();
	gets(login.usuario);
	printf("\nIngrese contrasena: ");
	gets(login.contra);
	
    rewind(f);
    fread(&us, sizeof(registro), 1, f);
    while(!feof(f))
    {
        valor = strcmp(login.usuario, us.Ausuario);
        valor2 = strcmp(login.contra, us.Acontra);
        
        if(valor == 0 && valor2 == 0)
		{
			printf("\n\nSesion iniciada correctamente\n\n");
			iniciado = true;
		}
        fread(&us, sizeof(registro), 1, f);
    }
    if(iniciado == false) printf("\n\nEl nombre de usuario y/o contrasena no coinciden\n\n");
    return iniciado;
}

void regmascota(FILE *f)
{
	mascota m;
	system("cls");

	printf("Registro de mascota\n\n\n");
	printf("Apellido(dueno) y nombre(mascota): ");
	_flushall();
	gets(m.apynomM);

	printf("\nDomicilio: ");
	gets(m.domicilio);

	printf("\nDNI(dueno): ");
	scanf("%d", &m.DNIdueno);

	printf("\nLocalidad: ");
	_flushall();
	gets(m.localidad);

	printf("\n\nFecha de nacimiento\n\n");
	printf("Dia: ");
	scanf("%d", &m.fec.dia);
	printf("\nMes: ");
	scanf("%d", &m.fec.mes);
	printf("\nAnio: ");
	do
	{
		scanf("%d", &m.fec.anio);
	} while (m.fec.anio <= 1900 && m.fec.anio >= 2020);
	
	m.edad = 2020 - m.fec.anio;

	printf("\nPeso: ");
	scanf("%f", &m.peso);

	printf("\nTelefono: ");
	_flushall();
	gets(m.telefono);

	fwrite(&m, sizeof(mascota), 1, f);
}

void regturnos(FILE *f)
{
	
}