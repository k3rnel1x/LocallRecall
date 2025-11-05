#include "x11ScreenShotSystem.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>


// dynamic memory allocation
XImage* x11ScreenShotSystem::GetActiveWinShot()
{
    // clear prev ximage
    if(ximage)
        XDestroyImage(ximage);

    // get active window
    target_window = x11ScreenShotSystem::getActiveWindow(global_display, root_win);
    if (target_window == 0) {
        return NULL;
    }

    // get window attributes
    int get_attributes_res = XGetWindowAttributes(global_display, target_window, &attributes);
    if (get_attributes_res == 0) {
        return NULL;
    }

    // get image
    ximage = XGetImage(
            global_display,
            target_window,
            0, 0,          // Начальные координаты 0, 0 относительно окна
            attributes.width, attributes.height,
            AllPlanes,
            ZPixmap
        ); // 32 bit RGB

    if (ximage == NULL) {
        return NULL;
    }

    return ximage;
}