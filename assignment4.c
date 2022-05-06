/*
Assignment 4
Vicki Young
student ID: 20591845
start date: 2021.11.03
end date: 2021.11.15 at 2359
CS 221-02
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//QUESTION 3
struct foo {
    int a;
    char b;
};

int* foo();
double scalarProduct(int, double*, double*);

int main(int argc, char* argv[]) {
    //QUESTION 1
    printf("QUESTION 1\n");
    //following problem does not compile; explain why
    int *p1 = (int*) malloc(sizeof(int) * 5);
    void* p2 = (void*) p1;
    //p2[0] = 1;
    printf("the issue is with the line attempting to assign 1 to *p2. because p2 is a void* pointer, we cannot dereference it, as the compiler does not know the size of the object pointed to by a void* pointer. so trying to assign integer 1 to wherever void* pointer p2 points to will not work; we need pointer type int (int*) to store the address of an int and access it.\n"); 

    //QUESTION 2
    printf("\nQUESTION 2\n");
    //explain whats wrong with code and show how to fix
    int *y = foo();
    printf("%d\n", *y);
    printf("function foo() attempts to return the address of local variable x, whose stack memory will be deallocated once the function call terminates. in order to fix this issue, we use malloc to allocate a block of memory from the heap, so that we can still access the int stored there (in this case 7) after the function foo() terminates. we also must make sure to check that memory was properly allocated by checking for NULL.\n");

    //QUESTION 3
    printf("\nQUESTION 3\n");
    //rewrite code with only dereferencing (*) and pointer addition (+)
    //also extend code so that allocated memory is freed properly

    //declares arr as a pointer to allocated memory space of size 5 struct foo
    struct foo* arr = (struct foo*) malloc(5 * sizeof(struct foo)); 

    //check if memory space was properly allocated
    if (arr == NULL) {
        printf("memory not allocated\n");
        return EXIT_FAILURE;
    }

    int x;
    for (x = 0; x < 5; x++) {
        //the allocated memory space of size struct foo that *(arr +x) points to is passed a created structure with members 0 and 'b'
        //**(arr + x) = (struct foo) {0,'b'}; 

        //arr[x]->a is the same as (*arr[x]).a
        //arr->a is the same as (*arr).a 
        (*(arr + x)).a = 0; 
        (*(arr + x)).b = 'b';

        //print for testing
        //printf("for (*(arr + %d)).a: %d\n", x, (*(arr + x)).a);
        //printf("for (*(arr + %d)).b: %c\n", x, (*(arr + x)).b);
    }
    //frees the allocated memory space
    free(arr);

    
    //QUESTION 4
    printf("\nQUESTION 4\n");
    //write program with function scalarProduct() which computes the scalar product between 2 arrays
    //in main() function read a length, n, from command line and create 2 arrays (dynamically) of that length
    //main() function asks user to populate the array
    //then free all the dynamically allocated memory
    //check for potential errors that might happen during creation of dynamic variables/arrays
    //scalar product between two arrays (vectors): A.B = a1b1 + a2b2 + a3b3 + . . . + anbn

    //function atoi() converts string representation of an integral number to an int value
    //argc refers to the number of arguments passed
    //argv[] is a pointer array which points to each argument passed to the program
    //argv[0] holds the name of the program itself and argv[1] is a pointer to the first command line argument supplied
    int length = atoi(argv[1]);
    printf("given length of the two arrays: %d\n", length);

    //dynamically allocates two arrays of size length
    double *arr1 = (double*) calloc(length, sizeof(double));
    double *arr2 = (double*) calloc(length, sizeof(double));
    //checks to make sure memory space was correctly allocated by checking for NULL pointers
    if (arr1 == NULL || arr2 == NULL) {
        printf("memory not allocated\n");
        return EXIT_FAILURE;
    }
    //asks user to populate arr1 and arr2
    printf("populate arr1 with %d numbers:\n", length);
    for (int i = 0; i < length; i++) {
        scanf("%lf", arr1 + i);
    }
    printf("populate arr2 with %d numbers:\n", length);
    for (int i = 0; i < length; i++) {
        scanf("%lf", arr2 + i);
    }

    //prints arr1 and arr2
    printf("arr1: ");
    for (int i = 0; i < length; i++) {
        printf("%.2f ", *(arr1+ i));
    }
    printf("\narr2: ");
    for (int i = 0; i < length; i++) {
        printf("%.2f ", *(arr2+ i));
    }

    //prints the scalar product of the two arrays
    printf("\nscalar product of the two arrays: %.2f\n", scalarProduct(length, arr1, arr2));

    //frees the dynamically allocated memory blocks 
    free(arr1);
    free(arr2);

    return 0;
}

//QUESTION 2
int* foo() {
    int *x = (int*) malloc(sizeof(int)); //CHANGE: original statement is int x = 7;
    if (x == NULL) {
        printf("memory not allocated\n");
        exit(1);
    }
    *x = 7; //CHANGE: added initializating statement statement
    return x; //CHANGE: original statement is return &x;
}

//QUESTION 4
double scalarProduct(int n, double* A, double* B) {
    double product = 0;
    for (int i = 0; i < n; i++) {
        product += *(A + i) * *(B + i);
        //FOR TESTING
        //printf("\ncurrent product: %.2f", product);
    }
    return product;
}