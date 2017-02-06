// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
    UPROPERTY(EditAnywhere)
    float Reach = 90.0f;


    UPhysicsHandleComponent* PhysicsHandle = nullptr;
    UInputComponent* InputComponent = nullptr;

    
    // Find (assumed) attached physics handle
    void FindPhysicsHandleComponent();

    // Setup (assumed) attached input component
    void SetupInputComponent();
    
    // Attach a nearby PhysicsBody to the player
    void Grab();
    
    // Release the PhysicsBody attached to the player
	void Release();
    
    // Get first PhysicsBody within reach
    const FHitResult GetFirstPhysicsBodyInReach();
    
	// Return FVector for where to end our player's reach
	FVector GetReachLineEnd();
    
    // Return FVector for start of reach line
    FVector GetReachLineStart();
	
};
