# Level 8

I denne opgave skal vi bruge programmet `grep` til at finde flaget i en lang fil. Med grep læses en fil (eller stream) igennem, og der ledes efter et bestemt pattern.

Sådan kaldes grep:
    ```
    grep [OPTION...] PATTERN [FILE...]
    ```

Hvis der ikke gives specielle options til grep udskrives de linjer, der matcher pattern. 

For at se hvilke options der er til grep kan du læse man-siden. Brug kommandoen `man grep`, eller find den her: https://man7.org/linux/man-pages/man1/grep.1.html

Da vi ved at vores flag i disse opgaver har formatet flag{XXXXX} kan vi greppe efter `flag{`

Det kan være en god idé at sætte pattern i quotes, ofte bedst med single-quotes (`'`), for at undgå problemer med shell-expansion.
