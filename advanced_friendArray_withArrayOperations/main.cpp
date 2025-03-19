#include <iostream>
#include <string>
using namespace std;

// Tirada ugu badan ee saaxiibada ee array-ga iyo stack-ga
const int MAX_SIZE = 100;

//  Stack class `si loogu kaydiyo magacyada saaxiibada
class FriendStack {
private:
    string stack[MAX_SIZE];
    int top;

public:
    FriendStack() {
        top = -1;  // Bilowga stack oo faaruq ah
    }

    // Ku darida magaca saaxiibka stack-ga (Push)
    void push(string name) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack is full! Cannot add a new friend." << endl;
            return;
        }
        stack[++top] = name;
        cout << name << " has been successfully added to the stack!" << endl;
    }

    // Ka saarida magaca saaxiibka stack-ga (Pop)
    void pop() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << stack[top] << " has been successfully removed from the stack!" << endl;
        top--;
    }

    // Fiirinta saaxiibka ugu sareeya stack-ga (Peek)
    void peek() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "The top friend in the stack is: " << stack[top] << endl;
    }

    // Muuqaalka dhamaan saaxiibada ku jira stack-ga
    void displayStack() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "\nFriends in the stack (from top to bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << i + 1 << ". " << stack[i] << endl;
        }
    }
};

// Muuqaalka liiska saaxiibada
void displayFriends(string friends[], int size) {
    cout << "\nYour friends list:" << endl;
    for(int i = 0; i < size; i++) {
        cout << i + 1 << ". " << friends[i] << endl;
    }
}

// Ku darida saaxiib cusub liiska
int insertFriend(string friends[], int size, int maxSize) {
    if(size >= maxSize) {
        cout << "Sorry, the friends list is full!" << endl;
        return size;
    }

    cout << "Enter the name of the new friend: ";
    cin >> friends[size];
    cout << friends[size] << " has been successfully added to your friends list!" << endl;
    return size + 1;
}

// Ka saarida saaxiib liiska
int deleteFriend(string friends[], int size) {
    if(size == 0) {
        cout << "The friends list is empty!" << endl;
        return size;
    }

    string nameToDelete;
    cout << "Enter the name of the friend you want to remove: ";
    cin >> nameToDelete;

    int pos = -1;
    for(int i = 0; i < size; i++) {
        if(friends[i] == nameToDelete) {
            pos = i;
            break;
        }
    }

    if(pos == -1) {
        cout << nameToDelete << " was not found in your friends list!" << endl;
        return size;
    }

    for(int i = pos; i < size - 1; i++) {
        friends[i] = friends[i + 1];
    }

    cout << nameToDelete << " has been successfully removed from the friends list!" << endl;
    return size - 1;
}

// Raadinta saaxiib ee liiska
void searchFriend(string friends[], int size) {
    if(size == 0) {
        cout << "The friends list is empty!" << endl;
        return;
    }

    string nameToSearch;
    cout << "Enter the name of the friend you are looking for: ";
    cin >> nameToSearch;

    bool found = false;
    for(int i = 0; i < size; i++) {
        if(friends[i] == nameToSearch) {
            cout << nameToSearch << " found at position " << i + 1 << endl;
            found = true;
            break;
        }
    }

    if(!found) {
        cout << nameToSearch << " not found in your friends list!" << endl;
    }
}

int main() {
    string friends[MAX_SIZE];
    int size = 0;
    char choice;
    FriendStack stack;  // Abuurista stack cusub

    cout << "Let's create your friends list!" << endl;
    cout << "How many friends do you want to add? ";
    cin >> size;

    if(size > MAX_SIZE) {
        cout << "Sorry, the maximum limit is " << MAX_SIZE << " friends." << endl;
        size = MAX_SIZE;
    }

    cout << "Enter the names of your " << size << " friends:" << endl;
    for(int i = 0; i < size; i++) {
        cout << "Friend " << i + 1 << ": ";
        cin >> friends[i];
    }

    do {
        cout << "\n=== Friends Management System ===" << endl;
        cout << "1. Show all friends" << endl;
        cout << "2. Add a new friend" << endl;
        cout << "3. Remove a friend" << endl;
        cout << "4. Search for a friend" << endl;
        cout << "5. Add a friend to the stack" << endl;
        cout << "6. Remove a friend from the stack" << endl;
        cout << "7. View the top friend in the stack" << endl;
        cout << "8. Show stack" << endl;
        cout << "9. Exit" << endl;
        cout << "Choose (1-9): ";
        cin >> choice;

        switch(choice) {
            case '1': displayFriends(friends, size); break;
            case '2': size = insertFriend(friends, size, MAX_SIZE); break;
            case '3': size = deleteFriend(friends, size); break;
            case '4': searchFriend(friends, size); break;
            case '5': { string name; cout << "Enter the name of the friend to add to the stack: "; cin >> name; stack.push(name); break; }
            case '6': stack.pop(); break;
            case '7': stack.peek(); break;
            case '8': stack.displayStack(); break;
            case '9': cout << "Goodbye!" << endl; break;
            default: cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != '9');

    return 0;
}
