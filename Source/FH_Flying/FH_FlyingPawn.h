// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "FH_FlyingPawn.generated.h"

UCLASS(config=Game)
class AFH_FlyingPawn : public APawn
{
public:
	GENERATED_UCLASS_BODY()

	/** StaticMesh component that will be the visuals for our flying pawn */
	UPROPERTY(Category=Mesh, VisibleDefaultsOnly, BlueprintReadOnly)
	TSubobjectPtr<class UStaticMeshComponent> PlaneMesh;

	/** Spring arm that will offset the camera */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly)
	TSubobjectPtr<class USpringArmComponent> SpringArm;

	/** Camera component that will be our viewpoint */
	UPROPERTY(Category=Camera, VisibleDefaultsOnly, BlueprintReadOnly)
	TSubobjectPtr<class UCameraComponent> Camera;

	// Begin AActor overrides
	virtual void Tick(float DeltaSeconds) OVERRIDE;
	virtual void ReceiveHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) OVERRIDE;
	// End AActor overrides

protected:

	// Begin APawn overrides
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) OVERRIDE; // Allows binding actions/axes to functions
	// End APawn overrides

	/** Bound to the vertical axis */
	void ThrustInput(float Val);
	
	/** Bound to the horizontal axis */
	void MoveUpInput(float Val);

	/** */
	void MoveRightInput(float Val);

private:

	/** How quickly forward speed changes */
	UPROPERTY(Category=Plane, EditAnywhere)
	float Acceleration;

	/** How quickly pawn can steer */
	UPROPERTY(Category=Plane, EditAnywhere)
	float TurnSpeed;

	/** MAx forward speed */
	UPROPERTY(Category = Pitch, EditAnywhere)
	float MaxSpeed;

	/** Min forward speed */
	UPROPERTY(Category=Yaw, EditAnywhere)
	float MinSpeed;

	/** Current forward speed */
	float CurrentForwardSpeed;

	/** Current yaw speed */
	float CurrentYawSpeed;

	/** Current pitch speed */
	float CurrentPitchSpeed;

	/** Current roll speed */
	float CurrentRollSpeed;
};