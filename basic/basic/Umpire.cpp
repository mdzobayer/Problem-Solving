#include<iostream>
#include<conio.h>
using namespace std;

class trnmnt
{
    int m;  //number of mathc in a tournament
    char match[11];     //stores the results of matches
    public:
        void set_m(){   cin>>m; }
        void set_match(){   int i;  for(i=0;i<m;i++)    cin>>match[i];  }   //set the results of matches
        void show_match(){   int i;  for(i=0;i<m;i++)    cout<<match[i]<<endl;  }   //set the results of matches
        void result();
};

void trnmnt::result()
{
    int i;  //for indexing
    int count=0;  //for counting loss or draw

   /* for(i=0;i<m;i++)
    {
        if(match[i]=='l')
            count++;
        else if(match[i]=='d')
            count++;
        else
            count=0;

        if(count>=3){
            break;}
    }*/

    for(i=0;i<m;i++)
    {
        switch(match[i])
        {
            case 'l' :
            case 'd' : count++;break;
            default: count=0;
        }

        if(count>=3){
            break;}
    }

    if(count==3)
        cout<<"Eliminated from the tournament at match no: "<<i+1<<endl;
    else
        cout<<"Won the tournament."<<endl;
}

int main()
{
    cout<<"\n\t\t\t\tUMPIRE\n"<<"\t\t\t\t------\n\n";
    cout<<"How many Tournaments ? (max : 10)\t";
    int tm; //number of tournaments or number of objects of class trnmnt
    cin>>tm;
    int mch=0;  //for counting match number

    trnmnt team[10];    //stores the tournament data
    int i=0;  //for indexing
    while(i<tm) //determining whether index is less than or equal to tournament number or not
    {
        cout<<"\n\t\t\t     Tournament "<<i+1<<"\n\t\t\t     ------------"<<endl;
        cout<<"How many matches in tournament "<<i+1<<" ? (max : 10)\t";
        team [i].set_m();
        cout<<"\nPlease enter match results for tournament "<<i+1<<" : "<<endl;
        team [i].set_match();
        //team [i].show_match();

        cout<<"\nResult for tournament "<<i+1<<" : ";
        team[i].result();

        i++;
    }

    getch();
    return 0;
}
