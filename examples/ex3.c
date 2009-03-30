#include "at.h"

#define CHAR_PINE 1

void load_font(void);

int main() {
    int x, y;
    
    atStart("Example 3", 80, 24); /* Create the window. */
    
    /* Load custom characters. */
    load_font();
    
    /* Main loop. */
    while (atIsRunning()) {
        /* Draw the map using custom characters. */
        for (y = 0; y < 10; ++y)
            for (x = 0; x < 15; ++x)
                atDrawChar(x, y, ATC_GREEN, atGetBgColor(), CHAR_PINE);
        
        atDrawString(0, 10, ATC_WHITE, atGetBgColor(), "Pine trees!");
        
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

void load_font(void) {
    char pine[AT_CHAR_HEIGHT][AT_CHAR_WIDTH] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0},
        {1, 1, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    
    atCharSet(CHAR_PINE, pine);
}
