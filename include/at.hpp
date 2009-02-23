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
        ATK_NONE = -1,
        
        ATK_FIRST = 0,
        ATK_NULL = 0,
        
        ATK_BACKSPACE = 8,
        ATK_TAB = 9,
        ATK_CLEAR = 12,
        ATK_RETURN = 13,
        ATK_PAUSE = 19,
        ATK_ESCAPE = 27,
        
        ATK_QUIT = 256,
        
        ATK_UP = 257,
        ATK_DOWN = 258,
        ATK_RIGHT = 259,
        ATK_LEFT = 260,
        ATK_LAST = 260
    };
    
    class color
    {
    public:
        color(Uint8 r=0, Uint8 g=0, Uint8 b=0) :
        r_(r), g_(g), b_(b)
        { }
        
        Uint8 red() const { return r_; }
        Uint8 green() const { return g_; }
        Uint8 blue() const { return b_; }
        
        void red(Uint8 r) { r_ = r; }
        void green(Uint8 g) { g_ = g; }
        void blue(Uint8 b) { b_ = b; }
    private:
        Uint8 r_, g_, b_;
    };
    
    static const color color_black(0x00, 0x00, 0x00);
    static const color color_blue(0x00, 0x00, 0xFF);
    static const color color_cyan(0x00, 0xFF, 0xFF);
    static const color color_green(0x00, 0xFF, 0x00);
    static const color color_magenta(0xFF, 0x00, 0xFF);
    static const color color_red(0xFF, 0x00, 0x00);
    static const color color_white(0xFF, 0xFF, 0xFF);
    static const color color_yellow(0xFF, 0xFF, 0x00);

    class window
    {
    public:
        window(int width=80, int height=24);
        window(SDL_Surface *surface);
        window(const window &win);
        virtual ~window();
        
        virtual int width() const;
        virtual int height() const;
    
        virtual void bgcolor(const color &bg);
        virtual color bgcolor() const;
        
        virtual void addch(int x, int y, char c, const color &fg);
        virtual void addch(int x, int y, char c, const color &fg, const color &bg);
        virtual void addstr(int x, int y, const char * str, const color &fg);
        virtual void addstr(int x, int y, const char * str, const color &fg, const color &bg);
        virtual void blit(int x, int y, const window &win);
        
        virtual void update();
        virtual void clear();
    
        window &operator =(const window &win);
    protected:
        Uint32 _get_pixel(int x, int y) const;
        void   _set_pixel(int x, int y, Uint32 p);
    
        SDL_Surface *surface_;
        color bgcolor_;
    };
    
    extern window *stdwin;
    
    const int MAX_CHARS   = 256;
    const int FONT_WIDTH  = 6;
    const int FONT_HEIGHT = 13;

    // Starts the console. Should be called before every other function.
    window *start(const char *title, int width=80, int height=24);
    // Ends the console.
    void stop();
    // Updates the main window. Applies the changes
    void update();
    // Clear the main window. Clears to the background color.
    void clear();
    
    // Quick version for accessing the main window.
    inline void addch(int x, int y, char c, const color &fg)
    {
        stdwin->addch(x, y, c, fg);
    }
    
    inline void addch(int x, int y, char c, const color &fg, const color &bg)
    {
        stdwin->addch(x, y, c, fg, bg);
    }
    
    inline void addstr(int x, int y, const char * str, const color &fg)
    {
        stdwin->addstr(x, y, str, fg);
    }
    
    inline void addstr(int x, int y, const char * str, const color &fg, const color &bg)
    {
        stdwin->addstr(x, y, str, fg, bg);
    }
    
    inline void blit(int x, int y, const window &win)
    {
        stdwin->blit(x, y, win);
    }
    
    // Returns a key.
    key getkey();
    // Returns true if the application is running. (no quit command)
    bool is_running();
    // Makes the next call to is_running return false.
    void stop_running();
    
    // Sets an imbedded font character to a new one.
    bool set_font_char(int c, bool rep[FONT_HEIGHT][FONT_WIDTH]);
} // namespace at

#endif // AT_HPP
