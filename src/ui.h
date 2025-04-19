#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED







#include "updater.h"


void SetupUpdaterUI();
void CloseUpdaterUI();
void UiDrawText(char* text, int posX, int posY, int fontsize, Color color);
Font UiGetFont();
Color GetUIBackgroundColor();
#endif
