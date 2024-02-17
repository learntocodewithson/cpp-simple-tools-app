#include<iostream>
#include<string>
using namespace std;

class Tools {
 int factorial(int n){
  if(n == 0){
   return 1;
  }else{
   return n * factorial(n-1);
  }
 }

 public:
  string menu(){
   return "\n1.) Sum of two value\n2.) Factorial of a number\n3.) Table of a number\n4.) Even number from min to max value\n5.) Prime number\n6.) Exit";
  }

  string horizontalLine(){
   return "====================================";
  }

  string displayTitle(){
   return "\tSimple Tools APP\n" + horizontalLine();
  }

  string getFactorial(int num1){
   return to_string(factorial(num1));
  }

  string displayFactorialProcess(int num1){
   string factorial_display = to_string(num1) + "! = ";
   
   for(int i = num1; i >= 1; i--){
    if(i != 1){
     factorial_display += to_string(i) + " x ";
    }else{
     factorial_display += to_string(i) + " = ";
    }
   }
   
   return factorial_display;
  }

  int sumOfTwoValue(int num1, int num2){
   return num1 + num2;
  }
 

};

void sumOfTwoValue(Tools &tools);
void factorial(Tools &tools);

int main(){
 Tools tools; 
 int choice;
 bool exit_choice = 0;

 cout << tools.displayTitle();
 do {
   cout << tools.menu();
   cout << "\n\nWhat do you want to do? <Type from 1 to 6>: ";
   cin >> choice;

   switch(choice){
    case 1:
     sumOfTwoValue(tools);
     break;
    case 2:
     factorial(tools);
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

void sumOfTwoValue(Tools &tools){
 system("clear");

 int num1, num2;
 cout << tools.displayTitle();
 cout << "\nSum of Two Value";
 cout << "\nEnter first number: ";
 cin >> num1;
 cout << "Enter second number: ";
 cin >> num2;

 cout << endl << tools.horizontalLine();
 cout << "\nThe sum of " << num1 << " and " << num2 << " is " << tools.sumOfTwoValue(num1, num2) << ".\n";
 cout << tools.horizontalLine() << endl;
}

void factorial(Tools &tools){
 system("clear");

 int num1;
 cout << tools.displayTitle();
 cout << "\nFactorial of a number";
 cout << "\nEnter first number: ";
 cin >> num1;

 cout << endl << tools.horizontalLine() << endl;
 cout << tools.displayFactorialProcess(num1) << tools.getFactorial(num1);
 cout << endl << tools.horizontalLine() << endl;
}
