# Project_4_TP
Repository for project 4  

Proste wytłumaczenie co zajmuje się czym w programie.

![Zrzut ekranu (15)](https://user-images.githubusercontent.com/65567778/176584971-3950c75f-5d84-489c-a3e9-4b3b8402c58d.png)

wszystkie funkcje zaczynające się od "MyOnPaint" zajmują się rysowaniem linii które tworzą windę, jej szyb, piętra oraz 'ludzi'.
Ta zamieszczona na zdjęciu tworzy szkielet szybu oraz pięter. Na kolejnym zdjęciu widać funkcje "repaintWindow" wywołujące 2 z istniejącyhc "MyOnPaint".
Niższa pozwala na przesuwanie się drzwi w górę oraz dół w zależności od dodatkowych danych zawartych w "stan_drzwi",
podczas gdy wyższa przemieszcza windę.
![Zrzut ekranu (17)](https://user-images.githubusercontent.com/65567778/176586049-04b8e6f2-1e4d-45e5-ad41-b9f8273df0ec.png)
istotnym elementem jest znajdujący się tam "for" oraz "sleep", które pozwalają na brak 'teleportacji' obiektów. Nie jets to jednak metoda bez wad, co wyraźnie widać gdy zostanie wciśnięty guzik w windzie. O ile obiekt przemieszcza się płynnie, o tyle czasami miga.
Jak wspomniałem wcześniej, funkcje "repaintWindow" są odpowiedzialne za przemieszczanie wszystkiego na ekranie po wciśnięciu guziku, a w zależności od obecnego położenia windy wywoływane są niewiele różne funkcje. Położenie windy jest zapisywane jako stała globalna która następnie determinuje jaki case powinien mieć miejsce.
![Zrzut ekranu (19)](https://user-images.githubusercontent.com/65567778/176587120-9d3fb7f5-508e-43c7-add1-9f0b05c31f5f.png)

