# Egyetemi Nyilvántartó Rendszer

Konzolos C++ alkalmazás hallgatók és oktatók adatainak kezelésére. Prog2 tantárgy Nagyházi Feladat (Egyházi Zoltán Tamás).

## Funkciók

- **Listázás** — összes rekord, csak hallgatók, csak oktatók
- **Szűrés** — csoport, tanszék, osztöndíj, PZH-kötelezettség, „kiváló" státusz
- **Adatok felvétele** — új hallgató vagy oktató interaktív hozzáadása
- **Szerkesztés és törlés** — meglévő rekordok módosítása, Neptun-kód alapján
- **Fájl műveletek** — CSV fájlból betöltés és fájlba mentés (`Kulcs:Érték` formátum)

## Buildelés

```bash
mkdir -p build && cd build
cmake ..
make
```

## Futtatás

```bash
./build/program.exe
```

Indításkor automatikusan betölti a `data/test_data.csv` fájlt.

## Tesztek

```bash
./build/test.exe
```

37 egységteszt a `gtest_lite` keretrendszerrel. Memóriaszivárgás-ellenőrzés a `memtrace` könyvtárral.

## Projekt felépítése

```
├── src/                  # Forráskód (.cpp)
├── include/              # Fejlécek (.h)
├── data/                 # CSV tesztadatok
├── CMakeLists.txt        # Build konfiguráció
└── diagram.nomnoml       # UML osztálydiagramm
```

## Osztályok

```
        Szemely (absztrakt)
           /        \
      Hallgato      Oktato

        Parser (adatkezelő)
           |
         Menu (felület)
```
