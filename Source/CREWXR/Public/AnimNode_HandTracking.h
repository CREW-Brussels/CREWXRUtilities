#pragma once

#include "CoreMinimal.h"
#include "BoneContainer.h"
#include "Animation/AnimInstanceProxy.h"
#include "Animation/AnimNodeBase.h"
#include "AnimNode_HandTracking.generated.h"

USTRUCT(BlueprintType)
struct CREWXR_API FAnimNode_HandTracking : public FAnimNode_Base
{
    GENERATED_BODY()

public:

    // Input pose
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Links")
    FPoseLink BasePose;

    // List of bones to apply hand tracking data to (using FName for Blueprints compatibility)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hand Tracking")
    TArray<FName> TargetBoneNames;

    // Hand tracking rotations in world space
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hand Tracking", meta = (PinShownByDefault))
    TArray<FRotator> HandTrackingRotations;

    // Alpha blend value (0 = no effect, 1 = full effect)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hand Tracking", meta = (PinShownByDefault, ClampMin = "0.0", ClampMax = "1.0"))
    float Alpha = 1.0f;

    // Initialize Bone References
    

protected:
    virtual void Evaluate_AnyThread(FPoseContext& Output) override;

private:
    void InitializeBoneReferences(const FBoneContainer& RequiredBones);
    // Internal array of bone references (resolved from TargetBoneNames)
    TArray<FBoneReference> TargetBones;
};