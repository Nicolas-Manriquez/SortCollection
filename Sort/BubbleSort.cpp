#include <iostream>
#include <chrono>

using namespace std;

/* Function to sort array using insertion sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    const int n = 8;
    int arr[n];  // Declaración que faltaba

    cout << "Ingresa 8 numeros:\n";

    for (int i = 0; i < n; ++i) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arr[i];
    }

    auto inicio = chrono::steady_clock::now();

    insertionSort(arr, n);

    auto fin = chrono::steady_clock::now();

    auto tiempo = chrono::duration_cast<chrono::nanoseconds>(
        fin - inicio
    ).count();

    cout << "\nArreglo ordenado: ";
    printArray(arr, n);

    cout << "Tiempo del sort: "
         << tiempo
         << " nanosegundos\n";

    return 0;
}
