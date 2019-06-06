// Author: okelykodely

#include <windows.h>
#include <stdio.h>

int c = 0;

#define PLAY_AGAIN_BUTTON 100

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#include <wingdi.h>
#define GetCurrentDir getcwd
#endif

int showNextBg = 1;

HWND hwnd;
HWND hwnd_title;
HWND hwnd_new_game;
HWND hwnd_stage;
HWND hwnd_next;
HWND hwnd_lines;
HWND hwnd_points;
HWND hwnd_blocks;
HWND hwnd_level;

char g_szClassName[] = "WinTris";
char filename[FILENAME_MAX];
char buff[FILENAME_MAX];
char* choice;
char * choicepre = "sq";
int sleeptime = 800;
int points=0;
int level = 1;
int blocks=0;
int lines=0;
int linenext = 10;
int b[740][720];

HINSTANCE hInst;
BITMAP bitmap;
WNDCLASSEX wc;
HDC hdcMem;
HGDIOBJ oldBitmap;
HBITMAP hBitmap, hb1,hb2,hb3,hb4,hb5;
HFONT font;
MSG Msg;
HANDLE thread, thrad;
BOOLEAN fist = TRUE;
HDC hdc;
HDC hdc2;
PAINTSTRUCT ps;
BITMAP bitmaps;
HDC hdcMems;
HGDIOBJ oldBitmaps;
HBITMAP hbitmap, hhbbs;

struct hat {
  int x0;
  int y0;
  int x1;
  int y1;
  int x2;
  int y2;
  int x3;
  int y3;
  int dir;
} ht;

struct square {
  int x0;
  int y0;
  int x1;
  int y1;
  int x2;
  int y2;
  int x3;
  int y3;
} sq;

struct line {
  int x0;
  int y0;
  int x1;
  int y1;
  int x2;
  int y2;
  int x3;
  int y3;
  int dir;
} lne;

struct lsho {
  int x0;
  int y0;
  int x1;
  int y1;
  int x2;
  int y2;
  int x3;
  int y3;
  int dir;
} lsh;

struct rsho {
  int x0;
  int y0;
  int x1;
  int y1;
  int x2;
  int y2;
  int x3;
  int y3;
  int dir;
} rsh;

struct larm {
  int x0;
  int y0;
  int x1;
  int y1;
  int x2;
  int y2;
  int x3;
  int y3;
  int dir;
} larm;

struct rarm {
  int x0;
  int y0;
  int x1;
  int y1;
  int x2;
  int y2;
  int x3;
  int y3;
  int dir;
} rarm;

BOOL goDown() {
    BOOL canGoDown = FALSE;
    
    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));

    RECT rrect3 = {219, 20, 420, 690};
    //FillRect(hdc2, &rrect3, brush);
    hb1 = (HBITMAP)LoadImage(hInst, "bg1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    oldBitmap = SelectObject(hdcMems, hb1);
    GetObject(hb1, sizeof(bitmap), &bitmap);
    BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);
    SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
    DeleteDC(hdcMems); DeleteObject(hb1);

    if(choice == "sq" && (sq.y0 <= 630 && sq.y1 <= 630 && sq.y2 <= 630 && sq.y3 <= 630)) {
        sq.y0 += 20;
        sq.y1 += 20;
        sq.y2 += 20;
        sq.y3 += 20;

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(sq.y0 > 650 || sq.y1 > 650 || sq.y2 > 650 || sq.y3 > 650) {
            b[sq.x0][sq.y0] = 1;
            b[sq.x1][sq.y1] = 1;
            b[sq.x2][sq.y2] = 1;
            b[sq.x3][sq.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else {
        }

        BOOLEAN flag = FALSE;
        if(b[sq.x0][sq.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[sq.x1][sq.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[sq.x2][sq.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[sq.x3][sq.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            canGoDown = FALSE;
            b[sq.x0][sq.y0] = 1;
            b[sq.x1][sq.y1] = 1;
            b[sq.x2][sq.y2] = 1;
            b[sq.x3][sq.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else
            canGoDown = TRUE;
          
        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
    }
    else if(choice == "lne" && (lne.y0 <= 580 || lne.y1 <= 580 || lne.y2 <= 580 || lne.y3 <= 580)) {
        lne.y0 += 20;
        lne.y1 += 20;
        lne.y2 += 20;
        lne.y3 += 20;

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(lne.y0 > 650 || lne.y1 > 650 || lne.y2 > 650 || lne.y3 > 650) {
            b[lne.x0][lne.y0] = 1;
            b[lne.x1][lne.y1] = 1;
            b[lne.x2][lne.y2] = 1;
            b[lne.x3][lne.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else {
        }

        BOOLEAN flag = FALSE;
        if(b[lne.x0][lne.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[lne.x1][lne.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[lne.x2][lne.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[lne.x3][lne.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            canGoDown = FALSE;
            b[lne.x0][lne.y0] = 1;
            b[lne.x1][lne.y1] = 1;
            b[lne.x2][lne.y2] = 1;
            b[lne.x3][lne.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else
            canGoDown = TRUE;

        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
    }
    else if(choice == "ht" && (ht.y0 <= 650 && ht.y1 <= 650 && ht.y2 <= 650 && ht.y3 <= 650)) {
        ht.y0 += 20;
        ht.y1 += 20;
        ht.y2 += 20;
        ht.y3 += 20;

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(ht.y0 > 650 || ht.y1 > 650 || ht.y2 > 650 || ht.y3 > 650) {
            b[ht.x0][ht.y0] = 1;
            b[ht.x1][ht.y1] = 1;
            b[ht.x2][ht.y2] = 1;
            b[ht.x3][ht.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else {
        }

        BOOLEAN flag = FALSE;
        if(b[ht.x0][ht.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[ht.x1][ht.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[ht.x2][ht.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[ht.x3][ht.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            canGoDown = FALSE;
            b[ht.x0][ht.y0] = 1;
            b[ht.x1][ht.y1] = 1;
            b[ht.x2][ht.y2] = 1;
            b[ht.x3][ht.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else
            canGoDown = TRUE;
        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
    }
    else if(choice == "larm" && (larm.y0 <= 650 && larm.y1 <= 650 && larm.y2 <= 650 && larm.y3 <= 650)) {
        larm.y0 += 20;
        larm.y1 += 20;
        larm.y2 += 20;
        larm.y3 += 20;

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(larm.y0 > 650 || larm.y1 > 650 || larm.y2 > 650 || larm.y3 > 650) {
            b[larm.x0][larm.y0] = 1;
            b[larm.x1][larm.y1] = 1;
            b[larm.x2][larm.y2] = 1;
            b[larm.x3][larm.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else {
        }

        BOOLEAN flag = FALSE;
        if(b[larm.x0][larm.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[larm.x1][larm.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[larm.x2][larm.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[larm.x3][larm.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            canGoDown = FALSE;
            b[larm.x0][larm.y0] = 1;
            b[larm.x1][larm.y1] = 1;
            b[larm.x2][larm.y2] = 1;
            b[larm.x3][larm.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else
            canGoDown = TRUE;
          
        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                    Rectangle(hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(hdc2, hOldPen));
                    SelectObject(hdc2, hOldBsh);
                }
            }
        }
    }
    else if(choice == "rarm" && (rarm.y0 <= 650 && rarm.y1 <= 650 && rarm.y2 <= 650 && rarm.y3 <= 650)) {
        rarm.y0 += 20;
        rarm.y1 += 20;
        rarm.y2 += 20;
        rarm.y3 += 20;

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(rarm.y0 > 650 || rarm.y1 > 650 || rarm.y2 > 650 || rarm.y3 > 650) {
            b[rarm.x0][rarm.y0] = 1;
            b[rarm.x1][rarm.y1] = 1;
            b[rarm.x2][rarm.y2] = 1;
            b[rarm.x3][rarm.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else {
        }

        BOOLEAN flag = FALSE;
        if(b[rarm.x0][rarm.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[rarm.x1][rarm.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[rarm.x2][rarm.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[rarm.x3][rarm.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            canGoDown = FALSE;
            b[rarm.x0][rarm.y0] = 1;
            b[rarm.x1][rarm.y1] = 1;
            b[rarm.x2][rarm.y2] = 1;
            b[rarm.x3][rarm.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else
            canGoDown = TRUE;

        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                    Rectangle(hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(hdc2, hOldPen));
                    SelectObject(hdc2, hOldBsh);
                }
            }
        }
    }
    else if(choice == "lsh" && (lsh.y0 <= 650 && lsh.y1 <= 650 && lsh.y2 <= 650 && lsh.y3 <= 650)) {
        lsh.y0 += 20;
        lsh.y1 += 20;
        lsh.y2 += 20;
        lsh.y3 += 20;

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(lsh.y0 > 650 || lsh.y1 > 650 || lsh.y2 > 650 || lsh.y3 > 650) {
            b[lsh.x0][lsh.y0] = 1;
            b[lsh.x1][lsh.y1] = 1;
            b[lsh.x2][lsh.y2] = 1;
            b[lsh.x3][lsh.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else {
        }

        BOOLEAN flag = FALSE;
        if(b[lsh.x0][lsh.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[lsh.x1][lsh.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[lsh.x2][lsh.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[lsh.x3][lsh.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            canGoDown = FALSE;
            b[lsh.x0][lsh.y0] = 1;
            b[lsh.x1][lsh.y1] = 1;
            b[lsh.x2][lsh.y2] = 1;
            b[lsh.x3][lsh.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else
            canGoDown = TRUE;

        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                    Rectangle(hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(hdc2, hOldPen));
                    SelectObject(hdc2, hOldBsh);
                }
            }
        }
    }
    else if(choice == "rsh" && (rsh.y0 <= 650 && rsh.y1 <= 650 && rsh.y2 <= 650 && rsh.y3 <= 650)) {
        rsh.y0 += 20;
        rsh.y1 += 20;
        rsh.y2 += 20;
        rsh.y3 += 20;

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(rsh.y0 > 650 || rsh.y1 > 650 || rsh.y2 > 650 || rsh.y3 > 650) {
            b[rsh.x0][rsh.y0] = 1;
            b[rsh.x1][rsh.y1] = 1;
            b[rsh.x2][rsh.y2] = 1;
            b[rsh.x3][rsh.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else {
        }

        BOOLEAN flag = FALSE;
        if(b[rsh.x0][rsh.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[rsh.x1][rsh.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[rsh.x2][rsh.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[rsh.x3][rsh.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            canGoDown = FALSE;
            b[rsh.x0][rsh.y0] = 1;
            b[rsh.x1][rsh.y1] = 1;
            b[rsh.x2][rsh.y2] = 1;
            b[rsh.x3][rsh.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        } else
            canGoDown = TRUE;

        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                    Rectangle(hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(hdc2, hOldPen));
                    SelectObject(hdc2, hOldBsh);
                }
            }
        }
    }
    
    DeleteObject(brush);
    
    return canGoDown;
}

void goRight() {
    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));

    RECT rrect3 = {219, 20, 420, 690};
    //FillRect(hdc2, &rrect3, brush);
    hb1 = (HBITMAP)LoadImage(hInst, "bg1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    oldBitmap = SelectObject(hdcMems, hb1);
    GetObject(hb1, sizeof(bitmap), &bitmap);
    BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);
    SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
    DeleteDC(hdcMems); DeleteObject(hb1);

    if(choice == "sq" && (sq.y0 <= 650 && sq.y1 <= 650 && sq.y2 <= 650 && sq.y3 <= 650)) {
        if(b[sq.x0+20][sq.y0] == 0 &&
           b[sq.x1+20][sq.y1] == 0 &&
           b[sq.x2+20][sq.y2] == 0 &&
           b[sq.x3+20][sq.y3] == 0 &&

           sq.x0 < 400 &&
           sq.x1 < 400 &&
           sq.x2 < 400 &&
           sq.x3 < 400
           ) {
            sq.x0 += 20;
            sq.x1 += 20;
            sq.x2 += 20;
            sq.x3 += 20;
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);
    }
    else if(choice == "lne" && (lne.y0 <= 650 && lne.y1 <= 650 && lne.y2 <= 650 && lne.y3 <= 650)) {
        if(b[lne.x0+20][lne.y0] == 0 &&
           b[lne.x1+20][lne.y1] == 0 &&
           b[lne.x2+20][lne.y2] == 0 &&
           b[lne.x3+20][lne.y3] == 0 &&

           lne.x0 < 400 &&
           lne.x1 < 400 &&
           lne.x2 < 400 &&
           lne.x3 < 400
           ) {
            lne.x0 += 20;
            lne.x1 += 20;
            lne.x2 += 20;
            lne.x3 += 20;
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);
    }
    else if(choice == "ht" && (ht.y0 <= 650 && ht.y1 <= 650 && ht.y2 <= 650 && ht.y3 <= 650)) {
        if(b[ht.x0+20][ht.y0] == 0 &&
           b[ht.x1+20][ht.y1] == 0 &&
           b[ht.x2+20][ht.y2] == 0 &&
           b[ht.x3+20][ht.y3] == 0 &&

           ht.x0 < 400 &&
           ht.x1 < 400 &&
           ht.x2 < 400 &&
           ht.x3 < 400
           ) {
            ht.x0 += 20;
            ht.x1 += 20;
            ht.x2 += 20;
            ht.x3 += 20;
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        BOOLEAN flag = FALSE;
        if(b[ht.x0][ht.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[ht.x1][ht.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[ht.x2][ht.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[ht.x3][ht.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            b[ht.x0][ht.y0] = 1;
            b[ht.x1][ht.y1] = 1;
            b[ht.x2][ht.y2] = 1;
            b[ht.x3][ht.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }
        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
    }
    else if(choice == "larm" && (larm.y0 <= 650 && larm.y1 <= 650 && larm.y2 <= 650 && larm.y3 <= 650)) {
        if(b[larm.x0+20][larm.y0] == 0 &&
           b[larm.x1+20][larm.y1] == 0 &&
           b[larm.x2+20][larm.y2] == 0 &&
           b[larm.x3+20][larm.y3] == 0 &&

           larm.x0 < 400 &&
           larm.x1 < 400 &&
           larm.x2 < 400 &&
           larm.x3 < 400
           ) {
            larm.x0 += 20;
            larm.x1 += 20;
            larm.x2 += 20;
            larm.x3 += 20;
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(larm.y0 > 650 || larm.y1 > 650 || larm.y2 > 650 || larm.y3 > 650) {
            b[larm.x0][larm.y0] = 1;
            b[larm.x1][larm.y1] = 1;
            b[larm.x2][larm.y2] = 1;
            b[larm.x3][larm.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }

        BOOLEAN flag = FALSE;
        if(b[larm.x0][larm.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[larm.x1][larm.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[larm.x2][larm.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[larm.x3][larm.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            b[larm.x0][larm.y0] = 1;
            b[larm.x1][larm.y1] = 1;
            b[larm.x2][larm.y2] = 1;
            b[larm.x3][larm.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }
        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                    Rectangle(hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(hdc2, hOldPen));
                    SelectObject(hdc2, hOldBsh);
                }
            }
        }
    }
    else if(choice == "rarm" && (rarm.y0 <= 650 && rarm.y1 <= 650 && rarm.y2 <= 650 && rarm.y3 <= 650)) {
        if(b[rarm.x0+20][rarm.y0] == 0 &&
           b[rarm.x1+20][rarm.y1] == 0 &&
           b[rarm.x2+20][rarm.y2] == 0 &&
           b[rarm.x3+20][rarm.y3] == 0 &&

           rarm.x0 < 400 &&
           rarm.x1 < 400 &&
           rarm.x2 < 400 &&
           rarm.x3 < 400
           ) {
            rarm.x0 += 20;
            rarm.x1 += 20;
            rarm.x2 += 20;
            rarm.x3 += 20;
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(rarm.y0 > 650 || rarm.y1 > 650 || rarm.y2 > 650 || rarm.y3 > 650) {
            b[rarm.x0][rarm.y0] = 1;
            b[rarm.x1][rarm.y1] = 1;
            b[rarm.x2][rarm.y2] = 1;
            b[rarm.x3][rarm.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }

        BOOLEAN flag = FALSE;
        if(b[rarm.x0][rarm.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[rarm.x1][rarm.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[rarm.x2][rarm.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[rarm.x3][rarm.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            b[rarm.x0][rarm.y0] = 1;
            b[rarm.x1][rarm.y1] = 1;
            b[rarm.x2][rarm.y2] = 1;
            b[rarm.x3][rarm.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }
        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                    Rectangle(hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(hdc2, hOldPen));
                    SelectObject(hdc2, hOldBsh);
                }
            }
        }
    }
    else if(choice == "lsh" && (lsh.y0 <= 650 && lsh.y1 <= 650 && lsh.y2 <= 650 && lsh.y3 <= 650)) {
        if(b[lsh.x0+20][lsh.y0] == 0 &&
           b[lsh.x1+20][lsh.y1] == 0 &&
           b[lsh.x2+20][lsh.y2] == 0 &&
           b[lsh.x3+20][lsh.y3] == 0 &&

           lsh.x0 < 400 &&
           lsh.x1 < 400 &&
           lsh.x2 < 400 &&
           lsh.x3 < 400
           ) {
            lsh.x0 += 20;
            lsh.x1 += 20;
            lsh.x2 += 20;
            lsh.x3 += 20;
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(lsh.y0 > 650 || lsh.y1 > 650 || lsh.y2 > 650 || lsh.y3 > 650) {
            b[lsh.x0][lsh.y0] = 1;
            b[lsh.x1][lsh.y1] = 1;
            b[lsh.x2][lsh.y2] = 1;
            b[lsh.x3][lsh.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }

        BOOLEAN flag = FALSE;
        if(b[lsh.x0][lsh.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[lsh.x1][lsh.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[lsh.x2][lsh.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[lsh.x3][lsh.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            b[lsh.x0][lsh.y0] = 1;
            b[lsh.x1][lsh.y1] = 1;
            b[lsh.x2][lsh.y2] = 1;
            b[lsh.x3][lsh.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }
        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                    Rectangle(hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(hdc2, hOldPen));
                    SelectObject(hdc2, hOldBsh);
                }
            }
        }
    }
    else if(choice == "rsh" && (rsh.y0 <= 650 && rsh.y1 <= 650 && rsh.y2 <= 650 && rsh.y3 <= 650)) {
        if(b[rsh.x0+20][rsh.y0] == 0 &&
           b[rsh.x1+20][rsh.y1] == 0 &&
           b[rsh.x2+20][rsh.y2] == 0 &&
           b[rsh.x3+20][rsh.y3] == 0 &&

           rsh.x0 < 400 &&
           rsh.x1 < 400 &&
           rsh.x2 < 400 &&
           rsh.x3 < 400
           ) {
            rsh.x0 += 20;
            rsh.x1 += 20;
            rsh.x2 += 20;
            rsh.x3 += 20;
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(rsh.y0 > 650 || rsh.y1 > 650 || rsh.y2 > 650 || rsh.y3 > 650) {
            b[rsh.x0][rsh.y0] = 1;
            b[rsh.x1][rsh.y1] = 1;
            b[rsh.x2][rsh.y2] = 1;
            b[rsh.x3][rsh.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }

        BOOLEAN flag = FALSE;
        if(b[rsh.x0][rsh.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[rsh.x1][rsh.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[rsh.x2][rsh.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[rsh.x3][rsh.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            b[rsh.x0][rsh.y0] = 1;
            b[rsh.x1][rsh.y1] = 1;
            b[rsh.x2][rsh.y2] = 1;
            b[rsh.x3][rsh.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }
        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                    Rectangle(hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(hdc2, hOldPen));
                    SelectObject(hdc2, hOldBsh);
                }
            }
        }
    }
    
    DeleteObject(brush);
}

void goLeft() {
    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));

    RECT rrect3 = {219, 20, 420, 690};
    //FillRect(hdc2, &rrect3, brush);
    hb1 = (HBITMAP)LoadImage(hInst, "bg1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    oldBitmap = SelectObject(hdcMems, hb1);
    GetObject(hb1, sizeof(bitmap), &bitmap);
    BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);
    SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
    DeleteDC(hdcMems); DeleteObject(hb1);

    if(choice == "sq" && (sq.y0 <= 650 && sq.y1 <= 650 && sq.y2 <= 650 && sq.y3 <= 650)) {
        if(sq.x0 > 220 &&
           sq.x1 > 220 &&
           sq.x2 > 220 &&
           sq.x3 > 220) {
            if(b[sq.x0-20][sq.y0] == 0 &&
               b[sq.x1-20][sq.y1] == 0 &&
               b[sq.x2-20][sq.y2] == 0 &&
               b[sq.x3-20][sq.y3] == 0) {
                sq.x0 -= 20;
                sq.x1 -= 20;
                sq.x2 -= 20;
                sq.x3 -= 20;
            }
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
        RECT rrect3 = {sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        
        DeleteObject(brush);
    }
    if(choice == "lne" && (lne.y0 <= 650 && lne.y1 <= 650 && lne.y2 <= 650 && lne.y3 <= 650)) {
        if(lne.x0 > 220 &&
           lne.x1 > 220 &&
           lne.x2 > 220 &&
           lne.x3 > 220) {
            if(b[lne.x0-20][lne.y0] == 0 &&
               b[lne.x1-20][lne.y1] == 0 &&
               b[lne.x2-20][lne.y2] == 0 &&
               b[lne.x3-20][lne.y3] == 0) {
                lne.x0 -= 20;
                lne.x1 -= 20;
                lne.x2 -= 20;
                lne.x3 -= 20;
            }
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20};
        FillRect(hdc2, &rrect6, brush);

        DeleteObject(brush);
    }
    else if(choice == "ht" && (ht.y0 <= 650 && ht.y1 <= 650 && ht.y2 <= 650 && ht.y3 <= 650)) {
        if(ht.x0 > 220 &&
           ht.x1 > 220 &&
           ht.x2 > 220 &&
           ht.x3 > 220) {
            if(b[ht.x0-20][ht.y0] == 0 &&
               b[ht.x1-20][ht.y1] == 0 &&
               b[ht.x2-20][ht.y2] == 0 &&
               b[ht.x3-20][ht.y3] == 0) {
                ht.x0 -= 20;
                ht.x1 -= 20;
                ht.x2 -= 20;
                ht.x3 -= 20;
            }
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20};
        FillRect(hdc2, &rrect6, brush);

        DeleteObject(brush);

        BOOLEAN flag = FALSE;
        if(b[ht.x0][ht.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[ht.x1][ht.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[ht.x2][ht.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[ht.x3][ht.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            b[ht.x0][ht.y0] = 1;
            b[ht.x1][ht.y1] = 1;
            b[ht.x2][ht.y2] = 1;
            b[ht.x3][ht.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }
        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
    }
    else if(choice == "larm" && (larm.y0 <= 650 && larm.y1 <= 650 && larm.y2 <= 650 && larm.y3 <= 650)) {
        if(larm.x0 > 220 &&
           larm.x1 > 220 &&
           larm.x2 > 220 &&
           larm.x3 > 220) {
            if(b[larm.x0-20][larm.y0] == 0 &&
               b[larm.x1-20][larm.y1] == 0 &&
               b[larm.x2-20][larm.y2] == 0 &&
               b[larm.x3-20][larm.y3] == 0) {
                larm.x0 -= 20;
                larm.x1 -= 20;
                larm.x2 -= 20;
                larm.x3 -= 20;
            }
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20};
        FillRect(hdc2, &rrect6, brush);

        DeleteObject(brush);

        if(larm.y0 > 650 || larm.y1 > 650 || larm.y2 > 650 || larm.y3 > 650) {
            b[larm.x0][larm.y0] = 1;
            b[larm.x1][larm.y1] = 1;
            b[larm.x2][larm.y2] = 1;
            b[larm.x3][larm.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }

        BOOLEAN flag = FALSE;
        if(b[larm.x0][larm.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[larm.x1][larm.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[larm.x2][larm.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[larm.x3][larm.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            b[larm.x0][larm.y0] = 1;
            b[larm.x1][larm.y1] = 1;
            b[larm.x2][larm.y2] = 1;
            b[larm.x3][larm.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }
        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                    Rectangle(hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(hdc2, hOldPen));
                    SelectObject(hdc2, hOldBsh);
                }
            }
        }
    }
    else if(choice == "rarm" && (rarm.y0 <= 650 && rarm.y1 <= 650 && rarm.y2 <= 650 && rarm.y3 <= 650)) {
        if(rarm.x0 > 220 &&
           rarm.x1 > 220 &&
           rarm.x2 > 220 &&
           rarm.x3 > 220) {
            if(b[rarm.x0-20][rarm.y0] == 0 &&
               b[rarm.x1-20][rarm.y1] == 0 &&
               b[rarm.x2-20][rarm.y2] == 0 &&
               b[rarm.x3-20][rarm.y3] == 0) {
                rarm.x0 -= 20;
                rarm.x1 -= 20;
                rarm.x2 -= 20;
                rarm.x3 -= 20;
            }
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20};
        FillRect(hdc2, &rrect6, brush);

        DeleteObject(brush);
        
        if(rarm.y0 > 650 || rarm.y1 > 650 || rarm.y2 > 650 || rarm.y3 > 650) {
            b[rarm.x0][rarm.y0] = 1;
            b[rarm.x1][rarm.y1] = 1;
            b[rarm.x2][rarm.y2] = 1;
            b[rarm.x3][rarm.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }

        BOOLEAN flag = FALSE;
        if(b[rarm.x0][rarm.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[rarm.x1][rarm.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[rarm.x2][rarm.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[rarm.x3][rarm.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            b[rarm.x0][rarm.y0] = 1;
            b[rarm.x1][rarm.y1] = 1;
            b[rarm.x2][rarm.y2] = 1;
            b[rarm.x3][rarm.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }
        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                    Rectangle(hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(hdc2, hOldPen));
                    SelectObject(hdc2, hOldBsh);
                }
            }
        }
    }
    else if(choice == "lsh" && (lsh.y0 <= 650 && lsh.y1 <= 650 && lsh.y2 <= 650 && lsh.y3 <= 650)) {
        if(lsh.x0 > 220 &&
           lsh.x1 > 220 &&
           lsh.x2 > 220 &&
           lsh.x3 > 220) {
            if(b[lsh.x0-20][lsh.y0] == 0 &&
               b[lsh.x1-20][lsh.y1] == 0 &&
               b[lsh.x2-20][lsh.y2] == 0 &&
               b[lsh.x3-20][lsh.y3] == 0) {
                lsh.x0 -= 20;
                lsh.x1 -= 20;
                lsh.x2 -= 20;
                lsh.x3 -= 20;
            }
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20};
        FillRect(hdc2, &rrect6, brush);

        DeleteObject(brush);

        if(lsh.y0 > 650 || lsh.y1 > 650 || lsh.y2 > 650 || lsh.y3 > 650) {
            b[lsh.x0][lsh.y0] = 1;
            b[lsh.x1][lsh.y1] = 1;
            b[lsh.x2][lsh.y2] = 1;
            b[lsh.x3][lsh.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }

        BOOLEAN flag = FALSE;
        if(b[lsh.x0][lsh.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[lsh.x1][lsh.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[lsh.x2][lsh.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[lsh.x3][lsh.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            b[lsh.x0][lsh.y0] = 1;
            b[lsh.x1][lsh.y1] = 1;
            b[lsh.x2][lsh.y2] = 1;
            b[lsh.x3][lsh.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }
        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                    Rectangle(hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(hdc2, hOldPen));
                    SelectObject(hdc2, hOldBsh);
                }
            }
        }
    }
    else if(choice == "rsh" && (rsh.y0 <= 650 && rsh.y1 <= 650 && rsh.y2 <= 650 && rsh.y3 <= 650)) {
        if(rsh.x0 > 220 &&
           rsh.x1 > 220 &&
           rsh.x2 > 220 &&
           rsh.x3 > 220) {
            if(b[rsh.x0-20][rsh.y0] == 0 &&
               b[rsh.x1-20][rsh.y1] == 0 &&
               b[rsh.x2-20][rsh.y2] == 0 &&
               b[rsh.x3-20][rsh.y3] == 0) {
                rsh.x0 -= 20;
                rsh.x1 -= 20;
                rsh.x2 -= 20;
                rsh.x3 -= 20;
            }
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(rsh.y0 > 650 || rsh.y1 > 650 || rsh.y2 > 650 || rsh.y3 > 650) {
            b[rsh.x0][rsh.y0] = 1;
            b[rsh.x1][rsh.y1] = 1;
            b[rsh.x2][rsh.y2] = 1;
            b[rsh.x3][rsh.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }

        BOOLEAN flag = FALSE;
        if(b[rsh.x0][rsh.y0+20] == 1) {
            flag = TRUE;
        }
        else if(b[rsh.x1][rsh.y1+20] == 1) {
            flag = TRUE;
        }
        else if(b[rsh.x2][rsh.y2+20] == 1) {
            flag = TRUE;
        }
        else if(b[rsh.x3][rsh.y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            b[rsh.x0][rsh.y0] = 1;
            b[rsh.x1][rsh.y1] = 1;
            b[rsh.x2][rsh.y2] = 1;
            b[rsh.x3][rsh.y3] = 1;
            blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
            prep();
        }
        if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                    Rectangle(hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(hdc2, hOldPen));
                    SelectObject(hdc2, hOldBsh);
                }
            }
        }
    }
    
    DeleteObject(brush);
}

void erasePreview() {
    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
    RECT rrect5 = {0, 20, 129, 220};
    FillRect(hdc2, &rrect5, brush);
    DeleteObject(brush);
}

void showNextPiece() {
    if(choicepre == "sq") {
        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
        RECT rrect5 = {-90+100, 100, -90+100 + 20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+120, 100, -90+120 + 20, 100 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+100, 120, -90+100 + 20, 120 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+120, 120, -90+120 + 20, 120 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    } else if(choicepre == "lne") {
        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
        RECT rrect5 = {-90+100, 100, -90+100 + 20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+100, 120, -90+100 + 20, 120 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+100, 140, -90+100 + 20, 140 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+100, 160, -90+100 + 20, 160 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    } else if(choicepre == "ht") {
        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
        RECT rrect5 = {-90+120, 100, -90+120 + 20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+100, 120, -90+100 + 20, 120 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+120, 120, -90+120 + 20, 120 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+140, 120, -90+140 + 20, 120 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    } else if(choicepre == "larm") {
        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
        RECT rrect5 = {-90+120, 100, -90+120 + 20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+120, 120, -90+120 + 20, 120 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+120, 140, -90+120 + 20, 140 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+100, 140, -90+100 + 20, 140 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    } else if(choicepre == "rarm") {
        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
        RECT rrect5 = {-90+120-20, 100, -90+120 + 20-20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+120-20, 120, -90+120 + 20-20, 120 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+120-20, 140, -90+120 + 20-20, 140 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+140-20, 140, -90+140 + 20-20, 140 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    } else if(choicepre == "lsh") {
        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
        RECT rrect5 = {-90+120, 100, -90+120 + 20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+120, 120, -90+120 + 20, 120 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+100, 120, -90+100 + 20, 120 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+100, 140, -90+100 + 20, 140 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    } else if(choicepre == "rsh") {
        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
        RECT rrect5 = {-90+100, 100, -90+100 + 20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+100, 120, -90+100 + 20, 120 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+120, 120, -90+120 + 20, 120 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+120, 140, -90+120 + 20, 140 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    }
}

void clearLine() {

    int count = 0;

    int clearBlocks[700];

    int cc = 0;

    BOOLEAN keepon = TRUE;

    do {
        for(int i=0; i<700; i++) {
            clearBlocks[i] = 0;
        }

        for(int j=0; j<=700 && keepon; j++) {

            int clearThisLine = 0;

            for(int i=0; i<740; i++) {
                if(1 == b[i][j]) {
                    clearThisLine++;
                }
            }

            if(clearThisLine == 10) {
                char aa[10];
                sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                clearBlocks[count] = j;
                count++;
                lines++;
                points+=10;
                keepon = FALSE;
            }
        }

        if(count > 0) {

            int cnt;

            cnt = 0;

            for(;cnt < count; cnt++) {
                for(int j=0; j<700; j++) {
                    for(int i=0; i<740; i++) {
                        if(j == clearBlocks[cnt]) {
                            b[i][j] = 0;
                        }
                    }
                }
            }

            cnt = 0;

            for(;cnt < count; cnt++) {
                for(int j=650; j>=0; j-=20) {
                    for(int i=0; i<740; i++) {
                        if(b[i][j] == 1 && j < clearBlocks[cnt]) {
                            b[i][j] = 0;
                            b[i][j+20] = 1;
                        }
                    }
                }
            }
        }

        cc++;

    } while(cc < 35);
}

DWORD WINAPI paintMe(void *data) {
    int a=1;
    do {
        char *str = (char *) malloc(strlen("bg1.bmp"));
        strcpy(str,"bg");
        char buffer[26];
        strcat(str,itoa(a,buffer,10));
        strcat(str,".bmp");
        hdcMems = CreateCompatibleDC(hdc2);
        hb1 = (HBITMAP)LoadImage(hInst, str, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        Sleep(120);
        oldBitmap = SelectObject(hdcMems, hb1);
        GetObject(hb1, sizeof(bitmap), &bitmap);
        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);
        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
        DeleteDC(hdcMems); DeleteObject(hb1);
        if(choice == "sq" && (sq.y0 <= 630 && sq.y1 <= 630 && sq.y2 <= 630 && sq.y3 <= 630)) {

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(sq.y0 > 650 || sq.y1 > 650 || sq.y2 > 650 || sq.y3 > 650) {
                b[sq.x0][sq.y0] = 1;
                b[sq.x1][sq.y1] = 1;
                b[sq.x2][sq.y2] = 1;
                b[sq.x3][sq.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[sq.x0][sq.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[sq.x1][sq.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[sq.x2][sq.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[sq.x3][sq.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[sq.x0][sq.y0] = 1;
                b[sq.x1][sq.y1] = 1;
                b[sq.x2][sq.y2] = 1;
                b[sq.x3][sq.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        }
        else if(choice == "lne" && (lne.y0 <= 580 || lne.y1 <= 580 || lne.y2 <= 580 || lne.y3 <= 580)) {
    //        lne.y0 += 20;
    //        lne.y1 += 20;
    //        lne.y2 += 20;
    //        lne.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(lne.y0 > 650 || lne.y1 > 650 || lne.y2 > 650 || lne.y3 > 650) {
                b[lne.x0][lne.y0] = 1;
                b[lne.x1][lne.y1] = 1;
                b[lne.x2][lne.y2] = 1;
                b[lne.x3][lne.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[lne.x0][lne.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[lne.x1][lne.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[lne.x2][lne.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[lne.x3][lne.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[lne.x0][lne.y0] = 1;
                b[lne.x1][lne.y1] = 1;
                b[lne.x2][lne.y2] = 1;
                b[lne.x3][lne.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        }
        else if(choice == "ht" && (ht.y0 <= 650 && ht.y1 <= 650 && ht.y2 <= 650 && ht.y3 <= 650)) {
    //        ht.y0 += 20;
    //        ht.y1 += 20;
    //        ht.y2 += 20;
    //        ht.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ht.y0 > 650 || ht.y1 > 650 || ht.y2 > 650 || ht.y3 > 650) {
                b[ht.x0][ht.y0] = 1;
                b[ht.x1][ht.y1] = 1;
                b[ht.x2][ht.y2] = 1;
                b[ht.x3][ht.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[ht.x0][ht.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[ht.x1][ht.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[ht.x2][ht.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[ht.x3][ht.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[ht.x0][ht.y0] = 1;
                b[ht.x1][ht.y1] = 1;
                b[ht.x2][ht.y2] = 1;
                b[ht.x3][ht.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        }
        else if(choice == "larm" && (larm.y0 <= 650 && larm.y1 <= 650 && larm.y2 <= 650 && larm.y3 <= 650)) {
    //        larm.y0 += 20;
    //        larm.y1 += 20;
    //        larm.y2 += 20;
    //        larm.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(larm.y0 > 650 || larm.y1 > 650 || larm.y2 > 650 || larm.y3 > 650) {
                b[larm.x0][larm.y0] = 1;
                b[larm.x1][larm.y1] = 1;
                b[larm.x2][larm.y2] = 1;
                b[larm.x3][larm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[larm.x0][larm.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[larm.x1][larm.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[larm.x2][larm.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[larm.x3][larm.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[larm.x0][larm.y0] = 1;
                b[larm.x1][larm.y1] = 1;
                b[larm.x2][larm.y2] = 1;
                b[larm.x3][larm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "rarm" && (rarm.y0 <= 650 && rarm.y1 <= 650 && rarm.y2 <= 650 && rarm.y3 <= 650)) {
    //        rarm.y0 += 20;
    //        rarm.y1 += 20;
    //        rarm.y2 += 20;
    //        rarm.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(rarm.y0 > 650 || rarm.y1 > 650 || rarm.y2 > 650 || rarm.y3 > 650) {
                b[rarm.x0][rarm.y0] = 1;
                b[rarm.x1][rarm.y1] = 1;
                b[rarm.x2][rarm.y2] = 1;
                b[rarm.x3][rarm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[rarm.x0][rarm.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[rarm.x1][rarm.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[rarm.x2][rarm.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[rarm.x3][rarm.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[rarm.x0][rarm.y0] = 1;
                b[rarm.x1][rarm.y1] = 1;
                b[rarm.x2][rarm.y2] = 1;
                b[rarm.x3][rarm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "lsh" && (lsh.y0 <= 650 && lsh.y1 <= 650 && lsh.y2 <= 650 && lsh.y3 <= 650)) {
    //        lsh.y0 += 20;
    //        lsh.y1 += 20;
    //        lsh.y2 += 20;
    //        lsh.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(lsh.y0 > 650 || lsh.y1 > 650 || lsh.y2 > 650 || lsh.y3 > 650) {
                b[lsh.x0][lsh.y0] = 1;
                b[lsh.x1][lsh.y1] = 1;
                b[lsh.x2][lsh.y2] = 1;
                b[lsh.x3][lsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[lsh.x0][lsh.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[lsh.x1][lsh.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[lsh.x2][lsh.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[lsh.x3][lsh.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[lsh.x0][lsh.y0] = 1;
                b[lsh.x1][lsh.y1] = 1;
                b[lsh.x2][lsh.y2] = 1;
                b[lsh.x3][lsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "rsh" && (rsh.y0 <= 650 && rsh.y1 <= 650 && rsh.y2 <= 650 && rsh.y3 <= 650)) {
    //        rsh.y0 += 20;
    //        rsh.y1 += 20;
    //        rsh.y2 += 20;
    //        rsh.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(rsh.y0 > 650 || rsh.y1 > 650 || rsh.y2 > 650 || rsh.y3 > 650) {
                b[rsh.x0][rsh.y0] = 1;
                b[rsh.x1][rsh.y1] = 1;
                b[rsh.x2][rsh.y2] = 1;
                b[rsh.x3][rsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[rsh.x0][rsh.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[rsh.x1][rsh.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[rsh.x2][rsh.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[rsh.x3][rsh.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[rsh.x0][rsh.y0] = 1;
                b[rsh.x1][rsh.y1] = 1;
                b[rsh.x2][rsh.y2] = 1;
                b[rsh.x3][rsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        a++;
        if(a == 13)
          a = 1;

        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                    Rectangle(hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(hdc2, hOldPen));
                    SelectObject(hdc2, hOldBsh);
                }
            }
        }

    } while (TRUE);

    return 0;
}

DWORD WINAPI downs(void *data) {
  
    BOOLEAN downIt = TRUE;

    do {
        Sleep(sleeptime);

        hdcMems = CreateCompatibleDC(hdc2);

        HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));

        RECT rrect3 = {219, 20, 420, 690};
        //FillRect(hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(choice == "sq" && (sq.y0 <= 630 && sq.y1 <= 630 && sq.y2 <= 630 && sq.y3 <= 630)) {

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(sq.y0 > 650 || sq.y1 > 650 || sq.y2 > 650 || sq.y3 > 650) {
                b[sq.x0][sq.y0] = 1;
                b[sq.x1][sq.y1] = 1;
                b[sq.x2][sq.y2] = 1;
                b[sq.x3][sq.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[sq.x0][sq.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[sq.x1][sq.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[sq.x2][sq.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[sq.x3][sq.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[sq.x0][sq.y0] = 1;
                b[sq.x1][sq.y1] = 1;
                b[sq.x2][sq.y2] = 1;
                b[sq.x3][sq.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        }
        else if(choice == "lne" && (lne.y0 <= 580 || lne.y1 <= 580 || lne.y2 <= 580 || lne.y3 <= 580)) {
    //        lne.y0 += 20;
    //        lne.y1 += 20;
    //        lne.y2 += 20;
    //        lne.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(lne.y0 > 650 || lne.y1 > 650 || lne.y2 > 650 || lne.y3 > 650) {
                b[lne.x0][lne.y0] = 1;
                b[lne.x1][lne.y1] = 1;
                b[lne.x2][lne.y2] = 1;
                b[lne.x3][lne.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[lne.x0][lne.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[lne.x1][lne.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[lne.x2][lne.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[lne.x3][lne.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[lne.x0][lne.y0] = 1;
                b[lne.x1][lne.y1] = 1;
                b[lne.x2][lne.y2] = 1;
                b[lne.x3][lne.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        }
        else if(choice == "ht" && (ht.y0 <= 650 && ht.y1 <= 650 && ht.y2 <= 650 && ht.y3 <= 650)) {
    //        ht.y0 += 20;
    //        ht.y1 += 20;
    //        ht.y2 += 20;
    //        ht.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ht.y0 > 650 || ht.y1 > 650 || ht.y2 > 650 || ht.y3 > 650) {
                b[ht.x0][ht.y0] = 1;
                b[ht.x1][ht.y1] = 1;
                b[ht.x2][ht.y2] = 1;
                b[ht.x3][ht.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[ht.x0][ht.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[ht.x1][ht.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[ht.x2][ht.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[ht.x3][ht.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[ht.x0][ht.y0] = 1;
                b[ht.x1][ht.y1] = 1;
                b[ht.x2][ht.y2] = 1;
                b[ht.x3][ht.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
        }
        else if(choice == "larm" && (larm.y0 <= 650 && larm.y1 <= 650 && larm.y2 <= 650 && larm.y3 <= 650)) {
    //        larm.y0 += 20;
    //        larm.y1 += 20;
    //        larm.y2 += 20;
    //        larm.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(larm.y0 > 650 || larm.y1 > 650 || larm.y2 > 650 || larm.y3 > 650) {
                b[larm.x0][larm.y0] = 1;
                b[larm.x1][larm.y1] = 1;
                b[larm.x2][larm.y2] = 1;
                b[larm.x3][larm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[larm.x0][larm.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[larm.x1][larm.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[larm.x2][larm.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[larm.x3][larm.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[larm.x0][larm.y0] = 1;
                b[larm.x1][larm.y1] = 1;
                b[larm.x2][larm.y2] = 1;
                b[larm.x3][larm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "rarm" && (rarm.y0 <= 650 && rarm.y1 <= 650 && rarm.y2 <= 650 && rarm.y3 <= 650)) {
    //        rarm.y0 += 20;
    //        rarm.y1 += 20;
    //        rarm.y2 += 20;
    //        rarm.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(rarm.y0 > 650 || rarm.y1 > 650 || rarm.y2 > 650 || rarm.y3 > 650) {
                b[rarm.x0][rarm.y0] = 1;
                b[rarm.x1][rarm.y1] = 1;
                b[rarm.x2][rarm.y2] = 1;
                b[rarm.x3][rarm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[rarm.x0][rarm.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[rarm.x1][rarm.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[rarm.x2][rarm.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[rarm.x3][rarm.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[rarm.x0][rarm.y0] = 1;
                b[rarm.x1][rarm.y1] = 1;
                b[rarm.x2][rarm.y2] = 1;
                b[rarm.x3][rarm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "lsh" && (lsh.y0 <= 650 && lsh.y1 <= 650 && lsh.y2 <= 650 && lsh.y3 <= 650)) {
    //        lsh.y0 += 20;
    //        lsh.y1 += 20;
    //        lsh.y2 += 20;
    //        lsh.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(lsh.y0 > 650 || lsh.y1 > 650 || lsh.y2 > 650 || lsh.y3 > 650) {
                b[lsh.x0][lsh.y0] = 1;
                b[lsh.x1][lsh.y1] = 1;
                b[lsh.x2][lsh.y2] = 1;
                b[lsh.x3][lsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[lsh.x0][lsh.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[lsh.x1][lsh.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[lsh.x2][lsh.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[lsh.x3][lsh.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[lsh.x0][lsh.y0] = 1;
                b[lsh.x1][lsh.y1] = 1;
                b[lsh.x2][lsh.y2] = 1;
                b[lsh.x3][lsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "rsh" && (rsh.y0 <= 650 && rsh.y1 <= 650 && rsh.y2 <= 650 && rsh.y3 <= 650)) {
    //        rsh.y0 += 20;
    //        rsh.y1 += 20;
    //        rsh.y2 += 20;
    //        rsh.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(rsh.y0 > 650 || rsh.y1 > 650 || rsh.y2 > 650 || rsh.y3 > 650) {
                b[rsh.x0][rsh.y0] = 1;
                b[rsh.x1][rsh.y1] = 1;
                b[rsh.x2][rsh.y2] = 1;
                b[rsh.x3][rsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[rsh.x0][rsh.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[rsh.x1][rsh.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[rsh.x2][rsh.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[rsh.x3][rsh.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[rsh.x0][rsh.y0] = 1;
                b[rsh.x1][rsh.y1] = 1;
                b[rsh.x2][rsh.y2] = 1;
                b[rsh.x3][rsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }

        HBRUSH brus = CreateSolidBrush(RGB(255, 255, 255));

        RECT ect3 = {219, 20, 420, 690};
        //FillRect(hdc2, &ect3, brus);
        DeleteObject(brus);

        if(fist) {
            thread = CreateThread(NULL, 0, downs, NULL, 0, NULL);
            srand(time(NULL));
            prep();
        }

        for(int i=0; i<700; i++) {
            for(int j=0; j<720; j++) {
                if(b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(hdc2, &rrect6, brush);
                    DeleteObject(brush);
                }
            }
        }

        erasePreview();
        printMiscLabels(level);
        showNextPiece();
        clearLine();

        hdcMems = CreateCompatibleDC(hdc2);

        hBitmap = (HBITMAP)LoadImage(hInst, "bgf.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255,253,255)));

        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        oldBitmap = SelectObject(hdcMems, hBitmap);

        GetObject(hBitmap, sizeof(bitmap), &bitmap);
        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
        DeleteDC(hdcMems); DeleteObject(hBitmap);

        if(choice == "sq") {

            sq.y0 += 20;
            sq.y1 += 20;
            sq.y2 += 20;
            sq.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(sq.y0 > 650 || sq.y1 > 650 || sq.y2 > 650 || sq.y3 > 650) {
                b[sq.x0][sq.y0] = 1;
                b[sq.x1][sq.y1] = 1;
                b[sq.x2][sq.y2] = 1;
                b[sq.x3][sq.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[sq.x0][sq.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[sq.x1][sq.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[sq.x2][sq.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[sq.x3][sq.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[sq.x0][sq.y0] = 1;
                b[sq.x1][sq.y1] = 1;
                b[sq.x2][sq.y2] = 1;
                b[sq.x3][sq.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "lne") {

            lne.y0 += 20;
            lne.y1 += 20;
            lne.y2 += 20;
            lne.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(lne.y0 > 650 || lne.y1 > 650 || lne.y2 > 650 || lne.y3 > 650) {
                b[lne.x0][lne.y0] = 1;
                b[lne.x1][lne.y1] = 1;
                b[lne.x2][lne.y2] = 1;
                b[lne.x3][lne.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[lne.x0][lne.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[lne.x1][lne.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[lne.x2][lne.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[lne.x3][lne.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[lne.x0][lne.y0] = 1;
                b[lne.x1][lne.y1] = 1;
                b[lne.x2][lne.y2] = 1;
                b[lne.x3][lne.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "ht") {

            ht.y0 += 20;
            ht.y1 += 20;
            ht.y2 += 20;
            ht.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(ht.y0 > 650 || ht.y1 > 650 || ht.y2 > 650 || ht.y3 > 650) {
                b[ht.x0][ht.y0] = 1;
                b[ht.x1][ht.y1] = 1;
                b[ht.x2][ht.y2] = 1;
                b[ht.x3][ht.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[ht.x0][ht.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[ht.x1][ht.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[ht.x2][ht.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[ht.x3][ht.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[ht.x0][ht.y0] = 1;
                b[ht.x1][ht.y1] = 1;
                b[ht.x2][ht.y2] = 1;
                b[ht.x3][ht.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "larm") {

            larm.y0 += 20;
            larm.y1 += 20;
            larm.y2 += 20;
            larm.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(larm.y0 > 650 || larm.y1 > 650 || larm.y2 > 650 || larm.y3 > 650) {
                b[larm.x0][larm.y0] = 1;
                b[larm.x1][larm.y1] = 1;
                b[larm.x2][larm.y2] = 1;
                b[larm.x3][larm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[larm.x0][larm.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[larm.x1][larm.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[larm.x2][larm.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[larm.x3][larm.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[larm.x0][larm.y0] = 1;
                b[larm.x1][larm.y1] = 1;
                b[larm.x2][larm.y2] = 1;
                b[larm.x3][larm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "rarm") {

            rarm.y0 += 20;
            rarm.y1 += 20;
            rarm.y2 += 20;
            rarm.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(rarm.y0 > 650 || rarm.y1 > 650 || rarm.y2 > 650 || rarm.y3 > 650) {
                b[rarm.x0][rarm.y0] = 1;
                b[rarm.x1][rarm.y1] = 1;
                b[rarm.x2][rarm.y2] = 1;
                b[rarm.x3][rarm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[rarm.x0][rarm.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[rarm.x1][rarm.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[rarm.x2][rarm.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[rarm.x3][rarm.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[rarm.x0][rarm.y0] = 1;
                b[rarm.x1][rarm.y1] = 1;
                b[rarm.x2][rarm.y2] = 1;
                b[rarm.x3][rarm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "lsh") {

            lsh.y0 += 20;
            lsh.y1 += 20;
            lsh.y2 += 20;
            lsh.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(lsh.y0 > 650 || lsh.y1 > 650 || lsh.y2 > 650 || lsh.y3 > 650) {
                b[lsh.x0][lsh.y0] = 1;
                b[lsh.x1][lsh.y1] = 1;
                b[lsh.x2][lsh.y2] = 1;
                b[lsh.x3][lsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[lsh.x0][lsh.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[lsh.x1][lsh.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[lsh.x2][lsh.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[lsh.x3][lsh.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[lsh.x0][lsh.y0] = 1;
                b[lsh.x1][lsh.y1] = 1;
                b[lsh.x2][lsh.y2] = 1;
                b[lsh.x3][lsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "rsh") {

            rsh.y0 += 20;
            rsh.y1 += 20;
            rsh.y2 += 20;
            rsh.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

            RECT rrect3 = {rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20};
            FillRect(hdc2, &rrect3, brush);

            RECT rrect4 = {rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20};
            FillRect(hdc2, &rrect4, brush);

            RECT rrect5 = {rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20};
            FillRect(hdc2, &rrect5, brush);

            RECT rrect6 = {rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(rsh.y0 > 650 || rsh.y1 > 650 || rsh.y2 > 650 || rsh.y3 > 650) {
                b[rsh.x0][rsh.y0] = 1;
                b[rsh.x1][rsh.y1] = 1;
                b[rsh.x2][rsh.y2] = 1;
                b[rsh.x3][rsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }

            BOOLEAN flag = FALSE;
            if(b[rsh.x0][rsh.y0+20] == 1) {
                flag = TRUE;
            }
            else if(b[rsh.x1][rsh.y1+20] == 1) {
                flag = TRUE;
            }
            else if(b[rsh.x2][rsh.y2+20] == 1) {
                flag = TRUE;
            }
            else if(b[rsh.x3][rsh.y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                b[rsh.x0][rsh.y0] = 1;
                b[rsh.x1][rsh.y1] = 1;
                b[rsh.x2][rsh.y2] = 1;
                b[rsh.x3][rsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"Blocks: %d, Points: %d, Lines: %d",blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines >= linenext) {level++;linenext+=10;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
    }
    while(downIt);

    return 0;
}

void prep() {
    choice = choicepre;
    if(fist) {
        int r = rand() % 7;
        if(r == 1)
          choicepre = "sq";
        else if(r == 2)
          choicepre = "lne";
        else if(r == 3)
          choicepre = "ht";
        else if(r == 4)
          choicepre = "larm";
        else if(r == 5)
          choicepre = "rarm";
        else if(r == 6)
          choicepre = "lsh";
        else
          choicepre = "rsh";
        choice = choicepre;
    }
    fist = FALSE;
    int r = rand() % 7;
    if(r == 1)
      choicepre = "sq";
    else if(r == 2)
      choicepre = "lne";
    else if(r == 3)
      choicepre = "ht";
    else if(r == 4)
      choicepre = "larm";
    else if(r == 5)
      choicepre = "rarm";
    else if(r == 6)
      choicepre = "lsh";
    else
      choicepre = "rsh";
    lsh.x0 = 300;
    lsh.y0 = 50;
    lsh.x1 = 280;
    lsh.y1 = 70;
    lsh.x2 = 300;
    lsh.y2 = 70;
    lsh.x3 = 280;
    lsh.y3 = 90;
    lsh.dir = 0;
    rsh.x0 = 300;
    rsh.y0 = 50;
    rsh.x1 = 300;
    rsh.y1 = 70;
    rsh.x2 = 320;
    rsh.y2 = 70;
    rsh.x3 = 320;
    rsh.y3 = 90;
    rsh.dir = 0;
    larm.x0 = 300;
    larm.y0 = 50;
    larm.x1 = 300;
    larm.y1 = 70;
    larm.x2 = 300;
    larm.y2 = 90;
    larm.x3 = 280;
    larm.y3 = 90;
    larm.dir = 0;
    rarm.x0 = 300;
    rarm.y0 = 50;
    rarm.x1 = 300;
    rarm.y1 = 70;
    rarm.x2 = 300;
    rarm.y2 = 90;
    rarm.x3 = 320;
    rarm.y3 = 90;
    rarm.dir = 0;
    ht.x0 = 300;
    ht.y0 = 50;
    ht.x1 = 280;
    ht.y1 = 70;
    ht.x2 = 300;
    ht.y2 = 70;
    ht.x3 = 320;
    ht.y3 = 70;
    ht.dir = 0;
    sq.x0 = 300;
    sq.y0 = 50;
    sq.x1 = 320;
    sq.y1 = 50;
    sq.x2 = 300;
    sq.y2 = 70;
    sq.x3 = 320;
    sq.y3 = 70;
    lne.x0 = 300;
    lne.y0 = 50;
    lne.x1 = 300;
    lne.y1 = 70;
    lne.x2 = 300;
    lne.y2 = 90;
    lne.x3 = 300;
    lne.y3 = 110;
    lne.dir = 0;

    if(b[rarm.x0][rarm.y0+20] == 1
        ||        
        b[rarm.x1][rarm.y1+20] == 1
        ||
        b[rarm.x2][rarm.y2+20] == 1
        ||
        b[rarm.x3][rarm.y3+20] == 1
        ||
        b[larm.x0][larm.y0+20] == 1
        ||        
        b[larm.x1][larm.y1+20] == 1
        ||
        b[larm.x2][larm.y2+20] == 1
        ||
        b[larm.x3][larm.y3+20] == 1
        ||
        b[rsh.x0][rsh.y0+20] == 1
        ||        
        b[rsh.x1][rsh.y1+20] == 1
        ||
        b[rsh.x2][rsh.y2+20] == 1
        ||
        b[rsh.x3][rsh.y3+20] == 1
        ||
        b[lsh.x0][lsh.y0+20] == 1
        ||        
        b[lsh.x1][lsh.y1+20] == 1
        ||
        b[lsh.x2][lsh.y2+20] == 1
        ||
        b[lsh.x3][lsh.y3+20] == 1               
        ||
        b[sq.x0][sq.y0+20] == 1
        ||        
        b[sq.x1][sq.y1+20] == 1
        ||
        b[sq.x2][sq.y2+20] == 1
        ||
        b[sq.x3][sq.y3+20] == 1
        ||
        b[lne.x0][lne.y0+20] == 1
        ||        
        b[lne.x1][lne.y1+20] == 1
        ||
        b[lne.x2][lne.y2+20] == 1
        ||
        b[lne.x3][lne.y3+20] == 1
        ||
        b[ht.x0][ht.y0+20] == 1
        ||        
        b[ht.x1][ht.y1+20] == 1
        ||
        b[ht.x2][ht.y2+20] == 1
        ||
        b[ht.x3][ht.y3+20] == 1) {

        GetCurrentDir( buff, FILENAME_MAX );
        buff[strlen(buff)] = '\0';
        strcpy(filename,buff);
        strcat(filename,"\\WinTris.exe");
        filename[strlen(filename)] = '\0';
        STARTUPINFO startUpInfo = { 0 };
        PROCESS_INFORMATION procInfo = { 0 };
        startUpInfo.cb = sizeof( startUpInfo );
        CreateProcess( filename, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startUpInfo, &procInfo );
        exit(0);
    }

    if(b[rarm.x0][rarm.y0-20] == 1
        ||        
        b[rarm.x1][rarm.y1-20] == 1
        ||
        b[rarm.x2][rarm.y2-20] == 1
        ||
        b[rarm.x3][rarm.y3-20] == 1
        ||
        b[larm.x0][larm.y0-20] == 1
        ||        
        b[larm.x1][larm.y1-20] == 1
        ||
        b[larm.x2][larm.y2-20] == 1
        ||
        b[larm.x3][larm.y3-20] == 1
        ||
        b[rsh.x0][rsh.y0-20] == 1
        ||        
        b[rsh.x1][rsh.y1-20] == 1
        ||
        b[rsh.x2][rsh.y2-20] == 1
        ||
        b[rsh.x3][rsh.y3-20] == 1
        ||
        b[lsh.x0][lsh.y0-20] == 1
        ||        
        b[lsh.x1][lsh.y1-20] == 1
        ||
        b[lsh.x2][lsh.y2-20] == 1
        ||
        b[lsh.x3][lsh.y3-20] == 1               
        ||
        b[sq.x0][sq.y0-20] == 1
        ||        
        b[sq.x1][sq.y1-20] == 1
        ||
        b[sq.x2][sq.y2-20] == 1
        ||
        b[sq.x3][sq.y3-20] == 1
        ||
        b[lne.x0][lne.y0-20] == 1
        ||        
        b[lne.x1][lne.y1-20] == 1
        ||
        b[lne.x2][lne.y2-20] == 1
        ||
        b[lne.x3][lne.y3-20] == 1
        ||
        b[ht.x0][ht.y0-20] == 1
        ||        
        b[ht.x1][ht.y1-20] == 1
        ||
        b[ht.x2][ht.y2-20] == 1
        ||
        b[ht.x3][ht.y3-20] == 1) {

        GetCurrentDir( buff, FILENAME_MAX );
        buff[strlen(buff)] = '\0';
        strcpy(filename,buff);
        strcat(filename,"\\WinTris.exe");
        filename[strlen(filename)] = '\0';
        STARTUPINFO startUpInfo = { 0 };
        PROCESS_INFORMATION procInfo = { 0 };
        startUpInfo.cb = sizeof( startUpInfo );
        CreateProcess( filename, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startUpInfo, &procInfo );
        exit(0);
    }

    if(b[rarm.x0][rarm.y0] == 1
        ||        
        b[rarm.x1][rarm.y1] == 1
        ||
        b[rarm.x2][rarm.y2] == 1
        ||
        b[rarm.x3][rarm.y3] == 1
        ||
        b[larm.x0][larm.y0] == 1
        ||        
        b[larm.x1][larm.y1] == 1
        ||
        b[larm.x2][larm.y2] == 1
        ||
        b[larm.x3][larm.y3] == 1
        ||
        b[rsh.x0][rsh.y0] == 1
        ||        
        b[rsh.x1][rsh.y1] == 1
        ||
        b[rsh.x2][rsh.y2] == 1
        ||
        b[rsh.x3][rsh.y3] == 1
        ||
        b[lsh.x0][lsh.y0] == 1
        ||        
        b[lsh.x1][lsh.y1] == 1
        ||
        b[lsh.x2][lsh.y2] == 1
        ||
        b[lsh.x3][lsh.y3] == 1               
        ||
        b[sq.x0][sq.y0] == 1
        ||        
        b[sq.x1][sq.y1] == 1
        ||
        b[sq.x2][sq.y2] == 1
        ||
        b[sq.x3][sq.y3] == 1
        ||
        b[lne.x0][lne.y0] == 1
        ||        
        b[lne.x1][lne.y1] == 1
        ||
        b[lne.x2][lne.y2] == 1
        ||
        b[lne.x3][lne.y3] == 1
        ||
        b[ht.x0][ht.y0] == 1
        ||        
        b[ht.x1][ht.y1] == 1
        ||
        b[ht.x2][ht.y2] == 1
        ||
        b[ht.x3][ht.y3] == 1) {

        GetCurrentDir( buff, FILENAME_MAX );
        buff[strlen(buff)] = '\0';
        strcpy(filename,buff);
        strcat(filename,"\\WinTris.exe");
        filename[strlen(filename)] = '\0';
        STARTUPINFO startUpInfo = { 0 };
        PROCESS_INFORMATION procInfo = { 0 };
        startUpInfo.cb = sizeof( startUpInfo );
        CreateProcess( filename, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startUpInfo, &procInfo );
        exit(0);
    }
}

void rotate() {
    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));

    RECT rrect3 = {219, 20, 420, 690};
    //FillRect(hdc2, &rrect3, brush);
    DeleteObject(brush);

    if(choice == "sq") {
        
        sq.y0 += 0;
        sq.y1 += 0;
        sq.y2 += 0;
        sq.y3 += 0;

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);
    }
    else if(choice == "lne") {
        
        int lnex0, lney0, lnex1, lney1, lnex2, lney2, lnex3, lney3, lnedir;

        lnedir = lne.dir;
        lnex0 = lne.x0;
        lney0 = lne.y0;
        lnex1 = lne.x1;
        lney1 = lne.y1;
        lnex2 = lne.x2;
        lney2 = lne.y2;
        lnex3 = lne.x3;
        lney3 = lne.y3;

        if(lne.dir == 0) {
            lne.dir = 1;
            lne.x0 += 20* 3;
            lne.y0 += 20* 3;
            lne.x1 += 20* 2;
            lne.y1 += 20* 2;
            lne.x2 += 20* 1;
            lne.y2 += 20* 1;
            lne.x3 += 20* 0;
            lne.y3 += 20* 0;
        }
        else if(lne.dir == 1) {
            lne.dir = 2;
            lne.x0 -= 20* 3;
            lne.y0 += 20* 3;
            lne.x1 -= 20* 2;
            lne.y1 += 20* 2;
            lne.x2 -= 20* 1;
            lne.y2 += 20* 1;
            lne.x3 -= 20* 0;
            lne.y3 += 20* 0;
        }
        else if(lne.dir == 2) {
            lne.dir = 3;
            lne.x0 -= 20* 3;
            lne.y0 -= 20* 3;
            lne.x1 -= 20* 2;
            lne.y1 -= 20* 2;
            lne.x2 -= 20* 1;
            lne.y2 -= 20* 1;
            lne.x3 -= 20* 0;
            lne.y3 -= 20* 0;
        }
        else if(lne.dir == 3) {
            lne.dir = 0;
            lne.x0 += 20* 3;
            lne.y0 -= 20* 3;
            lne.x1 += 20* 2;
            lne.y1 -= 20* 2;
            lne.x2 += 20* 1;
            lne.y2 -= 20* 1;
            lne.x3 += 20* 0;
            lne.y3 -= 20* 0;
        }
        
        if(lne.x0 > 400 || lne.x1 > 400 || lne.x2 > 400 || lne.x3 > 400 ||
           lne.x0 < 220 || lne.x1 < 220 || lne.x2 < 220 || lne.x3 < 220) {
            lne.dir = lnedir;
            lne.x0 = lnex0;
            lne.y0 = lney0;
            lne.x1 = lnex1;
            lne.y1 = lney1;
            lne.x2 = lnex2;
            lne.y2 = lney2;
            lne.x3 = lnex3;
            lne.y3 = lney3;
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);
    }
    else if(choice == "ht") {

        int htx0, hty0, htx1, hty1, htx2, hty2, htx3, hty3, htdir;

        htdir = ht.dir;
        htx0 = ht.x0;
        hty0 = ht.y0;
        htx1 = ht.x1;
        hty1 = ht.y1;
        htx2 = ht.x2;
        hty2 = ht.y2;
        htx3 = ht.x3;
        hty3 = ht.y3;

        if(ht.dir == 0) {
            ht.dir = 1;
            ht.x0 += 20* 0;
            ht.y0 += 20* 0;
            ht.x1 += 20* 0;
            ht.y1 -= 20* 2;
            ht.x2 -= 20* 1;
            ht.y2 -= 20* 1;
            ht.x3 -= 20* 2;
            ht.y3 -= 20* 0;
        }
        else if(ht.dir == 1) {
            ht.dir = 2;
            ht.x0 -= 20* 0;
            ht.y0 += 20* 0;
            ht.x1 += 20* 2;
            ht.y1 += 20* 0;
            ht.x2 += 20* 1;
            ht.y2 -= 20* 1;
            ht.x3 -= 20* 0;
            ht.y3 -= 20* 2;
        }
        else if(ht.dir == 2) {
            ht.dir = 3;
            ht.x0 -= 20* 0;
            ht.y0 -= 20* 0;
            ht.x1 -= 20* 0;
            ht.y1 += 20* 2;
            ht.x2 += 20* 1;
            ht.y2 += 20* 1;
            ht.x3 += 20* 2;
            ht.y3 += 20* 0;
        }
        else if(ht.dir == 3) {
            ht.dir = 0;
            ht.x0 += 20* 0;
            ht.y0 -= 20* 0;
            ht.x1 -= 20* 2;
            ht.y1 -= 20* 0;
            ht.x2 -= 20* 1;
            ht.y2 += 20* 1;
            ht.x3 -= 20* 0;
            ht.y3 += 20* 2;
        }

        if(ht.x0 > 400 || ht.x1 > 400 || ht.x2 > 400 || ht.x3 > 400 ||
           ht.x0 < 220 || ht.x1 < 220 || ht.x2 < 220 || ht.x3 < 220) {
            ht.dir = htdir;
            ht.x0 = htx0;
            ht.y0 = hty0;
            ht.x1 = htx1;
            ht.y1 = hty1;
            ht.x2 = htx2;
            ht.y2 = hty2;
            ht.x3 = htx3;
            ht.y3 = hty3;
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);
    }
    else if(choice == "larm") {
        
        int larmx0, larmy0, larmx1, larmy1, larmx2, larmy2, larmx3, larmy3, larmdir;

        larmdir = larm.dir;
        larmx0 = larm.x0;
        larmy0 = larm.y0;
        larmx1 = larm.x1;
        larmy1 = larm.y1;
        larmx2 = larm.x2;
        larmy2 = larm.y2;
        larmx3 = larm.x3;
        larmy3 = larm.y3;

        if(larm.dir == 0) {
            larm.dir = 1;
            larm.x0 += 20* 2;
            larm.y0 += 20* 2;
            larm.x1 += 20* 1;
            larm.y1 += 20* 1;
            larm.x2 += 20* 0;
            larm.y2 += 20* 0;
            larm.x3 += 20* 1;
            larm.y3 -= 20* 1;
        }
        else if(larm.dir == 1) {
            larm.dir = 2;
            larm.x0 -= 20* 2;
            larm.y0 += 20* 2;
            larm.x1 -= 20* 1;
            larm.y1 += 20* 1;
            larm.x2 -= 20* 0;
            larm.y2 += 20* 0;
            larm.x3 += 20* 1;
            larm.y3 += 20* 1;
        }
        else if(larm.dir == 2) {
            larm.dir = 3;
            larm.x0 -= 20* 2;
            larm.y0 -= 20* 2;
            larm.x1 -= 20* 1;
            larm.y1 -= 20* 1;
            larm.x2 -= 20* 0;
            larm.y2 -= 20* 0;
            larm.x3 -= 20* 1;
            larm.y3 += 20* 1;
        }
        else if(larm.dir == 3) {
            larm.dir = 0;
            larm.x0 += 20* 2;
            larm.y0 -= 20* 2;
            larm.x1 += 20* 1;
            larm.y1 -= 20* 1;
            larm.x2 += 20* 0;
            larm.y2 -= 20* 0;
            larm.x3 -= 20* 1;
            larm.y3 -= 20* 1;
        }

        if(larm.x0 > 400 || larm.x1 > 400 || larm.x2 > 400 || larm.x3 > 400 ||
           larm.x0 < 220 || larm.x1 < 220 || larm.x2 < 220 || larm.x3 < 220) {
            larm.dir = larmdir;
            larm.x0 = larmx0;
            larm.y0 = larmy0;
            larm.x1 = larmx1;
            larm.y1 = larmy1;
            larm.x2 = larmx2;
            larm.y2 = larmy2;
            larm.x3 = larmx3;
            larm.y3 = larmy3;
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);
    }
    else if(choice == "rarm") {
        
        int rarmx0, rarmy0, rarmx1, rarmy1, rarmx2, rarmy2, rarmx3, rarmy3, rarmdir;

        rarmdir = rarm.dir;
        rarmx0 = rarm.x0;
        rarmy0 = rarm.y0;
        rarmx1 = rarm.x1;
        rarmy1 = rarm.y1;
        rarmx2 = rarm.x2;
        rarmy2 = rarm.y2;
        rarmx3 = rarm.x3;
        rarmy3 = rarm.y3;

        if(rarm.dir == 0) {
            rarm.dir = 1;
            rarm.x0 += 20* 2;
            rarm.y0 += 20* 2;
            rarm.x1 += 20* 1;
            rarm.y1 += 20* 1;
            rarm.x2 += 20* 0;
            rarm.y2 += 20* 0;
            rarm.x3 -= 20* 1;
            rarm.y3 += 20* 1;
        }
        else if(rarm.dir == 1) {
            rarm.dir = 2;
            rarm.x0 -= 20* 2;
            rarm.y0 += 20* 2;
            rarm.x1 -= 20* 1;
            rarm.y1 += 20* 1;
            rarm.x2 -= 20* 0;
            rarm.y2 += 20* 0;
            rarm.x3 -= 20* 1;
            rarm.y3 -= 20* 1;
        }
        else if(rarm.dir == 2) {
            rarm.dir = 3;
            rarm.x0 -= 20* 2;
            rarm.y0 -= 20* 2;
            rarm.x1 -= 20* 1;
            rarm.y1 -= 20* 1;
            rarm.x2 -= 20* 0;
            rarm.y2 -= 20* 0;
            rarm.x3 += 20* 1;
            rarm.y3 -= 20* 1;
        }
        else if(rarm.dir == 3) {
            rarm.dir = 0;
            rarm.x0 += 20* 2;
            rarm.y0 -= 20* 2;
            rarm.x1 += 20* 1;
            rarm.y1 -= 20* 1;
            rarm.x2 += 20* 0;
            rarm.y2 -= 20* 0;
            rarm.x3 += 20* 1;
            rarm.y3 += 20* 1;
        }

        if(rarm.x0 > 400 || rarm.x1 > 400 || rarm.x2 > 400 || rarm.x3 > 400 ||
           rarm.x0 < 220 || rarm.x1 < 220 || rarm.x2 < 220 || rarm.x3 < 220) {
            rarm.dir = rarmdir;
            rarm.x0 = rarmx0;
            rarm.y0 = rarmy0;
            rarm.x1 = rarmx1;
            rarm.y1 = rarmy1;
            rarm.x2 = rarmx2;
            rarm.y2 = rarmy2;
            rarm.x3 = rarmx3;
            rarm.y3 = rarmy3;
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);
    }
    else if(choice == "lsh") {
        
        int lshx0, lshy0, lshx1, lshy1, lshx2, lshy2, lshx3, lshy3, lshdir;

        lshdir = lsh.dir;
        lshx0 = lsh.x0;
        lshy0 = lsh.y0;
        lshx1 = lsh.x1;
        lshy1 = lsh.y1;
        lshx2 = lsh.x2;
        lshy2 = lsh.y2;
        lshx3 = lsh.x3;
        lshy3 = lsh.y3;

        if(lsh.dir == 0) {
            lsh.dir = 1;
            lsh.x0 += 20* 1;
            lsh.y0 += 20* 1;
            lsh.x1 += 20* 1;
            lsh.y1 -= 20* 1;
            lsh.x2 += 20* 0;
            lsh.y2 += 20* 0;
            lsh.x3 += 20* 0;
            lsh.y3 -= 20* 2;
        }
        else if(lsh.dir == 1) {
            lsh.dir = 2;
            lsh.x0 -= 20* 1;
            lsh.y0 += 20* 1;
            lsh.x1 += 20* 1;
            lsh.y1 += 20* 1;
            lsh.x2 -= 20* 0;
            lsh.y2 += 20* 0;
            lsh.x3 += 20* 2;
            lsh.y3 -= 20* 0;
        }
        else if(lsh.dir == 2) {
            lsh.dir = 3;
            lsh.x0 -= 20* 1;
            lsh.y0 -= 20* 1;
            lsh.x1 -= 20* 1;
            lsh.y1 += 20* 1;
            lsh.x2 -= 20* 0;
            lsh.y2 -= 20* 0;
            lsh.x3 -= 20* 0;
            lsh.y3 += 20* 2;
        }
        else if(lsh.dir == 3) {
            lsh.dir = 0;
            lsh.x0 += 20* 1;
            lsh.y0 -= 20* 1;
            lsh.x1 -= 20* 1;
            lsh.y1 -= 20* 1;
            lsh.x2 += 20* 0;
            lsh.y2 -= 20* 0;
            lsh.x3 -= 20* 2;
            lsh.y3 += 20* 0;
        }

        if(lsh.x0 > 400 || lsh.x1 > 400 || lsh.x2 > 400 || lsh.x3 > 400 ||
           lsh.x0 < 220 || lsh.x1 < 220 || lsh.x2 < 220 || lsh.x3 < 220) {
            lsh.dir = lshdir;
            lsh.x0 = lshx0;
            lsh.y0 = lshy0;
            lsh.x1 = lshx1;
            lsh.y1 = lshy1;
            lsh.x2 = lshx2;
            lsh.y2 = lshy2;
            lsh.x3 = lshx3;
            lsh.y3 = lshy3;
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);
    }
    else if(choice == "rsh") {
        
        int rshx0, rshy0, rshx1, rshy1, rshx2, rshy2, rshx3, rshy3, rshdir;

        rshdir = rsh.dir;
        rshx0 = rsh.x0;
        rshy0 = rsh.y0;
        rshx1 = rsh.x1;
        rshy1 = rsh.y1;
        rshx2 = rsh.x2;
        rshy2 = rsh.y2;
        rshx3 = rsh.x3;
        rshy3 = rsh.y3;

        if(rsh.dir == 0) {
            rsh.dir = 1;
            rsh.x0 += 20* 1;
            rsh.y0 += 20* 1;
            rsh.x1 += 20* 0;
            rsh.y1 += 20* 0;
            rsh.x2 -= 20* 1;
            rsh.y2 += 20* 1;
            rsh.x3 -= 20* 2;
            rsh.y3 += 20* 0;
        }
        else if(rsh.dir == 1) {
            rsh.dir = 2;
            rsh.x0 -= 20* 1;
            rsh.y0 += 20* 1;
            rsh.x1 += 20* 0;
            rsh.y1 += 20* 0;
            rsh.x2 -= 20* 1;
            rsh.y2 -= 20* 1;
            rsh.x3 -= 20* 0;
            rsh.y3 -= 20* 2;
        }
        else if(rsh.dir == 2) {
            rsh.dir = 3;
            rsh.x0 -= 20* 1;
            rsh.y0 -= 20* 1;
            rsh.x1 -= 20* 0;
            rsh.y1 -= 20* 0;
            rsh.x2 += 20* 1;
            rsh.y2 -= 20* 1;
            rsh.x3 += 20* 2;
            rsh.y3 -= 20* 0;
        }
        else if(rsh.dir == 3) {
            rsh.dir = 0;
            rsh.x0 += 20* 1;
            rsh.y0 -= 20* 1;
            rsh.x1 += 20* 0;
            rsh.y1 -= 20* 0;
            rsh.x2 += 20* 1;
            rsh.y2 += 20* 1;
            rsh.x3 += 20* 0;
            rsh.y3 += 20* 2;
        }

        if(rsh.x0 > 400 || rsh.x1 > 400 || rsh.x2 > 400 || rsh.x3 > 400 ||
           rsh.x0 < 220 || rsh.x1 < 220 || rsh.x2 < 220 || rsh.x3 < 220) {
            rsh.dir = rshdir;
            rsh.x0 = rshx0;
            rsh.y0 = rshy0;
            rsh.x1 = rshx1;
            rsh.y1 = rshy1;
            rsh.x2 = rshx2;
            rsh.y2 = rshy2;
            rsh.x3 = rshx3;
            rsh.y3 = rshy3;
        }

        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));

        RECT rrect3 = {rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20};
        FillRect(hdc2, &rrect3, brush);

        RECT rrect4 = {rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20};
        FillRect(hdc2, &rrect4, brush);

        RECT rrect5 = {rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20};
        FillRect(hdc2, &rrect5, brush);

        RECT rrect6 = {rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    DeleteObject(hdc2);
    hdc2 = GetDC(hwnd);
  
    switch(msg)
    {
        case WM_KEYDOWN: 
            switch (wParam) 
            { 
                case VK_LEFT: 
                    
                    goLeft();
                    for(int i=0; i<700; i++) {
                        for(int j=0; j<700; j++) {
                            if(b[i][j] == 1) {
                                HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                                RECT rrect6 = {i, j, i + 20, j + 20};
                                FillRect(hdc2, &rrect6, brush);
                                DeleteObject(brush);

                                HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                                Rectangle(hdc2, i, j, i + 20, j + 20);
                                DeleteObject(SelectObject(hdc2, hOldPen));
                                SelectObject(hdc2, hOldBsh);
                            }
                        }
                    }
                
                    break;
 
                case VK_RIGHT: 
                    
                    goRight();
                    for(int i=0; i<700; i++) {
                        for(int j=0; j<700; j++) {
                            if(b[i][j] == 1) {
                                HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                                RECT rrect6 = {i, j, i + 20, j + 20};
                                FillRect(hdc2, &rrect6, brush);
                                DeleteObject(brush);

                                HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                                Rectangle(hdc2, i, j, i + 20, j + 20);
                                DeleteObject(SelectObject(hdc2, hOldPen));
                                SelectObject(hdc2, hOldBsh);
                            }
                        }
                    }
                     
                    break; 
 
                case VK_UP: 
                    
                    rotate();
                    for(int i=0; i<700; i++) {
                        for(int j=0; j<700; j++) {
                            if(b[i][j] == 1) {
                                HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                                RECT rrect6 = {i, j, i + 20, j + 20};
                                FillRect(hdc2, &rrect6, brush);
                                DeleteObject(brush);

                                HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                                Rectangle(hdc2, i, j, i + 20, j + 20);
                                DeleteObject(SelectObject(hdc2, hOldPen));
                                SelectObject(hdc2, hOldBsh);
                            }
                        }
                    }
                     
                    break; 
 
                case VK_DOWN: 
                    goDown();
                    for(int i=0; i<700; i++) {
                        for(int j=0; j<700; j++) {
                            if(b[i][j] == 1) {
                                HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                                RECT rrect6 = {i, j, i + 20, j + 20};
                                FillRect(hdc2, &rrect6, brush);
                                DeleteObject(brush);

                                HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 1, RGB(255, 0, 255)));
                                Rectangle(hdc2, i, j, i + 20, j + 20);
                                DeleteObject(SelectObject(hdc2, hOldPen));
                                SelectObject(hdc2, hOldBsh);
                            }
                        }
                    }
                    break;
                case VK_SPACE:
                    do {
                      
                    } while (goDown());
                    break;
        }
        case WM_PAINT:
        {
            if(fist) {
                HBRUSH brush = CreateSolidBrush(RGB(255, 200, 5));
                RECT rrect = {0, 0, 640, 750};
                FillRect(hdc2, &rrect, brush);
                DeleteObject(brush);

                thrad = CreateThread(NULL, 0, paintMe, NULL, 0, NULL);
                
                thread = CreateThread(NULL, 0, downs, NULL, 0, NULL);
                srand(time(NULL));
                prep();
            }

            for(int i=0; i<700; i++) {
                for(int j=0; j<720; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);
                    }
                }
            }
        }
        break;
        case WM_CREATE:
        {
            int y = 600; int h = 48;
            int x = 443; int w = 124;
  	    hwnd_new_game = CreateWindowEx(0, "BUTTON", "TRY NEW!", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
								x, y, w, h, hwnd, (HMENU) PLAY_AGAIN_BUTTON, GetModuleHandle(NULL), NULL);
        }
        break;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case PLAY_AGAIN_BUTTON:
                    if (HIWORD(wParam) == BN_CLICKED) {
                        GetCurrentDir( buff, FILENAME_MAX );
                        buff[strlen(buff)] = '\0';
                        strcpy(filename,buff);
                        strcat(filename,"\\WinTris.exe");
                        filename[strlen(filename)] = '\0';
                        STARTUPINFO startUpInfo = { 0 };
                        PROCESS_INFORMATION procInfo = { 0 };
                        startUpInfo.cb = sizeof( startUpInfo );
                        CreateProcess( filename, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startUpInfo, &procInfo );
                        exit(0);
                    }
                break;
            }
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void printMiscLabels(int stage) {
    font = CreateFont(30, 0, 0, 0,
                      FW_NORMAL, FALSE, FALSE, FALSE,
                      ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                    CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                    DEFAULT_PITCH | FF_ROMAN,
                   "Helvetica");

    char aa[16];sprintf(aa,"Stage: %d of 40",stage);

    SelectObject(hdc2, font);
    TextOut(hdc2, 440, 20, aa, 16);
    DeleteObject(font);
    
    font = CreateFont(30, 0, 0, 0,
                      FW_NORMAL, FALSE, FALSE, FALSE,
                      ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                    CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                    DEFAULT_PITCH | FF_ROMAN,
                   "Helvetica");

    int v = 800 - sleeptime;
    char bb[16];sprintf(bb,"Speed: %d", v);

    SelectObject(hdc2, font);
    if(v < 100)
        TextOut(hdc2, 440, 120, bb, 9);
    else
        TextOut(hdc2, 440, 120, bb, 10);
    DeleteObject(font);

    font = CreateFont(30, 0, 0, 0,
                      FW_NORMAL, FALSE, FALSE, FALSE,
                      ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                    CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                    DEFAULT_PITCH | FF_ROMAN,
                   "Verdana");

    SelectObject(hdc2, font);
    TextOut(hdc2, 443, 480, "WinTris", 7);
    DeleteObject(font);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {
  
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = CS_PARENTDC;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
    
    if(!RegisterClassEx(&wc)) {
        return 0;
    }

    hwnd = CreateWindowEx(WS_EX_LAYERED,
            g_szClassName, "",
            WS_OVERLAPPEDWINDOW,
            0, 0, 640, 750,
            NULL, NULL, hInstance, NULL);

    if(hwnd == NULL) {
        return 0;
    }
    
    int number = 100;

    SetLayeredWindowAttributes(hwnd, 0, (255 * number) / 100, LWA_ALPHA);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);

    RECT rc;
    GetWindowRect(hwnd, &rc);
    int xPos = (GetSystemMetrics(SM_CXSCREEN) - rc.right) / 2;
    int yPos = (GetSystemMetrics(SM_CYSCREEN) - rc.bottom) / 2;
    SetWindowPos(hwnd, NULL, xPos, yPos, 0, 0, SWP_NOZORDER | SWP_NOSIZE);

    while(GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}