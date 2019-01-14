#include <iostream>
#include <vector>
#include "CarFuncPtr.h"
#include <algorithm>

using namespace std;

vector<CarFuncPtr*> SelectBlueCars(vector<CarFuncPtr*> pool){
    // function to select all blue cars with hard coded color
    vector<CarFuncPtr*> selected;
    for(unsigned int x = 0; x < pool.size(); ++x)
    {
        if (pool[x]->GetColor() == "Blue")
        {
            selected.push_back(pool[x]);
        }
    }
    return selected;
}
vector<CarFuncPtr*> SelectFords(vector<CarFuncPtr*> pool)
{   // function to select all ford cars with hard coded make
    vector<CarFuncPtr*> selected;
    for (unsigned int x = 0; x < pool.size(); ++x)
    {
        if (pool[x]->GetMake() == "Ford")
        {
            selected.push_back(pool[x]);
        }
    }
    return selected;
}
/*
vector<CarFuncPtr*> SelectAny(vector<CarFuncPtr*) pool, string SelStmt)
{   // This would be great, but we can't interpret a string as code
    vector<CarFuncPtr*> selected;
    for(unsigned int x = 0; x < pool.size(); ++x)
    {
        if(SelStmt)
        {
            selected.push_back(pool[x]);
        }
    }
    return selected;
}*/

bool SelBlue(CarFuncPtr* c)
{
    return (c->GetColor() == "Blue");
}
bool SelFord(CarFuncPtr* c)
{
    return (c->GetMake() == "Ford");
}
    /**
    We can write a generic select function,
    and we can pass it, a pointer to one of those functions.
    A functions just like anything else lives in memory each code.
    It has an address. So if i can take the address of that function
    Pass that address into the select functions. And then called that
    functions to do my selection. I can pass actually any functions
    just a selection into the select any. Making select any a totally
    generic function. This is exectly what i am doing here

    The name of any function is actually its address in memory. Therefore i am
    passing a pointer to an address
    **/

vector<CarFuncPtr*> SelectAny(vector<CarFuncPtr*> pool, bool(*AnySelect)(CarFuncPtr*))
{
    vector<CarFuncPtr*> selected;
    for(unsigned int x = 0; x < pool.size(); ++x)
    {
        if(AnySelect(pool[x]))
        {
            selected.push_back(pool[x]);
        }
    }
    return selected;
}

int main() {

    vector<CarFuncPtr*> carpool;
    vector<CarFuncPtr*> selected;

    carpool.push_back(new CarFuncPtr("Ford", "Fiesta", "Blue"));
    carpool.push_back(new CarFuncPtr("Vauxhall", "Corsa", "Red"));
    carpool.push_back(new CarFuncPtr("Ford", "Fiesta", "Green"));
    carpool.push_back(new CarFuncPtr("Rolls Royce", "Phantom", "Silver"));
    carpool.push_back(new CarFuncPtr("Vauxhall", "Insignia", "Black"));
    carpool.push_back(new CarFuncPtr("Ford", "Focus", "Black"));
    carpool.push_back(new CarFuncPtr("Renault", "Clio", "Blue"));
    carpool.push_back(new CarFuncPtr("BMW", "Z4 Roadster", "Orange"));
    carpool.push_back(new CarFuncPtr("Ford", "Fiesta", "Yellow"));
    carpool.push_back(new CarFuncPtr("Vauxhall", "Corsa", "Black"));
    carpool.push_back(new CarFuncPtr("BMW", "4 Series Convertible", "White"));
    carpool.push_back(new CarFuncPtr("Ford", "Galaxy", "Green"));

    selected.clear();
    selected = SelectBlueCars(carpool);   // function to select all ford cars
    cout << endl << "Select Blue Cars using select function: " << endl;

    for(unsigned int x = 0; x < selected.size(); ++x)
    {
        cout << selected[x]->GetMake() << " " << selected[x]->GetModel() <<
             " " << selected[x]->GetColor() << endl;
    }

    selected.clear();
    selected = SelectFords(carpool);   // function to select all ford cars
    cout << endl << "Select Fords using select function: " << endl;

    for(unsigned int x = 0; x < selected.size(); ++x)
    {
        cout << selected[x]->GetMake() << " " << selected[x]->GetModel() <<
             " " << selected[x]->GetColor() << endl;
    }

    //SelectAny(carpool, "GetColor() == Blue");   // can't interpret a string as code!

    selected.clear();
    // Call a generic select function passing the select criteria
    // as a pointer to a function to perform the text.
    selected = SelectAny(carpool, SelBlue);
    cout << endl << "SelectAny blue cars using function pointer: " << endl;
    for(unsigned int x = 0; x < selected.size(); ++x)
    {
        cout << selected[x]->GetMake() << " " << selected[x]->GetModel() <<
            " " << selected[x]->GetColor() << endl;
    }

    selected.clear();
    // call a generic select function passing the select criteria
    // as a pointer to a function to perform the test.
    selected = SelectAny(carpool, SelFord);
    cout << endl << "SelectAny Fords using function pointer: " << endl;
    for(unsigned int x = 0; x < selected.size(); ++x)
    {
        cout << selected[x]->GetMake() << " " << selected[x]->GetModel() <<
            " " << selected[x]->GetColor() << endl;
    }

    return (0);
}

