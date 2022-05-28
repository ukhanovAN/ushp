# Учебная практика
**Вариант 1** : Кириллица, по алфавиту, по возрастанию, учитывать числа, сортировка пузырьком.
---
функция division делит символы на слова

функция bubble сортирует слова

функция f_statistic подсчитывает статистику по первым элементам слова

сам код в файле uchp.cpp

**Подробное описание реализованной функции**

int main() – основная функция, вызывающая другие функции, выводящая данные в консоль и в файл, открывающая и закрывающая входной и выходной файлы. 

Функция **division(string text)** – функция работает пока во входном файле есть символы. Если символ принадлежит промежутку чисел или букв кириллицы, слово вставляется в вектор word. Когда символ, не подходящий под условия задачи, встречается в тексте, функция проводит проверку на заполненность вектора word (на случай, если после знака препинания встречается пробел или после любого ненужного символа встречается второй подобный). Если вектор заполнен, функция преобразует вектор в строку, которую впоследствии добавляет в вектор all_words, хранящий все слова файла.

Функция **size_of_s(vector<string> &all_words)** на входе принимает массив всех слов. Проверяется первый символ слова. Если символ входит в промежуток заглавных букв, то функция его уменьшает.

Функция **bubble(vector<string> &all_words)** на входе принимает массив всех слов. В функции присутствует вложенный массив for, чтобы слова сортировались полностью. Во вложенной функции идет проверка первого символа проверяемого слова и последующего. Если первый символ проверяемого слова больше первого символа последующего слова, они меняются местами.

Функция **f_statistic(int *statistic, vector<string> &all_words, int k, int i)** на входе принимает массив для подсчета статистики, массив всех слов, индекс слова и индекс элемента (0). Далее следует проверка на принадлежность к числам или символам, от чего зависит индекс массива статистики для подсчета количества слов, начинающихся с данного символа.

  ## Тесты
  
  _Тест 1_
  
  Текст длиной в 329 символов:
  ______________________________________________________________________________________________
_Согласно легенде, панда когда-то была полностью белым медведем. Когда маленькая девочка попыталась спасти детеныша панды от нападения леопарда, леопард вместо этого убил девочку. Панды пришли на ее похороны с повязками из черного пепла. Вытирая глаза, обнимая друг друга и закрывая уши, на их теле оставались пятна черного пепла._
  ___
  
Результат работы программы на консоли: 
  ![image](https://user-images.githubusercontent.com/105941598/169800296-3b3f5cea-57a9-4e83-9bb7-dc547f12b77d.png)

Результат работы программы в файле
 ![image](https://user-images.githubusercontent.com/105941598/169800454-99905acc-fe41-4ac7-86ed-4b5e318c10f0.png)

  _Тест 2_
  
  Текст длинной 1901 символ
  ___
_Большая панда - это вид млекопитающих, принадлежащий семейству медвежьих. Имеют эти животные интересный чёрно-белый окрас, благодаря чему выглядят очень мило. Вдобавок к этому, обладают они безобидным характером. Другое название этого вида животных - Бамбуковый медведь (любимое их лакомство - бамбук).
Краткое описание панды
В среднем, длина тела этих милых животных составляет 1,5 метра, причём самцы немного крупнее самок. Масса тела взрослых особей при этом колеблется от 50 до 150 кг.
Как и подобает медведям, обладают они массивным телом, и являются немного неуклюжими. Вот только, в отличие от остальных медведей, очень медлительны. Однако, пандам ловкость со скоростью и не нужны, ведь они не охотятся, а питаются бамбуком, в основном. Или, скорее, наоборот, они питаются бамбуком, потому что тот не может от них убежать.
Отличить бамбуковых медведей от остальных животных довольно просто по окрасу, ведь является он весьма примечательным. Обычно большая часть тела панд покрыта белым густым мехом, но область вокруг глаз, уши и лапы окрашены в чёрный. Хотя существуют и другие вариации. Именно такой забавный окрас и делает животных столь милыми.
Интересное про панд
Сложно представить, но являются бамбуковые медведи хищниками. Хоть и едят они практически один лишь бамбук (около 30 кг в день), также могут питаться мелкими животными, насекомыми, и даже падалью. Справедливости ради стоит отметить, что это нужно им лишь для получения питательных веществ, ведь бамбук не может обеспечить организм всеми необходимыми веществами.
Из-за их окраса на протяжении длительного времени панды считались енотами. Истину удалось выяснить лишь в конце 20-го века. Также удалось выяснить, что на передних лапах они имеют 6 пальцев, что весьма необычно.
Новорожденные детёныши панды обладают весом в 10-20 раз меньше, чем новорожденные дети человека, 150-200 граммов. Первую неделю детёныши окрашены в белый цвет._  
___
  
Результат работы программы, вид с консоли
  ![image](https://user-images.githubusercontent.com/105941598/169801383-3652d192-74b3-4691-82da-8ee3a4900bfe.png)

Результат работы программы, вид из файла
![image](https://user-images.githubusercontent.com/105941598/169802986-b15e782d-6081-4bd8-81e4-ef833d332e7b.png)

