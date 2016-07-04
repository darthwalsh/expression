#pragma once

#include <string>
#include <regex>

#include "expression.hpp"

class parser {
  public: 
  parser();
  expression* parse(const std::string& s);
  
  private:
  std::string ops;
  std::regex pattern;

  expression* helper(std::sregex_iterator& matches);
};
