## 1. 프로젝트 소개
- GAS를 활용한 언리얼 엔진 포트폴리오
- 개발 목적 : GAS라는 표준화된 구조를 사용해보고 싶었습니다.
- 제작 기간 : 2025.10.23 ~ 2025.12.01
- 개발 인원 : 1인
- Paragon 에셋을 활용해서 Wukong 영웅으로 몰려오는 적들을 처치하는 액션게임을 만들었습니다.

## 2. 플레이 동영상 및 빌드 파일
> 이미지를 클릭하시면 youtube로 연결됩니다.

[![이미지](https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/HighLights_1.gif)](https://youtu.be/Kq3Ns3fv_qc)

> 플레이 빌드 파일

https://naver.me/xhl6zU7q

## 3. Gameplay Ability System
- Gameplay Ability
  <table>
	<tr>
	  <th colspan = "4">영웅 기능 구현 항목</th>
	</tr>
	<tr>
	  <th> Hero_ForcePush </th>
	  <th> Hero_DoubleJump </th>
	  <th> Hero_Slam </th>
	  <th> Hero_Ult </th>
	</tr>
	<tr>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/Wukong_ForcePush_1.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/Wukong_DoubleJump.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/Wukong_Slam.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/Wukong_Ult_1.gif" width = "200" heigh = "150"></td>
	</tr>
	<tr>
	  <th> Hero_Melee </th>
	  <th> Hero_Death </th>
	  <th> Hero_HitReact </th>
	  <th> Hero_Stun </th>
	</tr>
	<tr>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/Wukong_Melee.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/Wukong_Death_1.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/Wukong_HitReact.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/Red_UpperCut_1.gif" width = "200" heigh = "150"></td>
	</tr>
  </table>
	<details>
		<summary> GA_Hero_Light_Attack Blueprint (Click!)</summary>
		<img width="1063" height="415" alt="스크린샷 2025-12-04 154940" src="https://github.com/user-attachments/assets/d7da878b-883a-4c5a-9933-68958bb2e588" />
		<img width="1088" height="628" alt="스크린샷 2025-12-04 154957" src="https://github.com/user-attachments/assets/b31dc59a-9d63-44aa-aaf8-aad925c09503" />
		<img width="1095" height="431" alt="스크린샷 2025-12-04 155009" src="https://github.com/user-attachments/assets/ee5f32b7-e0ac-4bbc-83a9-e4bf4397c049" />
		<img width="1051" height="393" alt="스크린샷 2025-12-04 155017" src="https://github.com/user-attachments/assets/efdec381-dbd2-4e4c-b5c4-3662e0c24f2e" />
		<img width="1048" height="415" alt="스크린샷 2025-12-04 155030" src="https://github.com/user-attachments/assets/12e581b3-7fc7-4e48-8007-c876e2211aaa" />
		Light_Attack Montage
		<img width="1920" height="1040" alt="스크린샷 2025-12-04 154624" src="https://github.com/user-attachments/assets/323b7d0a-8f9a-4ea8-8406-883ecd2156c4" />
		AttackRecovery Montage
		<img width="1920" height="1040" alt="스크린샷 2025-12-04 154644" src="https://github.com/user-attachments/assets/74bc8725-17e7-495b-b1e5-bcad3622d3cb" />
	</details>&nbsp;
	  
  <table>
	<tr>
	  <th colspan = "4"> 적 기능 구현 항목 </th>
	</tr>
	<tr>
	  <th> Green_SpawnDamageZone </th>
	  <th> Black_Range </th>
	  <th> Red_BigSmash </th>
	  <th> Red_UpperCut </th>
	</tr>
	<tr>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/Green_SpawnDamageZone_1.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/Black_Range_1.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/Red_BigSmash_1.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/Red_UpperCut_1.gif" width = "200" heigh = "150"></td>
	</tr>
	<tr>
	  <th> Enemy_Melee </th>
	  <th> Enemy_Death </th>
	  <th> Enemy_Stun </th>
	</tr>
	<tr>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/White_Melee_1.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/Enemy_Death_1.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/AllEnemy_Stun_1.gif" width = "200" heigh = "150"></td>
	</tr>
  </table>
	<details>
		<summary> Shared_Stun_Base Blueprint (Click!)</summary>
		<img width="1090" height="354" alt="스크린샷 2025-12-04 160324" src="https://github.com/user-attachments/assets/ad7481d2-52fe-4fe4-ab59-2dc14cdcf148" />
		<img width="1086" height="579" alt="스크린샷 2025-12-04 160716" src="https://github.com/user-attachments/assets/5684464f-e467-4336-8e1f-f5990f3910fb" />
	</details>&nbsp;

- GameplayEffect
  <table>
	<tr>
	  <th colspan = "4"> 기능 구현 항목 </th>
	</tr>
	<tr>
	  <th> BaseDamage </th>
	  <th> FireDamage </th>
	  <th> PoisonDamage </th>
	</tr>
	<tr>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/GameplayEffect_BaseDamage.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/GameplayEffect_FireDamage.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/GameplayEffect_PoisonDamage.gif" width = "200" heigh = "150"></td>
	</tr>
	<tr>
	  <th> StatOverride </th>
	  <th> Cooldown </th>
	  <th> ManaCost </th>
	</tr>
	<tr>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/GameplayEffect_StatOverride.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/GameplayEffect_Cooldown.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/GameplayEffect_MansCost.gif" width = "200" heigh = "150"></td>
	</tr>
  </table>
	
	<details>
		<summary> StatOverride 코드 (Click!)</summary>
		
	```cpp
	DataAsset_StartUpDataBase.h
		void SetCharacterAttributeByLevel(UMWAbilitySystemComponent* InASCToGive, int32 ApplyLevel);
	```
	
	```cpp
	DataAsset_StartUpDataBase.cpp
	void UDataAsset_StartUpDataBase::SetCharacterAttributeByLevel(UMWAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
	{
		if (!StartUpGameplayEffects.IsEmpty())
		{
			for (const TSubclassOf<UGameplayEffect>& EffectClass : StartUpGameplayEffects)
			{
				if (!EffectClass) continue;
	
				UGameplayEffect* EffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();
				InASCToGive->ApplyGameplayEffectToSelf(
					EffectCDO,
					ApplyLevel,
					InASCToGive->MakeEffectContext()
				);
			}
		}
	}
	```
	<img width="1284" height="452" alt="스크린샷 2025-12-04 154057" src="https://github.com/user-attachments/assets/ff7b29bb-050e-4267-9dda-96fed71a8faf" />
	</details>&nbsp;

- GameplayCue
  <table>
	<tr>
	  <th colspan = "4"> 기능 구현 항목</th>
	</tr>
	<tr>
	  <th> Attack Warning</th>
	  <th> Level Up </th>
	  <th> Hero Ult </th>
	  <th> Stun </th>
	</tr>
	<tr>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/GameplayCue_AttackWarning.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/GameplayCue_LevelUp.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/GameplayCue_Ult.gif" width = "200" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/GameplayCue_Stun.gif" width = "200" heigh = "150"></td>
	</tr>
  </table>

## 4. UI
### HeroOverlay
- HP, Mana
	<table>
	<tr>
	  <th> Hp Change </th>
	  <th> Mana Chnage </th>
	</tr>
	<tr>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/GameplayEffect_BaseDamage.gif" width = "300" heigh = "150"></td>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/GameplayEffect_MansCost.gif" width = "300" heigh = "150"></td>
	</tr>
	</table>
	<details>
		<summary> HeroUIComponent.h 코드 (Click!)</summary>
		
	```cpp
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeroPortraitIconUpdateDelegate, UTexture2D*, HeroPortraitIcon);
		
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHeroAbilityIconUpdateDelegate, FGameplayTag, AbilityInputTag, UMaterialInterface*, HeroAbilityIconMaterial);
		
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAbilityCooldownBeginDelegate, FGameplayTag, AbilityInputTag, float, TotalCooldownTime, float, RemainingCooldownTime);
		
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityActivatableDelegate, FGameplayTag, AbilityInputTag);
		
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityDisableDelegate, FGameplayTag, AbilityInputTag);
		
		/**
		 * 
		 */
		UCLASS()
		class MW_API UHeroUIComponent : public UPawnUIComponent
		{
			GENERATED_BODY()
		
		public:
			UPROPERTY(BlueprintAssignable)
			FOnPercentChangedDelegate OnCurrentManaChanged;
		
			UPROPERTY(BlueprintCallable, BlueprintAssignable)
			FOnHeroPortraitIconUpdateDelegate OnHeroPortraitIconUpdated;
		
			UPROPERTY(BlueprintCallable, BlueprintAssignable)
			FOnHeroAbilityIconUpdateDelegate OnHeroAbilityIconUpdated;
			
			UPROPERTY(BlueprintCallable, BlueprintAssignable)
			FOnAbilityCooldownBeginDelegate OnAbilityCooldownBegin;
			
			UPROPERTY(BlueprintCallable, BlueprintAssignable)
			FOnAbilityActivatableDelegate OnAbilityActivatable;
		
			UPROPERTY(BlueprintCallable, BlueprintAssignable)
			FOnAbilityActivatableDelegate OnAbilityDisable;
		};
	```
	</details>
	
	<details>
		<summary> MWAttributeSet.cpp 코드 중 일부 + Delegate를 Bind한 Blueprints (Click!) </summary>
		
	```cpp
	void UMWAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
	{
		if (!CachedPawnUIInterface.IsValid())
		{
			CachedPawnUIInterface = TWeakInterfacePtr<IPawnUIInterface>(Data.Target.GetAvatarActor());
		}
	
		UPawnUIComponent* PawnUIInterface = CachedPawnUIInterface->GetPawnUIComponent();
	
		if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
		{
			const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());
	
			SetCurrentHealth(NewCurrentHealth);
	
			PawnUIInterface->OnCurrentHealthChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());
		}
	
		if (Data.EvaluatedData.Attribute == GetCurrentManaAttribute())
		{
			const float NewCurrentMana = FMath::Clamp(GetCurrentMana(), 0.f, GetMaxMana());
	
			SetCurrentMana(NewCurrentMana);
	
			{ ... }
	
			if (UHeroUIComponent* HeroUIComponent = CachedPawnUIInterface->GetHeroUIComponent())
			{
				HeroUIComponent->OnCurrentManaChanged.Broadcast(GetCurrentMana() / GetMaxMana());
			}
		}
 	}
	```
	<img width="1304" height="443" alt="스크린샷 2025-12-04 180642" src="https://github.com/user-attachments/assets/8d01c8b1-06fa-4392-b6ca-22f521d8d54b" />
	
	</details>
  	- HeroCharacter에서 HeroUIComponent를 소유하고 AttributeSet에서는 HP, Mana의 변경이 일어나면 변경된 퍼센티지를 Broadcast해줍니다.

&nbsp;

- Cooldown
	<table>
	<tr>
	  <th> Cooldown </th>
	</tr>
	<tr>
	  <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/GameplayEffect_Cooldown.gif" width = "400" heigh = "150"></td>
	</tr>
  </table>
  
	<details>
		<summary> TemplateWidget Blueprint의 CooldownBegin_Event (Click!)</summary>
		<img width="957" height="369" alt="스크린샷 2025-12-04 180557" src="https://github.com/user-attachments/assets/cc7043e7-587c-4db9-b44b-170bef7d3570" />
		<img width="1572" height="462" alt="스크린샷 2025-12-04 195154" src="https://github.com/user-attachments/assets/8177820d-1573-4593-aa1b-d5435b4629a1" />
		<img width="1141" height="581" alt="스크린샷 2025-12-04 195211" src="https://github.com/user-attachments/assets/3294f1f2-1c11-4d39-9382-93b771a33791" />
	</details>
	- Ability를 사용하는 곳에서 Delegate를 Call 해줍니다. Delegate를 Bind한 위젯에서 LatentAction인 Countdown을 이용해서 Text와 Material Parameter를 설정해줍니다.

## 5. etc
- Behavior Tree
  <details>
	  <summary> Enemy Red BT 일부 (Click!) </summary>
	  	<img width="643" height="471" alt="스크린샷 2025-12-04 200216" src="https://github.com/user-attachments/assets/0dc088d6-4ef5-47ab-b35a-2ad6eb7a4e68" />
		<img width="893" height="444" alt="스크린샷 2025-12-04 200138" src="https://github.com/user-attachments/assets/861cb377-1511-418e-947c-2e5d9a4285ca" />
		<img width="1323" height="760" alt="스크린샷 2025-12-04 200105" src="https://github.com/user-attachments/assets/0728b9e3-8e07-4711-9053-d332c4cce961" />
	  	<img width="1321" height="647" alt="스크린샷 2025-12-04 200036" src="https://github.com/user-attachments/assets/34b8f0b1-8e39-4502-a701-df39792cd14e" />
	  	EQS_FindStrafingLocation
	  	<img width="791" height="511" alt="스크린샷 2025-12-04 195729" src="https://github.com/user-attachments/assets/e939ca8a-34bb-4e2e-ac09-cce57079a1e6" />
  </details>
  - Perception으로 인식한 Target의 GroundLocation을 찾고 자신의 위치와 비교해서 일정 거리 안에 있으면 StrafingStatus에 돌입하고 멀면 Target을 쫓아갑니다. Target과 자신이 너무 가까울 경우 자신이 Target을 향해 바라보게 한 후 3개의 공격 Ability중 성공한 Ability를 실행합니다. 만약 자신의 체력이 일정 수치 이하일경우 MotionWarping을 사용한 Montage를 가지고 있는 Ability를 실행합니다.
&nbsp;
- SaveGame
	<details>
		<summary> SaveGame 기능 구현 항목 .gif (Click!)</summary>
	  <table>
	    <tr>
	      <th colspan = "2"> SaveGame </th>
	    </tr>
	    <tr>
	      <th> SaveWave </th>
	      <th> SaveDifficulty </th>
	    </tr>
	    <tr>
	      <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/SaveDifficulty_1.gif" width = "300" heigh = "150"></td>
	      <td><img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/SaveWave_1.gif" width = "300" heigh = "150"></td>
	    </tr>
	  </table>
	</details>

	<details>
		<summary> SaveGame 코드 (Click!)</summary>
		
	```cpp
			MWSaveGame.h
			UCLASS()
			class MW_API UMWSaveGame : public USaveGame
			{
				GENERATED_BODY()
	
			public:
				UPROPERTY(BlueprintReadOnly)
				EMWGameDfficulty SaveCurrentGameDifficulty;
	
				UPROPERTY(BlueprintReadOnly)
				int32 SavedCurrentWaveCount;
			};
	```
	
	```cpp
			MWBaseGameMode.h
			UCLASS()
			class MW_API AMWBaseGameMode : public AGameModeBase
			{
				GENERATED_BODY()
				
			public:
				AMWBaseGameMode();
			
				FORCEINLINE EMWGameDfficulty GetCurrentGameDifficulty() const { return CurrentGameDfficulty; }
				FORCEINLINE int32 GetCurrentGameWave() const { return CurrentWaveCount; }
			
			protected:
				UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
				EMWGameDfficulty CurrentGameDfficulty;
			
				UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Game Play Data")
				int32 CurrentWaveCount = 1;
			};
	```
		
	```cpp
			MWSurvivalGameMode.h 일부
			void AMWSurvivalGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
			{
				Super::InitGame(MapName, Options, ErrorMessage);
			
				EMWGameDfficulty SavedGameDifficulty;
			
				if (UMWBlueprintFunctionLibrary::TryLoadSavedCurrentGameDifficulty(SavedGameDifficulty))
				{
					CurrentGameDfficulty = SavedGameDifficulty;
				}
			
				int32 SavedCurrentWaveCount;
			
				if (UMWBlueprintFunctionLibrary::TryLoadSavedCurrentGameWave(SavedCurrentWaveCount))
				{
					CurrentWaveCount = SavedCurrentWaveCount;
				}
			
				TargetPointsArray.Empty();
			}
	```

	```cpp
 		MWBlueprintFunctionLibrary.cpp 일부
 		bool UMWBlueprintFunctionLibrary::TryLoadSavedCurrentGameWave(int32& OutSavedCurrentWave)
		{
			if (UGameplayStatics::DoesSaveGameExist(MWGameplayTags::GameData_SaveGame_Slot_2.GetTag().ToString(), 0))
			{
				USaveGame* SaveGameObject = UGameplayStatics::LoadGameFromSlot(MWGameplayTags::GameData_SaveGame_Slot_2.GetTag().ToString(), 0);
		
				if (UMWSaveGame* MWSaveGameObject = Cast<UMWSaveGame>(SaveGameObject))
				{
					OutSavedCurrentWave = MWSaveGameObject->SavedCurrentWaveCount;
		
					Debug::Print(TEXT("Loading Successful"));
		
					return true;
				}
			}
		
			return false;
		}
 	```
	</details>
	- 프로젝트에서 항상 부모 클래스인 MWBaseGameMode을 이용해 SaveGame을 통해 저장하고자 하는 변수들을 저장해줍니다. 그리고 SurvivalGameMode를 사용하는 Level에서 SaveGame을 통해 찾고자 하는 변수를 불러옵니다.
