#include "funciones.h"


int main()
{
    char seguir = 's';
    int opcion = 0, flag1 = 0, flag2 = 0;
    double A = 0, B = 0, resultado;

    while(seguir == 's')
    {

            printf("1- Ingresar 1er operando (A = %.2lf)\n", A);
            printf("2- Ingresar 2do operando (B = %.2lf)\n", B);
            printf("3- Calcular la suma (A + B)\n");
            printf("4- Calcular la resta (A - B)\n");
            printf("5- Calcular la division (A / B)\n");
            printf("6- Calcular la multiplicacion (A * B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n");


        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        while(opcion < 1 || opcion > 9)
        {
            printf("\nERROR, ingrese opcion nuevamente: ");
            scanf("%d", &opcion);
        }


        switch(opcion)
        {
            case 1:

                printf("Ingrese 1er operando: ");
                scanf("%lf", &A);
                printf("A = %.2lf\n", A);
                flag1 = 1;

                break;

            case 2:

                printf("Ingrese 2do operando: ");
                scanf("%lf", &B);
                printf("B = %.2lf\n", B);
                flag2 = 1;

                break;

            case 3:

                if(flag1 == 1 && flag2 == 1)
                {
                    resultado = suma(A, B);
                }
                else
                {
                    printf("ERROR, ingrese ambos numeros para realizar la operacion.\n");
                }

                break;

            case 4:

                if(flag1 == 1 && flag2 == 1)
                {
                    resultado = resta(A, B);
                }
                else
                {
                    printf("ERROR, ingrese ambos numeros para realizar la operacion.\n");
                }

                break;

            case 5:

                if(flag1 == 1 && flag2 == 1)
                {
                    resultado = division(A, B);
                }
                else
                {
                    printf("ERROR, ingrese ambos numeros para realizar la operacion.\n");
                }

                break;

            case 6:

                if(flag1 == 1 && flag2 == 1)
                {
                    resultado = multiplicar(A, B);

                }
                else
                {
                    printf("ERROR, ingrese ambos numeros para realizar la operacion.\n");
                }

                break;

            case 7:

                if(flag1 == 1)
                {
                    resultado = factorial(A);
                    printf("El factorial de %.2lf es: %.2lf\n", A, resultado);
                }
                else
                {
                    printf("ERROR, ingrese el primer operando para realizar la operacion.\n");
                }

                break;

            case 8:

                if(flag1 == 1 && flag2 == 1)
                {
                    resultado = suma(A, B);
                    resultado = resta(A, B);
                    resultado = division(A, B);
                    resultado = multiplicar(A, B);
                    resultado = factorial(A);

                    printf("El factorial de %.2lf es: %.2lf\n", A, resultado);
                }
                else
                {
                    printf("ERROR, ingrese ambos numeros para realizar la operacion.\n");
                }

                break;

            case 9:

                seguir = 'n';

                break;
        }

        system("pause");
        system("cls");



    }
    return 0;
}



