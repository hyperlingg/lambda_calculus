#include <iostream>
#include "definitions.h"

int main()
{
    Term lambda_x_xy = Abstraction(Variable("x"), Application(Variable("x"), Variable("y"))); // lambda x.(xy)
    return 0;
}