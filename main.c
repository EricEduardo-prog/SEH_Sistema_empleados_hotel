#include <stdio.h>
#include <stdlib.h>

#include "lib/empleados.h"
#include "lib/fns_gerente.h"
#include "lib/fns_muestra.h"
#include "lib/fns_nodo_hab.h"
#include "lib/fns_nodo_piso.h"
#include "lib/inicio_sesion.h"
#include "lib/menu.h"


int main()
{
    char file_Empleados[] = {"Registro_Empleados.dat"};
    int opcion = 1;

    nodo_piso* celda_pisos = inic_nodo_piso();

    /*
    muestro_archivo_pisos();
    system("pause");

    //st_Empleado arregloEmpleados[30];
    //int validos = 0;
    //validos = cargar_Empleado_Automatico(arregloEmpleados);
    //guardar_Empleado_Automatico(arregloEmpleados, file_Empleados, validos);

    crea_guarda_Empleado(file_Empleados);

    FILE* archivo=fopen(file_Empleados, "rb");
    mostrar_Registro_Empleados_Recursivo(archivo);
    fclose(archivo);*/

    //in_Order(arbol_Actual);
 ///a borrar luego

    do
    {
        system("cls");

        arbol_Empleado* arbol_Actual = inic_Arbol();

        arbol_Actual = insertar_Empleados_Arbol(file_Empleados, arbol_Actual);

        celda_pisos = inic_nodo_piso();
        celda_pisos = paso_archivo_hacia_LDL( celda_pisos );
        celda_pisos = invertir_pisos(celda_pisos);

        opcion = bienvenido();

        if(opcion == 1)
        {
            system("cls");

            st_Empleado en_Linea = ingreso_Empleado();

            arbol_Empleado* persona_En_Linea = buscar_Recursivo(arbol_Actual, en_Linea);

            if(persona_En_Linea==NULL && opcion == 1)
            {
                opcion = subPrograma_verifica_inicio_Sesion();

                if(opcion == 1)
                {
                    persona_En_Linea = verifica_inicio_Sesion(persona_En_Linea, arbol_Actual);
                }
            }

            if(persona_En_Linea!=NULL)
            {
                if(persona_En_Linea->actual.baja == 1)
                {
                    suspendido();
                }
                else
                {
                    switch (persona_En_Linea->actual.categoria)
                    {
                    case 0:
                        menuGerente(persona_En_Linea, arbol_Actual, file_Empleados, celda_pisos);
                        break;
                    case 1:
                        menuGobernanta(persona_En_Linea, celda_pisos);
                        break;
                    case 2:
                        menuRecepcion(persona_En_Linea, celda_pisos);
                        break;
                    case 3:
                        menuMantenimiento(persona_En_Linea, celda_pisos);
                        break;
                    case 4:
                        menuMucama(persona_En_Linea);
                        break;
                    }
                }

                system("cls");
                printf("\n***********************************************\n");
                printf("DESEA VOLVER A INICIAR SESION?");
                opcion = Seleccion_Si_No();
            }
            else
            {
                opcion = 0;
            }
        }
    }

    while(opcion == 1);

    liberar_hab_y_pisos( celda_pisos );


    return 0;
}
