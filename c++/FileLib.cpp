#include "FileLib.hpp"
#include <fstream>

std::string getFileContents(const std::string &filename)
{
  std::ifstream myfile;
  myfile.open(filename.c_str());
  std::string s;
  s.assign(std::istreambuf_iterator<char>(myfile), std::istreambuf_iterator<char>());
  myfile.close();
  return s;
}
