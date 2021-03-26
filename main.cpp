/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() and for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}

//call Example::main() in main()





struct CanPlant
{
    int tinAmount;
    double rawFish;
    int autoclaveLoad;
    int dayCansOut;
    float workHours;
    CanPlant() :
        tinAmount(1000),
        rawFish(100.21),
        autoclaveLoad(300),
        dayCansOut(900),
        workHours(12)
    {}
    
    struct OfficeWorker
    {
        int callOperatorId{ 1 };
        int intNumber{ 1301 };
        std::string operatorName;
        float hourStart{ 5.5f };
        float hourEnd{ 12.0f };
        OfficeWorker() : operatorName("Elena") {}
        
        void makeCall(int customerId = 0, float time = 0);
        void pickCall(int number, float time);
        int reserveGood(int customerId, int amount = 0);
    };
    
    int produceCans(int slicedFish, int tinAmount = 1000);
    void loadBoxes(int boxes, int wareHouseNumber);
    double reportScrapOut(double rawFish, double workHours);
};

struct SipProvider
{
    std::string codecName{ "G729" };
    int calls;
    bool t38;
    double price;
    double balance { -1 };
    int slaType;
    SipProvider() :
        calls(2),
        t38(false),
        price(0),
        slaType(1)
    {}
    
    void printStatus () { std::cout << "trunk: " << ( balance < 0 ? "offline" : "online" ) << std::endl; }
    bool makeCall(int src, int dst);
    double chargeCustomer(double time, int customerId);
    double traficCount(double time);
};

struct Cat
{
    int paw;
    char colour;
    bool gender; //0 female, 1 male
    float age;
    int liveNumber;
    Cat();

    void eat(char foodType);
    void sleep (float time);
    void mew (int count);
};

Cat::Cat()
{
    paw = 4;
    colour = 'B';
    gender = 0; //0 female, 1 male
    age = 3.5f;
    liveNumber = 1;
}

struct SpaceShip
{
    float orbitHeight{ 1000.f };
    std::string engineType{ "rocket" };
    int crewNum{ 3 };
    std::string country{ "RU" };
    std::string name{ "Salyut" };
    SpaceShip();
    
    struct CrewMember
    {
        int memberId{ 0 };
        std::string name{ "Rob" };
        std::string jobRole{ "scientist" };
        float weight{ 70.f };
        float age{ 33.3f };
        CrewMember();
        
        void examineAnimal(int date, float time, Cat cat);
        bool recordTest(int date, float time, int testNum=0);
        void examineCrew (int date, float time, CrewMember memberId);
    };

    bool dock();
    void makeLoop(int planetNum = 3);
    bool takeOf(float startTime);
};

SpaceShip::SpaceShip() {}
SpaceShip::CrewMember::CrewMember() {}

struct DAC
{
    int sampleRate;
    int bitDepth;
    int SNR;
    float amountOfPowerConsumed;
    double dynamicRange;
    DAC() :
        sampleRate(48000),
        bitDepth(24),
        SNR(112),
        amountOfPowerConsumed(0.9f),
        dynamicRange(9.9)
    {}
    
    void readInput(int channelNum = 0);
    bool checkError(double sampleNum);
    void audioOut(int channelNum = 0);
};

struct PowerUnit
{
    float weight;
    double inVolt;
    double outVolt { 12.0 };
    int outCurrent;
    int maxOutTemp { 80 };
    PowerUnit() : weight(1.2f), inVolt(220), outCurrent(1){}
    void printStatus()
    {
        std::cout<<"Power Unit Status:"<<std::endl;
        std::cout<<"inV:"<<inVolt<<std::endl;
        std::cout<<"outV:"<<outVolt<<std::endl;
    }
     
    bool getElectricity(int outletStandart=1);
    double convertVoltage(double inVolt, double outVolt);
    bool status(int circuitId = 1);
};

struct VCA
{
    float freqResponse;
    double insertLoss;
    int attenuation;
    float price;
    int channelNum;
    VCA() :
        freqResponse(0.5f),
        insertLoss(0.01),
        attenuation(-100),
        price(3),
        channelNum(2)
    {}
    
    void attenuate(int coefficient = -50);
    void inputPower(int amountOfPower = 20);
    int readKnob (int knobAngle = 10);
};

struct HeadphoneAmp
{
    int SNR;
    float outPower;
    int outImpendance;
    int maxFreq;
    double inVolt;
    HeadphoneAmp() :
        SNR(112),
        outPower(600.0f),
        outImpendance(32),
        maxFreq(20000),
        inVolt(12)
    {}
    
    void getInput(int channelNum = 0);
    void doAmp(int channelNum = 0);
    bool noiseReduction(int filterNum = 3);
};

struct Body
{
    float height;
    float width;
    float depth;
    char colour;
    char material;
    Body() :
        height(6.5f),
        width(15.0f),
        depth(10.5f),
        colour('B'),
        material('W')
    {}
    
    bool checkTheBolt(int circuitId = 1);
    bool checkShortCircuit(int circuitId = 1);
    void alarmOverDust(float time = 10);
};

struct MonitorController
{
    DAC DACLeft;
    DAC DACRight;
    PowerUnit PSU0;
    VCA VCA0;
    HeadphoneAmp AmpLeft;
    HeadphoneAmp AmpRight;
    Body body0;
    MonitorController(){}

    void setVol(int amount = 0);
    bool selectSource(int sourceNum, bool status=0);
    bool toggleCrossfeed(bool status = 0);
};

void CanPlant::OfficeWorker::makeCall(int customerId, float time)
{
    SipProvider sipnet;
    sipnet.makeCall(intNumber, customerId);
    ++time;
}

void CanPlant::OfficeWorker::pickCall(int number, float time)
{
    //int recordedNumber = number;
    number = 0;
    ++time;
}

int CanPlant::OfficeWorker::reserveGood(int customerId, int amount)
{
    ++customerId;
    return ++amount;
}

int CanPlant::produceCans(int fish, int tin)
{
    return fish / tin;
}

void CanPlant::loadBoxes(int boxes, int wareHouseNumber)
{
    ++boxes;
    ++wareHouseNumber;
}

double CanPlant::reportScrapOut(double raw, double work)
{
    return raw * work *.01;
}

bool SipProvider::makeCall(int src, int dst)
{
    return (src != dst);
}

double SipProvider::chargeCustomer(double time, int customerId)
{
    if (customerId == 0)
    {
        return 0;
    }
    return time * price;
}

double SipProvider::traficCount(double time)
{
    return time * 0.1;
}

void Cat::eat(char foodType)
{
    if (foodType == 'F')
    {
        mew(3);
    }
}

void Cat::sleep (float time)
{
    ++time;
}

void Cat::mew (int count)
{ 
//    --count;
    for (int i=1;i<=count;++i)
    std::cout << "mew" << i << std::endl;
}

void SpaceShip::CrewMember::examineAnimal(int date, float time, Cat cat)
{
    int testNum = 0;
    if (cat.liveNumber <= 9)
    {
        recordTest(date, time, ++testNum);
    } 
    
    ++date;
    ++time;
}

bool SpaceShip::CrewMember::recordTest(int date, float time, int testNum)
{
    ++date;
    ++time;
    
    return (testNum !=0);
}

void SpaceShip::CrewMember::examineCrew (int date, float time, CrewMember id)
{
    int testNum = 0;
    if (id.weight >= 70.0f)
    {
        recordTest(date, time, ++testNum);
        ++date;
        ++time;
    }
}

bool SpaceShip::dock()
{
    //SpaceShip Rassvet;
    if (orbitHeight != 40.0f)
    {
        return true;
    }
    return false;
}
void SpaceShip::makeLoop(int planetNum )
{
    ++planetNum;
}

bool SpaceShip::takeOf(float startTime)
{
    //SpaceShip Rassvet;
    ++startTime;
    return (orbitHeight != 0.0f);
}

void DAC::readInput(int channelNum)
{
    for ( int i = 0; i < channelNum; i++ )
    {
        checkError(i);
    }
}

bool DAC::checkError(double sampleNum)
{
    double originalValue = 3.141592;
    return !(sampleNum > originalValue || sampleNum < originalValue);
}

void DAC::audioOut(int channelNum)
{
    HeadphoneAmp ampLeft, ampRight;
    
    //int bits = 24;
    
    for ( int i = 0; i < channelNum; i++ )
    {
        ampLeft.doAmp(i);
        ampRight.doAmp(i);
    
    }
}

bool PowerUnit::getElectricity(int outletStandart)
{
    return (outletStandart<3);
}

double PowerUnit::convertVoltage(double in, double out)
{
    return std::abs(in - out);
}

bool PowerUnit::status(int circuitId)
{
    return !(circuitId == 0);
}

void VCA::attenuate(int coefficient)
{
    int knobValue = readKnob();
    knobValue = knobValue * coefficient;
}

void VCA::inputPower(int amountOfPower)
{
    PowerUnit PSU0;
    if (amountOfPower < 20)
    {
        PSU0.getElectricity(2);
    }
}

int VCA::readKnob (int knobAngle)
{
    return knobAngle * 1000;
}

void HeadphoneAmp::getInput(int channelNum)
{
    DAC DACLeft, DACRight;
    for ( int i = 0; i < channelNum; i++ )
    {
        DACLeft.readInput(i);
        DACRight.readInput(i);
    }

}

void HeadphoneAmp::doAmp(int channelNum)
{
    VCA VCA0;
    //int output;
    for ( int i = 0; i < channelNum; i++ )
    {
        VCA0.attenuate(1);
    }

}

bool HeadphoneAmp::noiseReduction(int filterNum)
{
    return (filterNum == 1);
}

bool Body::checkTheBolt(int circuitId)
{
    //bool status;
    return (circuitId == 0);
}

bool Body::checkShortCircuit(int circuitId)
{
    //bool status;
    return (circuitId == 0);
}

void Body::alarmOverDust(float time)
{
    ++time;
}

void MonitorController::setVol(int amount)
{
    HeadphoneAmp ampLeft, ampRight;
    
    ampLeft.doAmp(amount);
    ampRight.doAmp(amount);
}

bool MonitorController::selectSource(int sourceNum, bool status)
{
    int inputSource = 0;
    
    if (inputSource != sourceNum || status == true)
    {
        inputSource = sourceNum;
    }
     
    return true;
}

bool MonitorController::toggleCrossfeed(bool status)
{
    bool crossFeedStatus = 0;
    
    if (crossFeedStatus != status)
    {
        crossFeedStatus = status;
    }
    
    return true;
} 

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */ 

#include <iostream>
int main()
{
    Example::main();
    Cat Pusya;
    SipProvider sipnet;
    SpaceShip Proton;
    PowerUnit powerunit;
    DAC dacLeft;
    
    std::cout << "\nSIP trunk status:" << std::endl;
    sipnet.printStatus ();
    
    std::cout << "\n";
    powerunit.printStatus();
    
    std::cout << "\nDAC status: " << dacLeft.checkError(440) << std::endl;
    
    
    std::cout << "\nShip status: \n" ;
    std::cout << ( Proton.dock()  ? "free fly" : "docked" ) << std::endl;
    
    std::cout << "\nCat attributes:" << "\n" 
    << "colour: " << Pusya.colour << "\n"
    << "age: " << Pusya.age << "\n"
    << "gender: "<< ( Pusya.gender == 0 ? "Girl" : "Boy" ) << std::endl;
    
    Pusya.mew (3);
    
    // fill balance
    sipnet.balance = 100;
    std::cout << "\nSIP trunk status:" << std::endl;
    sipnet.printStatus ();
    
    // dock the ship
    std::cout << "\nShip status:" ;
    Proton.orbitHeight = 40;
    std::cout << "\n" << ( Proton.dock()  ? "free fly" : "docked" ) << std::endl;
    //
    std::cout << "good to go!" << std::endl;
}
