#include <stdio.h>
#include <stdlib.h>

int main()
{
     // Declare variables for marks in each test for each subject
    float physics[4], chemistry[4], math[4];
    float avg_physics, avg_chemistry, avg_math, overall_avg;

    // Input marks for Physics
    printf("Enter marks for Physics (Assignment, Course work, Mid term, End of term): ");
    for (int i = 0; i < 4; i++) {
        scanf("%f", &physics[i]);  // Input marks for each test in Physics
    }

    // Input marks for Chemistry
    printf("Enter marks for Chemistry (Assignment, Course work, Mid term, End of term): ");
    for (int i = 0; i < 4; i++){
    // Input marks for each test in Chemistry
        scanf("%f", &chemistry[i]);
    }

    // Input marks for Math
    printf("Enter marks for Math (Assignment, Course work, Mid term, End of term): ");{
    for (int i = 0; i < 4; i++)
    // Input marks for each test in Math
        scanf("%f", &math[i]);
    }

    // Calculate the average for each subject
    avg_physics = (physics[0] + physics[1] + physics[2] + physics[3]) / 4.0;
    avg_chemistry = (chemistry[0] + chemistry[1] + chemistry[2] + chemistry[3]) / 4.0;
    avg_math = (math[0] + math[1] + math[2] + math[3]) / 4.0;

    // Calculate the overall average for the three subjects
    overall_avg = (avg_physics + avg_chemistry + avg_math) / 3.0;

    // Output the averages
    printf("Average marks in Physics: %.2f\n", avg_physics);
    printf("Average marks in Chemistry: %.2f\n", avg_chemistry);
    printf("Average marks in Math: %.2f\n", avg_math);
    printf("Overall average: %.2f\n", overall_avg);

    return 0;
}
