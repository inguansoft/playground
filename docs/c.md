High address
+--------------------+------+--------------------+
|  stack     |       |      | local variables
|           \ /      |      | environment context
+--------------------+------+--------------------+
|                    |      |                    |
|                    |      |                    |
+--------------------+------+--------------------+
|  heap     / \      |      |  alloc, free
|            |       |      |
+--------------------+------+--------------------+
|  uninitialized     | bss  | global or static var
|  data    bss       |      | uninitialized
+--------------------+------+--------------------+
|  initialized       | data | global or static var
|  data              |      | initialized
+--------------------+------+--------------------+
|  text              | text |  program
|                    |      | 
+--------------------+------+--------------------+
Low address


size <program> output example
   OK      OK       OK    all+DEC  all+HEX  filename
   text	   data	    bss	    dec	    hex	filename
   1398	    604	      4	   2006	    7d6	silly

References
https://www.geeksforgeeks.org/memory-layout-of-c-program/

