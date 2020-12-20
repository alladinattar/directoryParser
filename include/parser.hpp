// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include "boost/filesystem.hpp"
#include "string"
#include "map"
#include "account.hpp"
#include "set"

class parserOfDir{
 private:
  std::vector<boost::filesystem::path> files;
  std::set<std::string> accountsStrings;
  std::vector<account> accounts;
 public:
  parserOfDir(std::string pathForParse);
  void assembleFilesForAcc();
  std::stringstream printAllFiles();
  std::string printFormatted(std::stringstream ss);

};
#endif // INCLUDE_HEADER_HPP_
