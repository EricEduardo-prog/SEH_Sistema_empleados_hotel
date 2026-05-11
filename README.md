# S-E-H — Sistema de Empleados de Hotel

[![C](https://img.shields.io/badge/C-99-blue.svg)](https://gcc.gnu.org/)
[![Estado](https://img.shields.io/badge/estado-completado-brightgreen)]()

> Sistema de gestión hotelera desarrollado en lenguaje C con enfoque en arquitectura modular, estructuras dinámicas y persistencia binaria.
> Proyecto realizado para el examen final de Programación II — UTN Mar del Plata (2022).

---

# 📌 Descripción

S-E-H es una aplicación de consola desarrollada en C que administra empleados, pisos y habitaciones de un hotel mediante estructuras dinámicas y archivos binarios.

El proyecto fue diseñado aplicando conceptos de programación estructurada y organización modular similares a estándares profesionales utilizados en sistemas backend de bajo nivel.

Entre sus principales características se incluyen:

- Gestión de empleados mediante ABB (Árbol Binario de Búsqueda)
- Administración dinámica de pisos y habitaciones
- Persistencia inmediata en archivos binarios
- Sistema de login con control de acceso por roles
- Validaciones completas de datos
- Liberación segura de memoria dinámica
- Arquitectura desacoplada por módulos

---

# 🧠 Conceptos y buenas prácticas implementadas

| Concepto | Implementación |
|----------|----------------|
| **Arquitectura modular** | Separación por responsabilidades en `lib/empleados.c`, `inicio_sesion.c`, `fns_archivo.c`, `menu.c`, etc. |
| **ABB (Árbol Binario de Búsqueda)** | Empleados organizados por legajo para optimizar búsquedas y login. |
| **Listas enlazadas** | Pisos y habitaciones administrados dinámicamente sin tamaños fijos. |
| **Persistencia binaria** | Escritura inmediata en archivos `.dat` y `.bin` luego de cada modificación. |
| **Gestión manual de memoria** | Liberación completa mediante `liberar_hotel()` y `liberar_arbol()`. |
| **Validación de entradas** | Verificación de DNI, edad, celular y otros campos antes de insertar datos. |
| **Control de acceso** | Menús dinámicos según categoría del empleado autenticado. |
| **Manejo de errores** | Validación de aperturas de archivos y retornos `NULL` / `0` / `1`. |

---

# 🏗️ Arquitectura del sistema

## Hotel

```text
Hotel
 ├── Piso 1
 │    ├── Habitación 101
 │    ├── Habitación 102
 │
 ├── Piso 2
 │    ├── Habitación 201
 │
 └── Piso N
```

### Estructuras utilizadas

- Lista enlazada simple para pisos
- Lista enlazada simple para habitaciones

---

## Empleados

```text
            (1001)
           /      \
        (512)    (2048)
        /   \        \
     (256) (768)   (4096)
```

### Estructura utilizada

- Árbol Binario de Búsqueda (ABB) ordenado por legajo

---

# 🔐 Sistema de login y roles

El sistema autentica empleados mediante legajo y contraseña.

Dependiendo de la categoría del usuario autenticado, se habilitan diferentes menús y permisos dentro del sistema.

Cada modificación realizada:

- actualiza la estructura en memoria
- y se guarda inmediatamente en disco

Esto evita pérdida de información ante cierres inesperados.

---

# 💾 Persistencia de datos

Archivos utilizados:

| Archivo | Función |
|----------|----------|
| `Registro_Empleados.dat` | Almacena empleados |
| `archivo_pisos.bin` | Almacena pisos y habitaciones |

---

# 🧩 Organización del proyecto

```text
3.1/
│
├── main.c
│
├── lib/
│   ├── empleados.c
│   ├── inicio_sesion.c
│   ├── fns_archivo.c
│   ├── menu.c
│   └── ...
│
├── archivo_pisos.bin
├── Registro_Empleados.dat
│
└── README.md
```

---

# 🛠️ Compilación y ejecución

## Requisitos

- GCC
- Windows (desarrollado y probado en Windows)
- Consola CMD / PowerShell

---

## Compilar

```bash
gcc -Wall -Ilib -o seh.exe main.c lib/*.c
```

## Ejecutar

```bash
./seh.exe
```

---

# 📚 Tecnologías utilizadas

- Lenguaje C (C99)
- Memoria dinámica
- Archivos binarios
- Listas enlazadas
- Árboles binarios de búsqueda
- Programación modular

---

# 🎯 Objetivos académicos del proyecto

Este proyecto fue desarrollado con el objetivo de aplicar:

- estructuras dinámicas complejas
- manejo manual de memoria
- persistencia de datos
- organización modular
- validación de datos
- diseño lógico de sistemas

simulando un entorno de desarrollo real orientado a backend de bajo nivel.

---

# 👨‍💻 Autores

Desarrollado por Eric Giménez y Blas Machado 
UTN Mar del Plata
