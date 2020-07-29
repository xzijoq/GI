#pragma once
#include "BitsE.h"
#include "DebugE.h"
#include "GData.h"

//

class SquareE : public BitsE
{
   public:
    inline u32 HasPlayer( u32 player )
    {
        return ( ( PInt >> player * G2::MAX_PIECES ) & 0b1111 );
    }
    inline u32 HasPP( u32 player, u32 piece )
    {
        assert( DebugE::IsInRange( player, 0, G2::MAX_PLAYERS ) );
        assert( DebugE::IsInRange( piece, 0, G2::MAX_PIECES ) );
        return GetBit( ( player * 4 + piece ) );
    }
    inline u32 HasPP( u32 PPnum ) { return GetBit( PPnum ); }
    friend class DebugE;
};



// square incoding would be like bbbb--- for detecting which player is on
// it need 5 states 1 for each player and one for none
// then it will contail 8 bits for players bb bb bb bb for each player
// get_num player
// push pp
// pop pp
// has pp
//  //flags 0000//players 11 11 11 11 22 22 22 22 33 33 33 33 44 44 44 /pnum0000
//

// SQUARE


//
// Input-- Piece clieced
// outPut list of from-to moves for different pieces
// and activate Dice input on some player
// input dice roll (perhaps internally generated)
// set of pieces for valid input
// loop



//player each player can be represented by 4 bits bb for playter num and bb for pice num
//helper funcitons etc can be made to need

// internal

