#ifndef MAP_H_
#define MAP_H_

#include <3ds.h>

typedef struct TimingPoint {
    int ms;
    int type;
    uint32_t args;
    uint32_t args2;
} TimingPoint;


typedef struct HitObject {
    int ms;
    float x;
    u32 color;
} HitObject;

typedef struct Map {
    HitObject   hitobjects  [131072];
    TimingPoint timingpoints[131072];
    u32         totalObjects;
    u32         objectsDone;
    u32         BackgroundColor;

    u32 ticks;
} Beatmap;



void PlayMap(Beatmap* map){
    map->ticks = 0;
    map->objectsDone = 0;
    
}

void MapTick(Beatmap* map){
    map->ticks = &map->ticks - 1;
    for(int i = &map->objectsDone; i != &map->totalObjects; i++){
        map->hitobjects[i].ms = &map->hitobjects[i].ms - 1;
    }
}

#endif