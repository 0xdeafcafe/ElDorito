#pragma once
#include <memory>
#include "../Utils/Utils.hpp"
#include "Queue.hpp"
#include "IRCBackend.hpp"
#include "TextInput.h"

class Queue;	
class ConsoleQueue;
class GlobalChatQueue;
class GameChatQueue;

class GameConsole : public Utils::Singleton<GameConsole>
{
private:
	bool capsLockToggled = false;
	int lastTimeConsoleShown = 0;
	static void startIRCBackend();
	void hideConsole();
	void displayChat(bool console);
	void initPlayerName();
	void handleDefaultKeyInput(USHORT vKey);

public:
	ConsoleQueue consoleQueue = ConsoleQueue();
	GlobalChatQueue globalChatQueue = GlobalChatQueue();
	GameChatQueue gameChatQueue = GameChatQueue();
	TextInput currentInput;
	int currentBacklogIndex = -1;
	bool tabHitLast = false;
	int tryCount = 0;
	std::string commandPriorComplete = "";
	std::vector<std::string> currentCommandList = std::vector < std::string > {};
	Queue* selectedQueue = &globalChatQueue;
	Queue* lastChatQueue = &globalChatQueue;
	std::string playerName = "";
	int lastTimeConsoleBlink = 0;
	bool consoleBlinking = false;
	bool showChat = false;
	bool showConsole = false;

	GameConsole();
	int getMsSinceLastConsoleOpen();
	int getMsSinceLastConsoleBlink();
	void peekConsole();
	void virtualKeyCallBack(USHORT vKey);
	void mouseCallBack(RAWMOUSE mouseInfo);
	std::string GenerateIRCNick(std::string name, uint64_t uid);
};