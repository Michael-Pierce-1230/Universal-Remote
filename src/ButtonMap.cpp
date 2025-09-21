#include "map"
#include "string"

struct ButtonData{
    int pin;
    uint8_t protocol;  // Will be 0 (UNKNOWN) when zero-initialized
    uint64_t rawData;        // Will be 0
    uint8_t bitLength;    

    ButtonData() :pin(0), protocol(0), rawData(0), bitLength(0) {}  // Default everything to 0
};

struct ButtonMap{
    std::map<std::string, ButtonData> buttons;

    std::string profileName = "DEFAULT";

    ButtonMap(){
        buttons["volumeUp"] = ButtonData();
        buttons["volumeUp"].pin = 4;
        buttons["volumeDown"] = ButtonData();
        buttons["volumeDown"].pin = 5;
        buttons["power"] = ButtonData();
        buttons["power"].pin = 12;
        buttons["mute"] = ButtonData();
        buttons["mute"].pin = 13;
    }
};

