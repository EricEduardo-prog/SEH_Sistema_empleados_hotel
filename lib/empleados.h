#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

long int verificar_LongInt(long int dato);
int verificar_Int(int dato);
int verificar_Genero(int dato);
int verificar_Categoria(int dato);
int Seleccion_Si_No();
int verificar_PIN(int dato);

typedef struct st_Datos_Personales
{
    long int dni;
    char celular[20];
    int edad;
    int genero; // 1 M, 2 F u 3 O
    char calle[20];
    int altura;
    int postal;

} st_Datos_Personales;


typedef struct st_Empleado
{
    int legajo;
    int pin;
    st_Datos_Personales datos;
    int categoria; // <0> GERENTE/ <1>Gobernanta / <2> Mantenimiento/ <3>Recepción / <4>Mucamas
    char nombre[20];
    char apellido[30];
    int baja;//0 alta // 1 baja

} st_Empleado;

int cargar_Empleado_Automatico(st_Empleado dato[]);
void guardar_Empleado_Automatico(st_Empleado dato[], char file[], int validos);


///FUNCIONES EMPLEADO
st_Datos_Personales cargar_Datos_Personales();
st_Datos_Personales inic_Datos_Personales();
st_Empleado cargar_Empleado();
st_Empleado ingreso_Empleado ();



#endif // EMPLEADOS_H_INCLUDED
