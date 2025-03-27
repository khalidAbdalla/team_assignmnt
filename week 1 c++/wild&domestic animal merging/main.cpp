#include <iostream>

using namespace std;

int main()
{
/*
-- this program is about a user entering both domestic and wild animals differently and merging them together in a new array
*/
     // Accept a group of domestic and wild animals
    int N, X;

    cout << "Enter the number of domestic animals: ";
    cin >> N;
    string domesticAnimals[N];


    for (int i = 0; i < N; i++) {
        cout << "Domestic animal " << (i + 1) << ": ";
        cin >> domesticAnimals[i];
    }


    cout << "\nEnter the number of wild animals: ";
    cin >> X;
    string wildAnimals[X];


    for (int i = 0; i < X; i++) {
        cout << "Wild animal " << (i + 1) << ": ";
        cin >> wildAnimals[i];
    }

/*
creating a merged array for both our wild and domestic animals
*/
    int totalSize= N+X;
    string AllAnimals[totalSize];

    // for copying domestic animals into our merged array
  for (int i=0; i<N; i++)
    {
    AllAnimals[i]=domesticAnimals[i];
}
// for copying wild animals into our merged array
  for (int i=0; i<X; i++)
    {
    AllAnimals[N+i]=wildAnimals[i];
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

