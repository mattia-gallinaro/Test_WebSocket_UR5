// Fill out your copyright notice in the Description page of Project Settings.


#include "WebSocketTest_GameInstance.h"
#include "WebSocketsModule.h"
void UWebSocketTest_GameInstance::Init() 
{
	Super::Init();
	if (!FModuleManager::Get().IsModuleLoaded("WebSockets"))//checks if the module has been loaded
	{
		FModuleManager::Get().LoadModule("WebSockets");//to load the web socket module if it hasn't been loaded correctly
	}

	WebSocket = FWebSocketsModule::Get().CreateWebSocket("ws://localhost:8080");
	WebSocket->Connect();
}

void UWebSocketTest_GameInstance::Shutdown()
{
	if (WebSocket -> IsConnected()) {
		WebSocket->Close();
	}
	Super::Shutdown();
}