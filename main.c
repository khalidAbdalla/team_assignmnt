#include <stdio.h>
#include <stdlib.h>

int main()
{/*
//1. Write a C program that calculates the average of marks got by a student in three subjects ie Physics, Chemistry, Math...assume for each subject, four different tests were conducted; assignment, Course work, mid term and end of term exams

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
*/

    // 2.Write a C program that accepts a group of N domestic animals and a group of X wild animals. Your program should print N + X animals after entering each group

    int N, X;

    // Accept the number of domestic animals
    printf("Enter the number of domestic animals: ");
    scanf("%d", &N);

    // Declare an array to store the names of N domestic animals
    char domesticAnimals[N][50];

    // Accept names of domestic animals
    printf("Enter the names of %d domestic animals:\n", N);
    for (int i = 0; i < N; i++) {
    printf("Domestic animal %d: ", i + 1);
    // Input the name of each domestic animal
    scanf("%s", domesticAnimals[i]);
    }

    // Print all domestic animals after entering
    printf("\nDomestic animals entered:\n");
    for (int i = 0; i < N; i++) {
    // Print each domestic animal
    printf("%s\n", domesticAnimals[i]);
    }

    // Accept the number of wild animals
    printf("\nEnter the number of wild animals: ");
    scanf("%d", &X);

    // Declare an array to store the names of X wild animals
    char wildAnimals[X][50];

    // Accept names of wild animals
    printf("Enter the names of %d wild animals:\n", X);
    for (int i = 0; i < X; i++) {
    printf("Wild animal %d: ", i + 1);
    // Input the name of each wild animal
    scanf("%s", wildAnimals[i]);
    }

    // Print all wild animals after entering
    printf("\nWild animals entered:\n");
    for (int i = 0; i < X; i++) {
    // Print each wild animal
    printf("%s\n", wildAnimals[i]);
    }

    // Print all animals (domestic + wild) after entering both groups
    printf("\nAll animals entered (Domestic + Wild):\n");
    for (int i = 0; i < N; i++) {
    // Print all domestic animals
    printf("%s\n", domesticAnimals[i]);
    }
    for (int i = 0; i < X; i++) {
    // Print all wild animals
    printf("%s\n", wildAnimals[i]);
    }

return 0;
}
