// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Weapon.generated.h"

class USoundBase;
class UBoxComponent;

UENUM(BlueprintType)
enum class EWeaponHanded : uint8
{
	EWH_OneHanded,
	EWH_TwoHanded
};

/**
 * 
 */
UCLASS()
class MYPROJECT3_API AWeapon : public AItem
{
	GENERATED_BODY()
public:
	AWeapon();
	void Equip(USceneComponent* InParent, FName InSocketName, AActor* NewOwner, APawn* NewInstigator);

	void DeactivateEmbers();

	void DisableSphereCollision();

	void PlayEquipSound(AActor* NewOwner);

	void AttachMeshToSocket(USceneComponent* InParent, const FName& InSocketName);

	TArray<AActor*> IgnoreActors;

	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	EWeaponHanded Handedness;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	bool ActorIsSameType(AActor* OtherActor);

	void ExecuteGetHit(FHitResult& BoxHit);

	UFUNCTION(BlueprintImplementableEvent)
	void CreateFields(const FVector& FieldLocation);


private:
	void BoxTrace(FHitResult& BoxHit); // non const reference bc we want to fill in and use later

	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	FVector BoxTraceExtent = FVector(5.f);

	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	bool showBoxDebug = false;

	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	USoundBase* EquipSound;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	UBoxComponent* WeaponBox;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	USceneComponent* BoxTraceStart;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	USceneComponent* BoxTraceEnd;

	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	float Damage = 20.f;

	

public:
	FORCEINLINE UBoxComponent* GetWeaponBox() const { return WeaponBox; }
};
