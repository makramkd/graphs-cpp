#include <iostream>
#include "edge.h"

int main() {
    edge<std::string, std::string> e;
    e.v1 = "hello";
    e.v2 = "world";
    e.weight = "hahaha";
}