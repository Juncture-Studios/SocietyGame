#include "DialogueEditor.h"

#include "DialogueContentCatalogAssetTypeActions.h"

#define LOCTEXT_NAMESPACE "FDialogueEditorModule"

void FDialogueEditorModule::StartupModule()
{
    DialogueContentCatalogAssetTypeActions = MakeShared<FDialogueContentCatalogAssetTypeActions>();
    FAssetToolsModule::GetModule().Get().RegisterAssetTypeActions(DialogueContentCatalogAssetTypeActions.ToSharedRef());
}

void FDialogueEditorModule::ShutdownModule()
{
    if (!FModuleManager::Get().IsModuleLoaded("AssetTools")) return;
    FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(DialogueContentCatalogAssetTypeActions.ToSharedRef());
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FDialogueEditorModule, DialogueEditor)