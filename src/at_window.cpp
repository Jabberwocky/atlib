// Copyright (c) 2009, Michael Patraw
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * The name of Michael Patraw may not be used to endorse or promote 
//       products derived from this software without specific prior written
//       permission.
//
// THIS SOFTWARE IS PROVIDED BY Michael Patraw ''AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL Michael Patraw BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#include <cassert>
#include <SDL/SDL.h>

#include "at.hpp"

namespace at
{
    extern bool font[][FONT_HEIGHT][FONT_WIDTH];
    
    window *stdwin = NULL;
    
    window::window(int width, int height)
    {
        int scr_width, scr_height;
        
        cell_to_screen(width, height, &scr_width, &scr_height);
        surface_ = SDL_CreateRGBSurface(SDL_SWSURFACE, scr_width, scr_height,
            32, 0, 0, 0, 0);
    }
    
    window::window(SDL_Surface *surface)
    {
        surface_ = surface;
    }
    
    window::~window()
    {
        if (surface_ != SDL_GetVideoSurface()) // Don't free the main surface.
            SDL_FreeSurface(surface_);
    }
    
    int window::width() const
    {
        assert(surface_ != NULL);
        
        int width;
        screen_to_cell(surface_->w, surface_->h, &width, NULL);
        
        return width;
    }
    
    int window::height() const
    {
        assert(surface_ != NULL);
        
        int height;
        screen_to_cell(surface_->w, surface_->h, NULL, &height);
        
        return height;
    }
    
    void window::addch(int x, int y, char c, Uint32 fg, Uint32 bg)
    {
        assert(c >= 0 && c < MAX_CHARS);
    
        int nx, ny;
        
        cell_to_screen(x, y, &nx, &ny);
        
        for (y = 0; y < FONT_HEIGHT; ++y) {
            for (x = 0; x < FONT_WIDTH; ++x) {
                if (font[int(c)][y][x])
                    this->_set_pixel(x + nx, y + ny, fg);
                else
                    this->_set_pixel(x + nx, y + ny, bg);
            }
        }
    }

    void window::addstr(int x, int y, const char * str, Uint32 fg, Uint32 bg)
    {
        unsigned int len = strlen(str);
        for (unsigned int i = 0; i < len; ++i)
        {
            if (x >= width())
            {
                x = 0;
                y++;
            }
            addch(x++, y, str[i], fg, bg);
        }
    }
    
    void window::update()
    {
        SDL_Flip(surface_);
    }
    
    void window::clear()
    {
        SDL_FillRect(surface_, NULL, 0);
    }
    
    Uint32 window::_get_pixel(int x, int y) const
    {
        assert(surface_ != NULL);
        assert(x >= 0 && x < surface_->w && y >= 0 && y < surface_->h);
        return ((Uint32 *)surface_->pixels)[y * surface_->w + x];
    }
    
    void window::_set_pixel(int x, int y, Uint32 p)
    {
        assert(surface_ != NULL);
        
        if (x >= 0 && x < surface_->w && y >= 0 && y < surface_->h)
            ((Uint32 *)surface_->pixels)[y * surface_->w + x] = p;
    }
} // namespace at