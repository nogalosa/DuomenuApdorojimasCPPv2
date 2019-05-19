Duomenu Apdorojimas
===================

[![Commit activity](https://img.shields.io/github/commit-activity/w/nogalosa/DuomenuApdorojimasCPPv2.svg)](https://github.com/nogalosa/DuomenuApdorojimasCPP/commits/master)
[![Last commit](https://img.shields.io/github/last-commit/nogalosa/DuomenuApdorojimasCPPv2.svg)](https://github.com/nogalosa/DuomenuApdorojimasCPP/commits/master)
[![Repo size](https://img.shields.io/github/repo-size/nogalosa/DuomenuApdorojimasCPPv2.svg)](https://github.com/nogalosa/DuomenuApdorojimasCPP/commits/master)
[![Release](https://img.shields.io/github/release/nogalosa/DuomenuApdorojimasCPPv2.svg)](https://github.com/nogalosa/DuomenuApdorojimasCPP/commits/master)

Pagal [/objprog/paskaitos2019/wiki/2-oji-užduotis](https://github.com/objprog/paskaitos2019/wiki/2-oji-u%C5%BEduotis) atliekama užduotis.

___

### Running the program
* Compile program with cmake using CMakeLists.txt file;
* If you want to load data from file, create kursiokai.txt with information you want to input and place it in the same directory as launch file. File ex.:
```
Pavardė     Vardas      ND1  ND2   ND3  ND4  ND5  Egzaminas
Vardas1     Zavardė1    8    9     10   6    10   9
Vardas2     Aavardė2    7    10    8    5    4    6
Vardas2     Pavardė2    7    10    8    5    4    6
```
* Run the program.

___

### Using the program

The program displays a menu when opened.
You can:
1. Ivesti nauja studenta;
2. Suskaiciuoti galutinius balus (su vidurkiu);
3. Suskaiciuoti galutinius balus (su mediana);
4. Pergeneruoti visu ivestu studentu namu darbu balus i atsitiktinius;
5. Ivesti studentu informacija is kursiokai.txt failo;
6. Sugeneruoti tam tikra skaiciu studentu, juos ikelti i programa ir isaugoti failuose;

How many students are added to `users` vector on sixth menu selection depends on selected strategy.

___

### Changelog

__v2.0 Changelog:__
* Added documentation (doxygen);
* Unit testing with Catch in `main_tests` class.

__v1.5 Changelog:__
* Studentas class now has base class called Asmuo.

__v1.2 Changelog:__
* Added deconstructor and two object copy methods (with `=` operator and constructor) for Studentas class.

__v1.1 Changelog:__
* Remade Studentas structure to class;
* Now using getters and setters to manipulate data;
* Benchmarked with `O1`, `O2`, `O3` flags and compared to last release. 

__Additional Task Changelog:__
* Added Additional Task generation strategy with `raskMinkstus()` and `iterpkKietus()` functions;
* Benchmarked it with vector and deque containers.

__v1.0 Changelog:__
* Remade Deque system to Vector system;
* Updated random number generation method;
* Added code optimization strategy with remove_if;
* Added benchmark results to README.md.

__v0.5.1 Changelog:__
* Added exception throwing.

__v0.5 Changelog:__
* Remade Vector system to List system and then to Deque system;
* Benchmarked execution time of sorting algorythms of each container.

__v0.4.2 Changelog:__
* Added exception throwing.

__v0.4.1 Changelog:__
* Added benchmark results to README.md.

__v0.4 Changelog:__
* Added random student generator;
* Added chrono benchmark information.

__v0.3.1 Changelog:__
* Added exception throwing.

__v0.3 Changelog:__
* Added header file;
* Integrated exception handling for file loading;
* Input checking.

__v0.2 Changelog:__
* Added information loading from kursiokai.txt file;
* Output is now ordered alphabetically;
* Fixed few major and minor bugs in code.

__v0.1 Changelog:__
* Initial release.

___

### Benchmarks

__v1.1 Benchmarks:__

1 000 students generation time in seconds. (Time is benchmarked with writing to file to compare with previous benchmarks)

| Type \ Strategy | 1 | 2 | 3 |
| :---: | :---: | :---: | :---: |
| Structure | 0.139039 | 0.219113 | 0.318443 |
| Class | 0.198103 | 0.182019 | 0.282342 |
| Class (-O1) | 0.182106 | 0.176346 | 0.274062 |
| Class (-O2) | 0.189386 | 0.180225 | 0.280019 |
| Class (-O3) | 0.182609 | 0.179780 | 0.282350 |

#### Older benchmarks (up to v1.0)

__Additional Task Benchmarks:__

Results show how much time (seconds) did `raskMinkstus()` and `iterpkKietus()` functions take to execute.

| Type \ Student count | 10 000 | 100 000 |
| :---: | :---: | :---: |
| Vector | 26.5866 / 0.0856295 | 1911.1 / 0.894586 |
| Deque | 8.2786 / 0.241168 | 798.89 / 2.62829 |

__v1.0 Benchmarks:__

1 000 students generation time in seconds. First strategy puts every student to main `users` vector and to vectors called `nuskriaustukai` and `galvociai` depending on what marks do they get. Second strategy puts students with better marks to `users` vector, and with lower marks directly to `nuskriaustukai` vector. The third strategy puts students directly to `users` array and after that it is sorted to `users` and `nuskriaustukai` depending on their marks.

| Type \ Strategy | 1 | 2 | 3 (optimized with remove_if) |
| :---: | :---: | :---: | :---: |
| Vector | 0.139039 | 0.219113 | 0.318443 |
| List | 0.176289 | 0.209452 | - |
| Deque | 0.381602 | 0.199127 | - |

__v0.5 Benchmarks:__

Used a file containing 1000 students info. Measured sorting time.

| Num. of students | Type | Execution time (s.) |
| :---: | :---: | :---: |
| 1 000 | Vector (from file) | 0.0051633 |
| 1 000 | List (from file) | 0.0072464 |
| 1 000 | Deque (from file) | 0.0083684 |

__v0.4 Benchmarks:__

Measured file generation time and execution (sorting) time in seconds.

| Num. of students | Generation time (s.) | Execution time (s.) | Total (s.) |
| :---: | :---: | :---: | :---: |
| 10 | 0.0077851 | 0.0002216 | 0.0080067 |
| 100 | 0.0141137 | 0.0029147 | 0.0170284 |
| 1 000 | 0.480815 | 0.0179601 | 0.4987751 |
| 10 000 | 0.95279 | 0.184916 | 1.137706 |
| 100 000 | 9.47004 | 1.90153 | 11.37157 |