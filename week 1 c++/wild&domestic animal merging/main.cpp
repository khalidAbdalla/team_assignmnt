#include <iostream>

using namespace std;

int main()
{
     // Accept a group of domestic and wild animals
    int N, X;

    cout << "Enter the number of domestic animals: ";
    cin >> N;
    string domesticAnimals[N];


    for (int i = 0; i < N; i++) {
        cout << "Domestic animal " << (i + 1) << ": ";
        cin >> domesticAnimals[i];
    }

    cout << "\nDomestic animals entered:\n";
    for (int i = 0; i < N; i++) {
        cout << domesticAnimals[i] << endl;
    }

    cout << "\nEnter the number of wild animals: ";
    cin >> X;
    string wildAnimals[X];


    for (int i = 0; i < X; i++) {
        cout << "Wild animal " << (i + 1) << ": ";
        cin >> wildAnimals[i];
    }

    cout << "\nWild animals entered:\n";
    for (int i = 0; i < X; i++) {
        cout << wildAnimals[i] << endl;
    }

    cout << "\nAll animals entered (Domestic + Wild):\n";
    for (int i = 0; i < N; i++) {
        cout << domesticAnimals[i] << endl;
    }
    for (int i = 0; i < X; i++) {
        cout << wildAnimals[i] << endl;
    }

    return 0;
}

