class Product
{
public:
	virtual ~Product() {}
};

class ConcreteProduct_1
	: public Product
{
};

class ConcreteProduct_2
	: public Product
{
};


class AbstractFactory
{
public:
	virtual Product* CreateProduct_1() = 0;
	virtual Product* CreateProduct_2() = 0;
};

class ConcreteFactory
	: public AbstractFactory
{
	Product* CreateProduct_1() override { return new ConcreteProduct_1; }
	Product* CreateProduct_2() override { return new ConcreteProduct_2; }
	
};


class SomeOtherProduct_1
	: public Product
{};

class SomeOtherProduct_2
	: public Product
{};

class SomeOtherFactory
	: public AbstractFactory
{
	Product* CreateProduct_1() override { return new SomeOtherProduct_1; }
	Product* CreateProduct_2() override { return new SomeOtherProduct_2; }

};





void testFactory(AbstractFactory* factorio)
{

	Product* prodygi_1 = factorio->CreateProduct_1();
	Product* prodygi_2 = factorio->CreateProduct_2();

	delete prodygi_1;
	delete prodygi_2;
}


int main(void)
{
	AbstractFactory* concrete_fact = new ConcreteFactory;
	AbstractFactory* some_other_fact = new SomeOtherFactory;

	testFactory(concrete_fact);
	testFactory(some_other_fact);

	delete concrete_fact;
	delete some_other_fact;

	return 0;
}