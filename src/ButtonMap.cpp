#include "map"
#include "string"

struct ButtonData{
    int pin;
    uint8_t protocol;  // Will be 0 (UNKNOWN) when zero-initialized
    uint64_t rawData;        // Will be 0
    uint8_t bitLength;    

    ButtonData(int p = 0, uint8_t proto = 0, uint64_t raw = 0x00, uint8_t len = 0)
        : pin(p), protocol(proto), rawData(raw), bitLength(len) {}

};

struct ButtonMap{
    std::map<std::string, ButtonData> buttons;

    std::string profileName = "DEFAULT";

    // ButtonMap constructor
    // assign pins to each button data
    ButtonMap(): buttons({
            {"volumeUp",   ButtonData(4)},
            {"volumeDown", ButtonData(5)},
            {"power",      ButtonData(12)},
            {"mute",       ButtonData(13)}
        }) {}
};

