#include <stdio.h>
#include <stdlib.h>

#include "string.h"
#include "empleados.h"
#include "inicio_sesion.h"

///FUNCIONES GERENTE
int verificar_Cambio(int opcion)
{
    while(opcion > 4 || opcion < 1)
    {
        int opcion;
        system("cls");
        printf("\nIngreso una opcion invalida, intente nuevamente");
        printf("\nSeleccione la categoria deseada para mostrar sus funciones");
        printf("\n1...Gobernanta");
        printf("\n2...Recepcion");
        printf("\n3...Mantenimiento");
        printf("\n4...Mucama");
        printf("\n\nEleccion: ");
        fflush(stdin);
        scanf("%i", &opcion);
    }

    return opcion;
}

int cambiar_Categoria()
{
    int opcion;

    printf("\nSeleccione la categoria deseada para mostrar sus funciones");
    printf("\n1...Gobernanta");
    printf("\n2...Recepcion");
    printf("\n3...Mantenimiento");
    printf("\n4...Mucama");
    printf("\n\nEleccion: ");
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

    printf("Ingrese un legajo a buscar: ");
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
