#&nbsp;ShelfPalletizeDepoletize<br />
Программа&nbsp;моделирует&nbsp;загрузку&nbsp;склада,&nbsp;паллетизацию&nbsp;поступающих&nbsp;в&nbsp;обработку&nbsp;паллет&nbsp;и&nbsp;депаллетизацию,&nbsp;заказанных&nbsp;типов&nbsp;коробок,&nbsp;паллет.<br />
В&nbsp;модели&nbsp;реализован&nbsp;блок&nbsp;из&nbsp;15&nbsp;стеллажей,&nbsp;по&nbsp;10&nbsp;каналов&nbsp;в&nbsp;каждом,&nbsp;по&nbsp;8&nbsp;позиций&nbsp;в&nbsp;каждом.<br />
Входные&nbsp;файлы:<br />
Формат&nbsp;-&nbsp;.csv,&nbsp;название&nbsp;-&nbsp;order_N,&nbsp;где&nbsp;N&nbsp;-&nbsp;целочисленный&nbsp;номер&nbsp;без&nbsp;разделителей.<br />
```
111141001011149550<br />
SKU, Quantity, Length, Width, Height, Weight, Strength, Aisle, Caustic
1001,	1,	229,	195,	246,	5409,	3,	17,	0,	
1002,	1,	284,	240,	217,	7048,	3,	8,	0,	
```

Выходные&nbsp;файлы:<br />
Формат&nbsp;-&nbsp;.csv,&nbsp;названия:&nbsp;depalletize,&nbsp;palletize,&nbsp;palletLog.<br />
Входные&nbsp;данные:&nbsp;char[]&nbsp;-&nbsp;внешний&nbsp;идентификатор&nbsp;паллеты,&nbsp;char[]&nbsp;-&nbsp;идентификатор&nbsp;коробки,&nbsp;8&nbsp;значений&nbsp;__int16:&nbsp;запрашиваемое&nbsp;кол-во,&nbsp;длинна,&nbsp;ширина,&nbsp;высота,&nbsp;масса,&nbsp;прочность,&nbsp;тип&nbsp;содержимого&nbsp;и&nbsp;цвет&nbsp;соответственно.<br />
Выходные&nbsp;данные:<br />
depalletize:&nbsp;time&nbsp;-&nbsp;кол-во&nbsp;операций&nbsp;изьятия/внесения&nbsp;коробок&nbsp;с/в&nbsp;канал&nbsp;стеллажа,&nbsp;boxID&nbsp;-&nbsp;внутренний&nbsp;номер&nbsp;типа&nbsp;коробки,&nbsp;eventtype&nbsp;-&nbsp;тип&nbsp;события,&nbsp;stackID&nbsp;-&nbsp;номер&nbsp;стеллажа,&nbsp;channelID&nbsp;-&nbsp;номер&nbsp;канала,&nbsp;palletID&nbsp;-&nbsp;номер&nbsp;палеты.<br />
```
startDepalletize<br />
|  time  | boxID | eventtype | stackID | channelID |           palletID           |
|        |       |           |         |           |                              |
|      1 |     0 |         1 |       0 |         0 |                            ~ |
|      2 |     1 |         1 |       0 |         0 |                            ~ |
```
palletize:&nbsp;time&nbsp;-&nbsp;кол-во&nbsp;операций&nbsp;изьятия/внесения&nbsp;коробок&nbsp;с/в&nbsp;канал&nbsp;стеллажаbox,&nbsp;boxID&nbsp;-&nbsp;внутренний&nbsp;номер&nbsp;типа&nbsp;коробки,&nbsp;eventtype&nbsp;-&nbsp;тип&nbsp;события,&nbsp;stackID&nbsp;-&nbsp;номер&nbsp;стеллажа,&nbsp;channelID&nbsp;-&nbsp;номер&nbsp;канала,&nbsp;palletID&nbsp;-&nbsp;номер&nbsp;палеты.<br />

```
startPalletize
|  time  | boxID | eventtype | stackID | channelID |           palletID           |
|        |       |           |         |           |                              |
|   1201 |     0 |         2 |       0 |         0 |           11141001011149550  | 
|   1202 |     1 |         2 |       0 |         0 |           11141001011149550  | 
```
palletLog:&nbsp;time&nbsp;-&nbsp;кол-во&nbsp;операций&nbsp;изьятия/внесения&nbsp;коробок&nbsp;с/в&nbsp;канал&nbsp;стеллажаbox,&nbsp;palletID&nbsp;-&nbsp;номер&nbsp;палеты,&nbsp;palletTypeID&nbsp;-&nbsp;номер&nbsp;типа&nbsp;палеты,&nbsp;eventtype&nbsp;-&nbsp;тип&nbsp;события.<br />
```
| time | palletID | palletTypeID | eventtype |
|      |          |              |           |
| 1200 |        0 |            0 |         4 | 
| 1263 |        0 |            0 |         7 | 
```

Сборка&nbsp;и&nbsp;запуск&nbsp;проекта:<br />
Скопировать&nbsp;код&nbsp;из&nbsp;PalletizeDepolletize_practica.cpp<br />
Создать&nbsp;консольное&nbsp;приложение&nbsp;в&nbsp;VSCode&nbsp;заменить&nbsp;на&nbsp;код&nbsp;из&nbsp;PalletizeDepolletize_practica.cpp,&nbsp;затем&nbsp;заменить&nbsp;коментарии&nbsp;выделенные&nbsp;"/*&nbsp;*/"&nbsp;на&nbsp;описанные&nbsp;в&nbsp;них&nbsp;параметры,&nbsp;собрать&nbsp;и&nbsp;запустить.<br />
