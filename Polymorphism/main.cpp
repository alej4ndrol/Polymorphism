//Реализовать программу демонстрирующую предметную область "Пиццерия"
//
//Заказ - это список из выбранных пользователем пицц.
//
//Пицца - это блюдо, которое выбирает пользователь.Пицца обладает именем(текст), описанием(текст), размером(один из вариантов 25, 30, 35, 40, который выбирает пользователь), ценой(зависит от размера выбранной пиццы и ингредиентов).Пользователь может подсолить любую пиццу N - раз или добавить сыра M - раз - это увеличивает цену в зависимости от вида и размера пиццы(формулу придумать на ваше усмотрение)
//
//Заказ - формируется пользователем через консоль, возможность добавить пиццу, распечатать заказ в консоль.
//
//Печать заказа - вывод всего списка выбранных пользователем пицц, с указанием названия, описания, N - соли и M - сыра, размера пиццы и стоимости пиццы с учётом всех параметров
//
//В конце распечатанного заказа вывести итоговую сумму за заказ
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pizza {
protected:
	string name;
	string description;
	int size;
	int price;
	int count_of_salt;
	int count_of_cheese;
	int base_price;

public:
	Pizza(int size) {
		count_of_salt = 0;
		count_of_cheese = 0;

		switch (size) {
		case 25:
			this->size = 25;
			break;
		case 30:
			this->size = 30;
			break;
		case 35:
			this->size = 35;
			break;
		case 40:
			this->size = 40;
			break;
		default:
			cout << "Wrong size, standart pizza(25) added" << endl;
			this->size = 25;
			break;
		}
		//price = base_price * this->size;
		price = 10 * this->size;
	}
	void add_salt() {
		cout << "How much salt do you want to add to your pizza? (0,1,2,...)" << endl;
		cin >> count_of_salt;
		price += count_of_salt * 1;
	}

	void add_cheese() {
		cout << "How much cheese do you want to add to your pizza? (0,1,2,...)" << endl;
		cin >> count_of_cheese;
		price += count_of_cheese * 5;
	}

	int get_price() {
		return price;
	}

	void get_full_name(bool to_menu) {
		cout << "Pizza: '" << name << "'" << endl
			<< "	Desc: " << description << endl;
		if (!to_menu)
		{
			cout << "	Size: " << size << endl
				<< "	Salt: " << count_of_salt << endl
				<< "	Cheese: " << count_of_cheese << endl;
		}
		cout << "	Price: " << price << " RUB" << endl;
	}
};

class Pizza_1 : public Pizza {
public:
	Pizza_1(int size) : Pizza(size) {
		name = "Pizza_1";
		description = "good pizza_1";
		price += 10 * this->size;
		//base_price = 10;
	}
};

class Pizza_2 : public Pizza {
public:
	Pizza_2(int size) : Pizza(size) {
		name = "Pizza_2";
		description = "very good pizza_2";
		price += 20 * this->size;
		//base_price = 20;
	}
};

class Pizza_3 : public Pizza {
public:
	Pizza_3(int size) : Pizza(size) {
		name = "Pizza_3";
		description = "very very good pizza_3";
		price += 30 * this->size;
		//base_price = 20;
	}
};

class Pizza_4 : public Pizza {
public:
	Pizza_4(int size) : Pizza(size) {
		name = "Pizza_4";
		description = "very very very good pizza_4";
		price += 40 * this->size;
		//base_price = 20;
	}
};

class Order {
private:
	vector<Pizza> pizzas;
	int total_price;

public:
	Order() {
		total_price = 0;
	}

	void add_pizza(Pizza pizza_name) {
		pizza_name.add_salt();
		pizza_name.add_cheese();
		pizzas.push_back(pizza_name);
		total_price += pizza_name.get_price();
	}

	void print_menu() {
		cout << endl << "Menu: " << endl;
		Pizza_1 pizza_1(25);
		pizzas.push_back(pizza_1);
		Pizza_2 pizza_2(25);
		pizzas.push_back(pizza_2);
		Pizza_3 pizza_3(25);
		pizzas.push_back(pizza_3);
		Pizza_4 pizza_4(25);
		pizzas.push_back(pizza_4);
		for (size_t i = 0; i < pizzas.size(); i++)
		{
			cout << endl << i << ". " << endl;
			pizzas[i].get_full_name(true);
		}
		pizzas.clear();
	}

	void print_order() {
		if (pizzas.size() != 0) {
			cout << "Your order: " << endl;
			for (size_t i = 0; i < pizzas.size(); i++)
			{
				cout << i << ". ";
				pizzas[i].get_full_name(false);
			}
		}
		else
		{
			cout << "Your order is empty.";
		}
		cout << "Total price: " << total_price;
	}
};

int main() {

	Order pepe;
	int size;
	int type_of_pizza;
	string ans = "";
	cout << "Add your first pizza to order" << endl;
	pepe.print_menu();
	do {
		cout << "Please, enter the type of pizza(0-3) and its size(25,30,35,40)" << endl;
		cin >> type_of_pizza >> size;
		switch (type_of_pizza) {
		case 0: {
			Pizza_1 pizza_1(size);
			pepe.add_pizza(pizza_1);
		}  break;

		case 1: {
			Pizza_2 pizza_2(size);
			pepe.add_pizza(pizza_2);
		}  break;
		case 2: {
			Pizza_2 pizza_3(size);
			pepe.add_pizza(pizza_3);
		}  break;
		case 3: {
			Pizza_2 pizza_4(size);
			pepe.add_pizza(pizza_4);
		}  break;
		}
		cout << "Do you want to add another pizza to order? (y/n)" << endl;
		cin >> ans;
	} while (ans == "y");

	pepe.print_order();

	return 0;
}