#ifndef FNS_NODO_HAB_H_INCLUDED
#define FNS_NODO_HAB_H_INCLUDED

#include "fns_generales.h"

typedef struct st_estado
{
    int baja; ///<0> Okey (disponible, para usar)/ <1> No disponible, de baja.
    int recepcion; ///<0> Okey (sin huesped) <1> Ocupada(Huesped en habitacion/No molestar). <2> Ocupada (Huespedes fuera de la hab)< 3 > Check out.
    int estado_gob; /// <0> Okey(Limpia, sin huesped) / <1> Para Limpieza intermedia / <2> Limpieza completa, termino estadia del huesped.
    int estado_mante; /// <0> Okey(Sin arreglos pendientes) / <1>Pedido de reparación por GERENTE <2> Pedido de reparacion por  Gobernanta/ < 3 >Pedido de reparacion por Recepcion.

} st_estado;

typedef struct st_inventario
{
    int telefono;
    int control_tv;
    int sabanas;
    int acolchado;
    int cubre_cama;
    int toallas;
    int toallones;
    int cortinas;
    int black_out;
                    /// De aca para abajo unicamente en SUITES
    int secador_pelo;
    int agua;
    int gaseosa_lima;
    int gaseosa_naranja;
    int cerveza;

} st_inventario;

typedef struct st_hab
{
    int nro_hab;
    int suite;
    struct st_estado informe;
    struct st_inventario chequeo;

} st_hab;

typedef struct nodo_hab
{
    st_hab hab;
    struct nodo_hab* hab_siguiente;

} nodo_hab;

typedef struct st_archivo_pisos
{
    int nro_piso;
    int piso_baja;
    st_hab hab;

} st_archivo_pisos;

int retorna_okey();
int retorna_uno();
int esta_okey_la_hab ( nodo_hab* iterador_lista_hab);
void esta_okey(int elemento_a_chequear);
int retorna_id_piso(int nro_hab);

nodo_hab* inic_nodo_hab ();
nodo_hab* crea_hab_okey (int nro_hab);
nodo_hab* crea_nodo_hab (st_hab hab);
nodo_hab* creo_nodo_hab ( st_archivo_pisos habitacion);
nodo_hab* agregar_al_comienzo_lista_hab (nodo_hab* lista_hab, nodo_hab* nueva_hab);
nodo_hab* agrego_en_orden_hab(nodo_hab* lista_hab, nodo_hab* nueva_hab);
nodo_hab* agregar_habitaciones(nodo_hab* lista_hab, int nro_Piso);
nodo_hab* agregar_habitaciones_suite(nodo_hab* lista_hab, int nro_Piso);
nodo_hab* subPrograma_agregar_habitaciones(nodo_hab* lista_hab, int nro_piso);
nodo_hab* crea_lista_hab(int iterador_piso);
nodo_hab* crea_lista_hab_suite();
int cantidad_Agregar_Habitaciones();
nodo_hab* busco_hab (nodo_hab* lista_hab, int nro_hab);
nodo_hab* busco_ultimo_nodo_hab(nodo_hab* lista_hab);
void libera_nodos_hab(nodo_hab* lista_hab);
int elegir_tipo_Habitacion();
int elegir_Habitacion();


#endif // FNS_NODO_HAB_H_INCLUDED
