#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

int main() {
  cout << "Classes" << endl;
  Media* media = new Media();
  cout << media->geti() << endl;
}
