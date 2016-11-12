

#include "funciones.h"


int main()
{
    int opcion = 0, cont = 0;
    EMovie movie[C];
    FILE *pArch;
    char seguir = 's';


    pArch = fopen("movie.dat", "rb+");

	if(pArch == NULL)
	{
		pArch = fopen("movie.dat", "wb+");
		if(pArch == NULL)
		{
		    printf("\nNo se puede crear el registro.");
			exit(1);
		}
	}

    while(seguir == 's')
    {
        printf("\n 1- Agregar pelicula. \n");
        printf(" 2- Borrar pelicula. \n");
        printf(" 3- Modificar película. \n");
        printf(" 4- Generar pagina web. \n");
        printf(" 5- Salir. \n");

        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                agregarPelicula(movie, pArch);
                break;
            case 2:
                borrarPelicula(movie, pArch);
                break;
            case 3:
                modificarPelicula(movie, pArch);
                break;
            case 4:
                generarPagina(movie);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Opcion invalida, reingrese: ");
                break;
        }
    }

    fclose(pArch);

    return 0;
}
