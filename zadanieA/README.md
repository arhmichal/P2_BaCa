# A - Operacje zbiorowe
[Szczegóły](https://p2.ii.uj.edu.pl/#ProblemDescription/1)
[Statystyki](https://p2.ii.uj.edu.pl/#ProblemStatistics/1)
[Treść](https://p2.ii.uj.edu.pl/#ProblemContent/1)
[Wysyłanie](https://p2.ii.uj.edu.pl/#SendSubmit/1)

[poprawiony link do treści](https://ww2.ii.uj.edu.pl/~kawa/intra/2017_2018_Programowanie_2/2017_2018_Programowanie_2_Zadanie_A.pdf)



#treść

###### Instytut Informatyki i Matematyki Komputerowej UJ
###### Programowanie 2, semestr zimowy 2017/2018
### Zasanie A
### Operacje ziorowe
#### Punktów do uzyskania: **10**
#### Język Programowania: C++
###### autor zadania: Rafał Kawa

### Generalia
* Zadanie polega na implementacji podprogramów obsługujących operacje na zbiorach obejmujących pięcioelementowe ciągi znaków 0 lub 1 nazywanych dalej prosto *zbiorami*.
* kod rozwiązania nie może stosować:
    - znaków kwadratowych nawiasów i ich równowarzników.
    - słów kluczowych pętli, czyli **for** , **while** oraz **goto**.
    - rekordów, czyli słów kluczowych **struct** oraz **class**.
    - znaków operatorów + oraz -.
    - poleceń obsługi pamięci dynamicznej.
    - typów własnych zmiennych innych niż **int**
    - własnych identyfikatorów zaczynających się od znaku podkreślenia.
    - kontenerów i ogólnie szablonów
* w wybranych podprogramach stosowany będzie porządek zbiorów w oparciu o regóły:
    - zbiór o większej liczności jest zawsze większy od zbioru o mniejszej liczności.
    - dla zbiorów o równej liczności zbiór poprzedzający w odwrotnej kolejności leksykograficznej elementów jest większy od zbioru następującego.

### Podprogramy wymagane w tym rozwiązaniu
```c++
void Emplace(string, int*);
```
- na podstawie spujnych pięcioelementowych sekwencji znaków 0 lub 1 zawartych w ciągu znakowym przekazywanym pierwszym argumentem wyznaczany jest według własnej implementacji zbiór, z adresem określenia zbioru przekazywanym drugim argumentem.
- ciąg znakowy przekazywany pierwszym argumentem jest dowolnie długi, obejmuje wyłącznie znaki 0, znaki 1 lub znak spacji, ale znaki 0 oraz 1 zawsze występują w pięcioelementowych spójnych sekwencjach.
```c++
void Insert(string, int*);
```
- pięcioelementowe spójne sekwencje znaków 0 lub 1 zawarte w ciągu znakowym przekazywanym pierwszym argumentem określają elementy dodawane do własnej implementacji zbioru, którego adres określania jest przekazywany drugim argumentem.
- warunki ciągu znakowego są identyczne jak dla procedury ```Emplace```.
```c++
void Erase(string, int*);
```
- pięcioelementowe spójne sekwencje znaków 0 lub 1 zawarte w ciągu znakowym przekazywanym pierwszym argumentem wyznaczają elementy usówane z własnej implementacji zbioru o adresie określania przekazywanym drugim argumentem.
- warunki ciągu znakowego są identyczne jak dla procedury ```Emplace``` oraz ```Insert```.
```c++
void Print(int, string*);
```
- zawartość zbioru określonego pierwszym argumentem jest przekazywana do ciągu znakowego o adresie danym drugim argumentem.
- elementy zbioru muszą być opisane pięcioelementową sekwencją znaków 0 lub 1 z następującą spacją.
kolejnością wypisywanych elementów jest malejąca kolejność lejsykograficzna elementów zbioru.
- zbiór pusty jest opisany słowem **empty**
```c++
bool Emptiness(int);
```
- wartościuje logicznie pustość zbioru określonego argumentem.
```c++
bool Nonempty(int);
```
- wartościuje logicznie niepustość zbioru określonego argumentem.
```c++
bool Member(string, int);
```
- wartościuje logicznie zawieranie elementu określonego pojedynczą spójną pięcioelementową sekwencją znaków 0 lub 1 zawartą w ciągu znakowym przekazywanym pierwszym argumentem w zbiorze określonym drugim argumentem.
- ciąg znakowy oprócz dowolnej ilości spacji, zawiera dokładnie jedną pięcioelementową sekwencję znaków 0 lub 1.
```c++
bool Disjoint(int, int);
```
- wartościuje logicznie rozłączność zbiorów okreslonych argumentami.
```c++
bool Conjunctive(int, int);
```
- wartościuje logicznie niepustość przecięcia zbiorów okreslonych argumentami.
```c++
bool Equality(int, int);
```
- wartościuje logicznie równość zbiorów okreslonych argumentami.
```c++
bool Inclusion(int, int);
```
- wartościuje logicznie zawieranie zbioru określonego pierwszym argumentem w zbiorze określonym drugim argumentem.
```c++
void Union(int, int, int*);
```
- sumę mnogościową zbiorów określonych dwoma pierwszymi argumentami przekazuje do zbioru o adresie określenia danym trzecim argumentem.
```c++
void Intersection(int, int, int*);
```
- iloczyn mnogościowy zbiorów określonych dwoma pierwszymi argumentami przekazuje do zbioru o adresie określenia danym trzecim argumentem.
```c++
void Symmetric(int, int, int*);
```
- różnicę symetryczną zbiorów określonych dwoma pierwszymi argumentami przekazuje do zbioru o adresie określenia danym trzecim argumentem.
```c++
void Difference(int, int, int*);
```
- różnicę mnogościową zbioru określonego pierwszym argumentem i zbioru określonego drugim argumentem przekazuje do zbioru o adresie określenia danym trzecim argumentem.
```c++
void Complement(int, int*);
```
- dopełnienie mnogościowe zbioru określonego pierwszym argumentem przekazuje do zbioru o adresie określenia danym drugim argumentem.
```c++
bool LessThen(int, int);
```
- wartościuje logicznie silną mniejszość zbioru określonego pierwszym argumentem względem zbioru określonego drugim argumentem.
```c++
bool LessEqual(int, int);
```
- wartościuje logicznie słabą mniejszość zbioru określonego pierwszym argumentem względem zbioru określonego drugim argumentem.
```c++
bool GreatEqual(int, int);
```
- wartościuje logicznie słabą większość zbioru określonego pierwszym argumentem względem zbioru określonego drugim argumentem.
```c++
bool GreatThen(int, int);
```
- wartościuje logicznie silną większość zbioru określonego pierwszym argumentem względem zbioru określonego drugim argumentem.

### Uzupełnienie
- w rozwiązaniu zabronione jest włączanie jakichkolwiek plików, jednakże można załorzyć dostępność plików nagłówkowych ```iostream```, ```string``` oraz ```sstream```.
- jedynymi podprogramami dopuszczającymi użycie typu ```string``` są podprogramy ```Emplace```, ```Insert```, ```Erase```, ```Print``` oraz ```Mamber```.
- jedynymi dopuszczalnymi metodami zmiennych typu ```string``` są metody ```at``` oraz ```length```.
- jedynymi podprogramami dopuszczającymi użycie typu ```sstream``` jest procedura ```Print```.
- jedynyą dopuszczalną metodą zmiennych typu ```sstream``` jest metoda ```str```.
- rozwiązanie musi być zamieszczone w pliku o rozszerzeniu ```cpp``` i w pierwszej linii zawierać komentarz z imieniem i nazwiskiem autora.
