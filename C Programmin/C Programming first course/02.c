#include <stdio.h>

int main()
{
    int num1,num2,sum,subtract, a;
    printf("Enter 1 for addition, \nEnter 2 for substraction");
    printf("\nEnter your Choice(1-2): ");
    scanf("%d",&a);
    printf("Enter the two values: ");
    scanf("%d %d",&num1,&num2);
    if(a==1){
        sum = add(num1,num2);
        printf("Addition = %d",sum);
    }
    if(a==2){
        subtract= sub(num1,num2);
        printf("Sub = %d",subtract);
    }
    else if (a>0)

    printf("Entered number is not in the range specified");
return 0;
}
int add(int a, int b){
int result;
result = a+b;
return result;

}
int sub(int a, int b){
int result;
result = a - b;
return result;

}
