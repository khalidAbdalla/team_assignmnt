#include <iostream>
#include <string>
using namespace std;

/*
 * code to calculate the average marks for three subjects: Physics, Chemistry, and Math.
 * user inputs marks for assignments, coursework, mid-term exams, and end-term exams by each subject.
 * This code then calculates and outputs the average by each subject and the overall average.
 */

// Structure to hold marks for different assessments
struct SubjectMarks {
    double assignment;
    double courseWork;
    double midTerm;
    double endTerm;
    /*
    - A structure is a user-defined datatype that allow you to group related variable togther
    - a struct is like a container that holds multiple pieces of data togther under one name basically organizes data

    */
};

// Structure to hold marks for all subjects
struct StudentMarks {
    SubjectMarks physics;
    SubjectMarks chemistry;
    SubjectMarks math;
     /*
    - another struct to hold marks for all 3 subjects

    */
};

// Function to input marks for a subject
SubjectMarks inputSubjectMarks(const string& subjectName){
    SubjectMarks marks;
    cout << "\nEnter marks for " << subjectName << ":" << endl;

    cout << "Assignment marks (out of 100): ";
    cin >> marks.assignment;

    cout << "Course work marks (out of 100): ";
    cin >> marks.courseWork;

    cout << "Mid-term exam marks (out of 100): ";
    cin >> marks.midTerm;

    cout << "End-term exam marks (out of 100): ";
    cin >> marks.endTerm;

    return marks;
}

// Function to calculate average for a subject
double calculateSubjectAverage(const SubjectMarks& marks) {
    return (marks.assignment + marks.courseWork + marks.midTerm + marks.endTerm) / 4.0;
}

int main() {
    StudentMarks student;

    cout << "Enter student marks for each subject:" << endl;

    // Input marks for each subject
    student.physics = inputSubjectMarks("Physics");
    student.chemistry = inputSubjectMarks("Chemistry");
    student.math = inputSubjectMarks("Mathematics");

    // Calculate averages for each subject
    double physicsAvg = calculateSubjectAverage(student.physics);
    double chemistryAvg = calculateSubjectAverage(student.chemistry);
    double mathAvg = calculateSubjectAverage(student.math);

    // Calculate overall average
    double overallAverage = (physicsAvg + chemistryAvg + mathAvg) / 3.0;

    // Display results
    cout << "\nResults:" << endl;
    cout << "Physics Average: " << physicsAvg << endl;
    cout << "Chemistry Average: " << chemistryAvg << endl;
    cout << "Mathematics Average: " << mathAvg << endl;
    cout << "Overall Average: " << overallAverage << endl;

    return 0;
}
