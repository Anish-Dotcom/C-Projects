#include <iostream>
#include <cstring>
#include "Items.h"

using namespace std;

void Items::setDescription(const char* desc) {
  strcpy(description, desc);
}

char* Items::getDescription() {
  return description;
}

void Items::setName(const char* I) {
  strcpy(name,I);
}

char* Items::getName(){
  return name;
}
