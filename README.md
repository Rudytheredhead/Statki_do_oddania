# Statki

Prosta gra w statki uruchamiana w terminalu.

Wymagania:
- Kompilator C++ (g++, clang++)
- make (opcjonalnie)

Kompilacja:
```sh
make
# lub ręcznie:
g++ src/*.cpp -o prog
```

Uruchomienie:
```sh
./prog
```

Rozgrywa:
```sh
Gra dwusobowa. Każdy z graczy wybiera ustawienie swoich statków, potem po kolei oddają po 3 strzały.
Wygrywa ten, który pierwszy zestrzleli statki przeciwnika
```