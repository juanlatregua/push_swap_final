Organización del Proyecto push_swap
Para mantener el código organizado y fácil de mantener, es común dividir el proyecto en múltiples archivos. Esta estructura permite una mejor gestión de las dependencias, facilita la compilación modular y hace que el código sea más legible y mantenible.

Estructura de Directorios
La estructura típica del proyecto podría ser:

css
Copiar código
push_swap/
├── includes/
│   └── push_swap.h
├── operation/
│   ├── push.c
│   ├── reverse_rotate.c
│   ├── rotate.c
│   ├── swap.c
├── src/
│   ├── do_move.c
│   ├── input_check_list.c
│   ├── input_check.c
│   ├── main.c
│   ├── position.c
│   ├── sort_utils.c
│   ├── sort.c
│   ├── stack_functions.c
│   ├── utils.c
└── Makefile
Descripción de los Archivos
includes/push_swap.h:

Contiene todas las declaraciones de funciones y la definición de la estructura t_stack.
Se incluye en todos los archivos .c para que puedan usar las funciones y estructuras declaradas en él.
