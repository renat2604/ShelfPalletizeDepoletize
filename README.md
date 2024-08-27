#&nbsp;ShelfPalletizeDepoletize<br />
Программа&nbsp;моделирует&nbsp;загрузку&nbsp;склада,&nbsp;паллетизацию&nbsp;поступающих&nbsp;в&nbsp;обработку&nbsp;паллет&nbsp;и&nbsp;депаллетизацию,&nbsp;заказанных&nbsp;типов&nbsp;коробок,&nbsp;паллет.<br />
В&nbsp;модели&nbsp;реализован&nbsp;блок&nbsp;из&nbsp;15&nbsp;стеллажей,&nbsp;по&nbsp;10&nbsp;каналов&nbsp;в&nbsp;каждом,&nbsp;по&nbsp;8&nbsp;позиций&nbsp;в&nbsp;каждом.<br />
Входные&nbsp;файлы:<br />
Формат&nbsp;-&nbsp;.csv,&nbsp;название&nbsp;-&nbsp;order_N,&nbsp;где&nbsp;N&nbsp;-&nbsp;целочисленный&nbsp;номер&nbsp;без&nbsp;разделителей.<br />

111141001011149550<br />
SKU,&nbsp;Quantity,&nbsp;Length,&nbsp;Width,&nbsp;Height,&nbsp;Weight,&nbsp;Strength,&nbsp;Aisle,&nbsp;Caustic<br />
1001,	1,	229,	195,	246,	5409,	3,	17,	0,	<br />
1002,	1,	284,	240,	217,	7048,	3,	8,	0,	<br />

Выходные&nbsp;файлы:<br />
Формат&nbsp;-&nbsp;.csv,&nbsp;названия:&nbsp;depalletize,&nbsp;palletize,&nbsp;palletLog.<br />
Входные&nbsp;данные:&nbsp;char[]&nbsp;-&nbsp;внешний&nbsp;идентификатор&nbsp;паллеты,&nbsp;char[]&nbsp;-&nbsp;идентификатор&nbsp;коробки,&nbsp;8&nbsp;значений&nbsp;__int16:&nbsp;запрашиваемое&nbsp;кол-во,&nbsp;длинна,&nbsp;ширина,&nbsp;высота,&nbsp;масса,&nbsp;прочность,&nbsp;тип&nbsp;содержимого&nbsp;и&nbsp;цвет&nbsp;соответственно.<br />
Выходные&nbsp;данные:<br />
depalletize:&nbsp;time&nbsp;-&nbsp;кол-во&nbsp;операций&nbsp;изьятия/внесения&nbsp;коробок&nbsp;с/в&nbsp;канал&nbsp;стеллажа,&nbsp;boxID&nbsp;-&nbsp;внутренний&nbsp;номер&nbsp;типа&nbsp;коробки,&nbsp;eventtype&nbsp;-&nbsp;тип&nbsp;события,&nbsp;stackID&nbsp;-&nbsp;номер&nbsp;стеллажа,&nbsp;channelID&nbsp;-&nbsp;номер&nbsp;канала,&nbsp;palletID&nbsp;-&nbsp;номер&nbsp;палеты.<br />

startDepalletize<br />
|&nbsp;&nbsp;time&nbsp;&nbsp;|&nbsp;boxID&nbsp;|&nbsp;eventtype&nbsp;|&nbsp;stackID&nbsp;|&nbsp;channelID&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;palletID&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br />
|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br />
|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;~&nbsp;|&nbsp;<br />
|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<pre>~</pre>&nbsp;|&nbsp;<br />

palletize:&nbsp;time&nbsp;-&nbsp;кол-во&nbsp;операций&nbsp;изьятия/внесения&nbsp;коробок&nbsp;с/в&nbsp;канал&nbsp;стеллажаbox,&nbsp;boxID&nbsp;-&nbsp;внутренний&nbsp;номер&nbsp;типа&nbsp;коробки,&nbsp;eventtype&nbsp;-&nbsp;тип&nbsp;события,&nbsp;stackID&nbsp;-&nbsp;номер&nbsp;стеллажа,&nbsp;channelID&nbsp;-&nbsp;номер&nbsp;канала,&nbsp;palletID&nbsp;-&nbsp;номер&nbsp;палеты.<br />

startPalletize
|&nbsp;&nbsp;time&nbsp;&nbsp;|&nbsp;boxID&nbsp;|&nbsp;eventtype&nbsp;|&nbsp;stackID&nbsp;|&nbsp;channelID&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;palletID&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br />
|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br />
|&nbsp;&nbsp;&nbsp;1201&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;11141001011149550&nbsp;&nbsp;|&nbsp;<br />
|&nbsp;&nbsp;&nbsp;1202&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;11141001011149550&nbsp;&nbsp;|&nbsp;<br />

palletLog:&nbsp;time&nbsp;-&nbsp;кол-во&nbsp;операций&nbsp;изьятия/внесения&nbsp;коробок&nbsp;с/в&nbsp;канал&nbsp;стеллажаbox,&nbsp;palletID&nbsp;-&nbsp;номер&nbsp;палеты,&nbsp;palletTypeID&nbsp;-&nbsp;номер&nbsp;типа&nbsp;палеты,&nbsp;eventtype&nbsp;-&nbsp;тип&nbsp;события.<br />

|&nbsp;time&nbsp;|&nbsp;palletID&nbsp;|&nbsp;palletTypeID&nbsp;|&nbsp;eventtype&nbsp;|<br />
|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|<br />
|&nbsp;1200&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4&nbsp;|&nbsp;<br />
|&nbsp;1263&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;7&nbsp;|&nbsp;<br />


Сборка&nbsp;и&nbsp;запуск&nbsp;проекта:<br />
Скопировать&nbsp;код&nbsp;из&nbsp;PalletizeDepolletize_practica.cpp<br />
Создать&nbsp;консольное&nbsp;приложение&nbsp;в&nbsp;VSCode&nbsp;заменить&nbsp;на&nbsp;код&nbsp;из&nbsp;PalletizeDepolletize_practica.cpp,&nbsp;затем&nbsp;заменить&nbsp;коментарии&nbsp;выделенные&nbsp;"/*&nbsp;*/"&nbsp;на&nbsp;описанные&nbsp;в&nbsp;них&nbsp;параметры,&nbsp;собрать&nbsp;и&nbsp;запустить.<br />
