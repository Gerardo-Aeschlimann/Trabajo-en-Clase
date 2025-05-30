#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

int partir(int arr[], int izq, int der) {
    int centro = izq + (der - izq) / 2;
    swap(arr[centro], arr[der]); 

    int pivote = arr[der];
    int i = izq - 1;

    for (int j = izq; j <= der - 1; j++) {
        if (arr[j] < pivote) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[der]);
    return i + 1;
}

void quick_sort(int arr[], int izq, int der) {
    if (izq < der) {
        int pivote = partir(arr, izq, der); 
        quick_sort(arr, izq, pivote - 1);  
        quick_sort(arr, pivote + 1, der);    
    }
}

int main() {
    srand(time(0));

    int arr[500000];
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101; 
    }

    clock_t start = clock();

    quick_sort(arr, 0, n - 1);

    /*
    cout << "\nResultado:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "-";
    }
    */

    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nN es igual a: "<<n<<"\nTiempo de ejecucion: " << time_taken << " segundos" << endl;

    return 0;
}
