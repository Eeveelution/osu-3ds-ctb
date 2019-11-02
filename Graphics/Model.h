#ifndef MODEL_H_
#define MODEL_H_

#include <3ds.h>

#define SM_RECTANGLE 1
#define SM_RECTANGLE_SOLID 2
#define SM_ELIPSE 4
#define SM_ELIPSE_SOLID 8
#define SM_CIRCLE 16
#define SM_CIRCLE_SOLID 32
#define SM_TRIANGLE 64
#define SM_TRIANGLE_SOLID 128
/*
Modifiers:
1st Bit: Single Color
2nd Bit:
3rd Bit:
4th Bit:
5th Bit:
6th Bit:
7th Bit:
8th Bit:

*/

typedef struct Shape {
    uint8_t type;
    uint8_t modifiers; 
    float x, y, z, size_x, size_y;
    u32 clr0, clr1, clr2, clr3;
} Shape;

typedef struct ShapeModel {
    Shape shapes[1024];
    size_t shapecount;
} ShapeModel;

void DrawModel(ShapeModel mdl);

#endif