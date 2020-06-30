#include "nonstd/scope.hpp"

using namespace nonstd;

int count = 0;

void on_exit() { ++count; }

int main()
{
    { auto guard = make_scope_exit(  on_exit ); } // note: on_exit w/o &
    { auto guard = make_scope_exit( &on_exit ); } // note: &on_exit

    return count;
}

// cl -nologo -EHsc -I../include 01-basic.cpp && 01-basic
// echo %ERRORLEVEL%

// g++ -std=c++11 -Wall -I../include -o 01-basic 01-basic.cpp && ./01-basic || echo $?
