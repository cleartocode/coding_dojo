# Coding Dojo 🥋

Repositorio personal para practicar **fluidez de programación** en Python, C, C++ y Rust.  
Objetivo: mejorar la velocidad y precisión al pasar de la idea → pseudocódigo → código.

## 📂 Estructura
```
coding_dojo/
c/ # ejercicios en C
cpp/ # ejercicios en C++
python/ # ejercicios en Python
rust/ # ejercicios en Rust
new_kata.sh # script para crear nuevos ejercicios
Makefile # targets comunes para test/run
```

## 🚀 Flujo de trabajo
1. Crear nuevo ejercicio:
   ```
   ./new_kata.sh <python|cpp|rust> <nombre_ejercicio>
   ```
2. Implementar solve(...) en el archivo creado.

## Ejecutar tests:
```
make test LANG=<python|cpp|rust> NAME=<nombre_ejercicio>
```

## Ejecutar programa (solo C++ y Rust, si tienen main):
```
make run LANG=<cpp|rust> NAME=<nombre_ejercicio>
```

## 🛠 Requisitos

```
gcc/clang con -std=c11
Python 3 + pytest
g++ (C++20)
Rust + Cargo
```

## 📅 Plan de práctica
Intercalado semanal: Lunes (Python), Martes (C++), Miércoles (Rust), Jueves (Python), Viernes (C++).

Cada ejercicio dura máx. 30 minutos.

Mantener tests primero y pseudocódigo de ≤10 líneas.
