#include <iostream>
#include <cstring>

using namespace std;
int main(){
    char name1[30];
    char name2[30];

    int len;
    cout<<"Enter the name1 and name2 : "<<endl;
    cin.getline(name1,30);
    cin.getline(name2,30);
    len = strlen(name1);
    cout<<"length = "<<len<<endl;
    cout<<"name1 = "<<name1<<endl<<"name2 = "<<name2<<endl;
    strrev(name1);
    strrev(name2);
    strcat(name1,name2);

    strupr(name1);
    cout<<"name1 = "<<name1<<endl;
    strcpy(name1,name2);
    cout<<"name1 = "<<name1<<endl;


    return (0);
}
