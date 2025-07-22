#include "CREWXRFunctionLibrary.h"
#include "Sockets.h"
#include "SocketSubsystem.h"


FString UCREWXRFunctionLibrary::GetLocalAddress() {
    bool bCanBindAll = false;
	TSharedPtr<FInternetAddr> LocalAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, bCanBindAll);
    if (LocalAddr.IsValid())
    {
        return LocalAddr->ToString(false);
    }
    return TEXT("127.0.0.1");
}

FString UCREWXRFunctionLibrary::GetLocalBroadcastAddress() {
    bool bCanBindAll = false;
    TSharedPtr<FInternetAddr> LocalAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, bCanBindAll);
    if (LocalAddr.IsValid())
    {
        FString addr = LocalAddr->ToString(false);
        int32 index;
        addr.FindLastChar(TCHAR('.'), index);
        return addr.Left(index+1) + TEXT("255");
    }
    return TEXT("255.255.255.255");
}

FString UCREWXRFunctionLibrary::GetConnectionString(AActor* context) {
    return FString(TEXT("open ")) + UCREWXRFunctionLibrary::GetLocalAddress() + FString(TEXT(":17777?game=")) + context->GetWorld()->GetMapName().Replace(TEXT("UEDPIE_0_"), TEXT(""));
}