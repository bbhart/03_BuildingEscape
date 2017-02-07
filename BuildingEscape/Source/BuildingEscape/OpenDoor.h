

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

    void OpenDoor();
    void CloseDoor();
    float GetTotalMassOfActorsOnPlate();
    
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
    
    bool isDoorOpen = false;
    
    UPROPERTY(EditAnywhere)
    float DoorAngle = 90.0f;
    
    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;

    UPROPERTY(EditAnywhere)
    float DoorOpenDelay = 1.5f;
    
    UPROPERTY(EditAnywhere)
    float TriggerMassInKg = 50.f;
    
    float LastDoorOpenTime;
    AActor* Owner;
    
	
};
