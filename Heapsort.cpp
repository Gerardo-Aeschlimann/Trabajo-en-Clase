#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

void heapify(int arr[], int n, int i) {
    int raiz = i;           
    int izq = 2 * i + 1;      
    int der = 2 * i + 2;     

    if (izq < n && arr[izq] > arr[raiz])
        raiz = izq;

    if (der < n && arr[der] > arr[raiz])
        raiz = der;

    if (raiz != i) {
        swap(arr[i], arr[raiz]);
        heapify(arr, n, raiz);
    }
}

void heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heap_sort(int arr[], int n) {
    heap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);    
        heapify(arr, i, 0);     
    }
}

int main() {
    srand(time(0));

    int arr [500000]; //Cambiar n
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int i=0;i<n;i++){
        arr[i]=rand()% 101;
    }

    
    clock_t start = clock();
    heap_sort(arr, n);
/*

    cout << "Arreglo original:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    

    cout << "Arreglo ordenado con Heap Sort:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
*/

    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC; 
    cout << "\nN es igual a: "<<n<<"\nTiempo de ejecucion: " << time_taken << " segundos" << endl;
    return 0;
}
