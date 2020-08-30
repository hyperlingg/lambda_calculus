#define BOOST_TEST_MODULE lambda_test
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

#include "../include/Definitions.h"
#include "../include/VarAnalysis.h"
#include "../include/Examples.h"

#include <iostream>

Term identity(lambda_x_x, map_lambda_x_x);

Term constant_y(lambda_x_xy, map_lambda_x_xy);

Term application(lambda_xxy, map_lambda_xxy);

Term complex_application(lambda_x_xy_y_xy, map_lambda_x_xy_y_xy);

// redirecting cout to output_test_stream 
// source: https://stackoverflow.com/a/5405268
struct cout_redirect
{
    cout_redirect(std::streambuf *new_buffer)
        : old(std::cout.rdbuf(new_buffer))
    {
    }

    ~cout_redirect()
    {
        std::cout.rdbuf(old);
    }

private:
    std::streambuf *old;
};


BOOST_AUTO_TEST_SUITE(PrintingSuite)

BOOST_AUTO_TEST_CASE(identity_print)
{
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());

        identity.print();
    }

    BOOST_CHECK(output.is_equal("(lambda x.x)\n"));
}

BOOST_AUTO_TEST_CASE(constant_y_print)
{
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());

        constant_y.print();
    }

    BOOST_CHECK(output.is_equal("(lambda x.(xy))\n"));
}

BOOST_AUTO_TEST_CASE(application_print)
{
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());

        application.print();
    }

    BOOST_CHECK(output.is_equal("(x(xy))\n"));
}

BOOST_AUTO_TEST_CASE(complex_application_print)
{
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());

        complex_application.print();
    }

    BOOST_CHECK(output.is_equal("((lambda x.(xy))(lambda y.(xy)))\n"));
}

BOOST_AUTO_TEST_SUITE_END()
