#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

using namespace std;

// Operaciones vector
void cargarVector(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }
}

void mostrarVector(int v[], int n)
{
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
        
    cout << endl;
}

// LLenar vector con numeros aleatorios
int aleatorio(int max, int min)
{
    srand(time(NULL));
    return min + rand() % (max + 1 - min);
}

void vectorAleatorio(int v[], int n)
{
    int max = 10, min = 0;
    
    for (int i = 0; i < n; i++)
        v[i] = aleatorio(max, min);
}

// Ordenar vector 
void intercambiar(int& a, int& b)
{
    int aux = b;
    b = a;
    a = aux;
}

void ordenar(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (v[j] > v[j + 1])
                intercambiar(v[j], v[j + 1]);
        }
    }
}

// Mayor numero del vector
int mayorVector(int v[], int n)
{
    int mayor = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > mayor)
            mayor = v[i];
    }
    
    return mayor;
}

// Menor numero del vector
int menorVector(int v[], int n)
{
    int menor = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < menor)
            menor = v[i];
    }
    
    return menor;
}

// Invertir vector
void invertir(int v[], int n)
{
    int j = n - 1;
    for (int i = 0; i < n / 2; i++)
    {
        intercambiar(v[i], v[j]);
        j--;
    }
}

// Verificar si el vector es capicua
bool esCapicua(int v[], int n)
{
    int j = n - 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (v[i] != v[j])
            return false;
            
        j--;
    }
    return true;
}

// Eliminar posicion de un vector
void eliminarPos(int v[], int &n, int p)
{
    for (int i = p; i < n - 1; i++)
        intercambiar(v[i], v[i + 1]);
    
    n--;
}

// Eliminar numero de un vector  
void eliminarNum(int v[], int &n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == num)
        {
            eliminarPos(v, n, i);
            i--;
        }
    }
}

// Verificar si un numero existe en el vector
bool existe(int v[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == num)
        {
            return true;
        }
    }
    
    return false;
}


// Conjuntos: Union v1 U v2 = v3
void unionVectores(int v1[], int n1, int v2[], int n2,
                   int v3[], int &n3)
{
    n3 = n1 + n2;
    for (int i = 0; i < n1; i++) 
    {
        v3[i] = v1[i];
    }
    
    int j = 0;
    for (int i = n1; i < n3; i++)
    {
        v3[i] = v2[j];
        j++;
    }
}

// Conjuntos: Interseccion v1 Y v2 = v3
void interseccionVectores(int v1[], int n1, int v2[], int n2,
                          int v3[], int &n3)
{
    n3 = 0;
    for (int i = 0; i < n1; i++) 
    {
        if (existe(v2, n2, v1[i]))
        {
            v3[n3] = v1[i];
            n3++;            
        }
    }
}

int main()
{
    int v[50], n = 5, p = 2, num = 3;
    cargarVector(v, n);
    //mostrarVector(v, n);
    
    //vectorAleatorio(v, n);
    //mostrarVector(v, n);
    
    ordenar(v, n);
    mostrarVector(v, n);
    
    //cout << mayorVector(v, n) << endl;
    //cout << menorVector(v, n) << endl;
    
    invertir(v, n);
    mostrarVector(v, n);
    
    //cout << esCapicua(v, n);
    
    // eliminarPos(v, n, p);
    // mostrarVector(v, n);
    
    //eliminarNum(v, n, num);
    //mostrarVector(v, n);
    
    int v1[] = { 1, 2, 4, 5 }, n1 = 4;
    int v2[] = { 4, 5, 1 }, n2 = 3;
    int v3[20], n3;
    //unionVectores(v1, n1, v2, n2, v3, n3);
    //mostrarVector(v3, n3);
    
    interseccionVectores(v1, n1, v2, n2, v3, n3);
    mostrarVector(v3, n3);
    
    return 0;
}
