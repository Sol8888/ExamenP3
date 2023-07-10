#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

typedef struct {
    int codigo;
    char nombre[MAX_LENGTH];
    char carrera[MAX_LENGTH];
    float nota1;
    float nota2;
    float nota3;
} Estudiante;
