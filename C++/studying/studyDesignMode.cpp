#include <iostream>
#include <algorithm>
#include <mutex>

#pragma  region 1.工厂模式
typedef enum TankType
{
	Tank__99A,
	Tank__15S,
	Tank__T90,
	Tank__M12A
}Tank_type;

class Tank
{
public:
	virtual	std::string Type()const
	{
		return _Type;
	}
private:
	std::string _Type;
};

class Tank_99A :public Tank
{
public:
	Tank_99A() :_Type("tank_99a")
	{

	}
	std::string Type()const
	{
		return _Type;
	}
private:
	std::string _Type;
};

class Tank_15S :public Tank
{
public:
	Tank_15S() :_Type("tank_15s")
	{

	}

	std::string Type()const
	{
		return _Type;
	}
private:
	std::string _Type;
};

class Tank_T90 :public Tank
{
public:
	Tank_T90() :_Type("tank_t90")
	{

	}

	std::string Type()const
	{
		return _Type;
	}
private:
	std::string _Type;
};

class Tank_M12A :public Tank
{
public:
	Tank_M12A() :_Type("tank_m12a")
	{

	}

	std::string Type()const
	{
		return _Type;
	}
private:
	std::string _Type;
};

class TankFactory
{
public:
	Tank* CreateTank(TankType type)
	{
		switch (type)
		{
		case Tank__99A:
			return new Tank_99A();
			break;
		case Tank__15S:
			return new Tank_15S();
			break;
		case Tank__T90:
			return new Tank_T90();
			break;
		case Tank__M12A:
			return new Tank_M12A();
			break;
		default:
			return nullptr;
			break;
		}
	}
};
#pragma  endregion

#pragma region 2.策略模式
class Damage
{
public:
	virtual void Blood()
	{

	}
};

class DpsDamage :public Damage
{
public:
	void Blood()
	{
		std::cout << "Dps Damage has been done" << std::endl;
	}
};

class PowerDamage :public Damage
{
public:
	void Blood()
	{
		std::cout << "Power Damage has been done" << std::endl;
	}
};

class Soldier
{
public:
	Soldier(Damage* damage) :_damage(damage)
	{

	}

	void Attack()
	{
		_damage->Blood();
	}
private:
	Damage* _damage;
};

template<typename T>
class Archer
{
public:
	void Attack()
	{
		m_damage.Blood();
	}
private:
	T m_damage;
};
#pragma endregion 

#pragma region 3.适配器模式
//A类不满足需求,B类来继承A类,然后B类适配新需求,使用过多会导致系统非常凌乱
class Dequeue
{
public:
	virtual void Push_Back(int data)
	{
		std::cout << "Dequeue Push Back: " << data << std::endl;
	}
	virtual void Push_Front(int data)
	{
		std::cout << "Dequeue Push Front: " << data << std::endl;
	}
	virtual void Pop_Back()
	{
		std::cout << "Dequeue Pop Back" << std::endl;
	}
	virtual void Pop_Front()
	{
		std::cout << "Dequeue Pop Front" << std::endl;
	}
};

class Sequence
{
public:
	virtual void Push(int data)
	{

	}
	virtual void Pop()
	{

	}
};

//复合
#if 0
class Stack :public Sequence
{
public:
	void Push(int x)
	{
		dequeue.Push_Front(x);
	}
	void Pop()
	{
		dequeue.Pop_Front();
	}
private:
	Dequeue dequeue;
};

class Queue :public Sequence
{
public:
	void Push(int x)
	{
		dequeue.Push_Back(x);
	}
	void Pop()
	{
		dequeue.Pop_Front();
	}
private:
	Dequeue dequeue;
};
#endif

//继承
class Queue :public Sequence, private Dequeue
{
public:
	void Push(int x)
	{
		Push_Back(x);
	}
	void Pop()
	{
		Pop_Front();
	}
};

class Stack :public Sequence, private Dequeue
{
public:
	void Push(int x)
	{
		Push_Front(x);
	}
	void Pop()
	{
		Pop_Front();
	}
};

#pragma endregion

#pragma region 4.单例模式
std::mutex mutex;
//构造函数私有,不能实例化对象,不能通过拷贝构造函数,赋值运算等方法实例化对象
class Singleton
{
public:
	static Singleton* GetInstance();
	~Singleton() {};

	void Hello()
	{
		std::cout << "Singleton has been instantiated" << std::endl;
	}
private:
	Singleton() {};
	Singleton(const Singleton& obj) = delete;
	Singleton& opreator(const Singleton& obj) = delete;

	static Singleton* _singleton;
};

//懒汉模式,不到非要使用时不会实例化
#if 0
Singleton* Singleton::_singleton = nullptr;

Singleton* Singleton::GetInstance()
{
	if (_singleton == nullptr)
	{
		mutex.lock();
		Singleton::_singleton = new Singleton();
		mutex.unlock();
	}
	return _singleton;
}
#endif

//饿汉模式,定义的时候就实例化
Singleton* Singleton::_singleton = new Singleton();

Singleton* Singleton::GetInstance()
{
	return _singleton;
}
#pragma endregion

#pragma region 重载运算符_类模板
#include <vector>

template<typename T>
class MyModel
{
public:
	MyModel()
	{

	}

	void Insert(T x)
	{
		_list.push_back(x);
	}

	T operator[](const int& index)
	{
		return _list[index];
	}
private:
	std::vector<T> _list;
};
#pragma endregion

#pragma region 5.原型模式
class Clone
{
public:
	virtual Clone* clone()
	{
		return nullptr;
	}
	virtual void show()
	{

	}
};

class Sheep :public Clone
{
public:
	Sheep(std::string name, int age) :_name(name), _age(age)
	{
		std::cout << "Sheep() name address: " << &_name << std::endl;
		std::cout << "Sheep() age address: " << &_age << std::endl;
	}

	Sheep(const Sheep& obj)
	{
		this->_age = obj._age;
		this->_name = obj._name;

		std::cout << "Sheep(const Sheep& obj) name address: " << &_name << std::endl;
		std::cout << "Sheep(const Sheep& obj) age address: " << &_age << std::endl;
	}

	Clone* clone()
	{
		return new Sheep(*this);
	}

	void show()
	{
		std::cout << "name: " << _name << std::endl;
		std::cout << "age: " << _age << std::endl;
	}
private:
	std::string _name;
	int _age;
};
#pragma endregion

#pragma region 6.模板模式
class Computer
{
public:
	void Product()
	{
		InstallCpu();
		InstallGpu();
		InstallDisk();
	}
protected:
	virtual void InstallCpu()
	{

	}
	virtual void InstallGpu()
	{

	}
	virtual void InstallDisk()
	{

	}
};

class ComputerA :public Computer
{
public:
	void InstallCpu()
	{
		std::cout << "Inter Core i5" << std::endl;
	}

	void InstallGpu()
	{
		std::cout << "Nvdia GTX 1050Ti" << std::endl;
	}

	void InstallDisk()
	{
		std::cout << "SamSung 1T Disk" << std::endl;
	}
};

class ComputerB :public Computer
{
public:
	void InstallCpu()
	{
		std::cout << "Inter Core i7" << std::endl;
	}

	void InstallGpu()
	{
		std::cout << "Nvdia GTX 3090" << std::endl;
	}

	void InstallDisk()
	{
		std::cout << "SamSung 2T Disk" << std::endl;
	}
};
#pragma  endregion

#pragma region 7.外观模式
class Control
{
public:
	virtual void Start() = 0;
	virtual void ShutDown() = 0;
};

class Host :public Control
{
public:
	void Start()
	{
		std::cout << "Host Start" << std::endl;
	}
	void ShutDown()
	{
		std::cout << "Host ShutDown" << std::endl;
	}
};

class Display :public Control
{
public:
	void Start()
	{
		std::cout << "Display Start" << std::endl;
	}
	void ShutDown()
	{
		std::cout << "Display ShutDown" << std::endl;
	}
};

class Extention :public Control
{
public:
	void Start()
	{
		std::cout << "Extention Start" << std::endl;
	}
	void ShutDown()
	{
		std::cout << "Extention ShutDown" << std::endl;
	}
};

class Ex_Computer
{
public:
	void Start()
	{
		_host.Start();
		_display.Start();
		_extention.Start();
	}

	void ShutDown()
	{
		_host.ShutDown();
		_display.ShutDown();
		_extention.ShutDown();
	}
private:
	Host _host;
	Display _display;
	Extention _extention;
};
#pragma endregion

class Order
{
public:
	Order()
	{

	}

	const std::string& Food()
	{
		std::cout << m_food << std::endl;
		return m_food;
	}
	const std::string& Drink()
	{
		std::cout << m_drink << std::endl;
		return m_drink;
	}

	void SetOrderFood(std::string food)
	{
		m_food = food;
	}
	void SetOrderDrink(std::string drink)
	{
		m_drink = drink;
	}
private:
	std::string m_food;
	std::string m_drink;
};

class OrderBuilder :public Order
{
public:
	virtual ~OrderBuilder()
	{
		std::cout << "~OrderBuilder" << std::endl;
	};
	virtual void SetOrderDrink() = 0;
	virtual void SetOrderFood() = 0;
	virtual Order* GetOrder() = 0;
private:
	Order* m_order;
};

class VegetablesOrder :public OrderBuilder
{
public:
	VegetablesOrder() { m_order = new Order(); }

	~VegetablesOrder()
	{
		std::cout << "~VegetableOrder" << std::endl;
	}

	void SetOrderFood()
	{
		m_order->SetOrderFood("green vegetables");
	}
	void SetOrderDrink()
	{
		m_order->SetOrderDrink("nongfu spring");
	}
	Order* GetOrder()
	{
		return m_order;
	}
private:
	Order* m_order;
};

class MeatOrder :public OrderBuilder
{
public:
	MeatOrder() { m_order = new Order(); }

	~MeatOrder()
	{
		std::cout << "~MeatOrder" << std::endl;
	}

	void SetOrderFood()
	{
		m_order->SetOrderFood("chicken meat");
	}
	void SetOrderDrink()
	{
		m_order->SetOrderDrink("ganten bai sui shan");
	}
	Order* GetOrder()
	{
		return m_order;
	}
private:
	Order* m_order;
};

class Director
{
public:
	Director(OrderBuilder* builder) :m_builder(builder)
	{

	}

	void Construct()
	{
		m_builder->SetOrderDrink();
		m_builder->SetOrderFood();
	}
private:
	OrderBuilder* m_builder;
};

int main()
{
	TankFactory* factory = new TankFactory();

	std::cout << factory->CreateTank(Tank__15S)->Type() << std::endl;

	std::cout << factory->CreateTank(Tank__99A)->Type() << std::endl;

	std::cout << factory->CreateTank(Tank__T90)->Type() << std::endl;

	std::cout << factory->CreateTank(Tank__M12A)->Type() << std::endl;

	Soldier* soldier = new Soldier(new DpsDamage());
	soldier->Attack();

	Archer<PowerDamage>* archer = new Archer<PowerDamage>();
	archer->Attack();

	Stack* stack = new Stack();
	stack->Push(5);
	stack->Pop();

	Singleton::GetInstance()->Hello();

	MyModel<std::string> model;
	model.Insert("lubaobao");
	model.Insert("zuixihuan");
	model.Insert("fujunjun");

	std::cout << model[1] << std::endl;

	Clone* s1 = new Sheep("lubaobao", 18);
	s1->show();

	Clone* s2 = s1->clone();
	s2->show();

	Computer* ca = new ComputerA();
	ca->Product();

	Computer* cb = new ComputerB();
	cb->Product();

	Ex_Computer* ex_computer = new Ex_Computer();
	ex_computer->Start();
	ex_computer->ShutDown();

	int g_a = 5;

	[&g_a]
	{
		g_a++;
		std::cout << g_a << std::endl;
	}();

	std::cout << "now " << g_a << std::endl;

	std::vector<int> v = { 1,2,3,4,5 };
	for_each(v.begin(), v.end(), [](int& i) {std::cout << i << std::endl; });

	OrderBuilder* builder = new MeatOrder();
	Director* director = new Director(builder);

	director->Construct();

	Order* order = builder->GetOrder();
	order->Drink();
	order->Food();

	return 0;
}
