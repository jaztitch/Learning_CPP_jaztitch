#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct NPC {
    string dialog;
    map<string, string> responses;
    string questItem;
};

struct Room {
    string name;
    string description;
    map<string, pair<string, bool> > exits; // exit name -> (room name, isLocked)
    vector<string> items;
    map<string, string> interactiveObjects;
    map<string, NPC> npcs;
};

map<string, Room> world;
string currentRoom = "The back of a cave";
vector<string> inventory;
bool hasTorch();

void toLowerCase(string &str);
void trim(string &str);
void showHelp();
void setupWorld();
void saveGame();
void loadGame();
void gameLoop();

int main() {
    setupWorld();
    cout<<"Welcome. Type help if you need help.";
    gameLoop();
    return 0;
}

void gameLoop() {
    while (true) {
        Room &room = world[currentRoom];
        cout << "\nLocation: " << room.name << "\n";
        cout << room.description << "\n";

        if (!room.items.empty()) {
            cout << "Items here: ";
            for (const string &item : room.items) cout << item << ", ";
            cout << "\n";
        }

        if (!room.exits.empty()) {
            cout << "Exits: ";
            for (const auto &e : room.exits) {
                if (currentRoom == "The back of a cave" && e.first == "crawlspace" && !hasTorch()) continue;
                cout << e.first << (e.second.second ? " (locked)" : "") << " ";
            }
            cout << "\n";
        }

        if (!room.npcs.empty()) {
            cout << "You see: ";
            for (map<string, NPC>::iterator it = room.npcs.begin(); it != room.npcs.end(); ++it)
                cout << it->first << ", ";
            cout << "\n";
        }

        cout << "\n> ";
        string cmd;
        getline(cin, cmd);
        toLowerCase(cmd);

        istringstream iss(cmd);
        vector<string> tokens;
        string word;
        while (iss >> word) tokens.push_back(word);
        if (tokens.empty()) continue;

        string action = tokens[0];
        string target = tokens.size() > 1 ? cmd.substr(action.size() + 1) : "";
        trim(target);

        if (action == "quit") break;
        else if (action == "help") { showHelp(); continue; }
        else if (action == "inventory") {
            cout << "You have: ";
            for (const string &item : inventory) cout << item << ", ";
            cout << "\n";
            continue;
        } else if (action == "save") { saveGame(); continue; }
        else if (action == "load") { loadGame(); continue; }

        else if ((action == "look" || action == "examine" || action == "inspect")) {
            if (target.empty()) cout << room.description << "\n";
            else if (room.interactiveObjects.count(target)) cout << room.interactiveObjects[target] << "\n";
            else cout << "You see no " << target << " here.\n";
            continue;
        }

        else if (action == "take" || action == "get" || action == "grab") {
            auto it = find(room.items.begin(), room.items.end(), target);
            if (it != room.items.end()) {
                inventory.push_back(target);
                room.items.erase(it);
                cout << "You take the " << target << ".\n";
            } else cout << "There is no " << target << " to take.\n";
            continue;
        }

        else if (action == "talk") {
            if (room.npcs.count(target)) {
                NPC &npc = room.npcs[target];
                cout << npc.dialog << "\n";
                if (!npc.questItem.empty() && find(inventory.begin(), inventory.end(), npc.questItem) != inventory.end()) {
                    cout << target << " notices your " << npc.questItem << ". \"Ah, you have what I need.\"\n";
                }
                cout << "You can ask: ";
                for (const auto &r : npc.responses) cout << "'" << r.first << "' ";
                cout << "\n> ";
                string question;
                getline(cin, question);
                toLowerCase(question);
                trim(question);
                if (npc.responses.count(question)) {
                    cout << npc.responses[question] << "\n";
                } else {
                    cout << target << " doesn't understand your question.\n";
                }
            } else {
                cout << "There's no one named '" << target << "' here.\n";
            }
            continue;
        }

        else if (action == "unlock") {
            if (room.exits.count(target)) {
                pair<string, bool> &exitInfo = room.exits[target];
                if (!exitInfo.second) {
                    cout << "The exit is already unlocked.\n";
                } else {
                    if (find(inventory.begin(), inventory.end(), "key") != inventory.end()) {
                        exitInfo.second = false;
                        cout << "You unlock the " << target << " exit.\n";
                    } else {
                        cout << "You need a key to unlock that.\n";
                    }
                }
            } else {
                cout << "There is no exit named '" << target << "' here.\n";
            }
            continue;
        }

        else if (room.exits.count(action)) {
            if (room.exits[action].second) {
                cout << "That exit is locked.\n";
            } else {
                currentRoom = room.exits[action].first;
            }
            continue;
        }

        cout << "I don't understand that command.\n";
    }
}

void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void trim(string &str) {
    str.erase(0, str.find_first_not_of(" \t\n\r"));
    str.erase(str.find_last_not_of(" \t\n\r") + 1);
}

bool hasTorch() {return find(inventory.begin(), inventory.end(), "torch") != inventory.end();}

void loadGame() {
    ifstream file("savegame.txt");
    if (!file.is_open()) {
        cout << "No save file found.\n";
        return;
    }
    inventory.clear();
    for (auto &p : world)
        p.second.items.clear();

    string line;
    string currentRoomName;
    while (getline(file, line)) {
        if (line.find("inv:") == 0)
            inventory.push_back(line.substr(4));
        else if (line.find("room:") == 0)
            currentRoomName = line.substr(5);
        else if (line.find("item:") == 0 && !currentRoomName.empty())
            world[currentRoomName].items.push_back(line.substr(5));
        else if (line.find("exit:") == 0 && !currentRoomName.empty()) {
            stringstream ss(line.substr(5));
            string exitName, destRoom, lockStatus;
            getline(ss, exitName, ',');
            getline(ss, destRoom, ',');
            getline(ss, lockStatus);
            world[currentRoomName].exits[exitName] = make_pair(destRoom, lockStatus == "locked");
        }
        else
            currentRoom = line; // first line is room name
    }
    file.close();
    cout << "Game loaded.\n";
}

void saveGame() {
    ofstream file("savegame.txt");
    file << currentRoom << "\n";
    for (const string &item : inventory)
        file << "inv:" << item << "\n";
    for (const auto &pair : world) {
        file << "room:" << pair.first << "\n";
        for (const string &item : pair.second.items)
            file << "item:" << item << "\n";
        for (const auto &exit : pair.second.exits)
            file << "exit:" << exit.first << "," << exit.second.first << "," << (exit.second.second ? "locked" : "unlocked") << "\n";
    }
    file.close();
    cout << "Game saved.\n";
}

void showHelp() {
    cout << "\nAvailable commands:\n";
    cout << " - examine [object]  : Examine an object or item\n";
    cout << " - take [item]       : Take an item\n";
    cout << " - talk [npc]        : Talk to a character\n";
    cout << " - unlock [exit]     : Unlock an exit (requires key)\n";
    cout << " - inventory         : Show your inventory\n";
    cout << " - save              : Save your game\n";
    cout << " - load              : Load your game\n";
    cout << " - quit              : Exit the game\n";
    cout << " - help              : Show this help message\n";
    cout << " - [exit name]       : Move through an exit (e.g., 'north')\n";
}

void setupWorld() {
	
	Room caveRear;
	caveRear.name="The back of a cave";
	caveRear.description="It's dark and cold in here. The floor and walls are made of a hard stone.";
	caveRear.exits["forward"] = make_pair("Cave Entrance", false);
	cave.exits["crawlspace"] = make_pair("Secret Chamber", false); // hidden unless torch is present
	
    Room cave;
    cave.name = "Cave Entrance";
    cave.description = "You're at the entrance of a cave. A pile of items lies nearby.";
    cave.items = { "torch", "key" };
    cave.interactiveObjects["pile"] = "An old pile of belongings. It contains a torch and a key.";
    cave.exits["outside"] = make_pair("Cliffside", false);

    Room cliff;
    cliff.name = "Cliffside";
    cliff.description = "You're standing on a cliff overlooking a forest. The cave is behind you.";
    cliff.exits["cave"] = make_pair("Cave Entrance", false);
    
    Room secret;
    secret.name = "Secret Chamber";
    secret.description = "You've discovered a hidden chamber within the cave. Ancient markings cover the walls.";
    secret.exits["cave"] = make_pair("Cave Entrance", false);

	world["The back of a cave"] = caveRear;
    world["Cave Entrance"] = cave;
    world["Cliffside"] = cliff;
    world["Secret Chamber"] = secret;
}
