#include <iostream>

class Logger // Can log into console, file, network, etc.
{
public:
    void log(const uint8_t level, const std::string& message)
    {
        switch(level)
        {
            case 0:
                std::cout << "[ERROR] " << message << std::endl;
                break;

            case 1:
                std::cout << "[WARN] " << message << std::endl;
                break;

            case 2:
                std::cout << "[INFO] " << message << std::endl;
                break;

            case 3:
            default:
                std::cout << "[DEBUG] " << message << std::endl;
                break;
        }
    }
};

class GateController : public Logger
{
public:
    void openGate()
    {
        // gate.open();
        log(2, "Gate opened");
    }
};

class OptParamReader : public Logger
{
public:
    void readParam(const std::string& paramName)
    {
        // read param from file
        log(3, "Reading param: " + paramName);
    }
};

void exampleLogger()
{
    GateController gc;
    gc.log(3, "Gate controller created");
    gc.openGate();

    OptParamReader opr;
    opr.log(3, "OptParamReader created");
    opr.readParam("param1");
}