#include <iostream>

#pragma  region 工厂模式
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

#pragma region 策略模式
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

	return 0;
}
