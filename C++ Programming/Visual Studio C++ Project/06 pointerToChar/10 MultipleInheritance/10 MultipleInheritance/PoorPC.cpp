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

class PC		// Multiple Inheritance
	: public Motherboard, public DiskDrive, public FloppyDisk,
	public keyboard, public Mouse, public Screen
{

};