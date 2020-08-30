#include "../include/VarAnalysis.h"
#include <algorithm>

S_Expr getSubExpr(S_Expr s_expr, int left, int right)
{
    S_Expr sub_s_exp;
    int delta = s_expr.at(left).getLocation().first;
    Symbol mod_sym;

    for (int i = left; i <= right; i++)
    {

        mod_sym = s_expr.at(i);
        mod_sym.shiftLocation(delta);
        sub_s_exp.push_back(mod_sym);
    }

    return sub_s_exp;
}

Vars pairwise_merge(Vars left, Vars right)
{
    std::set<char> lset;
    std::merge(left.first.begin(), left.first.end(),
               right.first.begin(), right.first.end(),
               std::inserter(lset, lset.begin()));

    std::set<char> rset;
    std::merge(left.second.begin(), left.second.end(),
               right.second.begin(), right.second.end(),
               std::inserter(rset, rset.begin()));

    return {lset, rset};
}

Vars analyze(S_Expr s_expr, Vars vars)
{
    if (s_expr.empty())
    {
        return {vars.first, vars.second};
    }
    else
    {
        S_Expr lterm, rterm;
        Symbol first_sym = s_expr.at(0);
        Symbol second_sym;
        int open_left, close_left;
        int open_right, close_right;
        char var;

        switch (first_sym.getSymType())
        {
        case OpenApplication:
            if (s_expr.size() < 2)
            {
                return {{}, {}};
            }

            second_sym = s_expr.at(1);

            open_left = second_sym.getLocation().first;
            close_left = second_sym.getLocation().second;

            open_right = close_left + 1;
            close_right = s_expr.at(open_right).getLocation().second;

            lterm = getSubExpr(s_expr, open_left, close_left);
            rterm = getSubExpr(s_expr, open_right, close_right);

            vars = pairwise_merge(analyze(lterm, vars), analyze(rterm, vars));
            break;

        case OpenAbstraction:
            second_sym = s_expr.at(1);
            var = second_sym.getSym().at(0);

            vars.second.insert(var);
            vars.first.erase(var);

            open_right = s_expr.at(2).getLocation().first;
            close_right = s_expr.at(2).getLocation().second;
            rterm = getSubExpr(s_expr, open_right, close_right);

            vars = analyze(rterm, vars);
            break;

        case Variable:
            var = first_sym.getSym().at(0);

            if (vars.second.find(var) == vars.second.end())
            {
                vars.first.insert(var);
            }

            break;
        default:
            break;
        }
    }
    return vars;
}

VarAnalysis::VarAnalysis(Term term) : term(term)
{
    auto res = analyze(term.getSExpr(), {{}, {}});
    free_vars = res.first;
    bound_vars = res.second;
}

VarAnalysis::~VarAnalysis() {}

std::pair<FreeVars, BoundVars> VarAnalysis::getResults()
{
    return {free_vars, bound_vars};
}
