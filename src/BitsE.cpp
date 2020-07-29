#include "Declarations.h"
using std::cout;





void BitsE::DisplayBits(int sp)
{
    for ( auto i = 31; i >= 0; i-- ) {
        ( PInt & 1ULL << i ) ? cout << 1 : cout << 0;
        if ( ( i ) % sp == 0 ) { cout << " "; }
        if ( ( i ) % 4 == 0 && sp==8 ) { cout << " "; }
    }
}
