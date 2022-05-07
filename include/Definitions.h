/* list definition of lambda terms */
/* author: jonas lingg */
#pragma once

#include <string>
#include <vector>
#include <utility>

/* first component is list index, second is position of closing parenthesis */
using Location = std::pair<int, int>;

enum SymbolType
{
    Variable,         /*  "x" */
    OpenApplication,  /*  "(" */
    OpenAbstraction,  /*  "[" */
    CloseAbstraction, /*  "]" */
    CloseApplication  /*  ")" */
};

class Symbol
{
public:
    Symbol(){};
    Symbol(char sym, Location loc, SymbolType type);
    ~Symbol(){};

    std::string getAsString();
    Location getLocation();
    SymbolType getSymbolType();
    void shiftLocation(int left); // TODO delete or make private

private:
    char symbol;
    Location location;
    SymbolType type;
};

/* symbolic representation of a term */
using SymbolicExpression = std::vector<Symbol>;
using StringExpression = std::string;
using LocationMap = std::vector<Location>;

class Term
{
public:
    Term(StringExpression string_expression, LocationMap location_map); // TODO assert : len(str) == length(loc_map)
    ~Term(){};
    std::string getAsString();
    void print();

private:
    SymbolicExpression symbolic_expression;

    void initializeSymbolicExpression(StringExpression string_expression, LocationMap location_map);
};
