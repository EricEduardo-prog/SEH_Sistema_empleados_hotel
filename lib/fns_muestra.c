#include <stdio.h>
#include <stdlib.h>
#include "sts_seh.h"    /// Libreria con nuestras estructuras.
#include "constantes_seh.h"  /// Nuestros valores CONSTANTES.
#include "fns_construye_hotel.h" /// Funciones necesarias para el creado de hab y pisos
#include "fns_generales.h" /// FUNCIONES generales, basicas.
#include "fns_nodo_hab.h"  /// Nuestras funciones de tipo NODO_HAB
#include "fns_nodo_piso.h" /// Nuestras funciones de LDL / tipo NODO_PISO
#include "empleados.h"
#include "string.h"
#include "fns_muestra.h"

void muestra_todo_okey()
{
    printf("\tHab 'OKEY'.(Libre/Disponible/Limpia/RREGIo ).\n");
}

void muestra_inventario_hab( st_hab hab)
{
    printf("\n\t\tInventario: \n" );
    printf("\t\t\tTelefono: ");
    esta_okey(hab.chequeo.telefono);
    printf("\t\t\tControl tv: ");
    esta_okey(hab.chequeo.control_tv);
    printf("\t\t\tSabanas: ");
    esta_okey(hab.chequeo.sabanas);
    printf("\t\t\tAcolchado: ");
    esta_okey(hab.chequeo.acolchado);
    printf("\t\t\tCubre cama: ");
    esta_okey(hab.chequeo.cubre_cama);
    printf("\t\t\tToallas: ");
    esta_okey( hab.chequeo.toallas);
    printf("\t\t\tToallones: ");
    esta_okey(hab.chequeo.toallones);
    printf("\t\t\tCortinas: ");
    esta_okey(hab.chequeo.cortinas);
    printf("\t\t\tBlack out: ");
    esta_okey(hab.chequeo.black_out);

    ///si es suite
    if(hab.suite == 1)
    {
        printf("\t\t\tSecador de pelo: ");
        esta_okey(hab.chequeo.secador_pelo);
        printf("\t\t\tAgua: ");
        esta_okey(hab.chequeo.agua);
        printf("\t\t\tGaseosa de Lima: ");
        esta_okey(hab.chequeo.gaseosa_lima);
        printf("\t\t\tGaseosa de Naranja: ");
        esta_okey(hab.chequeo.gaseosa_naranja);
        printf("\t\t\tCerveza: ");
        esta_okey(hab.chequeo.cerveza);
        printf("\n");
    }
}




void muestra_informe_baja(int baja)
{
    switch(baja)
    {
    case 0:
        muestra_todo_okey();
        break;
    case 1:
        printf("\tHab de BAJA. NO DISPONIBLE.\n");
        break;
    }
}


void muestra_informe_huesped(int huesped)
{
    switch(huesped)
    {
    case 0:
        muestra_todo_okey();
        break;
    case 1:
        printf("\tHab OCUPADA. Huesped en hab.\n");
        break;
    case 2:
        printf("\tHab OCUPADA. Huesped fuera de la hab.\n");
        break;
    case 3:
        printf("\tCHECK-OUT (Huesped dejo hab) .\n");
        break;
    }
}


void muestra_informe_gob(int estado_gob)
{
    switch(estado_gob)
    {
    case 0:
        muestra_todo_okey();
        break;
    case 1:
        printf("\tHab PARA LIMPIEZA INTERMEDIA.\n");
        break;
    case 2:
        printf("\tHacer LIMPIEZA COMPLETA (Recambio de recepcion).\n");
        break;
    }
}


void muestra_informe_mante(int estado_mante)
{
    switch(estado_mante)
    {
    case 0:
        muestra_todo_okey();
        break;
    case 1:
        printf("     GERENTE Solicita : Pedido de reparacion.\n");
        break;
    case 2:
        printf("     GOBERNANTA Solicita : Pedido de reparacion.\n");
        break;
    case 3:
        printf("     RECEPCION Solicita : Pedido de reparacion.\n");
        break;
    }
}

void muestra_informe_hab (st_estado informe)
{
    muestra_informe_baja(informe.baja);
    muestra_informe_huesped(informe.recepcion);
    muestra_informe_gob(informe.estado_gob);
    muestra_informe_mante(informe.estado_mante);
}


void muestra_hab_con_informe(st_hab hab)
{
    printf("***********************************************");
    printf("\nHab. Nro: %d .\n", hab.nro_hab);
    muestra_informe_hab(hab.informe);
    muestra_inventario_hab(hab);
}

void muestra_lista_hab(nodo_hab* lista_hab, int cat)
{
    nodo_hab* iterador = lista_hab;

    while( iterador != inic_nodo_hab())
    {
        switch(cat)
        {
        case 0:
            muestra_hab_con_informe(iterador->hab);
            break;
        case 1:
            if(iterador->hab.informe.estado_gob == 1)
            {
                muestra_hab_con_informe(iterador->hab);
            }
            break;
        case 2:
            muestra_hab_con_informe(iterador->hab);
            break;
        case 3:
            switch(iterador->hab.informe.estado_mante)
            {
            case 1:
                printf("\n***********************************************\n");
                printf("\t\t\nNOTIFICACION DE PARTE DE GERENTE\n");
                muestra_hab_con_informe(iterador->hab);
                break;
            case 2:
                printf("\n***********************************************\n");
                printf("\t\t\nNOTIFICACION DE PARTE DE GOBERNANTA\n");
                muestra_hab_con_informe(iterador->hab);
                break;
            case 3:
                printf("\n***********************************************\n");
                printf("\t\t\nNOTIFICACION DE PARTE DE RECEPCION\n");
                muestra_hab_con_informe(iterador->hab);
                break;
            }
            break;
        case 4:
            if(iterador->hab.informe.estado_gob == 2)
            {
                muestra_hab_con_informe(iterador->hab);
            }
            break;
        }

        iterador= iterador ->hab_siguiente;
    }

}


void muestra_nro_piso (int nro_piso)
{
    printf("\n***********************************************\n");
    printf("\t\tPISO Nro %i ", nro_piso);
    printf("\n");
}


void muestra_lista_pisos(nodo_piso* lista_pisos, int cat)
{
    nodo_piso* iterador = lista_pisos;

    while(iterador != inic_nodo_piso())
    {
        if(iterador->baja == 0)
        {
            muestra_nro_piso(iterador -> nro_piso);
            muestra_lista_hab(iterador ->lista_hab, cat);
        }
        else
        {
            printf("\n***********************************************\n");
            printf("\t\tPISO Nro %i ESTA DE BAJA", iterador -> nro_piso);
        }

        iterador= iterador-> piso_siguiente;
    }

}


void muestro_archivo_pisos ()
{
    FILE* archivo_pisos = fopen(ARCHIVO_P, "rb");

    st_archivo_pisos hab;

    if(archivo_pisos)
    {
        while(fread(&hab, sizeof(st_archivo_pisos), 1, archivo_pisos) > 0 )
        {
            muestra_nro_piso(hab.nro_piso);
            muestra_hab_con_informe(hab.hab);
        }

        fclose(archivo_pisos);
    }
}


void mostrar_Datos_Personales (st_Datos_Personales dato)
{
    if(dato.dni != 0)
    {
        printf("\nDNI: %ld", dato.dni);
    }
    if(strcmpi(dato.celular, "No especificado")!= 0)
    {
        printf("\nCelular: %s", dato.celular);
    }
    if(dato.edad != 0)
    {
        printf("\nEdad: %i", dato.edad);
    }
    if(dato.genero != 0)
    {
        switch(dato.genero)
        {
        case 1:

            printf("\nGenero: Masculino");
            break;
        case 2:
            printf("\nGenero: Femenino");
            break;
        case 3:
            printf("\nGenero: Otro");
            break;
        }
    }
    if(strcmpi(dato.calle, "No especificado")!= 0 && dato.altura != 0)
    {
        printf("\nDireccion: %s %i", dato.calle, dato.altura);
    }
    if(dato.postal != 0)
    {
        printf("\nCodigo Postal: %i", dato.postal);
    }


}

void mostrar_Empleado(st_Empleado dato)
{
    printf("\n\nDatos Empleado: %s %s\n", dato.nombre, dato.apellido);
    printf("Categoria: ");
    switch(dato.categoria)
    {
    case 0:
        printf("GERENTE");
        break;
    case 1:
        printf("GOBERNANTA");
        break;
    case 2:
        printf("RECEPCION");
        break;
    case 3:
        printf("MANTENIMIENTO");
        break;
    case 4:
        printf("MUCAMA");
        break;
    }
    printf("\nLEGAJO: %i", dato.legajo);
    printf("\nPIN: %i", dato.pin);

    if(dato.baja == 1)
    {
        printf("\nESTADO: BAJA");
    }
    else
    {
        printf("\nESTADO: ALTA");
    }

    mostrar_Datos_Personales(dato.datos);

}

void mostrar_Registro_Empleados_Recursivo(FILE* archivo)
{
    st_Empleado dato;

    if(fread(&dato, sizeof(dato),1,archivo) > 0)
    {
        if(dato.baja != 1)
        {
            mostrar_Empleado(dato);
            printf("\n\n");
        }
        mostrar_Registro_Empleados_Recursivo(archivo);
    }
}


