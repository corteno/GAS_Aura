// Copyright Snail's Pace Studio


#include "AbilitySystem/AuraAbilitySystemLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"
#include "UI/WidgetController/AuraWidgetController.h"

UAuraOverlayWidgetController* UAuraAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if(APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0)) {
		if(AAuraHUD* AuraHUD = Cast<AAuraHUD>(PC->GetHUD())) {
			AAuraPlayerState* PS = PC->GetPlayerState<AAuraPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();

			const FWidgetControllerParams& WidgetControllerParams = FWidgetControllerParams(PC, PS, ASC, AS);

			return AuraHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}

	return nullptr;
}

UAttributeMenuWidgetController* UAuraAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	if(APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0)) {
    	if(AAuraHUD* AuraHUD = Cast<AAuraHUD>(PC->GetHUD())) {
    		AAuraPlayerState* PS = PC->GetPlayerState<AAuraPlayerState>();
    		UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
    		UAttributeSet* AS = PS->GetAttributeSet();

    		const FWidgetControllerParams& WidgetControllerParams = FWidgetControllerParams(PC, PS, ASC, AS);

    		return AuraHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
    	}
    }
    
    return nullptr;
}
