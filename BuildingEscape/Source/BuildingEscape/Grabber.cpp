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
    FindPhysicsHandleComponent();
    SetupInputComponent();
	
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

    
    // If the player is trying to grab, then check if they've hit something grabbable
    
    
}

void UGrabber::Grab(){
    UE_LOG(LogTemp, Warning, TEXT("Trying to grab"))
    
}

void UGrabber::Release() {
	UE_LOG(LogTemp, Warning, TEXT("Releasing"))
}

void UGrabber::FindPhysicsHandleComponent()
{
    PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
    
    if (PhysicsHandle)
    {
        // Fine
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Cannot find UPhysicsHandleComponent attached to %s"), *GetOwner()->GetName())
    }
}

void UGrabber::SetupInputComponent()
{
    
    InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
    if (InputComponent)
    {
        UE_LOG(LogTemp, Warning, TEXT("Found UInputComponent."))
        UE_LOG(LogTemp, Warning, TEXT("Binding Grab action"))
        InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
        InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Cannot find UInputComponent"))
    }
    
}

const UGrabber::GetFirstPhysicsBodyInReach()
{
    
    // Get the PlayerViewG
    FVector PlayerViewLocation;
    FRotator PlayerViewRotation;
    
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint
    (
     OUT PlayerViewLocation,
     OUT PlayerViewRotation
     );
    
    
    FVector LineTraceEnd = PlayerViewLocation + PlayerViewRotation.Vector() * Reach;
    
    
    // Ray-cast out to the ReachDistance
    FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
    
    FHitResult Hit;
    GetWorld()->LineTraceSingleByObjectType(
                                            OUT Hit,
                                            PlayerViewLocation,
                                            LineTraceEnd,
                                            FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
                                            TraceParameters
                                            );
    
    
    AActor* ActorHit = Hit.GetActor();
    if (ActorHit)
    {
        UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *(ActorHit->GetName()))
    }
    

    
}
