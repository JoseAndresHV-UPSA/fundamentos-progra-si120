#include <iostream>

using namespace std;

// Serie Fibonacci 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
void fibonacci(int n)
{
    int a = 0, b = 1, c;
    cout << a << ", ";
    
    for(int i = 2; i <= n; i++)
    {
        cout << b << ", ";
        c = a + b;
        a = b;
        b = c;
    }
    
    cout << endl;
}

// Generar n terminos 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, ...
void serie1(int n) 
{
    int a = 1;
    while (true)
    {
        for (int i = 0; i < a; i++)
        {
            cout << a << ", ";
            n--;
            
            if (n <= 0)
            {
                cout << endl;
                return;
            }
        }
        a++;
    }
}

// Generar n terminos 1, 1, 2, 1, 2, 3, 1, 2, 3, 4, ...
void serie2(int n) 
{
    int a = 1;
    while (true)
    {
        for (int i = 1; i <= a; i++)
        {
            cout << i << ", ";
            n--;
            
            if (n <= 0)
            {
                cout << endl;
                return;
            }
        }
        a++;
    }
}

int main()
{
    fibonacci(6);
    serie1(10);
    serie2(10);
    
    return 0;
}
