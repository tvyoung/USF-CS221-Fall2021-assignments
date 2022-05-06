/*
Assignment 3
Vicki Young
student ID: 20591845
start date: 2021.10.11
end date: 2021.10.25 at 2359
CS 221-02
*/

#include <stdio.h>
#include <stdbool.h>

#define TEXT_LENGTH 50

void toUpperCase(char*);
int findMax(int*, int, int);
void reverse(char*, int, int);
long convertToBinary(int);
bool isPalindrome(char*, int, int);

int main(void) {
    
    //INSTRUCTIONS
    //complete body of the given functions
    //cannot modify function signatures (add new parameters or change data types)
    //cannot use square brackets
    //cannot use any library functions
    //cannot use any loops 

    //QUESTION 1
    //Write the body of the function below so that it recursively converts all lowercase letters in a string to uppercase
    printf("1)\n");
    char text1[] = "aBcD?2";
    printf("given string: %s\n", text1);
    toUpperCase(text1);
    printf("returned string: %s\n", text1);

    //QUESTION 2
    //Write a recursive program that receives an array of positive integers and its length and returns the largest number in the array.
    printf("\n2)\n");
    int arr[5] = {2, 31, 4, 12, 8};
    printf("array: ");
    for (int *i = arr; i < arr + 5; i++) {
        printf("%d ", *i);
    }
    printf("\nthe max is: %d\n", findMax(arr, 5, 0));

    //QUESTION 3
    //Write a program in C to reverse a string using recursion.
    printf("\n3)\n");
    char text2[] = "1AbCDEF2gH!Ijk3?";
    int length = (sizeof(text2) / sizeof(*text2)) - 1;
    printf("given string: %s\n", text2);
    printf("string length: %d\n", length);
    reverse(text2, 0, length);
    printf("returned string: %s\n", text2);

    //QUESTION 4
    //Write a function in C to convert a decimal number to binary using recursion.
    printf("\n4)\n");
    int n = 10;
    printf("convert %d to binary: %d\n", n, convertToBinary(n));

    //QUESTION 5
    //Write a function that checks whether a given string is a palindrome or not, recursively. Palindrome is a word, phrase, or sequence that reads the same backward as forward.
    printf("\n5)\n");
    char text3[] = "abcba";
    int text3Length = (sizeof(text3) / sizeof(*text3)) - 1;
    char text4[] = "abcb1";
    int text4Length = (sizeof(text4) / sizeof(*text4)) - 1;
    printf("given string %s is a palindrome: %s\n", text3, isPalindrome(text3, 0, text3Length-1) ? "true" : "false");
    printf("given string %s is a palindrome: %s\n", text4, isPalindrome(text4, 0, text4Length-1) ? "true" : "false");


    return 0;
}

//QUESTION 1
//Write the body of the function below so that it recursively converts all lowercase letters in a string to uppercase
void toUpperCase(char *str)
{
    if (*str == '\0') {
        return;
    } else {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 32;
        }
        return toUpperCase(++str);
    }
}

//QUESTION 2
//Write a recursive program that receives an array of positive integers and its length and returns the largest number in the array.
//p = size of the array
//max = stores the current max value in the array
int findMax(int *arr, int p, int max)
{
    //checks if reached the end of array; p is basically how many elements left to check for max
    //so if p is 0, as in, no more elements to check for max, then return the current max value
    if (p == 0) {
        return max;
    //if end of array not yet reached (still more elements to check)
    } else {
        //and if the current element pointed to in the array is greater than the current max
        if (*arr > max) {
            //current elemented pointed to in the array becomes the new max
            max = *arr;
        }
        //moves pointer up so we point to the next element in the array, and subtract from p to indicate one less element to check in array
        findMax(++arr, --p, max);
    }
}

//QUESTION 3
//Write a program in C to reverse a string using recursion.
//i = index (or the head of the array)
//s = size of array (or the tail of the array)
void reverse(char *str, int i , int s)
{
    //if the head and the tail of the array are the same, or the head is at an element past the tail, the elements of the array has been fully reversed; end function
    //since we will end the function after both the head and tail reach the middle of the array
    if (i >= s) {
        return;
    } else {
        //first have to decrement s to index the last element in the array arr[s-1]; but also to decrease s when reverse() is called again recursively
        --s;
        //swap the head and tail elements of array using temp variable
        char temp = *(str + i);
        *(str + i) = *(str + s);
        *(str + s) = temp;
        //call reverse function again with i incremented
        reverse(str, ++i, s);
    }

}

//QUESTION 4
//Write a function in C to convert a decimal number to binary using recursion.
//decimal number is base 10 number (total 10 digits; ranges from 0 to 9)
//binary number is base 2 number (total 2 digits; 0 or 1)
//use % modulo to find the remainder of the number; ex. 33 % 10 = 3, and 392 % 10 = 2
long convertToBinary(int num)
{
    if (num == 0) {
        return 0;
    } else {
        return (num % 2 + 10 * convertToBinary(num / 2));
    } 
}
/*ex. if num = 10
num % 2 returns either 0 or 1
10 % 2 = 0 + 10 * convertToBinary(5)  = 0 * 10 * 101 = 1010
5 % 2 = 1 + 10 * convertToBinary(2)   = 1 + 10 * 10  = 101
2 % 2 = 0 + 10 * convertToBinary(1)   = 0 + 10 * 1   = 10
1 % 2 = 1 + 10 * convertToBinary(0)   = 1 + 10 * 0   = 1
return 0
*/

//QUESTION 5
//Write a function that checks whether a given string is a palindrome or not, recursively. Palindrome is a word, phrase, or sequence that reads the same backward as forward.
//s = start; index number of the starting element (for stringArray[N], s should be 0)
//e = end; index number of the last element (for stringArray[N], e should be N-1)
bool isPalindrome(char *str, int s, int e)
{
    //if the index number s points to either is the same as what e points to or passes e, all elements in the string should have been checked
    //since nothing has caused function to return false, this means the string is a palindrome; return true
    //also considers the case that if string is a single letter, it is a palindrome; s = e, and so returns true
    if (s >= e) {
        return true;
    //else the string has not been fully checked yet
    } else {
        //if the element of starting point s is equal to the element of ending point e match, then can check the next elements now
        if (*(str + s) == *(str + e)) {
            //recursively call function again, this time checking if the elements of s+1 and e-1 match
            isPalindrome(str, ++s, --e);
        //else if the elements of the start and ends do not match, then the string is not a palindrome; immediately returns false
        } else {
            return false;
        }
    }
}