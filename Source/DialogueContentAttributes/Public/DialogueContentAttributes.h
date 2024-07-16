#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

UENUM(BlueprintType)
enum class EDialogueConditionType : uint8
{
    Elimination,
    Requirement
};

UENUM(BlueprintType)
enum class EDialogueNumericalComparator : uint8
{
    Equal,
    GreaterThan,
    LessThan,
    GreaterThanOrEqual,
    LessThanOrEqual
};

class FDialogueContentAttributesModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
