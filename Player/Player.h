#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Structs/Vec2.h"
#include <citro2d.h>

void pDrawPlayer(C3D_RenderTarget* topscreentarget);

void pMovePlayer(int keysdown);

#endif