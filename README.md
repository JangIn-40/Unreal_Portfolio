## 1. 프로젝트 소개
- GAS를 활용한 언리얼 엔진 포트폴리오
- 개발 목적 : GAS라는 표준화된 구조를 사용해보고 싶었습니다.
- 제작 기간 : 2025.10.23 ~ 2025.12.01 (약 한달)
- 개발 인원 : 1인
- Paragon 에셋을 활용해서 Wukong 영웅으로 몰려오는 적들을 처치하는 액션게임을 만들었습니다.

## 2. 플레이 동영상
<img src = "https://github.com/JangIn-40/Unreal_Portfolio/blob/main/gif/HighLights_1.gif" width = "400" heigh = "150">

## 3. Gameplay Ability System
### - Gameplay Ability
<details>
	<summary> 영웅 기능 구현 항목 .gif (Click!)</summary>
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
</details>

<details>
	<summary> GA_Hero_Light_Attack Blueprint (Click!)</summary>
	<img width="1063" height="415" alt="스크린샷 2025-12-04 154940" src="https://github.com/user-attachments/assets/d7da878b-883a-4c5a-9933-68958bb2e588" />
	<img width="1088" height="628" alt="스크린샷 2025-12-04 154957" src="https://github.com/user-attachments/assets/b31dc59a-9d63-44aa-aaf8-aad925c09503" />
	<img width="1095" height="431" alt="스크린샷 2025-12-04 155009" src="https://github.com/user-attachments/assets/ee5f32b7-e0ac-4bbc-83a9-e4bf4397c049" />
	<img width="1051" height="393" alt="스크린샷 2025-12-04 155017" src="https://github.com/user-attachments/assets/efdec381-dbd2-4e4c-b5c4-3662e0c24f2e" />
	<img width="1048" height="415" alt="스크린샷 2025-12-04 155030" src="https://github.com/user-attachments/assets/12e581b3-7fc7-4e48-8007-c876e2211aaa" />
	<img width="1920" height="1040" alt="스크린샷 2025-12-04 154624" src="https://github.com/user-attachments/assets/323b7d0a-8f9a-4ea8-8406-883ecd2156c4" />
	<img width="1920" height="1040" alt="스크린샷 2025-12-04 154644" src="https://github.com/user-attachments/assets/74bc8725-17e7-495b-b1e5-bcad3622d3cb" />

</details>&nbsp;
<details>
	<summary> 적 기능 구현 항목 .gif (Click!)</summary>
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
</details>
<details>
	<summary> Shared_Stun_Base Blueprint (Click!)</summary>
	<img width="1090" height="354" alt="스크린샷 2025-12-04 160324" src="https://github.com/user-attachments/assets/ad7481d2-52fe-4fe4-ab59-2dc14cdcf148" />
	<img width="1086" height="579" alt="스크린샷 2025-12-04 160716" src="https://github.com/user-attachments/assets/5684464f-e467-4336-8e1f-f5990f3910fb" />
</details>&nbsp;

### - GameplayEffect
<details>
	<summary>기능 구현 항목 .gif (Click!)</summary>
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
</details>

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
</details>&nbsp

### - GameplayCue
<details>
	<summary>기능 구현 항목 .gif (Click!)</summary>
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
</details>

## 4. etc
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
