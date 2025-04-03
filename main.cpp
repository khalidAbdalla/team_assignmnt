#include <iostream>
#define MAX 20
using namespace std;

class FriendStack {
    int top;
    string friends[MAX];

public:
    FriendStack() {
        top = -1;
    }

    // Push a friend's name onto the stack
    void push(string friendName) {
        if (top == MAX - 1) {
                cout << "Cannot add a new friend." << endl;
        } else {
            top += 1;
            friends[top] = friendName;
            cout << friendName << " successfully added " << endl;
        }
    }

    // Pop a friend's name from the stack
    string pop() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return "Stack is empty!";
        } else {
            string top_element = friends[top];
            top -= 1;
            return top_element;
        }
    }

    // Display all friends in the stack
    void displayStack() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "\nFriends in the stack (from top to bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << i + 1 << ". " << friends[i] << endl;
        }
    }

    string peek(){
    if (top==-1){
        cout<<"stack is empty!!";
        return "stack is empty ";
    }
    cout << "Top most friend in the stack : " << friends[top] << endl;
        return friends[top];
    }
};

int main() {
    FriendStack stack;  // an instance of FriendStack
    int choice;
    string data;  // Changed to string since we're dealing with names

    while (1) {
        cout<<"....................................";
        cout << "\nWELCOME TO DIAL MENU" << endl;
        cout<<"....................................\n ";
        cout << "1: push" << endl;
        cout << "2: pop" << endl;
        cout << "3: peek" << endl;
        cout << "4: display" << endl;
        cout << "5: exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
               cout << "Enter friend's name to push: ";
               cin >> data;
    if (data.find_first_of("0123456789><.!£$,") != string::npos) {
        cout << "Error !!!! ....Names should not contain numbers and signs....\n";
    } else {
        stack.push(data);
    }
                break;
            case 2:
                data = stack.pop();
                if (!data.empty()) {
                    cout << "Popped: " << data << endl;
                }
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.displayStack();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Wrong choice!!!!" << endl;
        }
    }
    return 0;
}
