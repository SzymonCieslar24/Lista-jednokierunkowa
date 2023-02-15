#     PL     #
<b>Lista jednokierunkowa</b><br>
Implementacja listy jednokierunkowej jako szablon klasy bez użycia kontenerów STL. Program zawiera dwie dodatkowe klasy służące jako test stworzonego szablonu. 
Program uruchamiany jest z linii poleceń, wykorzystując odpowiednie przełączniki. Kompliację programu można przeprowadzić przykładową komendą: <br>
g++.exe -o dowolnanazwa.exe main.cpp <br>
Pierwsza klasa umożliwia na wczytanie danych z plików tekstowych zawierających informacje na temat rejestru samochodów. 
Zaimpelentowana klasa pozwala na wygenerowanie listy osób posiadających samochód danej marki.
Aby skorzystać z tej opcji niezbędne jest w trakcie uruchamiania programu użycie następujących przełączników: <br>
-inper plik wejściowy z opisem osób, <br>
-incar plik wejściowy z opisem samochodów, <br>
-inrel plik wejściowy z opisem relacji, <br>
-out plik wyjściowy z informacjami. <br>
Przykładowa komenda pozwalająca na uruchomienie programu jako rejestru samochodów: <br>
.\dowolnanazwa.exe -inper osoby.txt -incar samochody.txt -inrel relacje.txt -out odp.txt <br>
Załączone pliki tekstowe osoby.txt, samochody.txt oraz relacje.txt posiadają przykładowe dane oraz prezentują format prawidłowych danych, który umożliwia poprawne działanie programu.
Plik odp.txt jest plikiem zawierający listę osób posiadających samochód danej marki. Domyślną marką jest Audi, aby ją zmnnienić niezbędna jest zmiana kodu w pliku main.cpp w linii 52 na żądaną markę. <br>
Druga klasa umożwilia na wczytanie danych z plików zawierających informacje o uczniach oraz zdobywanych przez nich ocenach. Klasa pozwala na oblicznienie średniej ocen z danego przedmiotu oraz na wygenerowanie listy uczniów mieszkających na tej samej ulicy.
Aby skorzystać z programu jako dziennika lekcyjnego niezbędne jest w trakcie uruchamiania programu użycie następujących przełączników: <br>
-inper plik wejściowy z opisem osób, <br>
-insub plik wejściowy z opisem przedmiotów, <br>
-out plik wyjściowy z informacjami. <br>
Przykładowa komenda, którą można użyć aby skorzystać z dziennika lekcyjnego: <br>
.\dowolnanazwa.exe -inper uczniowie.txt -insub oceny.txt -out odp.txt <br>
Załączone pliki uczniowie.txt i oceny.txt są przykładowymi plikami powodującymi poprawne działanie programu.
Plik odp.txt jest plikiem wynikowym który informuje o średniej ocen z danego przedmiotu. Zawwiera on również listę uczniów mieszkających na tej samej ulicy. W celu zmienienia przedmiotu, z którego liczona będzie średnia potrzebna jest zmiana wartości domyślnej (fizyka) w pliku main.cpp w linii 27. Podobnie, aby zmienić ulicę oraz miasto, których wartości będą brane pod uwagę w tworzeniu listy uczniów mieszkających na tej samej ulicy potrzebna jest zmiana z wartości domyślnej (Akademicka) w linii 22 oraz w linii 23, w której znajduje się nazwa miasta, z którego będą uwzględniani uczniowie. Domyślnie miasto to przyjmuje wartość Gliwice. 

#     ENG     #
<b>Singly linked list</b><br>
Singly linked list implementation as a class template without using STL containers. The program contains two additional classes serving as a test of the created template. The program is launched from the command line using the appropriate switches. Compilation of the program can be carried out with an example command:
g++.exe -o somename.exe main.cpp <br>
The first class allows you to load data from text files containing information about the car register. The implemented class allows you to generate a list of people who own a car of a given brand. To use this option, it is necessary to use the following switches when starting the program: <br>
-inper input file with description of persons, <br>
-incar input file with description of cars, <br>
-inrel input file with description of relations, <br>
-out output file with informations. <br>
An example command that allows you to run the program as a car register: <br>
.\somename.exe -inper osoby.txt -incar samochody.txt -inrel relacje.txt -out odp.txt <br>
The attached text files osoby.txt, samochody.txt and relacje.txt contain sample data and present the correct data format that allows the program to work properly.
The odp.txt file is a file containing a list of people who own a car of a given brand. The default brand is Audi, to change it it is necessary to change the code in the main.cpp file on line 52 to the desired brand. <br>
The second class made it possible to load data from files containing information about students and their grades. The class allows you to calculate the average grade in a given subject and to generate a list of students living in the same street.
To use the program as a class diary, it is necessary to use the following switches when starting the program:
-inper input file with description of students, <br>
-insub input file with description of grades, <br>
-out output file with informations. <br>
An example command that can be used to use the lesson log: <br>
.\somename.exe -inper uczniowie.txt -insub oceny.txt -out odp.txt <br>
The attached files uczniowie.txt and grades.txt are examples of files that cause the correct operation of the program.
The odp.txt file is a result file that informs about the average grade for a given subject. It also contains a list of students living in the same street. In order to change the subject from which the average will be calculated, you need to change the default value (physics) in the main.cpp file on line 27. Similarly, to change the street and city whose values will be taken into in creating a list of students living on the same street you need to change from the default value (Akademicka) in line 22 and in line 23 which is the name of the city from which students will be included. By default, this city is set to Gliwice.
