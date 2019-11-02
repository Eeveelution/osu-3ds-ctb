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
    float x, y;
    u32 color;
} HitObject;

typedef struct Map {
    HitObject   hitobjects  [131072];
    TimingPoint timingpoints[131072];

    u32 BackgroundColor;

} Beatmap;

#endif