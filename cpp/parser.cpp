#include "parser.hpp"

using namespace std;

parser::parser()
: ops("-+*/^%"), pattern("-?\\d+|[-+*/^%]")
{ }

struct parser::result {
  size_t end;
  expression* e;
};

expression* parser::parse(const string& s) 
{
  smatch matches;
  if (regex_match(s, matches, pattern))
  {
    result parse = helper(matches, 0);
    if (parse.end != matches.size())
    {
      return parse.e;
    }
  }

  return NULL;
}

parser::result parser::helper(smatch matches, size_t i)
{
  const string& s = matches[i].str();
  
  if (ops.find(s) != string::npos)
  {
    result left = helper(matches, i + 1);
    result right = helper(matches, left.end);
    expression* e;
    switch(s[0]) {
      case '+': e = new sum(left.e, right.e); break;
      default: throw invalid_argument(s);
    }
    return { right.end, e };
  }
  
  return { i + 1, new constant(stoi(s)) };
}
