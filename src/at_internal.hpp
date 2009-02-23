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
#ifndef AT_INTERNAL_HPP
#define AT_INTERNAL_HPP

#include <SDL/SDL.h>

#include "at.hpp"

namespace at
{
    inline Uint32 _at_to_sdl_color(const color &c)
    {
        return
        SDL_MapRGB(SDL_GetVideoSurface()->format, c.red(), c.green(), c.blue());
    }
    
    inline void _cell_to_screen(int x, int y, int *nx, int *ny)
    {
        if (nx)
            *nx = x * FONT_WIDTH;
        if (ny)
            *ny = y * FONT_HEIGHT;
    }
    
    inline void _screen_to_cell(int x, int y, int *nx, int *ny)
    {
        if (nx)
            *nx = x / FONT_WIDTH;
        if (ny)
            *ny = y / FONT_HEIGHT;
    }
} // namespace at

#endif // AT_INTERNAL_HPP
