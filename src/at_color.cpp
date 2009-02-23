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

namespace at
{
    Uint32 color::black = 0;
    Uint32 color::blue = 0;
    Uint32 color::cyan = 0;
    Uint32 color::green = 0;
    Uint32 color::magenta = 0;
    Uint32 color::red = 0;
    Uint32 color::white = 0;
    Uint32 color::yellow = 0;
    
    void color::init()
    {
        SDL_Surface *s = SDL_GetVideoSurface();
        color::black = SDL_MapRGB(s->format, 0x00, 0x00, 0x00);
        color::blue = SDL_MapRGB(s->format, 0x00, 0x00, 0xFF);
        color::cyan = SDL_MapRGB(s->format, 0x00, 0xFF, 0xFF);
        color::green = SDL_MapRGB(s->format, 0x00, 0xFF, 0x00);
        color::magenta = SDL_MapRGB(s->format, 0xFF, 0x00, 0xFF);
        color::red = SDL_MapRGB(s->format, 0xFF, 0x00, 0x00);
        color::white = SDL_MapRGB(s->format, 0xFF, 0xFF, 0xFF);
        color::yellow = SDL_MapRGB(s->format, 0xFF, 0xFF, 0x00);
    }
} // namespace at
