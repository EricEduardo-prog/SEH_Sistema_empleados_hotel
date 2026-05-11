#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "string.h"
#include "empleados.h"
#include "inicio_sesion.h"
#include "sts_seh.h"
#include "fns_muestra.h"
#include "fns_nodo_piso.h"
#include "fns_nodo_hab.h"
#include "fns_archivo.h"
#include "menu_modifi.h"
#include "fns_gerente.h"
#include "constantes_seh.h"

int subPrograma_menuMucama()
{
    int opcion;

    printf("\nSeleccione que funcion desea realizar:");
    printf("\n1...FUNCION");
    printf("\n2...FUNCION");
    printf("\n3...FUNCION");
    printf("\n4...FUNCION");
    printf("\n5...FUNCION");
    printf("\n0...Cerrar Sesion");
    printf("\nIngrese numero de funcion: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 5 || opcion < 0)
    {
        printf("\nIngreso una opcion invalida, intente nuevamente");
        printf("\n1...FUNCION");
        printf("\n2...FUNCION");
        printf("\n3...FUNCION");
        printf("\n4...FUNCION");
        printf("\n5...FUNCION");
        printf("\n0...Cerrar Sesion");
        printf("Ingrese numero de funcion: ");;
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;

}

void menuMucama(arbol_Empleado* persona_En_Linea)
{
    int opcion, eleccion;

    do
    {
        system("cls");
        printf("Bienvenido/a %s %s", persona_En_Linea->actual.nombre, persona_En_Linea->actual.apellido);
        printf("\n--------------------------------------------------------\n");

        eleccion = subPrograma_menuMucama();

        switch(eleccion)
        {
        case 1:
            printf("\nentre\n");
            break;
        case 2:
            printf("\nentre\n");
            break;
        case 3:
            printf("\nentre\n");
            break;
        case 4:
            printf("\nentre\n");
            break;
        case 5:
            break;
        case 0:
            printf("\nCerrando sesion...\n");
            eleccion = 0;
            break;
        }

        if(eleccion != 0)
        {
            printf("\n\nDesea realizar otra funcion?");
            opcion = Seleccion_Si_No();
        }

    }
    while((opcion == 1) && (eleccion!=0));
}

int subPrograma_menuMantenimiento()
{
    int opcion;

    printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
    printf("\n***************************************");
    printf("\n1...MODIFICAR ESTADO E INFORME DE HABITACION");
    printf("\n2...MOSTRAR INFORME PISO O HABITACIONES");
    printf("\n0...CERRAR SESION");
    printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
    printf("\n***************************************");
    printf("\nINGRESE NUMERO DE FUNCION: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 5 || opcion < 0)
    {
        printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
        printf("\n***************************************");
        printf("\n1...MODIFICAR ESTADO E INFORME DE HABITACION");
        printf("\n2...MOSTRAR INFORME PISO O HABITACIONES");
        printf("\n0...CERRAR SESION");
        printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
        printf("\n***************************************");
        printf("\nINGRESE NUMERO DE FUNCION: ");
    }

    return opcion;

}

void menuMantenimiento(arbol_Empleado* persona_En_Linea, nodo_piso* celda_pisos)
{
    int opcion, eleccion;

    do
    {
        system("cls");
        printf("BIENVENIDO/a %s %s \t ROL: MANTENIMIENTO", persona_En_Linea->actual.nombre, persona_En_Linea->actual.apellido);
        printf("\n--------------------------------------------------------\n");

        eleccion = subPrograma_menuMantenimiento();

        switch(eleccion)
        {
        case 1:
            modifico_informe(celda_pisos, 3);
            itero_en_celda_piso_para_escribir(celda_pisos);
            printf("\n\n");
            system("pause");
            break;
        case 2:
            system("cls");
            mostrar_Hotel(celda_pisos, 3);
            system("cls");
            break;
        case 3:
            printf("\nentre\n");
            break;
        case 4:
            printf("\nentre\n");
            break;
        case 5:
            break;
        case 0:
            printf("\nCerrando sesion...\n");
            eleccion = 0;
            break;
        }

        if(eleccion != 0)
        {
            printf("\n\nDesea realizar otra funcion?");
            opcion = Seleccion_Si_No();
        }

    }
    while((opcion == 1) && (eleccion!=0));
}

int subPrograma_mostrar_limpieza_Gobernanta()
{
    int opcion;

    printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
    printf("\n***************************************");
    printf("\n1...MOSTRAR TODO: PISO Y HABITACIONES");
    printf("\n2...MOSTRAR UN SOLO PISO Y SUS HABITACIONES");
    printf("\n0...MOSTRAR UNA HABITACION EN ESPECIFICO");
    printf("\n***************************************");
    printf("\nINGRESE NUMERO DE FUNCION:");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 2 || opcion < 0)
    {
        printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
        printf("\n***************************************");
        printf("\n1...MOSTRAR TODO: PISO Y HABITACIONES");
        printf("\n2...MOSTRAR UN SOLO PISO Y SUS HABITACIONES");
        printf("\n0...MOSTRAR UNA HABITACION EN ESPECIFICO");
        printf("\n***************************************");
        printf("\nINGRESE NUMERO DE FUNCION:");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;
}

void mostrar_limpieza_Gobernanta(nodo_piso* lista_pisos, int tipo)
{
    int opcion = subPrograma_mostrar_limpieza_Gobernanta();

    switch(opcion)
    {
    case 1:

        muestra_lista_pisos(lista_pisos, 1);
        break;
    case 2:

        break;
    case 3:

        break;
    }
}

int subPrograma_limpieza_Gobernanta(nodo_piso* lista_pisos)
{
    int opcion;

    printf("SELECCIONE QUE FUNCION  DESEA REALIZAR:");
    printf("\n***************************************");
    printf("\n1...VER HABITACIONES LIMPIEZA INTERMEDIA - PENDIENTES: %i", retorna_cantidad_limpieza(lista_pisos, 1));
    printf("\n2...VER HABITACIONES LIMPIEZA COMPLETA - PENDIENTES: %i", retorna_cantidad_limpieza(lista_pisos,4));
    printf("\n0...VOLVER AL MENU ANTERIOR");
    printf("\n***************************************");
    printf("\nINGRESE NUMERO DE FUNCION: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 2 || opcion < 0)
    {
        system("cls");
        printf("SELECCIONE QUE FUNCION  DESEA REALIZAR:");
        printf("\n***************************************");
        printf("\n1...VER HABITACIONES LIMPIEZA - INTERMEDIA");
        printf("\n2...VER HABITACIONES LIMPIEZA - COMPLETA");
        printf("\n0...VOLVER AL MENU ANTERIOR");
        printf("\n***************************************");
        printf("\nINGRESE NUMERO DE FUNCION:");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;
}

void limpieza_Gobernanta(nodo_piso* lista_pisos)
{
    int opcion = subPrograma_limpieza_Gobernanta(lista_pisos);

    switch(opcion)
    {
    case 1:
        ///intermedia
        system("cls");
        mostrar_Hotel(lista_pisos, 1);
        break;
    case 2:
        ///completa
        system("cls");
        mostrar_Hotel(lista_pisos, 4);

        break;
    }

}

int subPrograma_menuGobernanta()
{
    int opcion;

    printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
    printf("\n***************************************");
    printf("\n1...MODIFICAR ESTADO E INFORME DE HABITACION");
    printf("\n2...MOSTRAR INFORME PISO O HABITACIONES");
    printf("\n0...CERRAR SESION");
    printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
    printf("\n***************************************");
    printf("\nINGRESE NUMERO DE FUNCION: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 2 || opcion < 0)
    {
        printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
        printf("\n***************************************");
        printf("\n1...MODIFICAR ESTADO E INFORME DE HABITACION");
        printf("\n2...MOSTRAR INFORME PISO O HABITACIONES");
        printf("\n0...CERRAR SESION");
        printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
        printf("\n***************************************");
        printf("\nINGRESE NUMERO DE FUNCION: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;

}

void menuGobernanta(arbol_Empleado* persona_En_Linea, nodo_piso* celda_pisos)
{
    int opcion, eleccion;
    do
    {
        system("cls");
        printf("BIENVENIDO/A %s %s \tROL: GOBERNANTA", persona_En_Linea->actual.nombre, persona_En_Linea->actual.apellido);
        printf("\n--------------------------------------------------------\n");

        eleccion = subPrograma_menuGobernanta();

        switch(eleccion)
        {
        case 1:
            modifico_informe(celda_pisos, 1);
            itero_en_celda_piso_para_escribir(celda_pisos);
            printf("\n\n");
            system("pause");
            break;
        case 2:
            system("cls");
            limpieza_Gobernanta(celda_pisos);
            printf("\n\n");
            system("pause");
            break;
        case 0:
            printf("\nCerrando sesion...\n");
            eleccion = 0;
            break;
        }

        if(eleccion != 0)
        {
            printf("\n\nDesea realizar otra funcion?");
            opcion = Seleccion_Si_No();
        }

    }
    while((opcion == 1) && (eleccion!=0));
}

int subPrograma_menuRecepcion()
{
    int opcion;

    printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
    printf("\n***************************************");
    printf("\n1...MODIFICAR ESTADO E INFORME DE HABITACION");
    printf("\n2...MOSTRAR INFORME PISO O HABITACIONES");
    printf("\n0...CERRAR SESION");
    printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
    printf("\n***************************************");
    printf("\nINGRESE NUMERO DE FUNCION: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 2 || opcion < 0)
    {
        printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
        printf("\n***************************************");
        printf("\n1...MODIFICAR ESTADO E INFORME DE HABITACION");
        printf("\n2...MOSTRAR INFORME PISO O HABITACIONES");
        printf("\n0...CERRAR SESION");
        printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
        printf("\n***************************************");
        printf("\nINGRESE NUMERO DE FUNCION: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;

}

void menuRecepcion(arbol_Empleado* persona_En_Linea, nodo_piso* celda_pisos)
{
    int opcion, eleccion;

    do
    {
        system("cls");
        printf("BIENVENIDO/a %s %s \tROL: RECEPCION", persona_En_Linea->actual.nombre, persona_En_Linea->actual.apellido);
        printf("\n--------------------------------------------------------\n");

        eleccion = subPrograma_menuRecepcion();

        switch(eleccion)
        {
        case 1:
            system("cls");
            modifico_informe(celda_pisos, 2);
            itero_en_celda_piso_para_escribir(celda_pisos);
            printf("\n\n");
            system("pause");
            break;
        case 2:
            system("cls");
            mostrar_Hotel(celda_pisos, 2);
            break;
        case 0:
            printf("\n***************************************");
            printf("\nCERRANDO SESION...\n");
            eleccion = 0;
            break;
        }

        if(eleccion != 0)
        {
            printf("\n\n***************************************");
            printf("\nDESEA REALIZAR OTRA FUNCION?");
            opcion = Seleccion_Si_No();
        }

    }
    while((opcion == 1) && (eleccion!=0));
}

int subPrograma_administrar_Empleados_Gerente()
{
    int opcion;


    printf("SELECCIONE QUE FUNCION  DESEA REALIZAR:");
    printf("\n***************************************");
    printf("\n1...EDITAR EMPLEADO Y SUS DATOS PERSONALES. DAR DE BAJA/ALTA (SEGUN LEGAJO)");
    printf("\n2...VER REGISTRO EMPLEADOS EN BASE DE DATOS");
    printf("\n3...CREAR NUEVO EMPLEADO");
    printf("\n4...VER EMPLEADOS SEGUN CATEGORIA");
    printf("\n5...CAMBIAR CATEGORIA TEMPORALMENTE PARA REALIZAR SUS FUNCIONES");
    printf("\n0...VOLVER AL MENU ANTERIOR");
    printf("\n***************************************");
    printf("\nINGRESE NUMERO DE FUNCION: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 5 || opcion < 0)
    {
        system("cls");
        printf("SELECCIONE QUE FUNCION  DESEA REALIZAR:");
        printf("\n***************************************");
        printf("\n1...EDITAR EMPLEADO Y SUS DATOS PERSONALES. DAR DE BAJA/ALTA (SEGUN LEGAJO)");
        printf("\n2...VER REGISTRO EMPLEADOS EN BASE DE DATOSVer registro de empleados dentro de la base de datos");
        printf("\n3...CREAR NUEVO EMPLEADO");
        printf("\n5...CAMBIAR CATEGORIA TEMPORALMENTE PARA REALIZAR SUS FUNCIONES");
        printf("\n0...VOLVER AL MENU ANTERIOR");
        printf("\n***************************************");
        printf("\nINGRESE NUMERO DE FUNCION: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;
}

void administrar_Empleados_Gerente(arbol_Empleado* persona_En_Linea, arbol_Empleado* arbol_Actual, char filename[], nodo_piso* celda_pisos)
{
    int opcion = subPrograma_administrar_Empleados_Gerente();
    st_Empleado dato;

    switch(opcion)
    {
    case 1:
        system("cls");
        arbol_Actual = ver_Editar_Empleado(arbol_Actual, filename);
        printf("\n***************************************");
        printf("\nDESEA VER EL REGISTRO DE EMPLEADOS?");
        opcion = Seleccion_Si_No();

        if(opcion == 1)
        {
            in_Order(arbol_Actual);
            printf("\n\n");
            system("pause");
        }
        break;
    case 2:
        system("cls");
        printf("MOSTRANDO REGISTRO DE EMPLEADOS:");
        FILE* archivo= fopen(filename, "rb");
        mostrar_Registro_Empleados_Recursivo(archivo);
        fclose(archivo);
        printf("\n\n");
        system("pause");
        break;
    case 3:
        system("cls");
        dato = crea_guarda_Empleado(filename, arbol_Actual);
        insertar_Recursivo(arbol_Actual, dato);

        printf("\nDESEA VER EL REGISTRO DE EMPLEADOS?");
        opcion = Seleccion_Si_No();

        if(opcion == 1)
        {
            in_Order(arbol_Actual);
            printf("\n\n");
            system("pause");
        }
        break;

    case 4:
        system("cls");
        printf("INGRESE LA CATEGORIA PARA VER SUS EMPLEADOS");
        printf("\n\n0...GERENTE");
        printf("\n1...GOBERNANTA");
        printf("\n2...RECEPCION");
        printf("\n3...MANTENIMIENTO");
        printf("\n4...MUCAMA");
        printf("\n\nELECCION: ");
        fflush(stdin);
        scanf("%i", &opcion);
        opcion = verificar_Categoria(opcion);

        system("cls");
        in_Order_Segun_Categoria(arbol_Actual, opcion);
        printf("\n\n");
        system("pause");
        break;
    case 5:
        system("cls");
        switch(cambiar_Categoria())
        {
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
        break;
    }
}

int subPrograma_administrar_Hotel_Gerente()
{
    int opcion;

    printf("SELECCIONE QUE FUNCION  DESEA REALIZAR:");
    printf("\n***************************************");
    printf("\n1...EDITAR INFORME DE HABITACION ELEGIDA");
    printf("\n2...MOSTRAR INFORME PISO O HABITACIONES");
    printf("\n3...CREAR O MODIFICAR ESTADO INFRAESTRUCTURA DE HOTEL");
    printf("\n0...VOLVER AL MENU ANTERIOR");
    printf("\n***************************************");
    printf("\nINGRESE NUMERO DE FUNCION: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 3 || opcion < 0)
    {
        system("cls");
        printf("INGRESO UNA OPCION INCORRECTA, INTENTE NUEVAMENTE");
        printf("SELECCIONE QUE FUNCION  DESEA REALIZAR:");
        printf("\n***************************************");
        printf("\n1...EDITAR INFORME DE HABITACION ELEGIDA");
        printf("\n2...MOSTRAR INFORME PISO O HABITACIONES");
        printf("\n3...CREAR O MODIFICAR ESTADO INFRAESTRUCTURA DE HOTEL");
        printf("\n0...VOLVER AL MENU ANTERIOR");
        printf("\n***************************************");
        printf("\nINGRESE NUMERO DE FUNCION: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;

}

int subPrograma_mostrar_Hotel()
{
    int opcion;

    printf("SELECCIONE QUE FUNCION  DESEA REALIZAR:");
    printf("\n***************************************");
    printf("\n1...MOSTRAR INFORME Y TODOS LOS PISOS Y HABITACIONES");
    printf("\n2...MOSTRAR INFORME DE PISO Y HABITACIONES EN ESPECIFICO");
    printf("\n3...MOSTRAR INFORME HABITACION EN ESPECIFICO");
    printf("\n0...VOLVER AL MENU ANTERIOR");
    printf("\n***************************************");
    printf("\nINGRESE NUMERO DE FUNCION: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 3 || opcion < 0)
    {
        system("cls");
        printf("INGRESO UNA OPCION INCORRECTA, INTENTE NUEVAMENTE");
        printf("SELECCIONE QUE FUNCION  DESEA REALIZAR:");
        printf("\n***************************************");
        printf("\n1...EDITAR INFORME DE HABITACION ELEGIDA");
        printf("\n2...MOSTRAR INFORME PISO O HABITACIONES");
        printf("\n3...CREAR O MODIFICAR ESTADO INFRAESTRUCTURA DE HOTEL");
        printf("\n0...VOLVER AL MENU ANTERIOR");
        printf("\n***************************************");
        printf("\nINGRESE NUMERO DE FUNCION: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;
}

void mostrar_Hotel(nodo_piso* lista_pisos, int cat)
{
    int eleccion = subPrograma_mostrar_Hotel();
    int cantidad;
    nodo_piso* piso_Modificar = inic_nodo_piso();

    switch(eleccion)
    {
    case 1:
        system("cls");
        muestro_informe(lista_pisos, cat);
        muestra_lista_pisos(lista_pisos, cat);
        break;
    case 2:
        piso_Modificar = existe_Piso(lista_pisos);

        if(piso_Modificar != inic_nodo_piso())
        {
            if(piso_Modificar->baja == 0)
            {
                cantidad = cuento_hab(piso_Modificar->lista_hab, cat);

                switch(cat)
                {
                case 0:
                    printf("\nTOTAL HAB DE BAJA PISO %d: %d .\n",piso_Modificar->nro_piso, cantidad);
                    break;
                case 1:
                    printf("\nTOTAL HAB PENDIENTE LIMPIEZA INTERMEDIA PISO %d: %d .\n",piso_Modificar->nro_piso, cantidad);
                    break;
                case 2:
                    printf("\nTOTAL HAB OCUPADAS/NO DISPONIBLES PISO %d: %d .\n",piso_Modificar->nro_piso, cantidad);
                    break;
                case 3:
                    printf("\nTOTAL HAB PENDIENTE MANTENIMIENTO PISO %d: %d .\n",piso_Modificar->nro_piso, cantidad);
                    break;
                case 4:
                    printf("\nTOTAL HAB PENDIENTE LIMPIEZA COMPLETA PISO %d: %d .\n",piso_Modificar->nro_piso, cantidad);
                    break;
                }
                muestra_nro_piso(piso_Modificar-> nro_piso);
                muestra_lista_hab(piso_Modificar->lista_hab, cat);
            }
            else
            {
                printf("\n***********************************************\n");
                printf("\t\tPISO Nro %i DADO DE BAJA", piso_Modificar->nro_piso);
                printf("\n");
            }
        }
        else
        {
            printf("\n***************************************");
            printf("\nNO EXISTE ESE PISO EN EL HOTEL");
        }
        printf("\n\n");
        system("pause");
        break;
    case 3:
        existe_Hab(lista_pisos);
        printf("\n\n");
        system("pause");
        break;
    }
}

void administrar_Hotel_Gerente(nodo_piso* celda_pisos)
{

    int eleccion = 1;
    int opcion;
    nodo_piso* piso_Modificar = inic_nodo_piso();

    do
    {
        system("cls");

        opcion = subPrograma_administrar_Hotel_Gerente();

        switch(opcion)
        {
        case 1:
            system("cls");
            modifico_informe(celda_pisos, 0);
            itero_en_celda_piso_para_escribir(celda_pisos);
            printf("\n\n");
            system("pause");
            break;
        case 2:
            system("cls");
            mostrar_Hotel(celda_pisos, 0);
            break;
        case 3:
            system("cls");

            opcion = elegir_Operacion_Pisos_Habitaciones();

            system("cls");
            switch(opcion)
            {
            case 1:
                celda_pisos = subPrograma_agregar_Piso(celda_pisos);
                printf("\n***************************************");
                printf("\nPISO/S Y HABITACION/ES AGREGADA/S CON EXITO!");
                break;
            case 2:
                piso_Modificar = existe_Piso(celda_pisos);

                if(piso_Modificar != inic_nodo_piso())
                {
                    piso_Modificar->lista_hab = subPrograma_agregar_habitaciones(piso_Modificar->lista_hab, piso_Modificar->nro_piso);
                    printf("\n***************************************");
                    printf("\nHABITACION/ES AGREGADA/S CON EXITO");
                }
                else
                {
                    printf("\n***************************************");
                    printf("\nNO EXISTE ESE PISO EN EL HOTEL");
                }
                break;
            case 3:
                piso_Modificar = existe_Piso(celda_pisos);

                if(piso_Modificar != inic_nodo_piso())
                {
                    piso_Modificar = modifica_estado_piso(piso_Modificar);
                }
                else
                {
                    printf("\n***************************************");
                    printf("\nNO EXISTE ESE PISO EN EL HOTEL");
                }
                break;
            case 4:
                modifica_estado_hab(celda_pisos);
                break;
            }


            printf("\n\n***************************************");
            printf("\nDESEA VER TODOS LOS PISOS Y HABITACIONES?");
            opcion = Seleccion_Si_No();

            if(opcion == 1)
            {
                muestro_informe(celda_pisos, 0);
                muestra_lista_pisos(celda_pisos, 0);
                printf("\n\n");
                system("pause");
            }
            itero_en_celda_piso_para_escribir(celda_pisos);
            break;
        }
    }
    while((opcion != 0) && (eleccion == 0));
}

int subPrograma_menuGerente()
{
    int opcion;

    printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
    printf("\n***************************************");
    printf("\n1...ADMINISTRAR EMPLEADOS");
    printf("\n2...ADMINISTRAR HOTEL");
    printf("\n0...CERRAR SESION");
    printf("\n***************************************");
    printf("\nINGRESE NUMERO DE FUNCION: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 2 || opcion < 0)
    {
        printf("\nSELECCIONE QUE FUNCION  DESEA REALIZAR:");
        printf("\n***************************************");
        printf("\n1...ADMINISTRAR EMPLEADOS");
        printf("\n2...ADMINISTRAR HOTEL");
        printf("\n0...CERRAR SESION");
        printf("\n***************************************");
        printf("\nINGRESE NUMERO DE FUNCION: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;

}

void menuGerente(arbol_Empleado* persona_En_Linea, arbol_Empleado* arbol_Actual, char filename[], nodo_piso* celda_pisos)
{
    int opcion, eleccion;

    do
    {
        system("cls");
        printf("BIENVENIDO/A %s %s \tROL: GERENTE", persona_En_Linea->actual.nombre, persona_En_Linea->actual.apellido);
        printf("\n--------------------------------------------------------\n");

        eleccion = subPrograma_menuGerente();

        switch(eleccion)
        {
        case 1:
            system("cls");
            administrar_Empleados_Gerente(persona_En_Linea, arbol_Actual, filename, celda_pisos);
            opcion = 1;
            break;
        case 2:
            system("cls");
            administrar_Hotel_Gerente(celda_pisos);
            opcion = 1;
            break;
        case 0:
            printf("\nCERRANDO SESION...\n");
            eleccion = 0;

            printf("\n\n");
            system("pause");
            printf("\n");
            break;
        }
    }
    while((opcion == 1) && (eleccion!=0));
}

int menu_modifica_estado_hab()
{
    int opcion;

    printf("\n1- BAJA");
    printf("\n2- RECEPCION");
    printf("\n3- GOBERNANTA");
    printf("\n4- MANTENIMIENTO");
    printf("\n\tESTADO QUE DESEE MODIFICAR -> ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion > 4 || opcion < 1)
    {
        system("cls");
        printf("\nINGRESO UN NUMERO INCORRECTO, INTENTE NUEVAMENTE");
        printf("\n1- BAJA");
        printf("\n2- RECEPCION");
        printf("\n3- GOBERNANTA");
        printf("\n4- MANTENIMIENTO");
        printf("\n\tESTADO QUE DESEE MODIFICAR -> ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}

int menu_modifica_estado_hab_recepcion()
{
    int opcion;

    printf("\n1- RECEPCION");
    printf("\n2- GOBERNANTA");
    printf("\n3- MANTENIMIENTO");
    printf("\n\tESTADO QUE DESEE MODIFICAR -> ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion > 3 || opcion < 1)
    {
        system("cls");
        printf("\nINGRESO UN NUMERO INCORRECTO, INTENTE NUEVAMENTE");
        printf("\n1- RECEPCION");
        printf("\n2- GOBERNANTA");
        printf("\n3- MANTENIMIENTO");
        printf("\n\tESTADO QUE DESEE MODIFICAR -> ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}



int menu_modifica_baja_hab()
{
    int opcion;
    printf("\n0   -");
    muestra_todo_okey();
    printf("\n1   -\tHab de BAJA y NO DISPONIBLE.\n");
    printf("\n\tNUEVO ESTADO -> ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menu_modifica_huesped_hab()
{
    int opcion;
    printf("\n0   -");
    muestra_todo_okey();
    printf("\n1   -\tHab OCUPADA. Huesped en hab.\n");
    printf("\n2   -\tHab OCUPADA. Huesped fuera de la hab.\n");
    printf("\n3   -\tCHECK-OUT (Huesped deja hab) .\n");
    printf("\n\tNuevo estado -> ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int menu_modifica_gob_hab()
{
    int opcion;

    printf("\n0   -");
    muestra_todo_okey();
    printf("\n1   -\tHab PARA LIMPIEZA INTERMEDIA.\n");
    printf("\n2   -\tHacer LIMPIEZA COMPLETA (Recambio de recepcion).\n");
    printf("\n\tNUEVO ESTADO -> ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int menu_modifica_mante_hab()
{
    int opcion;

    printf("\n0   -");
    muestra_todo_okey();
    printf("\n1   -\tGERENTE Solicita : Pedido de reparacion.\n");
    printf("\n2   -\tGOBERNANTA Solicita : Pedido de reparacion.\n");
    printf("\n3   -\\tRECEPCION Solicita : Pedido de reparacion.\n");
    printf("\n\tNUEVO ESTADO -> ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

st_estado modifica_informe_hab_Recepcion(st_estado informe)
{
    int opcion;

    opcion = menu_modifica_estado_hab_recepcion();

    switch(opcion)
    {
    case 1:
        informe.recepcion = menu_modifica_huesped_hab();

        switch(informe.recepcion)
        {
        case 0:
            informe.estado_gob = 0;
            break;
        case 1:
            informe.estado_gob = 0;
            break;
        case 2:///fuera hab
            informe.estado_gob = 1;
            break;
        case 3:///check out
            informe.estado_gob = 2;
            break;
        }
        break;
    case 2:
        informe.estado_gob = menu_modifica_gob_hab();

        if(informe.estado_gob == 0)
        {
            if(informe.recepcion == 3)
            {
                informe.recepcion = 0;
            }
        }
        break;
    case 3:
        informe.estado_mante = menu_modifica_mante_hab();
        break;
    }

    return informe;
}

st_estado modifica_informe_hab_Gerente(st_estado informe)
{
    int opcion;

    opcion = menu_modifica_estado_hab();

    switch(opcion)
    {
    case 1:
        informe.baja= menu_modifica_baja_hab();
        break;
    case 2:
        informe.recepcion = menu_modifica_huesped_hab();

        switch(informe.recepcion)
        {
        case 0:
            informe.estado_gob = 0;
            break;
        case 1:
            informe.estado_gob = 0;
            break;
        case 2:///fuera hab
            informe.estado_gob = 1;
            break;
        case 3:///check out
            informe.estado_gob = 2;
            break;
        }
        break;
    case 3:
        informe.estado_gob = menu_modifica_gob_hab();

        if(informe.estado_gob == 0)
        {
            if(informe.recepcion == 3)
            {
                informe.recepcion = 0;
            }
        }
        break;
    case 4:
        informe.estado_mante = menu_modifica_mante_hab();
        break;
    }

    return informe;
}


st_estado modifica_informe_hab(st_estado informe, int cat)
{
    switch(cat)
    {
    case 0:
        informe = modifica_informe_hab_Gerente(informe);
        break;
    case 1:
        informe.estado_gob = menu_modifica_gob_hab();

        if(informe.estado_gob == 0)
        {
            if(informe.recepcion == 3)
            {
                informe.recepcion = 0;
            }
        }
        break;
    case 2:
        informe = modifica_informe_hab_Recepcion(informe);
        break;
    case 3:
        informe.estado_mante = menu_modifica_mante_hab();
        break;
    }

    return informe;
}

