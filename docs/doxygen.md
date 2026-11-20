# Doxygen Documentation for Neutron

## Generate the documentation

From the repository root, run:

```bash
doxygen Doxyfile
```

Then open `docs/doxygen/html/index.html` in a web browser.

## Add documentation

Add Doxygen comments to source files and declarations. Use `/** ... */` for block comments or `///` for brief comments on individual members.

### File

```c
/**
 * @file math.h
 * @brief Declarations for math utilities.
 */
```

### Function

```c
/**
 * @brief Adds two integers.
 * @param a The first number.
 * @param b The second number.
 * @return The sum of `a` and `b`.
 */
int add(int a, int b);
```

### Structure and members

```c
/**
 * @brief Stores basic user information.
 */
typedef struct {
  /// The user's display name.
  const char *name;

  /// The user's age in years.
  int age;

  /// The user's height in meters.
  float height;
} User;
```

### Enumeration

```c
/**
 * @brief Represents the state of a user.
 */
typedef enum {
  USER_STATE_INACTIVE, /**< The user is inactive. */
  USER_STATE_ACTIVE    /**< The user is active. */
} UserState;
```

### Function pointer typedef

```c
/**
 * @brief A function that executes a command.
 * @param command The command to execute.
 * @return `true` on success; otherwise, `false`.
 */
typedef bool (*ExecuteFunction)(const char *command);
```

## Include new directories

If you add a new application or source directory that should appear in the generated documentation, update the `Doxyfile`. Find the `INPUT` setting and add the new directory to its list.
