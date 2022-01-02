#include <iostream>
#include <limits.h>

using namespace std;

// Obtener el mayor de los digitos
int mayorDigito(int n) 
{
    int mayor = INT_MIN;
    while (n != 0) 
    {
        int dig = n % 10;
        
        if (dig > mayor)
            mayor = dig;
        
        n /= 10;
    }
    return mayor;
}

// Obtener el menor de los digitos
int menorDigito(int n) 
{
    int menor = INT_MAX;
    while (n != 0) 
    {
        int dig = n % 10;
        
        if (dig < menor)
            menor = dig;
        
        n /= 10;
    }
    return menor;
}

// Obtener la suma de los digitos
int sumaDigitos(int n) 
{
    int suma = 0;
    while (n != 0) 
    {
        int dig = n % 10;
        suma += dig;
        
        n /= 10;
    }
    return suma;
}

// Obtener la cantidad de digitos
int cantDigitos(int n) 
{
    if (n == 0 )
        return 1;
        
    int cont = 0;
    while (n != 0) 
    {
        cont++;
        n /= 10;
    }
    return cont;
}

// Eliminar digito 
int eliminarDigito(int n, int d) 
{
    int result = 0;
    int p = 1;
    
    while (n != 0) 
    {
        int dig = n % 10;
        
        if (dig != d) 
        {
            result += dig * p;
            p *= 10;
        }
        
        n /= 10;
    }
    
    return result;
}

// Ordenar digitos ascendentemente
int ordenarDigitosAsc(int n) {
    int result = 0;
    
    for (int dig = 0; dig <= 9; dig++)
    {
        int aux = n;
        while (aux != 0) 
        {
            if (aux % 10 == dig) 
                result = result * 10 + dig;
                
            aux /= 10;
        }
    }
    return result;
}

// Ordenar digitos descendentemente
int ordenarDigitosDesc(int n) {
    int result = 0;
    
    for (int dig = 9; dig >= 0; dig--)
    {
        int aux = n;
        while (aux != 0) 
        {
            if (aux % 10 == dig) 
                result = result * 10 + dig;
                
            aux /= 10;
        }
    }
    return result;
}

int main()
{
    cout << "Mayor digito: " << mayorDigito(123) << endl;
    cout << "Menor digito: " << menorDigito(123) << endl;
    cout << "Suma digitos: " << sumaDigitos(123) << endl;
    cout << "Cantidad digitos: " << cantDigitos(123) << endl;
    cout << "Eliminar digitos: " << eliminarDigito(123, 2) << endl;
    cout << "Ordenar digitos ascendentemente: " << ordenarDigitosAsc(1332) << endl;
    cout << "Ordenar digitos descendentemente: " << ordenarDigitosDesc(1332) << endl;
  
    return 0;
}
