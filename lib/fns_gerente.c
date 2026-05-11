#include <stdio.h>
#include <stdlib.h>

#include "string.h"
#include "empleados.h"
#include "inicio_sesion.h"
#include "constantes_seh.h"
#include "sts_seh.h"    /// Libreria con nuestras estructuras.
#include "fns_nodo_piso.h"
#include "fns_nodo_hab.h"
#include "fns_generales.h"
#include "fns_muestra.h"
#include "menu.h"


int cuento_hab( nodo_hab* itero_en_lista, int cat)
{
    int cantidad = retorna_okey();

    switch(cat)
    {
    case 0:
        if(itero_en_lista != inic_nodo_hab())
        {
            while(itero_en_lista != inic_nodo_hab())
            {
                if(itero_en_lista->hab.informe.baja == retorna_uno())
                {
                    cantidad += retorna_uno();
                }
                itero_en_lista = itero_en_lista->hab_siguiente;
            }
        }
        else
        {
            printf("\nPISO VACIO");
        }
        break;

    case 1:
        if(itero_en_lista != inic_nodo_hab())
        {
            while(itero_en_lista != inic_nodo_hab())
            {
                if(itero_en_lista->hab.informe.estado_gob == 1)
                {
                    cantidad += retorna_uno();
                }
                itero_en_lista = itero_en_lista->hab_siguiente;
            }
        }
        else
        {
            printf("\nPISO VACIO");
        }
        break;
    case 2:
        if(itero_en_lista != inic_nodo_hab())
        {
            while(itero_en_lista != inic_nodo_hab())
            {
                if(itero_en_lista->hab.informe.recepcion >= 1)
                {
                    cantidad += retorna_uno();
                }
                itero_en_lista = itero_en_lista->hab_siguiente;
            }
        }
        else
        {
            printf("\nPISO VACIO");
        }
        break;
    case 3:
        if(itero_en_lista != inic_nodo_hab())
        {
            while(itero_en_lista != inic_nodo_hab())
            {
                if(itero_en_lista->hab.informe.estado_mante >= 1)
                {
                    cantidad += retorna_uno();
                }
                itero_en_lista = itero_en_lista->hab_siguiente;
            }
        }
        else
        {
            printf("\nPISO VACIO");
        }
        break;
    case 4:
        if(itero_en_lista != inic_nodo_hab())
        {
            while(itero_en_lista != inic_nodo_hab())
            {
                if(itero_en_lista->hab.informe.estado_gob == 2)
                {
                    cantidad += retorna_uno();
                }
                itero_en_lista = itero_en_lista->hab_siguiente;
            }
        }
        else
        {
            printf("\nPISO VACIO");
        }
        break;
    }
    return cantidad;
}

void muestro_informe(nodo_piso* celda_pisos, int cat)
{
    nodo_piso* itero_en_celda = celda_pisos;

    int cantidad_por_piso = retorna_okey();

    if(itero_en_celda != inic_nodo_piso())
    {
        while(itero_en_celda != inic_nodo_piso())
        {
            if(itero_en_celda->baja == 0)
            {
                nodo_hab* itero_en_lista = itero_en_celda->lista_hab;

                cantidad_por_piso += cuento_hab(itero_en_lista, cat);

            }
            else
            {
                printf("\nPISO %d ESTA DE BAJA\n",itero_en_celda->nro_piso);
            }
            itero_en_celda = itero_en_celda ->piso_siguiente;
        }

        switch(cat)
        {
        case 0:
            printf("\nTOTAL HAB DE BAJA: %i.\n", cantidad_por_piso);
            break;
        case 1:
            printf("\nTOTAL HAB PENDIENTE LIMPIEZA INTERMEDIA: %i.\n", cantidad_por_piso);
            break;
        case 2:
            printf("\nTOTAL HAB OCUPADAS/NO DISPONIBLES: %i.\n", cantidad_por_piso);
            break;
        case 3:
            printf("\nTOTAL PENDIENTE MANTENIMIENTO PISO: %i.\n", cantidad_por_piso);
            break;
        case 4:
            printf("\nTOTAL HAB PENDIENTE LIMPIEZA COMPLETA: %i.\n", cantidad_por_piso);
            break;
        }
    }
    else
    {
        printf("\n***************************************");
        printf("\nEL HOTEL NO TIENE PISOS NI HABITACIONES CARGADAS");
    }
}

void modifico_informe(nodo_piso* celda_pisos, int cat)
{

    int opcion = 0;

    nodo_piso* itero_en_celda = inic_nodo_piso();

    do
    {
        system("cls");

        itero_en_celda = celda_pisos;
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
                    hab_buscada->hab.informe = modifica_informe_hab(hab_buscada->hab.informe, cat);
                    opcion = 0;
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

        if(itero_en_celda == inic_nodo_piso() && hab_buscada == inic_nodo_hab())
        {
            printf("\n***************************************");
            printf("\nPISO O HABITACION NO ENCONTRADA");
            printf("\nDESEA VOLVER A INTENTAR LA BUSQUEDA");
            opcion = Seleccion_Si_No();
        }
    }
    while(opcion == 1);
}

void modifica_estado_hab(nodo_piso* celda_pisos)
{
    int opcion = 0;

    nodo_piso* itero_en_celda = inic_nodo_piso();

    do
    {
        system("cls");

        itero_en_celda = celda_pisos;
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
                    hab_buscada->hab.informe.baja = menu_modifica_baja_hab();
                    printf("\n***************************************");
                    printf("\nHABITACION DADA DE BAJA CON EXITO");
                    opcion = 0;
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

        if(itero_en_celda == inic_nodo_piso() && hab_buscada == inic_nodo_hab())
        {
            printf("\n***************************************");
            printf("\nPISO O HABITACION NO ENCONTRADA");
            printf("\nDESEA VOLVER A REALIZAR LA BUSQUEDA?");
            opcion = Seleccion_Si_No();
        }
    }
    while(opcion == 1);
}

nodo_piso* modifica_estado_piso(nodo_piso* piso)
{
    int opcion;

    printf("\nQUE DESEA REALIZAR?");
    printf("\n1...DAR DE ALTA");
    printf("\n2...DAR DE BAJA");
    printf("\nELECCION: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion < 1 || opcion > 2)
    {
        printf("\nQUE DESEA REALIZAR?");
        printf("\n1...DAR DE ALTA");
        printf("\n2...DAR DE BAJA");
        printf("\nELECCION: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    if(opcion == 1)
    {
        piso->baja = 0;
        printf("\nPISO DADO DE ALTA CON EXITO!");

    }
    else
    {
        piso->baja = 1;
        printf("\nPISO DADO DE BAJA CON EXITO!");
    }

    return piso;
}

int retorna_cantidad_limpieza(nodo_piso* celda_pisos, int cat)
{
    nodo_piso* itero_en_celda = celda_pisos;

    int cantidad_por_piso = retorna_okey();

    if(itero_en_celda != inic_nodo_piso())
    {
        while(itero_en_celda != inic_nodo_piso())
        {
            if(itero_en_celda->baja == 0)
            {
                nodo_hab* itero_en_lista = itero_en_celda->lista_hab;

                cantidad_por_piso += cuento_hab(itero_en_lista, cat);

            }
            itero_en_celda = itero_en_celda ->piso_siguiente;
        }
    }

    return cantidad_por_piso;
}

///FUNCIONES GERENTE
int verificar_Cambio(int opcion)
{
    while(opcion > 4 || opcion < 1)
    {
        int opcion;
        system("cls");
        printf("\nSELECCIONE LA CATEGORIA DESEADA PARA VER SUS FUNCIONES");
        printf("\n***************************************");
        printf("\n1...GOBERNANTA");
        printf("\n2...RECEPCION");
        printf("\n3...MANTENIMIENTO");
        printf("\n4...MUCAMA");
        printf("\n***************************************");
        printf("\n\nELECCION: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;
}

int cambiar_Categoria()
{
    int opcion;

    printf("\nSELECCIONE LA CATEGORIA DESEADA PARA VER SUS FUNCIONES");
    printf("\n***************************************");
    printf("\n1...GOBERNANTA");
    printf("\n2...RECEPCION");
    printf("\n3...MANTENIMIENTO");
    printf("\n4...MUCAMA");
    printf("\n***************************************");
    printf("\n\nELECCION: ");
    fflush(stdin);
    scanf("%i", &opcion);
    opcion = verificar_Cambio(opcion);

    return opcion;
}

int verificar_Opcion_Empleado(int opcion)
{
    while(opcion > 4 || opcion < 1)
    {
        int opcion;
        system("cls");
        printf("\nIngreso una opcion invalida, intente nuevamente");
        printf("\nSeleccione que dato quiere editar:");
        printf("\n1.... PIN");
        printf("\n2.... Categoria");
        printf("\n3.... Nombre");
        printf("\n4.... Apellido");
        printf("\n\nIngrese el numero del dato a editar: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;
}

int verificar_Opcion_Datos_Personales(int opcion)
{
    while(opcion > 7 || opcion < 1)
    {
        int opcion;
        system("cls");
        printf("\nIngreso una opcion invalida, intente nuevamente");
        printf("\nSeleccione que dato quiere editar:");
        printf("\n1.... DNI");
        printf("\n2.... Celular");
        printf("\n3.... Edad");
        printf("\n4.... Genero");
        printf("\n5... Calle");
        printf("\n6... Altura");
        printf("\n7... Codigo Postal");
        printf("\n\nIngrese el numero del dato a editar: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;
}

arbol_Empleado* buscar_Legajo(arbol_Empleado* arbol_Actual, int legajo)
{
    arbol_Empleado* persona_En_Linea= inic_Arbol();

    if( arbol_Actual != NULL)
    {
        if(legajo == arbol_Actual ->actual.legajo)
        {
            persona_En_Linea = arbol_Actual;
        }
        else
        {
            if(legajo > arbol_Actual ->actual.legajo)
            {
                persona_En_Linea = buscar_Legajo( arbol_Actual ->derecha, legajo);
            }
            else
            {
                persona_En_Linea = buscar_Legajo( arbol_Actual ->izquierda, legajo);
            }
        }
    }

    return persona_En_Linea;
}

arbol_Empleado* dar_Baja_Empleado(arbol_Empleado* persona_En_Linea)
{
    system("cls");
    int opcion;

    mostrar_Empleado(persona_En_Linea->actual);
    printf("\n\nSeleccione que desea realizar:");
    printf("\n1... Dar de Baja");
    printf("\n2... Dar de Alta");
    printf("\n\nEleccion: ");
    scanf("%i", &opcion);
    while(opcion > 2 || opcion < 1)
    {
        printf("\nIngreso una opcion invalida, intente nuevamente");
        printf("\n\nSeleccione que desea realizar:");
        printf("\n1... Dar de baja");
        printf("\n2... Dar de Alta");
        printf("\n\nEleccion: ");
        scanf("%i", &opcion);
    }

    if(opcion == 1)
    {
        persona_En_Linea->actual.baja = 1;
    }
    else
    {
        persona_En_Linea->actual.baja = 0;
    }

    return persona_En_Linea;
}

arbol_Empleado* editar_Empleado(arbol_Empleado* persona_En_Linea)
{
    system("cls");
    int opcion, datoInt;
    char datoString[30];

    do
    {
        system("cls");
        mostrar_Empleado(persona_En_Linea->actual);
        printf("\n\nSeleccione que dato quiere editar:");
        printf("\n1.... PIN");
        printf("\n2.... Categoria");
        printf("\n3.... Nombre");
        printf("\n4.... Apellido");
        printf("\n\nEleccion: ");
        fflush(stdin);
        scanf("%i", &opcion);
        switch(verificar_Opcion_Empleado(opcion))
        {
        case 1:
            printf("\nPIN Actual: %i", persona_En_Linea->actual.pin);
            printf("\nNuevo PIN: ");
            fflush(stdin);
            scanf("%i", &datoInt);
            persona_En_Linea->actual.pin = verificar_PIN(datoInt);
            break;
        case 2:
            printf("\nCategoria Actual: %i", persona_En_Linea->actual.categoria);
            printf("\nSeleccione una nueva categoria:");
            printf("\n\n0...Gerente:");
            printf("\n1...Gobernanta:");
            printf("\n2...Recepcion:");
            printf("\n3...Mantenimiento:");
            printf("\n4...Mucama:");
            printf("\n\nEleccion: ");
            fflush(stdin);
            scanf("%i", &datoInt);
            persona_En_Linea->actual.categoria = verificar_Categoria(datoInt);
            break;
        case 3:
            printf("\nNombre Actual: %s", persona_En_Linea->actual.nombre);
            printf("\nNuevo Nombre: ");
            fflush(stdin);
            gets(datoString);
            strcpy(persona_En_Linea->actual.nombre, datoString);
            break;
        case 4:
            printf("\nApellido Actual: %s", persona_En_Linea->actual.apellido);
            printf("\nNuevo Apellido: ");
            fflush(stdin);
            gets(datoString);
            strcpy(persona_En_Linea->actual.apellido, datoString);
            break;
        }
        printf("\n\nDesea editar otro dato?");
        opcion = Seleccion_Si_No();

    }
    while(opcion == 1);

    return persona_En_Linea;
}

arbol_Empleado* editar_Datos_Personales(arbol_Empleado* persona_En_Linea)
{
    system("cls");
    int opcion, datoInt;
    long int datoLongInt;
    char datoString[30];
    do
    {
        system("cls");
        mostrar_Empleado(persona_En_Linea->actual);
        printf("\n\nSeleccione que dato quiere editar:");
        printf("\n1.... DNI");
        printf("\n2.... Celular");
        printf("\n3.... Edad");
        printf("\n4.... Genero");
        printf("\n5.... Calle");
        printf("\n6.... Altura");
        printf("\n7.... Codigo Postal");
        printf("\n\nEleccion: ");
        fflush(stdin);
        scanf("%i", &opcion);

        switch(verificar_Opcion_Datos_Personales(opcion))
        {
        case 1:
            printf("\nDNI Actual: %ld", persona_En_Linea->actual.datos.dni);
            printf("\nNuevo DNI: ");
            fflush(stdin);
            scanf("%ld", &datoLongInt);
            persona_En_Linea->actual.datos.dni = verificar_LongInt(datoLongInt);
            break;
        case 2:
            printf("\nCelular Actual: %s", persona_En_Linea->actual.datos.celular);
            printf("\nNuevo Celular: ");
            fflush(stdin);
            gets(datoString);
            strcpy(persona_En_Linea->actual.datos.celular, datoString);
            break;
        case 3:
            printf("\nEdad Actual: %i", persona_En_Linea->actual.datos.edad);
            printf("\nNueva Edad: ");
            fflush(stdin);
            scanf("%i", &datoInt);
            persona_En_Linea->actual.datos.edad = verificar_Int(datoInt);
            break;
        case 4:
            printf("\nGenero Actual: %i", persona_En_Linea->actual.datos.genero);
            printf("\nNuevo Genero: ");
            printf("\n1...Masculino ");
            printf("\n2...Femenino");
            printf("\n3...Otro");
            printf("\n\nEleccion: ");
            fflush(stdin);
            scanf("%i", &datoInt);
            persona_En_Linea->actual.datos.genero = verificar_Genero(datoInt);
            break;
        case 5:
            printf("\nCalle Actual: %s", persona_En_Linea->actual.datos.calle);
            printf("\nNueva Calle: ");
            fflush(stdin);
            gets(datoString);
            strcpy(persona_En_Linea->actual.datos.calle, datoString);
            break;
        case 6:
            printf("\nAltura de Calle Actual: %i", persona_En_Linea->actual.datos.altura);
            printf("\nNueva Altura: ");
            fflush(stdin);
            scanf("%i", &datoInt);
            persona_En_Linea->actual.datos.altura = verificar_Int(datoInt);
            break;
        case 7:
            printf("\nCodigo Postal Actual: %i", persona_En_Linea->actual.datos.postal);
            printf("\nNuevo Codigo Postal: ");
            fflush(stdin);
            scanf("%i", &datoInt);
            persona_En_Linea->actual.datos.postal = verificar_Int(datoInt);
            break;
        }
        printf("\n\nDesea editar otro dato?");
        opcion = Seleccion_Si_No();
    }
    while(opcion == 1);

    return persona_En_Linea;
}

arbol_Empleado* intercambiar_Datos_Empleado(arbol_Empleado* arbol_Actual, arbol_Empleado* nuevo)
{

    if( arbol_Actual != NULL)
    {
        if(nuevo->actual.legajo == arbol_Actual->actual.legajo)
        {
            arbol_Actual->actual = nuevo->actual;
        }
        else
        {
            if(nuevo->actual.legajo > arbol_Actual->actual.legajo)
            {
                arbol_Actual->derecha = intercambiar_Datos_Empleado(arbol_Actual->derecha, nuevo);
            }
            else
            {
                arbol_Actual->izquierda = intercambiar_Datos_Empleado(arbol_Actual->izquierda, nuevo);
            }
        }
    }

    return arbol_Actual;
}

void actualizar_file_Empleados(FILE* archivo, arbol_Empleado* arbol_Actual)
{
    if(arbol_Actual!=NULL)
    {
        st_Empleado dato = arbol_Actual->actual;
        fwrite(&dato, sizeof(dato),1,archivo);
        actualizar_file_Empleados(archivo, arbol_Actual->izquierda);
        actualizar_file_Empleados(archivo, arbol_Actual->derecha);
    }
}

arbol_Empleado* ver_Editar_Empleado(arbol_Empleado* arbol_Actual, char filename[])
{
    FILE* archivo = fopen(filename, "wb");
    ///
    int legajo, opcion;
    arbol_Empleado* persona_En_Linea;

    printf("INGRESE UN LEGAJO A BUSCAR: ");
    fflush(stdin);
    scanf("%i", &legajo);


    persona_En_Linea = buscar_Legajo(arbol_Actual, legajo);

    if(persona_En_Linea == NULL)
    {
        printf("\nNo se encontro un empleado con dicho legajo");
        printf("\n\n");
        system("pause");
        printf("\n");
    }
    else
    {
        mostrar_Empleado(persona_En_Linea->actual);
        printf("\n\nSeleccione opcion:");
        printf("\n1... Editar o agregar datos personales:");
        printf("\n2... Editar datos empleado:");
        printf("\n3... Dar de baja o alta empleado:");
        printf("\nEleccion: ");

        scanf("%i", &opcion);

        while(opcion < 1 || opcion > 3)
        {
            printf("\nIngreso una eleccion incorrecta, intente nuevamente:");
            printf("\n\nSeleccione opcion:");
            printf("\n1... Editar o agregar datos personales:");
            printf("\n2... Editar datos empleado:");
            printf("\n3... Dar de baja o alta empleado:");
            printf("\nEleccion: ");
            scanf("%i", &opcion);
        }
        switch(opcion)
        {
        case 1:
            persona_En_Linea = editar_Datos_Personales(persona_En_Linea);
            arbol_Actual = intercambiar_Datos_Empleado(arbol_Actual, persona_En_Linea);
            actualizar_file_Empleados(archivo, arbol_Actual);
            break;
        case 2:
            persona_En_Linea = editar_Empleado(persona_En_Linea);
            arbol_Actual = intercambiar_Datos_Empleado(arbol_Actual, persona_En_Linea);
            actualizar_file_Empleados(archivo, arbol_Actual);
            break;
        case 3:
            persona_En_Linea = dar_Baja_Empleado(persona_En_Linea);
            arbol_Actual = intercambiar_Datos_Empleado(arbol_Actual, persona_En_Linea);
            actualizar_file_Empleados(archivo, arbol_Actual);
            break;
        }
    }
    fclose(archivo);

    return arbol_Actual;
}

int elegir_Operacion_Pisos_Habitaciones()
{
    int opcion;

    printf("INGRESE QUE OPERACION DESEA REALIZAR");
    printf("\n***************************************");
    printf("\n1...AGREGAR UN PISO NUEVO Y AGREGARLE CON HABITACIONES");
    printf("\n2...AGREGAR HABITACIONES A UN PISO YA EXISTENTE");
    printf("\n3...DAR DE BAJA/ALTA UN PISO");
    printf("\n4...DAR DE BAJA/ALTA UNA HABITACION");
    printf("\n***************************************");
    printf("\nELECCION: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 4 || opcion < 1)
    {
        printf("INGRESE QUE OPERACION DESEA REALIZAR");
        printf("\n***************************************");
        printf("\n1...AGREGAR UN PISO NUEVO Y AGREGARLE CON HABITACIONES");
        printf("\n2...AGREGAR HABITACIONES A UN PISO YA EXISTENTE");
        printf("\n3...DAR DE BAJA/ALTA UN PISO");
        printf("\n4...DAR DE BAJA/ALTA UNA HABITACION");
        printf("\n***************************************");
        printf("\nELECCION: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;

}

st_inventario retorna_inventario_okey_hab()
{
    st_inventario chequeo;

    chequeo.telefono= retorna_okey();
    chequeo.control_tv= retorna_okey();
    chequeo.sabanas= retorna_okey();
    chequeo.acolchado= retorna_okey();
    chequeo.cubre_cama= retorna_okey();
    chequeo.toallas= retorna_okey();
    chequeo.toallones= retorna_okey();
    chequeo.cortinas= retorna_okey();
    chequeo.black_out= retorna_okey();


    chequeo.secador_pelo = retorna_uno();
    chequeo.agua = retorna_uno();
    chequeo.gaseosa_lima = retorna_uno();
    chequeo.gaseosa_naranja = retorna_uno();
    chequeo.cerveza = retorna_uno();

    return chequeo;
}

st_estado retorna_estado_hab_okey()
{
    st_estado informe;

    informe.baja = retorna_okey();
    informe.recepcion = retorna_okey();
    informe.estado_gob = retorna_okey();
    informe.estado_mante = retorna_okey();

    return informe;
}

st_hab retorna_hab_okey (int nro_hab)
{
    st_hab hab;

    hab.nro_hab = nro_hab;

    hab.informe = retorna_estado_hab_okey();

    hab.chequeo = retorna_inventario_okey_hab();

    hab.suite = 0;

    return hab;
}

st_inventario retorna_inventario_okey_suite()
{
    st_inventario chequeo;

    chequeo.telefono= retorna_okey();
    chequeo.control_tv= retorna_okey();
    chequeo.sabanas= retorna_okey();
    chequeo.acolchado= retorna_okey();
    chequeo.cubre_cama= retorna_okey();
    chequeo.toallas= retorna_okey();
    chequeo.toallones= retorna_okey();
    chequeo.cortinas= retorna_okey();
    chequeo.black_out= retorna_okey();

    chequeo.secador_pelo = retorna_okey();
    chequeo.agua = retorna_okey();
    chequeo.gaseosa_lima = retorna_okey();
    chequeo.gaseosa_naranja = retorna_okey();
    chequeo.cerveza = retorna_okey();

    return chequeo;
}

st_hab retorna_suite_okey (int nro_hab)
{
    st_hab suite;

    suite.nro_hab = nro_hab;

    suite.informe = retorna_estado_hab_okey();

    suite.chequeo = retorna_inventario_okey_suite();

    suite.suite = 1;

    return suite;
}


void escribo_hab_en_archivo (FILE* archivo_pisos, nodo_hab* hab_iteradora, int nro_piso, int baja)
{
    st_archivo_pisos hab_p_escribir;

    hab_p_escribir.nro_piso = nro_piso;

    hab_p_escribir.piso_baja = baja;

    while(hab_iteradora != inic_nodo_hab())
    {
        hab_p_escribir.hab = hab_iteradora -> hab;

        fwrite(&hab_p_escribir, sizeof(st_archivo_pisos), 1, archivo_pisos);

        hab_iteradora = hab_iteradora ->hab_siguiente;

        printf(".");
    }

    printf("Ok\n");
}


void itero_en_lista_hab_para_escribir ( FILE* archivo_pisos, nodo_hab* lista_hab, int nro_piso, int baja)
{
    nodo_hab* hab_iteradora = lista_hab;

    escribo_hab_en_archivo(archivo_pisos, hab_iteradora, nro_piso, baja);
}


void itero_en_celda_piso_para_escribir(nodo_piso* lista_pisos)
{
    nodo_piso* lista_iteradora = lista_pisos;

    FILE* archivo_pisos = fopen(ARCHIVO_P, "wb");
    printf("\n\n***************************************");
    printf("\nGUARDANDO EN ARCHIVO...\n");
    if(archivo_pisos)
    {
        while(lista_iteradora != inic_nodo_piso())
        {
            itero_en_lista_hab_para_escribir(archivo_pisos, lista_iteradora->lista_hab, lista_iteradora->nro_piso, lista_iteradora->baja);
            lista_iteradora = lista_iteradora ->piso_siguiente;
        }

        fclose(archivo_pisos);
    }
}


