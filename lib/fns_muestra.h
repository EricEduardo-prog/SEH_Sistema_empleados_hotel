#ifndef FNS_MUESTRA_H_INCLUDED
#define FNS_MUESTRA_H_INCLUDED
#include "fns_generales.h"
#include "fns_nodo_piso.h"

void muestra_todo_okey();
void muestra_hab_con_informe(st_hab hab);
void muestra_inventario_hab( st_hab hab);
void muestra_informe_hab (st_estado informe);
void muestra_informe_baja(int baja);
void muestra_informe_huesped(int huesped);
void muestra_informe_gob(int estado_gob);
void muestra_informe_mante(int estado_mante);
void muestra_lista_hab(nodo_hab* lista_hab, int cat);

void muestra_nro_piso (int nro_piso);

void muestra_lista_pisos(nodo_piso* lista_pisos, int cat);

void muestro_archivo_pisos ();

void mostrar_Datos_Personales (st_Datos_Personales dato);
void mostrar_Datos_Personales_Vacio ();
void mostrar_Empleado(st_Empleado dato);

///ARCHIVO EMPLEADO
void mostrar_Registro_Empleados_Recursivo(FILE* archivo);

#endif // FNS_MUESTRA_H_INCLUDED
