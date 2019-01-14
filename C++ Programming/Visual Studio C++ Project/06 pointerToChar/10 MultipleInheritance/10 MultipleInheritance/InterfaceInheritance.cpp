class iControllable
{
public:
	virtual void Contorl() = 0;
};
class iInsurable
{
public:
	virtual void PayPremium() = 0;
};
class Animal
{

};
class Dog : public Animal, public iControllable, public iInsurable
{

};
class Cat : public Animal, public iInsurable
{

};