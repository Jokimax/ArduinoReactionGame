# Dizaino dokumentas: Arduino reakcijos laiko žaidimas

Žaidimas sukurtas su Tinkercad. Žaidėjas turi pagauti krentančius LED apačioje, laiku paspausdamas vieną iš trijų mygtukų.

![Žaidimo nuotrauka](arduinoDesign.png "Žaidimo nuotrauka")

## Komponentai

- 1 Arduino UNO
- 12 LED
- 3 mygtukai, naudojami įvesčiai
- 7 rezistoriai, prijungti prie mygtukų ir LED, sumažinti įtampai
- 1 LCD 16×2, rodo žaidimo statusą

## Veikimas

Atsitiktinai generuojamas skaičius tarp 1 ir 3, ir tame stulpelyje viršuje užsidega LED. Kiekvieną žingsnį LED nusileidžia viena eilute žemyn. Kai LED pasiekia apatinę eilutę, reikia paspausti atitinkamą mygtuką. Mygtukai kartu veikia kaip įvestis ir įjungia mėlyną LED, kuris rodo, kur paspausta.

Už kiekvieną pagavimą gaunamas taškas. Žaidimas nuolat greitėja: žingsnis prasideda nuo 750 ms ir kas tašką sutrumpėja 5 ms, kol pasiekia 250 ms. Nepagavus LED, ekrane pasirodo „You lost!“.

## Patobulinimai

Visas projektas veikia, bet jį galima pagerinti dviem būdais:

- **Tvarkingesni laidai.** Reikėtų tvarkingiau laidus išdėstyti.
- **Greitesnis įvesties skaitymas.** Vietoj `delay()` mygtukus galima tikrinti dažniau naudojant `millis()` skaičiuoti laiką nuo paskutinio nusileidimo.
