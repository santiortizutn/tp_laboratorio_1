#include "funciones.h"

void validaCadena(char cadena[], int tam)
{

    while(strlen(cadena) > tam - 1)
    {
        printf("\n  ERROR, puede ingresar hasta %d caracteres: ", tam - 1);
        fflush(stdin);
        gets(cadena);
    }

}

void validaRta(char respuesta)
    {
        while(respuesta != 's' && respuesta != 'n')
        {
            printf("\nERROR, ingrese una opcion correcta (s/n): ");
            fflush(stdin);
            respuesta = tolower(getche());
        }
    }



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

/* toma un valor numerico ingresado por el usuario y verifica
 que cumpla la condicion especificada en la funcion y devuelve.*/
}

void inicEstado(EMovie movie[])
{
    int i;
    for(i = 0; i < C; i++)
    {
        movie[i].estado = 0;
    }
}


void agregarPelicula(EMovie movie[], FILE *p)
{
    char auxTit[100], auxGen[100], auxDes[100], auxLink[100];
    int i;

    inicEstado(movie);

    for(i = 0; i < C; i++)
    {
        if(movie[i].estado == 0)
        {

            printf(" \nIngrese titulo: ");
            fflush(stdin);
            gets(movie[i].titulo);

            validaCadena(auxTit, 20);
            strcpy(movie[i].titulo, auxTit);

            printf("\nIngrese genero: ");
            fflush(stdin);
            gets(movie[i].genero);

            validaCadena(auxGen, 20);
            strcpy(movie[i].genero, auxGen);

            printf("\nDescripcion: ");
            fflush(stdin);
            gets(movie[i].descripcion);

            validaCadena(auxDes, 50);
            strcpy(movie[i].descripcion, auxDes);

            printf("\nLink de imagen: ");
            fflush(stdin);
            gets(movie[i].linkImagen);

            validaCadena(auxLink, 50);
            strcpy(movie[i].linkImagen, auxLink);

            printf("\nDuracion: ");
            movie[i].duracion = validaMax(30, 300);

            printf("\nPuntaje: ");
            movie[i].puntaje = validaMax(0, 100);

            movie[i].estado = 1;

            fseek(p, 0L, SEEK_END);
            fwrite(&movie, sizeof(EMovie), 1, p);
            break;
        }
    }
}


void borrarPelicula(EMovie movie[], FILE *p)
{
    char auxTit[21];
    char rta;
    int i = 0;

    printf("\nIngrese el titulo de la pelicula a borrar: ");
    fflush(stdin);
    gets(auxTit);

    rewind(p);
    while(!feof(p))
    {
        fread(&movie, sizeof(EMovie), 1, p);

        if(strcmp(auxTit, movie[i].titulo) == 0 && movie[i].estado != 0)
        {
            printf("\nLos datos encontrados son:");
            printf("\n-Titulo: %s",movie[i].titulo);
            printf("\n-Genero: %s",movie[i].genero);
            printf("\n-Duracion: %d",movie[i].duracion);
            printf("\n-Descripcion: %s",movie[i].descripcion);
            printf("\n-Puntaje: %d",movie[i].puntaje);
            printf("\n-Link de imagen: %s",movie[i].linkImagen);

            printf("\nSeguro que desea borrarlos? (s/n): ");
            fflush(stdin);
            rta = tolower(getche());
            validaRta(rta);

            system("pause");
            system("cls");

            if(rta == 's')
            {
                movie[i].estado = 0;
                strcpy(movie[i].titulo,"\0");

                fseek(p, (-1)*sizeof(EMovie), SEEK_CUR);
                fwrite(&movie, sizeof(EMovie), 1, p);

                system("cls");

                printf("\nLos datos han sido borrados.");
                system("pause");
                break;
            }
            else
            {
                printf("\nLos datos no han sido borrados.");
                system("pause");
                break;
            }
        }
        else
        {
            printf("\nNo se encontro la pelicula.");
            system("pause");
            system("cls");
            break;
        }
    }
}


void modificarPelicula(EMovie movie[], FILE *p)
{
    char auxTit[21];
    char rta;
    int i = 0;

    printf("\nIngrese el titulo de la pelicula a modificar: ");
    fflush(stdin);
    gets(auxTit);

    rewind(p);
    while(!feof(p))
    {
        fread(&movie, sizeof(EMovie), 1, p);

        if(strcmpi(auxTit, movie[i].titulo) == 0 && movie[i].estado == 1)
        {
            printf("\nLos datos encontrados son:");
            printf("\n-Titulo: %s", movie[i].titulo);
            printf("\n-Genero: %s", movie[i].genero);
            printf("\n-Duracion: %d", movie[i].duracion);
            printf("\n-Descripcion: %s", movie[i].descripcion);
            printf("\n-Puntaje: %d", movie[i].puntaje);
            printf("\n-Link de imagen: %s", movie[i].linkImagen);

            printf("\nSeguro que desea modificarlos? s/n: ");
            fflush(stdin);
            rta = tolower(getche());
            validaRta(rta);

            system("pause");
            system("cls");

            if(rta == 's')
            {
                printf("\nIngrese el nuevo titulo de la pelicula: ");
                fflush(stdin);
                gets(movie[i].titulo);

                printf("\nIngrese el nuevo genero de la pelicula: ");
                fflush(stdin);
                gets(movie[i].genero);

                printf("\nIngrese la nueva duracion de la pelicula (en cantidad de minutos): ");
                scanf("%d", &movie[i].duracion);

                printf("\nIngrese la nueva descripcion de la pelicula: ");
                fflush(stdin);
                gets(movie[i].descripcion);

                printf("\nIngrese el nuevo puntaje de la pelicula: ");
                scanf("%d", &movie[i].puntaje);

                printf("\nIngrese el nuevo link de la imagen de la pelicula: ");
                fflush(stdin);
                gets(movie[i].linkImagen);

                fseek(p, (-1)*sizeof(EMovie), SEEK_CUR);
                fwrite(&movie, sizeof(EMovie), 1, p);

                system("cls");

                printf("\nLos datos han sido modificados.");
                system("pause");
                break;

            }

            else
            {
                printf("\nLos datos no han sido modificados.");
                system("pause");
                break;
            }
        }
        else
        {
            printf("\nNo se encontro la pelicula");
            system("pause");
            system("cls");
            break;
        }
    }
}






void generarPagina(EMovie movie[])
{

    FILE *pHtml;
    int i;


    pHtml = fopen("movie.html", "w");

    if(pHtml == NULL)
    {
      printf(" No se pudo abrir el archivo\n");
    }
    else
    {
        rewind(pHtml);
    }

    fprintf(pHtml, "<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>\n");

    for(i = 0; i < C; i++)
    {
        if(movie[i].estado == 1)
        {
            fprintf(pHtml, "<article class='col-md-4 article-intro'><a href='#'><img class='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul><p>%s</p></article>\n",movie[i].linkImagen,movie[i].titulo,movie[i].genero,movie[i].puntaje,movie[i].duracion,movie[i].descripcion);
        }
    }

    fprintf(pHtml, "</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");




    printf(" Html creado con exito\n");
    system("pause");
}












