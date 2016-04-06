#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
double factorial(double A);

double factorial(double A)
{
    double respuesta;

    if(A == 1)
    {
        return 1;
    }

    respuesta = A * factorial(A - 1);

    return respuesta;
}


double suma(double A, double B);

double suma(double A, double B)
{
    double respuesta;

    respuesta = A + B;
    printf("La suma da: %.2lf\n", respuesta);

    return respuesta;
}


double resta(double A, double B);

double resta(double A, double B)
{
    double respuesta;

    respuesta = A - B;
    printf("La resta da: %.2lf\n", respuesta);

    return respuesta;
}


double multiplicar(double A, double B);

double multiplicar(double A, double B)
{
    double respuesta;

    respuesta = A * B;
    printf("La multiplicacion da: %.2lf\n", respuesta);

    return respuesta;
}



double division(double A, double B);

double division(double A, double B)
{
    double respuesta;

    respuesta = A / B;

    if(B == 0)
    {
        printf("ERROR, vuelva a ingresar numero\n");
    }
    else
    {
        printf("La division da: %.2lf\n", respuesta);
    }


    return respuesta;


}




#endif // FUNCIONES_H_INCLUDED
