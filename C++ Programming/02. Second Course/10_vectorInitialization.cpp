#include <iostream>
#include <vector>
using namespace std;
int main(){
    //vector<string> names;
        //No storage space
        //initial reserve

    //vector<string> names(10);
        //with a number storage of
        //storage spaces reserve

    vector<string> names(10,"a");
        //with a number storage of spaces
        //reserve and a default value
        //to fetch into each space


    for(int i = 0; i < names.size(); ++i)
        cout << i << ": " << names[i] << endl;

    return (0);
}
