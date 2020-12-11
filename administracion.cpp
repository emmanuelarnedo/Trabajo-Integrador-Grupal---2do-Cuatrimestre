#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro
{
	char usuario[10];
	char Ausuario[10];
	char contra[10];
	char Acontra[10];
	char apynom[60];
	int matricula;
	int dni;
	char telefono[25];
};

int dibujarMenu();
void regusuario(int &creg);

main()
{
	int opc, creg=0;
	
	do{
		opc = dibujarMenu();
		switch(opc){
			case 1:				 	 
					 break;
					 
			case 2:	 regusuario(creg);
					 break;
					 
			case 3:				 
					 break;
					 
			case 4:
                    break;
		}
		system("pause");
	}while(opc != 5);
	exit(1);
}

int dibujarMenu(){
	system("cls");
	printf("*********************VENTAS*************************\n");
	printf("\t 1) Registrar Veterinario\n");
	printf("\t 2) Registrar Usuario Asistente\n");
	printf("\t 3) Atenciones por Veterinarios\n");
	printf("\t 4) Ranking de Veterinarios por Atenciones\n\n");
	printf("\t 5) Cerrar la aplicacion\n");
	printf("****************************************************\n");
	printf("ingrese la opcion deseada: ");
	int opc;
	scanf("%d", &opc);
	return opc;
}

void regusuario(int &creg)
{
	FILE *usuario = fopen("usuarios.dat", "a+b");
	system("cls");
	registro us;
	bool u = false, p = false;
	int mayus=0, digitos=0;

	system("cls");

	if(creg == 0)
	{
		printf("Cree usuario administrador\n\n\n");
		_flushall();
		do
		{
			printf("Condiciones:\n-Entre 6 y 10 caracteres\n-Letras, numeros, simbolos(+,-,/,*,?,¿,!,¡)\n-Comenzar con letra minuscula\n-Tener al menos 2 letras mayusculas\n-Tener como maximo 3 digitos\n");
			printf("\nNombre de usuario: ");
			gets(us.Ausuario);
			if(strlen(us.Ausuario)>= 6 && strlen(us.Ausuario) <= 10)
			{
				if(us.Ausuario[0] >= 97 && us.Ausuario[0] <= 122)
				{
					for(int i=0; i < strlen(us.Ausuario); i++)
					{
						if (us.Ausuario[i] >=65 && us.Ausuario[i] <=90) mayus++;
						if (us.Ausuario[i] == 43 || us.Ausuario[i] == 45 || us.Ausuario[i] == 47 || us.Ausuario[i] == 42 ||
						 us.Ausuario[i] == 63 || us.Ausuario[i] == 168 || us.Ausuario[i] == 173 || us.Ausuario[i] == 33 || us.Ausuario[i] >= 48 || us.Ausuario[i] <= 57)
						 digitos++;
						 if(mayus >= 2 && digitos <= 3)
						 {
						 	if(us.Ausuario[i] >= 65 || us.Ausuario[i] <= 90 || us.Ausuario[i] >= 97 || us.Ausuario[i] <= 122 || us.Ausuario[i] >= 48 || us.Ausuario[i] <= 57 || us.Ausuario[i] == 43 || 
								 us.Ausuario[i] == 45 || us.Ausuario[i] == 47 || us.Ausuario[i] == 42 ||
								 us.Ausuario[i] == 63 || us.Ausuario[i] == 168 || us.Ausuario[i] == 173 || us.Ausuario[i] == 33)
								 {
								 	u = true;
								 }
						 }
					}
				}
			}
		}while(u == false);
		
		system("cls");
		printf("Condiciones:\n-Contener al menos una letra mayuscula, una minuscula y un numero\n-No contener ningun caracter de puntuacion, ni acentos, ni espacios\n-Solo contener caracteres alfanumericos\n-Tener entre 6 y 32 caracteres\n-No tener mas de 3 caracteres consecutivos\n-No tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas(ascendentemente)\n");
		

		creg = 1;
		fwrite(&us, sizeof(registro), 1, usuario);
	}
	else
	{

	}
	fclose(usuario);
}
