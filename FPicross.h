/*Game logic w/o direct user interaction*/
#pragma once
#include <string>

//Unreal friendly syntax
using FString = std::string;
using int32 = int;

enum class EDrawCheck
{
	Invalid_Status,
	Ok,
	Already_Drawn
};

class FPicross
{
public:
	FPicross(); //Constructor**

	void Reset(int32&);
	bool IsGameWon() const;

	int32 GetMaxLife() const;
	int32 GetHiddenPictureNameFromSize() const;
	FString SetHiddenPictureFromSize(int32&) const;
	EDrawCheck DrawValidity(FString) const;

private:
	FString HiddenPicName;
	int32 HiddenPicture;
	bool GameResult;
	bool IsDrawn(FString) const;
};