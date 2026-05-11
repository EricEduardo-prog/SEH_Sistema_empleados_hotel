#ifndef FNS_GERENTE_H_INCLUDED
#define FNS_GERENTE_H_INCLUDED

#include "string.h"
#include "empleados.h"
#include "inicio_sesion.h"
#include "fns_nodo_piso.h"
#include "fns_nodo_hab.h"

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


void itero_en_lista_hab_para_escribir ( FILE* archivo_pisos, nodo_hab* lista_hab, int nro_piso, int baja);
void escribo_hab_en_archivo (FILE* archivo_pisos, nodo_hab* hab_iteradora, int nro_piso, int baja);
void itero_en_celda_piso_para_escribir(nodo_piso* lista_pisos);

st_inventario retorna_inventario_okey_hab(); //
st_estado retorna_estado_hab_okey();
st_hab retorna_hab_okey (int nro_hab);

st_inventario retorna_inventario_okey_suite();
st_hab retorna_suite_okey(int nro_hab);

void muestro_informe( nodo_piso* celda_pisos, int cat);

int cuento_hab( nodo_hab* itero_en_lista, int cat);

void modifico_informe(nodo_piso* celda_pisos, int cat);

int elegir_Operacion_Pisos_Habitaciones();

nodo_piso* modifica_estado_piso(nodo_piso* piso);
void modifica_estado_hab(nodo_piso* celda_pisos);

int retorna_cantidad_limpieza(nodo_piso* celda_pisos, int cat);

#endif // FNS_GERENTE_H_INCLUDED
