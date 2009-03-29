#include "at.h"
#include <string.h>

int main() {
    int x, y, key;
    AtWindow * win = NULL;

    atStart("Test", 80, 24);
    
    x = 0, y = 0;
    while (atIsRunning()) {
        atDrawChar(0, 0, ATC_GOLD, atGetBgColor(), '@');
        atDrawStringWrapAbs(x, y, ATC_GOLD, atGetBgColor(), "Hello, world");
    
        atUpdate();
        atClear();

        key = atGetKey();
        
        switch (key) {
            case ATK_DOWN:
                y++;
                break;
            case ATK_UP:
                y--;
                break;
            case ATK_LEFT:
                x--;
                break;
            case ATK_RIGHT:
                x++;
                break;
            case 's':
                y+=10;
                break;
            case 'w':
                y-=10;
                break;
            case 'a':
                x-=10;
                break;
            case 'd':
                x+=10;
                break;
            case 'Q':
                atStopRunning();
                break;
            default:
                break;
        }
    }
    
    atWindowDestroy(win);
    atStop();
    return 0;
}
