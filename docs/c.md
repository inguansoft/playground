# Memory management
## Memory layout
#### High address
| memory                 | known as | Details                            |
|:-----------------------|:---------|:-----------------------------------|
| Stack grows down       |          | local var, scope                   |
|                        |          |                                    |
| Heap grows up          |          | alloc, free                        |
| uninitialized data bss | bss      | global or static var uninitialized |
| initialized data       | data     | global or static var initialized   |
| text                   | text     | program                            |
#### Low address

```
size <program> 
#output example
   OK      OK       OK    all+DEC  all+HEX  filename
   text	   data	    bss	    dec	    hex	filename
   1398	    604	      4	   2006	    7d6	silly
```
### References
[geeksforgeeks memory-layout-of-c-program](https://www.geeksforgeeks.org/memory-layout-of-c-program/)
