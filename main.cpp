#include <iostream>
#include <set>
#include "include/Definitions.h"
#include "include/VarAnalysis.h"
#include "include/Examples.h"

int main()
{
    Term constant_y(lambda_x_xy, map_lambda_x_xy);
    std::string constant_y_string = constant_y.getAsString();
    std::cout << constant_y_string << std::endl;
    // VarAnalysis va(constant_y);
    // Vars res = va.getResults();

    // std::cout << "FV={";

    // for (const char &var : res.first)
    // {
    //     std::cout << var;
    // }
    // std::cout << "}, ";

    // std::cout << "BV={";

    // for (const char &var : res.second)
    // {
    //     std::cout << var;
    // }
    // std::cout << "}" << std::endl;

    return 0;
}