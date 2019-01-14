
#include <stdio.h>
#include <stdlib.h>
struct studentInfo
{
    char id[15];
    float cgpa;
};

float generateCGPA(float marks)
{
    if (marks >= 80)
        return (4.00);
    else if (marks >= 75)
        return (3.75);
    else if (marks >= 70)
        return (3.50);
    else if (marks >= 65)
        return (3.25);
    else if (marks >= 60)
        return (3.00);
    else if (marks >= 55)
        return (2.75);
    else if (marks >= 50)
        return (2.50);
    else if (marks >= 45)
        return (2.25);
    else if (marks >= 40)
        return (2.00);
    else
        return (0.0);
}

void DisplayCGPA(struct studentInfo *s, int size)
{
    int i;
    system("CLS");
    puts("\nID\t\tCGPA");
    puts("____________________\n");
    for (i = 0; i < size; ++i) {
        printf("%s\t%0.2f\n",s[i].id,s[i].cgpa);
    }
}

char* subCode(int i){
    if (i == 1)
        return "CSI101";
    else if (i == 2)
        return "CSI102";
    else if (i == 3)
        return "CSI201";
    else if (i == 4)
        return "CSI202";
    else if (i == 5)
        return "CSI301";
    else if (i == 6)
        return "CSI302";
    else if (i == 7)
        return "CSI401";
    else if (i == 8)
        return "CSI402";
    else if (i == 9)
        return "CSI501";
    else if (i == 10)
        return "CSI502";
    else
        return "CSI";
}

int main() {

    struct studentInfo *students;
    float tempMarks = 0, tempCGPA = 0.0;
    int stdNumber = 0, totalSub = 0;
    printf("Enter how many student: ");
    scanf("%d",&stdNumber);

    printf("Enter how many subject: ");
    scanf("%d",&totalSub);
    getchar();
    puts("\n");

    students = (struct studentInfo*)malloc(stdNumber * sizeof(struct studentInfo));
    int i;
    for(i = 0; i < stdNumber; ++i)
    {
        printf("Enter student id(CSE XXXXXX: ");
        gets(students[i].id);
        int j;
        students[i].cgpa = 0.0;
        for (j = 0; j < totalSub; ++j)
        {
            printf("Enter marks for %s : ",subCode(j + 1));
            scanf("%f",&tempMarks);
            getchar();
            tempCGPA = generateCGPA(tempMarks);
            students[i].cgpa = students[i].cgpa + tempCGPA;
        }
        students[i].cgpa = (float)students[i].cgpa / totalSub;

    }

    DisplayCGPA(students, stdNumber);

    free(students);

    return (0);
}
