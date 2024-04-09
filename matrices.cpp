#include <iostream>
#include <iomanip>
#include "matrices.h"

using namespace std;

void llamaCiclo()
{
    float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    char opcion;
    bool repetir = true;

    float promedio_facultad_1;
    float promedio_facultad_2;
    float promedio_facultad_3;

    char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA] = {"Carlos","Luis","Maria","Pedro","Juan"};
    do
    {
        system("cls");
        promedio_facultad_1=0;
        promedio_facultad_2=0;
        promedio_facultad_3=0;
        cout << "*** Comparativo de Facultades ***" << endl << endl;
        llenarMatriz(matriz_facultad_1);
        promedio_facultad_1 = imprimirMatriz(matriz_facultad_1, alumnos, "Facultad de Ingenieria");
        llenarMatriz(matriz_facultad_2);
        promedio_facultad_2 = imprimirMatriz(matriz_facultad_2, alumnos, "Facultad de Arquitectura");
        llenarMatriz(matriz_facultad_3);
        promedio_facultad_3 = imprimirMatriz(matriz_facultad_3, alumnos, "Facultad de Administracion");
        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3)
        {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Ingenieria" << " Promedio: " << promedio_facultad_1 << endl;
        } else
        if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3)
        {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Arquitectura" << " Promedio: " << promedio_facultad_2 << endl;
        } else
        if (promedio_facultad_3 > promedio_facultad_2 && promedio_facultad_3 > promedio_facultad_1)
        {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Administracion" << " Promedio: " << promedio_facultad_3 << endl;
        } else
        {
            cout << " Algunas facultades tienen el mismo promedio " << endl << endl;
        }
        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n')
        {
            repetir=false;
        }
    } while (repetir);
}

int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1])
{
    int y, x;
    for(int y = 0; y < NUMERO_ALUMNOS; y++) {
        for (int x = 0; x < NUMERO_NOTAS; x++) {
            matriz[y][x] = busquedaAleatorios(MIN_CALIFICACION, MAX_CALIFICACION);
        }
    }
}

void imprimirMatrizLinea() {
    cout << "--------------------------------------------------" << endl;
}

float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad)
{
    cout << endl << "Facultad: " << nombreFacultad << endl;
    imprimirMatrizLinea();
    cout << "Alumno" << setw(10) << "Nota1" << setw(10) << "Nota2" << setw(10) << "Nota3" << setw(10) << "Nota4" << setw(10) << "Promedio" << endl;
    imprimirMatrizLinea();
    float promedioGeneral = 0;
    for (int y = 0; y < NUMERO_ALUMNOS; y++) {
        float promedioAlumno = 0;
        cout << setw(7) << alumnos[y];
        for (int x = 0; x < NUMERO_NOTAS; x++) {
            cout << setw(10) << matriz[y][x];
            promedioAlumno += matriz[y][x];
        }
        promedioAlumno /= NUMERO_NOTAS;
        matriz[y][NUMERO_NOTAS] = promedioAlumno;
        promedioGeneral += promedioAlumno;
        cout << setw(10) << matriz[y][NUMERO_NOTAS] << endl;
    }
    imprimirMatrizLinea();
    promedioGeneral /= NUMERO_ALUMNOS;
    cout << "Promedio general: " << promedioGeneral << endl;
    return promedioGeneral;
}
