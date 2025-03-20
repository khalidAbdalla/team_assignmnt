
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X;

    // Input the number of domestic and wild animals
    cout << "Enter the number of domestic animals (N): ";
    cin >> N;
    cout << "Enter the number of wild animals (X): ";
    cin >> X;

    // Vectors to store the names of domestic and wild animals
    vector<string> domesticAnimals(N);
    vector<string> wildAnimals(X);

    // Input domestic animals
    cout << "\nEnter the names of " << N << " domestic animals:\n";
    for (int i = 0; i < N; ++i) {
        cout << "  Domestic animal " << i + 1 << ": ";
        cin >> domesticAnimals[i];
    }

    // Input wild animals
    cout << "\nEnter the names of " << X << " wild animals:\n";
    for (int i = 0; i < X; ++i) {
        cout << "  Wild animal " << i + 1 << ": ";
        cin >> wildAnimals[i];
    }

    // Print all animals (domestic + wild)
    cout << "\nAll " << N + X << " animals:\n";
    for (int i = 0; i < N; ++i) {
        cout << "  Domestic animal " << i + 1 << ": " << domesticAnimals[i] << endl;
    }
    for (int i = 0; i < X; ++i) {
        cout << "  Wild animal " << i + 1 << ": " << wildAnimals[i] << endl;
    }

    return 0;
}
