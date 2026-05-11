#include <stdio.h>
#include <stdlib.h>
#include "sts_seh.h"    /// Libreria con nuestras estructuras.
#include "constantes_seh.h"  /// Nuestros valores CONSTANTES.
#include "fns_gerente.h" /// Funciones necesarias para el creado de hab y pisos
#include "fns_muestra.h"

int retorna_okey()
{
    return 0;
}

int retorna_uno()
{
    return 1;
}

int esta_okey_la_hab ( nodo_hab* iterador_lista_hab)
{
    st_estado informe_hab_okey = retorna_estado_hab_okey();

    st_estado iterador_informe = iterador_lista_hab ->hab.informe;


    if ( (iterador_informe.baja) == (informe_hab_okey.baja) )
    {
        if ( (iterador_informe.estado_gob) == (informe_hab_okey.estado_gob) )
        {
            if ( (iterador_informe.estado_mante) == (informe_hab_okey.estado_mante) )
            {
                if ( (iterador_informe.recepcion) == (informe_hab_okey.recepcion) )
                {
                    return 1;


                }
            }

        }
    }

    return 0;
}

void esta_okey(int elemento_a_chequear)
{
    if(elemento_a_chequear)
    {
        printf("No esta okey.\n");
    }
    else
    {
        printf("Esta OKEY.\n");
    }
}

int retorna_id_piso(int nro_hab)
{
    int nro_piso = nro_hab/100;

    return nro_piso;
}


nodo_hab* inic_nodo_hab ()
{
    return NULL;
}


nodo_hab* crea_nodo_hab (st_hab hab)
{
    nodo_hab* nueva_hab = (nodo_hab*) malloc(sizeof(nodo_hab));

    nueva_hab ->hab = hab;
    nueva_hab ->hab_siguiente = inic_nodo_hab();

    return nueva_hab;
}

nodo_hab* creo_nodo_hab ( st_archivo_pisos habitacion)
{
    nodo_hab* nueva_hab = (nodo_hab*) malloc(sizeof(nodo_hab));

    nueva_hab ->hab = habitacion.hab;
    nueva_hab ->hab_siguiente = inic_nodo_hab();

    return nueva_hab;
}

nodo_hab* agregar_al_comienzo_lista_hab (nodo_hab* lista_hab, nodo_hab* nueva_hab)
{
    if(lista_hab == inic_nodo_hab())
    {
        lista_hab = nueva_hab;
    }
    else
    {
        nueva_hab ->hab_siguiente = lista_hab;
        lista_hab = nueva_hab;
    }

    return lista_hab;
}

nodo_hab* agrego_en_orden_hab(nodo_hab* lista_hab, nodo_hab* nueva_hab)
{
    if(lista_hab == inic_nodo_hab())
    {
        lista_hab = nueva_hab;
    }
    else
    {
        if ( nueva_hab ->hab.nro_hab < lista_hab ->hab.nro_hab)
        {
            lista_hab = agregar_al_comienzo_lista_hab( lista_hab, nueva_hab);
        }
        else
        {
            nodo_hab* anterior_hab = lista_hab;
            nodo_hab* itero_hab = lista_hab;

            while( (itero_hab )!= (inic_nodo_hab()) && (itero_hab-> hab.nro_hab) < (nueva_hab->hab.nro_hab))
            {
                anterior_hab = itero_hab;
                itero_hab = itero_hab -> hab_siguiente;
            }
            anterior_hab -> hab_siguiente = nueva_hab;
            nueva_hab -> hab_siguiente = itero_hab;
        }
    }
    return lista_hab;
}

int elegir_tipo_Habitacion()
{
    int opcion;

    printf("\nELIJA TIPO DE HABITACION DEL PISO:");
    printf("\n1...COMUN");
    printf("\n2...SUITE");
    printf("\nELECCION: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 2 || opcion < 1)
    {
        printf("INGRESO UNA OPCION INCORRECTA, INTENTE NUEVAMENTE: ");
        printf("\nELIJA TIPO DE HABITACION DEL PISO:");
        printf("\n1...COMUN");
        printf("\n2...SUITE");
        printf("\nELECCION: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;
}

int elegir_Habitacion()
{
    int opcion;

    printf("INGRESE NUMERO DE HABITACION: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion < 100)
    {
        printf("\nINGRESE NUMERO DE HABITACION: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;
}

nodo_hab* busco_hab(nodo_hab* lista_hab, int nro_hab)
{
    nodo_hab* itero_en_lista = lista_hab;
    nodo_hab* retorno_hab = inic_nodo_hab();

    while( (itero_en_lista != inic_nodo_hab()) && (retorno_hab == inic_nodo_hab()) )
    {
        if( itero_en_lista ->hab.nro_hab == nro_hab)
        {
            retorno_hab = itero_en_lista;
        }
        itero_en_lista = itero_en_lista ->hab_siguiente;
    }
    return retorno_hab;
}

void existe_Hab(nodo_piso* lista_pisos)
{
    nodo_piso* itero_en_celda = inic_nodo_piso();

    itero_en_celda = lista_pisos;
    nodo_hab* hab_buscada = inic_nodo_hab();

    int nro_hab_buscado = elegir_Habitacion();
    int nro_piso = retorna_id_piso(nro_hab_buscado);

    itero_en_celda = busco_Piso(itero_en_celda, nro_piso);

    if(itero_en_celda != inic_nodo_piso())
    {
        if(itero_en_celda->baja == 0)
        {
            hab_buscada = busco_hab(itero_en_celda->lista_hab, nro_hab_buscado);

            if(hab_buscada != inic_nodo_hab())
            {
                muestra_hab_con_informe(hab_buscada->hab);
            }
            else
            {
                printf("\n***************************************");
                printf("\nHABITACION NO ENCONTRADA");
            }
        }
        else
        {
            printf("\n***************************************");
            printf("\nPISO DADO DE BAJA");
        }

    }
    else
    {
        printf("\n***************************************");
        printf("\nHABITACION NO ENCONTRADA");
    }

}

nodo_hab* busco_ultimo_nodo_hab(nodo_hab* lista_hab)
{
    nodo_hab* iterador = lista_hab;

    while(iterador->hab_siguiente != inic_nodo_hab())
    {
        iterador = iterador->hab_siguiente;
    }

    return iterador;

}

int cantidad_Agregar_Habitaciones()
{
    ///obtengo cantidad a agregar
    int cantidad;
    printf("\nCUANTAS HABITACIONES DESEA AGREGAR?\n");
    printf("INGRESE LA CANTIDAD: ");
    fflush(stdin);
    if(scanf("%i", &cantidad) < 0)
    {
        printf("\nINGRESO UN NUMERO INVALIDO, INTENTE NUEVAMENTE: ");
        fflush(stdin);
        scanf("%i", &cantidad);
    }

    return cantidad;
}

nodo_hab* agregar_habitaciones(nodo_hab* lista_hab, int nro_Piso)
{
    ///obtengo cantidad a agregar
    int cantidad = cantidad_Agregar_Habitaciones();

    ///creo habitacion
    st_hab nueva_Hab;

    int nro_hab;

    int j = 0;

    if(lista_hab == inic_nodo_hab())
    {
        nro_hab = nro_Piso * 100;

        for(int i=0; i<cantidad; i++)
        {

            ///cargo habitacion
            if(j == 13)
            {
                j++;
            }

            nueva_Hab = retorna_hab_okey(nro_hab + j);

            ///agrego a la lista
            lista_hab = agrego_en_orden_hab(lista_hab, crea_nodo_hab(nueva_Hab));
            j++;
        }
    }
    else
    {
        nodo_hab* ultima_hab = busco_ultimo_nodo_hab(lista_hab);

        nro_hab = ultima_hab->hab.nro_hab;

        j = 1;

        for(int i=0; i<cantidad; i++)
        {
            ///si termina en X12 es la ultima
            if(nro_hab + j == nro_Piso*100 + 13)
            {
                j++;
            }

            nueva_Hab = retorna_hab_okey(nro_hab + j);

            ///agrego a la lista
            lista_hab = agrego_en_orden_hab(lista_hab, crea_nodo_hab(nueva_Hab));
            j++;
        }
    }

    return lista_hab;
}


nodo_hab* agregar_habitaciones_suite(nodo_hab* lista_hab, int nro_Piso)
{
    ///obtengo cantidad a agregar
    int cantidad = cantidad_Agregar_Habitaciones();

    ///creo habitacion
    st_hab nueva_Hab;

    int nro_hab;
    int j = 0;

    if(lista_hab == inic_nodo_hab())
    {
        nro_hab = nro_Piso * 100;

        for(int i=0; i<cantidad; i++)
        {

            ///cargo habitacion
            if(j == 13)
            {
                j++;
            }

            nueva_Hab = retorna_suite_okey(nro_hab + j);

            ///agrego a la lista
            lista_hab = agrego_en_orden_hab(lista_hab, crea_nodo_hab(nueva_Hab));
            j++;
        }
    }
    else
    {
        nodo_hab* ultima_hab = busco_ultimo_nodo_hab(lista_hab);

        nro_hab = ultima_hab->hab.nro_hab;

        j = 1;

        for(int i=0; i<cantidad; i++)
        {
            ///si termina en X12 la ultima
            if(nro_hab + j == nro_Piso*100 + 13)
            {
                j++;
            }

            nueva_Hab = retorna_suite_okey(nro_hab + j);

            ///agrego a la lista
            lista_hab = agrego_en_orden_hab(lista_hab, crea_nodo_hab(nueva_Hab));
            j++;
        }
    }

    return lista_hab;
}

nodo_hab* subPrograma_agregar_habitaciones(nodo_hab* lista_hab, int nro_piso)
{
    int opcion = elegir_tipo_Habitacion();

    if(opcion == 1)
    {
        lista_hab = agregar_habitaciones(lista_hab, nro_piso);
    }
    else
    {
        lista_hab = agregar_habitaciones_suite(lista_hab, nro_piso);
    }

    return lista_hab;
}

void libera_nodos_hab(nodo_hab* lista_hab)
{
    while(lista_hab != inic_nodo_hab())
    {
        nodo_hab* borrador= lista_hab;
        lista_hab= lista_hab->hab_siguiente;

        free(borrador);
    }
}

