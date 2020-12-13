#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registrov
{
	char apynom[60];
	int matricula; //4 digitos como maximo
	int dni;
	char cel[25];
	char Acontra[10];
};

struct registro{
	char Ausuario[10];
	char Acontra[10];
	char apynom[60];
	int modulo;
};

int dibujarMenu();
void regusuario();
void regveterinario();

main(){
	int opc;
	do{
		opc = dibujarMenu();
		switch(opc){
			case 1:	regveterinario();	 	 
					 break;
					 
			case 2:	 regusuario();
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
	printf("********VENTAS********\n");
	printf("\t 1) Registrar Veterinario\n");
	printf("\t 2) Registrar Usuario Asistente o Adiminstrador\n");	
	printf("\t 3) Atenciones por Veterinarios\n");
	printf("\t 4) Ranking de Veterinarios por Atenciones\n\n");
	printf("\t 5) Cerrar la aplicacion\n");
	printf("******************\n");
	printf("Ingrese la opcion deseada: ");
	int opc;
	scanf("%d", &opc);
	return opc;
}

void regusuario(){
	FILE *usuario = fopen("usuarios.dat", "a+b");
	system("cls");
	registro us;
	bool u = false, p = false;
	int mayus=0, digitos=0, opcion, x;

	system("cls");
	printf("Elija usuario a crear(1.Usuario, 2.Administrador): ");
	scanf("%d", &opcion);
	if(opcion == 1)	us.modulo = 0;
	else		us.modulo = 1;	
	
	do{

		do
		{	system("cls");
			printf("Condiciones:\n-Entre 6 y 10 caracteres\n-Letras, numeros, simbolos(+,-,/,*,?,�,!,�)\n-Comenzar con letra minuscula\n-Tener al menos 2 letras mayusculas\n-Tener como maximo 3 digitos\n");
			printf("\nNombre de usuario: ");
			_flushall();	
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
		
		char contra[15], auxc[15], ull[10];
		int cmin=0, cmay=0, cnum=0, a, b, c1, lon1;
		bool ecar=false, econs=false, error=false, eletconsec=false;
		
		system("cls");
		printf("Condiciones:\n-Contener al menos una letra mayuscula, una minuscula y un numero\n-No contener ningun caracter de puntuacion, ni acentos, ni espacios\n-Solo contener caracteres alfanumericos\n-Tener entre 6 y 32 caracteres\n-No tener mas de 3 caracteres consecutivos\n-No tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas(ascendentemente)\n");
		_flushall();
		
		do{	
		printf("\nContrase�a: ");
		gets(contra);
		lon1 = strlen(contra);
            strcpy(auxc,contra);
            strlwr(auxc);
			
			
            if (lon1>=6 && lon1<=32)
            {  
                for (int i = 0; i < lon1; i++)
                {

                    if((contra[i]>='a') || (contra[i]<'z'))
                    {
                        cmin++;

                    }

                    if ((contra[i]>='A') || (contra[i]<'Z'))
                    {
                        cmay++;
      
                    }

                    if (contra[i]>=48 && contra[i]<=57)
                    {
                        cnum++;

                    }
                    

                    if ((contra[i]<47 || contra[i]>58) && (contra[i]<65 || contra[i]>90) && (contra[i]<97 || contra[i]>122))
                    {

                        ecar=true;
                    }

                    if (contra[i]>=48 && contra[i]<=57)
                    {
                        a=contra[i];
                        b=a+1;
                        c1=a+2;

                        if (contra[i+1]==b && contra[i+2]==c1)
                        {
                            econs=true;
 
                        }                    
                    } 
                    
                    
                    if(auxc[i]>96 && auxc[i]<123)
                    {                    
                        a=auxc[i];
                        b=a+1;
                        if(auxc[i+1]==b)
                        {
                            printf("\nLetra 1: %c",auxc[i]);
                            printf("\nLetra: %c",auxc[i+1]);
                            eletconsec=true;
                        }
                    }               
                }			

                if (cmin==1)
                {
                    printf("\nDebe tener al menos una letra minuscula!!\n");
                    error=true;
                }

                if (cmay<1)
                {
                    printf("\nDebe tener al menos una letra minuscula!!\n");
                    error=true;
                }

                if (cnum<1)
                {
                    printf("\nDEBE TENER AL MENOS 1 NUMERO!!\n");
                    error=true;
                }
                

                if(ecar==true)
                {
                    printf("\nDEBE CONTENER SOLO CARACTERES ALFANUMERICOS!!\n");
                    error=true;
                }
                
                
 
                if (econs==true)
                {
                    printf("\nNO DEBE TENER MAS DE 3 NUMEROS CONSECUTIVOS!!\n");
                    error=true;                
                }
                

                if (eletconsec==true)
                {
                    printf("\nNO DEBE TENER LETRAS CONSECUTIVAS!!\n");
                    error=true;
                }
            }
            
            else error=true;
            
        }while (error==true);

        if (error==false)
        {       
            strcpy(us.Acontra, contra);
            printf("\nIngrese el apellido y nombre: ");        
            _flushall();
            gets(us.apynom);
			fwrite(&us, sizeof(registro), 1, usuario);
            do{
                printf("\nDesea agregar otro usuario? (SI:1 , NO:0): ");
                scanf("%d" ,&x);
            }while (x!=0 && x!=1);
        }
        
    	printf("\n");
    }while (x==1);
	

	fclose(usuario);
}

void regveterinario(){
	FILE *veterinario = fopen("veterinarios.dat", "a+b");
	system("cls");
	registrov vet;
	int mayus=0, digitos=0, x;

	system("cls");
	
	do{
		printf("Ingrese matricula(max. 4 digitos): ");
		scanf("%d", &vet.matricula);
		
		printf("Ingrese celular: ");
		_flushall();
		gets(vet.cel);
		
		char contra[15], auxc[15], ull[10];
		int cmin=0, cmay=0, cnum=0, a, b, c1, lon1;
		bool ecar=false, econs=false, error=false, eletconsec=false;
		
		system("cls");
		printf("Condiciones:\n-Contener al menos una letra mayuscula, una minuscula y un numero\n-No contener ningun caracter de puntuacion, ni acentos, ni espacios\n-Solo contener caracteres alfanumericos\n-Tener entre 6 y 32 caracteres\n-No tener mas de 3 caracteres consecutivos\n-No tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas(ascendentemente)\n");
		_flushall();
		
		do{	
		printf("\nContrase�a: ");
		gets(contra);
		lon1 = strlen(contra);
            strcpy(auxc,contra);
            strlwr(auxc);

            if (lon1>=6 && lon1<=32)
            { 	
                for (int i = 0; i < lon1; i++)
                {

                    if((contra[i]>='a') || (contra[i]<'z'))
                    {
                        cmin++;

                    }

                    if ((contra[i]>='A') || (contra[i]<'Z'))
                    {
                        cmay++;
      
                    }

                    if (contra[i]>=48 && contra[i]<=57)
                    {
                        cnum++;

                    }
                    

                    if ((contra[i]<47 || contra[i]>58) && (contra[i]<65 || contra[i]>90) && (contra[i]<97 || contra[i]>122))
                    {

                        ecar=true;
                    }

                    if (contra[i]>=48 && contra[i]<=57)
                    {
                        a=contra[i];
                        b=a+1;
                        c1=a+2;

                        if (contra[i+1]==b && contra[i+2]==c1)
                        {
                            econs=true;
 
                        }                    
                    } 
                    

                    
                    if(auxc[i]>96 && auxc[i]<123)
                    {                    
                        a=auxc[i];
                        b=a+1;
                        if(auxc[i+1]==b)
                        {
                            printf("\nLetra 1: %c",auxc[i]);
                            printf("\nLetra: %c",auxc[i+1]);
                            eletconsec=true;
                        }
                    }               
                }			

                if (cmin==1)
                {
                    printf("\nDebe tener al menos una letra minuscula!!\n");
                    error=true;
                }

                if (cmay<1)
                {
                    printf("\nDebe tener al menos una letra minuscula!!\n");
                    error=true;
                }

                if (cnum<1)
                {
                    printf("\nDEBE TENER AL MENOS 1 NUMERO!!\n");
                    error=true;
                }
                

                if(ecar==true)
                {
                    printf("\nDEBE CONTENER SOLO CARACTERES ALFANUMERICOS!!\n");
                    error=true;
                }
                
                
 
                if (econs==true)
                {
                    printf("\nNO DEBE TENER MAS DE 3 NUMEROS CONSECUTIVOS!!\n");
                    error=true;                
                }
                

                if (eletconsec==true)
                {
                    printf("\nNO DEBE TENER LETRAS CONSECUTIVAS!!\n");
                    error=true;
                }     
            }
            
            else error=true;
            
        }while (error==true);

        if (error==false)
        {       
            strcpy(vet.Acontra, contra);
            printf("\nIngrese el apellido y nombre: ");        
            _flushall();
            gets(vet.apynom);
			fwrite(&vet, sizeof(registro), 1, veterinario);
            do{
                printf("\nDesea agregar otro veterinario? (SI:1 , NO:0): ");
                scanf("%d" ,&x);
            }while (x!=0 && x!=1);
        }
        
    	printf("\n");
    }while (x==1);
	

	fclose(veterinario);
}