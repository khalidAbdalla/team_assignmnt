#include <iostream>
using namespace std;

int main()
{
    /*
    -- This program allows the user to enter domestic and wild animals separately
    -- and then combines them into a single merged list.
    */

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
    -- Creating a merged array for both wild and domestic animals
    */
    int totalSize = N + X;
    string AllAnimals[totalSize];

    // Copy domestic animals
    for (int i = 0; i < N; i++) {
        AllAnimals[i] = domesticAnimals[i];
    }

    // Copy wild animals
    for (int i = 0; i < X; i++) {
        AllAnimals[N + i] = wildAnimals[i];
    }

    /*
    -- Displaying the merged array
    */
    cout << "\nAll animals entered (Domestic + Wild):\n";
    cout << "-------------------------------------\n";

    for (int i = 0; i < totalSize; i++) {
        cout << i + 1 << ". " << AllAnimals[i] << endl;
    }

    cout << "\nThank you for using the animal list manager!\n";

    return 0;
}
