#pragma once
#include "CommonE.h"

// do we need to inline it

class BitsE
{
   public:
    u32                  PInt;
    static constexpr u32 pow[]{
        0b0,     0b1,      0b11,      0b111,     0b1111,  // wow
        0b11111, 0b111111, 0b1111111, 0b11111111

    };

    BitsE() : PInt{ 0 } {}

   public:
    void        DisplayBits( int sp = 8 );
    inline u32  GetBit( u32 bit ) { return PInt >> bit; }
    inline void SetBit( u32 bit ) { PInt |= (u32)1 << bit; }
    inline void UnSetBit( u32 bit ) { PInt &= ~( (u32)1 << bit ); }

    // to make private after testing
    inline void SetBits( u32 count, u32 bits, u32 posi )
    {
        
            // clear those bits to zero and set new
            PInt &= ~( pow[count] << posi );
            PInt |= bits << posi;
        
    }
    u32 GetBits( u32 count, u32 posi ) { return ( PInt >> posi ) & pow[count]; }
};