#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "CREWXRFunctionLibrary.generated.h"

UCLASS(ClassGroup = CREW_XR)
class CREWXR_API UCREWXRFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Local Address"), Category = "CREW_XR")
    static FString GetLocalAddress();

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Local Broadcast Address"), Category = "CREW_XR")
    static FString GetLocalBroadcastAddress();

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Connection String"), Category = "CREW_XR")
    static FString GetConnectionString(AActor *context);


};