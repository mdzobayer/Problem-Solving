#include <iostream>

using namespace std;
struct Employee1 {              // readable structure
    char employeeReference[10];
    double salary;
    int departmentCode;
    bool companyPension;
    double performanceBonus;
    bool conductSatisfactory;
    int daysAnnualLeave;
    bool companyCar;
    double carExpenseAllowance;
    int phoneExtension;
};

struct Employee2 {          // Compiler inserts padding for alignment
    char employeeReference[10];
    char padding1[6];
    double salary;
    int departmentCode;
    bool companyPension;
    char padding2[3];
    double performanceBonus;
    bool conductSatisfactory;
    char padding3[3];
    int daysAnnualLeave;
    bool companyCar;
    char padding4[7];
    double carExpenseAllowance;
    int phoneExtension;
    char padding5[4];
};
struct Employee3 {      // less readable but tighter packing
    double salary;
    double performanceBonus;
    double carExpenseAllowance;
    int departmentCode;
    int daysAnnualLeave;
    int phoneExtension;
    char employeeReference[10];
    bool companyPension;
    bool conductSatisfactor;
    bool companyCar;
};

// store the current packing onto an internal stack
#pragma pack (push)
// Modifies the default packing to 1 byte boundries.
#pragma pack (1)
struct Employee4 {      // readable but packed (non-portable) structure
    char employeeReference[10];
    double salary;
    int departmentCode;
    bool companyPension;
    double performanceBonus;
    bool conductSatisfactory;
    int daysAnnualLeave;
    bool companyCar;
    double carExpenseAllowance;
    int phoneExtension;
};
// Restores the values which is pushed on
#pragma pack (pop)
// Requested alignment can't upper 2 power 7
struct alignas(128) Employee5 {     // aligned structure
    char employeeReference[10];
    double salary;
    int department;
    bool companyPension;
    double performanceBonus;
    bool conductSatisfactory;
    int daysAnnualLeave;
    bool companyCar;
    double carExpenseAllowance;
    int phoneExtension;
    char padding[128];
};
struct Employee6 {          // effect of alignas(128)
    char employeeReference[10];
    double salary;
    int departmentCode;
    bool companyPension;
    double performanceBonus;
    bool conductSatisfactory;
    int daysAnnualLeave;
    bool companyCar;
    double carExpenseAllowance;
    int phoneExtension;
    char padding[56];
};

int main() {

    cout << "Size of readable Employee1 = " << sizeof(Employee1) << endl;
    cout << "Size of padded Employee2 = " << sizeof(Employee2) << endl;
    cout << "Size of less readable but packed Employee3 = " << sizeof(Employee3) << endl;
    cout << "Size of #pragma packed Employee4 = " << sizeof(Employee4) << endl;
    cout << "Size of aligned Employee5 = " << sizeof(Employee5) << endl;
    cout << "Size of simulated alignas Employee6 = " << sizeof(Employee6) << endl;

    return (0);
}
