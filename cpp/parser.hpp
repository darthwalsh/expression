#pragma once

#include <string>
#include <regex>

#include "constant.hpp"
#include "sum.hpp"

class parser {
  public: 
  parser();
  expression* parse(const std::string& s);
  
  private:
  std::string ops;
  std::regex pattern;

  struct result;
  result helper(std::smatch matches, size_t i);
};
