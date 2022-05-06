/*
Assignment 2
Vicki Young
student ID: 20591845
start date: 2021.09.24
end date: 2021.10.11 at 2359
CS 221-02
*/

#include <stdio.h>
#include <stdbool.h>

void findmin(int[], int, int**);
void computeCube (int, int*);
bool strequal(const char[], const char[]);
int* getPtrToArray(int*);
double mean(const double*, int);
const char* findTheChar(const char*, char);
int* maxwell(int*, int*);
void swap1(int*, int*);
void swap2(int*, int*);

int main(void) {

    //QUESTION 1
    printf("Question 1)\n\n");

    //define integer variables x = 2 and y = 12
    int x = 2;
    int y = 12;

    //define two pointer variables p and q (p pointer of x; q pointer of y)
    int *p = &x;
    int *q = &y;

    printf("(1a) address of x: %d; value of x: %d\n", &x, x);
    printf("(1b) value of p: %d; value of *p: %d\n", p, *p);
    printf("(1c) address of y: %d; value of y: %d\n", &y, y);
    printf("(1d) value of q: %d; value of *q: %d\n", q, *q);
    printf("(1e) address of p: %d\n", &p);
    printf("(1f) address of q: %d\n", &q);


    //QUESTION 2
    printf("\nQuestion 2)\n\n");

    //define an array of integers arr[5]; fill with values 11, 40, 27, 0, and 3
    int arr[5] = {11, 40, 27, 0, 3};
    //define int i and a pointer variable p that points to i
    int i;
    p = &i; //did not define p again here because p already defined previously; but otherwise the statement here would be: int *p = &i;

    printf("Output of the two printing loops: \n");
    for ( i = 0; i < 5; i++) {
        printf("%d %p %d\n", i, arr+i, arr[i]);
    }
    i = 0;
    p = arr;
    while (p < (arr+5))
    {
        printf("%d %p %d\n", i, p, *p);
        i++;
        p++;
    }
    printf("Output of both printing loops is the same.\n");

    
    //QUESTION 3
    printf("\nQuestion 3)\n\n");
    
    printf("(3a)\n");
    printf("fixed program which is expected to print 50, 60, 70, one per line:\n");
    int MyArray[3] = {10, 20, 30};
    p = MyArray; //&MyArray[0] //did not define p again here because p already defined previously; otherwise the statement here would be unchanged: int *p = MyArray;
    *p = 70; //set MyArray[0] to 70
    p++; //changed statement from original: *p +=1
    *p = 60; //set MyArray[1] to 60
    p++; //changed statement from original: p += 2
    p[0] = 50; //set MyArray[2] to 50
    p++; //added statement here
    do {
        p--;
        printf("%d\n", *p); //print values
    } while (p > MyArray); //changed statement from original: p >= MyArray


    printf("\n(3b)\n");
    //findmin is supposed to find the minimum item in an array, then set the pToMin parameter to point to that item
    //explain why this function won't do that + show how to fix
    //fix must be to the function only; must not change the main() function
    
    
    int nums[4] = {45, 13, 5, 66};
    int* g; //changed int *p to int *g here because int *p has already been declared earlier in the program
    findmin(nums, 4, &g);
    printf("the minimum is at address %p\n", g);
    printf("It's at position %d\n", g - nums);
    printf("Its value is %d\n", *g);
    

    printf("\n(3c)\n");
    //function computeCube is correct but main function has a problem; explain why it isnt working + show how to fix
    //dont change computeCube

    int ptr; //changed int *ptr to int ptr
    computeCube(5, &ptr); //changed ptr to &ptr
    printf("Five cubed is %d\n", ptr); //changed *ptr to ptr
   
    printf("\nThe issue to fix is in making ptr just an ordinary integer variable rather than a pointer.\n");
    printf("When calling the function computeCube, we need to supply &ptr, which is a pointer to ptr.\n");
    printf("We should not supply just ptr itself because we need to give the function the address of ptr or a pointer to it, so that it can store the necessary value in ptr.\n"); 
    printf("The function computeCube has a parameter ncubed which is a pointer.\nWhen the function computeCube is called, ncubed has the value &ptr, \nand so *ncubed (the object ncubed points to) will be an alias for ptr.\n");
    printf("Additionally, when printing ptr, we only need to use ptr rather than *ptr. \nSince ptr itself has the value and is not a pointer to anything.\n");
    

    printf("\n(3d)\n");
    //function strequal is supposed to return True if and only if two C string arguments have exact same text
    //what are the problems with it and how can they be fixed

    char a[15] = "Chen, B.";
    char b[15] = "Chen, Y.J.";
    if (strequal(a,b)) {
        printf("They're the same person!\n");
    }

    printf("\nThe issue is that the function strequal is comparing the addresses of the string arrays to each other, not their contents, and so it will always return false because the string arrays have different addresses in memory.\n");
    printf("Also, we need to have #include <stdbool.h> if we are using booleans.\n");
    printf("To fix the problem with function strequal, it's better to use the name of the string arrays as pointers to the elements in each string array.\n");
    printf("Using the name of the arrays as pointers will have them point to the first elements in their respective arrays. We increment them as we compare each element.\n");
    printf("Return False if at any point the char values being compared are not equal, and by the end of the comparisons if there has been no return False, then return True.\n");


    printf("\n(3e)\n");
    //program is supposed to write 5 4 3 2 1 but does not
    //what is the problem with it? (not proposing a fix)

    /*
    int n;
    int *pt = getPtrToArray(&n); //used pt here instead of ptr since ptr has already been declared earlier in the program

    for (int i = 0; i < n; i++) {
        printf("&d ", pt[i]);
    }
    printf("\n");
    */

    printf("The issue is that getPtrToArray should accept &n, the address of n, and its paramter m should be a pointer (*m)\n");
    printf("And also for returning an array, the function getPtrToArray seems to return the address of a local variable which we cannot do? Since the array will not exist once the function returns, and the pointer will be invalid.\n");
    printf("However because of the f() junk function, which generates a junk array, the pointer pt may end up pointing to a weird value as a result of the junk function creating an array in stack.\n");


    //QUESTION 4
    printf("\nQuestion 4)\n\n");

    printf("(a) Declare a pointer variable named student that can point to a variable of type double.\n");
    double *student;
    printf("(b) Declare grades to be a 5-element array of double.\n");
    double grades[5];
    printf("(c) Make the student variable point to the last element of grades.\n");
    student = &grades[4];
    printf("(d) Make the double pointed to by student equal to 17, using the * operator.\n");
    *student = 17;
    printf("(e) Without using student pointer, and without using square brackets, set the fourth element (ie the one at position 3) of the grades array to have the value 72.\n");
    *(grades+3) = 72; //essentially grades[3] = 72
    printf("(f) Move the student pointer back by three double.\n");
    student-=3; //student = student - 3; since student currently points to grades[4], 4 - 3 = 1; student = 1
    printf("(g) Using square brackets, but without using the name grades, set the third element (ie the one at position 2) of the grades array to have the value 93.\n");
    student[1] = 93; //treated as *(student+1); since student = 1, *(student+1) = *(2); therefore grades[2] = 93
    printf("(h) Without using the * operator, but using square brackets, set the double pointed to by student to have the value 85.\n");
    student[0] = 85; //treated as *(student+0); since student = 1, *(student+0) = *(1); therefore grades[1] = 85

    for (int i = 0; i < 5; i++) {
        printf("%.2f ", grades[i]);
    }
    printf("\n");
    //should print values: 0.00 85.00 93.00 72.00 17.00


    //QUESTION 5
    printf("\nQuestion 5)\n\n");

    printf("(5a)\n");
    //rewrite the program so returns same result but does not increment variable ptr
    //program must not use any square brackets, but must use integer variable to visit each double in the array
    //can remove any unneeded variables

    double scores[5] = {1, 2, 3, 4, 5};
    double* s = &scores[0];
    printf("%.2f\n", mean(s, 5));


    printf("\n(5b) & (5c)\n");
    //rewrite function so does not have any square brackets (not even in parameter declarations)
    //also does not use integer variable k

    const char text[25] = "hsdzljfalsdf";
    const char *letterZ = findTheChar(text, 'z');
    printf("printing z through letterZ: %c\n", *letterZ);

    //(5c) rewrite function in 5b so that there are no square brackets or integer variables
    //i already did that . . .


    //QUESTION 6
    printf("\nQuestion 6)\n\n");
    //what does the following program print and why
    
    printf("QUESTION IS ANSWERED: explanation is given in program notes for each line\n");
    printf("ADDITIONAL NOTE: because ptr was already declared in earlier problems, i replaced ptr here with ptr6\n\n");

    int array[6] = {5, 3, 4, 17, 22, 19};

    /*
    printf("FOR TESTING: array without any changes\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }
    printf("\nEND TESTING\n");
    */

    int* ptr6 = maxwell(array, &array[2]); //ptr already declared earlier; ptr6 = &array[0]
    *ptr6 = -1; //changes array[0] = -1
    ptr6 += 2; //ptr6 = 0 + 2 = 2; ptr6 = &array[2]
    ptr6[1] = 9; //treated as *(ptr6+1) = *(2+1) = *(3); changes array[3] = 9
    *(array+1) = 79; //changes array[1] = 79
    printf("%d\n", &array[5] - ptr6); //&array[5] - &array[2] = &array[5-2] = &array[3]; prints 3 (the array's element number)
    //array currently: -1 79 4 9 22 19

    /*
    printf("FOR TESTING: array after maxwell function + ptr statements \n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }
    printf("\nEND TESTING\n");
    */

    swap1(&array[0], &array[1]); //array[0] = -1 and array[1] = 79; 
    //no change occurs; the actual values in the array remain the same

    /*
    printf("FOR TESTING: array after swap1 \n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }
    printf("\nEND TESTING\n");
    */

    swap2(array, &array[2]); //array basically means &array[0]; array[0] = -1 and array[2] = 4; after the function is called, the values are swapped so that now array[0] = 4 and array[2] = -1
    for (int i = 0; i < 6; i++) {
        printf("%d\n", array[i]);
    }
    //final array printed: 4 79 -1 9 22 19

    return 0;
}

void findmin(int MyArray[], int n, int** pToMin) { //MADE CHANGE: double asterisk on pToMin, so that pointer pToMin = &g (the address of pointer g)
//this means that *pToMin (the object that pToMin points to) = g, or *pToMin is an alias for g
//therefore **pToMin = *g, or **pToMin is the object that pointer g points to

    if (n <= 0) {
        return; //no items, no minimum
    }

    *pToMin = MyArray; //MADE CHANGE: added asterisk to pToMin, so that g = &MyArray[0]; g has the address of the first element in MyArray
    //FOR TESTING printf("printing *pToMin: %d\n", *pToMin); //FOR TESTING
    for (int i = 1; i < n; i++) {
        if (MyArray[i] < **pToMin) { //MADE CHANGE: added asterisk to pToMin, so that MyArray[i] compares to *g, or whatever value that g points to
            *pToMin = MyArray + i; //MADE CHANGE: added asterisk to pToMin, so that g = &MyArray[i]
            //FOR TESTING printf("printing *pToMin when at a smaller value: %d\n", *pToMin); //FOR TESTING
        }
    }
    
}

void computeCube(int n, int* ncubed) {
    *ncubed = n * n * n;
}

bool strequal(const char str1[], const char str2[]) {
    while (*str1 != 0 && *str2!= 0) {
        if (*str1 != *str2) {
            return false;
        }
        *str1++;
        *str2++;
    }
    return true;
}

/*
int* getPtrToArray(int* m) {
    int anArray[5] = {5, 4, 3, 2, 1};
    *m = 5;
    return anArray;
}
*/

double mean(const double* scores, int numScores) { //declaring scores to be a pointer is equivalent to declaring it as an array
    //const double* ptr = scores; //&scores[0]
    //printf("what *ptr is: %f\n", *ptr); //scores[0]
    //printf("what ptr is: %f\n", ptr);
    //printf("what scores is: %f\n", scores);
    /*while (ptr != scores + numScores) { //while scores[0] != scores[0] + 5 
        tot += *ptr; //++scores[i]
        ptr++; 
    }*/
    /*for (ptr = scores; ptr < scores + numScores; ptr++) {
        tot += *ptr;
    }*/

    double tot = 0;
    for (int i = 0; i < numScores; i++) {
        tot += *(scores+i); //*(scores+i) is the same as scores[i]
    }
    return tot / numScores;
}

const char* findTheChar(const char* str, char chr) {
    while (*str != '\0') {
        if (*str == chr) {
            return str;
        }
        str++;
    }
    return NULL;
}

int* maxwell(int* a, int* b) { //a = &array[0] and b = &array[2]
    if (*a > *b) { //a* = array[0] = 5 and b* = array[2] = 4, so if 5 > 4; TRUE
        return a; //returns &array[0]
    } else {
        return b;
    }
}

void swap1(int* a, int* b) { //a = &array[0], meaning *a = array[0] = -1; and b = &array[1], meaning *b = array[1] = 3
    int* temp = a; //temp = &array[0]; as in, temp has the literal address of array[0] as its value
    a = b; //&array[0] = &array[1]; as in, the contents of b (the address of array[1]) are now copied into a, making a point to b
    b = temp; //&array[1] = &array[0]; as in, the the contents of temp (the address of array[0]) are now copied into b, making b point to temp/a
    //this just changes where the pointer parameters a and b point to; does not change any of the actual values in the array
}

void swap2(int* a, int* b) { //a = &array[0], meaning *a = array[0] = -1; and b = &array[2], meaning *b = array[2] = 4
    int temp = *a; //temp = array[0] = -1
    *a = *b; //array[0] = array[2]; changes array[0] = 4
    *b = temp; //changes array[2] = -1
}