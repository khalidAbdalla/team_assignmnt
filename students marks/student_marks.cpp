#include <iostream>
#include <string>
using namespace std;

struct SubjectMarks {
    double assignment, coursework, midTerm, endTerm;
};

// Function to get a valid mark
double getValidMark(const string& prompt) {
    double mark;
    while (true) {
        cout << prompt;
        cin >> mark;

        if (cin.fail() || mark < 0 || mark > 100) {
            cout << "Invalid input! Enter a number between 0 and 100.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            return mark;
        }
    }
}

// Function to input marks for a subject
void getMarks(SubjectMarks &marks, const string& subjectName) {
    cout << "\nEnter marks for " << subjectName << ":\n";
    marks.assignment = getValidMark("Assignment (out of 100): ");
    marks.coursework = getValidMark("Coursework (out of 100): ");
    marks.midTerm = getValidMark("Mid-term Exam (out of 100): ");
    marks.endTerm = getValidMark("End-term Exam (out of 100): ");
}

// Function to calculate average for a subject
double calculateAverage(const SubjectMarks& marks) {
    return (marks.assignment + marks.coursework + marks.midTerm + marks.endTerm) / 4.0;
}

int main() {
    const int numSubjects = 3;
    string subjects[numSubjects] = {"Physics", "Chemistry", "Mathematics"};
    SubjectMarks marks[numSubjects];

    // Get marks for each subject
    for (int i = 0; i < numSubjects; i++) {
        getMarks(marks[i], subjects[i]);
    }

    // Display results
    cout << "\nResults:\n";
    double totalAverage = 0;
    for (int i = 0; i < numSubjects; i++) {
        double avg = calculateAverage(marks[i]);
        cout << subjects[i] << " Average: " << avg << endl;
        totalAverage += avg;
    }

    cout << "Overall Average: " << (totalAverage / numSubjects) << endl;

    return 0;
}
