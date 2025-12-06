#include <iostream>
#include <cstring>
#include "Items.h"

using namespace std;

void Items::setDescription(const char* desc) {//Adds null terminator because it was cutting out last charecter
  strncpy(description, desc, sizeof(description) - 1);
  description[sizeof(description) - 1] = '\0';
}

char* Items::getDescription() {
  return description;
}

void Items::setName(const char* I) {
    strncpy(name, I, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0'; 
}

char* Items::getName(){
  return name;
}
