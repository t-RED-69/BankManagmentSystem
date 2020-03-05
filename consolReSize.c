#define WINVER 0x0500
#include <windows.h>

int consolReSize (int height,int width)
{
    // Get console window handle
    HWND wh = GetConsoleWindow();

    // Move window to required position
    MoveWindow(wh, 100, 100, width, height, TRUE);
}
