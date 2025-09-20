#include "map"
#include "string"

struct ButtonData{
    int pin = -1;
    uint8_t protocol = 0;  // Will be 0 (UNKNOWN) when zero-initialized
    uint64_t rawData = 0;        // Will be 0
    uint8_t bitLength = 0;    
};

struct ButtonMap{
    std::map<std::string, ButtonData> buttons;

    ButtonMap(){
        buttons["volumeUp"] = ButtonData{.pin = 4};
        buttons["volumeDown"] = ButtonData{.pin = 5};
        buttons["power"] = ButtonData{.pin = 12};
        buttons["mute"] = ButtonData{.pin = 13};
    }
    // private:
    //     const int b1 =  4; // D2
    //     const int b2 =  5; // D1
    //     const int b3 =  12; // D6
    //     const int b4 =  13; // D7
    
    // public:
    //     int protocolType = 0; // temp filler. will need to figure out how to determine the protocol
    //     unsigned int volumeUp = 0x00;
    //     unsigned int volumeDown = 0x00;
    //     unsigned int power = 0x00;
    //     unsigned int mute = 0x00;

};

