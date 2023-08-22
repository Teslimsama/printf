#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return (-1);

    int printed_chars = 0;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past '%'
            if (*format)
            {
                if (*format == 'c')
                    printed_chars += _print_char(args);
                else if (*format == 's')
                    printed_chars += _print_string(args);
                else if (*format == '%')
                    printed_chars += _print_percent();
                // Add more cases for other format specifiers as needed
                else
                    return (-1); // Invalid format specifier
            }
        }
        else
        {
            putchar(*format); // Print regular character
            printed_chars++;
        }
        format++; // Move to the next character in format
    }

    va_end(args);
    return (printed_chars);
}
