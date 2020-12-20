
#include "boost/filesystem.hpp"
#include "iostream"
class account {
 private:
  std::string brocker;
  std::string accountNumber;
  std::vector<boost::filesystem::path> files;
  size_t filesSum = 0;
  int lastDate;

 public:
  void addFile(boost::filesystem::path);
  void incFilesSum();
  void setLastDate(int);
  void setBrocker(std::string);
  void setAccountNumber(std::string);
  std::string getBrocker();
  std::string getAccountNum();
  std::size_t getFileSum();
  int getLastDate();
};