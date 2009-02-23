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
#include <cctype>
#include <SDL/SDL.h>

#include "at.hpp"

namespace at
{
    bool running = true;

    key _sdl_to_at(SDL_Event *ev)
    {
        SDLMod mod = SDL_GetModState();

        switch (ev->type)
        {
            // KEYS
            case SDL_KEYDOWN:
                // Character representations.
                if (ev->key.keysym.sym >= 33 && ev->key.keysym.sym <= 127)
                {
                    // Allows capital letters.
                    if (mod & KMOD_LSHIFT || mod & KMOD_RSHIFT)
                        return (key)toupper(ev->key.keysym.sym);
                    else
                        return (key)ev->key.keysym.sym;
                }

                switch (ev->key.keysym.sym)
                {
                    case SDLK_UP:
                        return ATK_UP;
                    case SDLK_DOWN:
                        return ATK_DOWN;
                    case SDLK_LEFT:
                        return ATK_LEFT;
                    case SDLK_RIGHT:
                        return ATK_RIGHT;
                    default:
                        return ATK_NONE;
                }
            // MOUSE
            case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                return ATK_NONE;
            // QUITTING
            case SDL_QUIT:
                running = false;
                return ATK_QUIT;
            default:
                return ATK_NONE;
        }
    }

    key getkey()
    {
        static SDL_Event ev;
        key ret;
        
        // Flushes the event queue.
        while (SDL_PollEvent(&ev))
            ;
        
        do
        {
            SDL_WaitEvent(&ev);
            ret = _sdl_to_at(&ev);
        } while (ret == ATK_NONE);
        
        return ret;
    }
    
    bool is_running()
    {
        return running;
    }
    
    void stop_running()
    {
        running = false;
    }
} // namespace at
