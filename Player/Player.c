#include "Player.h"

Vector2f PlayerPosition = {190.0f, 227.5f};

u32 headColor;

void pInit(){
    headColor = C2D_Color32(255, 195, 170, 255);
}

void pDrawPlayer(C3D_RenderTarget* topscreentarget){ 
    //Head
    C2D_DrawCircleSolid(PlayerPosition.x+0.5f, PlayerPosition.y-29, 0, 12.0f,
                        headColor
    );
    //Torso
    C2D_DrawEllipseSolid(PlayerPosition.x-7.0f, PlayerPosition.y-16, -1.0f,
                         16.0f, 22.0f,
                         C2D_Color32(16, 240, 0, 255)
    );
    //Left Foot
    C2D_DrawEllipseSolid(PlayerPosition.x-0.5f, PlayerPosition.y+6, 0.0f,
                         -20.0f, 6.0f,
                         C2D_Color32(255, 231, 173, 255)
    );
    //Right Foot
    C2D_DrawEllipseSolid(PlayerPosition.x+2.0f, PlayerPosition.y+6, 0.0f,
                         +20.0f, 6.0f,
                         C2D_Color32(255, 231, 173, 255)
    );
    //Left Hand
    C2D_DrawTriangle(PlayerPosition.x-16.0f, PlayerPosition.y-49, 
                     C2D_Color32(0xFF,0xFF,0xFF,0xFF),
                     PlayerPosition.x, PlayerPosition.y-43,
                     C2D_Color32(0xFF,0xFF,0xFF,0xFF),
                     PlayerPosition.x+16.0f, PlayerPosition.y-49,
                     C2D_Color32(0xFF,0xFF,0xFF,0xFF),
                     0.0f
    );
    //Right Hand
}

void pMovePlayer(int keysdown){
    if(keysdown & KEY_DLEFT){
        if(keysdown & KEY_A){
            PlayerPosition.x -= 8.4f;
            headColor = C2D_Color32(0xD8, 0x00, 0x26, 0xFF);

        } else {
            PlayerPosition.x -= 4.0f;
            headColor = C2D_Color32(255, 195, 170, 255);

        }
    } else if(keysdown & KEY_DRIGHT){
        if(keysdown & KEY_A){
            PlayerPosition.x += 8.4f;
            headColor = C2D_Color32(0xD8, 0x00, 0x26, 0xFF);

        } else {
            PlayerPosition.x += 4.0f;
            headColor = C2D_Color32(255, 195, 170, 255);
        }
    }
}