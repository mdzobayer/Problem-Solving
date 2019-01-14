
#include "Utility.h"

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
        printf("Enter student id(CSE XXXXXX): ");
        gets(students[i].id);
        int j;
        students[i].cgpa = 0.0;
        for (j = 0; j < totalSub; ++j)
        {
            printf("Enter marks for %s : ",subjectCode(j + 1));
            scanf("%f",&tempMarks);
            getchar();
            tempCGPA = generateCGPA(tempMarks);
            students[i].cgpa = students[i].cgpa + tempCGPA;
        }
        students[i].cgpa = (float)students[i].cgpa / totalSub;

    }

    DisplayCGPA(students, stdNumber);
    char decide;
    printf("\nDo you want to save it in a document(Y/N): ");
    decide = getchar();
    if (decide == 'y' || decide == 'Y'){
        saveDocument(students, stdNumber);
    }

    free(students);

    return (0);
};


