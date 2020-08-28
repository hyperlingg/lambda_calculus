#include "VarAnalysis.h"
#include <algorithm>

S_Expr getSubExpr(S_Expr s_expr, int left, int right)
{
    S_Expr sub_s_exp;
    int delta = s_expr.at(left).getLocation().first;
    Symbol mod_sym;

    for (int i = left; i <= right; i++)
    {
        std::cout << "count: " << i << " : " << s_expr.at(i).getSym() << std::endl;
        mod_sym = s_expr.at(i);
        mod_sym.shiftLocation(delta);
        std::cout << "new location: " << mod_sym.getLocation().first << " , " << mod_sym.getLocation().second << std::endl;
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

    std::cout << "s_expr size :" << s_expr.size() << std::endl;

    if (s_expr.empty())
    {
        return {vars.first, vars.second};
    }
    else
    {
        S_Expr vleft, vright, app_vright;
        Symbol first_sym = s_expr.at(0);
        Symbol second_sym;
        int open_left, close_left, open_right, close_right, app_open_right, app_close_right;
        char var, bound_var;
        bool is_in;

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

            vleft = getSubExpr(s_expr, open_left, close_left);
            vright = getSubExpr(s_expr, open_right, close_right);

            std::cout << "OpenApplication" << std::endl;
            std::cout << "vleft size: " << vleft.size() << " : vright size: " << vright.size() << std::endl;
            std::cout << "open_right: " << open_right << " close_right " << close_right << std::endl;

            vars = pairwise_merge(analyze(vleft, vars), analyze(vright, vars));
            break;

        case OpenAbstraction:
            second_sym = s_expr.at(1);
            bound_var = second_sym.getSym().at(0);

            vars.second.insert(bound_var);
            vars.first.erase(bound_var);

            app_open_right = s_expr.at(2).getLocation().first;
            app_close_right = s_expr.at(2).getLocation().second;
            app_vright = getSubExpr(s_expr, app_open_right, app_close_right);

            std::cout << "OpenAbstraction" << std::endl;
            std::cout << "Bound var: " << bound_var << std::endl;
            std::cout << "app_vright size: " << app_vright.size() << std::endl;

            vars = analyze(app_vright, vars);
            break;

        case Variable:
            var = first_sym.getSym().at(0);
            std::cout << "Variable " << var;

            if (vars.second.find(var) == vars.second.end())
            {
                std::cout << " is free";
                vars.first.insert(var);
            }

            std::cout << std::endl;

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
