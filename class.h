/**@file Plik nag³ówkowy zawieraj¹cy deklaracje klas.*/
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
    * Struktura jednej komórki listy jednokierunkowej. Posiada pole wartoœci oraz wskaŸnik na nastêpn¹ komórkê listy.
    */
    struct Node {
        T data;
        unique_ptr<Node> next;
        Node(T data, std::unique_ptr<Node> next = nullptr);
    };
    /**@brief
    * WskaŸnik na pierwszy element listy.
    */
    unique_ptr<Node> head;
public:
    /**@brief
    * Konstruktor bezargumentowy.
    */
    LinkedList();
    /**@brief
    * Konstruktor kopiuj¹cy.
    */
    LinkedList(const LinkedList<T>& other);
    /**@brief
    * Konstruktor przenosz¹cy.
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
    * Metoda dodawania do listy jednokierunkowej danej wartoœci przekazywanej jako argument.
    */
    void add(T data);
    /**@brief
    * Metoda zwracajaca liczbê elementów znajduj¹cych siê w liœcie jednokierunkowej.
    */
    int size();
    /**@brief
    * Metoda usuwania z listy jednokierunkowej danej wartoœci przekazywanej jako argument.
    */
    void remove(const T& data);
    /**@brief
    * Metoda s³u¿¹ca do wyœwietlenia  do listy jednokierunkowej danej wartoœci przekazywanej jako argument.
    */
    void print() const;
    /**@brief
    * Metoda s³u¿¹ca do sprawdzenia czy dana wartoœæ znajduje siê w liœcie jednokierunkowej.
    */
    bool search(const T& data);
    /**@brief
    * Metoda s³u¿¹ca do czy dana wartoœæ znajduje siê w liœcie. Dzia³a równie¿ z polami struktur co pozwala na sprawdzanie czy w liœcie znajdujê siê jakaœ struktura której wybrane pola s¹ równe wartoœci podanej jako argument.
    */
    template <typename F> T* search_data(F checker) const;
    /**@brief
    * Metoda s³u¿¹ca do sortowania listy jednokierunkowej. Wartoœæ 1 przekaazana jako argument powoduje posortowanie listy w kolejnoœci malej¹cej, a wartoœæ 2 soruje listê rosn¹co.
    */
    void sort(int type);
    /**@brief
    * Metoda s³u¿¹ca do zapisu listy jednokierunkowej do pliku.
    */
    void save_to_file(const string& filename);
    /**@brief
    * Metoda s³u¿¹ca do serializacji listy jednokierunkowej, czyli zapisu jej do pliku binarnego.
    */
    void serialize(const string& file_name);
    /**@brief
    * Metoda s³u¿¹ca do deserializacji listy jednokierunkowej, czyli odczytu jej z pliku bianarnego.
    */
    void deserialize_from_file(const std::string& file_name);
};
/**@brief
* Struktura opisuj¹ca osobê, poprzez PESEL (s³u¿¹cy jako identyfikator), imiê, nazwisko, datê urodzenia, ulicê, numer domu oraz miasto. Posiada zdefiniowane operatory ==, <<, >>.
*/
struct person {
    string PESEL, name, surname, birth, street, nr_house, city;
    person(string PESEL, string name, string surname, string birth, string street, string nr_house, string city);
    bool operator==(const person& other) const;
};
/**@brief
* Struktura s³u¿¹ca do opisu samochodu, który posiada numer identyfikacyjny, markê, model oraz rocznik. Posiada zdefiniowane operatory ==, <<, >>.
*/
struct car {
    int id;
    string company, model, year;
    car(int id, string company, string model, string year);
    bool operator==(const car& other) const;
};
/**@brief
* Struktura s³u¿¹ca do opisu relacji w³aœcicieli z samochodami poprzez identyfikatory. Posiada zdefiniowane operatory ==, <<, >>.
*/
struct relation {
    int id;
    string PESEL;
    relation(string PESEL, int id);
    bool operator==(const relation& other) const;

};
/**@brief
* Struktura opisuje oceny zdobywane przez uczniów. Posiada pola opisuj¹ce: PESEL, ocena, przedmiot oraz typ oceny. Posiada zdefiniowane operatory ==, <<, >>.
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
* Klasa s³u¿¹ca do stworzenia rejestru samochodów. Posiada trzy pola klasy, bêd¹ce listami jednokierunkowymi zawieraj¹cymi informacje o w³aœcicielach, samochodach oraz relacjach miêdzy w³aœcicielami a autami.
*/
class Register {
    LinkedList<person> l_persons;
    LinkedList<car> l_cars;
    LinkedList<relation> l_relations;
public:
    /**@brief
    * Metoda ta pozwala na odczyt danych z pliku, którego nazwa jest argumentem tej metody i zapis ich do listy. Zmienna type s³u¿y do wyboru listy do jakiej zapisaæ wczytane wartoœci. Przy wartoœci równej 1 dane wczytywane s¹ do listy zawieraj¹cej informacje o w³aœcicielach, dla wartoœci równej 2 do listy samochodów, a dla wartoœci 3 do listy relacji.
    */
    void read_data_from_file(const string& file_name, int type);
    /**@brief
    * Metoda zwraca listê osób posiadaj¹cych samochód danej marki, której nazwa jest argumentem.  
    */
    LinkedList<person> search_company(string name);
};
/**@brief
* Klasa s³u¿¹ca do stworzenia dziennika lekcyjnego. Posiada dwa pola klasy, bêd¹ce listami jednokierunkowymi zawieraj¹cymi informacje o uczniach oraz o zdobywanych przez nich ocenach.
*/
class Class_Diary {
    LinkedList<person> l_students;
    LinkedList<diary> l_grades;
public:
    /**@brief
    * Metoda ta pozwala na odczyt danych z pliku, którego nazwa jest argumentem tej metody i zapis ich do listy. Zmienna type s³u¿y do wyboru listy do jakiej zapisaæ wczytane wartoœci. Przy wartoœci równej 1 dane wczytywane s¹ do listy zawieraj¹cej informacje o uczniach, dla wartoœci równej 2 do listy informuj¹cej o ocenach, które zosta³y zdobyte przez uczniów.
    */
    void read_data_from_file(const string& file_name, int type);
    /**@brief
    * Metoda ta zwraca listê uczniów mieszkaj¹cych na tej samej ulicy w danym mieœcie. Nazwa ulicy oraz miasta, s¹ argumentami tej metody.
    */
    LinkedList<person> same_street(string search_street, string search_city);
    /**@brief
    * Metoda zwracaj¹ca obliczon¹ œredni¹ z ocen zdobywanych przez uczniów z danego przedmiotu, którego nazwa jest argumentem metody.  
    */
    double subject_average(string search_subject);
};
#endif
