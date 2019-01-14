#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int stack[100];
int top = 0;
int maxStack = 99;

void push(int item)
{
     if ( maxStack == top)
     {
          cout << "OverFlow" << endl;
          return;
     }
     stack[top] = item;
     top++;

}
void pop()
{
     if ( top == 0)
     {
          cout << "UnderFlow" << endl;
          return;
     }
     //stack[top] =
     top--;
}
void printStack()
{
     for(int i = 0; i < top; i++)
     {
          cout << stack[i] << " ";
     }
     cout << "\n\nPress any key to Back.. ";
     getch();
     system("cls");

}

int main()
{

     label:
     int choice;
     int value;
     cout << "1. Push" << endl;
     cout << "2. Pop" << endl;
     cout << "3. Print Stack" << endl;
     cout << "4. Exit" << endl;
     cout << "Enter your choice: ";
     cin >> choice;

     if ( choice == 1)
     {
          cout << "Enter an integer value: ";
          cin >> value;
          push(value);
          system("cls");
          goto label;
     }
     else if (choice == 2)
     {
          cout << "\nAn item removed successfully" << endl;
          pop();
          cout << "\nPress any key to Back.. ";
          getch();
          system("cls");
          goto label;
     }
     else if ( choice == 3)
     {
          cout << "Stack is : " << endl;
          system("cls");
          printStack();
          goto label;
     }
     else if ( choice == 4)
     {
          cout << "\nExit Successfully" << endl;
          getch();
          return (0);
     }
     else
     {
         cout << "\a\nWrong Choice!" << endl;
         cout << "Try again.\n\n";
         goto label;
     }

     return(0);
}
