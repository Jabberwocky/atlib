#include "at.hpp"

int main()
{
	at::start("Color!");
	
	// Crate a custom color.	
	at::color newcolor(100, 150, 150); // R, G, B
	
	while (at::is_running())
	{
		at::addstr(40, 12, "COLOR", at::color_red); // newcolor is the background.
		at::update();
		
		at::getkey();
	}
	
	at::stop();
	return 0;
}
