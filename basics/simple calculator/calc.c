#include <stdio.h>

int main() {
    float a, b;
    int c;
    int d  = (int)a;
    int e = (int)b;
    printf("\t***A_Simple_C_Calculator ✨***\n\n"); 
    printf("Enter First Number: ");
    scanf("%f", &a);

    printf("Enter Second Number: ");
    scanf("%f", &b);

    printf("\nChoose 1 for Addition\n");
    printf("Choose 2 for Subtraction\n");
    printf("Choose 3 for Divide\n");
    printf("Choose 4 for Multiply\n");
    printf("Choose 5 for Modulus\n\n");

    printf("Enter Your Choice: ");
    scanf("%d", &c);

    printf("\n");

    switch(c) {

        case 1:
            printf("%.2f + %.2f = %.2f\n", a, b, a+b);
            break;

        case 2:
            printf("%.2f - %.2f = %.2f\n", a, b, a-b);
            break;

        case 3:
            if(b != 0)
                printf("%.2f / %.2f = %.2f\n", a, b, a/b);
            else
                printf("Error: Not Defined\n");
            break;
        case 4:
            printf("%.2f * %.2f = %.2f\n", a, b, a*b);
            break;

        case 5: {
            int d = (int)a;
            int e = (int)b;
            if(e != 0)
                printf("%d %% %d = %d\n", d, e, d % e);
            else
                printf("Error: Modulus by zero not allowed!\n");
            break;
        }

        default:
        printf("Invalid Choice! Please choose 1-5.\n");
    }

    printf("\n\tThanks_for_Using_Our_Calculator\n\t\tHave_a_Good_Day\n");
    return 0;
}
