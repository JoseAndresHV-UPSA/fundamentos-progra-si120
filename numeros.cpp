#include <iostream>

using namespace std;

// Operaciones auxiliares
int sumaDivisores(int n) {
    int suma = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0)
            suma += i;
    }
    
    return suma;
}

// Número primo: todo número natural mayor que 1 que cumple que sus únicos divisores son el 1 y el propio número. Ejemplos: 2, 3, 5,… Éste es el más grande que se conoce.
bool esPrimo(int n) 
{
    if (n == 0 || n == 1 || n == 4) 
        return false;
    
    for (int i = 2; i < n / 2; i++) 
    {
        if (n % i == 0) 
            return false;
    }
    
    return true;
}

// Número compuesto: todo número natural mayor que 1 que no es primo.
bool esCompuesto(int n)
{
    if (n > 1 && !esPrimo(n))
        return true;
        
    return false;
}

// Número perfecto: todo número natural que es igual a la suma de sus divisores propios, excepto el propio número.
bool esPerfecto(int n) 
{
    int suma = sumaDivisores(n);
    
    return suma == n;
}

// Número abundante: todo número natural que cumple que la suma de sus divisores propios es mayor que el propio número.
bool esAbundante(int n) 
{
    int suma = sumaDivisores(n);
    
    return suma > n;
}

// Número deficiente: todo número natural que cumple que la suma de sus divisores propios es menor que el propio número.
bool esDeficiente(int n) 
{
    int suma = sumaDivisores(n);
    
    return suma < n;
}

// Números amigos: parejas de números que cumplen que la suma de los divisores propios de cada uno de ellos da como resultado el otro número.
bool sonAmigos(int n1, int n2)
{
    int suma1 = sumaDivisores(n1);
    int suma2 = sumaDivisores(n2);
    
    return n1 == suma2 && n2 == suma1;
}

// Número ambicioso: todo número que cumple que la secuencia que se forma al sumar sus divisores propios, después los divisores propios del resultado de esa suma, después los del número obtenido…acaba en un número perfecto.
bool esAmbicioso(int n) {
    int suma = sumaDivisores(n);
    
    return esPerfecto(suma);
}

int main()
{
    cout << "Primo: " << esPrimo(7) << endl;
    cout << "Compuesto: " << esCompuesto(4) << endl;
    cout << "Perfecto: " << esPerfecto(6) << endl;
    cout << "Abundante: " << esAbundante(12) << endl;
    cout << "Deficiente: " << esDeficiente(16) << endl;
    cout << "Amigos: " << sonAmigos(220, 284) << endl;
    cout << "Ambicioso: " << esAmbicioso(25) << endl;
    
    return 0;
}
