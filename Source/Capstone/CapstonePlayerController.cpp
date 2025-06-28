// Copyright Epic Games, Inc. All Rights Reserved.


#include "CapstonePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "CapstoneCameraManager.h"

ACapstonePlayerController::ACapstonePlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ACapstoneCameraManager::StaticClass();
}

void ACapstonePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
