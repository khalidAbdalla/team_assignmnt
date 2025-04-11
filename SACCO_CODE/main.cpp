#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <windows.h> // Windows Console API
#include <conio.h>   // For _getch()

using namespace std;

// ==================== UTILITY FUNCTIONS ====================
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen() {
    system("cls");
}

void waitForKey() {
    setColor(8); // Gray
    cout << "\nPress any key to continue...";
    _getch();
    cout << "\r" << string(30, ' ') << "\r"; // Clear the line
}

// ==================== CORE CLASSES ====================
string generatePassword() {
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    string password;
    srand(time(0));

    for (int i = 0; i < 8; ++i) {
        password += chars[rand() % chars.length()];
    }
    return password;
}

class User {
private:
    string firstName;
    string lastName;
    string phoneNumber;
    string email;
    string password;

public:
    User(string firstName, string lastName, string phoneNumber, string email, string password)
        : firstName(firstName), lastName(lastName), phoneNumber(phoneNumber), email(email), password(password) {}

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }
    string getPassword() const { return password; }
    void setPassword(const string& newPassword) { password = newPassword; }
};

class Account {
private:
    double balance = 0.0;
    vector<string> transactions;

public:
    void deposit(double amount) {
        if (amount <= 0) throw invalid_argument("Amount must be positive");
        balance += amount;
        transactions.push_back("Deposited: $" + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0) throw invalid_argument("Amount must be positive");
        if (balance < amount) throw runtime_error("Insufficient funds");
        balance -= amount;
        transactions.push_back("Withdrew: $" + to_string(amount));
    }

    double getBalance() const { return balance; }
    const vector<string>& getTransactions() const { return transactions; }
};

class AuthManager {
private:
    vector<User> users;
    User* currentUser = nullptr;
    Account currentAccount;

public:
    bool signUp(const string& firstName, const string& lastName,
                const string& phoneNumber, const string& email) {
        for (const auto& user : users) {
            if (user.getPhoneNumber() == phoneNumber) return false;
        }
        string tempPassword = generatePassword();
        users.emplace_back(firstName, lastName, phoneNumber, email, tempPassword);
        return true;
    }

    bool signIn(const string& phoneNumber, const string& password) {
        for (auto& user : users) {
            if (user.getPhoneNumber() == phoneNumber && user.getPassword() == password) {
                currentUser = &user;
                return true;
            }
        }
        return false;
    }

    bool isAuthenticated() const { return currentUser != nullptr; }
    User* getCurrentUser() const { return currentUser; }
    Account& getAccount() { return currentAccount; }

    void changePassword(const string& newPassword) {
        if (!currentUser) throw runtime_error("No user logged in");
        if (newPassword.length() < 6) throw invalid_argument("Password too short");
        currentUser->setPassword(newPassword);
    }
};

// ==================== UI CLASSES ====================
class SACCO_UI {
private:
    AuthManager auth;
    int attemptsLeft = 3;

    string getInput(const string& prompt) {
        cout << prompt;
        string input;
        getline(cin, input);
        return input;
    }

    double getAmountInput() {
        while (true) {
            try {
                string input = getInput("Enter amount: $");
                double amount = stod(input);
                if (amount <= 0) throw invalid_argument("Amount must be positive");
                return amount;
            } catch (...) {
                setColor(12);
                cout << "Invalid amount! Please enter a positive number.\n";
                setColor(15);
            }
        }
    }

    void showHeader(const string& title) {
        clearScreen();
        setColor(11); // Cyan
        cout << "=== " << title << " ===\n\n";
        setColor(15); // White
    }

    void showError(const string& message) {
        setColor(12); // Red
        cout << "Error: " << message << "\n";
        setColor(15);
        waitForKey();
    }

    void showSuccess(const string& message) {
        setColor(10); // Green
        cout << message << "\n";
        setColor(15);
        waitForKey();
    }

    void signUp() {
        showHeader("SACCO Member Registration");
        string firstName = getInput("First Name: ");
        string lastName = getInput("Last Name: ");
        string phone = getInput("Phone Number: ");
        string email = getInput("Email: ");

        if (auth.signUp(firstName, lastName, phone, email)) {
            string tempPass = generatePassword();
            auth.signIn(phone, tempPass);
            auth.changePassword(tempPass); // Force password change

            showHeader("Registration Complete");
            setColor(14); // Yellow
            cout << "Your temporary password: " << tempPass << "\n";
            setColor(15);
            cout << "You must change this after login.\n";
            waitForKey();
        } else {
            showError("Phone number already registered!");
        }
    }

    void signIn() {
        showHeader("Member Login");
        string phone = getInput("Phone Number: ");
        string password = getInput("Password: ");

        if (auth.signIn(phone, password)) {
            showSuccess("Login successful! Welcome " + auth.getCurrentUser()->getFirstName() + "!");
        } else {
            attemptsLeft--;
            showError("Invalid credentials. Attempts left: " + to_string(attemptsLeft));
        }
    }

    void changePassword() {
        showHeader("Change Password");
        string newPass = getInput("New Password (min 6 chars): ");

        try {
            auth.changePassword(newPass);
            showSuccess("Password changed successfully!");
        } catch (const exception& e) {
            showError(e.what());
        }
    }

    void deposit() {
        showHeader("Deposit Funds");
        double amount = getAmountInput();

        try {
            auth.getAccount().deposit(amount);
            showSuccess("$" + to_string(amount) + " deposited successfully!");
        } catch (const exception& e) {
            showError(e.what());
        }
    }

    void withdraw() {
        showHeader("Withdraw Funds");
        double amount = getAmountInput();

        try {
            auth.getAccount().withdraw(amount);
            showSuccess("$" + to_string(amount) + " withdrawn successfully!");
        } catch (const exception& e) {
            showError(e.what());
        }
    }

    void viewStatement() {
        showHeader("Account Statement");
        Account& acc = auth.getAccount();

        setColor(14); // Yellow
        cout << "Current Balance: $" << acc.getBalance() << "\n\n";
        setColor(15);

        cout << "Transaction History:\n";
        for (const auto& t : acc.getTransactions()) {
            cout << " • " << t << "\n";
        }
        waitForKey();
    }

    void mainMenu() {
        while (auth.isAuthenticated()) {
            showHeader("SACCO Main Menu");
            User* user = auth.getCurrentUser();

            setColor(11);
            cout << "Welcome, " << user->getFirstName() << " " << user->getLastName() << "!\n";
            setColor(15);

            cout << "\n1. Deposit\n2. Withdraw\n3. View Statement\n4. Change Password\n5. Logout\n\nChoice: ";

            char choice = _getch();
            switch (choice) {
                case '1': deposit(); break;
                case '2': withdraw(); break;
                case '3': viewStatement(); break;
                case '4': changePassword(); break;
                case '5': return; // Logout
                default: showError("Invalid choice!");
            }
        }
    }

public:
    void run() {
        while (attemptsLeft > 0) {
            showHeader("Farmers SACCO System");
            cout << "1. Register\n2. Login\n3. Exit\n\nChoice: ";

            char choice = _getch();
            switch (choice) {
                case '1': signUp(); break;
                case '2':
                    signIn();
                    if (auth.isAuthenticated()) {
                        mainMenu();
                        attemptsLeft = 3; // Reset attempts after logout
                    }
                    break;
                case '3': return;
                default: showError("Invalid choice!");
            }
        }
        showError("Too many failed attempts. System locked.");
    }
};

// ==================== MAIN ====================
int main() {
    // Set console title
    SetConsoleTitle(TEXT("Farmers SACCO System"));

    // Run the application
    SACCO_UI app;
    app.run();

    return 0;
}
