#include "AnimNode_HandTracking.h"
#include "AnimationRuntime.h"
#include "Animation/AnimInstanceProxy.h"

void FAnimNode_HandTracking::InitializeBoneReferences(const FBoneContainer& RequiredBones)
{
    // Convert FName to FBoneReference for each bone in the TargetBoneNames array
    TargetBones.Empty();
    for (const FName& BoneName : TargetBoneNames)
    {
        FBoneReference BoneRef;
        BoneRef.BoneName = BoneName;
        BoneRef.Initialize(RequiredBones);
        TargetBones.Add(BoneRef);
    }
}

void FAnimNode_HandTracking::Evaluate_AnyThread(FPoseContext& Output)
{
    // Evaluate the base pose first
    BasePose.Evaluate(Output);

    if (TargetBones.Num() != HandTrackingRotations.Num() || Alpha <= 0.0f)
    {
        // If input data is invalid or Alpha is 0, return without modification
        return;
    }

    const FBoneContainer& BoneContainer = Output.Pose.GetBoneContainer();

    for (int32 i = 0; i < TargetBones.Num(); i++)
    {
        if (!TargetBones[i].IsValidToEvaluate(BoneContainer))
        {
            continue;
        }

        // Get bone index
        FCompactPoseBoneIndex BoneIndex = TargetBones[i].GetCompactPoseIndex(BoneContainer);

        // Get current local transform
        FTransform BoneTransform = Output.Pose[BoneIndex];

        // Convert world space rotation to component space rotation
        FQuat WorldRotationQuat = HandTrackingRotations[i].Quaternion();
        FQuat ComponentSpaceQuat = BoneContainer.GetRefPoseTransform(BoneIndex).GetRotation().Inverse() * WorldRotationQuat;

        // Blend the rotation
        FQuat BlendedQuat = FQuat::Slerp(BoneTransform.GetRotation(), ComponentSpaceQuat, Alpha);
        BoneTransform.SetRotation(BlendedQuat);

        // Apply the new transform
        Output.Pose[BoneIndex] = BoneTransform;
    }
}
