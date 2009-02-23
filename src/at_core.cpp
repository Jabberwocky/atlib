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
#include "at_internal.hpp"

namespace at
{
    window *start(const char *title, int width, int height)
    {
        int scr_width, scr_height;
        unsigned int flags = SDL_SWSURFACE | SDL_DOUBLEBUF;
        
        if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
            return NULL;
        
        
        _cell_to_screen(width, height, &scr_width, &scr_height);
        stdwin = new window(SDL_SetVideoMode(scr_width, scr_height, 32, flags));
        
        if (stdwin == NULL)
            return NULL;
            
        SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,
            SDL_DEFAULT_REPEAT_INTERVAL);
        
        SDL_WM_SetCaption(title, NULL);
        
        // Initialize color.
        color::init();
        
        return stdwin;
    }
    
    void stop()
    {
        if (stdwin)
            delete stdwin;
        SDL_Quit();
    }
    
    void update()
    {
        assert(stdwin != NULL);
        stdwin->update();
    }
    
    void clear()
    {
        assert(stdwin != NULL);
        stdwin->clear();
    }

} // namespace at
