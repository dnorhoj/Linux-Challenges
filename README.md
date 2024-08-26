# Linux-Challenges

Simple framework for creating challenges similar to [OverTheWire Wargames](https://overthewire.org/wargames).

## Developing challenges

All challenges can be found in /challenges/src.

A couple of rules apply to each file in the subfolders.

- Any .c file will be compiled to an executable of the same name with SUID root.
- Any files in the optional subfolder `fs/`, will be placed in the root. (See level_04 for usage).
- Any file called `flag` will be set to only be readable by user and group (root).

## Prerequisites

Docker is the only prerequisite to build and run this.

## Trying it out

Until I create a more streamlined setup here is how to get it working.

```bash
# Clone repo
git clone https://github.com/dnorhoj/Linux-Challenges.git
cd Linux-Challenges

# Create .env file
cp .env.example .env

# Build challenges
cd challenges
./build.sh
cd ..

# Build controller
cd controller
./build.sh

# Start controller (Starts ssh server on localhost:2222)
docker compose up -d
```

You can now start a challenge instance with:

```bash
ssh -p 2222 user@localhost
```

## TODOs

- [ ] Better readme
- [ ] Configurable challenge via yml/similar
- [ ] More configurability in general
