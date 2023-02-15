/**@file Plik zawieraj¹cy fukcjê g³ówn¹ programu.*/
#include "class.cpp"

int main(int argc, char* argv[]) {
    std::string out_file, in_file_1, in_file_2, in_file_3;
    if (argc > 1) {
        if (argc == 7) {
            for (int i = 1; i < argc; i++) {
                std::string a = argv[i];
                if (a == "-inper" && argv[i + 1])
                    in_file_1 = argv[i + 1];
                else if (a == "-insub" && argv[i + 1])
                    in_file_2 = argv[i + 1];
                else if (a == "-out" && argv[i + 1])
                    out_file = argv[i + 1];
            }
            ofstream wyj(out_file, ios::app);
            Class_Diary d;
            d.read_data_from_file(in_file_1, 1);
            d.read_data_from_file(in_file_2, 2);
            LinkedList<person> list;
            string street = "Akademicka";
            string city = "Gliwice";
            list = d.same_street(street, city);
            d.read_data_from_file(in_file_1, 1);
            d.read_data_from_file(in_file_2, 2);
            string subject = "fizyka";
            double average = d.subject_average(subject);
            wyj << "Œrednia z przedmiotu " << subject << " wynosi:" << average << endl;
            wyj << "Lista osob mieszkaj¹cych na ulicy " << street << " w mieœcie " << city << ":" << endl;
            list.save_to_file(out_file);
            wyj.close();
        }
        else if (argc == 9) {
            for (int i = 1; i < argc; i++) {
                std::string a = argv[i];
                if (a == "-inper" && argv[i + 1])
                    in_file_1 = argv[i + 1];
                else if (a == "-incar" && argv[i + 1])
                    in_file_2 = argv[i + 1];
                else if (a == "-inrel" && argv[i + 1])
                    in_file_3 = argv[i + 1];
                else if (a == "-out" && argv[i + 1])
                    out_file = argv[i + 1];
            }
            ofstream wyj(out_file, ios::app);
            Register r;
            r.read_data_from_file(in_file_1, 1);
            r.read_data_from_file(in_file_2, 2);
            r.read_data_from_file(in_file_3, 3);
            LinkedList<person> list;
            list = r.search_company("Audi");
            list.save_to_file(out_file);
            wyj.close();
        }
        else
            std::cout << "Podaj wszystkie nazwy plikow" << std::endl;
    }
    else
        std::cout << "Aby uruchomic program w wierszu polecen uzyj odpowiednich przelacznikow" << std::endl;
    //TESTOWANIE SERIALIZACJI I DESERIALIZACJI
    //LinkedList<int> list;
    //list.add(1);
    //list.add(3);
    //list.add(2);
    //list.print();
    //list.serialize("test.txt");
    //LinkedList<int> list_2;
    //list_2.deserialize_from_file("test.txt");
    //cout << "----------" << endl;
    //list_2.print();
}