#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

#define C 262

typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;
}EMovie;

int validaMax(int min, int max);

void validaCadena(char cadena[], int tam);

void validaRta(char respuesta);

void inicEstado(EMovie movie[]);

void modificarPelicula(EMovie movie[], FILE *p);

void agregarPelicula(EMovie movie[], FILE *p);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
void borrarPelicula(EMovie movie[], FILE *p);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie movie[]);

#endif // FUNCIONES_H_INCLUDED
