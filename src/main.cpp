#include "main.h"

#include <bitset>
#include <functional>

#include "EASTL/array.h"
#include "EASTL/bitset.h"
#include "GData.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"
using u64 = unsigned long long int;

void DisplayBits( u64 wow );
using std::cout;

//
// Input-- Piece clieced
// outPut list of from-to moves for different pieces
// and activate Dice input on some player
// input dice roll (perhaps internally generated)
// set of pieces for valid input
// loop
// square incoding would be like bbbb--- for detecting which player is on 
// it need 5 states 1 for each player and one for none
//then it will contail 8 bits for players bb bb bb bb for each player 


//player each player can be represented by 4 bits bb for playter num and bb for pice num
//helper funcitons etc can be made to need

// internal
using namespace eastl;

bitset<18> j = 0;
bitset<18> k=0;

int main()
{
  // std::bitset<12> lo = 3;
   //lo|=3;
    j[0]               = 1;


    k[12]=1;
    j|=(12<<2);
    k=j;
    k&=(0xf<<2);
    k|=1;
    
     std::cout << "\nj is: ";
    DisplayBits( j );
    std::cout<<"\nk is: ";
    DisplayBits(k);


    // cout<<"\nLo is : "<<lo<<"\n";

    std::cout << "\n";
    return 0;
}
