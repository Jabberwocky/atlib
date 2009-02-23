#include "at.hpp"

int main()
{
	at::start("Hello, world"); // Creates the window with the title "Hello, world".
	
	// Main loop.
	while (at::is_running()) // Loops until the user closes the window.
	{
		at::addstr(0, 0, "Hello, world!", at::color_white); // Print's "Hello, world!" in white.
		at::update(); // Updates the window.
		
		at::getkey(); // Must process events or the window can't be closed.
	}
	
	at::stop(); // Shuts down atlib, cleaning up any memory.
	return 0;
}
