#pragma once

#include <array>

#include "GData.h"
#include "Core.h"


extern std::array<SquareE, G2::LudoBoard.size()>            Sq;
extern std::array<PieceE, G2::MAX_PLAYERS * G2::MAX_PIECES> Pp;

extern void InitAllPlayers();
