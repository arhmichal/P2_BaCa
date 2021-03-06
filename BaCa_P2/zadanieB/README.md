# Programowanie 2 BaCa

[>>> BaCa zadanka <<<](https://p2.ii.uj.edu.pl/#ProblemsPanel)

| Zadanie | Start zadania | Termin oddania | Koniec zdania |
|---|:---|:---:|---:|
| B - Podprogramy [Szczegóły](https://p2.ii.uj.edu.pl/#ProblemDescription/2) [Statystyki](https://p2.ii.uj.edu.pl/#ProblemStatistics/2) [Treść](https://p2.ii.uj.edu.pl/#ProblemContent/2) [Wysyłanie](https://p2.ii.uj.edu.pl/#SendSubmit/2) | 2018-03-20 10:15:00 | 2018-03-27 10:15:00 | 2018-04-05 10:15:00 |
| [[link do treści](https://ww2.ii.uj.edu.pl/~kawa/intra/2017_2018_Programowanie_2/2017_2018_Programowanie_2_Zadanie_B.pdf)] ||||

# Treść Zadania

###### Instytut Informatyki i Matematyki Komputerowej UJ
###### Programowanie 2, semestr zimowy 2017/2018
### Zasanie B
### Podprogramy
#### Punktów do uzyskania: **8**
#### Język Programowania: C++
###### autor zadania: Rafał Kawa

* Zadanie polega na implementacji zbioru podprogramów zgodnych z poniższymi nagłówkami:
```c++
std::string Sum(int, const std::string*);
std::string Sum(int, ...);
void Sum(std::string*, int, const std::string*);
void Sum(std::string*, int, ...);
void Sum(std::string&, int, const std::string*);
void Sum(std::string&, int, ...);

std::string Mult(int, const std::string*);
std::string Mult(int, ...);
void Mult(std::string*, int, const std::string*);
void Mult(std::string*, int, ...);
void Mult(std::string&, int, const std::string*);
void Mult(std::string&, int, ...);

std::string Operation(std::string(*)(int, const std::string*), int, const std::string*);
std::string Operation(std::string(*)(int, const std::string*), int, ...);
void Operation(std::string*, std::string(*)(int, const std::string*), int, const std::string*);
void Operation(std::string*, std::string(*)(int, const std::string*), int, ...);
void Operation(std::string&, void(*)(std::string*, int, const std::string*), int, const std::string*);
void Operation(std::string&, void(*)(std::string*, int, const std::string*), int, ...);
```
* Podprogramy o nazwach ```Sum``` oraz ```Mult``` implementyją odpowiednio sumowanie oraz mnożenie dowolnie dużych liczb całkowitych w dowolnej dużej ilości, z argumentami i zwracanymi wartościami przekazywanymi w formie ciągów znakowych.
* Podprogramy o identyfikatorach ```Operation``` implementują możliwość zastosowania w pojedyńczym wywołaniu jednego z podprogramów ```Sum``` lub ```Mult``` przekazywanego w argumencie wraz z pozostałymi koniecznymi argumentami
* Ponadto:
  * Wartości zwracane przez podprogramy zawsze służą przekazaniu wyników działań.
  * Argumenty całkowite zawsze oznaczają ilość argumentów działań i wynoszą nie mniej niż 2.
  * Pierwsze argumenty wskaźnikowe lub referencyjne zawsze służą zwruceniu efektów działań.
  * Ostatnie argumenty wskaźnikowe służą przekazaniu liczb podlegających działaniom.
  * Argumenty adresowe podprogramów odnoszą się do istniejących podprogramów `Sum` lub `Mult`.
* W przekazywanym ba BaCę kodzie źródłowym nie jest możliwe włączenie jakichkolwiek plików, ale można założyć dostepność plików nagłówkowych `iostream`, `string`, `cstdarg`.
* Wysyłany na BaCę plik źródłowy z rozwiązaniem może byc dowolnym plikiem z rozszerzeniem `cpp`.
