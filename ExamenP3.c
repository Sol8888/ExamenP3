#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LARGO 100

typedef struct {
    int numA;
    char nombre[MAX_LARGO];
    char carrera[MAX_LARGO];
    float N1;
    float N2;
    float N3;
} Estu;

int compararEstu( const void* estu1, const void* estu2) {
    Estu* e1 = (Estu*)estu1;
    Estu* e2 = (Estu*)estu2;
    return e2->numA - e1->numA;
}

float calculoProm(float N1, float N2, float N3) {
    return (N1 + N2+ N3)/3;
}

int main() {

    FILE *archiE, *archiS;
    Estu *estudiantes;
    int numEstu;
    archiE = fopen("alumnos.txt", "r");
    if (archiE == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    fscanf(archiE, "%d", &numEstu);

    estudiantes = (Estu*)malloc(numEstu * sizeof(Estu));
    if (estudiantes == NULL) {
        printf("No se pudo asignar memoria.\n");
        return 1;
    }

    for (int i =0; i < numEstu; i++) {
        fscanf (archiE, "%d;%[^;];%[^;];%f;%f;%f",
        &estudiantes[i]. numA, estudiantes[i]. nombre, estudiantes[i]. carrera,
        &estudiantes[i]. N1, estudiantes[i]. N2, estudiantes[i]. N3);
    }

    fclose(archiE);

    qsort(estudiantes, numEstu, sizeof(Estu), compararEstu);

    archiS = fopen ("estudiantes_en_orden.txt", "w");
    
    if (archiS == NULL) {
        printf ("No se puede abrir el archivo de salida");
        return 1;
    }

    fprintf(archiS, "%d\n", numEstu);

    float sumaProm = 0.00;

    for (int i= 0; i < numEstu; i++) {
        float promedio = calculoProm(estudiantes[i]. N1, estudiantes[i]. N2, estudiantes[i]. N3);
        sumaProm += promedio;
        fprintf (archiS,"%d, %s, %s, %.2f; %.2f; %2f\n",
            estudiantes[i]. numA, estudiantes[i]. nombre, estudiantes[i].carrera, 
            estudiantes[i].N1, estudiantes[i].N2, estudiantes[i].N3, promedio);
    }

    float promTotal = sumaProm / numEstu;
    fprintf (archiS, "Promedio total: %.2f\n", promTotal);

    fclose(archiS);

    
    free(estudiantes);

    printf("El proceso termino.\n");

    return 0;

} 







   
   
     

    
   
    
       
    
    
    

    


  
    



    
    
    
