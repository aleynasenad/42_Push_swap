🔄 Push Swap – Sıralama Algoritması (C)

42 Yazılım Okulu'nda yazdığım bir algoritma projesi. Bir stack'te tuttuğum sayıları, ikinci bir stack kullanarak belirli sayıda işlemle sıralayan bir algoritma. Başlangıçta tüm sayılar A stack'inde yer alıyor ve biz bunları B stack'ini de kullanarak en verimli şekilde sıralamaya çalışıyoruz. Ben bu projeyi geliştirirken Türk algoritmasını tercih ettim ve kodumu linked list yapısıyla yazdım. Linked list kullanmamın sebebi, eleman ekleme ve çıkarma işlemlerinin daha esnek ve verimli olmasıydı.


📌 Proje Mantığı

Push swap projesi çok basit ve etkili bir algoritma projesidir: veriler sıralanmalıdır. Elimizde bir dizi integer, 2 stack (A ve B) ve bu stackleri manipüle etmek için bir aksiyon setimiz var. Yapacağımız şey argüman olarak alınan integerları push_swap aksiyonlarını kullanarak, en kısa şekilde sıralayan ve çıktısını veren bir C programı yazmak. Kullanacağımız aksiyonlar şunlar:

🛠 Kullanılan Aksiyonlar

sa (swap a) → A stack'inin en üstteki iki elemanını yer değiştirir.

sb (swap b) → B stack'inin en üstteki iki elemanını yer değiştirir.

ss → sa ve sb işlemlerini aynı anda uygular.

pa (push a) → B stack'inin en üstteki elemanını A stack'ine taşır.

pb (push b) → A stack'inin en üstteki elemanını B stack'ine taşır.

ra (rotate a) → A stack'inin tüm elemanlarını bir yukarı kaydırır (ilk eleman sona gider).

rb (rotate b) → B stack'inin tüm elemanlarını bir yukarı kaydırır.

rr → ra ve rb işlemlerini aynı anda uygular.

rra (reverse rotate a) → A stack'inin tüm elemanlarını bir aşağı kaydırır (son eleman başa gelir).

rrb (reverse rotate b) → B stack'inin tüm elemanlarını bir aşağı kaydırır.

rrr → rra ve rrb işlemlerini aynı anda uygular.


🎯 Hedef Performans

Verileri sıralamak kolaydır. Onları en hızlı şekilde sıralamak ise daha az kolaydır. Bu projede 100 sayıyı 700'den az işlemde, 500 sayıyı 5500'den az hamlede sıralayabilmeliyiz.


🚀 Sonuç

Push Swap, ilk bakışta basit bir sıralama algoritması gibi görünse de, işin içine kısıtlı işlem sayısı ve stack mantığı girdiğinde oldukça zorlayıcı ve öğretici bir hale geliyor. Bu proje sayesinde linked list yönetimi, algoritma tasarımı ve optimizasyon konularında önemli deneyimler kazandım.
