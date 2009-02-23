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
#ifndef AT_HPP
#define AT_HPP

#include <SDL/SDL_types.h>

struct SDL_Surface;

namespace at
{
    enum key
    {
        ATK_FIRST = 0,
        
        ATK_NONE = 0,
        ATK_UP = 1,
        ATK_DOWN = 2,
        ATK_LEFT = 3,
        ATK_RIGHT = 4,
        ATK_QUIT = 5,
        
        ATK_LAST = 5
    };
    
    struct color
    {
        static void init();
        
        static Uint32 black;
        static Uint32 blue;
        static Uint32 cyan;
        static Uint32 green;
        static Uint32 magenta;
        static Uint32 red;
        static Uint32 yellow;
        static Uint32 white;
    };

    class window
    {
    public:
        window(int width=80, int height=24);
        window(SDL_Surface *surface);
        virtual ~window();
        
        virtual int width() const;
        virtual int height() const;
        
        virtual void addch(int x, int y, char c, Uint32 fg, Uint32 bg=color::black);
        virtual void addstr(int x, int y, const char * str,
            Uint32 fg, Uint32 bg=color::black);
        
        virtual void update();
        virtual void clear();
    
    protected:
        Uint32 _get_pixel(int x, int y) const;
        void   _set_pixel(int x, int y, Uint32 p);
    
        SDL_Surface *surface_;
    };
    extern window *stdwin;
    
    const int MAX_CHARS   = 256;
    const int FONT_WIDTH  = 6;
    const int FONT_HEIGHT = 13;

    // Starts the console.
    window *start(const char *title, int width=80, int height=24);

    // Ends the console.
    void stop();
    
    // Updates the main window.
    void update();
    
    // Clear the main window.
    void clear();
    
    // Returns a key.
    key getkey();
    
 
    bool is_running();

    void stop_running();
    
    inline void cell_to_screen(int x, int y, int *nx, int *ny)
    {
        if (nx)
            *nx = x * FONT_WIDTH;
        if (ny)
            *ny = y * FONT_HEIGHT;
    }
    
    inline void screen_to_cell(int x, int y, int *nx, int *ny)
    {
        if (nx)
            *nx = x / FONT_WIDTH;
        if (ny)
            *ny = y / FONT_HEIGHT;
    }
} // namespace at

#endif // AT_HPP
