Duomenu Apdorojimas
===================

[![Commit activity](https://img.shields.io/github/commit-activity/w/nogalosa/DuomenuApdorojimasCPP.svg)](https://github.com/nogalosa/DuomenuApdorojimasCPP/commits/master)
[![Last commit](https://img.shields.io/github/last-commit/nogalosa/DuomenuApdorojimasCPP.svg)](https://github.com/nogalosa/DuomenuApdorojimasCPP/commits/master)
[![Repo size](https://img.shields.io/github/repo-size/nogalosa/DuomenuApdorojimasCPP.svg)](https://github.com/nogalosa/DuomenuApdorojimasCPP/commits/master)
[![Release](https://img.shields.io/github/release/nogalosa/DuomenuApdorojimasCPP.svg)](https://github.com/nogalosa/DuomenuApdorojimasCPP/commits/master)

Pagal [/objprog/paskaitos2019/wiki/2-oji-užduotis](https://github.com/objprog/paskaitos2019/wiki/2-oji-u%C5%BEduotis) atliekama užduotis.

__How to run:__
* Compile program with cmake using CMakeLists.txt file;
* If you want to load data from file, create kursiokai.txt with information you want to input and place it in the same directory as launch file. File ex.:
```
Pavardė     Vardas      ND1  ND2   ND3  ND4  ND5  Egzaminas
Vardas1     Zavardė1    8    9     10   6    10   9
Vardas2     Aavardė2    7    10    8    5    4    6
Vardas2     Pavardė2    7    10    8    5    4    6
```
* Run the program.

__v0.4 Changelog:__
* Added random student generator
* Added chrono benchmark information

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

__v0.4 Benchmarks:__

| Num. of students | Generation time (s.) | Execution time (s.) | Total (s.) |
| :---: | :---: | :---: | :---: |
| 10 | 0.0077851 | 0.0002216 | 0.0080067 |
| 100 | 0.0141137 | 0.0029147 | 0.0170284 |
| 1 000 | 0.480815 | 0.0179601 | 0.4987751 |
| 10 000 | 0.95279 | 0.184916 | 1.137706 |
| 100 000 | 9.47004 | 1.90153 | 11.37157 |

__v0.5 Benchmarks:__

| Num. of students | Type | Execution time (s.) |
| :---: | :---: | :---: |
| 1 000 | Vector (from file) | 0.0051633 |
| 1 000 | List (from file) | 0.0072464 |
| 1 000 | Deque (from file) | 0.0083684 |