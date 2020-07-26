#include <functional>

#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
using u64 = unsigned long long int;

void DisplayBits( u64 wow );

int main()
{
    std::cout << "\nweo\n";
    spdlog::info("Welcome to spdlog!");
    // std::cout<<0blol;
     spdlog::error("Some error message with arg: {}", 1);

    DisplayBits( 1 );

    return 0;
}








void DisplayBits( u64 pint )
{
    std::cout<<"\n";
    for ( auto i = 63; i >= 0; i-- ) {
        if ( ( i + 1 ) % 8 == 0 ) std::cout << " ";
        ( pint & 1ULL << i ) ? std::cout << 1 : std::cout << 0;
    }
    std::cout << "\n";
}