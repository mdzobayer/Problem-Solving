#include <bits/stdc++.h>

using namespace std;

// Student Model
class Student {
    private:
        string rollNo;
        string name;
    public:
        Student() {
            rollNo = "";
            name = "";
        }
        Student(string name, string rollNo) {
            this->rollNo = rollNo;
            this->name = name;
        }
        string getRollNo() {
            return rollNo;
        }
        string getName() {
            return name;
        }
        void setName(string name) {
            this->name = name;
        }
        void setRollNo(string rollNo) {
            this->rollNo = rollNo;
        }
};

// View
class StudentView{
    public:
        void printStudentDetails(string studentName, string studentRollNo) {
            cout << "Student: ";
            cout << "Name: " + studentName << endl;
            cout << "Roll No: " + studentRollNo << endl;
        }
};

// Controller
class StudentController {
    private:
        Student model;
        StudentView view;
    
    public:
        StudentController(Student model, StudentView view) {
            this->model = model;
            this->view = view;
        }

        void setStudentName(string name) {
            model.setName(name);
        }

        string getStudentName() {
            return model.getName();
        }

        void setStudentRollNo(string rollNo) {
            model.setRollNo(rollNo);
        }

        string getStudentRollNo() {
            return model.getRollNo();
        }

        void updateView() {
            view.printStudentDetails(model.getName(), model.getRollNo());
        }
};

int main() {

    Student model("Zobayer", "CSE 059 07156");
    StudentView view;
    StudentController controller(model, view);

    controller.updateView();
    controller.setStudentName("Zobayer Mahmud");
    controller.updateView();

    return (0);
}