#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>


typedef struct
{

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

int validaMax(int minimo, int maximo);

char validaRta(char respuesta);

void inicializar(EPersona personas[]);

int obtenerEspacioLibre(EPersona personas[]);

void altas(EPersona personas[]);

void borrar(EPersona personas[]);

void listar(EPersona personas[]);

void contaEdad(EPersona personas[]);

void graficar(EPersona personas[]);


#endif // FUNCIONES_H_INCLUDED
