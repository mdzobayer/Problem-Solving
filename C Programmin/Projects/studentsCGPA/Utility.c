
#include "Utility.h"


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

char* subjectCode(int i){
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

void saveDocument(struct studentInfo *s, int size)
{
    FILE *fptr;
    char fName[200];
    char fFolder[200];
    sprintf(fName, "c:/Users/%s/Desktop/Results/result.txt", getenv("USERNAME"));
    sprintf(fFolder,"mkdir c:\\Users\\%s\\Desktop\\Results",getenv("USERNAME"));

    if( access( fName, F_OK ) != -1 )
    {
        fptr = fopen(fName,"a");
        int i;
        for (i = 0; i < size; ++i) {
        fprintf(fptr,"%s\t%0.2f\n",s[i].id,s[i].cgpa);
        }
        fclose(fptr);
        printf("\a\nFile Saved Successfully in Desktop/Results/result.txt");
        puts("\n\nPress any key to continue\n");
        getch();
    }
    else
    {
        system(fFolder);
        fptr = fopen(fName,"a");
        fputs("ID\t\tCGPA\n",fptr);
        fputs("____________________\n",fptr);
        int i;
        for (i = 0; i < size; ++i) {
            fprintf(fptr,"%s\t%0.2f\n",s[i].id,s[i].cgpa);
        }
        fclose(fptr);
        printf("\a\nFile Saved Successfully in Desktop/Results/result.txt");
        puts("\n\nPress any key to continue\n");
        getch();
    }
}


