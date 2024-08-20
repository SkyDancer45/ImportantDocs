

#include <iostream>
#include <string>
#include <unordered_map>

using marksMap = std::unordered_map<std::string, int>;
using marksMapiter = marksMap::const_iterator;

int main(int argc, char *argv[]) {
  marksMap marks;
  marks["Alex"] = 45;
  marks["Bethany"] = 42;

  for (marksMapiter itr = marks.begin(); itr != marks.end(); itr++) {

    auto &key = itr->first;
    auto &value = itr->second;
    std::cout << key << "is key of " << value << std::endl;
    ;
  }
  return 0;
}
