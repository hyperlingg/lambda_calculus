#include "definitions.h"
/* Examples in a format that would be returned by a simple cmd line parser */

Str_Expr lambda_x_xy = "[x(xy)]";
LocationMap map_lambda_x_xy = {{0, 4}, {1, 1}, {2, 4}, {3, 3}, {4, 4}};

Str_Expr lambda_x_x = "[xx]";
LocationMap map_lambda_x_x = {{0, 3}, {1, 1}, {2, 2}, {3, 0}};