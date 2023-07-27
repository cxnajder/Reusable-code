class Product
{};

class ConcreteProduct
	: public Product
{};

class Creator
{
public:
	Creator() {}
	virtual void factoryMethod()
	{
		if (product != nullptr)
			delete product;
		product = new Product;
	}
	virtual ~Creator()
	{
		if (product != nullptr)
			delete product;
	}
	Creator(const Creator&) = delete;
	Creator& operator=(const Creator&) = delete;
protected:
	Product * product;
};

class ConcreteCreator
	: public Creator
{
public:
	void factoryMethod() override
	{
		if (product != nullptr)
			delete product;
		product = new ConcreteProduct;
	}
};

int main(void)
{
	Creator creat;
	creat.factoryMethod();
	ConcreteCreator concreat;
	concreat.factoryMethod();
	return 0;
}