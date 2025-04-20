#define RAYGUI_IMPLMENTATION
#include "raylib/raygui.h"
#include <stddef.h>


static Font s_Font;



void SetupUpdaterUI(){
    s_Font = LoadFontEx("resources/MicrosoftJhengHeiLight-01.ttf", 400, NULL, 0);
}

void CloseUpdaterUI(){
    UnloadFont(s_Font);
}

void UiDrawText(char* text, int posX, int posY, int fontsize, Color color){
    DrawTextEx(s_Font, text, (Vector2){posX, posY}, fontsize, 2, color);
}

Font UiGetFont(){
    return s_Font;
}

Color GetUIBackgroundColor(){
    return (Color){7, 88, 155};
}

