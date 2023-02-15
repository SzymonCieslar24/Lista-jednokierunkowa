/**@file Plik nag��wkowy zawieraj�cy deklaracje klas.*/
#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <sstream>
#include <utility>

using namespace std;
/**@brief
* Szablon Klasy listy jednokierunkowej
*/
template <typename T> 
class LinkedList {
private:
    /**@brief
    * Struktura jednej kom�rki listy jednokierunkowej. Posiada pole warto�ci oraz wska�nik na nast�pn� kom�rk� listy.
    */
    struct Node {
        T data;
        unique_ptr<Node> next;
        Node(T data, std::unique_ptr<Node> next = nullptr);
    };
    /**@brief
    * Wska�nik na pierwszy element listy.
    */
    unique_ptr<Node> head;
public:
    /**@brief
    * Konstruktor bezargumentowy.
    */
    LinkedList();
    /**@brief
    * Konstruktor kopiuj�cy.
    */
    LinkedList(const LinkedList<T>& other);
    /**@brief
    * Konstruktor przenosz�cy.
    */
    LinkedList(LinkedList<T>&& other) noexcept;
    /**@brief
    * Operator przypisania.
    */
    LinkedList<T>& operator=(const LinkedList<T>& other);
    /**@brief
    * Operator przeniesienia.
    */
    LinkedList<T>& operator=(LinkedList<T>&& other);
    /**@brief
    * Destuktor.
    */
    ~LinkedList();
    /**@brief
    * Metoda dodawania do listy jednokierunkowej danej warto�ci przekazywanej jako argument.
    */
    void add(T data);
    /**@brief
    * Metoda zwracajaca liczb� element�w znajduj�cych si� w li�cie jednokierunkowej.
    */
    int size();
    /**@brief
    * Metoda usuwania z listy jednokierunkowej danej warto�ci przekazywanej jako argument.
    */
    void remove(const T& data);
    /**@brief
    * Metoda s�u��ca do wy�wietlenia  do listy jednokierunkowej danej warto�ci przekazywanej jako argument.
    */
    void print() const;
    /**@brief
    * Metoda s�u��ca do sprawdzenia czy dana warto�� znajduje si� w li�cie jednokierunkowej.
    */
    bool search(const T& data);
    /**@brief
    * Metoda s�u��ca do czy dana warto�� znajduje si� w li�cie. Dzia�a r�wnie� z polami struktur co pozwala na sprawdzanie czy w li�cie znajduj� si� jaka� struktura kt�rej wybrane pola s� r�wne warto�ci podanej jako argument.
    */
    template <typename F> T* search_data(F checker) const;
    /**@brief
    * Metoda s�u��ca do sortowania listy jednokierunkowej. Warto�� 1 przekaazana jako argument powoduje posortowanie listy w kolejno�ci malej�cej, a warto�� 2 soruje list� rosn�co.
    */
    void sort(int type);
    /**@brief
    * Metoda s�u��ca do zapisu listy jednokierunkowej do pliku.
    */
    void save_to_file(const string& filename);
    /**@brief
    * Metoda s�u��ca do serializacji listy jednokierunkowej, czyli zapisu jej do pliku binarnego.
    */
    void serialize(const string& file_name);
    /**@brief
    * Metoda s�u��ca do deserializacji listy jednokierunkowej, czyli odczytu jej z pliku bianarnego.
    */
    void deserialize_from_file(const std::string& file_name);
};
/**@brief
* Struktura opisuj�ca osob�, poprzez PESEL (s�u��cy jako identyfikator), imi�, nazwisko, dat� urodzenia, ulic�, numer domu oraz miasto. Posiada zdefiniowane operatory ==, <<, >>.
*/
struct person {
    string PESEL, name, surname, birth, street, nr_house, city;
    person(string PESEL, string name, string surname, string birth, string street, string nr_house, string city);
    bool operator==(const person& other) const;
};
/**@brief
* Struktura s�u��ca do opisu samochodu, kt�ry posiada numer identyfikacyjny, mark�, model oraz rocznik. Posiada zdefiniowane operatory ==, <<, >>.
*/
struct car {
    int id;
    string company, model, year;
    car(int id, string company, string model, string year);
    bool operator==(const car& other) const;
};
/**@brief
* Struktura s�u��ca do opisu relacji w�a�cicieli z samochodami poprzez identyfikatory. Posiada zdefiniowane operatory ==, <<, >>.
*/
struct relation {
    int id;
    string PESEL;
    relation(string PESEL, int id);
    bool operator==(const relation& other) const;

};
/**@brief
* Struktura opisuje oceny zdobywane przez uczni�w. Posiada pola opisuj�ce: PESEL, ocena, przedmiot oraz typ oceny. Posiada zdefiniowane operatory ==, <<, >>.
*/
struct diary {
    double grade;
    string PESEL, subject, type;
    diary(string PESEL, string subject, double grade, string type);
    bool operator==(const diary& other) const;
};
ostream& operator<<(ostream& out, const person& o);
istream& operator>>(istream& is, person& o);
ostream& operator<<(ostream& out, const car& s);
istream& operator>>(istream& is, car& s);
ostream& operator<<(ostream& out, const relation& r);
istream& operator>>(istream& is, relation& r);
ostream& operator<<(ostream& out, const diary& d);
istream& operator>>(istream& is, diary& d);
/**@brief
* Klasa s�u��ca do stworzenia rejestru samochod�w. Posiada trzy pola klasy, b�d�ce listami jednokierunkowymi zawieraj�cymi informacje o w�a�cicielach, samochodach oraz relacjach mi�dzy w�a�cicielami a autami.
*/
class Register {
    LinkedList<person> l_persons;
    LinkedList<car> l_cars;
    LinkedList<relation> l_relations;
public:
    /**@brief
    * Metoda ta pozwala na odczyt danych z pliku, kt�rego nazwa jest argumentem tej metody i zapis ich do listy. Zmienna type s�u�y do wyboru listy do jakiej zapisa� wczytane warto�ci. Przy warto�ci r�wnej 1 dane wczytywane s� do listy zawieraj�cej informacje o w�a�cicielach, dla warto�ci r�wnej 2 do listy samochod�w, a dla warto�ci 3 do listy relacji.
    */
    void read_data_from_file(const string& file_name, int type);
    /**@brief
    * Metoda zwraca list� os�b posiadaj�cych samoch�d danej marki, kt�rej nazwa jest argumentem.  
    */
    LinkedList<person> search_company(string name);
};
/**@brief
* Klasa s�u��ca do stworzenia dziennika lekcyjnego. Posiada dwa pola klasy, b�d�ce listami jednokierunkowymi zawieraj�cymi informacje o uczniach oraz o zdobywanych przez nich ocenach.
*/
class Class_Diary {
    LinkedList<person> l_students;
    LinkedList<diary> l_grades;
public:
    /**@brief
    * Metoda ta pozwala na odczyt danych z pliku, kt�rego nazwa jest argumentem tej metody i zapis ich do listy. Zmienna type s�u�y do wyboru listy do jakiej zapisa� wczytane warto�ci. Przy warto�ci r�wnej 1 dane wczytywane s� do listy zawieraj�cej informacje o uczniach, dla warto�ci r�wnej 2 do listy informuj�cej o ocenach, kt�re zosta�y zdobyte przez uczni�w.
    */
    void read_data_from_file(const string& file_name, int type);
    /**@brief
    * Metoda ta zwraca list� uczni�w mieszkaj�cych na tej samej ulicy w danym mie�cie. Nazwa ulicy oraz miasta, s� argumentami tej metody.
    */
    LinkedList<person> same_street(string search_street, string search_city);
    /**@brief
    * Metoda zwracaj�ca obliczon� �redni� z ocen zdobywanych przez uczni�w z danego przedmiotu, kt�rego nazwa jest argumentem metody.  
    */
    double subject_average(string search_subject);
};
#endif
