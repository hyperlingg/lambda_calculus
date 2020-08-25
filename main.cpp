#include <iostream>
#include "definitions.h"

std::string dump(Variable var)
{
    return var.getName();
}

int main()
{
    Variable x = Variable("x");
    Variable *pnt_x = &x;
    std::cout << dump(x) << std::endl;
    
    return 0;
}