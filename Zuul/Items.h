#ifndef Items
#define Items
#include <iostream>
#include <cstring>

using namespace std;

class Items {
 public:
  void  getDescription();
  void  setDescription(const char* desc);
 private:
   char description[20] = "Itemdesc";
};
#endif
