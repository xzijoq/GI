#pragma once
#include "BitsE.h"
#include "DebugE.h"
#include "GData.h"


//  PPnum(4 (0-16)) //Switch Into 7// EndSq 7// InSq 7// Square 7
//  32-30       28            21        14         7       0
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
