# ft_printf

> A versatile and customizable formatted output function.

### Function prototype
```c
int ft_printf(const char *, ...);
```

The goal of *ft_printf* is to provide a function that can format and print data to the console or another output stream. It supports a wide range of conversion specifiers, allowing the user to format and print various types of data, such as integers, strings, characters, and more.

The function parses the format string provided by the user, identifying conversion specifiers and their corresponding arguments. It then formats the data according to the specified conversion specifier and prints it to the output stream. *ft_printf* also supports various flags and modifiers, enabling precise control over the output formatting.

### Conversion specifiers and flags

My ft_printf handles the following conversion specifiers: `%c %s %p %d %i %u %x %X %%`

It also handles the following flags: `-0.` and `# +`
