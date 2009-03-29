/* Copyright (c) 2009, Michael Patraw
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * The name of Michael Patraw may not be used to endorse or promote
 *       products derived from this software without specific prior written
 *       permission.
 *
 * THIS SOFTWARE IS PROVIDED BY Michael Patraw ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Michael Patraw BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef AT_H
#define AT_H

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************\
 ATLIB Event Operations
\******************************************************************************/

enum {
    ATK_QUIT    = -1,
	ATK_NONE    = 0,
	
	ATK_FIRST      = 0,
	ATK_BACKSPACE  = 8,
	ATK_TAB        = 9,
	ATK_CLEAR      = 12,
	ATK_RETURN     = 13,
	ATK_PAUSE      = 19,
	ATK_ESCAPE     = 27,
	ATK_SPACE	   = 32,
	ATK_EXCLAIM    = 33,
	ATK_QUOTEDBL   = 34,
	ATK_HASH	   = 35,
	ATK_DOLLAR	   = 36,
	ATK_AMPERSAND  = 38,
	ATK_QUOTE	   = 39,
	ATK_LEFTPAREN  = 40,
	ATK_RIGHTPAREN = 41,
	ATK_ASTERISK   = 42,
	ATK_PLUS	   = 43,
	ATK_COMMA	   = 44,
	ATK_MINUS      = 45,
	ATK_PERIOD     = 46,
	ATK_SLASH      = 47,
	ATK_0		   = 48,
	ATK_1		   = 49,
	ATK_2		   = 50,
	ATK_3		   = 51,
	ATK_4		   = 52,
	ATK_5		   = 53,
	ATK_6		   = 54,
	ATK_7		   = 55,
	ATK_8		   = 56,
	ATK_9		   = 57,
	ATK_COLON	   = 58,
	ATK_SEMICOLON  = 59,
	ATK_LESS	   = 60,
	ATK_EQUALS	   = 61,
	ATK_GREATER    = 62,
	ATK_QUESTION   = 63,
	ATK_AT		   = 64,

	ATK_LEFTBRACKET	 = 91,
	ATK_BACKSLASH	 = 92,
	ATK_RIGHTBRACKET = 93,
	ATK_CARET        = 94,
	ATK_UNDERSCORE   = 95,
	ATK_BACKQUOTE    = 96,
	ATK_a            = 97,
	ATK_b			 = 98,
	ATK_c			 = 99,
	ATK_d			 = 100,
	ATK_e			 = 101,
	ATK_f			 = 102,
	ATK_g			 = 103,
	ATK_h			 = 104,
	ATK_i			 = 105,
	ATK_j			 = 106,
	ATK_k			 = 107,
	ATK_l			 = 108,
	ATK_m			 = 109,
	ATK_n			 = 110,
	ATK_o			 = 111,
	ATK_p			 = 112,
	ATK_q			 = 113,
	ATK_r			 = 114,
	ATK_s			 = 115,
	ATK_t			 = 116,
	ATK_u			 = 117,
	ATK_v			 = 118,
	ATK_w			 = 119,
	ATK_x			 = 120,
	ATK_y			 = 121,
	ATK_z			 = 122,
	ATK_DELETE		 = 127,

	ATK_KP0         = 256,
	ATK_KP1		    = 257,
	ATK_KP2		    = 258,
	ATK_KP3		    = 259,
	ATK_KP4		    = 260,
	ATK_KP5		    = 261,
	ATK_KP6		    = 262,
	ATK_KP7		    = 263,
	ATK_KP8		    = 264,
	ATK_KP9		    = 265,
	ATK_KP_PERIOD	= 266,
	ATK_KP_DIVIDE	= 267,
	ATK_KP_MULTIPLY	= 268,
	ATK_KP_MINUS	= 269,
	ATK_KP_PLUS		= 270,
	ATK_KP_ENTER	= 271,
	ATK_KP_EQUALS	= 272,

	ATK_UP			= 273,
	ATK_DOWN		= 274,
	ATK_RIGHT		= 275,
	ATK_LEFT		= 276,
	ATK_INSERT		= 277,
	ATK_HOME		= 278,
	ATK_END		    = 279,
	ATK_PAGEUP		= 280,
	ATK_PAGEDOWN	= 281,

	ATK_F1		= 282,
	ATK_F2		= 283,
	ATK_F3		= 284,
	ATK_F4		= 285,
	ATK_F5		= 286,
	ATK_F6		= 287,
	ATK_F7		= 288,
	ATK_F8		= 289,
	ATK_F9		= 290,
	ATK_F10		= 291,
	ATK_F11		= 292,
	ATK_F12		= 293,
	ATK_F13		= 294,
	ATK_F14		= 295,
	ATK_F15		= 296,

	ATK_NUMLOCK		= 300,
	ATK_CAPSLOCK	= 301,
	ATK_SCROLLOCK	= 302,
	ATK_RSHIFT		= 303,
	ATK_LSHIFT		= 304,
	ATK_RCTRL		= 305,
	ATK_LCTRL		= 306,
	ATK_RALT		= 307,
	ATK_LALT		= 308,
	ATK_RMETA		= 309,
	ATK_LMETA		= 310,
	ATK_LSUPER		= 311,
	ATK_RSUPER		= 312,
	ATK_MODE		= 313,
	ATK_COMPOSE		= 314,

	ATK_HELP		= 315,
	ATK_PRINT		= 316,
	ATK_SYSREQ		= 317,
	ATK_BREAK		= 318,
	ATK_MENU		= 319,
	ATK_POWER		= 320,
	ATK_EURO		= 321,
	ATK_UNDO		= 322,

	ATK_LAST
};


/* Waits for a key to be pressed.
 */
extern int atGetKey(void);

/* Doesn't wait for a key to be pressed.
 */
extern int atGrabKey(void);

/******************************************************************************\
 ATLIB Color
\******************************************************************************/

typedef struct AtColor {
    unsigned char r, g, b;
} AtColor;

/* Standard terminal colors.
 */
extern const AtColor ATC_STDBLACK;
extern const AtColor ATC_STDBLUE;
extern const AtColor ATC_STDCYAN;
extern const AtColor ATC_STDGREEN;
extern const AtColor ATC_STDMAGENTA;
extern const AtColor ATC_STDRED;
extern const AtColor ATC_STDWHITE;
extern const AtColor ATC_STDYELLOW;

/* Additional colors.
 */
extern const AtColor ATC_ALICEBLUE;
extern const AtColor ATC_ANTIQUEWHITE;
extern const AtColor ATC_AQUA;
extern const AtColor ATC_AQUAMARINE;
extern const AtColor ATC_AZURE;
extern const AtColor ATC_BEIGE;
extern const AtColor ATC_BISQUE;
extern const AtColor ATC_BLACK;
extern const AtColor ATC_BLANCHEDALMOND;
extern const AtColor ATC_BLUE;
extern const AtColor ATC_BLUEVIOLET;
extern const AtColor ATC_BROWN;
extern const AtColor ATC_BURLYWOOD;
extern const AtColor ATC_CADETBLUE;
extern const AtColor ATC_CHARTREUSE;
extern const AtColor ATC_CHOCOLATE;
extern const AtColor ATC_CORAL;
extern const AtColor ATC_CORNFLOWERBLUE;
extern const AtColor ATC_CORNSILK;
extern const AtColor ATC_CRIMSON;
extern const AtColor ATC_CYAN;
extern const AtColor ATC_DARKBLUE;
extern const AtColor ATC_DARKCYAN;
extern const AtColor ATC_DARKGOLDENROD;
extern const AtColor ATC_DARKGRAY;
extern const AtColor ATC_DARKGREY;
extern const AtColor ATC_DARKGREEN;
extern const AtColor ATC_DARKKHAKI;
extern const AtColor ATC_DARKMAGENTA;
extern const AtColor ATC_DARKOLIVEGREEN;
extern const AtColor ATC_DARKORANGE;
extern const AtColor ATC_DARKORCHID;
extern const AtColor ATC_DARKRED;
extern const AtColor ATC_DARKSALMON;
extern const AtColor ATC_DARKSEAGREEN;
extern const AtColor ATC_DARKSLATEBLUE;
extern const AtColor ATC_DARKSLATEGRAY;
extern const AtColor ATC_DARKSLATEGREY;
extern const AtColor ATC_DARKTURQUOISE;
extern const AtColor ATC_DARKVIOLET;
extern const AtColor ATC_DEEPPINK;
extern const AtColor ATC_DEEPSKYBLUE;
extern const AtColor ATC_DIMGRAY;
extern const AtColor ATC_DIMGREY;
extern const AtColor ATC_DODGERBLUE;
extern const AtColor ATC_FIREBRICK;
extern const AtColor ATC_FLORALWHITE;
extern const AtColor ATC_FORESTGREEN;
extern const AtColor ATC_FUCHSIA;
extern const AtColor ATC_GAINSBORO;
extern const AtColor ATC_GHOSTWHITE;
extern const AtColor ATC_GOLD;
extern const AtColor ATC_GOLDENROD;
extern const AtColor ATC_GRAY;
extern const AtColor ATC_GREY;
extern const AtColor ATC_GREEN;
extern const AtColor ATC_GREENYELLOW ;
extern const AtColor ATC_HONEYDEW;
extern const AtColor ATC_HOTPINK;
extern const AtColor ATC_INDIANRED;
extern const AtColor ATC_INDIGO;
extern const AtColor ATC_IVORY;
extern const AtColor ATC_KHAKI;
extern const AtColor ATC_LAVENDER;
extern const AtColor ATC_LAVENDERBLUSH;
extern const AtColor ATC_LAWNGREEN;
extern const AtColor ATC_LEMONCHIFFON;
extern const AtColor ATC_LIGHTBLUE;
extern const AtColor ATC_LIGHTCORAL;
extern const AtColor ATC_LIGHTCYAN;
extern const AtColor ATC_LIGHTGOLDENRODYELLOW;
extern const AtColor ATC_LIGHTGRAY;
extern const AtColor ATC_LIGHTGREY;
extern const AtColor ATC_LIGHTGREEN;
extern const AtColor ATC_LIGHTPINK;
extern const AtColor ATC_LIGHTSALMON;
extern const AtColor ATC_LIGHTSEAGREEN;
extern const AtColor ATC_LIGHTSKYBLUE;
extern const AtColor ATC_LIGHTSLATEGRAY;
extern const AtColor ATC_LIGHTSLATEGREY;
extern const AtColor ATC_LIGHTSTEELBLUE;
extern const AtColor ATC_LIGHTYELLOW;
extern const AtColor ATC_LIME;
extern const AtColor ATC_LIMEGREEN;
extern const AtColor ATC_LINEN;
extern const AtColor ATC_MAGENTA;
extern const AtColor ATC_MAROON;
extern const AtColor ATC_MEDIUMAQUAMARINE;
extern const AtColor ATC_MEDIUMBLUE;
extern const AtColor ATC_MEDIUMORCHID;
extern const AtColor ATC_MEDIUMPURPLE;
extern const AtColor ATC_MEDIUMSEAGREEN;
extern const AtColor ATC_MEDIUMSLATEBLUE;
extern const AtColor ATC_MEDIUMSPRINGGREEN;
extern const AtColor ATC_MEDIUMTURQUOISE;
extern const AtColor ATC_MEDIUMVIOLETRED;
extern const AtColor ATC_MIDNIGHTBLUE;
extern const AtColor ATC_MINTCREAM;
extern const AtColor ATC_MISTYROSE;
extern const AtColor ATC_MOCCASIN;
extern const AtColor ATC_NAVAJOWHITE;
extern const AtColor ATC_NAVY;
extern const AtColor ATC_OLDLACE;
extern const AtColor ATC_OLIVE;
extern const AtColor ATC_OLIVEDRAB;
extern const AtColor ATC_ORANGE;
extern const AtColor ATC_ORANGERED;
extern const AtColor ATC_ORCHID;
extern const AtColor ATC_PALEGOLDENROD;
extern const AtColor ATC_PALEGREEN;
extern const AtColor ATC_PALETURQUOISE;
extern const AtColor ATC_PALEVIOLETRED;
extern const AtColor ATC_PAPAYAWHIP;
extern const AtColor ATC_PEACHPUFF;
extern const AtColor ATC_PERU;
extern const AtColor ATC_PINK;
extern const AtColor ATC_PLUM;
extern const AtColor ATC_POWDERBLUE;
extern const AtColor ATC_PURPLE;
extern const AtColor ATC_RED;
extern const AtColor ATC_ROSYBROWN;
extern const AtColor ATC_ROYALBLUE;
extern const AtColor ATC_SADDLEBROWN;
extern const AtColor ATC_SALMON;
extern const AtColor ATC_SANDYBROWN;
extern const AtColor ATC_SEAGREEN;
extern const AtColor ATC_SEASHELL;
extern const AtColor ATC_SIENNA;
extern const AtColor ATC_SILVER;
extern const AtColor ATC_SKYBLUE;
extern const AtColor ATC_SLATEBLUE;
extern const AtColor ATC_SLATEGRAY;
extern const AtColor ATC_SLATEGREY;
extern const AtColor ATC_SNOW;
extern const AtColor ATC_SPRINGGREEN;
extern const AtColor ATC_STEELBLUE;
extern const AtColor ATC_TAN;
extern const AtColor ATC_TEAL;
extern const AtColor ATC_THISTLE;
extern const AtColor ATC_TOMATO;
extern const AtColor ATC_TURQUOISE;
extern const AtColor ATC_VIOLET;
extern const AtColor ATC_WHEAT;
extern const AtColor ATC_WHITE;
extern const AtColor ATC_WHITESMOKE;
extern const AtColor ATC_YELLOW;
extern const AtColor ATC_YELLOWGREEN;

/******************************************************************************\
 ATLIB Font/Char Operations
\******************************************************************************/

/* Font dimensions. */
#define AT_FONT_WIDTH  6
#define AT_FONT_HEIGHT 13

/* Checks if the location, c, is an already defined character like '@'.
 *  Returns 1 if it's defined, otherwise returns 0.
 */
extern int atCharIsDefined(
    int c /* The character to check. */
);

/* Sets a character to a custom one. Returns 1 on success, 0 on failure.
 */
extern int atCharSet(
    int c,                                  /* The character to change. */
    char rep[AT_FONT_HEIGHT][AT_FONT_WIDTH] /* The new character. */
);

/******************************************************************************\
 ATLIB Window Operations
\******************************************************************************/

/* Declared opaque. */
typedef struct AtWindow AtWindow;

/* Returns a pointer to a new window structure.
 */
extern AtWindow * atWindowCreate(
    int width, /* Width of the window. Default terminal width is 80. */
    int height /* Height of the window. Default terminal Height is 24. */
);

/* Destroys a window.
 */
extern void atWindowDestroy(
    AtWindow * win /* The window to be destroyed. */
);

/* Returns the width of a window.
 */
extern int atWindowWidth(
    AtWindow * win /* The window to determine the width of. */
);

/* Returns the height of a window.
 */
extern int atWindowHeight(
    AtWindow * win /* The window to determine the height of. */
);

/* Returns the absolute width of a window.
 */
extern int atWindowWidthAbs(
    AtWindow * win /* The window to determine the width of. */
);

/* Returns the absolute height of a window.
 */
extern int atWindowHeightAbs(
    AtWindow * win /* The window to determine the height of. */
);

/* Returns a copy of the background color to a window.
 */
extern AtColor atWindowGetBgColor(
    AtWindow * win /* The window to return the background color of. */
);

/* Sets a window's background color to a specific color.
 */
extern void atWindowSetBgColor(
    AtWindow * win, /* The window to set the background color of. */
    AtColor col   /* The background color to set to. */
);

/* Draws a pixel to a window.
 * NOTE: Doesn't use cell locations like other functions.
 */
extern void atWindowDrawPixel(
    AtWindow * win, /* The window to draw the pixel to. */
    int x, int y,   /* The location to put the pixel. */
    AtColor col   /* The color of the pixel. */
);

/* Draws a character to a window.
 */
extern void atWindowDrawChar(
    AtWindow * win, /* The window to draw the character to. */
    int x, int y,   /* Location to draw the character. */
    AtColor fg,   /* Foreground color. */
    AtColor bg,   /* Background color. */
    int c         /* The character. */
);

/* Draws a character to a window. Uses absolute coordinates, not cell
 * coordinates.
 */
extern void atWindowDrawCharAbs(
    AtWindow * win, /* The window to draw the character to. */
    int x, int y,   /* Location to draw the character. */
    AtColor fg,   /* Foreground color. */
    AtColor bg,   /* Background color. */
    int c         /* The character. */
);

/* Draws a string to a window.
 */
extern void atWindowDrawString(
    AtWindow * win,  /* The window to draw the string to. */
    int x, int y,    /* Location to draw the string. */
    AtColor fg,      /* Foreground color. */
    AtColor bg,      /* Background color. */
    const char * str /* The string to draw. Must be zero-terminated. */
);

/* Draws a string to a window. Uses absolute coordinates, not cell
 * coordinates.
 */
extern void atWindowDrawStringAbs(
    AtWindow * win,  /* The window to draw the string to. */
    int x, int y,    /* Location to draw the string. */
    AtColor fg,      /* Foreground color. */
    AtColor bg,      /* Background color. */
    const char * str /* The string to draw. Must be zero-terminated. */
);

/* Draws a string to a window, this function wraps the string at spaces if it's
 * too long for the location.
 */
extern void atWindowDrawStringWrap(
    AtWindow * win,  /* The window to draw the string to. */
    int x, int y,    /* Location to draw the string. */
    AtColor fg,      /* Foreground color. */
    AtColor bg,      /* Background color. */
    const char * str /* The string to draw. Must be zero-terminated. */
);

/* Draws a string to a window, this function wraps the string at spaces if it's
 * too long for the location. Uses absolute coordinates, not cell
 * coordinates.
 */
extern void atWindowDrawStringWrapAbs(
    AtWindow * win,  /* The window to draw the string to. */
    int x, int y,    /* Location to draw the string. */
    AtColor fg,      /* Foreground color. */
    AtColor bg,      /* Background color. */
    const char * str /* The string to draw. Must be zero-terminated. */
);

/* Blits one window to another.
 */
extern void atWindowBlit(
    AtWindow * dst, /* The window to blit to. */
    int x, int y,   /* The location on the destination window. */
    AtWindow * src, /* The window to blit from. */
    int sx, int sy, int sw, int sh /* The area of the src window. */
);

/* Blits one window to another. Uses absolute coordinates, not cell
 * coordinates.
 */
extern void atWindowBlitAbs(
    AtWindow * dst, /* The window to blit to. */
    int x, int y,   /* The location on the destination window. */
    AtWindow * src, /* The window to blit from. */
    int sx, int sy, int sw, int sh /* The area of the src window. */
);

/* Clears a window to the background color of the window.
 */
extern void atWindowClear(
    AtWindow * win /* The window to clear. */
);

/******************************************************************************\
 ATLIB Core Operations
\******************************************************************************/

/* Creates the main window with a title. Returns 1 on success, 0 on failure.
 */
extern int atStart(
    const char * title, /* The title of the window. */
    int width,          /* Default terminal width is 80. */
    int height          /* Default terminal Height is 24. */
);

/* Destroys the main window.
 */
extern void atStop(void);

/* Returns 1 if the user hasn't closed the application, 0 otherwise.
 */
extern int atIsRunning(void);

/* Makes it so calls to atIsRunning return 0.
 */
extern void atStopRunning(void);

/* Returns the number of ticks since atStop was called.
 */
extern unsigned int atTicks(void);

/**********************************************
 * Some shortcut functions for the main window.
 */

/* Returns the width of the main window.
 */
extern int atWidth(void);

/* Returns the height of the main window.
 */
extern int atHeight(void);

/* Returns the absolute width of the main window.
 */
extern int atWidthAbs(void);

/* Returns the absolute height of the main window.
 */
extern int atHeightAbs(void);

/* Returns a copy of the background color to the main window.
 */
extern AtColor atGetBgColor(void);

/* Sets the main window's background color to a specific color.
 */
extern void atSetBgColor(
    AtColor col   /* The background color to set to. */
);

/* Draws a pixel to the main window.
 * NOTE: Doesn't use cell locations like other functions.
 */
extern void atDrawPixel(
    int x, int y,   /* The location to put the pixel. */
    AtColor col   /* The color of the pixel. */
);

/* Draws a character to the main window.
 */
extern void atDrawChar(
    int x, int y,   /* Location to draw the character. */
    AtColor fg,    /* Foreground color. */
    AtColor bg,    /* Background color. */
    int c          /* The character. */
);

/* Draws a character to the main window. Uses absolute coordinates, not cell
 * coordinates.
 */
extern void atDrawCharAbs(
    int x, int y,   /* Location to draw the character. */
    AtColor fg,    /* Foreground color. */
    AtColor bg,    /* Background color. */
    int c          /* The character. */
);

/* Draws a string to the main window. 
 */
extern void atDrawString(
    int x, int y,    /* Location to draw the string. */
    AtColor fg,      /* Foreground color. */
    AtColor bg,      /* Background color. */
    const char * str /* The string to draw. Must be zero-terminated. */
);

/* Draws a string to the main window. Uses absolute coordinates, not cell
 * coordinates.
 */
extern void atDrawStringAbs(
    int x, int y,    /* Location to draw the string. */
    AtColor fg,      /* Foreground color. */
    AtColor bg,      /* Background color. */
    const char * str /* The string to draw. Must be zero-terminated. */
);

/* Draws a string to the main window, this function wraps the string at spaces 
 * if it's too long for the location.
 */
extern void atDrawStringWrap(
    int x, int y,    /* Location to draw the string. */
    AtColor fg,      /* Foreground color. */
    AtColor bg,      /* Background color. */
    const char * str /* The string to draw. Must be zero-terminated. */
);

/* Draws a string to the main window, this function wraps the string at spaces 
 * if it's too long for the location. Uses absolute coordinates, not cell
 * coordinates.
 */
extern void atDrawStringWrapAbs(
    int x, int y,    /* Location to draw the string. */
    AtColor fg,      /* Foreground color. */
    AtColor bg,      /* Background color. */
    const char * str /* The string to draw. Must be zero-terminated. */
);

/* Blits one window to the main window.
 */
extern void atBlit(
    int x, int y,   /* The location on the destination window. */
    AtWindow * src, /* The window to blit from. */
    int sx, int sy, int sw, int sh /* The area of the src window, -1 is full. */
);

/* Blits one window to the main window. Uses absolute coordinates, not cell
 * coordinates.
 */
extern void atBlitAbs(
    int x, int y,   /* The location on the destination window. */
    AtWindow * src, /* The window to blit from. */
    int sx, int sy, int sw, int sh /* The area of the src window, -1 is full. */
);

/* Clears the main window to the background color of the window.
 */
extern void atClear(void);

/* Updates the main window.
 */
extern void atUpdate(void);

#ifdef __cplusplus
}
#endif

#endif /* AT_H */
