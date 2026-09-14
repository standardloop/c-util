# API Reference

## Classes

| Name                      | Description                                                                                                                   |
| ------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| [`StringArr`](#stringarr) | The [StringArr](#stringarr) struct, contains an array of strings and the variable holding the number of strings in the array. |

## Functions

---

### StringToLower

```cpp
void StringToLower(char * s)
```

Converts an input string s in place to all lowercase.

#### Parameters

| Parameter | Type     | Description       |
| --------- | -------- | ----------------- |
| `s`       | `char *` | The input string. |

---

### StringToUpper

```cpp
void StringToUpper(char * s)
```

Converts an input string s in place to all uppercase.

#### Parameters

| Parameter | Type     | Description       |
| --------- | -------- | ----------------- |
| `s`       | `char *` | The input string. |

---

### IsCharInString

```cpp
bool IsCharInString(const char * input_str, char checker)
```

Checks a string for a specific character.

#### Returns

true if the character is present, false if not.

#### Parameters

| Parameter   | Type           | Description             |
| ----------- | -------------- | ----------------------- |
| `input_str` | `const char *` | The input string.       |
| `checker`   | `char`         | The character to check. |

---

### NumCharInString

```cpp
size_t NumCharInString(const char * input_str, char checker)
```

Checks a string for a specific character and returns the number of occurences.

#### Returns

The number of occurences.

#### Parameters

| Parameter   | Type           | Description             |
| ----------- | -------------- | ----------------------- |
| `input_str` | `const char *` | The input string.       |
| `checker`   | `char`         | The character to check. |

---

### PutQuotesAroundString

```cpp
char * PutQuotesAroundString(char * input_str, bool free_input)
```

Puts Quotes around a string and returns the new string.

#### Returns

The new string with quotes around it.

#### Parameters

| Parameter    | Type     | Description                                    |
| ------------ | -------- | ---------------------------------------------- |
| `input_str`  | `char *` | The string to duplicate and change.            |
| `free_input` | `bool`   | If true, will free the input_str for convience |

---

### GetEnv

```cpp
const char * GetEnv(char * name, char * fallback)
```

Looks up an environment variable with an optional fallback.

#### Returns

A string of the environment variable.

#### Parameters

| Parameter  | Type     | Description                                                         |
| ---------- | -------- | ------------------------------------------------------------------- |
| `name`     | `char *` | The name of the environment variable to look up.                    |
| `fallback` | `char *` | The fallback default if the environment variable couldn't be found. |

---

### EveryoneExplodeNow

```cpp
StringArr * EveryoneExplodeNow(char * input_str, char delim)
```

Creates a [StringArr](#stringarr) based on an input string and a delimiter. For example, `[EveryoneExplodeNow](#everyoneexplodenow)("hello world", ' ')` will return `["hello", "world"]`.

#### Returns

The [StringArr](#stringarr)

#### Parameters

| Parameter   | Type     | Description                                    |
| ----------- | -------- | ---------------------------------------------- |
| `input_str` | `char *` | The input string.                              |
| `delim`     | `char`   | What character to break the string about from. |

---

### EveryoneExplodeNowHandleQuotes

```cpp
StringArr * EveryoneExplodeNowHandleQuotes(char * input_str, char delim, char quotes_char)
```

Creates a [StringArr](#stringarr) based on an input string and a delimiter. For example, `[EveryoneExplodeNow](#everyoneexplodenow)("hello world", ' ')` will return `["hello", "world"]` but also handle quotes, so delim characters in quotes will not be exploded.

#### Returns

The [StringArr](#stringarr)

#### Parameters

| Parameter     | Type     | Description                                    |
| ------------- | -------- | ---------------------------------------------- |
| `input_str`   | `char *` | The input string.                              |
| `delim`       | `char`   | What character to break the string about from. |
| `quotes_char` | `char`   | Which quote character to ignore from.          |

---

### FreeStringArr

```cpp
void FreeStringArr(StringArr * string_arr)
```

Free all Strings inside a [StringArr](#stringarr) and the [StringArr](#stringarr) itself.

#### Parameters

| Parameter    | Type                        | Description                          |
| ------------ | --------------------------- | ------------------------------------ |
| `string_arr` | [`StringArr`](#stringarr) * | The [StringArr](#stringarr) to free. |

---

### PrintStringArr

```cpp
void PrintStringArr(StringArr * string_arr)
```

Pretty Print a [StringArr](#stringarr) for debugging.

#### Parameters

| Parameter    | Type                        | Description                           |
| ------------ | --------------------------- | ------------------------------------- |
| `string_arr` | [`StringArr`](#stringarr) * | The [StringArr](#stringarr) to print. |

## StringArr

```cpp
#include <standardloop/util.h>
```

```cpp
struct StringArr
```

The [StringArr](#stringarr) struct, contains an array of strings and the variable holding the number of strings in the array.

### Public Attributes

| Return    | Name                          | Description                         |
| --------- | ----------------------------- | ----------------------------------- |
| `int`     | [`num_strings`](#num_strings) | The number of strings in the array. |
| `char **` | [`strings`](#strings)         | The array of strings.               |

---

#### num_strings

```cpp
int num_strings
```

The number of strings in the array.

---

#### strings

```cpp
char ** strings
```

The array of strings.
