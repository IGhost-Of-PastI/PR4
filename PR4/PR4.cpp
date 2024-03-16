#include <iostream>
#include <vector>

using namespace std;

class Vehicle
{
public:
	virtual void print(std::ostream& out) = 0;
	friend std::ostream& operator<< (std::ostream& out, const Vehicle& obj);
};

std::ostream& operator<<(std::ostream& out, const Vehicle& obj)
{
	// TODO: вставьте здесь оператор return
}

class WaterVehicle :Vehicle
{
	float osadka;
public:
	virtual void print(std::ostream& out) override
	{
		out << osadka;
	}
};
class RoadVehicle: public Vehicle
{
	float roadprosvet;
public:
	RoadVehicle(float raodpr)
	{
		roadprosvet = raodpr;
	}
	virtual void print(std::ostream& out) override
	{
		out << roadprosvet;
	}
};
class Wheel;
class Engine;
class Bicycle :public RoadVehicle
{
	Wheel wheels[2];
public:
	Bicycle(Wheel w1, Wheel w2, float prosv) : RoadVehicle(prosv), wheels{ w1,w2 } {};
};

class Car : public RoadVehicle
{
	Engine engine;
	Wheel wheels[4];
public:
	Car(Engine engine, Wheel w1, Wheel w2, Wheel w3, Wheel w4, float prosv) : RoadVehicle(prosv), engine(engine), wheels{ w1, w2, w3, w4 } {}
};

class Wheel
{
	float diametr;
public:
	Wheel(float diametr)
	{
		this->diametr = diametr;
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
};

int main()

{

	Car c(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 150);

	std::cout << c << '\n';



	Bicycle t(Wheel(20), Wheel(20), 300);

	std::cout << t << '\n';


	///////////////
	std::vector<Vehicle*> v;

	v.push_back(new Car(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 250));

	//v.push_back(new Circle(Point(1, 2, 3), 7));

	v.push_back(new Car(Engine(200), Wheel(19), Wheel(19), Wheel(19), Wheel(19), 130));

	v.push_back(new WaterVehicle(5000));



	//TODO: Вывод элементов вектора v здесь



	std::cout << "The highest power is" << getHighestPower(v) << '\n'; // реализуйте эту функцию



	//TODO: Удаление элементов вектора v здесь
	return 0;

}



//Производил следующий результат :
//
//Car Engine : 150 Wheels : 17 17 18 18 Ride height : 150
//
//Bicycle Wheels : 20 20 Ride height : 300
//
//
//
//Реализуйте функционал описанный в TODO следующего кода :


