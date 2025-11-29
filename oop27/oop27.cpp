#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
	string bodymaterial;
	string color;
	double weight;
	double price;
public:
	Car(string bd, string col, double we, double pr)
		: bodymaterial(bd), color(col), weight(we), price(pr) {}

	void Print()
	{
		cout << "Body material: " << bodymaterial << endl;
		cout << "Color: " << color << endl;
		cout << "Weight: " << weight << "Kg" << endl;
		cout << "Price: " << price << "$" << endl;
	}

};

class SportCar : public Car
{
private:
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

int main()
{
	Car* car = nullptr;

	int choice = 0;

	cout << "1. Car Sport" << endl;
	cout << "Make your choice: ";

	cin >> choice;

	switch (choice)
	{
	case 1:
		car = new SportCar("Aluminum", "Red", 1200, 35000.0, "Ferrari", 2, 12.5, 320, 60.0);
		break;
	default:
		cout << "Invalid choice." << endl;
		return 1;
	}

	car->Print();

	delete car;
	return 0;
}