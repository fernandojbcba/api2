//
//  main.cpp
//  api2
//
//  Created by Fernando Benavidez on 18/04/2024.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std; // Permite utilizar los elementos de la biblioteca estándar sin anteponer std::
int main()
{
    /* definimos las variables */
    int rangoMin, rangoMax, intentosMaximos;
    /* mensaje de bienvenida */
    cout << "Bienvenido al Juego de Adivinanza de numero"<< endl;
    /* ingresamos el rango */
    // Solicitamos al usuario que ingrese el rango ninimo
    cout << "Ingrese el rango de numeros para el juego (min): ";
    cin >> rangoMin;
    // Solicitamos al usuario que ingrese el rango máximo
    cout << "Ingrese el rango de numeros para el juego (max): ";
    cin >> rangoMax;
    while (rangoMax < rangoMin){
        cout << "El rango maximo debe ser mayor a rango min "<< endl;
        cout << "Ingrese el rango de numeros para el juego (max): ";
        cin >> rangoMax;
    };
    int diferenciarango = rangoMax  - rangoMin;
    /* ingresamos los intentos: */
    cout << "Ingrese la cantidad de intentos maximos: ";
    cin >> intentosMaximos;
    while (diferenciarango < intentosMaximos){
        cout << "el numero de intentos no puede ser superior a la diferencia de rango :" << diferenciarango << endl;
        cout << "Ingrese la cantidad de intentos maximos: ";;
        cin >> intentosMaximos;
    };

    /* initializar random: */
    srand((unsigned int)time(NULL));

    /* numero random  : el rango para rand es restando el maximo menos el minimo  */
    /* y se establece + rangoMin, para el comienzo del rango.  */
    int numeroSecreto = rand() % (rangoMax - rangoMin + 1) + rangoMin;
    // Creamos un vector para almacenar los intentos realizados por el usuario
    vector<int> intentosRealizados;
    // Inicializamos el número de intentos restantes al máximo
    int intentosRestantes = intentosMaximos;
    int numeroIngresado;
    // Comienza el bucle principal del juego
    while (intentosRestantes > 0)
    {
        // Solicitamos al usuario que ingrese un número
        cout << "Intento " << intentosMaximos - intentosRestantes + 1 << " de " << intentosMaximos << ". Ingrese un numero: "<< endl;
        cin >> numeroIngresado;
        // Validamos si el número ingresado está dentro del rango
        if (numeroIngresado < rangoMin || numeroIngresado > rangoMax)
        {
            cout << "El numero ingresado esta fuera de rango. Ingrese un numero entre " << rangoMin << " y " << rangoMax << endl
                 << endl;
            continue;
        }
        // Validamos si el número ingresado ya fue intentado antes
        if (find(intentosRealizados.begin(), intentosRealizados.end(), numeroIngresado) != intentosRealizados.end())
        {
            cout << "Ya has ingresado ese numero. Intenta con otro." << endl
                 << endl;
            continue;
        }
        // Agregamos el número ingresado al vector de intentos realizados
        intentosRealizados.push_back(numeroIngresado);
        // Ordenamos los números ingresados hasta el momento
        sort(intentosRealizados.begin(), intentosRealizados.end());
        // Comparamos el número ingresado con el número secreto
        if (numeroIngresado == numeroSecreto)
        {
            cout << "¡Felicidades! Has adivinado el numero secreto.\n"
                 << endl
                 << endl;
            break; // Salimos del bucle
        }
        else if (numeroIngresado < numeroSecreto)
        {
            cout << "El numero ingresado es menor que el numero secreto." << endl
                 << endl;
        }
        else
        {
            cout << "El numero ingresado es mayor que el numero secreto." << endl
                 << endl;
        }
        // Actualizamos el número de intentos restantes
        intentosRestantes--;
        cout << "Intentos restantes: " << intentosRestantes << endl;
        // Mostramos los números ingresados hasta el momento
        cout << "Numeros ingresados: ";
        for (int num : intentosRealizados)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    // Mensaje si el usuario se queda sin intentos
    if (intentosRestantes == 0)
    {
        cout << "Te has quedado sin intentos. El numero secreto era: " << numeroSecreto << endl;
    }

    return 0;
}
