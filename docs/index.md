# API Reference

## Classes

| Name                      | Description |
| ------------------------- | ----------- |
| [`StringArr`](#stringarr) |             |

## Macros

---

### STANDARDLOOP_UTIL_H_MAJOR_VERSION

```cpp
#define STANDARDLOOP_UTIL_H_MAJOR_VERSION 0
```

---

### STANDARDLOOP_UTIL_H_MINOR_VERSION

```cpp
#define STANDARDLOOP_UTIL_H_MINOR_VERSION 0
```

---

### STANDARDLOOP_UTIL_H_PATCH_VERSION

```cpp
#define STANDARDLOOP_UTIL_H_PATCH_VERSION 8
```

---

### STANDARDLOOP_UTIL_H_VERSION

```cpp
#define STANDARDLOOP_UTIL_H_VERSION "0.0.8"
```

---

### ALWAYS

```cpp
#define ALWAYS 1
```

---

### QUESTION_CHAR

```cpp
#define QUESTION_CHAR '?'
```

---

### EQUAL_CHAR

```cpp
#define EQUAL_CHAR '='
```

---

### AND_CHAR

```cpp
#define AND_CHAR '&'
```

---

### DOLLAR_CHAR

```cpp
#define DOLLAR_CHAR '$'
```

---

### CARROT_CHAR

```cpp
#define CARROT_CHAR '^'
```

---

### SPACE_CHAR

```cpp
#define SPACE_CHAR ' '
```

---

### TAB_CHAR

```cpp
#define TAB_CHAR '\t'
```

---

### NEWLINE_CHAR

```cpp
#define NEWLINE_CHAR '\n'
```

---

### CARRIAGE_CHAR

```cpp
#define CARRIAGE_CHAR '\r'
```

---

### DASH_MINUS_CHAR

```cpp
#define DASH_MINUS_CHAR '-'
```

---

### PLUS_CHAR

```cpp
#define PLUS_CHAR '+'
```

---

### DOT_CHAR

```cpp
#define DOT_CHAR '.'
```

---

### COMMA_CHAR

```cpp
#define COMMA_CHAR ','
```

---

### COLON_CHAR

```cpp
#define COLON_CHAR ':'
```

---

### DOUBLE_QUOTES_CHAR

```cpp
#define DOUBLE_QUOTES_CHAR '\"'
```

---

### SINGLE_QUOTES_CHAR

```cpp
#define SINGLE_QUOTES_CHAR '\''
```

---

### BACKSLASH_CHAR

```cpp
#define BACKSLASH_CHAR '\\'
```

---

### FORWARDLASH_CHAR

```cpp
#define FORWARDLASH_CHAR '/'
```

---

### BRACKET_OPEN_CHAR

```cpp
#define BRACKET_OPEN_CHAR '['
```

---

### BRACKET_CLOSE_CHAR

```cpp
#define BRACKET_CLOSE_CHAR ']'
```

---

### CURLY_OPEN_CHAR

```cpp
#define CURLY_OPEN_CHAR '{'
```

---

### CURLY_CLOSE_CHAR

```cpp
#define CURLY_CLOSE_CHAR '}'
```

---

### NULL_CHAR

```cpp
#define NULL_CHAR '\0'
```

---

### EOT_CHAR

```cpp
#define EOT_CHAR 4
```

---

### pass

```cpp
#define pass (void)0
```

## Functions

---

### CopyString

```cpp
void CopyString(char *, char *, size_t, size_t)
```

---

### CopyStringCanary

```cpp
void CopyStringCanary(char *, char *, u_int64_t)
```

---

### CopyStringServer

```cpp
void CopyStringServer(char *, char *, size_t, size_t, bool)
```

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

### TestStringHelpers

```cpp
void TestStringHelpers()
```

---

### GetEnv

```cpp
const char * GetEnv(char *, char *)
```

---

### TestEnv

```cpp
void TestEnv()
```

---

### RegexBoolMatch

```cpp
bool RegexBoolMatch(char *, char *)
```

---

### RegexReturnMatch

```cpp
char * RegexReturnMatch(char *, char *, int *, int *)
```

---

### EveryoneExplodeNow

```cpp
StringArr * EveryoneExplodeNow(char *, char)
```

---

### EveryoneExplodeNowHandleQuotes

```cpp
StringArr * EveryoneExplodeNowHandleQuotes(char *, char, char)
```

---

### FreeStringArr

```cpp
void FreeStringArr(StringArr *)
```

---

### PrintStringArr

```cpp
void PrintStringArr(StringArr *)
```

---

### TestExplode

```cpp
void TestExplode()
```

## StringArr

```cpp
struct StringArr
```

### Public Attributes

| Return    | Name                          | Description |
| --------- | ----------------------------- | ----------- |
| `char **` | [`strings`](#strings)         |             |
| `int`     | [`num_strings`](#num_strings) |             |

---

#### strings

```cpp
char ** strings
```

---

#### num_strings

```cpp
int num_strings
```
