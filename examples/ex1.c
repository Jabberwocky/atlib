#include "at.h"

int main() {
    atStart("Example 1", 80, 24); /* Create the window. */
    
    /* Main loop. */
    while (atIsRunning()) {
        /* Draw "Hello, world!" onto the center of the screen. */
        atDrawString(40, 12, ATC_WHITE, atGetBgColor(), "Hello, world!");
        
        /* Update the window. */
        atUpdate();
        /* Clear the backbuffer. */
        atClear();
        
        /* Grab events to allow the user to close the window. */
        atGetKey();
    }
    
    atStop(); /* Close the window. */
    return 0;
}
