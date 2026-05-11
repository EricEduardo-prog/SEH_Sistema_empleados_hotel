#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "inicio_sesion.h"
#include "fns_muestra.h"

arbol_Empleado* inic_Arbol()
{
    return NULL;
}

arbol_Empleado* crear_Nodo_Arbol(st_Empleado dato)
{
    arbol_Empleado* nuevo_N_A = (arbol_Empleado*)malloc (sizeof(arbol_Empleado));

    nuevo_N_A ->actual = dato;

    nuevo_N_A ->derecha = inic_Arbol();
    nuevo_N_A ->izquierda = inic_Arbol();

    return nuevo_N_A;

}

arbol_Empleado* insertar_Recursivo (arbol_Empleado* arbol_Actual, st_Empleado dato)
{
    if(arbol_Actual == NULL)
    {
        arbol_Actual = crear_Nodo_Arbol(dato);
    }
    else
    {

        if( dato.legajo > arbol_Actual -> actual.legajo)
        {
            arbol_Actual->derecha = insertar_Recursivo(arbol_Actual->derecha, dato);
        }
        else
        {
            arbol_Actual->izquierda = insertar_Recursivo( arbol_Actual->izquierda, dato);
        }
    }

    return arbol_Actual;
}

arbol_Empleado* insertar_Empleados_Arbol(char filename[], arbol_Empleado* arbol_Actual)
{
    st_Empleado nuevo;
    FILE* archivo=fopen(filename, "rb");
    while(fread(&nuevo, sizeof(nuevo),1,archivo) > 0)
    {
        arbol_Actual = insertar_Recursivo(arbol_Actual, nuevo);
    }

    return arbol_Actual;
}

void in_Order(arbol_Empleado* arbol_Actual)  /// EN ORDEN
{
    if( arbol_Actual != NULL)
    {
        in_Order(arbol_Actual ->izquierda);

        if(arbol_Actual->actual.baja != 1)
        {
            mostrar_Empleado(arbol_Actual->actual);
        }
        in_Order(arbol_Actual ->derecha);
    }
}

void in_Order_Segun_Categoria(arbol_Empleado* arbol_Actual, int categoria)
{
    if( arbol_Actual != NULL)
    {
        in_Order_Segun_Categoria(arbol_Actual->izquierda, categoria);

        if((arbol_Actual->actual.baja != 1) && (arbol_Actual->actual.categoria == categoria))
        {
            mostrar_Empleado(arbol_Actual->actual);
        }
        in_Order_Segun_Categoria(arbol_Actual->derecha, categoria);
    }
}

int cantidad_Determinada_Categoria(arbol_Empleado* arbol_Actual, int categoria)
{
    int cantidad = 0;

    if(arbol_Actual != NULL)
    {
        if(arbol_Actual->actual.categoria == categoria)
        {
            cantidad = 1;
        }
        cantidad = cantidad + cantidad_Determinada_Categoria(arbol_Actual->izquierda, categoria);
        cantidad = cantidad + cantidad_Determinada_Categoria(arbol_Actual->derecha, categoria);
    }
    return cantidad;
}



st_Empleado crea_guarda_Empleado(char filename[], arbol_Empleado* arbol_Actual)
{
    st_Empleado nuevo = cargar_Empleado(arbol_Actual);

    FILE* archivo=fopen(filename, "ab");

    fwrite(&nuevo, sizeof(nuevo),1,archivo);

    fclose(archivo);

    return nuevo;
}

void guarda_Empleado(char filename[], st_Empleado nuevo)
{
    FILE* archivo=fopen(filename, "ab");

    fwrite(&nuevo, sizeof(nuevo),1,archivo);

    fclose(archivo);
}

arbol_Empleado* buscar_Recursivo( arbol_Empleado* arbol_Actual, st_Empleado dato)
{
    arbol_Empleado* persona_En_Linea= inic_Arbol();

    if( arbol_Actual != NULL)
    {
        if(dato .legajo == arbol_Actual ->actual.legajo && dato. pin == arbol_Actual ->actual.pin)
        {
            persona_En_Linea = arbol_Actual;
        }
        else
        {
            if( dato.legajo > arbol_Actual ->actual.legajo)
            {
                persona_En_Linea = buscar_Recursivo( arbol_Actual ->derecha, dato);
            }
            else
            {
                persona_En_Linea = buscar_Recursivo( arbol_Actual ->izquierda, dato);
            }
        }
    }

    return persona_En_Linea;
}

int subPrograma_verifica_inicio_Sesion()
{
    system("cls");
    int opcion;
     printf("\n***************************************");
    printf("INGRESO SU LEGAJO O PIN DE FORMA INCORRECTA");
    printf("\nDESEA INTENTAR NUEVAMENTE?");
    opcion = Seleccion_Si_No();

    return opcion;
}

arbol_Empleado* verifica_inicio_Sesion(arbol_Empleado* persona_En_Linea, arbol_Empleado* arbol_Actual)
{
    int opcion = 1;

    while(persona_En_Linea == NULL && opcion == 1)
    {
        system("cls");
        st_Empleado en_Linea = ingreso_Empleado();
        persona_En_Linea = buscar_Recursivo(arbol_Actual, en_Linea);

        if(persona_En_Linea == NULL)
        {
            opcion = subPrograma_verifica_inicio_Sesion();
        }
    }

    return persona_En_Linea;
}

int bienvenido()
{
    int opcion;

    printf("BIENVENIDO/A - SELECCIONE QUE DESEA REALIZAR: ");
    printf("\n\n1... INICIAR SESION");
    printf("\n0... SALIR");
    printf("\n\nEleccion: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 1 || opcion < 0)
    {
        system("cls");
        printf("INGRESO UNA OPCION INCORRECTA, INTENTE NUEVAMENTE");
        printf("\n\n1... INICIAR SESION");
        printf("\n0... SALIR");
        printf("\n\nEleccion: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;
}

void suspendido()
{
    printf("\nEl usuario esta temporalmente suspendido. De ser un error: ");
    printf("\nNotifique a gerente acerca de este problema o intente ingresar con otro legajo");

    printf("\n\n");
    system("pause");
    printf("\n");
}
