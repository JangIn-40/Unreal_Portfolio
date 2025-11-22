// JIH

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MWWidgetBase.generated.h"

class UHeroUIComponent;
class UEnemyUIComponent;

/**
 * 
 */
UCLASS()
class MW_API UMWWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owning Hero UI Component Initialized"))
	void BP_OnOwningHeroUIComponentInitialized(UHeroUIComponent* OwningHeroUIComponent);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owning Enemy UI Component Initialized"))
	void BP_OnOwningEnemyUIComponentInitialized(UEnemyUIComponent* OwningEnemyUIComponent);

public:
	UFUNCTION(BlueprintCallable)
	void InitEnemyCreateWidget(AActor* OwningEnemyActor);

};
