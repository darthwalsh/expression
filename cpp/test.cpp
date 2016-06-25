#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 

#include "expression.hpp"
#include "constant.hpp"
#include "sum.hpp"

using namespace std;

int main() {
  constant* c2 = new constant(2);
  constant* c3 = new constant(3);
  sum s(c2, c3);
  cout << s.evaluate() << endl;
  

  ifstream test("..\\test.txt");
  
  string e;
  string ans;
  while (getline(test, e)) {
    getline(test, ans);
    int expected = atoi(ans.c_str() + 1);

    cout << e << " = " << expected << endl;
    getline(test, e);
  }

  cout << "test succeeded" << endl;
}