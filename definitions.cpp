#include "definitions.h"
#include <iostream>

Symbol::Symbol(char sym, Location loc, SymbolType type) : sym(sym), loc(loc), type(type) {}

std::string Symbol::getSym()
{
    std::string str;
    str.push_back(sym);
    return str;
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
            ++it;
        }
        else
        {
            std::cout << "(len(str) != len(loc_map)) => fail" << std::endl;
        }

        s_expr.push_back(Symbol(sym, *it, type));
    }
}

void Term::print()
{
    std::string str;
    bool openAbstract = false;

    for (Symbol &sym : s_expr)
    {

        std::string temp = "";

        switch (sym.type)
        {
        case OpenApplication:
            temp = "(";
            std::cout << "OpenApplication" << std::endl;
            break;
        case OpenAbstraction:
            temp = "(lambda ";
            std::cout << "OpenAbstraction" << std::endl;
            openAbstract = true;
            break;
        case CloseAbstraction:
            temp = ")";
            std::cout << "CloseAbstraction" << std::endl;
            break;
        case CloseApplication:
            temp = ")";
            std::cout << "CloseApplication" << std::endl;
            break;
        case Variable:
            if (openAbstract)
            {
                temp = sym.getSym() + ".";
                std::cout << "Bound Variable" << std::endl;
                openAbstract = false;
            }
            else
            {
                temp = sym.getSym();
                std::cout << "Variable" << std::endl;
            }

            break;
        default:
            break;
        }
        std::cout << temp << std::endl;
        str.append(temp);
    }

    std::cout << str << std::endl;
}