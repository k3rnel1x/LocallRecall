#include "x11ScreenShotSystem.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int x11ScreenShotSystem::Init()
{
    global_display = XOpenDisplay(NULL);
    if (global_display == NULL) {
        return 0;
    }

    root_win = XDefaultRootWindow(global_display);

    _init = 1;
    return 1;
}


