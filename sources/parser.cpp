//
// Created by rinat on 12/18/20.
//
#include "parser.hpp"

#include "boost/filesystem.hpp"
#include "iomanip"
#include "iostream"
#include "regex"
parserOfDir::parserOfDir(std::string pathForParse) {
  const std::regex regularExp(
      "^(balance_)\\d\\d\\d\\d\\d\\d\\d\\d_\\d\\d\\d\\d\\d\\d\\d\\d");

  const boost::filesystem::path pathObj{pathForParse};
  if (boost::filesystem::exists(pathObj)) {
    for (auto itEntry =
             boost::filesystem::recursive_directory_iterator(pathObj);
         itEntry != boost::filesystem::recursive_directory_iterator();
         ++itEntry) {
      if (boost::filesystem::is_regular_file(itEntry->path())) {
        if ((itEntry->path().stem().extension() == "")) {
          if (itEntry->path().extension() == ".txt") {
            if (std::regex_search(itEntry->path().stem().string(),
                                  regularExp)) {
              files.push_back(itEntry->path());
              accountsStrings.insert(
                  itEntry->path().stem().string().substr(8, 8));
            }
          }
        }
      }

      if (boost::filesystem::is_symlink(itEntry->path())) {
        for (auto itEntrySymLink =
                 boost::filesystem::recursive_directory_iterator(
                     itEntry->path());
             itEntrySymLink !=
             boost::filesystem::recursive_directory_iterator();
             ++itEntrySymLink) {
          if (boost::filesystem::is_regular_file(itEntry->path())) {
            if ((itEntry->path().stem().extension() == "")) {
              if (itEntry->path().extension() == ".txt") {
                if (std::regex_search(itEntry->path().stem().string(),
                                      regularExp)) {
                  files.push_back(itEntry->path());
                  accountsStrings.insert(
                      itEntry->path().stem().string().substr(8, 8));
                }
              }
            }
          }
        }

        /*const auto filenameStr = itEntry->path().filename().string();
        std::cout<<filenameStr<<std::endl;*/
      }
    }
  }
}

std::stringstream parserOfDir::printAllFiles() {
  std::stringstream ss;
  for (auto file : files) {
    ss << file.parent_path().filename().string() << " "
              << file.filename().string() << std::endl;
  }
  return ss;
}

std::string parserOfDir::printFormatted(std::stringstream ss) {
  for (auto acc : accounts){
    ss<<"broker:"<<acc.getBrocker()<<" "<<"account:"<<
    acc.getAccountNum()<<" "<<"files:"<<acc.getFileSum()<<
    " "<<"lastdate:"<<acc.getLastDate()<<std::endl;
  }
  return ss.str();
}


void parserOfDir::assembleFilesForAcc() {
  for (auto acc : accountsStrings) {
    account tempAcc;
    tempAcc.setAccountNumber(acc);
    int lastDate = 0;
    for (auto file : files) {
      if (file.filename().string().substr(8, 8) == acc) {

        tempAcc.incFilesSum();
        tempAcc.addFile(file);
        tempAcc.setBrocker(file.parent_path().filename().string());
        if (std::stoi(file.filename().stem().string().substr(17, 8)) > lastDate) {
          lastDate = std::stoi(file.filename().stem().string().substr(17, 8));
        }
      }
    }
    tempAcc.setLastDate(lastDate);
     accounts.push_back(tempAcc);

  }

}
