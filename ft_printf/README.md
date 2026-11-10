*This activity has been created as part of the 42 curriculum by epigot.*

# Description
The goal of this activity is to create a C library with an home made printf equivalent.

The ft_printf function supports interpolations for :
- %c : prints a single character.
- %s : prints a string (as defined by the common C convention).
- %p : prints void * pointer argument in hexadecimal format.
- %d : prints a decimal (base 10) number.
- %i : prints an integer in base 10.
- %u : prints an unsigned decimal (base 10) number.
- %x : prints a number in hexadecimal (base 16) lowercase format.
- %X : prints a number in hexadecimal (base 16) uppercase format.
- %% : prints a percent sign.

More information on the functions behavior can be found in the 42 activity subject.

# Instructions
To compile use the make commands available :
- make 
- make re (recompiles the full library)
- make clean (cleans object files)
- make fclean (cleans object files and the library)

You can use the library in your own code by including *ft_printf.h* and using *libftprintf.a* during compilation.

# Resources
For more informations on the original printf function behavior see the Linux man pages : https://man7.org/linux/man-pages/man3/printf.3.html

# Technical details
ft_print.c contains the main function which prints characters until finding a % character, upon which it then checks the next character to know exactly what to do with the arguments.
The printed arguments are stored in a variable list from which the data is pulled every time a % is found.
printers.c contains the different functions called to print in different formats.
writers.c contains the number and characters printers, calling the write standard function.
