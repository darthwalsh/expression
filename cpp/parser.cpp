#include "parser.hpp"

using namespace std;

parser::parser()
: ops("-+*/^%"), pattern("-?\\d+|[-+*/^%]| ")
{ }

expression* parser::parse(const string& s) 
{
  sregex_iterator matches(s.begin(), s.end(), pattern);
  expression* parse = helper(matches);
  if (matches == sregex_iterator())
  {
    return parse;
  }

  return NULL;
}

expression* parser::helper(sregex_iterator& matches)
{
  while (matches->str() == " ")
  {
    ++matches;
  }
  const string& s(matches->str());
  ++matches;
  
  if (ops.find(s) != string::npos)
  {
    expression* left = helper(matches);
    expression* right = helper(matches);
    switch(s[0]) {
      case '+': return new sum(left, right);
      default: throw invalid_argument(s);
    }
  }
  
  return new constant(stoi(s));
}
