#pragma once

#include "GData.h"

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

//  PPnum(4 (0-16)) //Switch Into 7// EndSq 7// InSq 7// Square 7
//  32-30       28            21        14         7       0
class PieceE : public BitsE
{
   public:
    inline u32 GetSq() { return GetBits( 7, 0 ); }
    inline u32 GetInSq() { return GetBits( 7, 7 ); }
    inline u32 GetEndSq() { return GetBits( 7, 14 ); }
    inline u32 GetSwiSq() { return GetBits( 7, 21 ); }
    inline u32 GetPieNum() { return GetBits( 2, 28 ); }
    inline u32 GetPnum() { return GetBits( 2, 30 ); }
    inline u32 GetPPnum() { return GetBits( 4, 28 ); }
    void       InitPieceE( u32 Sq, u32 InSq, u32 EndSq, u32 SwiSq, u32 PlNum,
                           u32 PieNum );

    inline void SetSq( u32 sq ) { SetBits( 7, sq, 0 ); }

   private:
    inline void SetInSq( u32 sq ) { SetBits( 7, sq, 7 ); }
    inline void SetEndSq( u32 sq ) { SetBits( 7, sq, 14 ); }
    inline void SetSwiSq( u32 sq ) { SetBits( 7, sq, 21 ); }
    inline void SetPieNum( u32 pieNum ) { SetBits( 2, pieNum, 28 ); }
    inline void SetPnum( u32 pNum ) { SetBits( 2, pNum, 30 ); }
    inline void SetPPnum( u32 ppNum ) { SetBits( 4, ppNum, 28 ); }

   public:
    friend class DebugE;
};

// pp1 -4 pp2-4 pp3-4 pp4-4
class SquareE : public BitsE
{
   public:
    inline u32 GetPlayer( u32 player )
    {
        return ( ( PInt >> player * G2::MAX_PIECES ) & 0b1111 );
    }
    inline u32 GetPP( u32 player, u32 piece )
    {
        return GetBit( ( player * 4 + piece ) );
    }
    inline u32 GetPP( u32 PPnum ) { return GetBit( PPnum ); }

    friend class DebugE;
};

// from7  to7  PP4 isCap1  Cpl2 pieBits4  lsb->msb
//   0     7    14  18     19  21 ---25
class MoveE : public BitsE
{
   public:
    void SetmFrom( u32 frm ) { SetBits( 7, frm, 0 ); }
    void SetmTo( u32 to ) { SetBits( 7, to, 7 ); }
    void SetmPP( u32 pp ) { SetBits( 4, pp, 14 ); }
    void SetmIsCap( u32 val ) { SetBits( 1, val, 18 ); }
    void SetmCPl( u32 pl ) { SetBits( 2, pl, 19 ); }
    void SetmPBits( u32 bits ) { SetBits( 4, bits, 21 ); }
    void SetmCPiece( u32 piece ) { SetBit( 21 + piece ); }

    u32 GetmFrom() { return GetBits( 7, 0 ); }
    u32 GetmTo() { return GetBits( 7, 7 ); }
    u32 GetmPP() { return GetBits( 4, 14 ); }
    u32 GetmIsCap() { return GetBits( 1, 18 ); }
    u32 GetmCPl() { return GetBits( 2, 19 ); }
    u32 GetmPBits() { return GetBits( 4, 21 ); }
};