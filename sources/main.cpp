// Copyright 2020 Your Name <your_email>

#include "boost/filesystem.hpp"
#include "iomanip"
#include "iostream"
#include "regex"
#include "parser.hpp"
int main(int argc, char *argv[]) {
  std::string path;

  if (argc == 1) {
    path = ".";

  } else {
    path = argv[1];
  }

  parserOfDir parser(path);
  parser.assembleFilesForAcc();
  std::cout<<parser.printFormatted(parser.printAllFiles());
}
