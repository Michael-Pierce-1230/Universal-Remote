#include "map"
#include "string"
#include <Arduino.h>

struct BaseButton{
    int pin = 0;
    bool buttonState = HIGH;
    bool lastButtonState = HIGH;
    unsigned long lastDebounceTime = 0;

    BaseButton() = default;
    BaseButton(int p) : pin(p) {} // constructor that sets pin

};

struct ButtonData : BaseButton{
    // int pin;
    uint8_t protocol = 0;  // Will be 0 (UNKNOWN) when zero-initialized
    uint64_t rawData = 0;        // Will be 0
    uint8_t bitLength = 0;
    // bool buttonState;
    // bool lastButtonState;
    // unsigned long lastDebounceTime = 0;

    // constructor to allow pin initialization
    ButtonData() = default;
    ButtonData(int p) : BaseButton(p) {}
    // ButtonData(int p = 0, uint8_t proto = 0, uint64_t raw = 0x00, uint8_t len = 0)
    //     : pin(p), protocol(proto), rawData(raw), bitLength(len){}

};

struct ButtonMap{
    std::map<std::string, ButtonData> buttons;

    std::string profileName = "DEFAULT";

    // ButtonMap constructor
    // assign pins to each button data
    ButtonMap(): buttons({
            {"volumeUp",   ButtonData(25)},
            {"volumeDown", ButtonData(27)},
            {"power",      ButtonData(26)},
            // {"mute",       ButtonData(14)}
        }) {}
};

