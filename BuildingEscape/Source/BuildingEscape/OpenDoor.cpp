

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
    
    Owner = GetOwner();
    ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
    
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Check every frame to see if our allowed actor as collided with the Pressure Place
    
    // Door is open, pressure plate not overlapped: close door after DoorOpenDelay
    if (isDoorOpen)
    {
        // If pressure plate not overlapped, close door after DoorOpenDelay
        if (!PressurePlate->IsOverlappingActor(ActorThatOpens))
        {
            if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorOpenDelay)
            {
                CloseDoor();
            }
        }
    }
    
    // Door is closed, pressure plate overlapped: open door
    if (!isDoorOpen && (PressurePlate->IsOverlappingActor(ActorThatOpens)))
    {
        OpenDoor();
    }
}


void UOpenDoor::OpenDoor()
{
    
    Owner->SetActorRotation(FRotator(0.0f, DoorAngle, 0.0f));
    LastDoorOpenTime = GetWorld()->GetTimeSeconds();
    isDoorOpen = true;

}

void UOpenDoor::CloseDoor()
{
    Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
    isDoorOpen = false;
}
