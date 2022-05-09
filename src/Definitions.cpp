#include "../include/Definitions.h"
#include <iostream>

Symbol::Symbol(char sym, Location loc, SymbolType type) : symbol(sym), location(loc), type(type) {}

void Symbol::shiftLocation(int delta)
{
    location.first = location.first - delta;
    location.second = location.second - delta;
}

Term::Term(StringExpression string_expression, LocationMap location_map)
{
    initializeSymbolicExpression(string_expression, location_map);
}

std::string Term::getAsString()
{
    std::string str;
    bool openAbstract = false;

    for (Symbol &sym : symbolic_expression)
    {
        std::string temp;

        switch (sym.getSymbolType())
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
                temp = sym.getAsString() + ".";
                openAbstract = false;
            }
            else
            {
                temp = sym.getAsString();
            }
            break;
        default:
            break;
        }
        str.append(temp);
    }

    return str;
}

std::string Symbol::getAsString()
{
    std::string str(1, symbol);
    return str;
}

SymbolType Symbol::getSymbolType()
{
    return type;
}

Location Symbol::getLocation()
{
    return location;
}

void Term::initializeSymbolicExpression(StringExpression string_expression, LocationMap location_map)
{
    SymbolType type;
    LocationMap::iterator it = location_map.begin();

    for (char &sym : string_expression)
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

        if (it != end(location_map))
        {
            symbolic_expression.push_back(Symbol(sym, *it, type));
            ++it;
        }
        else
        {
            std::cout << "(len(str) != len(loc_map)) => fail" << std::endl;
        }
    }
}

SymbolicExpression Term::getSymbolicExpression()
{
    return symbolic_expression;
}