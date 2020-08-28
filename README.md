# lambda_calculus
list-based lambda calculus implementation.

example terms: 

[x(xy)] = (lambda x. (xy))

[xx]   = (lambda x. x)

On the left the internal symbolic representation, on the right the conventional term representation (as we would want to read cmd line input). The parentheses of the symbolic representation "know" their span (position of closing parenthesis). Although a list is used to represent lambda terms, it is better to think of it as an in-place tree.

# Input
A command line parser is assumed: For every term (lambda x. ((xy)z)) it generates the corresponding internal representation [x((xy)z)] and a list of tuples
[{0,9},{1,1},{2,8},{3,6},{4,4},{5,5},{6,6},{7,7},{8,8},{9,9}]. Each tuple contains as first field the position of the symbol it describes and as second field the position of the corresponding closing symbol, e.g. {0,9} means that the opening "[" corresponds to the "]" on the ninth position of the term.

## Features

* printing internal representation as conventional lambda term

## In progress

* Variable analysis: set of free and bound variables for a term, e.g. for (lambda x. x), FV={} and BV={x}.
