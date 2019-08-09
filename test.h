#include <array>
#include <string>
#include <vector>

void change(int &i) { i = 12; }

void change(bool &b) { b = false; }

void change(std::string &s) { s = "changed"; }

void change(std::array<int, 1> &arr) { arr[0] = 0; }

void change(std::vector<int> &vect) { vect.push_back(1); }
