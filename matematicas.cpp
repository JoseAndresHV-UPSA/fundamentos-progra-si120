#include <iostream>
#include <math.h>

using namespace std;

// Calcular area de un cuadrado
double areaCuadrado(double l)
{
    double a = l * l;
    return a;
}

// Calcular area de un triangulo
double areaTriangulo(double b, double h)
{
    double a = b * h / 2;
    return a;
}

// Calcular area de un triangulo
double areaCirculo(double r)
{
    double a = M_PI * r * r;
    return a;
}

// Resolver ecuacion del tipo Ax + B = 0
double ecuacionLineal(int a, int b) 
{
    double x = -b / a;
    return x;
}

// Resolver sistema ecuaciones del tipo Ax + By = C 
//                                      Dx + Ey = F

void sistemaEc2x2(int a, int b, int c,
                  int d, int e, int f) 
{
    double delta = a * e - b * d;
    
    if (delta != 0) 
    {
        double dx = c * e - b * f;
        double dy = a * f - c * d;
        double x = dx / delta;
        double y = dy / delta;
        
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
    else
    {
        cout << "Sin solucion" << endl;
    }
}

// Resolver ecuacion del tipo Ax2 + Bx + C = 0
void ecuacionCuadratica(int a, int b, int c) 
{
    if (a == 0) 
        cout << "x = " << ecuacionLineal(b, c);
        
    else 
    {
        double disc = b * b - 4 * a * c;
        if (disc < 0) 
        {
            cout << "Solucion imaginaria" << endl;
        }
        else 
        {
            double x1 = (- b + sqrt(disc)) / (2 * a);
            double x2 = (- b - sqrt(disc)) / (2 * a);
            
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }
}

int main()
{
    cout << "Area Cuadrado: " << areaCuadrado(4) << endl;
    cout << "Area Rectangulo: " << areaTriangulo(4, 3) << endl;
    cout << "Area Circulo: " << areaCirculo(4) << endl;
    cout << "Ecuacion Lineal: " << ecuacionLineal(2, 4) << endl;
    sistemaEc2x2(1, 1, 1, 2, 1, 0);
    ecuacionCuadratica(2, 9, 10);
    
    return 0;
}
