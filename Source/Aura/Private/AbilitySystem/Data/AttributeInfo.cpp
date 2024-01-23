// Copyright Snail's Pace Studio


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributeInformation) {
		if(Info.AttributeTag == AttributeTag) {
			return Info;
		}
	}

	if(bLogNotFound) {
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Red,
		FString::Printf(TEXT("Can't find Info for AttributeTag [%s] on AttributeInfo [%s]"), *AttributeTag.ToString(), *GetNameSafe(this))
		);
	}

	return FAuraAttributeInfo();
}
