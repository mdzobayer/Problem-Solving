#include <iostream>
using namespace std;
class stud{
protected:
    int k;
public:
    char name[20];
    int age;
    float per;

    void enter(){
    cout<<"Enter the name age and percentage:";
    cin>>name>>age>>per;
    };
    void display(){
        cout<<"\nname\tage\tpercentage";
        cout<<"\n"<<name<<"\t"<<age<<"\t"<<per<<endl;
    };
};

int main(){
    class stud s;
    s.enter();
    s.display();


    return (0);
};
