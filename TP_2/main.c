
#include "funciones.h"
#define C 20


int main()
{
    EPersona personas[C];
    char salir = 'n';
    int opcion = 0;

    inicializar(personas);

    while(salir == 'n')
    {
        printf("\n\n  Bienvenido al menu de opciones! \n");
        printf("  1- Agregar persona.\n");
        printf("  2- Borrar persona.\n");
        printf("  3- Imprimir lista ordenada por nombre.\n");
        printf("  4- Imprimir grafico de edades.\n");
        printf("  5- Salir.\n");


        printf("\n  Ingrese una de las opciones: ");

        opcion = validaMax(1, 5);
        printf("\n\n");

        switch(opcion)
        {
            case 1://alta
                altas(personas);

                break;

            case 2://baja
                borrar(personas);
                system("pause");
                system("cls");

                break;

            case 3://lista
                listar(personas);
                system("pause");

                break;

            case 4://grafico
                graficar(personas);

                break;

            case 5://salir
                printf("  Esta seguro que desea salir? (s/n): ");
                salir = validaRta(salir);

                if(salir == 's')
                {
                    printf("\n\n  Adios, vuelva pronto!\n\n");
                }

                break;
        }

    }

    return 0;
}
