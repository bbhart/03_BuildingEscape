// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty."))
    
	
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Get the PlayerViewG
    FVector PlayerViewLocation;
    FRotator PlayerViewRotation;
    
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint
    (
        OUT PlayerViewLocation,
        OUT PlayerViewRotation
     );
    
    UE_LOG(LogTemp, Warning, TEXT("Player is looking at loc %s with rot %s"),
           *PlayerViewLocation.ToString(),
           *PlayerViewRotation.ToString())
    
    
    // Draw the debug line (if enabled)
    if (DebugLineEnabled)
    {
        FVector DebugLineEnd = PlayerViewLocation + FVector(0.f, 0.f, Reach);
        DrawDebugLine(
                      GetWorld(),
                      PlayerViewLocation,
                      DebugLineEnd,
                      FColor(255,0,0), 
                      false, -1, 0, 
                      12.333
                      );
        
    }
    
    // Ray-cast out to the ReachDistance
    
    // See if we overlapped any objects
    
    
}

