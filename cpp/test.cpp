#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 

#include "parser.hpp"

using namespace std;

int main() {
  ifstream test("..\\test.txt");
  
  parser p;
  string e;
  string ans;
  while (getline(test, e)) {
    getline(test, ans);
    int expected = atoi(ans.c_str() + 1);
    expression* exp = p.parse(e);
    if (exp == NULL)
    {
      cerr << "No parse for \"" << e << '"' << endl;
      exit(1);
    }

    int actual = exp->evaluate();
    delete exp;

    cout << e;
    
    if (expected != actual)
    {
      cerr << " " << expected <<  " != " << actual << endl;
      exit(1);
    }

    cout << " = " << expected << endl;
    getline(test, e);
  }

  cout << "test succeeded" << endl;
}