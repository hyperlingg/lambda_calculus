/* list definition of lambda terms */
/* author: jonas lingg */
#pragma once

#include <string>
#include <vector>
#include <utility>

/* first component is list index, second is span (offset to closing parenthesis) */
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
private:
    char sym;
    Location loc;

public:
    SymbolType type;
    Symbol(char sym, Location loc, SymbolType type);
    ~Symbol(){};
    std::string getSym();
};

/* symbolic representation of a term */
using S_Expr = std::vector<Symbol>;
using Str_Expr = std::string;
using LocationMap = std::vector<Location>;

class Term
{
private:
    S_Expr s_expr;

public:
    Term(Str_Expr str, LocationMap loc_map); // assert : len(str) == length(loc_map)
    ~Term(){};
    void print();
    int expandedSize();
};
