#include <iostream>
#include <vector>
#include <string>

class Product{
private:
	std::string m_name;
	double m_price;
public:
	Product(const std::string &name, double price) : m_name(name), m_price(price){}

void display() const{
	std::cout<<m_name<<std::endl;
	std::cout<<m_price<<std::endl;
}

std::string  getName() const{
	return m_name;
}

double getPrice () const{
	return m_price;
}

void discount(double percent){
	m_price = m_price  - ((m_price * percent)/100);
}
};

class Cart{
private:
	std::vector<Product> products;
public:
	void add(const Product &product){
		products.push_back(product);
	}

	void remove(const std::string &name){
		for(size_t i = 0; i<products.size(); i++){
			if(products[i].getName() == name){
				products.erase(products.begin() + i);
				return;
			}
		}
	}
	
	void display() const{
		double total = 0;
		for(size_t i = 0; i<products.size(); i++){
			products[i].display();
			total +=products[i].getPrice();
	    }
		std::cout<<"Total price is"<<total<<std::endl;
	}

	void applyDiscount(double percent){
		for(size_t i = 0; i<products.size(); i++){
			products[i].discount(percent);
		}
	}
};

class Customer{
private:
	std::string m_name;
	 Cart m_cart;	
public:
	Customer(const std::string& name) : m_name(name) {}
	
	void addtoCart(const Product &product){
		m_cart.add(product);
	}

	void removefromCart(const std::string &name){
		m_cart.remove(name);
	}

	void applyDiscountToCart(double percent){
		m_cart.applyDiscount(percent);
	}

	void viewCart() const{
		std::cout<<m_name<<std::endl;
		m_cart.display();
	}
};
