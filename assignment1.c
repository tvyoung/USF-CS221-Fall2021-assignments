/*
Assignment 1
Vicki Young
student ID: 20591845
2021.09.04
CS 221-02
*/

#include <stdio.h>

int main() 
{

    //1. Under what conditions will this code print “water” only?
    printf("Question 1: the following code will print \"water\" only when T >= 32 and T < 212\n");
    
    int T = 32;

    printf("T is equal to %d\n", T);
    if (T < 32) {
        printf("ice\n");
    } else if (T < 212) {
        printf("water\n");
    } else {
        printf("steam\n");
    }


    //2. Accept a month in digit from the user. Display the month in words. If number is not between 1 and 12 display message “Invalid Month”. Must use switch.
    int month;
    printf("\nQuestion 2: Enter the number of a month: ");
    scanf("%d", &month);
    
    switch (month) {
        case 1: 
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3: 
            printf("March");
            break;
        case 4: 
            printf("April");
            break;
        case 5: 
            printf("May");
            break;
        case 6: 
            printf("June");
            break;
        case 7: 
            printf("July");
            break;
        case 8: 
            printf("August");
            break;
        case 9: 
            printf("September");
            break;
        case 10: 
            printf("October");
            break;
        case 11: 
            printf("November");
            break;
        case 12: 
            printf("December");
            break;
        default:
            printf("Invalid Month");
            break;
    }


    //3. Write a program to print the following triangle. Do not use ten printf statements; use two nested loops instead.
    printf("\n\nQuestion 3: Printing a triangle\n");
    
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++) 
        {
            printf("*");
        }
        printf("\n");
    }
    

    //4. Write a C program that takes an int from input and calculates the factorial of a given number, as specified in the example below:
    int n;
    unsigned long factorial = 1;
    printf("\nQuestion 4: Calculating the factorial of a given number\n");
    printf("Enter a number: ");
    scanf("%d", &n);

    //0! = 1
    for (int i = n; i > 0; i--)
    {
        factorial *= i;
        //FOR TESTING printf("factorial: %lu, number: %d\n", factorial, i);
    }
    printf("The Facorial of %d is: %lu\n", n, factorial);


    //5. Write a C program that takes a long int and calculates the sum of the digits of the number entered, as specified in the example below.
    long num;
    long sum = 0;
    long digit;
    printf("\nQuestion 5: Calculating the sum of the digits in a given long int\n");
    printf("Enter a number: ");
    scanf("%d", &num);

    //use % to find the remainder of the number then divide by 10. repeat
    while (num > 0) 
    {
        digit = num % 10;
        //FOR TESTING printf("sum: %d\n", sum);
        sum += digit;
        num /= 10;
        //FOR TESTING printf("num: %d\n", num);
    }
    printf("The sum of the digits is: %d\n", sum);


    //6. Write a C program that takes two positive int and calculates their greatest common divisor, as specified in the example below:
    int num1;
    int num2;
    int greatestCommonDivisor = 1;
    printf("\nQuestion 6: Calculating the greatest common divisor of two given positive integers\n");
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    //doesnt matter whether num1 or num2 is larger for the for loop. 
    for (int i = 1; i <= num1; i++) 
    {
        //if num1 is divisble by i AND num2 is divisible by i (meaning i is a factor of both num1 and num2) 
        //AND if i is greater than current saved divisor
        //then i becomes the new greatest common divisor
        if ((num1 % i == 0) && (num2 % i == 0) && (i > greatestCommonDivisor)) 
        {
            greatestCommonDivisor = i;
            //FOR TESTING printf("current greatest common divisor: %d\n", greatestCommonDivisor);
        }
    }
    printf("The greatest common divisor of %d and %d is %d.", num1, num2, greatestCommonDivisor);
       
    return 0;
}