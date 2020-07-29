#include "Declarations.h"

using std::cout;

void DebugE::PrintPieceArray()
{
    for ( int i = 0; i < MAX_PP; i++ ) {
        Pp[i].DisplayBits( 7 );
        cout << "\n";
    }

    for ( int i = 0; i < MAX_PP; i++ ) {
        cout << "\nPlN: " << Pp[i].GetPnum() << " PieN: " << Pp[i].GetPieNum()
             << " SwiSq: " << Pp[i].GetSwiSq() << " EndSq: " << Pp[i].GetEndSq()
             << " InSq: " << Pp[i].GetInSq() << " Sq: " << Pp[i].GetSq();
    }
}
void DebugE::zDebugPieceFunctions()
{
    PieceE test;
    cout << "\n-----------SetTestStart-------";
    test.SetSq( 0b1000011 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetInSq( 0b1000101 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetEndSq( 0b1001001 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetSwiSq( 0b1010001 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetPnum( 0b11 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetPieNum( 0b01 );
    test.DisplayBits( 7 );
    cout << "\n";

    cout << "\n----------GetTestStart -----------\n";

    DebugE::DisplayBits( test.GetSq(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetInSq(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetEndSq(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetSwiSq(), 7 );
    cout << "\n";

    DebugE::DisplayBits( test.GetPnum(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetPieNum(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetPPnum(), 7 );
    cout << "\n";
}
void DebugE::DisplayBits( u32 num, int sp,bool val )
{
    for ( auto i = 31; i >= 0; i-- ) {
        if ( val ) {
            std::cout << ( num & 1ULL << i ) << " ";
        } else {
            ( num & 1ULL << i ) ? cout << 1 : cout << 0;
        }
        if ( ( i ) % sp == 0 ) { cout << " "; }
        if ( ( i ) % 4 == 0 && sp==8 ) { cout << " "; }
    }
}