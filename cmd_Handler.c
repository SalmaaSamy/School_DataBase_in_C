#include "./cmd_Handler.h"

void cmdSetConsoleColour(u8 au8Color)
{
	HANDLE  hConsoleHandler;
	hConsoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleHandler, au8Color);
}

void cmdResetConsoleColour(void)
{
	HANDLE  hConsoleHandler;
	hConsoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleHandler, TEXT_DWhite);
}

void cmdGoToXY(u8 au8Xposition, u8 au8Yposition)
{
	HANDLE hConsoleHandler;
	COORD cConsoleCoordinatorHandler;

	hConsoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	cConsoleCoordinatorHandler.X = au8Xposition;
	cConsoleCoordinatorHandler.Y = au8Yposition;

	SetConsoleCursorPosition(hConsoleHandler, cConsoleCoordinatorHandler);
}

void cmdSetScreenDim(u16 au16Width, u16 au16Height)
{
    // Create a new console window
    HWND consoleWindow = GetConsoleWindow();
    if (consoleWindow != NULL) {
        // Set the window size and lock it from resizing
        RECT rect;
        GetWindowRect(consoleWindow, &rect);
        MoveWindow(consoleWindow, rect.left, rect.top, au16Width * 8, au16Height * 18, TRUE);
        SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_SIZEBOX);
    }
}

void cmdClearScreen(void)
{
    //system("@cls||clear");
	system("cls"); //from windows APIs
}

void cmdShowConsoleCursor(u8 au8ShowFlag)
{
   HANDLE  hConsoleHandler;
   CONSOLE_CURSOR_INFO CS_info;

   hConsoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
   GetConsoleCursorInfo(hConsoleHandler, &CS_info);
   CS_info.bVisible = au8ShowFlag;
   SetConsoleCursorInfo(hConsoleHandler, &CS_info);
}

void cmdDelay(u32 DelayValue)
{
	volatile u32 u32Local_Count1 = 0;
	volatile u32 u32Local_Count2 = 0;
	for (u32Local_Count1 = 0; u32Local_Count1 < DelayValue; u32Local_Count1++)
	{
		for (u32Local_Count2 = 0; u32Local_Count2 < 310000; u32Local_Count2++)
		{/* Do nothing for 1 ms*/}
	}
}
