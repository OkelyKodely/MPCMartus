#include <windows.h>

char * choicepre = "sq";

HINSTANCE hInst;
BITMAP bitmap;
HDC hdcMem;
HGDIOBJ oldBitmap;
HBITMAP hBitmap;

HFONT font;

int level = 1;

int blocks=0;
int points=1000000;
int lines=0;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

const char g_szClassName[] = "TetrisC";

WNDCLASSEX wc;
HWND hwnd, hwnd_title, hwnd_stage, hwnd_next, hwnd_lines, hwnd_points, hwnd_blocks, hwnd_level;
MSG Msg;

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

int b[740][720];

HANDLE thread;

BOOLEAN fist = TRUE;

char* choice;

int sleeptime = 800;

int linenext = 4;

DWORD WINAPI downs(void *data) {
    while (1) {
        printf(choicepre);
        returnStage(level);
        HBRUSH brush = CreateSolidBrush(RGB(254, 254, 254));
        RECT rrect5 = {60, 80, 190, 200};
        FillRect(hdc2, &rrect5, brush);
        DeleteObject(brush);
        if(choicepre == "sq") {
            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
            RECT rrect5 = {100, 100, 100 + 20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {120, 100, 120 + 20, 100 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {100, 120, 100 + 20, 120 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {120, 120, 120 + 20, 120 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        }
        else if(choicepre == "lne") {
            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
            RECT rrect5 = {100, 100, 100 + 20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {100, 120, 100 + 20, 120 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {100, 140, 100 + 20, 140 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {100, 160, 100 + 20, 160 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        }
        else if(choicepre == "ht") {
            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
            RECT rrect5 = {120, 100, 120 + 20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {100, 120, 100 + 20, 120 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {120, 120, 120 + 20, 120 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {140, 120, 140 + 20, 120 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        }
        else if(choicepre == "larm") {
            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
            RECT rrect5 = {120, 100, 120 + 20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {120, 120, 120 + 20, 120 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {120, 140, 120 + 20, 140 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {100, 140, 100 + 20, 140 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        }
        else if(choicepre == "rarm") {
            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
            RECT rrect5 = {120, 100, 120 + 20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {120, 120, 120 + 20, 120 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {120, 140, 120 + 20, 140 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {140, 140, 140 + 20, 140 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        }
        else if(choicepre == "lsh") {
            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
            RECT rrect5 = {120, 100, 120 + 20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {120, 120, 120 + 20, 120 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {100, 120, 100 + 20, 120 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {100, 140, 100 + 20, 140 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        }
        else if(choicepre == "rsh") {
            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
            RECT rrect5 = {100, 100, 100 + 20, 100 + 20};
            FillRect(hdc2, &rrect5, brush);
            RECT rrect6 = {100, 120, 100 + 20, 120 + 20};
            FillRect(hdc2, &rrect6, brush);
            RECT rrect7 = {120, 120, 120 + 20, 120 + 20};
            FillRect(hdc2, &rrect7, brush);
            RECT rrect8 = {120, 140, 120 + 20, 140 + 20};
            FillRect(hdc2, &rrect8, brush);
            DeleteObject(brush);
        }
        hdc2 = GetDC (hwnd);
        Sleep(sleeptime);
        int count =0;
        int clearBlocks[700];
        for(int i=0; i<700; i++) {
            clearBlocks[i] = 0;
        }
        for(int j=0; j<700; j+=1) {
            int clearThisLine = 0;
            for(int i=0; i<740; i+=1) {
                int x = i;
                int y = j;
                if(1 == b[i][j]) {
                    clearThisLine++;
                }
            }
            if(clearThisLine >= 10) {
                points += 10;
                lines += 1;
                char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                clearBlocks[count] = j;
                ++ count;
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
                for(int j=700; j>=0; j--) {
                    for(int i=0; i<740; i++) {
                        if(b[i][j] == 1 && j < clearBlocks[cnt]) {
                            b[i][j] = 0;
                            b[i][j+20] = 1;
                        }
                    }
                }
            }
        }
        printf("asdfsdfaABC:");
        printf(choice);
        printf("\n");
        if(choice == "sq") {
            printf("here i am");
            //hdc2 = GetDC(hwnd);
            hdcMems = CreateCompatibleDC(hdc2);

            hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

            oldBitmap = SelectObject(hdcMems, hBitmap);

            GetObject(hBitmap, sizeof(bitmap), &bitmap);
            BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

            SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
            DeleteDC(hdcMems); DeleteObject(hBitmap);

            sq.y0 += 20;
            sq.y1 += 20;
            sq.y2 += 20;
            sq.y3 += 20;
        
            HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect3 = {sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20};
            FillRect(hdc2, &rrect3, brush);
            DeleteObject(brush);

            HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect4 = {sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20};
            FillRect(hdc2, &rrect4, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect5 = {sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20};
            FillRect(hdc2, &rrect5, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect6 = {sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            if(b[sq.x0][sq.y0] == 1) {
                for(int i=0; i<600; i++) {
                    for(int j=0; j<720; j++) {
                        b[i][j] = 0;
                    }
                }
            }

            if(sq.y0 > 650 || sq.y1 > 650 || sq.y2 > 650 || sq.y3 > 650) {
                b[sq.x0][sq.y0] = 1;
                b[sq.x1][sq.y1] = 1;
                b[sq.x2][sq.y2] = 1;
                b[sq.x3][sq.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
                blocks = 0;
                lines = 0;
                points = 1000000;
            }
            if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "lne") {
            //hdc2 = GetDC(hwnd);
            hdcMems = CreateCompatibleDC(hdc2);

            hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

            oldBitmap = SelectObject(hdcMems, hBitmap);

            GetObject(hBitmap, sizeof(bitmap), &bitmap);
            BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

            SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
            DeleteDC(hdcMems); DeleteObject(hBitmap);

            lne.y0 += 20;
            lne.y1 += 20;
            lne.y2 += 20;
            lne.y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect3 = {lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20};
            FillRect(hdc2, &rrect3, brush);
            DeleteObject(brush);

            HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect4 = {lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20};
            FillRect(hdc2, &rrect4, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect5 = {lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20};
            FillRect(hdc2, &rrect5, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect6 = {lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            if(b[lne.x0][lne.y0] == 1) {
                for(int i=0; i<600; i++) {
                    for(int j=0; j<700; j++) {
                        b[i][j] = 0;
                    }
                }
            }

            if(lne.y0 > 650 || lne.y1 > 650 || lne.y2 > 650 || lne.y3 > 650) {
                b[lne.x0][lne.y0] = 1;
                b[lne.x1][lne.y1] = 1;
                b[lne.x2][lne.y2] = 1;
                b[lne.x3][lne.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
                blocks = 0;
                lines = 0;
                points = 1000000;
            }
            if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "ht") {
            //hdc2 = GetDC(hwnd);
            hdcMems = CreateCompatibleDC(hdc2);

            hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

            oldBitmap = SelectObject(hdcMems, hBitmap);

            GetObject(hBitmap, sizeof(bitmap), &bitmap);
            BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

            SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
            DeleteDC(hdcMems); DeleteObject(hBitmap);

            ht.y0 += 20;
            ht.y1 += 20;
            ht.y2 += 20;
            ht.y3 += 20;
        
            HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect3 = {ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20};
            FillRect(hdc2, &rrect3, brush);
            DeleteObject(brush);

            HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect4 = {ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20};
            FillRect(hdc2, &rrect4, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect5 = {ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20};
            FillRect(hdc2, &rrect5, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect6 = {ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            if(b[ht.x0][ht.y0] == 1) {
                for(int i=0; i<600; i++) {
                    for(int j=0; j<700; j++) {
                        b[i][j] = 0;
                    }
                }
            }

            if(ht.y0 > 650 || ht.y1 > 650 || ht.y2 > 650 || ht.y3 > 650) {
                b[ht.x0][ht.y0] = 1;
                b[ht.x1][ht.y1] = 1;
                b[ht.x2][ht.y2] = 1;
                b[ht.x3][ht.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "larm") {
            //hdc2 = GetDC(hwnd);
            hdcMems = CreateCompatibleDC(hdc2);

            hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

            oldBitmap = SelectObject(hdcMems, hBitmap);

            GetObject(hBitmap, sizeof(bitmap), &bitmap);
            BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

            SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
            DeleteDC(hdcMems); DeleteObject(hBitmap);

            larm.y0 += 20;
            larm.y1 += 20;
            larm.y2 += 20;
            larm.y3 += 20;
        
            HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect3 = {larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20};
            FillRect(hdc2, &rrect3, brush);
            DeleteObject(brush);

            HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect4 = {larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20};
            FillRect(hdc2, &rrect4, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect5 = {larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20};
            FillRect(hdc2, &rrect5, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect6 = {larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            if(b[larm.x0][larm.y0] == 1) {
                for(int i=0; i<600; i++) {
                    for(int j=0; j<700; j++) {
                        b[i][j] = 0;
                    }
                }
            }

            if(larm.y0 > 650 || larm.y1 > 650 || larm.y2 > 650 || larm.y3 > 650) {
                b[larm.x0][larm.y0] = 1;
                b[larm.x1][larm.y1] = 1;
                b[larm.x2][larm.y2] = 1;
                b[larm.x3][larm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "rarm") {
            //hdc2 = GetDC(hwnd);
            hdcMems = CreateCompatibleDC(hdc2);

            hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

            oldBitmap = SelectObject(hdcMems, hBitmap);

            GetObject(hBitmap, sizeof(bitmap), &bitmap);
            BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

            SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
            DeleteDC(hdcMems); DeleteObject(hBitmap);

            rarm.y0 += 20;
            rarm.y1 += 20;
            rarm.y2 += 20;
            rarm.y3 += 20;
        
            HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect3 = {rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20};
            FillRect(hdc2, &rrect3, brush);
            DeleteObject(brush);

            HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect4 = {rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20};
            FillRect(hdc2, &rrect4, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect5 = {rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20};
            FillRect(hdc2, &rrect5, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect6 = {rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            if(b[rarm.x0][rarm.y0] == 1) {
                for(int i=0; i<600; i++) {
                    for(int j=0; j<700; j++) {
                        b[i][j] = 0;
                    }
                }
            }

            if(rarm.y0 > 650 || rarm.y1 > 650 || rarm.y2 > 650 || rarm.y3 > 650) {
                b[rarm.x0][rarm.y0] = 1;
                b[rarm.x1][rarm.y1] = 1;
                b[rarm.x2][rarm.y2] = 1;
                b[rarm.x3][rarm.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "lsh") {
            //hdc2 = GetDC(hwnd);
            hdcMems = CreateCompatibleDC(hdc2);

            hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

            oldBitmap = SelectObject(hdcMems, hBitmap);

            GetObject(hBitmap, sizeof(bitmap), &bitmap);
            BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

            SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
            DeleteDC(hdcMems); DeleteObject(hBitmap);

            lsh.y0 += 20;
            lsh.y1 += 20;
            lsh.y2 += 20;
            lsh.y3 += 20;
        
            HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect3 = {lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20};
            FillRect(hdc2, &rrect3, brush);
            DeleteObject(brush);

            HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect4 = {lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20};
            FillRect(hdc2, &rrect4, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect5 = {lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20};
            FillRect(hdc2, &rrect5, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect6 = {lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            if(b[lsh.x0][lsh.y0] == 1) {
                for(int i=0; i<600; i++) {
                    for(int j=0; j<700; j++) {
                        b[i][j] = 0;
                    }
                }
            }

            if(lsh.y0 > 650 || lsh.y1 > 650 || lsh.y2 > 650 || lsh.y3 > 650) {
                b[lsh.x0][lsh.y0] = 1;
                b[lsh.x1][lsh.y1] = 1;
                b[lsh.x2][lsh.y2] = 1;
                b[lsh.x3][lsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(choice == "rsh") {
            //hdc2 = GetDC(hwnd);
            hdcMems = CreateCompatibleDC(hdc2);

            hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

            oldBitmap = SelectObject(hdcMems, hBitmap);

            GetObject(hBitmap, sizeof(bitmap), &bitmap);
            BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

            SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
            DeleteDC(hdcMems); DeleteObject(hBitmap);

            rsh.y0 += 20;
            rsh.y1 += 20;
            rsh.y2 += 20;
            rsh.y3 += 20;
        
            HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect3 = {rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20};
            FillRect(hdc2, &rrect3, brush);
            DeleteObject(brush);

            HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect4 = {rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20};
            FillRect(hdc2, &rrect4, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect5 = {rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20};
            FillRect(hdc2, &rrect5, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            brush = CreateSolidBrush(RGB(255, 165, 0));
            RECT rrect6 = {rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20};
            FillRect(hdc2, &rrect6, brush);
            DeleteObject(brush);

            hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
            hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
            Rectangle(hdc2, rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20);
            DeleteObject(SelectObject(hdc2, hOldPen));
            SelectObject(hdc2, hOldBsh);

            if(b[rsh.x0][rsh.y0] == 1) {
                for(int i=0; i<600; i++) {
                    for(int j=0; j<700; j++) {
                        b[i][j] = 0;
                    }
                }
            }

            if(rsh.y0 > 650 || rsh.y1 > 650 || rsh.y2 > 650 || rsh.y3 > 650) {
                b[rsh.x0][rsh.y0] = 1;
                b[rsh.x1][rsh.y1] = 1;
                b[rsh.x2][rsh.y2] = 1;
                b[rsh.x3][rsh.y3] = 1;
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                prep();
            }
            if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                }
            }
        }
    }
    return 0;
}

void prep() {
    fist = FALSE;
    choice = choicepre;
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
}

void rotate() {
    if(choice == "sq") {
        //hdc2 = GetDC(hwnd);
        hdcMems = CreateCompatibleDC(hdc2);

        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

        oldBitmap = SelectObject(hdcMems, hBitmap);

        GetObject(hBitmap, sizeof(bitmap), &bitmap);
        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
        DeleteDC(hdcMems); DeleteObject(hBitmap);

        sq.y0 += 0;
        sq.y1 += 0;
        sq.y2 += 0;
        sq.y3 += 0;

        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect3 = {sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20};
        FillRect(hdc2, &rrect3, brush);
        DeleteObject(brush);

        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);
        
        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect4 = {sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20};
        FillRect(hdc2, &rrect4, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect5 = {sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20};
        FillRect(hdc2, &rrect5, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect6 = {sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);
    }
    else if(choice == "lne") {
        //hdc2 = GetDC(hwnd);
        hdcMems = CreateCompatibleDC(hdc2);

        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

        oldBitmap = SelectObject(hdcMems, hBitmap);

        GetObject(hBitmap, sizeof(bitmap), &bitmap);
        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
        DeleteDC(hdcMems); DeleteObject(hBitmap);

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

        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect3 = {lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20};
        FillRect(hdc2, &rrect3, brush);
        DeleteObject(brush);

        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);
        
        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect4 = {lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20};
        FillRect(hdc2, &rrect4, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect5 = {lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20};
        FillRect(hdc2, &rrect5, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect6 = {lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);
    }
    else if(choice == "ht") {
        //hdc2 = GetDC(hwnd);
        hdcMems = CreateCompatibleDC(hdc2);

        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

        oldBitmap = SelectObject(hdcMems, hBitmap);

        GetObject(hBitmap, sizeof(bitmap), &bitmap);
        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
        DeleteDC(hdcMems); DeleteObject(hBitmap);

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

        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect3 = {ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20};
        FillRect(hdc2, &rrect3, brush);
        DeleteObject(brush);

        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect4 = {ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20};
        FillRect(hdc2, &rrect4, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect5 = {ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20};
        FillRect(hdc2, &rrect5, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect6 = {ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);
    }
    else if(choice == "larm") {
        //hdc2 = GetDC(hwnd);
        hdcMems = CreateCompatibleDC(hdc2);

        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

        oldBitmap = SelectObject(hdcMems, hBitmap);

        GetObject(hBitmap, sizeof(bitmap), &bitmap);
        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
        DeleteDC(hdcMems); DeleteObject(hBitmap);

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

        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect3 = {larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20};
        FillRect(hdc2, &rrect3, brush);
        DeleteObject(brush);

        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);
        
        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect4 = {larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20};
        FillRect(hdc2, &rrect4, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect5 = {larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20};
        FillRect(hdc2, &rrect5, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect6 = {larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);
    }
    else if(choice == "rarm") {
        //hdc2 = GetDC(hwnd);
        hdcMems = CreateCompatibleDC(hdc2);

        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

        oldBitmap = SelectObject(hdcMems, hBitmap);

        GetObject(hBitmap, sizeof(bitmap), &bitmap);
        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
        DeleteDC(hdcMems); DeleteObject(hBitmap);

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

        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect3 = {rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20};
        FillRect(hdc2, &rrect3, brush);
        DeleteObject(brush);

        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);
        
        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect4 = {rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20};
        FillRect(hdc2, &rrect4, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect5 = {rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20};
        FillRect(hdc2, &rrect5, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect6 = {rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);
    }
    else if(choice == "lsh") {
        //hdc2 = GetDC(hwnd);
        hdcMems = CreateCompatibleDC(hdc2);

        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

        oldBitmap = SelectObject(hdcMems, hBitmap);

        GetObject(hBitmap, sizeof(bitmap), &bitmap);
        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
        DeleteDC(hdcMems); DeleteObject(hBitmap);

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

        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect3 = {lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20};
        FillRect(hdc2, &rrect3, brush);
        DeleteObject(brush);

        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);
        
        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect4 = {lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20};
        FillRect(hdc2, &rrect4, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect5 = {lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20};
        FillRect(hdc2, &rrect5, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect6 = {lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);
    }
    else if(choice == "rsh") {
        //hdc2 = GetDC(hwnd);
        hdcMems = CreateCompatibleDC(hdc2);

        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

        oldBitmap = SelectObject(hdcMems, hBitmap);

        GetObject(hBitmap, sizeof(bitmap), &bitmap);
        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
        DeleteDC(hdcMems); DeleteObject(hBitmap);

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

        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect3 = {rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20};
        FillRect(hdc2, &rrect3, brush);
        DeleteObject(brush);

        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);
        
        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect4 = {rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20};
        FillRect(hdc2, &rrect4, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect5 = {rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20};
        FillRect(hdc2, &rrect5, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);

        brush = CreateSolidBrush(RGB(255, 165, 0));
        RECT rrect6 = {rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20};
        FillRect(hdc2, &rrect6, brush);
        DeleteObject(brush);

        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
        Rectangle(hdc2, rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20);
        DeleteObject(SelectObject(hdc2, hOldPen));
        SelectObject(hdc2, hOldBsh);
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CHAR:  {
            switch (wParam)  
            {  
                case 'i':  {
                    //code here    
                    rotate();
                    for(int i=0; i<700; i++) {
                        for(int j=0; j<700; j++) {
                            if(b[i][j] == 1) {
                                HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                                RECT rrect6 = {i, j, i + 20, j + 20};
                                FillRect(hdc2, &rrect6, brush);
                                DeleteObject(brush);

                                HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                Rectangle(hdc2, i, j, i + 20, j + 20);
                                DeleteObject(SelectObject(hdc2, hOldPen));
                                SelectObject(hdc2, hOldBsh);
                            }
                        }
                    }
                    break;  
                }
                case 'k':  {
                        //your code here    
                    if(choice == "sq" && (sq.y0 <= 610 || sq.y1 <= 610 || sq.y2 <= 610 || sq.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);
                        
                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);
                        sq.y0 += 20;
                        sq.y1 += 20;
                        sq.y2 += 20;
                        sq.y3 += 20;

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[sq.x0][sq.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<720; j++) {
                                    b[i][j] = 0;
                                }
                            }
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                    }
                    else if(choice == "lne" && (lne.y0 <= 580 || lne.y1 <= 580 || lne.y2 <= 580 || lne.y3 <= 580)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);
                        lne.y0 += 20;
                        lne.y1 += 20;
                        lne.y2 += 20;
                        lne.y3 += 20;

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[lne.x0][lne.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<720; j++) {
                                    b[i][j] = 0;
                                }
                            }
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                    }
                    else if(choice == "ht" && (ht.y0 <= 610 || ht.y1 <= 610 || ht.y2 <= 610 || ht.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);
                        ht.y0 += 20;
                        ht.y1 += 20;
                        ht.y2 += 20;
                        ht.y3 += 20;

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[ht.x0][ht.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<720; j++) {
                                    b[i][j] = 0;
                                }
                            }
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                    }
                    else if(choice == "larm" && (larm.y0 <= 610 || larm.y1 <= 610 || larm.y2 <= 610 || larm.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);

                        larm.y0 += 20;
                        larm.y1 += 20;
                        larm.y2 += 20;
                        larm.y3 += 20;

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[larm.x0][larm.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<700; j++) {
                                    b[i][j] = 0;
                                }
                            }
                        }

                        if(larm.y0 > 650 || larm.y1 > 650 || larm.y2 > 650 || larm.y3 > 650) {
                            b[larm.x0][larm.y0] = 1;
                            b[larm.x1][larm.y1] = 1;
                            b[larm.x2][larm.y2] = 1;
                            b[larm.x3][larm.y3] = 1;
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                        for(int i=0; i<700; i++) {
                            for(int j=0; j<700; j++) {
                                if(b[i][j] == 1) {
                                    HBRUSH brush = CreateSolidBrush(RGB(50, 50, 50));
                                    RECT rrect6 = {i, j, i + 20, j + 20};
                                    FillRect(hdc2, &rrect6, brush);
                                    DeleteObject(brush);

                                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                    Rectangle(hdc2, i, j, i + 20, j + 20);
                                    DeleteObject(SelectObject(hdc2, hOldPen));
                                    SelectObject(hdc2, hOldBsh);
                                }
                            }
                        }
                    }
                    else if(choice == "rarm" && (rarm.y0 <= 610 || rarm.y1 <= 610 || rarm.y2 <= 610 || rarm.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);

                        rarm.y0 += 20;
                        rarm.y1 += 20;
                        rarm.y2 += 20;
                        rarm.y3 += 20;

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[rarm.x0][rarm.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<700; j++) {
                                    b[i][j] = 0;
                                }
                            }
                        }

                        if(rarm.y0 > 650 || rarm.y1 > 650 || rarm.y2 > 650 || rarm.y3 > 650) {
                            b[rarm.x0][rarm.y0] = 1;
                            b[rarm.x1][rarm.y1] = 1;
                            b[rarm.x2][rarm.y2] = 1;
                            b[rarm.x3][rarm.y3] = 1;
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                        for(int i=0; i<700; i++) {
                            for(int j=0; j<700; j++) {
                                if(b[i][j] == 1) {
                                    HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                                    RECT rrect6 = {i, j, i + 20, j + 20};
                                    FillRect(hdc2, &rrect6, brush);
                                    DeleteObject(brush);

                                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                    Rectangle(hdc2, i, j, i + 20, j + 20);
                                    DeleteObject(SelectObject(hdc2, hOldPen));
                                    SelectObject(hdc2, hOldBsh);
                                }
                            }
                        }
                    }
                    else if(choice == "lsh" && (lsh.y0 <= 610 || lsh.y1 <= 610 || lsh.y2 <= 610 || lsh.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);

                        lsh.y0 += 20;
                        lsh.y1 += 20;
                        lsh.y2 += 20;
                        lsh.y3 += 20;

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[lsh.x0][lsh.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<700; j++) {
                                    b[i][j] = 0;
                                }
                            }
                        }

                        if(lsh.y0 > 650 || lsh.y1 > 650 || lsh.y2 > 650 || lsh.y3 > 650) {
                            b[lsh.x0][lsh.y0] = 1;
                            b[lsh.x1][lsh.y1] = 1;
                            b[lsh.x2][lsh.y2] = 1;
                            b[lsh.x3][lsh.y3] = 1;
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                        for(int i=0; i<700; i++) {
                            for(int j=0; j<700; j++) {
                                if(b[i][j] == 1) {
                                    HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                                    RECT rrect6 = {i, j, i + 20, j + 20};
                                    FillRect(hdc2, &rrect6, brush);
                                    DeleteObject(brush);

                                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                    Rectangle(hdc2, i, j, i + 20, j + 20);
                                    DeleteObject(SelectObject(hdc2, hOldPen));
                                    SelectObject(hdc2, hOldBsh);
                                }
                            }
                        }
                    }
                    else if(choice == "rsh" && (rsh.y0 <= 610 || rsh.y1 <= 610 || rsh.y2 <= 610 || rsh.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);

                        rsh.y0 += 20;
                        rsh.y1 += 20;
                        rsh.y2 += 20;
                        rsh.y3 += 20;

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[rsh.x0][rsh.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<700; j++) {
                                    b[i][j] = 0;
                                }
                            }
                        }

                        if(rsh.y0 > 650 || rsh.y1 > 650 || rsh.y2 > 650 || rsh.y3 > 650) {
                            b[rsh.x0][rsh.y0] = 1;
                            b[rsh.x1][rsh.y1] = 1;
                            b[rsh.x2][rsh.y2] = 1;
                            b[rsh.x3][rsh.y3] = 1;
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                        for(int i=0; i<700; i++) {
                            for(int j=0; j<700; j++) {
                                if(b[i][j] == 1) {
                                    HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                                    RECT rrect6 = {i, j, i + 20, j + 20};
                                    FillRect(hdc2, &rrect6, brush);
                                    DeleteObject(brush);

                                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                    Rectangle(hdc2, i, j, i + 20, j + 20);
                                    DeleteObject(SelectObject(hdc2, hOldPen));
                                    SelectObject(hdc2, hOldBsh);
                                }
                            }
                        }
                    }
                    for(int i=0; i<700; i++) {
                        for(int j=0; j<700; j++) {
                            if(b[i][j] == 1) {
                                HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                                RECT rrect6 = {i, j, i + 20, j + 20};
                                FillRect(hdc2, &rrect6, brush);
                                DeleteObject(brush);

                                HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                Rectangle(hdc2, i, j, i + 20, j + 20);
                                DeleteObject(SelectObject(hdc2, hOldPen));
                                SelectObject(hdc2, hOldBsh);
                            }
                        }
                    }
                }
                break;  
                case 'j':  {
                      //your code here    
                    if(choice == "sq" && (sq.y0 <= 650 || sq.y1 <= 650 || sq.y2 <= 650 || sq.y3 <= 650)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);
                        
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

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                    if(choice == "lne" && (lne.y0 <= 650 || lne.y1 <= 650 || lne.y2 <= 650 || lne.y3 <= 650)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);
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

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                    else if(choice == "ht" && (ht.y0 <= 610 || ht.y1 <= 610 || ht.y2 <= 610 || ht.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);
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

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                    }
                    else if(choice == "larm" && (larm.y0 <= 610 || larm.y1 <= 610 || larm.y2 <= 610 || larm.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);

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
                        
                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[larm.x0][larm.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<700; j++) {
                                    b[i][j] = 0;
                                }
                            }
                        }

                        if(larm.y0 > 650 || larm.y1 > 650 || larm.y2 > 650 || larm.y3 > 650) {
                            b[larm.x0][larm.y0] = 1;
                            b[larm.x1][larm.y1] = 1;
                            b[larm.x2][larm.y2] = 1;
                            b[larm.x3][larm.y3] = 1;
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                        for(int i=0; i<700; i++) {
                            for(int j=0; j<700; j++) {
                                if(b[i][j] == 1) {
                                    HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                                    RECT rrect6 = {i, j, i + 20, j + 20};
                                    FillRect(hdc2, &rrect6, brush);
                                    DeleteObject(brush);

                                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                    Rectangle(hdc2, i, j, i + 20, j + 20);
                                    DeleteObject(SelectObject(hdc2, hOldPen));
                                    SelectObject(hdc2, hOldBsh);
                                }
                            }
                        }
                    }
                    else if(choice == "rarm" && (rarm.y0 <= 610 || rarm.y1 <= 610 || rarm.y2 <= 610 || rarm.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);

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

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[rarm.x0][rarm.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<700; j++) {
                                    b[i][j] = 0;
                                }
                            }
                        }

                        if(rarm.y0 > 650 || rarm.y1 > 650 || rarm.y2 > 650 || rarm.y3 > 650) {
                            b[rarm.x0][rarm.y0] = 1;
                            b[rarm.x1][rarm.y1] = 1;
                            b[rarm.x2][rarm.y2] = 1;
                            b[rarm.x3][rarm.y3] = 1;
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                        for(int i=0; i<700; i++) {
                            for(int j=0; j<700; j++) {
                                if(b[i][j] == 1) {
                                    HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                                    RECT rrect6 = {i, j, i + 20, j + 20};
                                    FillRect(hdc2, &rrect6, brush);
                                    DeleteObject(brush);

                                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                    Rectangle(hdc2, i, j, i + 20, j + 20);
                                    DeleteObject(SelectObject(hdc2, hOldPen));
                                    SelectObject(hdc2, hOldBsh);
                                }
                            }
                        }
                    }
                    else if(choice == "lsh" && (lsh.y0 <= 610 || lsh.y1 <= 610 || lsh.y2 <= 610 || lsh.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);

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
                        
                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[lsh.x0][lsh.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<700; j++) {
                                    b[i][j] = 0;
                                }
                            }
                        }

                        if(lsh.y0 > 650 || lsh.y1 > 650 || lsh.y2 > 650 || lsh.y3 > 650) {
                            b[lsh.x0][lsh.y0] = 1;
                            b[lsh.x1][lsh.y1] = 1;
                            b[lsh.x2][lsh.y2] = 1;
                            b[lsh.x3][lsh.y3] = 1;
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                        for(int i=0; i<700; i++) {
                            for(int j=0; j<700; j++) {
                                if(b[i][j] == 1) {
                                    HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                                    RECT rrect6 = {i, j, i + 20, j + 20};
                                    FillRect(hdc2, &rrect6, brush);
                                    DeleteObject(brush);

                                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                    Rectangle(hdc2, i, j, i + 20, j + 20);
                                    DeleteObject(SelectObject(hdc2, hOldPen));
                                    SelectObject(hdc2, hOldBsh);
                                }
                            }
                        }
                    }
                    else if(choice == "rsh" && (rsh.y0 <= 610 || rsh.y1 <= 610 || rsh.y2 <= 610 || rsh.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);

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

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[rsh.x0][rsh.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<700; j++) {
                                    b[i][j] = 0;
                                }
                            }
                        }

                        if(rsh.y0 > 650 || rsh.y1 > 650 || rsh.y2 > 650 || rsh.y3 > 650) {
                            b[rsh.x0][rsh.y0] = 1;
                            b[rsh.x1][rsh.y1] = 1;
                            b[rsh.x2][rsh.y2] = 1;
                            b[rsh.x3][rsh.y3] = 1;
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                        for(int i=0; i<700; i++) {
                            for(int j=0; j<700; j++) {
                                if(b[i][j] == 1) {
                                    HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                                    RECT rrect6 = {i, j, i + 20, j + 20};
                                    FillRect(hdc2, &rrect6, brush);
                                    DeleteObject(brush);

                                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                    Rectangle(hdc2, i, j, i + 20, j + 20);
                                    DeleteObject(SelectObject(hdc2, hOldPen));
                                    SelectObject(hdc2, hOldBsh);
                                }
                            }
                        }
                    }
                    for(int i=0; i<700; i++) {
                        for(int j=0; j<700; j++) {
                            if(b[i][j] == 1) {
                                HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                                RECT rrect6 = {i, j, i + 20, j + 20};
                                FillRect(hdc2, &rrect6, brush);
                                DeleteObject(brush);

                                HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                Rectangle(hdc2, i, j, i + 20, j + 20);
                                DeleteObject(SelectObject(hdc2, hOldPen));
                                SelectObject(hdc2, hOldBsh);
                            }
                        }
                    }
                }
                break;
                case 'l':  {
                        //your code here    
                    if(choice == "sq" && (sq.y0 <= 650 || sq.y1 <= 650 || sq.y2 <= 650 || sq.y3 <= 650)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);
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

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, sq.x0, sq.y0, sq.x0 + 20, sq.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, sq.x1, sq.y1, sq.x1 + 20, sq.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, sq.x2, sq.y2, sq.x2 + 20, sq.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, sq.x3, sq.y3, sq.x3 + 20, sq.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                    else if(choice == "lne" && (lne.y0 <= 650 || lne.y1 <= 650 || lne.y2 <= 650 || lne.y3 <= 650)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);
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
                        
                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lne.x0, lne.y0, lne.x0 + 20, lne.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lne.x1, lne.y1, lne.x1 + 20, lne.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lne.x2, lne.y2, lne.x2 + 20, lne.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lne.x3, lne.y3, lne.x3 + 20, lne.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);
                    }
                    else if(choice == "ht" && (ht.y0 <= 610 || ht.y1 <= 610 || ht.y2 <= 610 || ht.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);
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

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, ht.x0, ht.y0, ht.x0 + 20, ht.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, ht.x1, ht.y1, ht.x1 + 20, ht.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, ht.x2, ht.y2, ht.x2 + 20, ht.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, ht.x3, ht.y3, ht.x3 + 20, ht.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                    }
                    else if(choice == "larm" && (larm.y0 <= 610 || larm.y1 <= 610 || larm.y2 <= 610 || larm.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);

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

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, larm.x0, larm.y0, larm.x0 + 20, larm.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, larm.x1, larm.y1, larm.x1 + 20, larm.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, larm.x2, larm.y2, larm.x2 + 20, larm.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, larm.x3, larm.y3, larm.x3 + 20, larm.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[larm.x0][larm.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<700; j++) {
                                    b[i][j] = 0;
                                }
                            }
                        }

                        if(larm.y0 > 650 || larm.y1 > 650 || larm.y2 > 650 || larm.y3 > 650) {
                            b[larm.x0][larm.y0] = 1;
                            b[larm.x1][larm.y1] = 1;
                            b[larm.x2][larm.y2] = 1;
                            b[larm.x3][larm.y3] = 1;
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                        for(int i=0; i<700; i++) {
                            for(int j=0; j<700; j++) {
                                if(b[i][j] == 1) {
                                    HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                                    RECT rrect6 = {i, j, i + 20, j + 20};
                                    FillRect(hdc2, &rrect6, brush);
                                    DeleteObject(brush);

                                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                    Rectangle(hdc2, i, j, i + 20, j + 20);
                                    DeleteObject(SelectObject(hdc2, hOldPen));
                                    SelectObject(hdc2, hOldBsh);
                                }
                            }
                        }
                    }
                    else if(choice == "rarm" && (rarm.y0 <= 610 || rarm.y1 <= 610 || rarm.y2 <= 610 || rarm.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);

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
                        
                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rarm.x0, rarm.y0, rarm.x0 + 20, rarm.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rarm.x1, rarm.y1, rarm.x1 + 20, rarm.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rarm.x2, rarm.y2, rarm.x2 + 20, rarm.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rarm.x3, rarm.y3, rarm.x3 + 20, rarm.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[rarm.x0][rarm.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<700; j++) {
                                    b[i][j] = 0;
                                }
                            }
                        }

                        if(rarm.y0 > 650 || rarm.y1 > 650 || rarm.y2 > 650 || rarm.y3 > 650) {
                            b[rarm.x0][rarm.y0] = 1;
                            b[rarm.x1][rarm.y1] = 1;
                            b[rarm.x2][rarm.y2] = 1;
                            b[rarm.x3][rarm.y3] = 1;
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                        for(int i=0; i<700; i++) {
                            for(int j=0; j<700; j++) {
                                if(b[i][j] == 1) {
                                    HBRUSH brush = CreateSolidBrush(RGB(50, 50, 50));
                                    RECT rrect6 = {i, j, i + 20, j + 20};
                                    FillRect(hdc2, &rrect6, brush);
                                    DeleteObject(brush);

                                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                    Rectangle(hdc2, i, j, i + 20, j + 20);
                                    DeleteObject(SelectObject(hdc2, hOldPen));
                                    SelectObject(hdc2, hOldBsh);
                                }
                            }
                        }
                    }
                    else if(choice == "lsh" && (lsh.y0 <= 610 || lsh.y1 <= 610 || lsh.y2 <= 610 || lsh.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);

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

                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lsh.x0, lsh.y0, lsh.x0 + 20, lsh.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lsh.x1, lsh.y1, lsh.x1 + 20, lsh.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lsh.x2, lsh.y2, lsh.x2 + 20, lsh.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, lsh.x3, lsh.y3, lsh.x3 + 20, lsh.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[lsh.x0][lsh.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<700; j++) {
                                    b[i][j] = 0;
                                }
                            }
                        }

                        if(lsh.y0 > 650 || lsh.y1 > 650 || lsh.y2 > 650 || lsh.y3 > 650) {
                            b[lsh.x0][lsh.y0] = 1;
                            b[lsh.x1][lsh.y1] = 1;
                            b[lsh.x2][lsh.y2] = 1;
                            b[lsh.x3][lsh.y3] = 1;
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                        for(int i=0; i<700; i++) {
                            for(int j=0; j<700; j++) {
                                if(b[i][j] == 1) {
                                    HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                                    RECT rrect6 = {i, j, i + 20, j + 20};
                                    FillRect(hdc2, &rrect6, brush);
                                    DeleteObject(brush);

                                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                    Rectangle(hdc2, i, j, i + 20, j + 20);
                                    DeleteObject(SelectObject(hdc2, hOldPen));
                                    SelectObject(hdc2, hOldBsh);
                                }
                            }
                        }
                    }
                    else if(choice == "rsh" && (rsh.y0 <= 610 || rsh.y1 <= 610 || rsh.y2 <= 610 || rsh.y3 <= 610)) {
                        //hdc2 = GetDC(hwnd);
                        hdcMems = CreateCompatibleDC(hdc2);

                        hBitmap = (HBITMAP)LoadImage(hInst, "bgg.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                        oldBitmap = SelectObject(hdcMems, hBitmap);

                        GetObject(hBitmap, sizeof(bitmap), &bitmap);
                        BitBlt(hdc2, 219, 20, 420, 690, hdcMems, 0, 0, SRCCOPY);

                        SelectObject(hdcMems, oldBitmap); DeleteObject(oldBitmap); DeleteObject(hdcMems);
                        DeleteDC(hdcMems); DeleteObject(hBitmap);

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
                        
                        HBRUSH brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect3 = {rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20};
                        FillRect(hdc2, &rrect3, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rsh.x0, rsh.y0, rsh.x0 + 20, rsh.y0 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect4 = {rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20};
                        FillRect(hdc2, &rrect4, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rsh.x1, rsh.y1, rsh.x1 + 20, rsh.y1 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect5 = {rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20};
                        FillRect(hdc2, &rrect5, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rsh.x2, rsh.y2, rsh.x2 + 20, rsh.y2 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        brush = CreateSolidBrush(RGB(255, 165, 0));
                        RECT rrect6 = {rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20};
                        FillRect(hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                        hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                        Rectangle(hdc2, rsh.x3, rsh.y3, rsh.x3 + 20, rsh.y3 + 20);
                        DeleteObject(SelectObject(hdc2, hOldPen));
                        SelectObject(hdc2, hOldBsh);

                        if(b[rsh.x0][rsh.y0] == 1) {
                            for(int i=0; i<600; i++) {
                                for(int j=0; j<700; j++) {
                                    b[i][j] = 0;
                                }
                            }
                        }

                        if(rsh.y0 > 650 || rsh.y1 > 650 || rsh.y2 > 650 || rsh.y3 > 650) {
                            b[rsh.x0][rsh.y0] = 1;
                            b[rsh.x1][rsh.y1] = 1;
                            b[rsh.x2][rsh.y2] = 1;
                            b[rsh.x3][rsh.y3] = 1;
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
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
                            blocks++;char aa[10];sprintf(aa,"TetrisC | Level: %d, Blocks: %d, Points: %d, Lines: %d",level,blocks,points,lines);SetWindowTextA(hwnd,aa);
                            prep();
                        }
                        if(level < 40 && lines == linenext) {level++;linenext+=4;sleeptime-=15;}
                        for(int i=0; i<700; i++) {
                            for(int j=0; j<700; j++) {
                                if(b[i][j] == 1) {
                                    HBRUSH brush = CreateSolidBrush(RGB(50, 50, 50));
                                    RECT rrect6 = {i, j, i + 20, j + 20};
                                    FillRect(hdc2, &rrect6, brush);
                                    DeleteObject(brush);

                                    HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                    HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                    Rectangle(hdc2, i, j, i + 20, j + 20);
                                    DeleteObject(SelectObject(hdc2, hOldPen));
                                    SelectObject(hdc2, hOldBsh);
                                }
                            }
                        }
                    }
                    for(int i=0; i<700; i++) {
                        for(int j=0; j<700; j++) {
                            if(b[i][j] == 1) {
                                HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
                                RECT rrect6 = {i, j, i + 20, j + 20};
                                FillRect(hdc2, &rrect6, brush);
                                DeleteObject(brush);

                                HGDIOBJ hOldBsh = SelectObject(hdc2, GetStockObject(NULL_BRUSH));
                                HGDIOBJ hOldPen = SelectObject(hdc2, CreatePen(PS_SOLID, 2, RGB(200,40,0)));
                                Rectangle(hdc2, i, j, i + 20, j + 20);
                                DeleteObject(SelectObject(hdc2, hOldPen));
                                SelectObject(hdc2, hOldBsh);
                            }
                        }
                    }
                }
                break;  
            }
        }
        case WM_CTLCOLORSTATIC:
        {
            SetBkColor((HDC)wParam,RGB(100,100,255));
            SetTextColor((HDC)wParam, RGB(55,55,55));
            return (BOOL)CreateSolidBrush (GetSysColor(COLOR_MENU));
            break;
        }
        case WM_PAINT:
        {
            if(fist) {
                thread = CreateThread(NULL, 0, downs, NULL, 0, NULL);

                for(int i=0; i<700; i++) {
                    for(int j=0; j<720; j++) {
                        b[i][j] = 0;
                    }
                }
                
                font = CreateFont(30, 0, 0, 0,
                                  FW_NORMAL, FALSE, FALSE, FALSE,
                                  ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                                CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                                DEFAULT_PITCH | FF_ROMAN,
                               "Helvetica");

                SelectObject(hdc2, font);
                SetBkColor((HDC)wParam,RGB(100,100,255));
                TextOut(hdc2, 20, 8, "TetrisC", 7);
                DeleteObject(font);
                
                font = CreateFont(30, 0, 0, 0,
                                  FW_NORMAL, FALSE, FALSE, FALSE,
                                  ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                                CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                                DEFAULT_PITCH | FF_ROMAN,
                               "Helvetica");

                SelectObject(hdc2, font);
                SetBkColor((HDC)wParam,RGB(255,255,255));
                TextOut(hdc2, 500, 8, "Stage: 1", 8);
                DeleteObject(font);
                
                srand(time(NULL));
                prep();
            }

            for(int i=0; i<700; i++) {
                for(int j=0; j<720; j++) {
                    if(b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(0, 250, 0));
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
            char c[33] = "rotate,left,down,right = i,j,k,l";
            int y = 50; int h = 16;
            int x = 10; int w = 179;
            hwnd_title = CreateWindow("static", NULL,
                                       WS_CHILD | WS_VISIBLE | WS_TABSTOP,
                                       x, y, w, h,
                                       hwnd, (HMENU)(501),
                                       (HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE), NULL);
            SetTextColor(hdc2, RGB(255,255,255));
            SetWindowText(hwnd_title, c);

            char d[7] = "NEXT - ";
            y = 150; h = 16;
            x = 10; w = 44;
            hwnd_next = CreateWindow("static", NULL,
                                       WS_CHILD | WS_VISIBLE | WS_TABSTOP,
                                       x, y, w, h,
                                       hwnd, (HMENU)(501),
                                       (HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE), NULL);
            SetTextColor(hdc2, RGB(255,255,255));
            SetWindowText(hwnd_next, d);
        }
        break;
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

void returnStage(int stage) {
    font = CreateFont(30, 0, 0, 0,
                      FW_NORMAL, FALSE, FALSE, FALSE,
                      ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                    CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                    DEFAULT_PITCH | FF_ROMAN,
                   "Helvetica");

    char aa[10];sprintf(aa,"Stage: %d",stage);

    SelectObject(hdc2, font);
    TextOut(hdc2, 500, 8, aa, 8);
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
            0, 0, 630, 750,
            NULL, NULL, hInstance, NULL);

    if(hwnd == NULL) {
        return 0;
    }
    
    int number;
    number = 100;
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