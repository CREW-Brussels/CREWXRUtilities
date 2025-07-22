#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNodeUtils.h"
#include "AnimGraphNode_Base.h"
#include "AnimNode_HandTracking.h"
#include "AnimGraphNode_HandTracking.generated.h"

UCLASS()
class CREWXREDITOR_API UAnimGraphNode_HandTracking : public UAnimGraphNode_Base
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, Category = "Settings")
    FAnimNode_HandTracking Node;

    virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override
    {
        return FText::FromString(TEXT("Hand Tracking Node"));
    }

    virtual FText GetTooltipText() const override
    {
        return FText::FromString(TEXT("Applies hand tracking rotations to bones."));
    }

    virtual FString GetNodeCategory() const override
    {
        return TEXT("Hand Tracking");
    }

    // Ensure array inputs appear as pins
    virtual void CustomizePinData(UEdGraphPin* Pin, FName SourcePropertyName, int32 ArrayIndex) const override
    {
        if (SourcePropertyName == GET_MEMBER_NAME_CHECKED(FAnimNode_HandTracking, HandTrackingRotations))
        {
            Pin->bHidden = false;  // Show array input in Blueprint
        }
        if (SourcePropertyName == GET_MEMBER_NAME_CHECKED(FAnimNode_HandTracking, Alpha))
        {
            Pin->bHidden = false;  // Show array input in Blueprint
        }
    }
};