#include "x11ScreenShotSystem.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>

void x11ScreenShotSystem::End()
{
    if (global_display)
        XCloseDisplay(global_display);

    if (ximage)
        XDestroyImage(ximage);
}
