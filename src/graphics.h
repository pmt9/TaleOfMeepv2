#ifndef _GRAPHICS_
#define _GRAPHICS_

#include "SDL.h"
#include "SDL_image.h"

enum colors {Red = 1,Green = 2,Blue = 3,Yellow = 4,Orange = 5,Violet = 6,Brown = 7,Grey = 8,DarkRed = 9,DarkGreen = 10,
               DarkBlue = 11,DarkYellow = 12,DarkOrange = 13,DarkViolet = 14,DarkBrown = 15,DarkGrey = 16,LightRed =17,
               LightGreen = 18,LightBlue = 19,LightYellow = 20,LightOrange = 21,LightViolet = 22,LightBrown = 23,LightGrey = 24,
               Black = 25,White = 26,Tan = 27,Gold = 28,Silver = 29,YellowGreen = 30,Cyan = 31,Magenta = 32};

enum FONTS{F_Small, F_Medium, F_Large};

typedef struct Sprite_T
{
	SDL_Surface *image;
	char filename[40];
	int w,h; //width and heidght of the individual fram, not the whole image
	int framesperline;
	int used;
}Sprite;

typedef struct
{
	int xres, yres, depth;
}ScreenData;

//basics
void Init_Graphics(int windowed);
void DrawPixel(SDL_Surface *screen, Uint8 R, Uint8 G, Uint8 B, int x, int y);
void DrawSquareLine(SDL_Surface *screen, Uint32 color, int sx, int xy, int gx, int gy);
void ShowImgage(SDL_Surface *image, SDL_Surface *screen, int x, int y);
Uint32 getpixel(SDL_Surface *surface, int x, int y);
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
void DrawFilledRect(int sx,int sy, int sw, int sh, Uint32 Color, SDL_Surface *surface);
void DrawRect(int sx,int sy, int sw, int sh, Uint32 Color, SDL_Surface *surface);
void DrawElipse(int ox,int oy, int radius, Uint32 Color, SDL_Surface *surface);
void DrawAnyLine(int sx,int sy,int dx, int dy,Uint32 Color,SDL_Surface *surface);
void DrawThickLine(int sx,int sy,int dx, int dy,int width,Uint32 Color,SDL_Surface *surface);

/*sprite functions*/
void InitSpriteList();
void FreeSprite(Sprite *img);
Sprite *LoadSprite(char *filename,int sizex, int sizey);
void DrawSprite(Sprite *sprite,SDL_Surface *surface,int sx,int sy, int frame);
void DrawGreySprite(Sprite *sprite,SDL_Surface *surface,int sx,int sy, int frame);
void DrawSpritePixel(Sprite *sprite,SDL_Surface *surface,int sx,int sy, int frame);
void CloseSprites();

/*'palette swapping functions*/
Sprite *LoadSwappedSprite(char *filename,int sizex, int sizey);
Uint32 SetColor(Uint32 color, int newcolor1,int newcolor2, int newcolor3);
//void SwapSprite(SDL_Surface *sprite);
Uint32 IndexColor(int color);

/*frame handling functions*/
void BlankScreen(SDL_Surface *buf,Uint32 color);
void FrameDelay(Uint32 delay);
void ResetBuffer();
void NextFrame();

/*font stuff*/
void LoadFonts();
void LoadFont(char filename[40],int ptsize,int type);
void DrawText(char *text,SDL_Surface *surface,int sx,int sy,Uint32 color,int size);
void DrawTextCentered(char *text,SDL_Surface *surface,int sx,int sy,Uint32 color,int size);
void DrawMessages();
void InitMessages();
void NewMessage(char *text,Uint32 color);

#endif