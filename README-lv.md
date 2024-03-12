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

## Kompilācija

Kompilācijai operētājsistēmā Linux ir nepieciešams cmake un CXX kompilators (e.g., g++).

### ninja

```bash
cmake -G Ninja -B build
cd build
ninja
./main
```

### Make

```bash
cmake -B build
cd build
make
./main
```

Rezultātā iegūtie binārie faili ir `build/main` - programma un `build/runtests`, lai
palaistu punktos norādītos testus iekš `test.cpp`.
