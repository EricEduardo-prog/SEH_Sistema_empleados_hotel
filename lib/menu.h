#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "fns_nodo_hab.h"
#include "fns_nodo_piso.h"
#include "inicio_sesion.h"

///MENU HOTEL
int subPrograma_mostrar_Hotel();
void mostrar_Hotel(nodo_piso* lista_pisos, int cat);

///MENU MUCAMA
int subPrograma_menuMucama();
void menuMucama(arbol_Empleado* persona_En_Linea);

///MENU MANTENIMIENTO
int subPrograma_menuMantenimiento();
void menuMantenimiento(arbol_Empleado* persona_En_Linea, nodo_piso* celda_pisos);

///MENU GOBERNANTA

int subPrograma_mostrar_limpieza_Gobernanta();
void mostrar_limpieza_Gobernanta(nodo_piso* lista_pisos, int tipo);
int subPrograma_limpieza_Gobernanta(nodo_piso* lista_pisos);
void limpieza_Gobernanta(nodo_piso* lista_pisos);
int subPrograma_menuGobernanta();
void menuGobernanta(arbol_Empleado* persona_En_Linea, nodo_piso* celda_pisos);

///MENU RECEPCION
int subPrograma_menuRecepcion();
void menuRecepcion(arbol_Empleado* persona_En_Linea, nodo_piso* celda_pisos);

///MENU GERENTE
int subPrograma_administrar_Empleados_Gerente();
void administrar_Empleados_Gerente(arbol_Empleado* persona_En_Linea, arbol_Empleado* arbol_Actual, char filename[], nodo_piso* celda_pisos);
int subPrograma_administrar_Hotel_Gerente();
void administrar_Hotel_Gerente(nodo_piso* celda_pisos);
int subPrograma_menuGerente();
void menuGerente(arbol_Empleado* persona_En_Linea, arbol_Empleado* arbol_Actual, char filename[], nodo_piso* celda_pisos);

///MENUES EXTRAS
int menu_modifica_estado_hab();
int menu_modifica_estado_hab_recepcion();

st_estado modifica_informe_hab_Recepcion(st_estado informe);
st_estado modifica_informe_hab_Gerente(st_estado informe);
st_estado modifica_informe_hab(st_estado informe, int cat);

int menu_modifica_baja_hab();
int menu_modifica_huesped_hab();
int menu_modifica_gob_hab();
int menu_modifica_mante_hab();
#endif // MENU_H_INCLUDED
