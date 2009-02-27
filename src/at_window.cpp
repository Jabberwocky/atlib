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
#include <SDL/SDL.h>

#include "at.hpp"
#include "at_internal.hpp"

namespace at
{
    extern bool font[][FONT_HEIGHT][FONT_WIDTH];
    
    window *stdwin = NULL;
    
    window::window(int width, int height) :
    bgcolor_(COLOR_BLACK)
    {
        int scr_width, scr_height;
        
        _cell_to_screen(width, height, &scr_width, &scr_height);
        surface_ = SDL_CreateRGBSurface(SDL_SWSURFACE, scr_width, scr_height,
            32, 0, 0, 0, 0);
    }
    
    window::window(SDL_Surface *surface) :
    bgcolor_(COLOR_BLACK)
    {
        surface_ = surface;
    }
    
    window::window(const window &win) :
    surface_(NULL), bgcolor_(COLOR_BLACK)
    {
        *this = win;
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
        _screen_to_cell(surface_->w, surface_->h, &width, NULL);
        
        return width;
    }
    
    int window::height() const
    {
        assert(surface_ != NULL);
        
        int height;
        _screen_to_cell(surface_->w, surface_->h, NULL, &height);
        
        return height;
    }
    
    void window::bgcolor(const color &bg)
    {
        bgcolor_ = bg;
        clear();
    }
    
    color window::bgcolor() const
    {
        return bgcolor_;
    }
    
    void window::addch(int x, int y, char c, const color &fg)
    {
        addch(x, y, c, fg, bgcolor_);
    }
    
    void window::addch(int x, int y, char c, const color &fg, const color &bg)
    {
        assert(c >= 0 && c < MAX_CHARS);
    
        int nx, ny;
        
        _cell_to_screen(x, y, &nx, &ny);
        
        for (y = 0; y < FONT_HEIGHT; ++y) {
            for (x = 0; x < FONT_WIDTH; ++x) {
                if (font[int(c)][y][x])
                    this->_set_pixel(x + nx, y + ny, _at_to_sdl_color(fg));
                else
                    this->_set_pixel(x + nx, y + ny, _at_to_sdl_color(bg));
            }
        }
    }
    
    void window::addstr(int x, int y, const char * str, const color &fg)
    {
        addstr(x, y, str, fg, bgcolor_);
    }
    
    void window::addstr(int x, int y, const char * str, const color &fg, const color &bg)
    {
        unsigned int len = strlen(str);
        for (unsigned int i = 0; i < len; ++i)
            addch(x++, y, str[i], fg, bg);
    }
    
    void window::blit(int x, int y, const window &win)
    {
        SDL_Rect xy;
        
        _cell_to_screen(x, y, (int *)&xy.x, (int *)&xy.y);
        
        SDL_BlitSurface(win.surface_, NULL, surface_, &xy);
    }
    
    void window::update()
    {
        SDL_Flip(surface_);
    }
    
    void window::clear()
    {
        SDL_FillRect(surface_, NULL, _at_to_sdl_color(bgcolor_));
    }
    
    window &window::operator =(const window &win)
    {
        if (this != &win && this != stdwin)
        {
            if (surface_ != NULL)
                SDL_FreeSurface(surface_);

            // Copy the surface.
            if (win.surface_ != NULL)
                surface_ = SDL_DisplayFormat(win.surface_);

            // Copy data.
            bgcolor_ = win.bgcolor_;
        }
        return *this;
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
