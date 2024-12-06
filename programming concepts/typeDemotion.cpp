//Type demotion is the process of converting a value from a higher precision or larger data type to a lower precision or smaller 
//data type. This can lead to loss of data or precision and should be handled carefully to avoid unintended consequences in your
// programs.
#include<iostream>
using namespace std;
int main(){
  double i = 22.7;
  int d = i; // type demotion: double to int
  cout << d << endl ; // 22

  float f = 5.5;
  int j = 2;
  float result = f / j;  // Type demotion: int to float
  cout << result << endl; // 2.75

  cout << sizeof(char) << " " << sizeof(short) << endl; // 1 2
  short s = 65; 
  char t = s; //short to char
  cout << t; // A


}