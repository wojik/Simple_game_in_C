# Ping Pong Game in C

## Opis

Ten projekt to klasyczna gra Ping Pong napisana w języku C z wykorzystaniem konsoli systemu Windows. Gra jest przeznaczona dla dwóch graczy i polega na odbijaniu piłki za pomocą paletek. Pierwszy gracz, który zdobędzie 5 punktów, wygrywa.

## Wymagania systemowe

- System operacyjny: Windows
- Kompilator obsługujący standard C (np. MinGW dla Windows)

## Kompilacja i uruchomienie

Aby skompilować program, użyj polecenia w terminalu:

```sh
gcc -o ping_game ping_game.c -Wall -Wextra
```

Następnie uruchom grę:

```sh
ping_game.exe
```

## Sterowanie

| Gracz  | Klawisz  | Akcja        |
|--------|---------|-------------|
| Gracz 1 | W       | Ruch w górę  |
| Gracz 1 | S       | Ruch w dół   |
| Gracz 2 | I       | Ruch w górę  |
| Gracz 2 | K       | Ruch w dół   |
| Każdy   | Q       | Zakończenie gry |
| Każdy   | C       | Rozpoczęcie gry |

## Zasady gry

- Gra rozpoczyna się po naciśnięciu klawisza `C`.
- Dwóch graczy kontroluje paletki za pomocą odpowiednich klawiszy.
- Piłka odbija się od ścian i paletek.
- Jeśli piłka przekroczy lewą lub prawą krawędź, przeciwnik zdobywa punkt.
- Gra kończy się, gdy któryś z graczy zdobędzie 5 punktów.

