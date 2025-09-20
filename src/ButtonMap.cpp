#include "map"
#include "string"

struct ButtonData{
    int pin;
    uint8_t protocol;  // Will be 0 (UNKNOWN) when zero-initialized
    uint64_t rawData;        // Will be 0
    uint8_t bitLength;    

    ButtonData() : pin(0), protocol(0), rawData(0), bitLength(0) {}  // Default everything to 0
};

struct ButtonMap{
    std::map<std::string, ButtonData> buttons;

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

