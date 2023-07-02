#include <vector>
#include <iostream>


class Sensor {
public:
    virtual void measure() = 0;
    virtual double get_result() = 0;
//  virtual function = 0 <- means the function does not have implementation
//  PL:
//  virtual function = 0; to funkcja czyto-wirtualna
//  jeśli klasa ma min-jedną staje się klasą abstrakcyjną
//  - nie można tworzyć obiektów klas abstrakcyjnych;
//  - ale można tworzyć wskaźniki i referencje;
};

class TempSensor: public Sensor {
public:
    void measure() override;
    double get_result() override;
};

class PressureSensor: public Sensor {
public:
    void measure() override;
    double get_result() override;
};

class SensorManager {

    std::vector<Sensor *> sensors;
public:
    void info();
};

void SensorManager::info() {
    for (size_t i=0; i<sensors.size(); ++i) {
        sensors[i]->measure();
        std::cout<<sensors[i]->get_result()<<'\n';
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}