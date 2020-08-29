#include <iostream>
#include <set>
#include "include/Definitions.h"
#include "include/VarAnalysis.h"
#include "include/Examples.h"
int main()
{
    Term identity(lambda_x_x, map_lambda_x_x);
    identity.print();

    Term constant_y(lambda_x_xy, map_lambda_x_xy);
    constant_y.print();

    Term application(lambda_xxy, map_lambda_xxy);
    application.print();

    Term complex_application(lambda_x_xy_y_xy, map_lambda_x_xy_y_xy);
    complex_application.print();

    VarAnalysis va(constant_y);
    Vars res = va.getResults();

    std::cout << "FV={";

    for (const char &var : res.first)
    {
        std::cout << var;
    }
    std::cout << "}" << std::endl;

    std::cout << "BV={";

    for (const char &var : res.second)
    {
        std::cout << var;
    }
    std::cout << "}" << std::endl;

    return 0;
}