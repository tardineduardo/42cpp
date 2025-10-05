#include "Bag.hpp"
#include "messages.hpp"

// canonic methods -------------------------------------------------------------

Bag::Bag() {
	m_bagctor();
    _items = new std::string[_k_nb_items];
}

Bag::Bag(const Bag &other) {
	m_bagcopy();
    _items = new std::string[_k_nb_items];	
	deepcopy(*this, other);
}

Bag &Bag::operator=(const Bag &other) {
	m_bagassg();
	delete[](_items);
    _items = new std::string[_k_nb_items];
	deepcopy(*this, other);
	return (*this);
}

Bag::~Bag() {
	delete[](_items);
	m_bagdtor();
}

//------------------------------------------------------------------------------

void Bag::deepcopy(Bag& dst, const Bag& src) {
	for(int i = 0; i < _k_nb_items; i++)
		dst._items[i] = src._items[i];
}

void	Bag::store_item(const int& index, const std::string& item) {
	if (index >= _k_nb_items)
		std::cout << YEL "⚠️  bag: invalid item index" RST << std::endl;
	else
		_items[index] = item;
}

void	Bag::show_items() {
	for(int i = 0; i < _k_nb_items; i++)
		if (_items[i] != "")
			std::cout << i << ". " << _items[i] << std::endl;
}

# define PNK	"\001\033[35m\002"
void m_bagctor(){std::cout << PNK "💼 bag default constructor called" RST << std::endl;}
void m_bagdtor(){std::cout << RED "💼 🗑️ bag destructor called" RST << std::endl;}
void m_bagcopy(){std::cout << PNK "💼 bag copy constructor called" RST << std::endl;}
void m_bagassg(){std::cout << PNK "💼 bag assignment operator called" RST << std::endl;}