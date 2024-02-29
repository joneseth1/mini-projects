#include <windows.h>
#include <algorithm>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Register the window class
    const char CLASS_NAME[] = "BlackSquareWindowClass";

    WNDCLASS wc = {};


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            
            RECT rect;
            GetClientRect(hwnd, &rect);
            int width = rect.right - rect.left;
            int height = rect.bottom - rect.top;
            int squareSize = std::min(width, height) / 2; 
            int x = (width - squareSize) / 2;
            int y = (height - squareSize) / 2;

            RECT squareRect = { x, y, x + squareSize, y + squareSize };
            FillRect(hdc, &squareRect, (HBRUSH)GetStockObject(BLACK_BRUSH));

        }
        return 0;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}
}
