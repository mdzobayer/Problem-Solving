/* Stamford Grading System */
#include <stdio.h>

//------- Grading Category --------
int category(float marks) {
    if (marks < 40) {
        return (0);//F
    }
    else if (marks < 45) {
        return (9);//E+
    }
    else if (marks < 50) {
        return (8);//D
    }
    else if (marks < 55) {
        return (7);//D+
    }
    else if (marks < 60) {
        return (6);//C
    }
    else if (marks < 65) {
        return (5);//C+
    }
    else if (marks < 70) {
        return (4);//B
    }
    else if (marks < 75) {
        return (3);//B+
    }
    else if (marks < 80) {
        return (2);//A
    }
    else {
        return (1);//A+
    }
}
//------- Main Function -------
int main() {
    float marks;
    int grade;
    printf("Enter your Marks: ");
    scanf("%f",&marks);
    grade = category(marks);

    //------ Switch Statement ------
    switch(grade) {
    case 0:
        printf("Your Grade is F\n");
        break;
    case 1:
        printf("Your Grade is A+\n");
        break;
    case 2:
        printf("Your Grade is A\n");
        break;
    case 3:
        printf("Your Grade is B+\n");
        break;
    case 4:
        printf("Your Grade is B\n");
        break;
    case 5:
        printf("Your Grade is C+\n");
        break;
    case 6:
        printf("Your Grade is C\n");
        break;
    case 7:
        printf("Your Grade is D+\n");
        break;
    case 8:
        printf("Your Grade is D\n");
        break;
    case 9:
        printf("Your Grade is E+\n");
        break;
    default:
        printf("You didn't attend the Examination\n");
    }

    return (0);
}
