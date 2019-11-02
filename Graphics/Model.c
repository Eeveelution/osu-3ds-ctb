#include "Model.h"

#include <citro2d.h>

void DrawModel(ShapeModel mdl){
    for(int i = 0; i != mdl.shapecount; i++){
        if(mdl.shapes[i].type == SM_RECTANGLE){
            C2D_DrawRectangle(mdl.shapes[i].x,mdl.shapes[i].y,mdl.shapes[i].z,mdl.shapes[i].size_x, mdl.shapes[i].size_y, mdl.shapes[i].clr0, mdl.shapes[i].clr1, mdl.shapes[i].clr2, mdl.shapes[i].clr3);
        }
    }
}