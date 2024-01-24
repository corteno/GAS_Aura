// Copyright Snail's Pace Studio


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound)
{
	for (FAuraInputAction AbilityInputAction : AbilityInputActions) {
		if(AbilityInputAction.InputAction && AbilityInputAction.InputTag.MatchesTagExact(InputTag)) {
			return AbilityInputAction.InputAction;
		}
	}

	if(bLogNotFound) {
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Yellow,
		        FString::Printf(TEXT("Can't find AbilityInputAction for InputTag [%s]"), *InputTag.ToString())
		);
	}

	return nullptr;
}
