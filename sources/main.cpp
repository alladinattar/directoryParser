// Copyright 2020 Rinat <rinamuka4@gmail.com>


#include "iostream"
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
  std::cout<<parser.printFormatted();
}
