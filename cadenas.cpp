#include <iostream>
#include <string.h>

using namespace std;

const int N = 100;

// Contar la cantidad de palabras en una cadena
int cantPalabras(char cad[])
{
    if (strlen(cad) == 0) 
        return 0;
        
    int count = 1;
    for (int i = 0; i < strlen(cad); i++)
    {
        if (cad[i] == ' ')
            count++;
    }
    return count;
}

// Intercambiar valores
void intercambiar(char& a, char& b)
{
    char aux = a;
    a = b;
    b = aux;
}

// Eliminar posicion de la cadena
void eliminarPos(char cad[], int pos)
{
    int n = strlen(cad);
    
    if (pos < 0 || pos >= n)
        return;
    
    for (int i = pos; i < n - 1; i++)
    {   
        cad[i] = cad[i + 1];
    }
    
    cad[n - 1] = '\0';
}

// Invertir cadena
void invertir(char cad[])
{
    int n = strlen(cad);
    int j = n - 1;
    for (int i = 0; i < n / 2; i++)
    {
        intercambiar(cad[i], cad[j]);
        j--;
    }
}

// Eliminar espacios
void eliminarEspacios(char cad[])
{
    int n = strlen(cad);
    for (int i = 0; i < n; i++)
    {
        if (cad[i] == ' ') 
        {
            eliminarPos(cad, i);
            i--;            
        }
    }
}

// Verificar si es capicua
bool esCapicua(char cad[])
{
    int n = strlen(cad);
    int j = n - 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (cad[i] != cad[j]) 
            return false;          
        
        j--;
    }
    return true;
}

// Convertir a minuscula
void minuscula(char& c)
{
    c = tolower(c);
}

void cadMinuscula(char cad[])
{
    int n = strlen(cad);
    for (int i = 0; i < n; i++)
    {
        minuscula(cad[i]);
    }
}

// Convertir a mayuscula
void mayuscula(char& c)
{
    c = toupper(c);
}

void cadMayuscula(char cad[])
{
    int n = strlen(cad);
    for (int i = 0; i < n; i++)
    {
        mayuscula(cad[i]);
    }
}

// Eliminar palabra
void eliminarPalabra(char cad[], char pal[])
{
    char* p = strstr(cad, pal); // Primer ocurrencia de pal en cad
    
    if (!p) { 
        cout << "Palabra " << pal << " no encontrada" << endl;
        return;
    }
    
    int nCad = strlen(cad);
    int nPal = strlen(pal);
    int nP = strlen(p);
    
    char resto[N]; // Cadena despues de pal
    int nResto = nP - nPal;
    
    int j = 0;
    for (int i = nP - nResto; i < nP; i++)
    {
        // Guarda todo lo encontrado despues de pal
        resto[j] = p[i];
        j++;
    }
    
    // Reemplaza la ocurrencia (puntero) por el resto encontrado
    strcpy(p, resto);
    
    // Encuentra la nueva longitud y la corta
    int n = nCad - nPal;
    cad[n] = '\0';
}

int main()
{
    char cad[N];  
    //cin.get(cad, N); // Leer con espacios
    //cin.ignore(); // Para poder volver a leer
    
    //cout << cad << endl;
    //cout << strlen(cad) << endl; // Cantidad de caracteres usados
    
    //cout << cantPalabras(cad) << endl;
    
    //eliminarPos(cad, 3);
    //cout << cad << endl;
    
    // invertir(cad);
    // cout << cad << endl;
    
    // eliminarEspacios(cad);
    // cout << cad << endl;
    
    //cout << esCapicua(cad) << endl;
    
    // cadMinuscula(cad);
    // cout << cad << endl;
    // cadMayuscula(cad);
    // cout << cad << endl;
    
    char s1[] = "Hola como estas";
    char s2[] = "como";
    eliminarPalabra(s1, s2);
    cout << s1 << endl;
    
    return 0;
}
