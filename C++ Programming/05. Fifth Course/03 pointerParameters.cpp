
struct Date{
    int dd;
    int mm;
    int ccyy;
};
//bool IsValid (const Date * pDate)
    /*
    We can prevent modification Date by making our parameter
bool IsValid (const Date * pDate)
    constant Now pDate is now a pointer to a constant date
    I can still modify the pointer. because its not constant */
bool IsValid (const Date * const pDate)
    /*
    Prevent that type of modification, i can use constant
    pointer to constant date
    */
{
    bool valid;
    pDate->dd = 10;
    pDate = new Date{1, 1, 2000};
    return valid;
};

