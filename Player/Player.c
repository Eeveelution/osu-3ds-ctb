#include "Player.h"

Vector2f PlayerPosition = {96.0f, 96.0f};

void pDrawPlayer(C3D_RenderTarget* topscreentarget){
    u32 clrWhite = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
    C2D_DrawCircleSolid(PlayerPosition.x, PlayerPosition.y, 0, 5.0f, clrWhite);
}

void pMovePlayer(int keysdown){

}