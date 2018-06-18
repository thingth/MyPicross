#pragma once
#include "FPicross.h"
#include <map>
#define TMap std::map

FPicross::FPicross() { /*Reset();*/ }

void FPicross::Reset(int32& PicSize)
{
	GameResult = false;
	FString Hidden_Picture = SetHiddenPictureFromSize(PicSize);
	HiddenPicName = Hidden_Picture;
}

bool FPicross::IsGameWon() const { return GameResult; }

int32 FPicross::GetMaxLife() const
{
	TMap<int32, int32> PictureSizeToMaxLives{ {5,3},{10,5},{15,5},{20,7},{30,9} };
	return PictureSizeToMaxLives[HiddenPicName.length()]; //TODO Change in [] to be puzzle size
}

int32 FPicross::GetHiddenPictureNameFromSize() const
{
	return 0;
}

FString FPicross::SetHiddenPictureFromSize(int32 &Pic_Size) const
{
	TMap<int32, FString> PictureSizeToName{ { 5,"Cloud" } };
	return PictureSizeToName[Pic_Size];
}

EDrawCheck FPicross::DrawValidity(FString) const
{
	return EDrawCheck();
}

bool FPicross::IsDrawn(FString) const
{
	return false;
}
