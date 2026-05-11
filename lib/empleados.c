#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "empleados.h"
#include "inicio_sesion.h"
#include "fns_muestra.h"

/*
int cargar_Empleado_Automatico(st_Empleado dato[])
{
    int i=0;

    /// RECEPCION
    strcpy(dato[i].nombre, "Sergio");
    strcpy(dato[i].apellido, "Gomez");
    dato[i].baja = 0;
    dato[i].categoria = 2;
    dato[i].legajo = 503;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    ///MANTENIMIENTO
    strcpy(dato[i].nombre, "Angel");
    strcpy(dato[i].apellido, "Ferrin");
    dato[i].baja = 0;
    dato[i].categoria = 3;
    dato[i].legajo = 703;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    ///GOBERNANTA
    strcpy(dato[i].nombre, "Marta");
    strcpy(dato[i].apellido, "Rodriguez");
    dato[i].baja = 0;
    dato[i].categoria = 1;
    dato[i].legajo = 303;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    ///RECEPCION
    strcpy(dato[i].nombre, "Mauricio");
    strcpy(dato[i].apellido, "Gonzalez");
    dato[i].baja = 0;
    dato[i].categoria = 2;
    dato[i].legajo = 502;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    ///RECEPCION
    strcpy(dato[i].nombre, "Fabricio");
    strcpy(dato[i].apellido, "Perez");
    dato[i].baja = 0;
    dato[i].categoria = 2;
    dato[i].legajo = 505;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    ///RECEPCION
    strcpy(dato[i].nombre, "Julieta");
    strcpy(dato[i].apellido, "Diaz");
    dato[i].baja = 0;
    dato[i].categoria = 2;
    dato[i].legajo = 504;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    ///RECEPCION
    strcpy(dato[i].nombre, "Micaela");
    strcpy(dato[i].apellido, "Guzman");
    dato[i].baja = 0;
    dato[i].categoria = 2;
    dato[i].legajo = 501;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Mateo");
    strcpy(dato[i].apellido, "Danilo");
    dato[i].baja = 0;
    dato[i].categoria = 2;
    dato[i].legajo = 506;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Valentina");
    strcpy(dato[i].apellido, "Fernandez");
    dato[i].baja = 0;
    dato[i].categoria = 2;
    dato[i].legajo = 500;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    ///GOBERNANTA
    strcpy(dato[i].nombre, "Marta");
    strcpy(dato[i].apellido, "Rodriguez");
    dato[i].baja = 0;
    dato[i].categoria = 1;
    dato[i].legajo = 302;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Macarena");
    strcpy(dato[i].apellido, "Blanco");
    dato[i].baja = 0;
    dato[i].categoria = 1;
    dato[i].legajo = 304;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Andrea");
    strcpy(dato[i].apellido, "Ledesma");
    dato[i].baja = 0;
    dato[i].categoria = 1;
    dato[i].legajo = 301;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Nora");
    strcpy(dato[i].apellido, "Prats");
    dato[i].baja = 0;
    dato[i].categoria = 1;
    dato[i].legajo = 305;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Victoria");
    strcpy(dato[i].apellido, "Jimenez");
    dato[i].baja = 0;
    dato[i].categoria = 1;
    dato[i].legajo = 300;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;


    /// MANTENIMIENTO
    strcpy(dato[i].nombre, "Juan");
    strcpy(dato[i].apellido, "Vignati");
    dato[i].baja = 0;
    dato[i].categoria = 3;
    dato[i].legajo = 702;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Oscar");
    strcpy(dato[i].apellido, "Gutierrez");
    dato[i].baja = 0;
    dato[i].categoria = 3;
    dato[i].legajo = 704;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Martin");
    strcpy(dato[i].apellido, "Fernandez");
    dato[i].baja = 0;
    dato[i].categoria = 3;
    dato[i].legajo = 701;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Alfredo");
    strcpy(dato[i].apellido, "Sales");
    dato[i].baja = 0;
    dato[i].categoria = 3;
    dato[i].legajo = 705;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Julieta");
    strcpy(dato[i].apellido, "Morera");
    dato[i].baja = 0;
    dato[i].categoria = 3;
    dato[i].legajo = 700;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    /// MUCAMAS
    strcpy(dato[i].nombre, "Elizabeth");
    strcpy(dato[i].apellido, "Domingo");
    dato[i].baja = 0;
    dato[i].categoria = 4;
    dato[i].legajo = 903;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Agustina");
    strcpy(dato[i].apellido, "Berrocal");
    dato[i].baja = 0;
    dato[i].categoria = 4;
    dato[i].legajo = 902;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Nicoleta");
    strcpy(dato[i].apellido, "Gomez");
    dato[i].baja = 0;
    dato[i].categoria = 4;
    dato[i].legajo = 901;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Natalia");
    strcpy(dato[i].apellido, "Sacristan");
    dato[i].baja = 0;
    dato[i].categoria = 4;
    dato[i].legajo = 905;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Delfina");
    strcpy(dato[i].apellido, "Valcarcel");
    dato[i].baja = 0;
    dato[i].categoria = 4;
    dato[i].legajo = 900;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;


    ///GERENTE


    strcpy(dato[i].nombre, "Eric");
    strcpy(dato[i].apellido, "Gimenez");
    dato[i].baja = 0;
    dato[i].categoria = 0;
    dato[i].legajo = 101;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Blas");
    strcpy(dato[i].apellido, "Machado");
    dato[i].baja = 0;
    dato[i].categoria = 0;
    dato[i].legajo = 100;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    strcpy(dato[i].nombre, "Matias");
    strcpy(dato[i].apellido, "Pascual");
    dato[i].baja = 0;
    dato[i].categoria = 0;
    dato[i].legajo = 102;
    dato[i].pin = 1234;
    dato[i].datos = inic_Datos_Personales();
    i++;

    return i;

}
*/

void guardar_Empleado_Automatico(st_Empleado dato[], char file[], int validos)
{
    FILE* archivo = fopen(file, "wb");

    for(int i=0; i<validos; i++)
    {
        fwrite(&dato[i], sizeof(dato[i]),1,archivo);
    }
    fclose(archivo);
}


long int verificar_LongInt(long int dato)
{
    if(dato < 0)
    {
        printf("\nIngreso un dato invalido, intente nuevamente: ");
        fflush(stdin);
        scanf("%ld", &dato);
    }
    return dato;
}

int verificar_Int(int dato)
{
    if(dato < 0)
    {
        printf("\nIngreso un dato invalido, intente nuevamente: ");
        fflush(stdin);
        scanf("%i", &dato);
    }
    return dato;
}

int verificar_Genero(int dato)
{
    while(dato > 3 || dato <1)
    {
        printf("\nIngreso una opcion invalida, intente nuevamente");
        printf("Genero: ");
        printf("\n1...Masculino");
        printf("\n2...Femenino");
        printf("\n3...Otro");
        printf("\n\nEleccion: ");
        fflush(stdin);
        scanf("%i", &dato);
    }

    return dato;
}
///verificar String?

st_Datos_Personales cargar_Datos_Personales()
{
    st_Datos_Personales dato;

    printf("DNI: ");
    fflush(stdin);
    scanf("%ld", &dato.dni);
    dato.dni = verificar_LongInt(dato.dni);

    printf("Celular: ");
    fflush(stdin);
    gets(dato.celular);

    printf("Edad: ");
    fflush(stdin);
    scanf("%i", &dato.edad);
    dato.edad = verificar_Int(dato.edad);

    printf("Genero: ");
    printf("\n1...Masculino");
    printf("\n2...Femenino");
    printf("\n3...Otro");
    printf("\n\nEleccion: ");
    fflush(stdin);
    scanf("%i", &dato.genero);
    dato.genero = verificar_Genero(dato.genero);

    printf("Calle: ");
    fflush(stdin);
    gets(dato.calle);
    ///verificar String?

    printf("Altura: ");
    fflush(stdin);
    scanf("%i", &dato.altura);
    dato.altura = verificar_Int(dato.altura);

    printf("Codigo Postal: ");
    fflush(stdin);
    scanf("%i", &dato.postal);
    dato.postal = verificar_Int(dato.postal);

    return dato;
}


st_Datos_Personales inic_Datos_Personales()
{
    st_Datos_Personales vacio;

    vacio.altura = 0;
    strcpy(vacio.calle, "No especificado");
    strcpy(vacio.celular, "No especificado");
    vacio.dni = 0;
    vacio.edad = 0;
    vacio.genero = 0;
    vacio.postal = 0;

    return vacio;
}

int verificar_Categoria(int dato)
{
    while(dato > 4 || dato < 0)
    {

        system("cls");
        printf("INGRESO UNA OPCION INVALIDA, INTENTE NUEVAMENTE");
        printf("\nINGRESE LA CATEGORIA PARA VER SUS EMPLEADOS");
        printf("\n\n0...GERENTE");
        printf("\n1...GOBERNANTA");
        printf("\n2...RECEPCION");
        printf("\n3...MANTENIMIENTO");
        printf("\n4...MUCAMA");
        printf("\n\nELECCION: ");
        fflush(stdin);
        scanf("%i", &dato);
        if(dato >= 0 && dato <= 4)
        {
            system("cls");
        }
    }

    return dato;
}

int verificar_PIN (int dato)
{
    while(dato < 1000 || dato > 9999)
    {
        printf("\nIngreso un formato de PIN incorrecto\n");
        printf("\nATENCION: EL PIN debe contener 4 digitos entre los numeros 0 a 9");
        printf("\nATENCION: Dicho PIN no puede comenzar con 0");
        printf("\nIngrese un PIN:");
        fflush(stdin);
        scanf("%i", &dato);

        if(dato >= 1000 && dato <= 9999)
        {
            system("cls");
            printf("PIN CORRECTO\n");
        }
    }
    return dato;
}

int Seleccion_Si_No()
{
    int opcion;

    printf("\n1...SI");
    printf("\n0...NO");
    printf("\n\nELECCION: ");
    fflush(stdin);
    scanf("%i", &opcion);

    while(opcion > 1 || opcion < 0)
    {
        printf("\nINGRESO UNA OPCION INVALIDA, INTENTE NUEVAMENTE");
        printf("\n\n1...SI");
        printf("\n0...NO");
        printf("\nELECCION: ");
        scanf("%i", &opcion);
    }

    return opcion;
}

st_Empleado cargar_Empleado(arbol_Empleado* arbol_Actual)
{
    st_Empleado nuevo;

    int opcion;
    int cantidad;

    printf("\nCargando Nuevo Empleado:");
    printf("\n\nSeleccione una categoria:");
    printf("\n\n0...Gerente");
    printf("\n1...Gobernanta");
    printf("\n2...Recepcion");
    printf("\n3...Mantenimiento");
    printf("\n4...Mucama");
    printf("\n\nEleccion: ");
    fflush(stdin);
    scanf("%i", &nuevo.categoria);
    nuevo.categoria = verificar_Categoria(nuevo.categoria);

    printf("Categoria seleccionada: ");

    cantidad = cantidad_Determinada_Categoria(arbol_Actual, nuevo.categoria);

    switch(nuevo.categoria)
    {
    case 0:
        printf("GERENTE");
        nuevo.legajo = 100 + cantidad;
        break;
    case 1:
        printf("GOBERNANTA");
        nuevo.legajo = 300 + cantidad;
        break;
    case 2:
        printf("RECEPCION");
        nuevo.legajo = 500 + cantidad;
        break;
    case 3:
        printf("MANTENIMIENTO");
        nuevo.legajo = 700 + cantidad;
        break;
    case 4:
        printf("MUCAMA");
        nuevo.legajo = 900 + cantidad;
        break;
    }

    printf("\n\nLegajo asignado: %i", nuevo.legajo);

    printf("\n\nCreacion de PIN:");
    printf("\nATENCION: EL PIN debe contener 4 digitos entre los numeros 0 a 9");
    printf("\nATENCION: Dicho PIN no puede comenzar con 0");
    printf("\nIngrese un PIN: ");
    fflush(stdin);
    scanf("%i", &nuevo.pin);
    nuevo.pin = verificar_PIN(nuevo.pin);

    printf("\nCompletar datos personales obligatorios:");

    printf("\nNombre: ");
    fflush(stdin);
    gets(nuevo.nombre);

    ///verificar String?

    printf("Apellido: ");
    fflush(stdin);
    gets(nuevo.apellido);

    ///Verificar String?

    printf("\nDesea completar los datos personales restantes?");
    opcion = Seleccion_Si_No();

    if(opcion == 1)
    {
        nuevo.datos = cargar_Datos_Personales();
    }
    else
    {
        nuevo.datos = inic_Datos_Personales();
    }

    nuevo.baja = 0;

    return nuevo;
}

st_Empleado ingreso_Empleado ()
{
    st_Empleado dato;
    printf("INGRESE SU LEGAJO: ");
    scanf("%i", &dato.legajo);


    printf("\nINGRESE SU PIN: ");
    scanf("%i", &dato.pin);

    return dato;
}
