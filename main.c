// Simple citro2d untextured shape example
#include <citro2d.h>
#include <3ds.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Player/Player.c"
#include "Maps/Map.h"



#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240

//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//---------------------------------------------------------------------------------
	// Init libs
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_BOTTOM, NULL);

	// Create screens
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

	// Create colors
	Beatmap map;
	map.BackgroundColor = C2D_Color32(0xFF, 0x00, 0x30, 0x00);
	map.hitobjects[0] = (HitObject){
		60, 180.0f, C2D_Color32(0x00, 0x19, 0xff, 0xff)
	};
	map.hitobjects[1] = (HitObject){
		120, 240.0f, C2D_Color32(0x00, 0x19, 0xff, 0xff)
	};
	map.hitobjects[2] = (HitObject){
		180, 120.0f, C2D_Color32(0x00, 0x19, 0xff, 0xff)
	};
	map.hitobjects[3] = (HitObject){
		240, 90.0f, C2D_Color32(0x00, 0x19, 0xff, 0xff)
	};
	map.hitobjects[4] = (HitObject){
		300, 300.0f, C2D_Color32(0x00, 0x19, 0xff, 0xff)
	};
	map.totalObjects = 4;

	u32 clrClear = map.BackgroundColor;

	pInit();

	time_t startTime = osGetTime();
	time_t nowTime = osGetTime();
	

	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();
		
		
		// Respond to user input
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
		printf("\x1b[1;1Hosu!3ds fruits! Codebase");
		printf("\x1b[2;1HCPU:         %6.2f%%\x1b[K", C3D_GetProcessingTime()*6.0f);
		printf("\x1b[3;1HGPU:         %6.2f%%\x1b[K", C3D_GetDrawingTime()*6.0f);
		printf("\x1b[4;1HCmdBuf:      %6.2f%%\x1b[K", C3D_GetCmdBufUsage()*100.0f);
		printf("\x1b[5;1HActive(ms):  %i\x1b[K", nowTime - startTime);

		nowTime = osGetTime();
		// Render the scene
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, clrClear);
		C2D_SceneBegin(top); //Start Render

		pDrawPlayer(top);
		pMovePlayer(hidKeysHeld());

		

		C3D_FrameEnd(0);
	}
	
	// Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
