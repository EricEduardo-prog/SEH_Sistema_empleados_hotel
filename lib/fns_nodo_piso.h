#ifndef FNS_NODO_PISO_H_INCLUDED
#define FNS_NODO_PISO_H_INCLUDED
#include "fns_nodo_hab.h"

typedef struct nodo_piso
{
    int nro_piso;
    int baja;
    struct nodo_hab* lista_hab;
    struct nodo_piso* piso_siguiente;

} nodo_piso;

nodo_piso* inic_nodo_piso();
nodo_piso* creo_nodo_piso(int nro_piso);

nodo_piso* creo_nodo_piso_desde_archivo(st_archivo_pisos hab);
nodo_piso* agregar_al_comienzo_nodo_piso(nodo_piso* lista_pisos, nodo_piso* nuevo_piso);

//nodo_hab* enlisto_hab_para_mucama(nodo_piso* celda_pisos, st_Empleado empleado); /// Necesitare una constante para determinar cuantas hab puede tener cada mucama


nodo_piso* LDL_busco_piso(nodo_piso* lista_pisos, st_archivo_pisos hab);
nodo_piso* busco_Piso(nodo_piso* lista_pisos, int piso);
nodo_piso* agrego_en_orden_pisos( nodo_piso* lista_pisos, nodo_piso* nuevo_piso);
nodo_piso* busco_ultimo_nodo_piso (nodo_piso* lista_pisos);
nodo_piso* subPrograma_agregar_Piso(nodo_piso* lista_pisos);
nodo_piso* agregar_Piso(nodo_piso* lista_pisos);
nodo_piso* agregar_al_final_nodo_piso( nodo_piso* lista_pisos, nodo_piso* nuevo_piso);
nodo_piso* cargo_LDL (nodo_piso* lista_pisos, st_archivo_pisos hab);
nodo_piso* paso_archivo_hacia_LDL( nodo_piso* lista_pisos);
void liberar_hab_y_pisos(nodo_piso* lista_pisos);
nodo_piso* invertir_pisos(nodo_piso* lista);
nodo_piso* existe_Piso(nodo_piso* lista_pisos);
void mostrarListaDeLista(nodo_piso* lista_pisos);
void existe_Hab(nodo_piso* lista_pisos);

#endif // FNS_NODO_PISO_H_INCLUDED
