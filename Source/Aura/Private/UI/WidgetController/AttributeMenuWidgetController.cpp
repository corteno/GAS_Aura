// Copyright Snail's Pace Studio


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);
	
	for (auto& Info : AttributeInfo.Get()->AttributeInformation) {
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Info.AttributeGetter).AddLambda(
	[this, Info](const FOnAttributeChangeData& Data) {
				FAuraAttributeInfo NewInfo = AttributeInfo->FindAttributeInfoForTag(Info.AttributeTag);
				NewInfo.AttributeValue = Data.NewValue;
				AttributeInfoDelegate.Broadcast(NewInfo);
			}
		);
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& Tag) const
{
	// Getting info from DataAsset based on gameplay tag match
	FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Tag);
	// Set hidden attribute value in dataset
	Info.AttributeValue = Info.AttributeGetter.GetNumericValue(AttributeSet);
	// Broadcast for those who subscribe, eg.: widgets
	AttributeInfoDelegate.Broadcast(Info);
	
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);

	check(AttributeInfo);

	for (auto& Tag : AttributeInfo.Get()->AttributeInformation) {
		BroadcastAttributeInfo(Tag.AttributeTag);
	}

	/*FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(FAuraGameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue = AS->GetStrength();

	AttributeInfoDelegate.Broadcast(Info);*/
}
