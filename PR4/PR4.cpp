#include <iostream>
#include <vector>

using namespace std;

class Wheel
{
	float diametr;
public:
	Wheel(float diametr)
	{
		this->diametr = diametr;
	}
	float print() const
	{
		return diametr;
	}
};
class Engine
{
	float power;
public:
	Engine(float power)
	{
		this->power = power;
	}
	float print() const
	{
		return power;
	}
};

class Vehicle
{
public:
	virtual void print(std::ostream& out) const = 0;
	friend std::ostream& operator<< (std::ostream& out, const Vehicle& obj);
	virtual ~Vehicle() {};
};

std::ostream& operator<<(std::ostream& out, const Vehicle& obj)
{
	obj.print(out);
	return out;
}

class WaterVehicle :public Vehicle
{
	float osadka;
public:
	WaterVehicle(float os)
	{
		osadka = os;
	}
	virtual void print(std::ostream& out) const override
	{
		out<< "WaterVehicle " << " Ride height:" << osadka;
	}
	virtual ~WaterVehicle() { }
};
class RoadVehicle: public Vehicle
{
	float roadprosvet;
public:
	RoadVehicle(float raodpr)
	{
		roadprosvet = raodpr;
	}
	virtual void print(std::ostream& out) const override
	{
		out<< "Ride height:" << roadprosvet;
	}
	virtual ~RoadVehicle() {};
};

class Bicycle :public RoadVehicle
{
	Wheel wheels[2];
public:
	Bicycle(Wheel w1, Wheel w2, float prosv) : RoadVehicle(prosv), wheels{ w1,w2 } {};
	virtual void print(std::ostream& out) const override
	{
		out << "Bicycle ";
		out << "Wheels: ";
		for (int i = 0 ;i < 2 ; i++)
		{
			cout << wheels[i].print() << " ";
		}
		RoadVehicle::print(out);
	}
	virtual ~Bicycle() {};
};

class Car : public RoadVehicle
{
	Wheel wheels[4];
public:
	Engine engine;
	
	Car(Engine engine, Wheel w1, Wheel w2, Wheel w3, Wheel w4, float prosv) : RoadVehicle(prosv), engine(engine), wheels{ w1, w2, w3, w4 } {}
	virtual void print(std::ostream& out) const override
	{
		out << "Car ";
		out << "Engine: ";
		out << engine.print() << " ";
		out << "Wheels: ";
		for (int i = 0; i < 4; i++)
		{
			cout << wheels[i].print() << " ";
		}
		RoadVehicle::print(out);
	}
	virtual ~Car() {};
};



float getHighestPower(vector<Vehicle*>& v)
{
	float result=0;
		Car* tempel;
	for (const auto& temp : v)
	{
	tempel = dynamic_cast<Car*>(temp);
	if (tempel && tempel->engine.print() > result)
	{
		result = tempel->engine.print();
	}
	}
	return result;
}

int main()
{
	Car c(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 150);
	std::cout << c << '\n';

	Bicycle t(Wheel(20), Wheel(20), 300);
	std::cout << t << '\n';

	///////////////
	cout << endl;
	std::vector<Vehicle*> v;

	v.push_back(new Car(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 250));
	//v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Car(Engine(200), Wheel(19), Wheel(19), Wheel(19), Wheel(19), 130));
	v.push_back(new WaterVehicle(5000));

	for (const auto& temp : v)
	{
		cout << *temp << endl;
	}
	cout << endl;
	std::cout << "The highest power is " << getHighestPower(v) << '\n'; // реализуйте эту функцию

	for (auto elem : v) {
		delete elem;
	}
	v.clear();

	return 0;
}



