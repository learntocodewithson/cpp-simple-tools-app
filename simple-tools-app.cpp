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

 bool isEven(int n){
  return (n % 2 == 0);
 }

 public:
  string menu(){
   return "\n1.) Sum of two values\n2.) Factorial of a number\n3.) Table of a number\n4.) Even number from min to max value\n5.) Prime number\n6.) Sum of numbers when prime number is found\n7.) Guess odd or even number\n8.) Reverse a string\n9.) List students by grade\n10.) Exit";
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

  string tableOfANumber(int num1){
   string table;

   for(int i = 1; i <= 10; i++){
    table += to_string(num1) + " x " + to_string(i) + " = " + to_string((num1 * i)) + "\n";
   }

   return table;
  }

  string evenNumberFromMinMax(int min, int max){
   string even_number_display;

   for(int i = min; i <= max; i++){
    if(isEven(i)){
     even_number_display += to_string(i) + " ";
    }
   }

   return even_number_display;
  }

  string primeNumberDisplay(int num1){
   if(primeNumber(num1))
    return "Prime Number";
   else
    return "Not a Prime Number";
  }

  int sumOfTwoValue(int num1, int num2){
   return num1 + num2;
  }

  bool primeNumber(int num1){
   string result_message;
    if (num1 <= 1)
     return false;
    if (num1 <= 3)
     return true;
    if (num1 % 2 == 0 || num1 % 3 == 0)
     return false;
    for (int i = 5; i * i <= num1; i += 6) {
      if (num1 % i == 0 || num1 % (i + 2) == 0)
         return false;
    }

    return true;
  }

  string oddOrEven(int n){
   if(isEven(n)){
     return "Even";
   } else {
     return "Odd";
   }
  }

  string reverseAString(string str){
   int str_length = str.length();
   string reverseString;
   
   for(int i = (str_length - 1); i >= 0; i--){
    reverseString += str[i];
   }

   return reverseString;
  }
 

};

struct Student {
 string name;
 int grade;
};

void sumOfTwoValue(Tools &tools);
void factorial(Tools &tools);
void tableOfANumber(Tools &tools);
void evenNumberFromMinMax(Tools &tools);
void primeNumber(Tools &tools);
void sumOfNumbersWhenPrimeNumberIsFound(Tools &tools);
void guessOddOrEvenNumber(Tools &tools);
void reverseAString(Tools &tools);
void listStudentsByGrade(Tools &tools);
void studentsSort(Student arr[], int size, string asc_desc);

int main(){
 Tools tools; 
 int choice;
 bool exit_choice = 0;

 cout << tools.displayTitle();
 do {
   cout << tools.menu();
   cout << "\n\nWhat do you want to do? <Type from 1 to 10>: ";
   cin >> choice;

   switch(choice){
    case 1:
     sumOfTwoValue(tools);
     break;
    case 2:
     factorial(tools);
     break;
    case 3:
     tableOfANumber(tools);
     break;
    case 4:
     evenNumberFromMinMax(tools);
     break;
    case 5:
     primeNumber(tools);
     break;
    case 6:
     sumOfNumbersWhenPrimeNumberIsFound(tools);
     break;
    case 7:
     guessOddOrEvenNumber(tools);
     break;
    case 8:
     reverseAString(tools);
     break;
    case 9:
     listStudentsByGrade(tools);
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
 cout << "\nSum of Two Values";
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

void tableOfANumber(Tools &tools){
  system("clear");
 
  int num1;
  cout << tools.displayTitle();
  cout << "\nTable of a number";
  cout << "\nEnter base number: ";
  cin >> num1;

  cout << endl << tools.horizontalLine();
  cout << tools.tableOfANumber(num1);
  cout << tools.horizontalLine() << endl;
}

void evenNumberFromMinMax(Tools &tools){
 system("clear");

 int min, max;
 cout << tools.displayTitle();
 cout << "\nEven number from min to max";
 cout << "\nEnter starting point: ";
 cin >> min;
 cout << "Enter end point: ";
 cin >> max;

 cout << tools.evenNumberFromMinMax(min, max);
}

void primeNumber(Tools &tools){
 system("clear");

 int num1 = 0;
 cout << tools.displayTitle();
 cout << "\nPrime number";
 cout << "\nEnter a number: ";
 cin >> num1;

 cout << endl << tools.horizontalLine();
 cout << endl << tools.primeNumberDisplay(num1) << endl;
 cout << tools.horizontalLine() << endl;
}

void sumOfNumbersWhenPrimeNumberIsFound(Tools &tools){
 system("clear");

 int num1 = 0;
 int sum = 0;
 cout << tools.displayTitle();
 cout << "\nSum of numbers when prime number is found\n";

 while(!tools.primeNumber(num1)){
  sum += num1;

  cout << "Enter a number: ";
  cin >> num1;
 }

 cout << endl << tools.horizontalLine();
 cout << endl << "Found PRIME NUMBER " + to_string(num1) + ".\nThe sum of previous inputs is " << sum << "." << endl;
 cout << tools.horizontalLine() << endl;
}

void guessOddOrEvenNumber(Tools &tools){
  system("clear");

  int num1 = 0;
  cout << tools.displayTitle();
  cout << "\nGuess Odd or Even Number";
  cout << "\nEnter a number: ";
  cin >> num1;

  cout << endl << tools.horizontalLine();
  cout << endl << num1 << " is " + tools.oddOrEven(num1) << endl;
  cout << tools.horizontalLine() << endl;
}

void reverseAString(Tools &tools){
  system("clear");

  string str;
  cout << tools.displayTitle();
  cout << "\nReverse a string";
  cout << "\nEnter a string: ";
  cin >> str;
  
  cout << endl << tools.horizontalLine();
  cout << endl << "The Reverse of " << str << " is " + tools.reverseAString(str) << endl;
  cout << tools.horizontalLine() << endl;
}

void listStudentsByGrade(Tools &tools){
  system("clear");

  int size = 10;
  Student students[size];
  string asc_desc;

  cout << tools.displayTitle();
  cout << "\nList Students by Grade\n";

  for(int i = 0; i < size; i++){
   cout << "Enter student"<< (i+1) << " name: "; 
   cin >> students[i].name;

   cout <<  "Enter student"<< (i+1) << " grade: ";
   cin >> students[i].grade;

   cout << endl; 
  }

  cout << "Sort by Desc or Asc? <type asc or desc>: ";
  cin >> asc_desc;

  // sort
  if(asc_desc == "asc")
   studentsSort(students, size, "asc");
  else
   studentsSort(students, size, "desc");
  
  cout << endl << "Sort by " << asc_desc << endl;

  for(int i = 0; i < size; i++)
   cout << students[i].name << " - " << students[i].grade << endl;
  
}

void studentsSort(Student arr[], int size, string asc_desc) {
 for (int i = 0; i < size - 1; ++i) {
  for (int j = 0; j < size - i - 1; ++j) {
   bool swap_checker = false;

   if(asc_desc == "asc")
     if (arr[j].grade > arr[j + 1].grade)
      swap_checker = true;
   
   if (asc_desc == "desc")
    if (arr[j].grade < arr[j + 1].grade)
     swap_checker = true;
   
   if(swap_checker){
     Student temp = arr[j]; 
     arr[j] = arr[j + 1]; 
     arr[j + 1] = temp;
   }

  }
 }
}
