# Level 6

For at løse denne opgave skal du bruge pipe redirection til at reverse outputtet af programmet.

Her er nogen eksempler på pipe redirection:

```sh
$ whoami
user
$ whoami | base64
cGlyYXQK
$ echo dXNlcgo= | base64 -d
user
$ whoami | base64 | base64 -d
user
```

Du skal bruge pipe redirection for at få flaget i denne opgave.
