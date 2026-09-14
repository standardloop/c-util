# API Reference

## Classes

| Name                      | Description                                                                                                                   |
| ------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| [`StringArr`](#stringarr) | The [StringArr](#stringarr) struct, contains an array of strings and the variable holding the number of strings in the array. |

## Functions

---

### Int64ToString

```cpp
char * Int64ToString(int64_t)
```

---

### QuickAllocatedString

```cpp
char * QuickAllocatedString(char *)
```

---

### PrintSpaces

```cpp
void PrintSpaces(int)
```

---

### PrintBuffer

```cpp
void PrintBuffer(char *, size_t, bool)
```

---

### StringToLower

```cpp
void StringToLower(char *)
```

---

### StringToUpper

```cpp
void StringToUpper(char *)
```

---

### IsCharInString

```cpp
bool IsCharInString(const char *, char)
```

---

### NumCharInString

```cpp
size_t NumCharInString(const char *, char)
```

---

### PutQuotesAroundString

```cpp
char * PutQuotesAroundString(char *, bool)
```

---

### GetEnv

```cpp
const char * GetEnv(char *, char *)
```

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
