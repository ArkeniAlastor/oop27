#include <iostream>
#include <string>
using namespace std;

class Car
{
protected:
	string bodymaterial;
	string color;
	double weight;
	double price;
public:
	Car(string bd, string col, double we, double pr)
		: bodymaterial(bd), color(col), weight(we), price(pr) {}

	virtual void Print()
	{
		cout << "Body material: " << bodymaterial << endl;
		cout << "Color: " << color << endl;
		cout << "Weight: " << weight << "Kg" << endl;
		cout << "Price: " << price << "$" << endl;
	}

	virtual string GetColor() const = 0;
	virtual int GetSpeed() const = 0;

};

class SportCar : public Car
{
protected:
	string brand;
	int passengers;
	double mileage;
	int speed;
	double fuel;
public:
	SportCar(string bd, string col, double we, double pr, string br, int pass, double mil, int sp, double f)
		: Car (bd, col, we, pr), brand(br), passengers(pass), mileage(mil), speed(sp), fuel(f) {}

	void Print()
	{
		Car::Print();
		cout << "Brand: " << brand << endl;
		cout << "Passengers: " << passengers << " persons" << endl;
		cout << "Mileage: " << mileage << " km/l" << endl;
		cout << "Speed: " << speed << "km/h" << endl;
		cout << "Fuel: " << fuel << " liters" << endl;
	}
};

class RetroCar : public Car
{
protected:
	string brand;
	int passengers;
	double mileage;
	int speed;
	double fuel;
	int year;
	string owner;
	bool hasRadio;
	double trunkCapacity;
	bool chromedTrim;
public:
	RetroCar(string bd, string col, double we, double pr,
		string br, int pass, double mil, int sp, double f,
		int yr, string own, bool radio, double trunk, bool chrome)
		: Car(bd, col, we, pr),
		brand(br), passengers(pass), mileage(mil), speed(sp), fuel(f),
		year(yr), owner(own), hasRadio(radio), trunkCapacity(trunk), chromedTrim(chrome) {}

	void Print()
	{
		Car::Print();
		cout << "Brand: " << brand << endl;
		cout << "Passengers: " << passengers << " persons" << endl;
		cout << "Mileage: " << mileage << " km/l" << endl;
		cout << "Speed: " << speed << " km/h" << endl;
		cout << "Fuel: " << fuel << " liters" << endl;
		cout << "Year: " << year << endl;
		cout << "Owner: " << owner << endl;
		cout << "Has radio: " << (hasRadio ? "Yes" : "No") << endl;
		cout << "Trunk capacity: " << trunkCapacity << " liters" << endl;
		cout << "Chromed trim: " << (chromedTrim ? "Yes" : "No") << endl;
	}

};

int main()
{
	Car* car = nullptr;

	int choice = 0;

	cout << "1. Car Sport" << endl;
	cout << "2. Car Retro" << endl;
	cout << "Make your choice: ";

	cin >> choice;

	switch (choice)
	{
	case 1:
		car = new SportCar("Aluminum", "Red", 1200, 35000.0, "Ferrari", 2, 12.5, 320, 60.0);
		break;
	case 2:
		car = new RetroCar("Steel", "Cream", 1500, 18000.0, "VW Beetle", 4, 8.0, 140, 50.0, 1967, "Ivan Petrov", true, 320.0, true);
		break;
	default:
		cout << "Invalid choice." << endl;
		return 1;
	}

	car->Print();

	delete car;
	return 0;
}