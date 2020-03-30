# [Versija v0.1](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.1)
Programa nuskaito studentų vardus ir pavardes ir tada leidžia įvesti 
arba sugeneruoti atsitiktinai namų darbų ir egzaminų rezultatus, po to program
apskaičiuoja vidurkį arba medianą (pasirinktinai) ir išveda rezultatus.
# [Versija v0.1.1](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.1.1)
Programa atlaisvina dinamiškai paskirtą atmintį.
# [Versija v0.1.2](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.1.2)
Programa atnaujinta pakeičiant užsilikusius C masyvus į vektorius.
# [Versija v0.2](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.2)
Programa gali nuskaityti duomenis ne tik iš įvesties, bet ir iš failo, arba juos sugeneruoti. Rezultatai surikiuojami pagal studentų vardus ir pavardes ir išvedami į failą.
# [Versija v0.3](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.3)
Programa pertvarkyta į daug mažesnių kodo bei antraščių failų ir pradėtos naudoti išimtys.
# [Versija v0.4](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.4)
Programa dabar gali pati sugeneruoti pradinių duomenų failus ir rezultatus dalina į dvi grupes: tuos kurių vidurkis >= 5 ir likusius.

## Programos veikimo laiko analizė:
Studentų kiekis | Studentų generavimas | Failų generavimas | Duomenų nuskaitymas | Studentų rikiavimas | Studentų rūšiavimas į dvi kategorijas | Pažangių studentų surašymas į failą | Nepažangių studentų surašymas į failą | Visas programos veikimo laikas
--------------- | -------------------- | ----------------- | ------------------- | ------------------- | ------------------------------------- | ----------------------------------- | ------------------------------------- | ------------------------------
1000 | 3.79208s | 0.0055796s | 0.0056261s | 0.0015246s | 0.0003923s | 0.0051052s | 0.00039824s | 17.2514s
10000 | 3.21854s | 0.0365878s | 0.0460614s | 0.0152302s | 0.0027093s | 0.0355636s | 0.0372222s | 13.7339s
100000 | 9.52402s | 0.786247s | 1.1548s | 0.421733s | 0.0382856s | 0.414563s | 0.307117s | 27.857s
1000000 | 29.3251s | 4.1484s | 5.41935s | 1.69674s | 0.469434s | 3.55203s | 3.61551s | 32.1945s
10000000 | 165.339s | 36.2581s | 44.3545s | 17.6408s | 4.23923s | 36.4908s | 42.16s | 164.168s

# [Versija v0.5](https://github.com/mxstrong/2-uzduotis/releases/tag/v0.5)
Programa dabar suskirstyta į 3 versijas, su skirtingomis duomenų struktūromis: std::vector, std::list ir std::deque.

## Programos veikimo laiko analizė, su skirtingomis duomenų struktūromis:

### std::vector:
Studentų kiekis | Duomenų nuskaitymas | Studentų rūšiavimas į dvi kategorijas
--------------- | ------------------- | -------------------------------------
1000 | 0.0056261s | 0.0003923s
10000 | 0.0460614s | 0.0027093s
100000 | 1.1548s | 0.0382856s
1000000 | 5.41935s | 0.469434s
10000000 | 44.3545s | 4.23923s

### std::list:
Studentų kiekis | Duomenų nuskaitymas | Studentų rūšiavimas į dvi kategorijas
--------------- | ------------------- | -------------------------------------
1000 | 0.0089173s | 0.0007535s
10000 | 0.0467701s | 0.0063385s
100000 | 1.22308s | 0.146764s
1000000 | 6.05603s | 1.09972s
10000000 | 47.787s | 9.35601s

### std::deque:
Studentų kiekis | Duomenų nuskaitymas | Studentų rūšiavimas į dvi kategorijas
--------------- | ------------------- | -------------------------------------
1000 | 0.0102834s | 0.0006412s
10000 | 0.049512s | 0.0069454s
100000 | 1.20976s | 0.0954378s
1000000 | 5.60804s | 0.83865s
10000000 | 50.1963s | 11.5791s

### Kompiuterio parametrai
CPU | RAM | SSD
--- | --- | ---
Intel CORE i5 8th Gen | 8GB | 256GB

# [Versija v1.0](https://github.com/mxstrong/2-uzduotis/releases/tag/v1.0)
Programa buvo pertvarkyta ir ženkliai optimizuota ir todėl atnaujintos programos spartos analizės. Programa dabar taiko 2 skirtingas strategijas studentams surūšiuoti į dvi grupes.

## Studentų rūšiavimo strategijų palyginimas
1 strategija - studentų konteinerį padalinti į du konteinerius
2 strategija - iš studentų konteinerio perkelti kriterijų atitinkančius studentus į naują konteinerį

Studentų kiekis | std::vector 1 strategija | std::vector 2 strategija | std::list 1 strategija | std::list 2 strategija | std::deque 1 strategija | std::deque 2 strategija
--------------- | ------------------------ | ------------------------ | ---------------------- | ---------------------- | ---------------------- | -----------------------
1000 | 0.0003923s | 0.0001764 | 0.0007535s | 0.0005547s | 0.0006412s |  0.0004933s
10000 | 0.0027093s | 0.0016226s | 0.0063385s | 0.0077404s | 0.0069454s | 0.0070327s
100000 | 0.0382856s | 0.0184986s | 0.146764s | 0.102567s | 0.0954378s | 0.0729289s
1000000 | 0.469434s | 0.241298s | 1.09972s | 1.14836s | 0.83865s | 0.769068s
10000000 | 4.23923s | 2.44195s | 9.35601s | 9.33468s | 11.5791s | 7.82477s
