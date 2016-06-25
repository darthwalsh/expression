#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 

using namespace std;

int main() {
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