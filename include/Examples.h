/* Examples in a format that would be returned by a simple cmd line parser */
#include "Definitions.h"

/* LocationMap contains the scope of each symbol. */
/* note that closing parentheses do not have meaningful scope. */
Str_Expr lambda_x_xy = "[x(xy)]";
LocationMap map_lambda_x_xy = {{0, 6}, {1, 1}, {2, 5}, {3, 3}, {4, 4}, {5, 5}, {6, 6}};

Str_Expr lambda_xxy = "(x(xy))";
LocationMap map_lambda_xxy = {{0, 6}, {1, 1}, {2, 5}, {3, 3}, {4, 4}, {5, 5}, {6, 6}};

Str_Expr lambda_x_x = "[xx]";
LocationMap map_lambda_x_x = {{0, 3}, {1, 1}, {2, 2}, {3, 3}};

Str_Expr lambda_x_xy_y_xy = "([x(xy)][y(xy)])";
LocationMap map_lambda_x_xy_y_xy = {{0, 15}, {1, 7}, {2, 2}, {3, 6}, {4, 4}, {5, 5},
                                    {6, 6}, {7, 7}, {8, 14}, {9, 9}, {10, 13},
                                    {11, 11}, {12, 12}, {13, 13}, {14, 14}, {15, 15}};