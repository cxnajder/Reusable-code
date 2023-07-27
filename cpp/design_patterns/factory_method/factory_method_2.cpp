class Product
{};

class ConcreteProduct
	: public Product
{};

class Creator
{
public:
	Creator() {}
	virtual Product* factoryMethod()
	{
		return new Product;
	}

	void assignProduct() {
		if (product != nullptr)
			delete product;
		product = factoryMethod();
	}

	virtual ~Creator()
	{
		if (product != nullptr)
			delete product;
	}

	Creator(const Creator&) = delete;
	Creator& operator=(const Creator&) = delete;
private:
	Product * product;
};


class ConcreteCreator
	: public Creator
{
public:
	Product* factoryMethod() override
	{
		return new ConcreteProduct;
	}
};


int main(void)
{
	Creator creat;
	creat.assignProduct();
	ConcreteCreator concreat;
	concreat.assignProduct();

	auto prod_ptr = creat.factoryMethod();
	delete prod_ptr;
	prod_ptr = concreat.factoryMethod();
	delete prod_ptr;

	return 0;
}