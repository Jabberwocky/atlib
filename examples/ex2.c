#include "at.h"

int main() {
    int x = 40, y = 12;
    int key;

    atStart("Example 2", 80, 24); /* Create the window. */
    
    /* Main loop. */
    while (atIsRunning()) {
        /* Draw '@' at the location x,y. */
        atDrawChar(x, y, ATC_BLUE, atGetBgColor(), '@');
        
        /* Update the window. */
        atUpdate();
        /* Clear the backbuffer. */
        atClear();
        
        /* Grab events to allow the user to close the window. */
        key = atGetKey();
        
        /* Process events. */
        switch (key) {
            case ATK_UP: /* Up arrow. */
                --y;
                break;
            case ATK_DOWN: /* Down arrow. */
                ++y;
                break;
            case ATK_LEFT: /* Left arrow. */
                --x;
                break;
            case ATK_RIGHT: /* Right arrow. */
                ++x;
                break;
            case 'Q':
                atStopRunning(); /* Stop running. */
                break;
            default:
                break;
        }
    }
    
    atStop(); /* Close the window. */
    return 0;
}
