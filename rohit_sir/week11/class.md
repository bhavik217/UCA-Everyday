## File Management in C

#### There are two type of files in C
1. **Text Files**
2. **Binary Files**

| Text Files | Binary Files |
|------------|--------------|
| Human Readable | Not Human Readable |
| Can be Opened in any Text Editor | Can't be Opened in any Text Editor |
| File Extension is .txt | File Extension is .bin |
| ASCII and UTF-8 Encoding | Just 0 and 1 is There |

---

# File Handling in C
## FILE Struct in C

```C
typedef struct _iobuf
{
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
} FILE;
```
I don't know about above struct

#### File Handling Functions

- **fopen()** - To Open a File
```C
FILE *fopen(const char *filename, const char *mode);
```

- **fclose()** - To Close a File
```C
int fclose(FILE *stream);
```

- **fputc()** - To Write a Character to a File
```C
int fputc(int c, FILE *stream);
```

- **fgetc()** - To Read a Character from a File
```C
int fgetc(FILE *stream);
```

- **fprintf()** - To Write a String to a File
```C
int fprintf(FILE *stream, const char *format, ...);
```

- **fscanf()** - To Read a String from a File
```C
int fscanf(FILE *stream, const char *format, ...);
```

- **fgets()** - To Read a Line from a File
```C
char *fgets(char *str, int n, FILE *stream);
```

- **fputs()** - To Write a Line to a File
```C
int fputs(const char *str, FILE *stream);
```
---

***Homework :-***
- How it reads escape characters!   VERY IMP.
- Input - Store it binary
- Binary - Text

<a href="https://stackoverflow.com/questions/4459859/where-are-standard-streams-stdin-and-stdout-created#:~:text=In%20Linux%2C%20you%20can%20generally,%2Fself%2Ffd%2F1%20">Link to StackOverflow</a>
