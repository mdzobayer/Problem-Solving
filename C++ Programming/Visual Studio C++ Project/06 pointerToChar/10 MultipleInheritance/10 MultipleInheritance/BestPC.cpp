#include <vector>
class Motherboard
{

};
class DiskDrive
{

};
class FloppyDisk
{

};
class keyboard
{

};
class Mouse
{

};
class Screen
{

};
class PC
{
private:
	Motherboard* m;
	std::vector<DiskDrive*> d;
	FloppyDisk* f = nullptr;
	keyboard* k;
	Mouse* mo;
	std::vector<Screen*> s;
};