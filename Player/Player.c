#include "Player.h"

Vector2f PlayerPosition = {190.0f, 220.0f};

u32 clrWhite;

void pInit(){
    clrWhite = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
}

void pDrawPlayer(C3D_RenderTarget* topscreentarget){
    
    C2D_DrawCircleSolid(PlayerPosition.x, PlayerPosition.y, 0, 15.0f, clrWhite);
}

void pMovePlayer(int keysdown){
    if(keysdown & KEY_DLEFT){
        if(keysdown & KEY_A){
            PlayerPosition.x -= 8.4f;
            clrWhite = C2D_Color32(0x0e, 0xFF, 00, 0xFF);

        } else {
            PlayerPosition.x -= 4.0f;
            clrWhite = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);

        }
    } else if(keysdown & KEY_DRIGHT){
        if(keysdown & KEY_A){
            PlayerPosition.x += 8.4f;
            clrWhite = C2D_Color32(0x0e, 0xFF, 00, 0xFF);

        } else {
            PlayerPosition.x += 4.0f;
            clrWhite = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
        }
    }
}