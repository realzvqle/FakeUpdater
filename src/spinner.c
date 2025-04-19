#include "spinner.h"
#include "raylib/raylib.h"


static int s_FrameCounter = 0;
static int s_FrameDelay = 2;
static int s_CurrentAnimFrame = 0;
static int s_AnimFrames = 0;
static unsigned int s_NextFrameDataOffset = 0;
static Texture2D s_Tex;
static Image s_SpinnerImage;

void SetupSpinner(){
    s_SpinnerImage = LoadImageAnim("resources/spinner.gif", &s_AnimFrames);
    s_Tex = LoadTextureFromImage(s_SpinnerImage);
}

void UpdateSpinner(){
    s_FrameCounter++;
    if(s_FrameCounter >= s_FrameDelay){
        s_CurrentAnimFrame++;
        if(s_CurrentAnimFrame >= s_AnimFrames) s_CurrentAnimFrame = 0;
        s_NextFrameDataOffset = s_SpinnerImage.width * s_SpinnerImage.height * 4 * s_CurrentAnimFrame;
        UpdateTexture(s_Tex, ((unsigned char*)s_SpinnerImage.data) + s_NextFrameDataOffset);
        s_FrameCounter = 0;
    }
}

void DrawSpinner(int posX, int posY, float scale){
    DrawTextureEx(s_Tex, (Vector2){posX, posY}, 0, scale, WHITE);
}