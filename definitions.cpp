#include "definitions.h"

Symbol::Symbol(char sym, Location loc, SymbolType type) : sym(sym), loc(loc), type(type) {}

Term::Term(Str_Expr str, LocationMap loc_map)
{
    S_Expr s_expr;
    SymbolType type;
    LocationMap::iterator it = loc_map.begin();

    for (char &sym : str)
    {
        switch (sym)
        {
        case '(':
            type = Application;
            break;
        case '[':
            type = Abstraction;
        default:
            type = Variable; // note: only one-char variables allowed
            break;
        }

        if (it != end(loc_map))
        {
            ++it;
        }
        else
        {
            // implies (len(str) != len(loc_map)) => fail
        }

        s_expr.push_back(Symbol(sym, *it, type));
    }
}

// Term::print()
// {
//     std::string str;

//     for (Symbol &sym : s_expr)
//     {
      
//     }
// }