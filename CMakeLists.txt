cmake_minimum_required(VERSION 3.0.0)
project(lambda_calculus VERSION 0.1.0)

include(CTest)
add_subdirectory(include)

file(GLOB SOURCES "*.cpp")
add_executable(lambda_calculus ${SOURCES})

target_link_libraries(lambda_calculus PUBLIC Definitions VarAnalysis)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

enable_testing()

# invoke in /build with "ctest -VV"
add_test(NAME Runs COMMAND lambda_calculus) 