Code originally posted as an edit to this StackOverflow answer, to fill it out:
http://stackoverflow.com/a/20476577/733077

This is a C program which generates postscript code to draw polygons and polygonal webs.
All calculations are performed in C and postscript merely executes sequences of "moveto"
and "lineto".

The program determines whether to output a simple polygon or a web by checking the 
program name from the command line. So, it's 2 programs in one. The second may be a
copy of or (hard or symbolic) link to the first.
