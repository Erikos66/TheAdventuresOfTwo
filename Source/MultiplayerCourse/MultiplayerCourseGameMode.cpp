// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiplayerCourseGameMode.h"
#include "MultiplayerCourseCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiplayerCourseGameMode::AMultiplayerCourseGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AMultiplayerCourseGameMode::HostLanGame() const
{
	GetWorld()->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap.ThirdPersonMap?listen");
}

void AMultiplayerCourseGameMode::JoinLanGame() const
{
	if (APlayerController *PC = GetGameInstance()->GetFirstLocalPlayerController())
	{
		PC->ClientTravel("192.168.0.120", TRAVEL_Absolute);
	}
}
