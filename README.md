# get_next_line
Program a function that returns a line read from a file descriptor.

## 👩🏻‍💻 Points to consider.

- [x]  Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
- [x]  Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return **NULL**.
- [x]  Make sure that your function works as expected both when reading a file and when
reading from the standard input.
- [x]  Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.
- [x]  Your header file **get_next_line.h** must at least contain the prototype of the **get_next_line()** function
- [x]  Add all the helper functions you need in the **get_next_line_utils.c** file.
- [x]  Because you will have to read files in **get_next_line()**, add this option to your
compiler call: **-D BUFFER_SIZE=n**
It will define the buffer size for **read()**.
The buffer size value will be modified by your peer-evaluators and the Moulinette
in order to test your code.

---
<aside>
🚨 We must be able to compile this project with and without the -D
BUFFER_SIZE flag in addition to the usual flags. You can choose the
default value of your choice.
</aside>

---

- [x]  You will compile your code as follows (a buffer size of 42 is used as an example): **cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c.**
- [x]  We consider that **get_next_line()** has an undefined behavior if the file pointed to
by the file descriptor changed since the last call whereas read() didn’t reach the
end of file
- [x]  We also consider that **get_next_line()** has an undefined behavior when reading
a binary file. However, you can implement a logical way to handle this behavior if
you want to.

---
<aside>
🗣 **Intenta leer lo menos posible cada vez que se llame a get_next_line(). Si encuentras un salto de línea, deberás devolver la línea actual. No leas el archivo entero y luego proceses cada línea.**

</aside>
