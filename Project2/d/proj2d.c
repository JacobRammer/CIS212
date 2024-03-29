#include <stdio.h>

int main()
{
    int a[21] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 
                    233, 377, 610, 987, 1597, 2584, 4181, 6765};

    int *b[3] = {a, a + 7, a + 14};
    /*
    b[0] = a;
    b[1] = a + 7;
    b[2] = a + 14;

    printf("b[2] %p\n", b[0]);  // pointer 
    printf("Pointer for a%p\n", a);  // pointer
    printf("%d\n", a[20]);  // value 
    printf("Pointing location of b[2]: %p, location of a[14]: %p" 
            "value of a[14]: %d\n", b[2], &a[14], a[14]);
    printf("%d is the value\n", b[1][5]); // 5 + 7
    printf("%d is the value of a[1]\n", a[1]);
    */

    // question 1
    printf("Q1: %d is the value of *a\n", *a);
    
    //question 2
    printf("Q2: the value of b[1][3] is %d\n", b[1][3]);

    // question 3
    printf("Q3: the value of *(a + 4) is %d\n", *(a + 4));

    //question 4
    printf("Q4: the value of (a + 6) is %p\n", (a + 6));

    // for (int i = 0; i < 21; i++)
    // {
    //     printf("%p\n", (a + i));
    // }

    //question 5
    // printf("Q5: *(a + 6): %d\n", *(a + 6)); // should = 8

    // question 6
    printf("q5: b[2][0]-b[1][6] is: %d\n", (b[2][0] - b[1][6]));  // is taking the values and subtracting

    // question 7
    printf("q6: b[2][0]-b[1][7] is :%d\n", (b[2][0] - b[1][7]));

    // question 8
    // printf("*p (a+6): %d\n", *(a + 6));
    // printf("*p (a + 3) is: %d\n", *(a + 3));
    printf("q7: (a+6) - (a+3) is: %ld\n", ((a + 6) - (a + 3)));

    // question 9
    printf("q8: *(a+6) - *(a+3) is: %d\n", (*(a + 6) - *(a + 2)));

    // question 10
    printf("q9: a[5]-*(a+4) is: %d\n", a[5] - *(a + 4));

    // question 11
    // printf("b[0] is : %d\n", *a);
    // printf("(a+9) is :%d\n", *(a + 9));
    printf("q10: (a+9) - b[0] is: %ld\n", (a + 9) - b[0]);

    // question 12
    printf("q11: b[0] is :%p\n", b[0]);

    // 13
    printf("q12: (b[2][2]) - (a[15]) is: %d\n", (b[2][2]) - (a[15]));

    // question 13
    // printf("&(b[2][3]) is :%p\n", &(b[2][3]));
    printf("q13: &(b[2][3]) - &(a[15]) is: %ld\n", &(b[2][3]) - &(a[15]));

    // question 14
    printf("q14: *(&a[6] is :%d\n", *(&a[6]));

    // question 15
    // printf("q15: b[3]-b[1] is :%ld\n", b[3] - b[1]);

    return 0;
}