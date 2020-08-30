#define BOOST_TEST_MODULE definitions_test
#include <boost/test/unit_test.hpp>

#include "../include/Definitions.h"
#include <iostream>

int add(int i, int j)
{
    Symbol sym;
    std::cout << "symbol:" << sym.getSym() << std::endl;
    return i + j;
}

BOOST_AUTO_TEST_CASE(universeInOrder)
{
    BOOST_CHECK(add(2, 2) == 4);
}