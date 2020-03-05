#define WINVER 0x0500
#include <windows.h>

int consolReSize (int height,int width)
{
    // Get console window handle
    HWND wh = GetConsoleWindow();

    MoveWindow(wh, 100, 100, width, height, TRUE);
    //Move window x=^ ,y=^  required position
}
