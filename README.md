# DoublyLinkedList

->ÖZET
  Sayilar.txt dosyasının içindeki veriyi ‘#’ karakterinden ayırarak 2 farklı sayıya ayırıp bu iki 
sayıyı karşılaştırmam gerekmektedir. Detaya inmek gerekirse, C++ dili ile Doubly Linked List veri 
yapısı oluşturup, ele aldığımız 2 farklı sayıyı 2 farklı listeye 3’er basamaklı olacak şekilde atıp 
karşılıklı her düğümü karşılaştırıp gerekli işlemleri yapmamız bekleniyor. Bu işlemler iki karşılıklı 
düğümü birbiriyle yer değiştirmek ve listeyi tersine çevirmek. Ben projeyi dört bölüme ayırıp çözmeyi 
tercih ettim. Önce Dosyanın içindeki veriyi 2 farklı sayı olarak alabilmeyi yaptım. İkinci olarak bu 
sayıları her bir elemanı 3’er basamak olacak şekilde 2 diziye atıp bu dizileri döndürmeyi yaptım. 
Üçüncü olarak doubly linked list veri yapısı oluşturup bu iki diziyi iki farklı listeye atmayı yaptım. 
Son olarak ise bu iki listeyi karşılaştırma işlemini yapıp sonucu ekrana yazdırmayı yaptım.

->PROJENİN YAPILMA AŞAMASINDA İZLEDİĞİM YOL
  Ben projeye öncelikle dosyayı okuyup içerisindeki iki sayıyı alıp döndüren bir File sınıfı
oluşturmakla başladım. Bu işlemleri yaptıktan sonra ilk sayı ve ikinci sayı için gereken işlemleri
yapmak için sınıfları yazdım. Aldığım sayıların boyutu her zaman sabit kalmayacağı için önce 3’er
basamak şeklinde string diziye attım sonrasında döngüyle bu 3 basamaklı sayıları int türüne çevirip int
diziye atıp sayıların tür dönüşümünde boyut hatası almasının önüne geçmiş oldum. Bu işlemlerden
sonra Node sınıfı oluşturup constructor metodlarını yazdım. Arkasından düğümlerin üzerinde
dolaşmak için Iterator sınıfı yazdım. Bu adımdan sonra DoublyLinkedList sınıfımı oluşturdum, bu
sınıfta listem üzerinde projede kullanmam gereken işlemleri yazdığım metodları amaca uygun şekilde
yazmaya çalıştım. Örnek verecek olursam parametre olarak vereceğim int dizinin elemanlarını sırayla
listenin sonuna atan metod, listeyi ters çeviren metod, listenin head’ini döndüren metod vb. Son olarak
ComparisonList sınıfımı oluşturdum. Bu sınıfın constructor metodunda main metodumda yapacağım
ön işlemleri (dosyayı okutmak diziye sayıları atmak gibi) yaptırdım ve main içinde fazlalık kod
olmasını engelledim. Bu sınıfın içinde ayrıca swap işlemini yapan metodu ve karşılaştırma işlemini
yapan metodu oluşturdum. Son olarak main metodumda bu sınıftan nesne oluşturup 2 liste parametresi
vererek karşılaştırma metodumu çağırdım.

