#include "FileLib.hpp"
#include <sstream>
#include <fstream>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim))
  {
    elems.push_back(item);
  }
  return elems;
}


std::vector<std::string> split(const std::string &s, char delim)
{
  std::vector<std::string> elems;
  split(s, delim, elems);
  return elems;
}

std::string getFileContents(const std::string &filename)
{
  std::ifstream myfile;
  myfile.open(filename.c_str());
  std::string s;
  s.assign(std::istreambuf_iterator<char>(myfile), std::istreambuf_iterator<char>());
  myfile.close();
  return s;
}
