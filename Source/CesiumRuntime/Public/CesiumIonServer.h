// Copyright 2020-2023 CesiumGS, Inc. and Contributors

#pragma once

#include "Engine/DataAsset.h"
#include "UObject/Object.h"
#include "CesiumIonServer.generated.h"

UCLASS()
class CESIUMRUNTIME_API UCesiumIonServer : public UDataAsset {
  GENERATED_BODY()

public:
  static UCesiumIonServer* GetOrCreateDefault();

  static UCesiumIonServer* GetDefaultForNewObjects();
  static void SetDefaultForNewObjects(UCesiumIonServer* Server);

#if WITH_EDITOR
  static UCesiumIonServer* GetOrCreateForApiUrl(const FString& apiUrl);
#endif

  /**
   * The name to display for this server.
   */
  UPROPERTY(
      EditAnywhere,
      AssetRegistrySearchable,
      Category = "Cesium",
      meta = (DisplayName = "Display Name"))
  FString DisplayName = "ion.cesium.com";

  /**
   * The main URL of the Cesium ion server. For example, the server URL for the
   * public Cesium ion is https://ion.cesium.com.
   */
  UPROPERTY(
      EditAnywhere,
      Category = "Cesium",
      meta = (DisplayName = "Server URL"))
  FString ServerUrl = "https://ion.cesium.com";

  /**
   * The URL of the main API endpoint of the Cesium ion server. For example, for
   * the default, public Cesium ion server, this is `https://api.cesium.com`. If
   * left blank, the API URL is automatically inferred from the Server URL.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium", meta = (DisplayName = "API URL"))
  FString ApiUrl = "https://api.cesium.com";

  /**
   * The application ID to use to log in to this server using OAuth2. This
   * OAuth2 application must be configured on the server with the exact URL
   * `http://127.0.0.1/cesium-for-unreal/oauth2/callback`.
   */
  UPROPERTY(
      EditAnywhere,
      Category = "Cesium",
      meta = (DisplayName = "OAuth Application ID"))
  int64 OAuth2ApplicationID = 190;

  /**
   * The ID of the default access token to use to access Cesium ion assets at
   * runtime. This property may be an empty string, in which case the ID is
   * found by searching the logged-in Cesium ion account for the
   * DefaultIonAccessToken.
   */
  UPROPERTY(
      EditAnywhere,
      Category = "Cesium",
      meta = (DisplayName = "Default Cesium ion Access Token ID"))
  FString DefaultIonAccessTokenId;

  /**
   * The default token used to access Cesium ion assets at runtime. This token
   * is embedded in packaged games for use at runtime.
   */
  UPROPERTY(
      EditAnywhere,
      Category = "Cesium",
      meta = (DisplayName = "Default Cesium ion Access Token"))
  FString DefaultIonAccessToken;

private:
  static UCesiumIonServer* _pDefaultForNewObjects;
};
