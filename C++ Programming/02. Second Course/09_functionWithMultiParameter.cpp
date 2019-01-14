#include <iostream>
using namespace std;

int maximum(int num1,int num2,double num3){
    int largest;
    if(num1 > num2){
        largest = num1;
    }
    else
        largest = num2;
    if(num3 > largest)
        largest = num3;

    return (largest);
}
double ftoc(double temp){
    return ((temp -32.0) * (5.0/9.0));
};
double ctof(double temp){
    return (temp * (9.0/5.0) + 32.0);
};
double convertTemp(double temp, char scale){
    if(scale == 'c')
        return ftoc(temp);
    else if(scale == 'f')
        return ctof(temp);
}
int main(){
    /*
    int number1, number2, number3, max;
    cout << "Enter the three number: ";
    cin >> number1 >> number2 >> number3;
    max = maximum(number1,number2,number3);
    cout << "The maximum value is " << max << endl;


    double fahrTemp, celsius;

    cout << "Enter a fahrenheit temprature: ";
    cin >> fahrTemp;
    celsius = ftoc(fahrTemp);
    cout << fahrTemp << " fahrenheit is equal to "
         << celsius << " Celsius. " << endl;

    /*
    cout << "Enter a celsius Temperature: ";
    cin >> celsius;
    fahrTemp = ctof(celsius);
    cout << celsius << " celsius is equal to "
         << fahrTemp << " fahrenheit. " << endl;
    */

    double temp, convertedTemp;
    char tempScale;
    cout << "Enter a temperature and a scale to convert to: ";
    cin >> temp >> tempScale;
    convertedTemp = convertTemp(temp, tempScale);
    cout << "The conveted temperature is : "
         << convertedTemp << "." << endl;
    return (0);
};
