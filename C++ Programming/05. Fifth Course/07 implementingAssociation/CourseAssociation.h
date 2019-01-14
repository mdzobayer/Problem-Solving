#pragma once
// Class CourseAssociation
// Has custody of delegates - is responsible for their creation & deletion
// Does not have custody of the trainer - Trainer is created separately &
// can exist without a course. Does not have Custody of Location. Has a constant
// association with Location. Location is reference
//       and must be assigned in a constructor


#include "DelegateAssociation.h"
#include "TrainerAssociation.h"
#include "LocationAssociation.h"
#include <map>
#include <iostream>
using namespace std;

class CourseAssociation
{
public:
    CourseAssociation(LocationAssociation& courseLocation)
        : rLocation{ courseLocation }
    {
        // Course Constructor initializes the course location reference
    }

    ~CourseAssociation()
    {
        // Courses destructor - delete all delegates currently on course
        // Only delegates are deleted because the trainer * location are
        // without custody.
        for(map<string, DelegateAssociation*>::iterator it = delegates.begin(); it != delegates.end(); ++it)
        {
            delete it->second;
        }
    }

    void SetTrainer(TrainerAssociation* pTrain)
    {
        // trainer is variable association without custody. New trainers can
        // be supplied simply by replacing the pTrainter pointer with a pointer
        // to another trainer.
        pTrainer = pTrain;
    }

    void AddDelegate(string dName, string dAddress)
    {
        // Delegates are with custody. They are created internally to the
        // Course object & added to the delegates map.
        delegates.emplace(dName, new DelegateAssociation(dName, dAddress));
    }

    void RemoveDelegate(string dName)
    {
        // Delegates can be removed from a course, in which case they must be
        // removed from the map & their memory deleted. This must be done
        // internally to the course because they are with custody.
        map<string, DelegateAssociation*>::iterator miterator;
        miterator = delegates.find(dName);
        delete miterator->second;
        delegates.erase(miterator);
    }

    void ListDelegates()
    {
        // list all delegates currently in the map
        // using cout is bad practice in classes, but used here for demonstration
        // purposes only.
        for(map<string, DelegateAssociation*>::iterator it = delegates.begin(); it != delegates.end(); ++it)
        {
            cout << it->first << endl;
        }
    }
private:
    // map of delegetes used for with custody variable association objects
    map<string, DelegateAssociation*> delegates;
    // pointer to trainer used for without custody variable association trainer
    TrainerAssociation* pTrainer;
    // reference to location which MUST be initialized in a constructor &
    // cannot be changed thereafter. It is this a constant association, but since
    // the location object is not created / deleted by the course it is
    // without custody
    LocationAssociation& rLocation;
};
