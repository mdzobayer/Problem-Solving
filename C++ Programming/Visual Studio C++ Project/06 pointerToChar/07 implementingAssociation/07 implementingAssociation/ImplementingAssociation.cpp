#include "TrainerAssociation.h"
#include "LocationAssociation.h"
#include "CourseAssociation.h"
#include "DelegateAssociation.h"

int main() {

	// create a location
	LocationAssociation loaction1("Moscow", 99);

	// create a trainer
	TrainerAssociation* trainer1 = new TrainerAssociation("Fred Flintstone", "Tid123");
	TrainerAssociation* trainer2 = new TrainerAssociation("Simon Bailey", "Tid456");

	// create a course with fixed association for course location
	CourseAssociation CPPCourse(loaction1);

	// add a trainer to the course
	CPPCourse.SetTrainer(trainer1);

	// add delegates
	CPPCourse.AddDelegate("Yogi Bear", "Jellystone National Park");
	CPPCourse.AddDelegate("Batman", "Gotham City");
	CPPCourse.AddDelegate("Popeye", "Sweethaven");
	CPPCourse.AddDelegate("Superman", "Krypton");
	CPPCourse.ListDelegates();

	// Fred Flintstone is no longer available - change the trainer variable association without custody
	CPPCourse.SetTrainer(trainer2);

	// remove a delegate
	CPPCourse.RemoveDelegate("Batman");
	CPPCourse.ListDelegates();

	// add delegates
	CPPCourse.AddDelegate("Robin", "Gotham City");
	CPPCourse.AddDelegate("Cinderella", "The Royal Castle");
	CPPCourse.ListDelegates();

	cout << endl;

	return (0);
}
