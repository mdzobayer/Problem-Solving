#include "PCInheritance.h"
#include "PCComposition.h"


int main() {

	// create a PC using inheritance with 1024Gb disk, 28" screen & monochrome
	// printer with scanner
	PCInheritance myPC(1024, 28, true, false, false);
	myPC.PCDisplay();

	// create a PC using composition with 1024Gb disk, additional 2048Gb disk,
	// 2 X 28" screen & no printer
	PCComposition myPC2(1024);
	myPC2.PCAddDisk(2048);
	myPC2.PCAddDisk(28);
	myPC2.PCAddDisk(28);
	myPC2.PCDisplay();

	return (0);
}
