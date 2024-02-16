#include<iostream>
#include<string>
using namespace std;

string menu(){
 return "\n1.) Sum of two value\n2.) Factorial of a number\n3.) Table of a number\n4.) Even number from min to max value\n5.) Prime number\n6.) Exit";
}

int main(){
 int choice;
 bool exit_choice = 0;

 cout << "\tSimple Tools APP\n";
 cout << "\t================\n ";
 do {
   cout << menu();
   cout << "\n\nWhat do you want to do? <Type from 1 to 6>: ";
   cin >> choice;
   cout << choice;

   switch(choice){
    case 1:
     cout << "Sum of two value";
     break;
    case 2:
     cout << "Factorial of a number";
     break;
    case 3:
     cout << "Table of a number"; 
     break;
    case 4:
     cout << "Even number from min to max";
     break;
    case 5:
     cout << "Prime number";
     break;
    default: 
     exit_choice = 1;
     cout << "\nThank your for using this app.";
   }
 } while(!exit_choice);

 return 0;
}
