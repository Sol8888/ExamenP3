#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LARGO 50

typedef struct {
    int codigo;
    char nombre[MAX_LARGO];
    char carrera[MAX_LARGO];
    float N1;
    float N2;
    float N3;
} Estudiante;

float calcularPromedio(float N1, float N2, float N3,) {
     return (N1 + N2+ N3)/3;
}

int compararEstu( const void* estu1, const void* estu2) {
    Estudiante* e1 = (Estudiante*)estu1;
    Estudiante* e2 = (Estudiante*)estu2;
    return e2->codigo - e1->codigo;
}















    