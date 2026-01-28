// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IVCharacterHUDInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIVCharacterHUDInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INTERVERSE_API IIVCharacterHUDInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void SetupHUDWidget(class UIVHUDWidget* InHUDWidget) = 0;
};
