#pragma once
#include <string>
using namespace std;

class CarLambda
{
public:
	CarLambda(string mak, string modl, string col);
	string GetMake() const;
	string GetModel() const;
	string GetColor() const;

private:
	string make;
	string model;
	string color;
};
