cmake_minimum_required(VERSION 2.8.11)
project(lambda_testing)
enable_testing()

set(Boost_ADDITIONAL_VERSIONS "1.71" "1.71.0")

# finds boost, triggers an error otherwise
find_package(Boost 1.71 REQUIRED COMPONENTS unit_test_framework)

add_subdirectory(../include
             [EXCLUDE_FROM_ALL])

# creates the executable
add_executable(lambda_test lambda_test.cpp)
# indicates the include paths
target_include_directories(lambda_test PUBLIC ${Boost_INCLUDE_DIRS} ../include)
# indicates the shared library variant
target_compile_definitions(lambda_test PUBLIC "BOOST_TEST_DYN_LINK=1")
# indicates the link paths
target_link_libraries(lambda_test Definitions VarAnalysis ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

# declares a test with our executable
add_test(NAME test1 COMMAND lambda_test)