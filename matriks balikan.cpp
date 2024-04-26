#include <iostream>
#include <vector>

using namespace std;

// fungsi untuk mencari invers dari sebuah matriks
vector<vector<double>> inverse(vector<vector<double>> A) {
    int n = A.size();
    vector<vector<double>> I(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        I[i][i] = 1;
    }

    for (int i = 0; i < n; i++) {
        double div = A[i][i];
        for (int j = 0; j < n; j++) {
            A[i][j] /= div;
            I[i][j] /= div;
        }

        for (int j = 0; j < n; j++) {
            if (i != j) {
                double factor = A[j][i];
                for (int k = 0; k < n; k++) {
                    A[j][k] -= factor * A[i][k];
                    I[j][k] -= factor * I[i][k];
                }
            }
        }
    }

    return I;
}

// fungsi untuk mencari solusi SPL menggunakan metode invers
vector<double> solveSPL(vector<vector<double>> A, vector<double> b) {
    int n = A.size();

    // mencari invers dari matriks A
    vector<vector<double>> A_inv = inverse(A);

    // menghitung solusi SPL dengan menggunakan invers dari A
    vector<double> x(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[i] += A_inv[i][j] * b[j];
        }
    }

    return x;
}

// Kode Testing
int main() {
    // contoh SPL
    // 6x + 8y = 12
    // 10x + 2y = 40
    vector<vector<double>> A = {{6, 8}, {10, 2}};
    vector<double> b = {12, 40};

    // mencari solusi SPL menggunakan metode invers
    vector<double> x = solveSPL(A, b);

    // pencetakan solusi
    cout << "Solusi SPL:" << endl;
    cout << "x = " << x[0] << endl;
    cout << "y = " << x[1] << endl;

    return 0;
}
