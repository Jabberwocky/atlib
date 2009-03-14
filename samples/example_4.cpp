#include "at.hpp"

bool custom[at::FONT_HEIGHT][at::FONT_WIDTH] =
{
    {0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 0, 1},
    {0, 1, 1, 0, 1, 0},
    {1, 0, 1, 1, 0, 1},
    {0, 1, 1, 0, 1, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
};

int main()
{
	at::start("Trees!!");
	
    // Replace the character 'T' with our custom character.
	at::set_font_char('T', custom);
	
	while (at::is_running())
	{
        // Draws T's which we've just replaced.
		at::addstr(40, 12, "TTTTTTT = trees!", at::COLOR_GREEN);
		at::update();
		
		at::getkey();
	}
	
	at::stop();
	return 0;
}
