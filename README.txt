This application compiles valid Slic programming language instructions into valid GSTAL programming language instructions.

Implemented Features:
- While loops
- If statement
- If-Else statement
- Assignment statement
- Read statement
- Print statement (See Known Bugs)
- Exit statement
- datatype coercion

Tested Programs:
- zeller.slic (Succeeded)
- root.slic (Succeeded, modified last print statement)

Missing Features:
- Counting loops are not implemented

Known Bugs:
- Print statements can only handle one thing to print at a time.
  ex.) print 5, "hello", 8; will not work. However, print 5;, print "hello";, or print 8; will work.

- The modulus operator cannot be used as a left or right operand of an expression.
  ex.) (5 % 6) + (9 % 5) will not work. However, (5 + 6) % (9 + 5) will work.
