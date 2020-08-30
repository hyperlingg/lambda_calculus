#include "../include/Definitions.h"
#include <iostream>

Symbol::Symbol(char sym, Location loc, SymbolType type) : sym(sym), loc(loc), type(type) {}

void Symbol::shiftLocation(int delta)
{
    loc.first = loc.first - delta;
    loc.second = loc.second - delta;
}

Term::Term(Str_Expr str, LocationMap loc_map)
{
    SymbolType type;
    LocationMap::iterator it = loc_map.begin();

    for (char &sym : str)
    {
        switch (sym)
        {
        case '(':
            type = OpenApplication;
            break;
        case '[':
            type = OpenAbstraction;
            break;
        case ']':
            type = CloseAbstraction;
            break;
        case ')':
            type = CloseApplication;
            break;
        default:
            type = Variable; // note: only one-char variables allowed
            break;
        }

        if (it != end(loc_map))
        {
            s_expr.push_back(Symbol(sym, *it, type));
            ++it;
        }
        else
        {
            std::cout << "(len(str) != len(loc_map)) => fail" << std::endl;
        }
    }
}

void Term::print()
{
    std::string str;
    bool openAbstract = false;

    for (Symbol &sym : s_expr)
    {
        std::string temp;

        switch (sym.getSymType())
        {
        case OpenApplication:
            temp = "(";
            break;
        case OpenAbstraction:
            temp = "(lambda ";
            openAbstract = true;
            break;
        case CloseAbstraction:
            temp = ")";
            break;
        case CloseApplication:
            temp = ")";
            break;
        case Variable:
            if (openAbstract) /* this variable is bound */
            {
                temp = sym.getSym() + ".";
                openAbstract = false;
            }
            else
            {
                temp = sym.getSym();
            }
            break;
        default:
            break;
        }
        str.append(temp);
    }

    std::cout << str << std::endl;
}

std::string Symbol::getSym()
{
    std::string str;
    str.push_back(sym);
    return str;
}

SymbolType Symbol::getSymType()
{
    return type;
}

Location Symbol::getLocation()
{
    return loc;
}

S_Expr Term::getSExpr()
{
    return s_expr;
}
