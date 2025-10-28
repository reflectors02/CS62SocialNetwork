#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "user.h"
#include "network.h"

using namespace std;

int main() {
  Network net;
  net.readUsers("cycle5.txt");

  int to;
  vector<int> path = net.distanceUser(2,to,3);
  assert(to == -1);
  assert(path.size() == 0);
  return 0;
}