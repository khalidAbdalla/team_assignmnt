
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X;

    // here we insert  the number of domestic and wild animals
    cout << "Enter the number of domestic animals (N): ";
    cin >> N;
    cout << "Enter the number of wild animals (X): ";
    cin >> X;

    // the Vectors to store the names of domestic and wild animals ,
    // is like a flexible and smart container that will hold the domesticAnimals and wildAnimals for us,
    // It grows or shrinks automatically as you add or remove words, 
    vector<string> domesticAnimals(N);
    vector<string> wildAnimals(X);

    // let's now enter the  domestic animals
    cout << "\nEnter the names of " << N << " domestic animals:\n";
    for (int i = 0; i < N; ++i) {
        cout << "  Domestic animal " << i + 1 << ": ";
        cin >> domesticAnimals[i];
    }

    // the the  wild animals
    cout << "\nEnter the names of " << X << " wild animals:\n";
    for (int i = 0; i < X; ++i) {
        cout << "  Wild animal " << i + 1 << ": ";
        cin >> wildAnimals[i];
    }

    // we now print  all animals (domestic + wild)
    cout << "\nAll " << N + X << " animals:\n";
    for (int i = 0; i < N; ++i) {
        cout << "  Domestic animal " << i + 1 << ": " << domesticAnimals[i] << endl;
    }
    for (int i = 0; i < X; ++i) {
        cout << "  Wild animal " << i + 1 << ": " << wildAnimals[i] << endl;
    }

    return 0;
}
