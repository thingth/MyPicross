#pragma once

#include <iostream>
#include <string>
#include "FPicross.h"

void PrintIntro();
void Play();
int32 GetDifficulty();
FString GetValidDraw();
void PrintResult();
bool PlayAgain();
void Pause();
void Clear();

FPicross PicGame; //Class and instance; instantiate a new game

int main()
{
	do
	{
		PrintIntro();
		Play();
	} while (PlayAgain() == 1);

	return 0;
}

void PrintIntro()
{
	std::cout << std::endl << "  Welcome to my picross game!\n";
}

void Play()
{
	int32 Pic_Size = GetDifficulty();

	if (Pic_Size == 5)
	{
		std::cout << std::endl;
		std::cout << "            [A][B][C][D][E]\n";
		std::cout << "                   3\n";
		std::cout << "             2  4  1  3  2\n";
		std::cout << "            ---------------\n";
		std::cout << "  [1]    3 |  |  |  |  |  |\n";
		std::cout << "           ----------------\n";
		std::cout << "  [2]    5 |  |  |  |  |  |\n";
		std::cout << "           ----------------\n";
		std::cout << "  [3]    5 |  |  |  |  |  |\n";
		std::cout << "           ----------------\n";
		std::cout << "  [4]    1 |  |  |  |  |  |\n";
		std::cout << "           ----------------\n";
		std::cout << "  [5]    1 |  |  |  |  |  |\n";
		std::cout << "           ----------------\n";
	}
	else if (Pic_Size == 10)
	{
		std::cout << "";
	}

	GetValidDraw();
}

int32 GetDifficulty()
{
	int32 Size = 0;

	std::cout << std::endl << "  Please choose size of the picture (5 or 10): ";
	do
	{
		std::cin >> Size;

		if (Size != 5 && Size != 10)
		{
			std::cout << "Please choose 5 or 10: ";
		}
	} while (Size != 5 && Size != 10);

	return Size;
}

FString GetValidDraw()
{
	char b[10][10] = {
		{ '\0','\0', '\0', '\0', '\0' },
	{ '\0','\0', '\0', '\0', '\0' },
	{ '\0','\0', '\0', '\0', '\0' },
	{ '\0','\0', '\0', '\0', '\0' },
	{ '\0','\0', '\0', '\0', '\0' }
	};

	bool DrawFinish = 0;
	FString DrawPos = "";
	int32 match = 0;
	int32 lives = 3;

	std::cin.clear();
	std::cin.ignore();

	do
	{
		std::cout << "\n  Life x " << lives << std::endl;
		std::cout << "  Enter position you want to draw: ";
		std::getline(std::cin, DrawPos);

		if (DrawPos[0] == 'A')
		{
			if (DrawPos[1] == '1')
			{
				b[0][0] = 'X';
				lives--;
			}
			else if (DrawPos[1] == '2')
			{
				b[1][0] = 178;
				match++;
			}
			else if (DrawPos[1] == '3')
			{
				b[2][0] = 178;
				match++;
			}
			else if (DrawPos[1] == '4')
			{
				b[3][0] = 'X';
				lives--;
			}
			else if (DrawPos[1] == '5')
			{
				b[4][0] = 'X';
				lives--;
			}
			else
			{
				std::cout << "\n\nPlease enter valid position.\n\n";
			}
		}
		else if (DrawPos[0] == 'B')
		{
			if (DrawPos[1] == '1')
			{
				b[0][1] = 178;
				match++;
			}
			else if (DrawPos[1] == '2')
			{
				b[1][1] = 178;
				match++;
			}
			else if (DrawPos[1] == '3')
			{
				b[2][1] = 178;
				match++;
			}
			else if (DrawPos[1] == '4')
			{
				b[3][1] = 176;
				match++;
			}
			else if (DrawPos[1] == '5')
			{
				b[4][1] = 'X';
				lives--;
			}
			else
			{
				std::cout << "\n\nPlease enter valid position.\n\n";
			}
		}
		else if (DrawPos[0] == 'C')
		{
			if (DrawPos[1] == '1')
			{
				b[0][2] = 178;
				match++;
			}
			else if (DrawPos[1] == '2')
			{
				b[1][2] = 178;
				match++;
			}
			else if (DrawPos[1] == '3')
			{
				b[2][2] = 178;
				match++;
			}
			else if (DrawPos[1] == '4')
			{
				b[3][2] = 'X';
				lives--;
			}
			else if (DrawPos[1] == '5')
			{
				b[4][2] = 176;
				match++;
			}
			else
			{
				std::cout << "\n\nPlease enter valid position.\n\n";
			}
		}
		else if (DrawPos[0] == 'D')
		{
			if (DrawPos[1] == '1')
			{
				b[0][3] = 178;
				match++;
			}
			else if (DrawPos[1] == '2')
			{
				b[1][3] = 178;
				match++;
			}
			else if (DrawPos[1] == '3')
			{
				b[2][3] = 178;
				match++;
			}
			else if (DrawPos[1] == '4')
			{
				b[3][3] = 'X';
				lives--;
			}
			else if (DrawPos[1] == '5')
			{
				b[4][3] = 'X';
				lives--;
			}
			else
			{
				std::cout << "\n\nPlease enter valid position.\n\n";
			}
		}
		else if (DrawPos[0] == 'E')
		{
			if (DrawPos[1] == '1')
			{
				b[0][4] = 'X';
				lives--;
			}
			else if (DrawPos[1] == '2')
			{
				b[1][4] = 178;
				match++;
			}
			else if (DrawPos[1] == '3')
			{
				b[2][4] = 178;
				match++;
			}
			else if (DrawPos[1] == '4')
			{
				b[3][4] = 'X';
				lives--;
			}
			else if (DrawPos[1] == '5')
			{
				b[4][4] = 'X';
				lives--;
			}
			else
			{
				std::cout << "\n\nPlease enter valid position.\n\n";
			}
		}
		else
		{
			std::cout << "\n\nPlease enter valid position.\n\n";
		}

		std::cout << std::endl;
		std::cout << "\n\n            [A][B][C][D][E]\n\n";
		std::cout << "                   3\n";
		std::cout << "             2  4  1  3  2\n";
		std::cout << "            ---------------\n";
		std::cout << "  [1]    3 |" << b[0][0] << b[0][0] << "|" << b[0][1] << b[0][1] << "|" << b[0][2] << b[0][2] << "|" << b[0][3] << b[0][3] << "|" << b[0][4] << b[0][4] << "|\n";
		std::cout << "           ----------------\n";
		std::cout << "  [2]    5 |" << b[1][0] << b[1][0] << "|" << b[1][1] << b[1][1] << "|" << b[1][2] << b[1][2] << "|" << b[1][3] << b[1][3] << "|" << b[1][4] << b[1][4] << "|\n";
		std::cout << "           ----------------\n";
		std::cout << "  [3]    5 |" << b[2][0] << b[2][0] << "|" << b[2][1] << b[2][1] << "|" << b[2][2] << b[2][2] << "|" << b[2][3] << b[2][3] << "|" << b[2][4] << b[2][4] << "|\n";
		std::cout << "           ----------------\n";
		std::cout << "  [4]    1 |" << b[3][0] << b[3][0] << "|" << b[3][1] << b[3][1] << "|" << b[3][2] << b[3][2] << "|" << b[3][3] << b[3][3] << "|" << b[3][4] << b[3][4] << "|\n";
		std::cout << "           ----------------\n";
		std::cout << "  [5]    1 |" << b[4][0] << b[4][0] << "|" << b[4][1] << b[4][1] << "|" << b[4][2] << b[4][2] << "|" << b[4][3] << b[4][3] << "|" << b[4][4] << b[4][4] << "|\n";
		std::cout << "           ----------------\n\n\n\n\n";

		if (match == 15)
		{
			DrawFinish = 1;
		}

	} while (DrawFinish == 0 && lives > 0);

	if (DrawFinish = 1 && lives > 0)
	{
		std::cout << "  CONGRATULATION!\n";
		std::cout << "  You finished the picture.\n\n\n\n";

		for (int i = 0; i < 5; i++) //TODO change 5 to get difficulty method
		{
			for (int j = 0; j < 5; j++) //TODO change 5 to get difficulty method
			{
				if (b[i][j] == 'X')
				{
					b[i][j] = '\0';
				}
				std::cout << b[i][j] << b[i][j];
			}
			std::cout << "\n";
		}

		std::cout << "\n\n\n  It's a cloud with lightening!\n\n\n\n\n";
	}
	else if (lives <= 0)
	{
		std::cout << "  YOU LOSE!\n\n\n";
	}

	return DrawPos;
}

void PrintResult()
{
	bool GameResult = 0;

	if (GameResult = 1)
	{
		std::cout << "  YOU FINISHED THE PICTURE! CONGRATULATION.\n\n";
	}
	else
	{
		std::cout << "  YOU LOSE!\n\n";
	}
}

bool PlayAgain()
{
	std::cin.ignore();
	std::cout << "\n  Play again? (Y/N)";
	FString Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void Pause()
{
	std::cin.clear();
	std::cout << std::endl << "\  nPress any key to continue...";
	std::cin.ignore();
}

void Clear()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\n";
	}
}