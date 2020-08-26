#include <iostream>
#include "definitions.h"
#include "examples.h"

int main()
{
    Term identity(lambda_x_x, map_lambda_x_x);
    identity.print();

    Term constant_y(lambda_x_xy, map_lambda_x_xy);
    constant_y.print();
    
    return 0;
}