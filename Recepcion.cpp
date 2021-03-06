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

struct registrov
{
	char apynom[60];
	int matricula;
	int dni;
	char cel[25];
	char Acontra[10];
	int atendidos;
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
void regturnos(FILE *t, FILE *f, FILE *M);
void listatencion(FILE *t, FILE *M);

main()
{
	FILE *mascotas = fopen("mascotas.dat", "a+b");
	FILE *turnos = fopen("turnos.dat", "a+b");
	FILE *usuario = fopen("usuarios.dat", "rb");
	FILE *veterinarios = fopen("veterinarios.dat", "rb");
	if(veterinarios == NULL)
	{
		printf("Veterinarios.dat no ha sido creado.\n\n");
		system("pause");
		exit(1);
	}
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
						 else printf("\nPrimero debe Iniciar sesion!\n\n");
					 break;
					 
			case 3: if(iniciado == true)
						{
							regturnos(turnos, veterinarios, mascotas);
					 	}
						 else printf("\nPrimero debe Iniciar sesion!\n\n");	 
					 break;
					 
			case 4: if(iniciado == true)
						{
							listatencion(turnos, mascotas);
					 	}
						 else printf("\nPrimero debe Iniciar sesion!\n\n");
                    break;
		}
		printf("\n");
		system("pause");
	}while(opc != 5);
	
	fclose(mascotas);
	fclose(turnos);
	fclose(usuario);
	fclose(veterinarios);
}

int dibujarMenu(){
	system("cls");
	printf("****************** Modulo Asistente *************************\n");
	printf("\t 1) Iniciar Sesion   \n");
	printf("\t 2) Registrar Mascota							\n");
	printf("\t 3) Registrar Turno							\n");
	printf("\t 4) Listado de Atenciones por Veterinario y Fecha	\n");
    printf("\t 5) Cerrar la aplicacion								\n");
	printf("*************************************************************\n");
	printf("\nIngrese la opcion deseada -> ");
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
	
	printf("- Ingrese nombre de usuario: ");
	_flushall();
	gets(login.usuario);
	printf("\n- Ingrese contrasena: ");
	gets(login.contra);
	
    rewind(f);
    fread(&us, sizeof(registro), 1, f);
    while(!feof(f))
    {
        valor = strcmp(login.usuario, us.Ausuario);
        valor2 = strcmp(login.contra, us.Acontra);
        
        if(valor == 0 && valor2 == 0)
		{
			printf("\n\n -Sesion iniciada correctamente.- \n\n");
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

	printf(" *Registro de mascota*\n\n\n");
	printf("-> Apellido(dueno) y nombre(mascota): ");
	_flushall();
	gets(m.apynomM);

	printf("\n-> Domicilio: ");
	gets(m.domicilio);

	printf("\n-> DNI(dueno): ");
	scanf("%d", &m.DNIdueno);

	printf("\n-> Localidad: ");
	_flushall();
	gets(m.localidad);

	printf("\n\n* Fecha de nacimiento *\n\n");
	printf("-> Dia: ");
	scanf("%d", &m.fec.dia);
	printf("\n-> Mes: ");
	scanf("%d", &m.fec.mes);
	printf("\n-> Anio: ");
	do
	{
		scanf("%d", &m.fec.anio);
	} while (m.fec.anio <= 1900 && m.fec.anio >= 2020);
	
	m.edad = 2020 - m.fec.anio;

	printf("\n-> Peso(Kg): ");
	scanf("%f", &m.peso);

	printf("\n-> Telefono: ");
	_flushall();
	gets(m.telefono);

	fwrite(&m, sizeof(mascota), 1, f);
}

void regturnos(FILE *t, FILE *f, FILE *M)
{
	fclose(M);
	M = fopen("mascotas.dat", "rb");
	rewind(f);
	
	registrov reg;
	turnos tur;
	mascota m;
	bool exito = false;
	system("cls");
	
	printf("* Registro de Turnos* \n\n\n");
	printf("- Matricula de veterinario: ");
	scanf("%d", &tur.matvet);
	
	fread(&reg, sizeof(registrov), 1, f);
	while(!feof(f))
	{
		if(tur.matvet == reg.matricula)
		{
			printf("\n\n* Fecha *\n\n");
			printf("-> Dia: ");
			scanf("%d", &tur.fec.dia);
			printf("\n-> Mes: ");
			scanf("%d", &tur.fec.mes);
			printf("\n-> Anio: ");
			do{
				scanf("%d", &tur.fec.anio);
			} while (tur.fec.anio <= 1900 && tur.fec.anio >= 2020);

			fread(&m, sizeof(mascota), 1, M);
			printf("\n-> DNI del dueno: ");
			scanf("%d", &tur.DNId);
			while(!feof(M))
			{
				if(tur.DNId == m.DNIdueno)
				{
					strcpy(tur.detAten, "");
					exito = true;	
				}
				fread(&m, sizeof(mascota), 1, M);
			}
		}
		fread(&reg, sizeof(registrov), 1, f);
	}


	if(exito == true)
	{
		printf("\nTurno registrado con exito\n\n");
		fwrite(&tur, sizeof(turnos), 1, t);
	}
	else printf("\nTurno no registrado\n\n");

	fclose(M);
	M = fopen("mascotas.dat", "a+b");
}

void listatencion(FILE *t, FILE *M)
{
	system("cls");
	fclose(t);
	t = fopen("turnos.dat", "rb");
	fclose(M);
	M = fopen("mascotas.dat", "rb");

	mascota mas;
	turnos tur;
	int matricula, dia, mes, anio, nada;
	bool confirm = false;

	printf("Buscar informe de mascota\n\n");
	printf("Matricula de veterinario: ");
	scanf("%d",&matricula);
	printf("\nFecha de atencion\n");
	printf("\n-Dia: ");
	scanf("%d",&dia);
	printf("\n-Mes: ");
	scanf("%d",&mes);
	printf("\n-Anio: ");
	scanf("%d",&anio);
	
	rewind(t);
	fread(&tur, sizeof(turnos), 1, t);
	while(!feof(t))
	{
		nada = strcmp(tur.detAten, "");

		if(nada != 0)
		{	
			if(matricula == tur.matvet && dia == tur.fec.dia && mes == tur.fec.mes && anio == tur.fec.anio)
			{
				
				fread(&mas, sizeof(mascota), 1, M);
				while(!feof(M))
				{
					if(tur.DNId == mas.DNIdueno)
					{
						confirm = true;

						system("cls");
						printf("Listado de mascotas atendidas: \n\n");
						printf("------------------------------\n");
						printf("\nMascota: ");
						puts(mas.apynomM);
						printf("\n");
						puts(tur.detAten);
					}
					fread(&mas, sizeof(mascota), 1, M);
				}
			}
		}
		fread(&tur, sizeof(turnos), 1, t);
	}

	fclose(t);
	fclose(M);
	t = fopen("turnos.dat", "a+b");
	M = fopen("mascotas.dat", "a+b");
}
