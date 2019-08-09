#include <iostream>
#include <array>
#include <vector>
#include "test.h"

struct customType {
public:
    int x;
};

int main() {
    customType type{1};
    std::string string;
    std::vector<int> vector;
    std::array<int, 1> array = {1};
    int int_ = static_cast<int>(1.2);
    bool bool_ = true;

    int tmp = 0;

    auto l = [&](int lamdba_param) {
        int_ = lamdba_param;
    };

    // change outside current frame
    change(int_);
    change(string);

    // int read
    tmp = int_;

    // bool read
    tmp = (int) bool_;

    // array read
    tmp = array[0];
    // array write
    array[0] = 2;

    // vector read
    tmp = vector.size();
    // vector write
    vector.push_back(1);

    // string read
    tmp = string.length();
    // string write
    string = "new string";

    // custom read
    tmp = type.x;
    // custom write
    type.x = 2;

    l(12);
    return 0;
}

