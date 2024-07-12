#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FDialogueContentCatalogAssetTypeActions;

class FDialogueEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
private:
    TSharedPtr<FDialogueContentCatalogAssetTypeActions> DialogueContentCatalogAssetTypeActions;
};
