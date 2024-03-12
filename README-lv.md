# Pārskats

[![Tests](https://github.com/jorenchik/testing-spring-2024/actions/workflows/test.yml/badge.svg)](https://github.com/jorenchik/testing-spring-2024/actions/workflows/test.yml)

## Projekts

Šis ir vienkāršs C++ projekts, kas ietver funkciju mūsu kolēģiem
testēšanai. Funkcija (t.i., galvenā funkcija un tajā izmantotās apakšfunkcijas)
atrodas `lib.cpp`.

## Papildu bibliotēkas un izpildāmā programma

Mūsu bibliotēka `prep` ir saistīta ar datu sagatavošanu pirms funkcijas
izsaukuma. `test.cpp` ir viens testa fails, kurā būs mūsu kolēģu testi
un mūsu pašu izstrādes testi. GTest tiek izmantots testiem.

## Lietojums

## Kompilācija uz Linux un MacOS

Kompilācijai operētājsistēmā Linux ir nepieciešams cmake un CXX kompilators (e.g., g++).

### MacOS

MacOS nepieciešama atsevišķi instalēt `gcc13`.

#### Izmantojot [Homebrew](https://brew.sh/)

```bash
brew install cmake gcc@13
brew install ninja # opcionāli
```

### Linux

Jūs zināt, ko darīt.

### ninja

```bash
cmake -G Ninja -B build
# vai
# cmake -G Ninja -B build -D CMAKE_CXX_COMPILER=g++-13 # MacOS
cd build
ninja
./main
```

### Make

```bash
cmake -B build
# or
# cmake -B build -D CMAKE_CXX_COMPILER=g++-13 # for MacOS
cd build
make
./main
```

### Windows un/vai VSCode

Uzstādiet [CMake](https://cmake.org/download/) un VSCode [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) paplašinājumu.

- Atveriet projektu kā saknes direktoriju VSCode.
- Izvēlaties **View->Command palete...** vai `Ctrl+Shift+P` un palaidiet `CMake: Build`.

Rezultātā iegūtie binārie faili ir `build/main` - programma un `build/runtests`, lai
palaistu punktos norādītos testus iekš `test.cpp`.
