#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Combina dos subarreglos ordenados
void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Ordena el vector usando merge sort
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    int n;

    cout << "¿Cuantos numeros deseas ingresar? ";
    cin >> n;

    if (n <= 0) {
        cout << "La cantidad debe ser mayor que cero.\n";
        return 1;
    }

    vector<int> arr;

    cout << "Ingresa " << n << " numeros:\n";

    for (int i = 0; i < n; i++) {
        int numero;

        cout << "Numero " << i + 1 << ": ";
        cin >> numero;

        arr.push_back(numero);
    }

    auto inicio = chrono::steady_clock::now();

    mergeSort(arr, 0, arr.size() - 1);

    auto fin = chrono::steady_clock::now();

    double tiempoMicrosegundos =
        chrono::duration<double, micro>(
            fin - inicio
        ).count();

    cout << "\nArreglo ordenado: ";

    for (int numero : arr)
        cout << numero << " ";

    cout << "\n\nTiempo del merge sort: "
         << tiempoMicrosegundos
         << " microsegundos\n";

    return 0;
}
