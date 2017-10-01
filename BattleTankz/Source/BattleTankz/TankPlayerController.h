// Copyright P. Gent 2017

#pragma once
#include "CoreMinimal.h"
#include "public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKZ_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	ATank* GetControlledTank() const;

	UPROPERTY(EditAnywhere)
	float CrossHairLocationX = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairLocationY = 0.33333;

private:
	bool GetSightRayLocation(FVector& OutHitLocation) const;
	/// Moves barrel towards crosshairs if bullet is going to hit something.
	void AimTowardsCrosshair();
	FVector2D GetScreenLocationOfCrossHair() const;
};
