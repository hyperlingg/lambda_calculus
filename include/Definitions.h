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
private:
    char sym;
    Location loc;
    SymbolType type;

public:
    Symbol(){};
    Symbol(char sym, Location loc, SymbolType type);
    ~Symbol(){};
    std::string getSym();
    Location getLocation();
    SymbolType getSymType();
    void shiftLocation(int left);
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
    S_Expr getSExpr();
    char getBoundVariable(Symbol sym); // assert : sym.getSymType() == OpenAbstraction
};
