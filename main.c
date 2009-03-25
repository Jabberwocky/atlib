#include "at.h"

int main() {
    int x, y, key;
    AtWindow * win;

    atStart("Test", 80, 24);
    
    win = atWindowCreate(10, 10);
    atSetBgColor(ATC_STDGREEN);
    
    x = 70, y = 0;
    while (atIsRunning()) {
        atBlit(x, y, win);
    
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
