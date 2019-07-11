#include <stdlib.h>
#include <stdio.h>
#include <xcb/xcb.h>

int
main (){
    
    xcb_connection_t    *c;
    xcb_screen_t        *screen;
    xcb_drawable_t       win;
    xcb_gcontext_t       foreground;
    uint32_t             mask = 0;

    xcb_rectangle_t rectangles[] = {
      {50, 50, 600, 400},
    };

    c = xcb_connect (NULL, NULL);

    /* get the first screen */
    screen = xcb_setup_roots_iterator (xcb_get_setup (c)).data;

    /* root window */
    win = screen->root;

    foreground = xcb_generate_id (c);
    mask = XCB_GC_FOREGROUND | XCB_GC_LINE_WIDTH | XCB_GC_SUBWINDOW_MODE;
    uint32_t values[] = {
        screen->black_pixel,
        4,
        XCB_SUBWINDOW_MODE_INCLUDE_INFERIORS
    };

    xcb_create_gc (c, foreground, win, mask, values);

    while(1)
    {
        xcb_poly_rectangle (c, win, foreground, 1, rectangles);
        xcb_flush ( c );
    }
}