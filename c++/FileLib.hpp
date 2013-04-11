#ifndef FILELIB_HPP
#define FILELIB_HPP

#include <string>
#include <vector>

std::string getFileContents(const std::string &filename);
std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

#endif
