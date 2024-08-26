# Level 10

I denne challenge skal du bruge programmet level_10. Det udskriver 1337 linjer, som er tilfældige, på nær en linje, der altid er den samme. Den linje, der altid forekommer indeholder flaget.

Der er flere måder at løse denne opgave på, men et forslag er at bruge programmet `uniq`. Læs man-siden:
https://man7.org/linux/man-pages/man1/uniq.1.html
(eller `man uniq` i en konsol)

OBS: Læg mærke til at beskrivelsen er "Filter *ADJACENT* matching lines..." Det betyder at input skal være sorteret for at uniq kan fungere. For at sortere kan vi bruge programmet `sort`:
https://man7.org/linux/man-pages/man1/sort.1.html
(eller `man sort`i en konsol)

Du får brug for at køre programmet to gange og bruge uniq til at finde den linje, der er ens. Man kan gøre det med en sub-shell: https://www.geeksforgeeks.org/shell-scripting-subshell/

Alternativt kan du gemme output fra level_10 i en fil. Vær dog opmærksom på at du ikke har skriveadgang i mappen level_10.

Når du har fundet linjen, der indeholder flaget skal du dekode det. Det er base64-kodet. Du kan bruge cyberchef: https://gchq.github.io/CyberChef/ eller `base64` (husk at du skal *de*kode)
