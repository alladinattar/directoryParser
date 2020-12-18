// Copyright 2020 Your Name <your_email>

#include <parser.hpp>
#include "boost/filesystem.hpp"
#include "iostream"

int main(int argc, char *argv[]) {
  std::string path;
  if (argc == 1) {
    path = ".";

  } else {
    path = argv[1];
  }
  const boost::filesystem::path pathObj{path};

  for (const boost::filesystem::directory_entry& x : boost::filesystem::directory_iterator{pathObj})
  {
    if (boost::filesystem::is_directory(x)){

    }
  }
}