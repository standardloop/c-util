# c-util

https://github.com/standardloop/c-util

[![GitHub Release](https://img.shields.io/github/v/release/standardloop/c-util?sort=semver)](https://github.com/standardloop/c-util/releases) ![Platform: macOS](https://img.shields.io/badge/platform-macOS-000000?style=flat&logo=apple&logoColor=white) ![C Version](https://img.shields.io/badge/C_Standard-C17-00599C?logo=c&logoColor=white)

## About

c-util is a dynamic library of utililty based functions I use in more than one project.

In the future, this may be split off, but for now it is grouped like this.

## `explode`

### `EveryoneExplodeNow(2)`

This functions turns a string into an array of strings based on a delim character.

This is similiar to `split()` in python or `explode()` in php.

The function name, `EveryoneExplodeNow()` is a play on the [funny Pokémon card move.](<https://bulbapedia.bulbagarden.net/wiki/Forretress_(Undaunted_3)>)

### `EveryoneExplodeNowHandleQuotes(3)`

Similiar to above but characters that in quotes will not be split.

## `env`

### `GetEnv(2)`

Gets an environment variable, if the variable is not present, allows for a fallback.

## `stringhelpers`

### `IsCharInString(2)`

returns `true` or `false` if a character is in a string.

### `NumCharInString(2)`

returns the number of a specific character in a string.

### `StringToLower(1)`

modifies the input string to be lowercase.

### `StringToUpper(1)`

modifies the input string to be uppercase.

### `PutQuotesAroundString(2)`

Takes an input string and returns a new string with quotes around it.

## `regex` (WIP)

## `temp` (WIP)

needs to be reorganized

## Running

This repo uses [task](https://github.com/go-task/task).

Please run the default `task` to see all the avaiable `tasks`

```sh
$ task
task: Available tasks for this project:
* default:                   Show all avaiable tasks.
* test:                      Build and Run the test program.
* release:build:             Build the dylib.
* remote:download:           Download the released dylib from the GitHub release.
* remote:move:               Move the dylib and header file into paths for other programs to access.
* test:build:                Build the test program.
* test:build-sanitize:       Build the test with address sanitizer on.
* test:leaks:                Run macOS leaks on the test program.
* test:run:                  Run the test program.
```
