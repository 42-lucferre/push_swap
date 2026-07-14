# _This project has been created as part of the 42 curriculum by lucferre_

## Description

This activity is about programming a function that returns a line read from a file descriptor.

This activity will not only allow to add a highly useful function to my collection, but it will also teach an important concept in C programming: __static variables__.

## Details

The following core mechanics were implemented in this project:

* __Reading from a file descriptor__:
  * Uses __read()__ to load _acc_ (accumulator) a size of data defined by _BUFFER_SIZE_.

* __Static accumulator__:
  * A static pointer named _acc_ (accumulator) preserves unextracted lines from file descriptors.

* __Line extraction__:
  * The _acc_ buffer is scanned for a newline character ('_\n_');
  * If found, everything before it is returned as a line;
  * The remainder is kept in the buffer, where it will join next buffer until a new '_\n_' is found.

* __End of file handling__:
  * When __read()__ returns 0 (End of File - EOF), the remaining content in the buffer is returned as the last line;
  * If there's nothing reamining on the buffer upon EOF, NULL is returned.

* __Error handling__:
  * If __read()__ returns -1 or if __malloc()__ fails, the _acc_ buffer is freed and NULL is returned.

***

Helper functions were stored on the get_next_line_utils.c file. These functions are:

* __line_end()__: Checks if the accumulated string has a '_\n_' character.

* __str_len()__: A static function, used only by the helper functions in this very same file (...utils.c) to calculate string length.

* __str_join()__: Concatenates the existing _acc_ with the next buffer loaded, creating a new _acc_ and freeing the old one in the process.

* __read_line()__: Loads a line from the _acc_ into a pointer named _line_, which is returned by the __get_next_line()__ function.

* __extract_line()__: Removes from the _acc_ the lines already loaded by __read_line()__.

***

### Bonus

The bonus version extends the function to handle multiple file descriptors (fd) simultaneously.

Instead of a single static _acc_ pointer, an array of 4096 static pointers are used, where each index corresponds to a different (fd), meaning up to 4096 different fd's can be handled at the same time.

## Instructions

To use the function, clone on your project folder with:

```bash
git clone https://https://github.com/42-lucferre/get_next_line.git get_next_line
```

### Command lines

To use the function, compile with:

```bash
cc <your_file.c> get_next_line/get_next_line_bonus.c -I./get_next_line_bonus -o <output_name>
```

## Resources

"__man__" used on Linux terminal and internet forums such as Stack Overflow were the primary sources of information.

AI was used as a secondary learning tool.
