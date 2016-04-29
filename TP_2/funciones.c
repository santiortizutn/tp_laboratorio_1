
#include "funciones.h"
#define C 20

int validaMax(int min, int max)
{
    int valor;
    scanf("%d",&valor);

    while(valor < min || valor > max)
    {
        printf("\n  ERROR, ingrese valor nuevamente: ");
        scanf("%d", &valor);
    }

    return valor;

/*toma un valor numerico ingresado por el usuario y verifica
 que cumpla la condicion especificada en la funcion y devuelve.*/
}

char validaRta(char rta)
{
    rta = tolower(getche());

    while(rta != 's' && rta != 'n')
    {
        printf("\n  ERROR, ingrese nuevamente(s/n): ");
        rta = tolower(getche());
    }
    return rta;

/*toma un caracter ingresado por el usuario y verifica
 que cumpla la condicion especificada en la funcion y devuelve.*/
}

void inicializar(EPersona personas[])
{
    int i;
    for(i = 0; i < C; i++)
    {
        strcpy(personas[i].nombre, "\0");
        personas[i].dni = 0;
        personas[i].edad = 0;
        personas[i].estado = 0;
    }
/*toma cada variable de la estructura y la inicializa en 0
para que no se acumule basura y ande mal el progama.*/
}


int obtenerEspacioLibre(EPersona personas[])
{
    int ind = -1, i;

	for(i = 0; i < C ; i++)
    {
        if(personas[i].estado == 0)
        {
            ind = i;
            break;
	    }
    }

	return ind;

/*verifica a traves del estado la disponibilidad del registro,
 devuelve un indice que varia si el registro esta ocupado o no.*/
}


void altas(EPersona personas[])
{
    int i, j, ind, encontro = 0;
    long int aux;
    char auxNom[100];

    ind = obtenerEspacioLibre(personas);

    if(ind != -1)
    {
        printf("  INGRESE DATOS: \n");

        printf("\n  Ingrese DNI: ");
        aux = validaMax(1000000, 60000000);

        for(i = 0; i < C; i++)
        {
            if(aux == personas[i].dni)
            {
                encontro = 1;//encontro en true
                break;
            }
        }

        if(!encontro)//entra si encontro = 0
		{
            personas[ind].dni = aux;

		    printf("\n  Ingrese nombre: ");
		    fflush(stdin);
            gets(auxNom);

            while(strlen(auxNom) > 49)
            {
                printf("\n  ERROR, puede ingresar hasta 49 caracteres: ");
                fflush(stdin);
                gets(auxNom);
            }

            strlwr(auxNom);
            auxNom[0] = toupper(auxNom[0]);

            for(j = 0; j < 50; j++)
            {
                if(auxNom[j] == ' ')
                {
                    auxNom[j + 1] = toupper(auxNom[j + 1]);
                }
            }


            strcpy(personas[ind].nombre, auxNom);

            printf("\n  Ingrese edad: ");
            personas[ind].edad = validaMax(1, 99);

            personas[ind].estado = 1;

		}

		else
		{
			printf("\n  El DNI ingresado ya existe, ingrese datos nuevamente.  \n\n");
			system("pause");
			system("cls");
		}


    }

    else
    {
        printf("\n  No queda espacio para mas personas. \n\n\n");
        system("pause");
    }

/*verifica la disponibilidad del registro con una funcion. Si hay espacio,
se piden los datos correspondientes y se veifica que sean correctos,
y se muestra un mensaje si no hay espacio disponible o si hay un Dni repetido.*/

}//llave de funcion



void borrar(EPersona personas[])
{
    long int aux;
    int i, flag = 0;
    char rta = 's';

    printf("\n  Ingrese DNI de la persona que desea borrar: ");
    aux = validaMax(1000000, 60000000);

    for(i = 0; i < C; i++)
    {
        if(aux == personas[i].dni)
        {
            printf("\n  DATOS:  \n");
            printf("\n  Nombre: %s\n  DNI: %ld\n  Edad: %d\n", personas[i].nombre, personas[i].dni, personas[i].edad);
            printf("\n  Desea elminiar esta persona? (s/n) ");
            rta = validaRta(rta);

            if(rta == 's')
            {
                strcpy(personas[i].nombre, "\0");
                personas[i].dni = 0;
                personas[i].edad = 0;
                personas[i].estado = 0;

                printf("\n  Persona eliminada. \n\n\n");
            }
            else
			{
				printf("\n  La persona no fue eliminada. \n\n\n");
				//system("pause");
			}
			flag = 1;
			break;

        }
    }

    if(flag == 0)
    {
        printf("\n  DNI inexistente. \n\n\n");
        //system("  pause");
    }

/*elimina registros. se utiliza una busqueda por dni que
compara el dato ingresa con el dato del registro que se desea eliminar,
si hay igualdad el registro se elimina por completo,
sino se muestra el mensaje correspondiente.*/

}//llave de funcion


void listar(EPersona personas[])
{
    int i,j;
	EPersona auxPersona;

	for(i = 0; i < C - 1; i++)
    {
        for(j = i + 1; j < C; j++)
        {
            if(strcmp(personas[i].nombre, personas[j].nombre) > 0)
			{
				auxPersona = personas[i];
				personas[i] = personas[j];
				personas[j] = auxPersona;
			}
        }
    }

    for(i = 0; i < C; i++)
	{
        if(personas[i].estado != 0)
        {
            printf("\n  Nombre: %s\n  DNI: %ld\n  Edad: %d\n", personas[i].nombre, personas[i].dni, personas[i].edad);
        }

    }

/*ordena por nombre(de la A a la Z) los registros y los muestra con sus datos correspondientes,
a menos que no haya sido cargado ningun dato*/

}


void graficar(EPersona personas[])
{
    int i, men18 = 0, de19a35 = 0, may35 = 0, flag = 0, mayor;

    for(i = 0; i < C; i++)
    {

        if(personas[i].edad > 35)
        {
            may35++;
        }
        else
        {
            if(personas[i].edad > 18 && personas[i].edad <= 35)
            {
                de19a35++;
            }
            else
            {
                if(personas[i].edad > 0 && personas[i].edad <= 18)
                {
                    men18++;
                }
            }
        }
    }


    if(men18 >= de19a35 && men18 >= may35)
    {
        mayor = men18;
    }
    else
        {
            if(de19a35 >= men18 && de19a35 >= may35)
            {
                mayor = de19a35;
            }
            else
                {
                    mayor = may35;
                }
        }

    for(i = mayor; i > 0; i--)
    {
        if(i < C)
        {
            printf("  %02d|", i);
        }
        else
        {
            printf("  %02d|", i);
        }


        if(i <= men18)
        {
            printf(" *");
        }

        if(i <= de19a35)
        {
            flag = 1;
            printf("\t    *");
        }

        if(i <= may35)
        {
            if(flag == 0)
            {
                printf("\t\t  *");
            }

            if(flag == 1)
            {
                printf("\t  *");
            }

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("  --+-----------------");
    printf("\n    |<18  19-35  >35\n");
    printf("\n      %d     %d \t  %d  \n\n", men18, de19a35, may35);
    system("pause");
    system("cls");

/*toma las edades de cada persona ingresada y valida 3 rangos de edad,
muestra a traves de un grafico con los 3 rangos de edad la cantidad
de personas ingresadas en cada rango*/



}//funcion











