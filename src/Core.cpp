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

class PieceE : public BitsE
{
   public:
    inline u32  GetSq() { return GetBits( 7, 0 ); }
    inline u32  GetInSq() { return GetBits( 7, 7 ); }
    inline u32  GetEndSq() { return GetBits( 7, 14 ); }
    inline u32  GetSwiSq() { return GetBits( 7, 21 ); }
    inline u32  GetPieNum() { return GetBits( 2, 28 ); }
    inline u32  GetPnum() { return GetBits( 2, 30 ); }
    inline u32  GetPPnum() { return GetBits( 4, 28 ); }
    void InitPieceE( u32 Sq, u32 InSq, u32 EndSq, u32 SwiSq, u32 PlNum,
                     u32 PieNum );

    friend class DebugE;

    inline void SetSq( u32 sq ) { SetBits( 7, sq, 0 ); }
   private:
    inline void SetInSq( u32 sq ) { SetBits( 7, sq, 7 ); }
    inline void SetEndSq( u32 sq ) { SetBits( 7, sq, 14 ); }
    inline void SetSwiSq( u32 sq ) { SetBits( 7, sq, 21 ); }
    inline void SetPieNum( u32 pieNum ) { SetBits( 2, pieNum, 28 ); }
    inline void SetPnum( u32 pNum ) { SetBits( 2, pNum, 30 ); }
    inline void SetPPnum( u32 ppNum ) { SetBits( 4, ppNum, 28 ); }
};
