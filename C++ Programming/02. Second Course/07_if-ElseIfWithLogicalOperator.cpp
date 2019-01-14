#include <iostream>
using namespace std;
int main(){
    int grade;
    string letterGrade;
    cout << "Enter a grade : ";
    cin >> grade;
    if ((grade >= 97) && (grade <= 100)){
        letterGrade = "A+";
    }
    else if ((grade >= 93) && (grade <= 96)){
        letterGrade = "A";
    }
    else if((grade >= 90) && (grade <= 92)){
        letterGrade = "A-";
    }
    else if ((grade >= 87) && (grade <= 89)){
        letterGrade = "B+";
    }
    else if ((grade >= 83) && (grade <= 86)){
        letterGrade = "B";
    }
    else if((grade >= 80) && (grade <= 82)){
        letterGrade = "B-";
    }
    else if ((grade >= 77) && (grade <= 79)){
        letterGrade = "C+";
    }
    else if ((grade >= 73) && (grade <= 76)){
        letterGrade = "C";
    }
    else if((grade >= 70) && (grade <= 72)){
        letterGrade = "C-";
    }
    else if ((grade >= 67) && (grade <= 69)){
        letterGrade = "D+";
    }
    else if ((grade >= 63) && (grade <= 66)){
        letterGrade = "D";
    }
    else if((grade >= 60) && (grade <= 62)){
        letterGrade = "D-";
    }
    else {
        letterGrade = "F";
    }
    cout << "The letter Grade for a "
         << grade <<" is a " << letterGrade << " ." << endl;

    return (0);
}

