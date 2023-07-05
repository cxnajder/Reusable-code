#include <memory>


class Coordinate;
class RouteStrategy;


class Map
{
    std::unique_ptr<RouteStrategy> routeFinder;
};



class RouteStrategy
{
public:
    virtual void findRout(Coordinate, Coordinate) = 0;
};



class CarRouteStrategy : public RouteStrategy
{
public:
    void findRout(Coordinate point_A, Coordinate point_B) override;
};


class BikeRouteStrategy : public RouteStrategy
{
public:
    void findRout(Coordinate point_A, Coordinate point_B) override;
};


class WalkRouteStrategy : public RouteStrategy
{
public:
    void findRout(Coordinate point_A, Coordinate point_B) override;
};
