#include "at.hpp"

int main()
{
	at::start("Color!");
	
	at::color newcolor(100, 150, 150);
	
    // Unused window.
	at::window win(10, 10);
    
	// Change the default background of the main window.
	at::stdwin->bgcolor(newcolor);
	
	while (at::is_running())
	{
		at::addstr(40, 12, "COLOR", at::color_red);
		at::update();
		
		at::getkey();
	}
	
	at::stop();
	return 0;
}