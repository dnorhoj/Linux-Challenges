# Level 7

For at klare dette level skal du give en fil til programmet som input.

Det fungerer ved at man giver programmet en fil som "stdin" (standard input).
Normalt er stdin bare det man skriver i terminalen mens programmet køres.

Men man kan lave to former for stdin input. Her er de to typer:

**Type 1**: Output redirection:

```sh
$ echo hej | rev
jeh
```

Her får programmet "rev" outputtet af kommandoen, "echo hej", som input.

**Type 2**: File redirection:

```sh
$ # Der er en fil der hedder ost som har indholdet hej
$ cat ost
hej
$ # Her laver vi inputtet:
$ rev < ost
jeh
```

Det er denne type redirection du skal lave for at løse denne opgave.

Du skal give 'level_07' programmet en fil som hedder coding som har indholdet 'pirates'.
Så for at løse opgaven skal du først lave en fil der hedder coding. Og bagefter give den til 'level_07'.
