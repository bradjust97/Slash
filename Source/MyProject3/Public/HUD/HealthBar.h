// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT3_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()

public:
	// Note that this variable name MUST be same as variable in hierarchy panel in blueprint. This is from meta bind widget (lec 164)
	UPROPERTY(meta = (Bindwidget))
	class UProgressBar* HealthBar;
	
};
