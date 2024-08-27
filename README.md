#&nbspShelfPalletizeDepoletize<br />
Программа&nbspмоделирует&nbspзагрузку&nbspсклада,&nbspпаллетизацию&nbspпоступающих&nbspв&nbspобработку&nbspпаллет&nbspи&nbspдепаллетизацию,&nbspзаказанных&nbspтипов&nbspкоробок,&nbspпаллет.<br />
В&nbspмодели&nbspреализован&nbspблок&nbspиз&nbsp15&nbspстеллажей,&nbspпо&nbsp10&nbspканалов&nbspв&nbspкаждом,&nbspпо&nbsp8&nbspпозиций&nbspв&nbspкаждом.<br />
Входные&nbspфайлы:<br />
Формат&nbsp-&nbsp.csv,&nbspназвание&nbsp-&nbsporder_N,&nbspгде&nbspN&nbsp-&nbspцелочисленный&nbspномер&nbspбез&nbspразделителей.<br />

111141001011149550<br />
SKU,&nbspQuantity,&nbspLength,&nbspWidth,&nbspHeight,&nbspWeight,&nbspStrength,&nbspAisle,&nbspCaustic<br />
1001,	1,	229,	195,	246,	5409,	3,	17,	0,	<br />
1002,	1,	284,	240,	217,	7048,	3,	8,	0,	<br />

Выходные&nbspфайлы:<br />
Формат&nbsp-&nbsp.csv,&nbspназвания:&nbspdepalletize,&nbsppalletize,&nbsppalletLog.<br />
Входные&nbspданные:&nbspchar[]&nbsp-&nbspвнешний&nbspидентификатор&nbspпаллеты,&nbspchar[]&nbsp-&nbspидентификатор&nbspкоробки,&nbsp8&nbspзначений&nbsp__int16:&nbspзапрашиваемое&nbspкол-во,&nbspдлинна,&nbspширина,&nbspвысота,&nbspмасса,&nbspпрочность,&nbspтип&nbspсодержимого&nbspи&nbspцвет&nbspсоответственно.<br />
Выходные&nbspданные:<br />
depalletize:&nbsptime&nbsp-&nbspкол-во&nbspопераций&nbspизьятия/внесения&nbspкоробок&nbspс/в&nbspканал&nbspстеллажа,&nbspboxID&nbsp-&nbspвнутренний&nbspномер&nbspтипа&nbspкоробки,&nbspeventtype&nbsp-&nbspтип&nbspсобытия,&nbspstackID&nbsp-&nbspномер&nbspстеллажа,&nbspchannelID&nbsp-&nbspномер&nbspканала,&nbsppalletID&nbsp-&nbspномер&nbspпалеты.<br />

startDepalletize<br />
|&nbsp&nbsptime&nbsp&nbsp|&nbspboxID&nbsp|&nbspeventtype&nbsp|&nbspstackID&nbsp|&nbspchannelID&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsppalletID&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|<br />
|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|<br />
|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp1&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp1&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp~&nbsp|&nbsp<br />
|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp2&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp1&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp1&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp~&nbsp|&nbsp<br />

palletize:&nbsptime&nbsp-&nbspкол-во&nbspопераций&nbspизьятия/внесения&nbspкоробок&nbspс/в&nbspканал&nbspстеллажаbox,&nbspboxID&nbsp-&nbspвнутренний&nbspномер&nbspтипа&nbspкоробки,&nbspeventtype&nbsp-&nbspтип&nbspсобытия,&nbspstackID&nbsp-&nbspномер&nbspстеллажа,&nbspchannelID&nbsp-&nbspномер&nbspканала,&nbsppalletID&nbsp-&nbspномер&nbspпалеты.<br />

startPalletize
|&nbsp&nbsptime&nbsp&nbsp|&nbspboxID&nbsp|&nbspeventtype&nbsp|&nbspstackID&nbsp|&nbspchannelID&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsppalletID&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|<br />
|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|<br />
|&nbsp&nbsp&nbsp1201&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp2&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp11141001011149550&nbsp&nbsp|&nbsp<br />
|&nbsp&nbsp&nbsp1202&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp1&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp2&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp11141001011149550&nbsp&nbsp|&nbsp<br />

palletLog:&nbsptime&nbsp-&nbspкол-во&nbspопераций&nbspизьятия/внесения&nbspкоробок&nbspс/в&nbspканал&nbspстеллажаbox,&nbsppalletID&nbsp-&nbspномер&nbspпалеты,&nbsppalletTypeID&nbsp-&nbspномер&nbspтипа&nbspпалеты,&nbspeventtype&nbsp-&nbspтип&nbspсобытия.<br />

|&nbsptime&nbsp|&nbsppalletID&nbsp|&nbsppalletTypeID&nbsp|&nbspeventtype&nbsp|<br />
|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp|<br />
|&nbsp1200&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp4&nbsp|&nbsp<br />
|&nbsp1263&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp0&nbsp|&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp7&nbsp|&nbsp<br />


Сборка&nbspи&nbspзапуск&nbspпроекта:<br />
Скопировать&nbspкод&nbspиз&nbspPalletizeDepolletize_practica.cpp<br />
Создать&nbspконсольное&nbspприложение&nbspв&nbspVSCode&nbspзаменить&nbspна&nbspкод&nbspиз&nbspPalletizeDepolletize_practica.cpp,&nbspзатем&nbspзаменить&nbspкоментарии&nbspвыделенные&nbsp"/*&nbsp*/"&nbspна&nbspописанные&nbspв&nbspних&nbspпараметры,&nbspсобрать&nbspи&nbspзапустить.<br />
