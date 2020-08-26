# lambda_calculus
list-based lambda calculus implementation. Assumes a commandline parser.

example terms: 

[x(xy)] = (lambda x. (xy))

[xx]   = (lambda x. x)

On the left the internal symbolic representation, on the right the conventional term representation (as we would want to read cmd line input). The parentheses of the symbolic representation "know" their span (offset to the end of scope). Although a list is used to represent lambda terms, it is better to think of it as an in-place tree.

## Features

* printing internal representation as conventional lambda term

## In progress

* Variable analysis: set of free and bound variables for a term, e.g. for (lambda x. x), FV={} and BV={x}.
