#include <stdio.h>
#include <stdlib.h>

#include "empleados.h"
#include "sts_seh.h"    /// Libreria con nuestras estructuras.
#include "constantes_seh.h"  /// Nuestros valores CONSTANTES.
#include "fns_construye_hotel.h" /// Funciones necesarias para el creado de hab y pisos
#include "fns_generales.h" /// FUNCIONES generales, basicas.
#include "fns_nodo_hab.h"  /// Nuestras funciones de tipo NODO_HAB
#include "menu_modifi.h" /// Libreria que contiene FUNCIONES QUE MODIFICAN ESTADO DE HAB
#include "fns_muestra.h" /// FUNCIONES CON PRINTF. FNS que Muestran
#include "fns_archivo.h" /// FUNCIONES QUE MANEJAN COMUNICACION CON ARCHIVOS
#include "fns_nodo_piso.h"



nodo_piso* inic_nodo_piso()
{
    return NULL;
}

nodo_piso* creo_nodo_piso (int nro_piso)
{
    nodo_piso* nuevo_piso = (nodo_piso*) malloc( sizeof (nodo_piso));

    nuevo_piso -> nro_piso = nro_piso;
    nuevo_piso -> baja = 0;
    nuevo_piso -> lista_hab = inic_nodo_hab();
    nuevo_piso -> piso_siguiente = inic_nodo_piso();

    return nuevo_piso;
}


nodo_piso* creo_nodo_piso_desde_archivo(st_archivo_pisos hab)
{
    nodo_piso* nuevo_piso = (nodo_piso*) malloc( sizeof (nodo_piso));

    nuevo_piso-> nro_piso = hab.nro_piso;
    //printf("\n\tGUARDE EL NRO DE PISO %i EN NUEVO NODO", hab.nro_piso);
    nuevo_piso-> baja = hab.piso_baja;
    nuevo_piso-> lista_hab = inic_nodo_hab();
    nuevo_piso-> piso_siguiente = inic_nodo_piso();

    return nuevo_piso;
}


nodo_piso* agregar_al_comienzo_nodo_piso(nodo_piso* lista_pisos, nodo_piso* nuevo_piso)
{
    if(lista_pisos == inic_nodo_piso())
    {
        lista_pisos= nuevo_piso;
    }
    else
    {
        nuevo_piso -> piso_siguiente = lista_pisos;
        lista_pisos = nuevo_piso;
    }

    return lista_pisos;
}

nodo_piso* agrego_en_orden_pisos( nodo_piso* lista_pisos, nodo_piso* nuevo_piso)
{
    if(lista_pisos == inic_nodo_piso())
    {
        lista_pisos = nuevo_piso;
    }
    else
    {
        if (nuevo_piso->nro_piso <= lista_pisos->nro_piso)
        {
            lista_pisos = agregar_al_comienzo_nodo_piso(lista_pisos, nuevo_piso);
        }
        else
        {
            nodo_piso* piso_anterior = lista_pisos;
            nodo_piso* piso_iterador = lista_pisos;

            while((piso_iterador)!=(inic_nodo_piso()) && ( piso_iterador->nro_piso) <= (nuevo_piso->nro_piso))
            {
                piso_anterior = piso_iterador;
                piso_iterador = piso_iterador->piso_siguiente;
            }

            piso_anterior->piso_siguiente = nuevo_piso;
            nuevo_piso->piso_siguiente = piso_iterador;
        }
    }

    return lista_pisos;
}

nodo_piso* subPrograma_agregar_Piso(nodo_piso* lista_pisos)
{
    system("cls");
    int opcion;
    printf("CUANTOS PISOS DESEA CREAR?");
    printf("\nINGRESE CANTIDAD: ");
    fflush(stdin);
    scanf("%i", &opcion);
    if(opcion < 1)
    {
        printf("\nINGRESO UN NUMERO INVALIDO, INTENTE NUEVAMENTE: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    for(int i=0; i<opcion; i++)
    {
        lista_pisos = agregar_Piso(lista_pisos);
    }

    return lista_pisos;
}

nodo_piso* busco_ultimo_nodo_piso (nodo_piso* lista_pisos)
{
    nodo_piso* itero_en_pisos = lista_pisos;

    if(itero_en_pisos != inic_nodo_piso())
    {
        while ( itero_en_pisos ->piso_siguiente != inic_nodo_piso())
        {
            itero_en_pisos = itero_en_pisos ->piso_siguiente;
        }
    }
    return itero_en_pisos;
}

nodo_piso* agregar_Piso(nodo_piso* lista_pisos)
{
    int opcion;

    nodo_piso* nuevo_Piso = inic_nodo_piso();

    ///paso por parametro el primer piso
    nuevo_Piso = creo_nodo_piso(1);

    ///busco ultimo nodo para pasarle el piso y referencia
    if(lista_pisos != inic_nodo_piso())
    {
        nodo_piso* ultimo_Piso = busco_ultimo_nodo_piso(lista_pisos);

        ///defino nuevo piso
        nuevo_Piso->nro_piso = ultimo_Piso->nro_piso + 1;
    }

    printf("\nCARGANDO PISO Nro: %i\n", nuevo_Piso->nro_piso);

    ///le cargo la lista de habitaciones

    opcion = elegir_tipo_Habitacion();

    if(opcion == 1)
    {
        nuevo_Piso->lista_hab = agregar_habitaciones(nuevo_Piso->lista_hab, nuevo_Piso->nro_piso);
    }
    else
    {
        nuevo_Piso->lista_hab = agregar_habitaciones_suite(nuevo_Piso->lista_hab, nuevo_Piso->nro_piso);
    }

    ///agrego piso al final del hotel
    if(lista_pisos == inic_nodo_piso())
    {
        lista_pisos = nuevo_Piso;
    }
    else
    {
        lista_pisos = agregar_al_final_nodo_piso(lista_pisos, nuevo_Piso);
    }

    ///retorno la lista cargada con nuevo piso
    return lista_pisos;
}

int elegir_Piso()
{
    int opcion;

    printf("INGRESE EL PISO: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion < 1)
    {
        printf("INGRESE EL PISO: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;
}

nodo_piso* existe_Piso(nodo_piso* lista_pisos)
{
    int piso = elegir_Piso();

    nodo_piso* piso_buscado = busco_Piso(lista_pisos, piso);

    return piso_buscado;
}

nodo_piso* busco_Piso(nodo_piso* lista_pisos, int piso)
{
    nodo_piso* itero_en_lista = lista_pisos;
    nodo_piso* piso_buscado = inic_nodo_piso();

    while((itero_en_lista != inic_nodo_piso()) && (piso_buscado == inic_nodo_piso()))
    {
        if(itero_en_lista->nro_piso == piso)
        {
            piso_buscado = itero_en_lista;
        }
        itero_en_lista = itero_en_lista ->piso_siguiente;
    }

    return piso_buscado;
}

nodo_piso* agregar_al_final_nodo_piso( nodo_piso* lista_pisos, nodo_piso* nuevo_piso)
{
    if(lista_pisos == inic_nodo_piso())
    {
        lista_pisos = nuevo_piso;
    }
    else
    {
        nodo_piso* ultimo = busco_ultimo_nodo_piso(lista_pisos);
        ultimo ->piso_siguiente = nuevo_piso;
    }

    return lista_pisos;
}

nodo_piso* LDL_busco_piso(nodo_piso* lista_pisos, st_archivo_pisos hab)
{
    nodo_piso* itero_en_lista = lista_pisos;
    nodo_piso* retorno_piso = inic_nodo_piso();

    while( (itero_en_lista != inic_nodo_piso()) && (retorno_piso == inic_nodo_piso()) )
    {
        if(itero_en_lista->nro_piso == hab.nro_piso)
        {
            //printf("\nPISO ITERADOR: %i --- PISO ARCHIVO: %i", itero_en_lista->nro_piso, hab.nro_piso);
            retorno_piso = itero_en_lista;
        }
        itero_en_lista = itero_en_lista ->piso_siguiente;
    }

    return retorno_piso;
}

nodo_piso* cargo_LDL (nodo_piso* lista_pisos, st_archivo_pisos hab)
{
    nodo_piso* nuevo_piso = LDL_busco_piso(lista_pisos, hab);

    if(nuevo_piso == NULL)
    {
        //printf("\n\tNUEVO PISO ESTA NULO");
    }

    if(nuevo_piso == inic_nodo_piso())
    {
        lista_pisos = agregar_al_comienzo_nodo_piso(lista_pisos, creo_nodo_piso_desde_archivo(hab));

        nuevo_piso = lista_pisos;
        //printf("\n\tLISTA NUEVO PISO %i", lista_pisos->nro_piso);
        //printf("\n\tNUEVO PISO %i", nuevo_piso->nro_piso);
    }

    //printf("\n\tNUEVO PISO FUERA DE IF %i", nuevo_piso->nro_piso);

    //printf("\n\tAGREGUE ESTO A LA LISTA: ");
    //printf("\nNRO PISO: %i", hab.nro_piso);
    //printf("\nNRO HAB: %i", hab.hab.nro_hab);

    nuevo_piso->lista_hab = agrego_en_orden_hab(nuevo_piso->lista_hab, creo_nodo_hab(hab));

    return lista_pisos;
}

nodo_piso* paso_archivo_hacia_LDL( nodo_piso* lista_pisos)
{
    FILE* archivo_pisos = fopen(ARCHIVO_P, "rb");

    st_archivo_pisos hab;

    if (archivo_pisos != NULL)
    {
        //fseek(archivo_pisos, 0, SEEK_SET);

        while(fread(&hab, sizeof(hab), 1, archivo_pisos) > 0)
        {
            //muestra_nro_piso(hab.nro_piso);
            //muestra_hab_con_informe(hab.hab);

            lista_pisos = cargo_LDL ( lista_pisos, hab);

        }
        fclose(archivo_pisos);
    }
    else
    {
        //printf("vacio");
    }

    return lista_pisos;
}

nodo_piso* invertir_pisos(nodo_piso* lista)
{
    nodo_piso* invertida = inic_nodo_piso();

    if(lista==NULL)
    {
        //printf("\nWarning: la lista esta vacia\n");
    }
    else
    {
       nodo_piso* iterador = lista;
       nodo_piso* guardaNodo;

       while(iterador != NULL)
       {
           guardaNodo = iterador;
           iterador = iterador->piso_siguiente;
           guardaNodo->piso_siguiente = inic_nodo_piso();
           invertida = agregar_al_comienzo_nodo_piso(invertida, guardaNodo);
       }
    }

    return invertida;
}

void liberar_hab_y_pisos(nodo_piso* lista_pisos)
{
    while(lista_pisos != inic_nodo_piso())
    {
        nodo_piso* piso_borrador= lista_pisos;
        nodo_hab* hab_borrador= lista_pisos->lista_hab;

        lista_pisos= lista_pisos->piso_siguiente;

        libera_nodos_hab(hab_borrador);

        free(piso_borrador);
    }
}


