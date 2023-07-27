#include <memory>


class Coordinate;
class RouteStrategy;


class Map
{
    std::unique_ptr<RouteStrategy> routeFinder;

public:
    /*
     * there are 2 popular ways to inject strategy (set the RouteStrategy object)
     * 1)   Injection by constructor
     * 2)   Injection by setter
     */
    explicit Map(std::unique_ptr<RouteStrategy> &&routeFinder_ = {}) : routeFinder(std::move(routeFinder_)) {}

    void routeSetter(std::unique_ptr<RouteStrategy> &&routeFinder_)
    {
        routeFinder = std::move(routeFinder_);
    }
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
