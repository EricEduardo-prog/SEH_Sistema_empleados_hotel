#ifndef FUNCIONESMENU_H_INCLUDED
#define FUNCIONESMENU_H_INCLUDED
#include "string.h"
#include "empleados.h"
#include "inicio_sesion.h"

///FUNCIONES GERENTE
int verificar_Cambio(int opcion);
int cambiar_Categoria();
arbol_Empleado* intercambiar_Datos_Empleado(arbol_Empleado* arbol_Actual, arbol_Empleado* nuevo);
arbol_Empleado* buscar_Legajo(arbol_Empleado* arbol_Actual, int legajo);
arbol_Empleado* intercambiar_Datos_Empleado(arbol_Empleado* arbol_Actual, arbol_Empleado* nuevo);
void actualizar_file_Empleados(FILE* archivo, arbol_Empleado* arbol_Actual);

int verificar_Opcion_Empleado(int opcion);
int verificar_Opcion_Datos_Personales(int opcion);
arbol_Empleado* editar_Datos_Personales(arbol_Empleado* persona_En_Linea);
arbol_Empleado* ver_Editar_Empleado(arbol_Empleado* arbol_Actual, char filename[]);
arbol_Empleado* editar_Empleado(arbol_Empleado* persona_En_Linea);
arbol_Empleado* dar_Baja_Empleado(arbol_Empleado* persona_En_Linea);

#endif // FUNCIONESMENU_H_INCLUDED
