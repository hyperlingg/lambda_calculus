/* Examples in a format that would be returned by a simple cmd line parser */
#include "definitions.h"

/* LocationMap contains the scope of each symbol. */
/* note that closing parentheses do not have meaningful scope. */
Str_Expr lambda_x_xy = "[x(xy)]";
LocationMap map_lambda_x_xy = {{0, 6}, {1, 1}, {2, 5}, {3, 3}, {4, 4}, {5, 5}, {6, 6}};

Str_Expr lambda_x_x = "[xx]";
LocationMap map_lambda_x_x = {{0, 3}, {1, 1}, {2, 2}, {3, 3}};