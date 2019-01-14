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
	// This is call containment rather then inheritance
	Motherboard m;
	DiskDrive d;
	FloppyDisk f;
	keyboard k;
	Mouse mo;
	Screen s;
};