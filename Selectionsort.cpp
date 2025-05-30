#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(0));

    int arr[500000];
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101;
    }

    clock_t start = clock();

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int x = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[x]) {
                x = j;
            }
        }
        if (x != i) {
            swap(arr[i], arr[x]);
        }
    }

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
