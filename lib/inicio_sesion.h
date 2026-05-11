#ifndef INICIO_SESION_H_INCLUDED
#define INICIO_SESION_H_INCLUDED
#include "empleados.h"

typedef struct arbol_Empleado
{
    st_Empleado actual;
    struct arbol_Empleado* izquierda;
    struct arbol_Empleado* derecha;

}arbol_Empleado;


///FUNCIONES ARBOLES
arbol_Empleado* inic_Arbol();
arbol_Empleado* crear_Nodo_Arbol(st_Empleado dato);
arbol_Empleado* insertar_Recursivo (arbol_Empleado* arbol_Actual, st_Empleado dato);
arbol_Empleado* insertar_Empleados_Arbol(char filename[], arbol_Empleado* arbol_Actual);
void in_Order( arbol_Empleado* arbol_Actual);
void in_Order_Segun_Categoria(arbol_Empleado* arbol_Actual, int categoria);

st_Empleado crea_guarda_Empleado(char filename[], arbol_Empleado* arbol_Actual);
arbol_Empleado* verifica_inicio_Sesion(arbol_Empleado* persona_En_Linea, arbol_Empleado* arbol_Actual);
arbol_Empleado* buscar_Recursivo( arbol_Empleado* arbol_Actual, st_Empleado dato);
int cantidad_Determinada_Categoria(arbol_Empleado* arbol_Actual, int categoria);

int bienvenido();
int subPrograma_verifica_inicio_Sesion();
void suspendido();

#endif // INICIO_SESION_H_INCLUDED
