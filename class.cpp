/**@file Plik zawieraj¹cy definicje struktur oraz metod klas.*/
#include "class.h"

template <typename T>
LinkedList<T>::Node::Node(T data, std::unique_ptr<LinkedList<T>::Node> next) : data(std::move(data)), next(std::move(next)) {}

template <typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
}
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
	auto current = other.head.get();
	while (current != nullptr) {	
		add(current->data);
		current = current->next.get();
	}
}
template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& other) noexcept{
	head = std::move(other.head);
}
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T>&& other) {
	if (this == &other) {
		return *this;
	}
	head = std::move(other.head);
	return *this;
}
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T>& other) {
	if (this == &other) {
		return *this;
	}
	head.reset();
	auto current = other.head.get();
	while (current != nullptr) {
		add(current->data);
		current = current->next.get();
	}

	return *this;
}
template <typename T>
LinkedList<T>::~LinkedList() {}
template <typename T>
void LinkedList<T>::add(T data) {
	if (!head) {
		head = make_unique<Node>(data);
		return;
	}
	auto current = head.get();
	while (current->next) {
		current = current->next.get();
	}
	current->next = make_unique<Node>(data);
}
template <typename T>
int LinkedList<T>::size() {
	int count = 0;
	auto current = head.get();
	while (current != nullptr) {
		count++;
		current = current->next.get();
	}
	return count;
}
template <typename T>
void LinkedList<T>::remove(const T& data) {
	if (head->data == data) {
		head = std::move(head->next);
		return;
	}
	auto current = head.get();
	while (current->next != nullptr) {
		if (current->next->data == data) {
			current->next = std::move(current->next->next);
			return;
		}
		current = current->next.get();
	}
}
template <typename T>
void LinkedList<T>::print() const {
	auto current = head.get();
	while (current != nullptr) {
		std::cout << current->data << endl;
		current = current->next.get();
	}
}
template <typename T>
bool LinkedList<T>::search(const T& data) {
	auto current = head.get();
	while (current != nullptr) {
		if (current->data == data) {
			return true;
		}
		current = current->next.get();
	}
	return false;
}
template <typename T>
template <typename F>
T* LinkedList<T>::search_data(F checker) const {
	auto current = head.get();
	while (current != nullptr) {
		if (checker(current->data)) {
			return &current->data;
		}
		current = current->next.get();
	}
	return nullptr;
}
template <typename T>
void LinkedList<T>::sort(int type) {
	if (type == 1 or type == 2) {
		Node* current = head.get();	
		while (current) {
			Node* max = current;
			Node* before_max = nullptr;
			Node* temp = current;
			while (temp) {
				switch (type) {
				case 1: {
					if (temp->data >= max->data) {
						max = temp;
						before_max = current;
					}
					temp = temp->next.get();
					break;
				}
				case 2: {
					if (temp->data <= max->data) {
						max = temp;
						before_max = current;
					}
					temp = temp->next.get();
					break;					}
				}
			}
			if (before_max) {
				swap(before_max->data, max->data);
			}
			current = current->next.get();
		}
	}
	else
		cout << "Podaj rodzaj sortowania. 1 - malej¹co, 2 - rosn¹co" << endl;
}
template <typename T>
void LinkedList<T>::save_to_file(const string& filename) {
	ofstream file(filename, ios::app);
	auto current = head.get();	
	while (current != nullptr) {
		file << current->data << endl;
		current = current->next.get();
	}
	file.close();
}
template <typename T>
void LinkedList<T>::serialize(const string& file_name) {
	ofstream file(file_name, ios::binary);
	auto current = head.get();
	while (current != nullptr) {
		file.write(reinterpret_cast<const char*>(&current->data), sizeof(current->data));
		current = current->next.get();
	}
	file.close();
}
template <typename T>
void LinkedList<T>::deserialize_from_file(const string& file_name) {
	std::ifstream file(file_name, std::ios::binary);
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file " + file_name);
	}
	T data;
	while (file.read(reinterpret_cast<char*>(&data), sizeof(T))) {
		add(data);
	}
	file.close();
}
person::person(string PESEL, string name, string surname, string birth, string street, string nr_house, string city) : PESEL(PESEL), name(name), surname(surname), birth(birth), street(street), nr_house(nr_house), city(city) {}
bool person::operator==(const person& other) const {
	return PESEL == other.PESEL && name == other.name && surname == other.surname && birth == other.birth && street == other.street && nr_house == other.nr_house && city == other.city;
}
car::car(int id, string company, string model, string year) : id(id), company(company), model(model), year(year) {}
bool car::operator==(const car& other) const {
	return id == other.id && company == other.company && model == other.model && other.year == other.year;
}
relation::relation(string PESEL, int id) : PESEL(PESEL), id(id) {}
bool relation::operator==(const relation& other) const {
	return PESEL == other.PESEL && id == other.id;
}
diary::diary(string PESEL, string subject, double grade, string type) : PESEL(PESEL), subject(subject), grade(grade), type(type) {}
bool diary::operator==(const diary& other) const {
	return PESEL == other.PESEL && subject == other.subject && grade == other.grade && other.type == other.type;
}
ostream& operator<<(ostream& out, const person& o) {
	out << o.PESEL << " " << o.name << " " << o.surname << " " << o.birth << " " << o.street << " " << o.nr_house << " " << o.city;
	return out;
}
istream& operator>>(istream& is, person& o) {
	is >> o.PESEL >> o.name >> o.surname >> o.birth >> o.street >> o.nr_house >> o.city;
	return is;
}
ostream& operator<<(ostream& out, const car& s) {
	out << " " << s.id << " " << s.company << " " << s.model << " " << s.year;
	return out;
}
istream& operator>>(istream& is, car& s) {
	is >> s.id >> s.company >> s.model >> s.year;
	return is;
}
ostream& operator<<(ostream& out, const relation& r) {
	out << " " << r.PESEL << " " << r.id;
	return out;
}
istream& operator>>(istream& is, relation& r) {
	is >> r.PESEL >> r.id;
	return is;
}
ostream& operator<<(ostream& out, const diary& d) {
	out << " " << d.PESEL << " " << d.subject << " " << d.grade << " " << d.type;
	return out;
}
istream& operator>>(istream& is, diary& d) {
	is >> d.PESEL >> d.subject >> d.grade >> d.type;
	return is;
}
void Register::read_data_from_file(const string& file_name, int type) {
	ifstream file(file_name);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			switch (type) {
			case 1: {
				istringstream iss(line);
				string PESEL, name, surname, birth, street, nr_house, city;
				getline(iss, PESEL, ',');
				getline(iss, name, ',');
				getline(iss, surname, ',');
				getline(iss, birth, ',');
				getline(iss, street, ',');
				getline(iss, nr_house, ',');
				getline(iss, city);
				l_persons.add(person(PESEL, name, surname, birth, street, nr_house, city));
				break;
			}
			case 2: {
				istringstream iss(line);
				string str_id, company, model, year;
				getline(iss, str_id, ',');
				getline(iss, company, ',');
				getline(iss, model, ',');
				getline(iss, year);
				l_cars.add(car(stoi(str_id), company, model, year));
				break;
			}
			case 3: {
				istringstream iss(line);
				string PESEL, str_id;
				getline(iss, PESEL, ',');
				getline(iss, str_id);
				l_relations.add(relation(PESEL, stoi(str_id)));
				break;
			}
			}
		}
		file.close();
	}
}
LinkedList<person> Register::search_company(string name) {
	LinkedList<person>list;
	while (auto found = l_cars.search_data([&name](const car& s) { return s.company == name; })) {
		if (found != nullptr) {
			int searched_id = found->id;
			while (auto found_id = l_relations.search_data([&searched_id](const relation& r) { return r.id == searched_id; })) {
				if (found_id != nullptr) {
					string searched_PESEL = found_id->PESEL;
					while (auto found_PESEL = l_persons.search_data([&searched_PESEL](const person& o) { return o.PESEL == searched_PESEL; })) {
						if (found_PESEL != nullptr) {
							list.add(*found_PESEL);
						}
						l_persons.remove(*found_PESEL);
					}
				}
				l_relations.remove(*found_id);
			}
			l_cars.remove(*found);
		}
	}
	return list;
}
void Class_Diary::read_data_from_file(const string& file_name, int type) {
	ifstream file(file_name);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			switch (type) {
			case 1: {
				istringstream iss(line);
				string PESEL, name, surname, birth, street, nr_house, city;
				getline(iss, PESEL, ',');
				getline(iss, name, ',');
				getline(iss, surname, ',');
				getline(iss, birth, ',');
				getline(iss, street, ',');
				getline(iss, nr_house, ',');
				getline(iss, city);
				l_students.add(person(PESEL, name, surname, birth, street, nr_house, city));
				break;
			}
			case 2: {
				istringstream iss(line);
				string PESEL, str_grade, subject, type;
				getline(iss, PESEL, ',');
				getline(iss, subject, ',');
				getline(iss, str_grade, ',');
				getline(iss, type);
				l_grades.add(diary(PESEL, subject, stod(str_grade), type));
				break;
			}
			}
		}
		file.close();
	}
}
LinkedList<person> Class_Diary::same_street(string search_street, string search_city) {
	LinkedList<person>list;
	while (auto found = l_students.search_data([&search_street, &search_city](const person& o) { return o.street == search_street && o.city == search_city; })) {
		if (found != nullptr) {
			list.add(*found);
		}
		l_students.remove(*found);
	}
	return list;
}
double Class_Diary::subject_average(string search_subject) {
	int counter = 0;
	double average = 0;
	double sum = 0;
	while (auto found = l_grades.search_data([&search_subject](const diary& d) { return d.subject == search_subject; })) {
		if (found != nullptr) {
			double grade = found->grade;
			sum += grade;
			counter++;
		}
		l_grades.remove(*found);
	}
	average = sum / counter;
	return average;
}
