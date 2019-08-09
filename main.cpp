#include "test.h"
#include <array>
#include <vector>

struct customType {
public:
  int x;
};

int main() {
  customType type{1};
  std::string string_;
  std::vector<int> vector_ = {0};
  std::array<int, 1> array_ = {1};
  int int_ = static_cast<int>(1.2);
  bool bool_ = true;

  int tmp = 0;

  auto l = [&](int lamdba_param) { int_ = lamdba_param; };

  // change outside current frame
  change(int_);
  change(string_);
  change(bool_);
  change(array_);
  change(vector_);

  // int read
  tmp = int_;

  // bool read
  tmp = (int)bool_;

  // array read
  tmp = array_[0];
  // array write
  array_[0] = 2;

  // vector read
  tmp = vector_.size();
  // vector write
  vector_.push_back(1);

  // string read
  tmp = string_.length();
  // string write
  string_ = "new string";

  // custom read
  tmp = type.x;
  // custom write
  type.x = 2;

  l(12);
  return 0;
}
