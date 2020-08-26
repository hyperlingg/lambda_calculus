/* list definition of lambda terms */
/* author: jonas lingg */

#include <string>
#include <vector>
#include <utility>

/* first component is list index, second is span (offset to closing parenthesis) */
using Location = std::pair<int, int>;

enum SymbolType
{
    Variable,    /*  "x"  */
    Application, /*  "()" */
    Abstraction  /*  "[]" */
};

class Symbol
{
private:
    char sym;
    Location loc;
    SymbolType type;

public:
    Symbol(char sym, Location loc, SymbolType type);
    ~Symbol(){};
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
};
